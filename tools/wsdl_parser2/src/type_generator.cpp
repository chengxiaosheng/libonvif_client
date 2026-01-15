/**
 * @file type_generator.cpp
 * @brief 类型定义代码生成器实现
 */

#include "../include/type_generator.h"
#include "../include/config.h"
#include "../include/type_utils.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <regex>
#include <set>
#include <functional>
#include <iostream>

namespace wsdl_parser2 {

TypeGenerator::TypeGenerator(const ParserConfig& config, const GeneratorOptions& options)
    : config_(config), options_(options) {
}

std::string TypeGenerator::generate_types_for_file(
    const std::shared_ptr<FileInfo>& file_info,
    const std::vector<std::shared_ptr<FileInfo>>& all_files) const {
    
    std::ostringstream oss;
    
    // 收集依赖
    auto dependencies = collect_dependencies(file_info, all_files);
    
    // 生成文件头部
    oss << generate_file_header(file_info, dependencies);
    
    // 开始命名空间
    oss << "namespace " << config().client_namespace  << " {\n\n";

    // 对类型进行拓扑排序并检测循环依赖
    auto sort_result = topological_sort_types(file_info->types);

    // 生成循环依赖类型的前置声明
    if (!sort_result.circular_types.empty()) {
        oss << "// 前置声明（循环依赖的类型）\n";
        for (const auto& type_name : sort_result.circular_types) {
            // 找到对应的类型以获取完整的前缀名
            for (const auto& type : file_info->types) {
                if (type.name == type_name) {
                    oss << "struct " << get_prefixed_type_name(type) << ";\n";
                    break;
                }
            }
        }
        oss << "\n";
    }

    // 跟踪已生成的列表类型（用于去重）
    std::map<std::string, std::string> generated_list_types;  // underlying_type -> first_type_name

    // 生成类型定义
    for (const auto& type : sort_result.sorted_types) {
        if (type.is_enum) {
            oss << generate_enum(type) << "\n\n";
        } else if (type.is_list) {
            // 检查是否重复定义
            std::string element_cpp_type = TypeUtils::convert_xsd_to_cpp_type(type.list_item_type);
            std::string underlying_type = "std::vector<" + element_cpp_type + ">";
            std::string prefixed_name = get_prefixed_type_name(type);

            auto it = generated_list_types.find(underlying_type);
            if (it != generated_list_types.end()) {
                // 重复定义：生成别名指向第一个定义
                if (options_.generate_comments) {
                    oss << "// " << type.name << " 列表类型别名（与 " << it->second << " 相同）\n";
                    oss << "// 元素类型: " << type.list_item_type << "\n";
                }
                oss << "using " << prefixed_name << " = " << it->second << ";\n\n";
            } else {
                // 首次定义：正常生成
                oss << generate_list_type(type) << "\n\n";
                generated_list_types[underlying_type] = prefixed_name;
            }
        } else if (type.is_simple_type_rename) {
            oss << generate_simple_type_rename(type, file_info) << "\n\n";
        } else {
            oss << generate_struct(type, file_info, all_files) << "\n\n";
        }

        // 生成XmlTraits
        if (options_.generate_xml_traits) {
            if (type.is_enum) {
                oss << generate_enum_xml_traits(type) << "\n\n";
            } else if (type.is_list) {
                // 检查是否为重复定义
                std::string element_cpp_type = TypeUtils::convert_xsd_to_cpp_type(type.list_item_type);
                std::string underlying_type = "std::vector<" + element_cpp_type + ">";
                std::string prefixed_name = get_prefixed_type_name(type);

                auto it = generated_list_types.find(underlying_type);
                if (it != generated_list_types.end() && it->second != prefixed_name) {
                    // 重复定义：添加注释说明共享适配器
                    oss << "// Note: " << prefixed_name << " shares XmlValueAdapter with " << it->second << "\n\n";
                } else {
                    // 首次定义：生成适配器
                    if (TypeUtils::is_basic_cpp_type(element_cpp_type)) {
                        oss << generate_list_xml_traits(type) << "\n\n";
                    } else {
                        oss << "// Note: " << prefixed_name
                            << " uses generic std::vector adapter (element type is complex)\n\n";
                    }
                }
            } else if (!type.is_simple_type_rename) {
                // 简单类型别名不需要特殊的 Adapter
                oss << generate_xml_traits(type) << "\n\n";
            }
        }
    }
    
    // 结束命名空间
    oss << "} // namespace " << config().client_namespace << "\n";
    
    return oss.str();
}


int TypeGenerator::generate_all_type_files(
    const std::vector<std::shared_ptr<FileInfo>>& files) const {
    
    // 完全采用分离模式，为每个文件生成独立的类型文件
    return generate_separate_schema_files(files);
}


std::string TypeGenerator::generate_file_header(
    const std::shared_ptr<FileInfo>& file_info,
    const std::set<std::string>& dependencies) const {
    
    std::ostringstream oss;
    
    // 使用统一的头文件名生成逻辑
    std::string filename = generate_header_name(file_info);
    
    oss << "/**\n";
    oss << " * @file " << filename << "\n";
    oss << " * @brief 从 " << std::filesystem::path(file_info->file_path).filename().string() << " 生成的类型定义\n";
    if (!file_info->target_namespace.empty()) {
        oss << " * @namespace " << file_info->target_namespace << "\n";
    }
    oss << " * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改\n";
    oss << " */\n\n";
    
    oss << "#pragma once\n\n";

    // 基础头文件
    oss << "// 标准库头文件\n";
    oss << "#include <string>\n";
    oss << "#include <vector>\n";
    oss << "#include <optional>\n";
    oss << "#include <memory>\n";
    oss << "#include <map>\n";
    oss << "#include <cstdint>\n";
    oss << "#include <sstream>\n\n";

    // 包含依赖的头文件
    if (!dependencies.empty()) {
        oss << "// 依赖的类型定义\n";
        for (const auto& dep : dependencies) {
            oss << "#include " << generate_types_include_path(dep) << "\n";
        }
        oss << "\n";
    }
    
    // libonvif_client头文件
    oss << "// libonvif_client框架头文件\n";
    oss << "#include " << config().xml_convert_path << "\n";
    oss << "#include \"libonvif_client/base_types.h\"\n\n";
    
    return oss.str();
}


std::set<std::string> TypeGenerator::collect_dependencies(
    const std::shared_ptr<FileInfo>& file_info,
    const std::vector<std::shared_ptr<FileInfo>>& all_files) const {

    std::set<std::string> deps;

    // 获取当前文件的头文件名
    std::string current_header = generate_header_name(file_info);

    std::cout << "📋 collect_dependencies 被调用: " << current_header
              << " (依赖数量: " << file_info->dependencies.size() << ")" << std::endl;

    // 1. 使用解析时已经记录的依赖关系（从 xs:import）
    for (const auto& dep_file : file_info->dependencies) {
        std::cout << "🔍 检查依赖: " << (dep_file ? dep_file->file_path : "null")
                  << " (类型数量: " << (dep_file ? dep_file->types.size() : 0) << ")" << std::endl;

        if (!dep_file || dep_file->types.empty()) {
            std::cout << "⏭️  跳过无效或空的依赖文件" << std::endl;
            continue; // 跳过无效或空的依赖文件
        }

        // 为依赖文件生成对应的头文件名
        std::string dep_header = generate_header_name(dep_file);

        // 避免自我包含
        if (dep_header != current_header) {
            deps.insert(dep_header);

            std::cout << "✅ 依赖收集: " << current_header << " -> " << dep_header
                     << " (来源: " << dep_file->target_namespace << ")" << std::endl;
        } else {
            std::cout << "🔄 跳过自引用: " << dep_header << std::endl;
        }
    }

    // 2. 补充配置文件中声明的依赖（SchemaConfig::dependencies）
    auto schema_config = find_schema_config(config_, file_info->target_namespace);
    if (schema_config.has_value() && !schema_config->dependencies.empty()) {
        std::cout << "🔧 检查配置文件依赖: " << schema_config->dependencies.size() << " 个" << std::endl;

        for (const auto& dep_source_file : schema_config->dependencies) {
            std::cout << "🔍 配置依赖: " << dep_source_file << std::endl;

            // 在 all_files 中查找匹配的文件
            for (const auto& potential_dep : all_files) {
                if (!potential_dep || potential_dep->types.empty()) continue;

                // 检查文件路径是否匹配（支持部分匹配）
                std::string file_path = potential_dep->file_path;
                if (file_path.find(dep_source_file) != std::string::npos) {
                    std::string dep_header = generate_header_name(potential_dep);

                    // 避免自我包含
                    if (dep_header != current_header) {
                        if (deps.insert(dep_header).second) {
                            std::cout << "✅ 配置依赖收集: " << current_header << " -> " << dep_header
                                     << " (配置来源: " << dep_source_file << ")" << std::endl;
                        }
                    }
                    break; // 找到匹配的文件，跳出内层循环
                }
            }
        }
    }

    std::cout << "📊 依赖收集完成: " << current_header << " 共收集到 " << deps.size() << " 个依赖" << std::endl;

    return deps;
}

TopologicalSortResult TypeGenerator::topological_sort_types(const std::vector<WsdlType>& types) const {
    TopologicalSortResult result;
    std::set<std::string> visited;
    std::set<std::string> visiting;

    // 创建完整类型名到类型的映射（包含命名空间前缀）
    std::map<std::string, const WsdlType*> type_map;
    for (const auto& type : types) {
        std::string prefixed_name = get_prefixed_type_name(type);
        type_map[prefixed_name] = &type;
        // 同时也用原始名称做映射，用于本地引用
        type_map[type.name] = &type;
    }

    // 深度优先搜索
    std::function<bool(const WsdlType*)> dfs = [&](const WsdlType* type) -> bool {
        if (visiting.count(type->name)) {
            // 检测到循环依赖
            result.circular_types.insert(type->name);
            return true; // 循环依赖，跳过
        }

        if (visited.count(type->name)) {
            return true; // 已访问
        }

        visiting.insert(type->name);

        // 处理基类型依赖
        if (!type->base_type.empty()) {
            auto [ns_prefix, base_type_name] = TypeUtils::parse_type_ref(type->base_type);
            auto it = type_map.find(base_type_name);
            if (it != type_map.end()) {
                if (visiting.count(base_type_name)) {
                    // 基类型也参与循环
                    result.circular_types.insert(base_type_name);
                    result.circular_types.insert(type->name);
                }
                dfs(it->second);
            }
        }

        // 处理简单类型重命名的基础类型依赖
        if (type->is_simple_type_rename && !type->base_simple_type.empty()) {
            auto [ns_prefix, base_simple_type_name] = TypeUtils::parse_type_ref(type->base_simple_type);
            auto it = type_map.find(base_simple_type_name);
            if (it != type_map.end()) {
                if (visiting.count(base_simple_type_name)) {
                    result.circular_types.insert(base_simple_type_name);
                    result.circular_types.insert(type->name);
                }
                dfs(it->second);
            }
        }

        // 处理字段类型依赖
        for (const auto& field : type->fields) {
            auto [ns_prefix, field_type_name] = TypeUtils::parse_type_ref(field.type);
            auto it = type_map.find(field_type_name);
            if (it != type_map.end()) {
                if (visiting.count(field_type_name)) {
                    // 字段类型参与循环
                    result.circular_types.insert(field_type_name);
                    result.circular_types.insert(type->name);
                }
                dfs(it->second);
            }
        }

        visiting.erase(type->name);
        visited.insert(type->name);
        result.sorted_types.push_back(*type);

        return true;
    };

    // 对所有类型进行排序
    for (const auto& type : types) {
        if (!visited.count(type.name)) {
            dfs(&type);
        }
    }

    return result;
}

std::string TypeGenerator::generate_struct(
    const WsdlType& type,
    const std::shared_ptr<FileInfo>& current_file,
    const std::vector<std::shared_ptr<FileInfo>>& all_files) const {
    std::ostringstream oss;
    
    // 生成文档注释
    if (options_.generate_comments) {
        oss << generate_doc_comment(type.name + " 类型定义");
        if (!type.ns_uri.empty()) {
            oss << generate_doc_comment("命名空间: " + type.ns_uri);
        }
        if (!type.source_file.empty()) {
            oss << generate_doc_comment("源文件: " + std::filesystem::path(type.source_file).filename().string());
        }
    }
    if (config().export_directive.empty()) {
        oss << "struct " << get_prefixed_type_name(type);
    } else {
        oss << "struct " << config().export_directive << " " << get_prefixed_type_name(type);
    }
    

    // 处理继承（基类型已在wsdl_parser中解析完成）
    if (!type.base_type.empty()) {
        std::string base_cpp_type = type.base_type;
        // 确保基类型名符合C++标识符规范
        std::replace(base_cpp_type.begin(), base_cpp_type.end(), '-', '_');
        std::replace(base_cpp_type.begin(), base_cpp_type.end(), ':', '_');
        oss << " : public " << base_cpp_type;
    }
    
    oss << " {\n";

    // 元数据已移至 Service 层，不再在类型中定义

    // 生成字段
    for (const auto& field : type.fields) {
        if (options_.generate_comments && !field.doc.empty()) {
            oss << generate_doc_comment(field.doc, 1);
        }

        // 直接使用WsdlField的get_cpp_type方法（命名空间和类型信息已在wsdl_parser中处理完成）
        std::string field_type_name = field.get_cpp_type();

        oss << options_.indent << field_type_name << " " << field.get_cpp_field_name();

        // 对需要初始化的类型添加 {} 避免未初始化警告
        if (TypeUtils::needs_brace_initialization(field_type_name)) {
            oss << " {}";
        }

        oss << ";\n";
    }

    oss << "};\n";
    
    return oss.str();
}

std::string TypeGenerator::generate_enum(const WsdlType& type) const {
    std::ostringstream oss;
    
    // 生成文档注释
    if (options_.generate_comments) {
        oss << generate_doc_comment(type.name + " 枚举类型");
        if (!type.base_type.empty()) {
            oss << generate_doc_comment("基础类型: " + type.base_type);
        }
    }
    
    oss << "enum class " << config().export_directive << " " << get_prefixed_type_name(type) << " {\n";
    
    // 生成枚举值
    for (size_t i = 0; i < type.enumeration.size(); ++i) {
        const auto& value = type.enumeration[i];
        std::string sanitized = sanitize_enum_value(value);
        oss << options_.indent << sanitized;
        if (i < type.enumeration.size() - 1) {
            oss << ",";
        }
        if (options_.generate_comments && sanitized != value) {
            oss << " // " << value;
        }
        oss << "\n";
    }
    
    oss << "};\n";
    
    // 生成转换函数
    std::string prefixed_name = get_prefixed_type_name(type);
    
    oss << "\n// 字符串转换函数\n";
    oss << "inline std::string to_string(" << prefixed_name << " value) {\n";
    oss << options_.indent << "switch (value) {\n";
    for (const auto& value : type.enumeration) {
        std::string sanitized = sanitize_enum_value(value);
        oss << options_.indent << options_.indent << "case " << prefixed_name << "::" << sanitized 
            << ": return \"" << value << "\";\n";
    }
    oss << options_.indent << options_.indent << "default: return \"\";\n";
    oss << options_.indent << "}\n";
    oss << "}\n";
    
    oss << "\ninline bool from_string(" << prefixed_name << "& value, const std::string& str) {\n";
    for (const auto& enum_value : type.enumeration) {
        std::string sanitized = sanitize_enum_value(enum_value);
        oss << options_.indent << "if (str == \"" << enum_value << "\") { value = " 
            << prefixed_name << "::" << sanitized << "; return true; }\n";
    }
    oss << options_.indent << "return false;\n";
    oss << "}\n";
    
    return oss.str();
}

std::string TypeGenerator::generate_list_type(const WsdlType& type) const {
    std::ostringstream oss;

    // 获取列表元素的C++类型（列表元素类型已在wsdl_parser中解析完成）
    std::string element_cpp_type = type.list_item_type;

    // 优先进行基础类型映射
    element_cpp_type = TypeUtils::convert_xsd_to_cpp_type(element_cpp_type);

    // 生成文档注释
    if (options_.generate_comments) {
        oss << generate_doc_comment(type.name + " 列表类型别名");
        oss << generate_doc_comment("元素类型: " + type.list_item_type);
    }

    std::string prefixed_name = get_prefixed_type_name(type);

    // 直接使用 using 别名，不再生成包装结构体
    oss << "using " << prefixed_name << " = std::vector<" << element_cpp_type << ">;\n";

    return oss.str();
}

std::string TypeGenerator::generate_simple_type_rename(const WsdlType& type,
                                                       const std::shared_ptr<FileInfo>& current_file) const {
    std::ostringstream oss;

    // 获取基础类型的C++类型
    std::string base_cpp_type = TypeUtils::convert_xsd_to_cpp_type(type.base_simple_type);

    // 生成文档注释
    if (options_.generate_comments) {
        oss << generate_doc_comment(type.name + " 类型别名");
        oss << generate_doc_comment("基础类型: " + base_cpp_type);
    }

    std::string prefixed_name = get_prefixed_type_name(type);

    // 直接使用 using 别名，不再生成包装结构体
    oss << "using " << prefixed_name << " = " << base_cpp_type << ";\n";

    return oss.str();
}

std::string TypeGenerator::generate_xml_traits(const WsdlType& type) const {
    std::ostringstream oss;
    
    std::string prefixed_name = get_prefixed_type_name(type);

    if (type.is_simple_type_rename) {
        // 简单类型别名不需要特殊的 Adapter
        // 类型别名会自动使用基础类型的 Adapter
        oss << "// Note: " << prefixed_name << " is a type alias, uses base type's XML adapters\n";
    } else {
        // 普通结构体的XmlTraits - 适配新的xml_convert系统
        oss << "// XmlTraits for " << prefixed_name << "\n";
        oss << "template<>\n";
        oss << "struct xml_convert::XmlTraits<" << prefixed_name << "> {\n";
        oss << options_.indent << "static constexpr auto fields = ";
        if (!type.base_type.empty()) {
            std::string base_cpp_type = get_cpp_type_name(type.base_type, nullptr, {});
            oss << "std::tuple_cat(xml_convert::XmlTraits<"
                << base_cpp_type << ">::fields, ";
        }
        oss << "std::make_tuple(\n";
        
        bool first = true;
        for (const auto& field : type.fields) {
            if (!first) {
                oss << ",\n";
            }
            first = false;
            
            oss << options_.indent << options_.indent;

            // 对特殊字段类型使用特殊处理
            if (field.field_type == FieldType::TEXT_CONTENT) {
                // TEXT_CONTENT字段表示元素的文本内容，使用nullptr作为名称
                oss << "xml_convert::make_field_desc(nullptr, ";
            } else if (field.field_type == FieldType::ANY_ELEMENT) {
                // xs:any字段使用字段名
                oss << "xml_convert::make_field_desc(\"" << field.name << "\", ";
            } else {
                // 普通字段使用字段名
                oss << "xml_convert::make_field_desc(\"" << field.name << "\", ";
            }

            oss << "&" << prefixed_name << "::" << field.get_cpp_field_name();
            
            // 新API参数顺序：name, ptr, ns_prefix, type
            // 属性、anyAttribute 和 TEXT_CONTENT 不应该有命名空间前缀
            if (field.field_type == FieldType::ATTRIBUTE ||
                field.field_type == FieldType::ANY_ATTRIBUTE ||
                field.field_type == FieldType::TEXT_CONTENT) {
                oss << ", nullptr";
            } else if (field.field_type == FieldType::ANY_ELEMENT && (field.name == "_any_" || field.name == "##any" || field.name.empty())) {
                // ##any类型的AnyElement不应该有命名空间前缀
                oss << ", nullptr";
            } else if (!field.ns_prefix.empty()) {
                oss << ", \"" << field.ns_prefix << "\"";
            } else {
                oss << ", nullptr";
            }
            
            // 添加序列化类型
            if (field.field_type == FieldType::ANY_ELEMENT) {
                oss << ", xml_convert::serialize_type::full | xml_convert::serialize_type::any_element";
            } else if (field.field_type == FieldType::ATTRIBUTE || field.field_type == FieldType::ANY_ATTRIBUTE) {
                oss << ", xml_convert::serialize_type::attribute";
            } else {
                oss << ", xml_convert::serialize_type::full";
            }
            oss << ")";
        }
        if (!type.base_type.empty()) {
            oss << ")";
        }
        oss << "\n" << options_.indent << ");\n";
        oss << "};\n";
    }
    
    return oss.str();
}

std::string TypeGenerator::generate_enum_xml_traits(const WsdlType& type) const {
    std::ostringstream oss;
    
    std::string prefixed_name = get_prefixed_type_name(type);
    
    oss << "// XmlValueAdapter specialization for enum " << prefixed_name << "\n";
    oss << "template<>\n";
    oss << "struct xml_convert::XmlValueAdapter<" << prefixed_name << "> {\n";
    
    // from_xml_val方法 - 适配新的API
    oss << options_.indent << "static bool from_xml_val(" << prefixed_name << "& val, xmlNodePtr element, const char* name = nullptr,\n";
    oss << options_.indent << "                         const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {\n";
    oss << options_.indent << options_.indent << "xmlNodePtr targetElement = name ? \n";
    oss << options_.indent << options_.indent << "    xmlGetChildElementByName(element, name) : element;\n";
    oss << options_.indent << options_.indent << "if (!targetElement) return false;\n";
    oss << options_.indent << options_.indent << "xmlChar* content = xmlNodeGetContent(targetElement);\n";
    oss << options_.indent << options_.indent << "if (!content) return false;\n";
    oss << options_.indent << options_.indent << "std::string str_val(reinterpret_cast<char*>(content));\n";
    oss << options_.indent << options_.indent << "xmlFree(content);\n";
    oss << options_.indent << options_.indent << "return from_string(val, str_val);\n";
    oss << options_.indent << "}\n";
    oss << options_.indent << "\n";
    
    // to_xml_val方法 - 适配新的API
    oss << options_.indent << "static bool to_xml_val(const " << prefixed_name << "& val, xmlNodePtr parent, const char* name,\n";
    oss << options_.indent << "                       const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {\n";
    oss << options_.indent << options_.indent << "if (!parent || !name) return false;\n";
    oss << options_.indent << options_.indent << "xmlNodePtr element = create_element_with_ns(parent, name, ns_prefix, namespaces);\n";
    oss << options_.indent << options_.indent << "if (!element) return false;\n";
    oss << options_.indent << options_.indent << "xmlNodeSetContent(element, BAD_CAST to_string(val).c_str());\n";
    oss << options_.indent << options_.indent << "return true;\n";
    oss << options_.indent << "}\n";
    oss << options_.indent << "\n";
    
    // 辅助函数：创建带命名空间的元素
    oss << "private:\n";
    oss << options_.indent << "static xmlNodePtr create_element_with_ns(xmlNodePtr parent, const char* name, \n";
    oss << options_.indent << "                                        const char* ns_prefix, const std::map<std::string_view, std::string_view>& namespaces) {\n";
    oss << options_.indent << options_.indent << "xmlNodePtr element = xmlNewChild(parent, nullptr, BAD_CAST name, nullptr);\n";
    oss << options_.indent << options_.indent << "if (element && ns_prefix) {\n";
    oss << options_.indent << options_.indent << options_.indent << "auto it = namespaces.find(ns_prefix);\n";
    oss << options_.indent << options_.indent << options_.indent << "if (it != namespaces.end()) {\n";
    oss << options_.indent << options_.indent << options_.indent << options_.indent << "xmlNsPtr ns = xmlNewNs(element, BAD_CAST it->second.data(), BAD_CAST ns_prefix);\n";
    oss << options_.indent << options_.indent << options_.indent << options_.indent << "xmlSetNs(element, ns);\n";
    oss << options_.indent << options_.indent << options_.indent << "}\n";
    oss << options_.indent << options_.indent << "}\n";
    oss << options_.indent << options_.indent << "return element;\n";
    oss << options_.indent << "}\n";
    
    oss << options_.indent << "\n";
    oss << options_.indent << "static xmlNodePtr xmlGetChildElementByName(xmlNodePtr parent, const char* name) {\n";
    oss << options_.indent << options_.indent << "if (!parent || !name) return nullptr;\n";
    oss << options_.indent << options_.indent << "for (xmlNodePtr child = parent->children; child; child = child->next) {\n";
    oss << options_.indent << options_.indent << options_.indent << "if (child->type == XML_ELEMENT_NODE && \n";
    oss << options_.indent << options_.indent << options_.indent << "    xmlStrcmp(child->name, BAD_CAST name) == 0) {\n";
    oss << options_.indent << options_.indent << options_.indent << options_.indent << "return child;\n";
    oss << options_.indent << options_.indent << options_.indent << "}\n";
    oss << options_.indent << options_.indent << "}\n";
    oss << options_.indent << options_.indent << "return nullptr;\n";
    oss << options_.indent << "}\n";
    oss << "};\n\n";
    
    // 为枚举类型生成 XmlAttributeAdapter 特化
    oss << "// XmlAttributeAdapter specialization for enum " << prefixed_name << "\n";
    oss << "template<>\n";
    oss << "struct xml_convert::XmlAttributeAdapter<" << prefixed_name << "> {\n";
    
    oss << options_.indent << "static bool to_attribute(xmlNodePtr element, const char* name, const " << prefixed_name << "& value) {\n";
    oss << options_.indent << options_.indent << "if (!element || !name) return false;\n";
    oss << options_.indent << options_.indent << "std::string str_val = to_string(value);\n";
    oss << options_.indent << options_.indent << "xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());\n";
    oss << options_.indent << options_.indent << "return true;\n";
    oss << options_.indent << "}\n\n";
    
    oss << options_.indent << "static bool from_attribute(" << prefixed_name << "& value, xmlNodePtr element, const char* name) {\n";
    oss << options_.indent << options_.indent << "if (!element || !name) return false;\n";
    oss << options_.indent << options_.indent << "xmlChar* attr = xmlGetProp(element, BAD_CAST name);\n";
    oss << options_.indent << options_.indent << "if (!attr) return false;\n";
    oss << options_.indent << options_.indent << "std::string str_val(reinterpret_cast<char*>(attr));\n";
    oss << options_.indent << options_.indent << "xmlFree(attr);\n";
    oss << options_.indent << options_.indent << "return from_string(value, str_val);\n";
    oss << options_.indent << "}\n";
    oss << "};\n";
    
    return oss.str();
}

static bool type_is_num(const std::string &type) {
    static std::set<std::string_view> num_types = {
        "int", "int8_t", "int16_t", "int32_t", "int64_t",
        "uint", "uint8_t", "uint16_t", "uint32_t", "uint64_t",
        "float", "double"
    };
    return num_types.find(type) != num_types.end();
}

std::string TypeGenerator::generate_list_xml_traits(const WsdlType& type) const {
    std::ostringstream oss;

    std::string prefixed_name = get_prefixed_type_name(type);
    std::string element_cpp_type = TypeUtils::convert_xsd_to_cpp_type(type.list_item_type);

    oss << "// XmlValueAdapter specialization for list " << prefixed_name << "\n";
    oss << "template<>\n";
    oss << "struct xml_convert::XmlValueAdapter<" << prefixed_name << "> {\n";

    // from_xml_val方法 - 适配新的API，直接操作vector（不再有.value成员）
    oss << options_.indent << "static bool from_xml_val(" << prefixed_name << "& val, xmlNodePtr element, const char* name = nullptr,\n";
    oss << options_.indent << "                         const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {\n";
    oss << options_.indent << options_.indent << "xmlNodePtr targetElement = name ? \n";
    oss << options_.indent << options_.indent << "    xmlGetChildElementByName(element, name) : element;\n";
    oss << options_.indent << options_.indent << "if (!targetElement) return false;\n";
    oss << options_.indent << options_.indent << "val.clear();  // 直接操作vector，不再是val.value\n";
    oss << options_.indent << options_.indent << "xmlChar* content = xmlNodeGetContent(targetElement);\n";
    oss << options_.indent << options_.indent << "if (!content) return true;\n";
    oss << options_.indent << options_.indent << "std::string str_val(reinterpret_cast<char*>(content));\n";
    oss << options_.indent << options_.indent << "xmlFree(content);\n";
    oss << options_.indent << options_.indent << "std::istringstream iss(str_val);\n";
    oss << options_.indent << options_.indent << "std::string item;\n";
    oss << options_.indent << options_.indent << "while (iss >> item) {\n";

    // 根据元素类型进行转换
    if (element_cpp_type == "std::string") {
        oss << options_.indent << options_.indent << options_.indent << "val.push_back(item);\n";
    } else if (element_cpp_type == "int32_t" || element_cpp_type == "int64_t") {
        oss << options_.indent << options_.indent << options_.indent << "try {\n";
        oss << options_.indent << options_.indent << options_.indent << options_.indent << "val.push_back(std::stoll(item));\n";
        oss << options_.indent << options_.indent << options_.indent << "} catch (...) { return false; }\n";
    } else if (element_cpp_type == "double" || element_cpp_type == "float") {
        oss << options_.indent << options_.indent << options_.indent << "try {\n";
        oss << options_.indent << options_.indent << options_.indent << options_.indent << "val.push_back(std::stod(item));\n";
        oss << options_.indent << options_.indent << options_.indent << "} catch (...) { return false; }\n";
    } else if (element_cpp_type == "bool") {
        oss << options_.indent << options_.indent << options_.indent << "val.push_back(item == \"true\" || item == \"1\");\n";
    } else {
        oss << options_.indent << options_.indent << options_.indent << "val.push_back(item);\n";
    }
    
    oss << options_.indent << options_.indent << "}\n";
    oss << options_.indent << options_.indent << "return true;\n";
    oss << options_.indent << "}\n";
    oss << options_.indent << "\n";
    
    // to_xml_val方法 - 适配新的API，直接操作vector
    oss << options_.indent << "static bool to_xml_val(const " << prefixed_name << "& val, xmlNodePtr parent, const char* name,\n";
    oss << options_.indent << "                       const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {\n";
    oss << options_.indent << options_.indent << "if (!parent || !name) return false;\n";
    oss << options_.indent << options_.indent << "xmlNodePtr element = create_element_with_ns(parent, name, ns_prefix, namespaces);\n";
    oss << options_.indent << options_.indent << "if (!element) return false;\n";
    oss << options_.indent << options_.indent << "std::ostringstream oss;\n";
    oss << options_.indent << options_.indent << "for (size_t i = 0; i < val.size(); ++i) {\n";
    oss << options_.indent << options_.indent << options_.indent << "if (i > 0) oss << \" \";\n";

    if (element_cpp_type == "bool") {
        oss << options_.indent << options_.indent << options_.indent << "oss << (val[i] ? \"true\" : \"false\");\n";
    } else if (type_is_num(element_cpp_type)) {
        oss << options_.indent << options_.indent << options_.indent << "oss << std::to_string(val[i]);\n";
    } else if (element_cpp_type == "std::string" || element_cpp_type == "std::string_view") {
        oss << options_.indent << options_.indent << options_.indent << "oss << val[i];\n";
    } else {
        oss << options_.indent << options_.indent << options_.indent << "oss << val[i];\n";
    }
    
    oss << options_.indent << options_.indent << "}\n";
    oss << options_.indent << options_.indent << "xmlNodeSetContent(element, BAD_CAST oss.str().c_str());\n";
    oss << options_.indent << options_.indent << "return true;\n";
    oss << options_.indent << "}\n";
    oss << options_.indent << "\n";
    
    // 辅助函数
    oss << "private:\n";
    oss << options_.indent << "static xmlNodePtr create_element_with_ns(xmlNodePtr parent, const char* name, \n";
    oss << options_.indent << "                                        const char* ns_prefix, const std::map<std::string_view, std::string_view>& namespaces) {\n";
    oss << options_.indent << options_.indent << "xmlNodePtr element = xmlNewChild(parent, nullptr, BAD_CAST name, nullptr);\n";
    oss << options_.indent << options_.indent << "if (element && ns_prefix) {\n";
    oss << options_.indent << options_.indent << options_.indent << "auto it = namespaces.find(ns_prefix);\n";
    oss << options_.indent << options_.indent << options_.indent << "if (it != namespaces.end()) {\n";
    oss << options_.indent << options_.indent << options_.indent << options_.indent << "xmlNsPtr ns = xmlNewNs(element, BAD_CAST it->second.data(), BAD_CAST ns_prefix);\n";
    oss << options_.indent << options_.indent << options_.indent << options_.indent << "xmlSetNs(element, ns);\n";
    oss << options_.indent << options_.indent << options_.indent << "}\n";
    oss << options_.indent << options_.indent << "}\n";
    oss << options_.indent << options_.indent << "return element;\n";
    oss << options_.indent << "}\n";
    oss << options_.indent << "\n";
    oss << options_.indent << "static xmlNodePtr xmlGetChildElementByName(xmlNodePtr parent, const char* name) {\n";
    oss << options_.indent << options_.indent << "if (!parent || !name) return nullptr;\n";
    oss << options_.indent << options_.indent << "for (xmlNodePtr child = parent->children; child; child = child->next) {\n";
    oss << options_.indent << options_.indent << options_.indent << "if (child->type == XML_ELEMENT_NODE && \n";
    oss << options_.indent << options_.indent << options_.indent << "    xmlStrcmp(child->name, BAD_CAST name) == 0) {\n";
    oss << options_.indent << options_.indent << options_.indent << options_.indent << "return child;\n";
    oss << options_.indent << options_.indent << options_.indent << "}\n";
    oss << options_.indent << options_.indent << "}\n";
    oss << options_.indent << options_.indent << "return nullptr;\n";
    oss << options_.indent << "}\n";
    oss << "};\n";

    // 为所有列表类型生成 XmlAttributeAdapter 特化
    {
        oss << "// XmlAttributeAdapter specialization for list " << prefixed_name << "\n";
        oss << "template<>\n";
        oss << "struct xml_convert::XmlAttributeAdapter<" << prefixed_name << "> {\n";
        oss << options_.indent << "static bool to_attribute(xmlNodePtr element, const char* name, const " << prefixed_name << "& value) {\n";
        oss << options_.indent << options_.indent << "bool is_first = false; std::ostringstream oss; \n";
        oss << options_.indent << options_.indent << "for (const auto& item : value) {\n";
        oss << options_.indent << options_.indent << options_.indent << "if(!is_first) oss << \" \";\n";
        oss << options_.indent << options_.indent << options_.indent << options_.indent << "is_first = true;\n";
        if (element_cpp_type == "bool") {
            oss << options_.indent << options_.indent << options_.indent << options_.indent << "oss << (item ? \"true\" : \"false\");\n";
        } else if (type_is_num(element_cpp_type) || element_cpp_type == "std::string" || element_cpp_type == "std::string_view") {
            oss << options_.indent << options_.indent << options_.indent << options_.indent << "oss << item;\n";
        } else {
            oss << options_.indent << options_.indent << options_.indent << options_.indent << "oss << item;\n";
        }
        oss << options_.indent << options_.indent << "}\n";
        oss << options_.indent << options_.indent << "return xml_convert::XmlAttributeAdapter<std::string>::to_attribute(element, name, oss.str());\n";
        oss << options_.indent << "}\n";

        oss << options_.indent << "static bool from_attribute(" << prefixed_name << "& val, xmlNodePtr element, const char* name) {\n";
        oss << options_.indent << options_.indent << "std::string str_val;\n";
        oss << options_.indent << options_.indent << "if (!xml_convert::XmlAttributeAdapter<std::string>::from_attribute(str_val, element, name)) return false;\n";
        oss << options_.indent << options_.indent << "val.clear();  // 直接操作vector\n";
        oss << options_.indent << options_.indent << "size_t pos = 0, start = 0;\n";
        oss << options_.indent << options_.indent << "while(pos < str_val.size()) {\n";
        oss << options_.indent << options_.indent << options_.indent << "if (str_val[pos] == ' ') {\n";
        oss << options_.indent << options_.indent << options_.indent << options_.indent << "std::string_view sub(str_val.data() + start, pos - start);\n";
        oss << options_.indent << options_.indent << options_.indent << options_.indent << "start = pos + 1;\n";
        if (element_cpp_type == "bool") {
            oss << options_.indent << options_.indent << options_.indent << options_.indent << "if (sub == \"true\" || sub == \"True\"  || sub == \"1\") {\n";
            oss << options_.indent << options_.indent << options_.indent << options_.indent << "val.push_back(true);\n";
            oss << options_.indent << options_.indent << options_.indent << options_.indent << "} else {\n";
            oss << options_.indent << options_.indent << options_.indent << options_.indent << "val.push_back(false);\n";
            oss << options_.indent << options_.indent << options_.indent << options_.indent << "}\n";
        } else if (type_is_num(element_cpp_type)) {
            if (element_cpp_type == "double" || element_cpp_type == "float") {
                oss << options_.indent << options_.indent << options_.indent << options_.indent << "val.push_back(std::stod(sub.data()));\n";
            } else {
                oss << options_.indent << options_.indent << options_.indent << options_.indent << "val.push_back(std::stoll(sub.data()));\n";
            }
        } else {
            oss << options_.indent << options_.indent << options_.indent << options_.indent << "val.push_back(" << element_cpp_type << "(std::string(sub)));\n";
        }
        oss << options_.indent << options_.indent << options_.indent << "}\n";
        oss << options_.indent << options_.indent << options_.indent << "pos++;\n";

        oss << options_.indent << options_.indent << "}\n";
        oss << options_.indent << options_.indent << "return true;\n";
        oss << options_.indent << "}\n";
        oss << "};\n";
    }


    
    return oss.str();
}

std::string TypeGenerator::get_cpp_type_name(
    const std::string& type_name,
    const std::shared_ptr<FileInfo>& current_file,
    const std::vector<std::shared_ptr<FileInfo>>& all_files) const {
    
    // 这个方法现在被简化了，因为大部分工作已经在wsdl_parser中完成
    // 主要用于处理基础类型映射
    std::string basic_type = TypeUtils::convert_xsd_to_cpp_type(type_name);
    if (basic_type != type_name) {
        return basic_type; // 是基础类型，直接返回映射结果
    }
    
    // 对于自定义类型，确保符合C++标识符规范
    std::string result = type_name;
    std::replace(result.begin(), result.end(), '-', '_');
    std::replace(result.begin(), result.end(), ':', '_');
    
    return result;
}

std::string TypeGenerator::get_prefixed_type_name(const WsdlType& type) const {
    std::string name = type.name;
    std::string ns_prefix = type.ns_prefix;
    
    // Replace hyphens with underscores to ensure valid C++ identifiers
    std::replace(name.begin(), name.end(), '-', '_');
    std::replace(ns_prefix.begin(), ns_prefix.end(), '-', '_');
    
    if (ns_prefix.empty()) {
        return name;
    }
    return ns_prefix + "_" + name;
}

std::string TypeGenerator::sanitize_enum_value(const std::string& value) const {
    std::string result = value;
    
    // 替换特殊字符
    std::regex special_chars(R"([^a-zA-Z0-9_])");
    result = std::regex_replace(result, special_chars, "_");
    
    // 处理多个连续下划线
    std::regex multiple_underscores("_+");
    result = std::regex_replace(result, multiple_underscores, "_");
    
    // 移除开头和结尾的下划线
    while (!result.empty() && result.front() == '_') {
        result = result.substr(1);
    }
    while (!result.empty() && result.back() == '_') {
        result.pop_back();
    }
    
    // 确保以字母开头
    if (!result.empty() && std::isdigit(result[0])) {
        result = "VALUE_" + result;
    }
    
    // 如果为空，使用默认值
    if (result.empty()) {
        result = "UNKNOWN_VALUE";
    }
    
    return result;
}

std::string TypeGenerator::to_cpp_field_name(const std::string& name) const {
    std::string result;
    for (size_t i = 0; i < name.length(); ++i) {
        if (i > 0 && std::isupper(name[i]) && !std::isupper(name[i-1])) {
            result += '_';
        }
        result += std::tolower(name[i]);
    }
    return result;
}

std::string TypeGenerator::generate_doc_comment(const std::string& text, int indent_level) const {
    if (!options_.generate_comments || text.empty()) {
        return "";
    }
    
    std::string indent_str(indent_level * options_.indent.size(), ' ');
    
    // Check if the text contains newlines (multi-line)
    if (text.find('\n') != std::string::npos) {
        // Multi-line comment: use block comment format
        std::ostringstream oss;
        oss << indent_str << "/*\n";
        
        // Split text into lines and format each line
        std::istringstream iss(text);
        std::string line;
        while (std::getline(iss, line)) {
            // Trim whitespace from each line
            line.erase(0, line.find_first_not_of(" \t\r"));
            line.erase(line.find_last_not_of(" \t\r") + 1);
            
            if (!line.empty()) {
                oss << indent_str << " * " << line << "\n";
            } else {
                oss << indent_str << " *\n";
            }
        }
        
        oss << indent_str << " */\n";
        return oss.str();
    } else {
        // Single line comment: use // format
        return indent_str + "// " + text + "\n";
    }
}



std::string TypeGenerator::normalize_filename(const std::string& filename) const {
    std::string result = filename;
    
    // 替换连字符为下划线
    std::replace(result.begin(), result.end(), '-', '_');
    
    // 移除其他特殊字符，保留字母、数字、下划线和点
    std::string cleaned;
    for (char c : result) {
        if (std::isalnum(c) || c == '_' || c == '.') {
            cleaned += c;
        }
    }
    
    // 确保不以数字开头
    if (!cleaned.empty() && std::isdigit(cleaned[0])) {
        cleaned = "types_" + cleaned;
    }
    
    // 如果为空，使用默认名称
    if (cleaned.empty()) {
        cleaned = "unknown.h";
    }
    
    return cleaned;
}

std::string TypeGenerator::generate_header_name(const std::shared_ptr<FileInfo>& file_info) const {
    std::string header_name;
    
    // 优先级1: 通过目标命名空间和源文件匹配查找配置的输出文件名
    if (!file_info->target_namespace.empty()) {
        // 提取当前文件的文件名（不含路径）
        std::filesystem::path current_file_path(file_info->file_path);
        std::string current_filename = current_file_path.filename().string();

        for (const auto& schema_config : config_.schema_configs) {
            // 首先检查命名空间是否匹配
            if (schema_config.ns_url != file_info->target_namespace) {
                continue;
            }

            // 如果配置了 source_files，必须精确匹配源文件名
            if (!schema_config.source_files.empty()) {
                bool file_matches = false;
                for (const auto& source_file : schema_config.source_files) {
                    if (current_filename == source_file) {
                        file_matches = true;
                        break;
                    }
                }

                if (!file_matches) {
                    continue; // 源文件不匹配，继续查找下一个配置
                }
            }

            // 找到匹配的配置，优先使用 output_name
            if (!schema_config.output_name.empty()) {
                header_name = schema_config.output_name + ".h";
                if (config_.verbose) {
                    std::cout << "使用output_name: " << file_info->target_namespace
                              << " (源文件: " << current_filename << ") -> " << header_name << std::endl;
                }
            } else if (!schema_config.ns_prefix.empty()) {
                // 如果没有 output_name，才使用 ns_prefix
                header_name = schema_config.ns_prefix + ".h";
                if (config_.verbose) {
                    std::cout << "使用ns_prefix: " << file_info->target_namespace
                              << " (源文件: " << current_filename << ") -> " << header_name << std::endl;
                }
            }
            break; // 找到匹配的配置就停止
        }
    }
    
    // 优先级2: 使用文件的namespace_prefix（但要排除不合理的前缀）
    if (header_name.empty() && !file_info->namespace_prefix.empty()) {
        // 排除过于通用或不合理的前缀
        static const std::set<std::string> bad_prefixes = {
            "namespace", "ns", "xmlns", "default", "temp", "tmp"
        };
        
        if (bad_prefixes.find(file_info->namespace_prefix) == bad_prefixes.end()) {
            header_name = file_info->namespace_prefix + ".h";
            if (config_.verbose) {
                std::cout << "使用namespace_prefix: " << file_info->file_path
                          << " (ns_prefix: " << file_info->namespace_prefix << ") -> " << header_name << std::endl;
            }
        } else {
            if (config_.verbose) {
                std::cout << "跳过不合理的namespace_prefix: " << file_info->namespace_prefix 
                          << " for " << file_info->file_path << std::endl;
            }
        }
    }
    
    // 优先级3: 使用file_prefix_name
    if (header_name.empty() && !file_info->file_prefix_name.empty()) {
        header_name = file_info->file_prefix_name + ".h";
    }
    
    // 优先级4: 使用源文件名（智能推断）
    if (header_name.empty()) {
        std::filesystem::path path(file_info->file_path);
        std::string stem = path.stem().string();
        
        // 清理文件名，移除版本号等后缀
        if (stem.find("_http") != std::string::npos) {
            stem = stem.substr(0, stem.find("_http"));
        }
        if (stem.find("_v10") != std::string::npos) {
            stem = stem.substr(0, stem.find("_v10"));
        }
        if (stem.find("_v20") != std::string::npos) {
            stem = stem.substr(0, stem.find("_v20"));
        }
        
        // 智能映射：对于特殊的文件名，使用更合理的名称
        if (stem == "xml") {
            stem = "xml";  // xml.xsd -> xml_types
        } else if (stem == "soap-envelope") {
            stem = "soapenv";  // soap-envelope.xml -> soapenv_types
        } else if (stem == "ws-addr") {
            stem = "wsa";  // ws-addr.xsd -> wsa_types
        }
        // 可以根据需要添加更多映射...

        header_name = stem + ".h";
        if (config_.verbose) {
            std::cout << "使用文件名: " << file_info->file_path
                      << " (target_ns: " << file_info->target_namespace << ") -> " << header_name << std::endl;
        }
    }
    
    // 标准化文件名
    return normalize_filename(header_name);
}

std::string TypeGenerator::generate_header_name_for_namespace(const std::string& target_namespace, 
                                                              const std::string& source_file_path) const {
    std::string header_name;
    
    // 优先级1: 通过目标命名空间和源文件匹配查找配置的输出文件名
    if (!target_namespace.empty()) {
        // 提取源文件名（不含路径）
        std::string source_filename;
        if (!source_file_path.empty()) {
            std::filesystem::path path(source_file_path);
            source_filename = path.filename().string();
        }

        for (const auto& schema_config : config_.schema_configs) {
            // 首先检查命名空间是否匹配
            if (schema_config.ns_url != target_namespace) {
                continue;
            }

            // 如果有源文件名且配置了 source_files，必须匹配源文件名
            if (!source_filename.empty() && !schema_config.source_files.empty()) {
                bool file_matches = false;
                for (const auto& source_file : schema_config.source_files) {
                    if (source_filename == source_file) {
                        file_matches = true;
                        break;
                    }
                }

                if (!file_matches) {
                    continue; // 源文件不匹配，继续查找下一个配置
                }
            }

            // 找到匹配的配置，优先使用 output_name
            if (!schema_config.output_name.empty()) {
                header_name = schema_config.output_name + ".h";
            } else if (!schema_config.ns_prefix.empty()) {
                // 如果没有 output_name，才使用 ns_prefix
                header_name = schema_config.ns_prefix + ".h";
            }
            break; // 找到匹配的配置就停止
        }
    }
    
    // 优先级2: 使用源文件名
    if (header_name.empty() && !source_file_path.empty()) {
        std::filesystem::path path(source_file_path);
        std::string stem = path.stem().string();
        
        // 清理文件名，移除版本号等后缀
        if (stem.find("_http") != std::string::npos) {
            stem = stem.substr(0, stem.find("_http"));
        }
        if (stem.find("_v10") != std::string::npos) {
            stem = stem.substr(0, stem.find("_v10"));
        }
        if (stem.find("_v20") != std::string::npos) {
            stem = stem.substr(0, stem.find("_v20"));
        }
        
        header_name = stem + ".h";
    }

    // 优先级3: 默认名称
    if (header_name.empty()) {
        header_name = "unknown.h";
    }
    
    return normalize_filename(header_name);
}

void TypeGenerator::resolve_circular_dependencies(
    std::map<std::string, std::vector<std::shared_ptr<FileInfo>>>& file_groups,
    const std::vector<std::shared_ptr<FileInfo>>& all_files) const {
    
    // 构建文件依赖图
    std::map<std::string, std::set<std::string>> dependency_graph;
    std::map<std::string, std::shared_ptr<FileInfo>> filename_to_fileinfo;
    
    for (const auto& [filename, group_files] : file_groups) {
        dependency_graph[filename] = std::set<std::string>();
        
        // 收集该文件组的所有依赖
        for (const auto& file_info : group_files) {
            filename_to_fileinfo[filename] = file_info; // 记录映射关系
            
            for (const auto& dep_file : file_info->dependencies) {
                if (!dep_file || dep_file->types.empty()) continue;
                
                std::string dep_filename = generate_header_name(dep_file);
                if (dep_filename != filename) {
                    dependency_graph[filename].insert(dep_filename);
                }
            }
        }
    }
    
    // 检测循环依赖
    std::set<std::string> visited;
    std::set<std::string> visiting;
    std::vector<std::pair<std::string, std::string>> circular_deps;
    
    std::function<void(const std::string&, const std::string&)> detect_cycles = 
        [&](const std::string& current, const std::string& parent) {
        if (visiting.count(current)) {
            // 找到循环依赖
            circular_deps.push_back({parent, current});
            if (config_.verbose) {
                std::cout << "检测到循环依赖: " << parent << " -> " << current << std::endl;
            }
            return;
        }
        
        if (visited.count(current)) return;
        
        visiting.insert(current);
        
        for (const auto& dep : dependency_graph[current]) {
            detect_cycles(dep, current);
        }
        
        visiting.erase(current);
        visited.insert(current);
    };
    
    for (const auto& [filename, _] : file_groups) {
        if (!visited.count(filename)) {
            detect_cycles(filename, "");
        }
    }
    
    // 解决循环依赖：将循环依赖的文件进行拆分
    for (const auto& [file1, file2] : circular_deps) {
        if (config_.verbose) {
            std::cout << "解决循环依赖: 拆分 " << file1 << " 和 " << file2 << std::endl;
        }
        
        // 策略：将依赖的文件单独生成，避免合并
        // 这里可以通过修改文件名来实现拆分
        auto it1 = file_groups.find(file1);
        auto it2 = file_groups.find(file2);
        
        if (it1 != file_groups.end() && it2 != file_groups.end()) {
            // 如果两个文件都是合并的结果，尝试拆分
            if (it1->second.size() > 1) {
                // 拆分 file1
                for (size_t i = 1; i < it1->second.size(); ++i) {
                    std::string new_filename = generate_unique_filename(it1->second[i]);
                    file_groups[new_filename] = {it1->second[i]};
                }
                it1->second.resize(1); // 只保留第一个文件
            }
            
            if (it2->second.size() > 1) {
                // 拆分 file2
                for (size_t i = 1; i < it2->second.size(); ++i) {
                    std::string new_filename = generate_unique_filename(it2->second[i]);
                    file_groups[new_filename] = {it2->second[i]};
                }
                it2->second.resize(1); // 只保留第一个文件
            }
        }
    }
}

std::string TypeGenerator::generate_unique_filename(const std::shared_ptr<FileInfo>& file_info) const {
    // 为避免循环依赖，生成唯一的文件名
    std::string base_name;
    
    if (!file_info->file_prefix_name.empty()) {
        base_name = file_info->file_prefix_name;
    } else if (!file_info->namespace_prefix.empty()) {
        base_name = file_info->namespace_prefix;
    } else {
        std::filesystem::path path(file_info->file_path);
        base_name = path.stem().string();
    }
    
    // 添加命名空间后缀以确保唯一性
    if (!file_info->target_namespace.empty()) {
        size_t hash_val = std::hash<std::string>{}(file_info->target_namespace);
        base_name += "_" + std::to_string(hash_val % 10000);
    }
    
    return normalize_filename(base_name + ".h");
}


void TypeGenerator::validate_type_adapters(const std::vector<std::shared_ptr<FileInfo>>& files) const {
    std::map<std::string, TypeUsageContext> global_usage;
    
    // 收集全局类型使用情况
    for (const auto& file : files) {
        for (const auto& [type_name, usage] : file->type_usage) {
            auto& global_entry = global_usage[type_name];
            if (usage.used_as_attribute) {
                global_entry.used_as_attribute = true;
                global_entry.attribute_locations.insert(
                    usage.attribute_locations.begin(), 
                    usage.attribute_locations.end()
                );
            }
            if (usage.used_as_element) {
                global_entry.used_as_element = true;
                global_entry.element_locations.insert(
                    usage.element_locations.begin(), 
                    usage.element_locations.end()
                );
            }
        }
    }
    
    // 验证类型适配器完整性
    for (const auto& [type_name, usage] : global_usage) {
        if (usage.used_as_attribute) {
            // 查找类型定义
            bool found_type = false;
            bool has_attribute_adapter = false;
            
            for (const auto& file : files) {
                for (const auto& type : file->types) {
                    std::string full_type_name = type.ns_prefix.empty() ? 
                        type.name : type.ns_prefix + "_" + type.name;
                    
                    if (full_type_name == type_name || type.name == type_name) {
                        found_type = true;
                        // 检查是否会生成属性适配器
                        if (type.is_enum) {
                            has_attribute_adapter = true;
                        } else if (type.is_list) {
                            // 只有元素类型是基础类型的列表才会生成属性适配器
                            std::string element_cpp_type = TypeUtils::convert_xsd_to_cpp_type(type.list_item_type);
                            if (TypeUtils::is_basic_cpp_type(element_cpp_type)) {
                                has_attribute_adapter = true;
                            }
                        } else if (type.is_simple_type_rename) {
                            // 只有包装基础类型的 simple_type_rename 才会生成 XmlAttributeAdapter
                            std::string base_cpp_type = TypeUtils::convert_xsd_to_cpp_type(type.base_simple_type);
                            if (TypeUtils::is_basic_cpp_type(base_cpp_type)) {
                                has_attribute_adapter = true;
                            }
                        }
                        break;
                    }
                }
                if (found_type) break;
            }
            
            if (found_type && !has_attribute_adapter) {
                std::cout << "⚠️  类型 " << type_name << " 用作属性但缺少 XmlAttributeAdapter" << std::endl;
                std::cout << "   属性位置: ";
                for (const auto& loc : usage.attribute_locations) {
                    std::cout << loc << " ";
                }
                std::cout << std::endl;
            }
        }
        
        if (usage.needs_both_adapters()) {
            std::cout << "ℹ️  类型 " << type_name << " 同时用作元素和属性，已生成双重适配器" << std::endl;
        }
    }
}

int TypeGenerator::generate_separate_schema_files(
    const std::vector<std::shared_ptr<FileInfo>>& files) const {

    int generated_files = 0;

    // 收集所有需要生成的schema配置（包括配置的和自动发现的）
    // 使用 output_name 作为 key，因为同一个 namespace 可能需要生成多个文件
    std::map<std::string, SchemaConfig> all_schema_configs;

    // 1. 先添加配置文件中明确指定的
    for (const auto& schema_config : config_.schema_configs) {
        all_schema_configs[schema_config.output_name] = schema_config;
    }

    // 2. 自动发现所有解析的文件（包括通过wsdl:import导入的）
    for (const auto& file_info : files) {
        // 只跳过没有命名空间的文件，即使没有类型也生成（生成空文件）
        if (file_info->target_namespace.empty()) {
            continue;
        }

        // 生成自动配置的 output_name
        std::string raw_output_name = file_info->file_prefix_name.empty()
                                     ? file_info->namespace_prefix
                                     : file_info->file_prefix_name;
        // 移除.h后缀（如果有）再normalize
        if (raw_output_name.length() > 2 && raw_output_name.substr(raw_output_name.length() - 2) == ".h") {
            raw_output_name = raw_output_name.substr(0, raw_output_name.length() - 2);
        }
        // normalize: 将-替换为_
        std::replace(raw_output_name.begin(), raw_output_name.end(), '-', '_');

        // 如果该 output_name 还没有配置，自动创建一个
        if (all_schema_configs.find(raw_output_name) == all_schema_configs.end()) {
            SchemaConfig auto_config;
            auto_config.ns_url = file_info->target_namespace;
            auto_config.ns_prefix = file_info->namespace_prefix;
            auto_config.output_name = raw_output_name;
            auto_config.comment = "Auto-generated from wsdl:import";

            // 添加源文件
            std::filesystem::path file_path(file_info->file_path);
            auto_config.source_files.push_back(file_path.filename().string());

            all_schema_configs[raw_output_name] = auto_config;

            if (config_.verbose) {
                std::cout << "🔍 自动发现类型文件: " << auto_config.output_name
                         << " (namespace: " << auto_config.ns_url
                         << ", types: " << file_info->types.size() << ")" << std::endl;
            }
        }
    }

    // 将map转换为vector
    std::vector<const SchemaConfig*> separate_configs;
    std::vector<SchemaConfig> temp_configs; // 用于存储临时的SchemaConfig对象
    temp_configs.reserve(all_schema_configs.size());

    for (const auto& [output_name, schema_config] : all_schema_configs) {
        temp_configs.push_back(schema_config);
    }

    for (const auto& schema_config : temp_configs) {
        separate_configs.push_back(&schema_config);
    }
    
    // 首先预分析所有文件的依赖关系，建立依赖图
    std::map<std::string, std::set<std::string>> dependency_graph;
    std::map<std::string, const SchemaConfig*> config_map;
    
    // 建立配置映射 - 去重，保留最后一个同名配置
    for (const auto* schema_config : separate_configs) {
        config_map[schema_config->output_name] = schema_config;
    }
    
    // 从map重建去重后的配置列表
    std::vector<const SchemaConfig*> deduplicated_configs;
    std::set<std::string> added_names;
    for (const auto* schema_config : separate_configs) {
        if (added_names.find(schema_config->output_name) == added_names.end()) {
            deduplicated_configs.push_back(config_map[schema_config->output_name]);
            added_names.insert(schema_config->output_name);
        }
    }
    separate_configs = deduplicated_configs;
    
    // 为每个配置分析其依赖
    for (const auto* schema_config : separate_configs) {
        // 查找匹配的FileInfo
        std::vector<std::shared_ptr<FileInfo>> target_files;
        
        if (!schema_config->source_files.empty()) {
            for (const auto& source_file : schema_config->source_files) {
                for (const auto& file_info : files) {
                    std::filesystem::path file_path(file_info->file_path);
                    std::string filename = file_path.filename().string();
                    
                    if (filename == source_file) {
                        target_files.push_back(file_info);
                        break;
                    }
                }
            }
        } else {
            // 按命名空间查找
            for (const auto& file_info : files) {
                if (file_info->target_namespace == schema_config->ns_url) {
                    target_files.push_back(file_info);
                }
            }
        }
        
        if (!target_files.empty()) {
            // 合并所有匹配文件的类型
            std::vector<WsdlType> all_types;
            for (const auto& file_info : target_files) {
                all_types.insert(all_types.end(), file_info->types.begin(), file_info->types.end());
            }
            
            // 分析依赖
            auto deps = analyze_type_dependencies(all_types, files);
            dependency_graph[schema_config->output_name] = deps;
        }
    }
    
    // 基于依赖图进行拓扑排序
    std::vector<const SchemaConfig*> sorted_configs;
    std::set<std::string> processed_configs;
    
    std::function<void(const SchemaConfig*)> process_config = 
        [&](const SchemaConfig* config) {
            if (processed_configs.find(config->output_name) != processed_configs.end()) {
                return; // 已处理
            }
            
            // 先处理依赖
            auto deps_it = dependency_graph.find(config->output_name);
            if (deps_it != dependency_graph.end()) {
                for (const auto& dep_name : deps_it->second) {
                    auto it = config_map.find(dep_name);
                    if (it != config_map.end()) {
                        process_config(it->second);
                    }
                }
            }
            
            processed_configs.insert(config->output_name);
            sorted_configs.push_back(config);
        };
    
    for (const auto* schema_config : separate_configs) {
        process_config(schema_config);
    }
    
    // 为每个分离配置生成单独的类型文件
    for (const auto* schema_config : sorted_configs) {
        
        // 查找匹配的FileInfo - 严格按source_files匹配
        std::vector<std::shared_ptr<FileInfo>> target_files;
        
        if (!schema_config->source_files.empty()) {
            // 严格按指定的源文件查找 - 只处理明确指定的文件
            
            for (const auto& source_file : schema_config->source_files) {
                for (const auto& file_info : files) {
                    std::filesystem::path file_path(file_info->file_path);
                    std::string filename = file_path.filename().string();
                    
                    // 确保命名空间也匹配，避免错误包含
                    if (filename == source_file && file_info->target_namespace == schema_config->ns_url) {
                        target_files.push_back(file_info);
                        break;
                    }
                }
            }
        } else {
            // 如果没有指定源文件，按命名空间查找，但排除已被其他配置指定的文件
            std::set<std::string> excluded_files;
            
            // 收集所有被其他配置明确指定的文件
            for (const auto& other_config : config_.schema_configs) {
                if (&other_config != schema_config && !other_config.source_files.empty()) {
                    excluded_files.insert(other_config.source_files.begin(), other_config.source_files.end());
                }
            }
            
            for (const auto& file_info : files) {
                std::filesystem::path file_path(file_info->file_path);
                std::string filename = file_path.filename().string();
                
                if (file_info->target_namespace == schema_config->ns_url && 
                    excluded_files.find(filename) == excluded_files.end()) {
                    target_files.push_back(file_info);
                }
            }
        }
        
        if (target_files.empty()) {
            if (config_.verbose) {
                std::cout << "⚠️  未找到匹配的文件: " << schema_config->output_name << std::endl;
            }
            continue;
        }
        
        // 合并所有匹配文件的类型
        std::vector<WsdlType> all_types;
        for (const auto& file_info : target_files) {
            all_types.insert(all_types.end(), file_info->types.begin(), file_info->types.end());
        }

        // 即使没有类型也生成文件（生成空的或只包含依赖的头文件）
        if (all_types.empty()) {
            if (config_.verbose) {
                std::cout << "ℹ️  无类型定义，将生成空头文件: " << schema_config->output_name << std::endl;
            }
        }
        
        // 生成头文件内容
        std::string code = generate_separate_schema_types(target_files, *schema_config, files);
        
        // 写入文件（确保文件名经过normalize处理）
        std::string output_filename = normalize_filename(schema_config->output_name + ".h");
        std::string output_path = (std::filesystem::path(config().output_types_header_dir) / output_filename).string();
        
        std::ofstream out(output_path);
        if (!out.is_open()) {
            std::cerr << "❌ 无法创建文件: " << output_path << std::endl;
            continue;
        }
        
        out << code;
        out.close();
        
        std::cout << "✅ 生成分离类型文件: " << output_path 
                 << " (" << all_types.size() << " 个类型)" << std::endl;
        generated_files++;
    }
    
    return generated_files;
}

std::string TypeGenerator::generate_separate_schema_types(
    const std::vector<std::shared_ptr<FileInfo>>& target_files,
    const SchemaConfig& schema_config,
    const std::vector<std::shared_ptr<FileInfo>>& all_files) const {
    
    std::ostringstream oss;
    
    // 合并所有类型
    std::vector<WsdlType> all_types;
    std::string source_file_list;
    
    for (size_t i = 0; i < target_files.size(); ++i) {
        const auto& file_info = target_files[i];
        all_types.insert(all_types.end(), file_info->types.begin(), file_info->types.end());
        
        std::filesystem::path file_path(file_info->file_path);
        if (i > 0) source_file_list += ", ";
        source_file_list += file_path.filename().string();
    }
    
    // 生成文件头部注释
    oss << "/**\n";
    oss << " * @file " << schema_config.output_name << ".h\n";
    oss << " * @brief 从 " << source_file_list << " 生成的类型定义\n";
    oss << " * @namespace " << schema_config.ns_url << "\n";
    oss << " * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改\n";
    if (!schema_config.comment.empty()) {
        oss << " * @comment " << schema_config.comment << "\n";
    }
    oss << " */\n\n";
    
    oss << "#pragma once\n\n";
    
    // 合并文件级别依赖和类型级别依赖
    std::set<std::string> auto_dependencies;
    
    // 1. 收集文件级别的依赖（从解析时记录的依赖中获取）
    std::set<std::string> file_level_deps;
    for (const auto& file_info : target_files) {
        std::cout << "🔧 检查文件依赖: " << file_info->file_path 
                  << " (依赖数量: " << file_info->dependencies.size() << ")" << std::endl;
        
        for (const auto& dep_file : file_info->dependencies) {
            // 将依赖文件转换为对应的头文件名（不含.h后缀）
            std::string dep_header = generate_header_name(dep_file);
            // 移除.h后缀，避免后续重复添加
            if (dep_header.length() > 2 && dep_header.substr(dep_header.length() - 2) == ".h") {
                dep_header = dep_header.substr(0, dep_header.length() - 2);
            }
            // 避免自引用
            if (dep_header != schema_config.output_name) {
                file_level_deps.insert(dep_header);
                std::cout << "  ➡️ 文件依赖: " << dep_file->file_path << " -> " << dep_header << std::endl;
            }
        }
    }
    
    // 2. 分析类型级别的依赖
    std::set<std::string> type_level_deps_raw = analyze_type_dependencies(all_types, all_files);

    // 2.1. 标准化类型级依赖（移除.h后缀）
    std::set<std::string> type_level_deps;
    for (const auto& dep : type_level_deps_raw) {
        std::string normalized_dep = dep;
        if (normalized_dep.length() > 2 && normalized_dep.substr(normalized_dep.length() - 2) == ".h") {
            normalized_dep = normalized_dep.substr(0, normalized_dep.length() - 2);
        }
        type_level_deps.insert(normalized_dep);
    }

    // 2.2. 补充配置文件中指定的依赖（SchemaConfig::dependencies）
    std::set<std::string> config_level_deps;
    if (!schema_config.dependencies.empty()) {
        std::cout << "🔧 检查配置文件依赖: " << schema_config.dependencies.size() << " 个" << std::endl;

        for (const auto& dep_source_file : schema_config.dependencies) {
            // 在所有文件中查找匹配的文件
            for (const auto& potential_dep : all_files) {
                if (!potential_dep || potential_dep->types.empty()) continue;

                std::string file_path = potential_dep->file_path;
                // 使用部分字符串匹配来查找文件
                if (file_path.find(dep_source_file) != std::string::npos) {
                    std::string dep_header = generate_header_name(potential_dep);

                    // 标准化：移除.h后缀
                    if (dep_header.length() > 2 && dep_header.substr(dep_header.length() - 2) == ".h") {
                        dep_header = dep_header.substr(0, dep_header.length() - 2);
                    }

                    // 避免自引用
                    if (dep_header != schema_config.output_name) {
                        config_level_deps.insert(dep_header);
                        std::cout << "  ✅ 配置依赖收集: " << schema_config.output_name << " -> " << dep_header
                                 << " (配置来源: " << dep_source_file << ")" << std::endl;
                    }
                    break; // 找到第一个匹配的就停止
                }
            }
        }
    }

    // 3. 合并依赖（文件级别 + 类型级别 + 配置级别）
    auto_dependencies.insert(file_level_deps.begin(), file_level_deps.end());
    auto_dependencies.insert(type_level_deps.begin(), type_level_deps.end());
    auto_dependencies.insert(config_level_deps.begin(), config_level_deps.end());
    
    if (config_.verbose) {
        std::cout << "🔍 " << schema_config.output_name << " 文件级依赖: ";
        for (const auto& dep : file_level_deps) {
            std::cout << dep << " ";
        }
        std::cout << std::endl;

        std::cout << "🔍 " << schema_config.output_name << " 类型级依赖: ";
        for (const auto& dep : type_level_deps) {
            std::cout << dep << " ";
        }
        std::cout << std::endl;

        std::cout << "🔍 " << schema_config.output_name << " 配置级依赖: ";
        for (const auto& dep : config_level_deps) {
            std::cout << dep << " ";
        }
        std::cout << std::endl;

        std::cout << "🔍 " << schema_config.output_name << " 最终依赖: ";
        for (const auto& dep : auto_dependencies) {
            std::cout << dep << " ";
        }
        std::cout << std::endl;
    }
    if (!auto_dependencies.empty()) {
        oss << "// 依赖的类型定义\n";
        for (const auto& dep : auto_dependencies) {
            if (dep != schema_config.output_name) { // 避免自引用
                oss << "#include <libonvif_client/types/" << dep << ".h>\n";
            }
        }
        oss << "\n";
    }
    
    // 标准库头文件
    oss << "// 标准库头文件\n";
    oss << "#include <string>\n";
    oss << "#include <vector>\n";
    oss << "#include <optional>\n";
    oss << "#include <memory>\n";
    oss << "#include <map>\n";
    oss << "#include <cstdint>\n";
    oss << "#include <sstream>\n\n";

    // 框架头文件
    oss << "// libonvif_client框架头文件\n";
    oss << "#include " << config().xml_convert_path << "\n";
    oss << "#include " << "\"" << config().base_types_path.substr(1, config().base_types_path.length() - 2) << "\"" << "\n\n";

    // 开始命名空间
    oss << "namespace " << config().client_namespace << " {\n\n";

    // 对合并的类型进行拓扑排序并检测循环依赖
    auto sort_result = topological_sort_types(all_types);

    // 生成循环依赖类型的前置声明
    if (!sort_result.circular_types.empty()) {
        oss << "// 前置声明（循环依赖的类型）\n";
        for (const auto& type_name : sort_result.circular_types) {
            // 找到对应的类型以获取完整的前缀名
            for (const auto& type : all_types) {
                if (type.name == type_name) {
                    oss << "struct " << get_prefixed_type_name(type) << ";\n";
                    break;
                }
            }
        }
        oss << "\n";
    }

    // 跟踪已生成的列表类型（用于去重）
    std::map<std::string, std::string> generated_list_types;  // underlying_type -> first_type_name

    // 生成类型定义
    for (const auto& type : sort_result.sorted_types) {
        if (type.is_enum) {
            oss << generate_enum(type) << "\n\n";
        } else if (type.is_list) {
            // 检查是否重复定义
            std::string element_cpp_type = TypeUtils::convert_xsd_to_cpp_type(type.list_item_type);
            std::string underlying_type = "std::vector<" + element_cpp_type + ">";
            std::string prefixed_name = get_prefixed_type_name(type);

            auto it = generated_list_types.find(underlying_type);
            if (it != generated_list_types.end()) {
                // 重复定义：生成别名指向第一个定义
                if (options_.generate_comments) {
                    oss << "// " << type.name << " 列表类型别名（与 " << it->second << " 相同）\n";
                    oss << "// 元素类型: " << type.list_item_type << "\n";
                }
                oss << "using " << prefixed_name << " = " << it->second << ";\n\n";
            } else {
                // 首次定义：正常生成
                oss << generate_list_type(type) << "\n\n";
                generated_list_types[underlying_type] = prefixed_name;
            }
        } else if (type.is_simple_type_rename) {
            oss << generate_simple_type_rename(type, target_files.empty() ? nullptr : target_files[0]) << "\n\n";
        } else {
            // 对于结构体，需要传递合适的文件信息
            oss << generate_struct(type, target_files.empty() ? nullptr : target_files[0], all_files) << "\n\n";
        }

        // 生成XML Traits
        if (options_.generate_xml_traits) {
            if (type.is_enum) {
                oss << generate_enum_xml_traits(type) << "\n\n";
            } else if (type.is_list) {
                // 检查是否为重复定义
                std::string element_cpp_type = TypeUtils::convert_xsd_to_cpp_type(type.list_item_type);
                std::string underlying_type = "std::vector<" + element_cpp_type + ">";
                std::string prefixed_name = get_prefixed_type_name(type);

                auto it = generated_list_types.find(underlying_type);
                if (it != generated_list_types.end() && it->second != prefixed_name) {
                    // 重复定义：添加注释说明共享适配器
                    oss << "// Note: " << prefixed_name << " shares XmlValueAdapter with " << it->second << "\n\n";
                } else {
                    // 首次定义：生成适配器
                    if (TypeUtils::is_basic_cpp_type(element_cpp_type)) {
                        oss << generate_list_xml_traits(type) << "\n\n";
                    } else {
                        oss << "// Note: " << prefixed_name
                            << " uses generic std::vector adapter (element type is complex)\n\n";
                    }
                }
            } else if (!type.is_simple_type_rename) {
                // 简单类型别名不需要特殊的 Adapter
                oss << generate_xml_traits(type) << "\n\n";
            }
        }
    }
    
    // 结束命名空间
    oss << "} // namespace " << config().client_namespace << "\n";
    
    return oss.str();
}

std::set<std::string> TypeGenerator::analyze_type_dependencies(
    const std::vector<WsdlType>& types,
    const std::vector<std::shared_ptr<FileInfo>>& all_files) const {
    
    std::set<std::string> dependencies;
    std::set<std::string> current_types; // 当前文件中定义的类型
    
    // 收集当前文件中定义的所有类型名
    for (const auto& type : types) {
        current_types.insert(type.name);
        // 也添加带命名空间前缀的版本
        if (!type.ns_prefix.empty()) {
            current_types.insert(type.ns_prefix + "_" + type.name);
        }
    }
    
    // 分析每个类型的依赖
    for (const auto& type : types) {
        analyze_single_type_dependencies(type, current_types, all_files, dependencies);
    }
    
    return dependencies;
}

void TypeGenerator::analyze_single_type_dependencies(
    const WsdlType& type,
    const std::set<std::string>& current_types,
    const std::vector<std::shared_ptr<FileInfo>>& all_files,
    std::set<std::string>& dependencies) const {
    
    // 分析基类型依赖
    if (!type.base_type.empty() && !TypeUtils::is_basic_cpp_type(type.base_type)) {
        std::string clean_base_type = TypeUtils::clean_type_name(type.base_type);
        if (current_types.count(clean_base_type) == 0) {
            find_type_dependency(clean_base_type, all_files, dependencies);
        }
    }
    
    // 分析简单类型重命名的基础类型依赖
    if (type.is_simple_type_rename && !type.base_simple_type.empty() && !TypeUtils::is_basic_cpp_type(type.base_simple_type)) {
        std::string clean_base_simple_type = TypeUtils::clean_type_name(type.base_simple_type);
        if (current_types.count(clean_base_simple_type) == 0) {
            find_type_dependency(clean_base_simple_type, all_files, dependencies);
        }
    }
    
    // 分析结构体字段的依赖
    for (const auto& field : type.fields) {
        std::string clean_type = TypeUtils::clean_type_name(field.type);
        
        // 跳过基础类型和当前文件中定义的类型
        if (TypeUtils::is_basic_cpp_type(clean_type) || current_types.count(clean_type) > 0) {
            continue;
        }
        
        find_type_dependency(clean_type, all_files, dependencies);
    }
    
    // 分析枚举值和其他可能的依赖...
    // （这里可以根据需要添加更多分析逻辑）
}

void TypeGenerator::find_type_dependency(
    const std::string& clean_type,
    const std::vector<std::shared_ptr<FileInfo>>& all_files,
    std::set<std::string>& dependencies) const {

    // 首先尝试在当前解析的文件中查找类型定义
    for (const auto& file_info : all_files) {
        for (const auto& file_type : file_info->types) {
            if (file_type.name == clean_type ||
                (file_type.ns_prefix + "_" + file_type.name) == clean_type) {

                // 直接使用 generate_header_name 生成头文件名
                // 这个函数会根据 file_info 的命名空间和前缀生成正确的文件名
                std::string dep_header = generate_header_name(file_info);
                dependencies.insert(dep_header);
                return; // 找到就返回
            }
        }
    }

    // 如果在当前文件中没找到，尝试根据类型前缀推断依赖
    std::string inferred_dependency = infer_dependency_from_type_prefix(clean_type);
    if (!inferred_dependency.empty()) {
        // 推断的依赖名需要转换为头文件名格式
        dependencies.insert(inferred_dependency + ".h");
    }
}


std::string TypeGenerator::infer_dependency_from_type_prefix(const std::string& clean_type) const {
    // 根据类型前缀推断依赖关系
    if (clean_type.empty()) {
        return "";
    }
    
    // 寻找下划线分隔的前缀
    size_t pos = clean_type.find('_');
    if (pos == std::string::npos || pos == 0) {
        return "";
    }
    
    std::string prefix = clean_type.substr(0, pos);
    
    // 根据前缀查找对应的schema配置
    for (const auto& schema_config : config_.schema_configs) {
        if (schema_config.ns_prefix == prefix) {
            return schema_config.output_name;
        }
    }
    
    return "";
}


std::string TypeGenerator::generate_namespace_mappings(
    const std::vector<std::shared_ptr<FileInfo>>& files) const {

    std::ostringstream oss;

    // 文件头
    oss << "/**\n";
    oss << " * @file onvif_namespaces.cpp\n";
    oss << " * @brief ONVIF 全局命名空间映射实现\n";
    oss << " * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改\n";
    oss << " */\n\n";

    oss << "#include <libonvif_client/core/onvif_service_base.h>\n";
    oss << "#include <unordered_map>\n";
    oss << "#include <string>\n\n";

    oss << "namespace " << config().client_namespace << " {\n\n";

    // 收集所有唯一的命名空间映射
    std::map<std::string, std::string> namespace_map;

    for (const auto& file : files) {
        if (!file || file->target_namespace.empty()) continue;

        // 直接使用 file->namespace_prefix 和 file->target_namespace
        if (!file->namespace_prefix.empty()) {
            namespace_map[file->namespace_prefix] = file->target_namespace;
        }
    }

    // 生成 ns_map_ 实现
    oss << "/**\n";
    oss << " * @brief 全局命名空间映射表\n";
    oss << " * 用于SOAP消息序列化时的命名空间前缀解析\n";
    oss << " */\n";
    oss << "std::map<std::string_view, std::string_view> ns_map_ = {\n";

    // 按前缀排序输出
    for (auto it = namespace_map.begin(); it != namespace_map.end(); ) {
        oss << "    {\"" << it->first << "\", \"" << it->second << "\"}";
        if (++it != namespace_map.end()) {
            oss << ",";
        }
        oss << "\n";
    }

    oss << "};\n\n";

    oss << "} // namespace " << config().client_namespace << "\n";

    return oss.str();
}


std::string TypeGenerator::generate_namespace_mappings_header(
    const std::vector<std::shared_ptr<FileInfo>>& files) const {

    std::ostringstream oss;

    // 文件头
    oss << "/**\n";
    oss << " * @file namespaces.h\n";
    oss << " * @brief ONVIF 全局命名空间映射（header-only）\n";
    oss << " * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改\n";
    oss << " */\n\n";

    oss << "#pragma once\n\n";

    oss << "#include <string_view>\n";
    oss << "#include <array>\n\n";

    oss << "namespace " << config().client_namespace << " {\n\n";

    // 收集所有唯一的命名空间映射
    std::map<std::string, std::string> namespace_map;

    for (const auto& file : files) {
        if (!file || file->target_namespace.empty()) continue;

        // 直接使用 file->namespace_prefix 和 file->target_namespace
        if (!file->namespace_prefix.empty()) {
            namespace_map[file->namespace_prefix] = file->target_namespace;
        }
    }

    // 生成命名空间对结构
    oss << "/**\n";
    oss << " * @brief 命名空间对\n";
    oss << " */\n";
    oss << "struct namespace_pair {\n";
    oss << "    constexpr namespace_pair(const char* p, const char* u)\n";
    oss << "        : prefix(p), uri(u) {}\n";
    oss << "    const char* prefix;   // 命名空间前缀\n";
    oss << "    const char* uri;      // 命名空间 URI\n";
    oss << "};\n\n";

    // 先生成命名空间映射数组（查找函数会复用它）
    oss << "/**\n";
    oss << " * @brief 所有命名空间映射\n";
    oss << " */\n";
    oss << "inline constexpr std::array<namespace_pair, " << namespace_map.size() << "> g_namespace_mappings = {{\n";

    for (const auto& [prefix, ns_uri] : namespace_map) {
        oss << "    namespace_pair{\"" << prefix << "\", \"" << ns_uri << "\"},\n";
    }

    oss << "}};\n\n";

    // 生成查找函数 - 复用 g_namespace_mappings
    oss << "/**\n";
    oss << " * @brief 根据 URI 查找命名空间前缀\n";
    oss << " * @param uri 命名空间 URI\n";
    oss << " * @return 命名空间前缀，未找到返回 nullptr\n";
    oss << " */\n";
    oss << "[[nodiscard]]\n";
    oss << "constexpr const char* find_namespace_prefix(const std::string_view& uri) noexcept {\n";
    oss << "    for (const auto& [prefix, u] : g_namespace_mappings) {\n";
    oss << "        if (uri == u) return prefix;\n";
    oss << "    }\n";
    oss << "    return nullptr;\n";
    oss << "}\n\n";

    oss << "/**\n";
    oss << " * @brief 根据前缀查找命名空间 URI\n";
    oss << " * @param prefix 命名空间前缀\n";
    oss << " * @return 命名空间 URI，未找到返回 nullptr\n";
    oss << " */\n";
    oss << "[[nodiscard]]\n";
    oss << "constexpr const char* find_namespace_uri(const std::string_view& prefix) noexcept {\n";
    oss << "    for (const auto& [p, uri] : g_namespace_mappings) {\n";
    oss << "        if (prefix == p) return uri;\n";
    oss << "    }\n";
    oss << "    return nullptr;\n";
    oss << "}\n\n";

    oss << "} // namespace " << config().client_namespace << "\n";

    return oss.str();
}

} // namespace wsdl_parser2