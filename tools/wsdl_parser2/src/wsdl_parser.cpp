/**
 * @file wsdl_parser.cpp
 * @brief WSDL/XSD解析器实现
 */

#include "wsdl_parser.h"
#include "type_utils.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>
#include <filesystem>
#include <functional>
#include <libxml/parser.h>
#include <libxml/tree.h>

namespace wsdl_parser2 {

// ParseResult实现
std::vector<WsdlType> ParseResult::get_all_types() const {
    std::vector<WsdlType> all_types;
    for (const auto& file : files) {
        all_types.insert(all_types.end(), file->types.begin(), file->types.end());
    }
    return all_types;
}

std::vector<WsdlService> ParseResult::get_all_services() const {
    std::vector<WsdlService> all_services;
    for (const auto& file : files) {
        all_services.insert(all_services.end(), file->services.begin(), file->services.end());
    }
    return all_services;
}

// WsdlParser实现
WsdlParser::WsdlParser(const ParserConfig& config) 
    : config_(config) {
    // 初始化libxml2
    xmlInitParser();
    
    // 创建下载器
    downloader_ = std::make_unique<Downloader>(config_.cache_dir, config_.download_timeout);
}

WsdlParser::~WsdlParser() {
    // 清理libxml2
    xmlCleanupParser();
}

ParseResult WsdlParser::parse(const std::string& file_path) {
    return parse_multiple({file_path});
}

ParseResult WsdlParser::parse_multiple(const std::vector<std::string>& file_paths) {
    ParseResult result;
    
    try {
        // 加载所有文件
        std::vector<std::shared_ptr<FileInfo>> files;
        for (const auto& path : file_paths) {
            auto file_info = load_file(path);
            if (file_info) {
                files.push_back(file_info);
            } else {
                result.warnings.push_back("无法加载文件: " + path);
            }
        }
        
        if (files.empty()) {
            result.error_message = "没有成功加载任何文件";
            return result;
        }
        
        // 解析文件
        bool all_success = true;
        for (auto& file_info : files) {
            if (config_.verbose) {
                std::cout << "解析文件: " << file_info->file_path << std::endl;
            }
            
            if (!parse_file(file_info)) {
                all_success = false;
                result.warnings.push_back("解析文件失败: " + file_info->file_path);
                if (!config_.ignore_missing_deps) {
                    result.error_message = "文件解析失败: " + file_info->file_path;
                    return result;
                }
            }
        }
        
        // 处理依赖关系
        resolve_dependencies(files);
        
        // 收集所有文件（包括依赖文件）
        std::vector<std::shared_ptr<FileInfo>> all_files = files;
        std::set<std::shared_ptr<FileInfo>> processed_files;
        
        // 递归收集所有依赖文件
        std::function<void(const std::shared_ptr<FileInfo>&)> collect_dependencies = 
            [&](const std::shared_ptr<FileInfo>& file_info) {
                if (processed_files.find(file_info) != processed_files.end()) {
                    return; // 已处理过
                }
                processed_files.insert(file_info);
                
                for (const auto& dep : file_info->dependencies) {
                    if (dep && processed_files.find(dep) == processed_files.end()) {
                        all_files.push_back(dep);
                        collect_dependencies(dep);
                    }
                }
            };
        
        for (const auto& file_info : files) {
            collect_dependencies(file_info);
        }
        
        // 确定命名空间信息
        for (auto& file_info : all_files) {
            determine_namespace_info(file_info);
        }
        
        result.success = all_success || config_.ignore_missing_deps;
        result.files = all_files;
        result.global_namespaces = global_namespaces_;
        
    } catch (const std::exception& e) {
        result.error_message = std::string("解析异常: ") + e.what();
    }
    
    return result;
}

std::shared_ptr<FileInfo> WsdlParser::load_file(const std::string& file_path) {
    // 检查是否已经加载过
    auto it = loaded_files_.find(file_path);
    if (it != loaded_files_.end()) {
        return it->second;
    }
    
    // 检查是否正在处理中（防止循环依赖）
    if (processing_files_.find(file_path) != processing_files_.end()) {
        if (config_.verbose) {
            std::cout << "检测到循环依赖，跳过: " << file_path << std::endl;
        }
        return nullptr; // 返回nullptr表示循环依赖
    }
    
    // 标记为正在处理
    processing_files_.insert(file_path);
    
    auto file_info = std::make_shared<FileInfo>();
    file_info->status = FileStatus::PROCESSING;
    
    std::string local_path = file_path;
    
    // 如果是URL，先下载
    if (is_url(file_path)) {
        file_info->network_url = file_path;
        
        if (config_.verbose) {
            std::cout << "下载文件: " << file_path << std::endl;
        }
        
        auto download_result = downloader_->download(file_path);
        if (!download_result.success) {
            std::cerr << "下载失败: " << download_result.error_message << std::endl;
            file_info->status = FileStatus::FAILED;
            file_info->error_message = download_result.error_message;
            processing_files_.erase(file_path);
            return nullptr;
        }
        
        local_path = download_result.local_path;
    }
    
    // 检查文件是否存在
    if (!std::filesystem::exists(local_path)) {
        std::cerr << "文件不存在: " << local_path << std::endl;
        file_info->status = FileStatus::FAILED;
        file_info->error_message = "文件不存在";
        processing_files_.erase(file_path);
        return nullptr;
    }
    
    // 设置文件信息
    file_info->file_path = std::filesystem::absolute(local_path).string();
    
    // 获取文件名和类型
    std::filesystem::path path(file_info->file_path);
    file_info->file_name = path.stem().string();
    std::string extension = path.extension().string();
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    
    if (extension == ".wsdl") {
        file_info->file_type = "wsdl";
    } else if (extension == ".xsd" || extension == ".xml") {
        file_info->file_type = "xsd";  // 将 .xml 文件视为 XSD 文件
    } else {
        // 尝试基于内容检测文件类型
        if (config_.verbose) {
            std::cout << "尝试通过内容检测文件类型: " << file_info->file_path << std::endl;
        }
        std::string detected_type = detect_file_type_by_content(file_info->file_path);
        if (!detected_type.empty()) {
            file_info->file_type = detected_type;
            if (config_.verbose) {
                std::cout << "通过内容检测确定文件类型: " << file_info->file_path 
                          << " -> " << detected_type << std::endl;
            }
        } else {
            std::cerr << "未知文件类型: " << extension << " (文件: " << file_info->file_path << ")" << std::endl;
            file_info->status = FileStatus::FAILED;
            file_info->error_message = "未知文件类型";
            processing_files_.erase(file_path);
            return nullptr;
        }
    }
    
    // 解析XML文档
    xmlDocPtr doc = xmlReadFile(file_info->file_path.c_str(), nullptr, 0);
    if (!doc) {
        std::cerr << "无法解析XML文件: " << file_info->file_path << std::endl;
        file_info->status = FileStatus::FAILED;
        file_info->error_message = "XML解析失败";
        processing_files_.erase(file_path);
        return nullptr;
    }
    
    file_info->xml_doc = std::shared_ptr<xmlDoc>(doc, xmlFreeDoc);
    file_info->status = FileStatus::COMPLETED;
    
    // 缓存文件信息
    loaded_files_[file_path] = file_info;
    
    // 移除处理标记
    processing_files_.erase(file_path);
    
    return file_info;
}

bool WsdlParser::parse_file(std::shared_ptr<FileInfo> file_info) {
    if (!file_info || !file_info->xml_doc) {
        return false;
    }
    
    xmlNodePtr root = xmlDocGetRootElement(file_info->xml_doc.get());
    if (!root) {
        return false;
    }
    
    // 收集命名空间
    collect_namespaces(file_info, root);
    
    // 根据文件类型解析
    if (file_info->file_type == "wsdl") {
        return parse_wsdl_file(file_info, root);
    } else if (file_info->file_type == "xsd") {
        return parse_xsd_file(file_info, root);
    }
    
    return false;
}

bool WsdlParser::parse_wsdl_file(std::shared_ptr<FileInfo> file_info, xmlNodePtr root) {
    std::string root_name = reinterpret_cast<const char*>(root->name);
    if (root_name != "definitions") {
        std::cerr << "无效的WSDL文件，根节点不是definitions" << std::endl;
        return false;
    }

    // 获取目标命名空间
    file_info->target_namespace = get_node_attribute(root, "targetNamespace");

    // 第一阶段：处理 wsdl:import（必须在处理 types 之前）
    for (xmlNodePtr child = root->children; child; child = child->next) {
        if (child->type != XML_ELEMENT_NODE) continue;

        std::string node_name = reinterpret_cast<const char*>(child->name);

        // 处理 wsdl:import 元素
        if (node_name == "import") {
            parse_wsdl_import(file_info, child);
        }
    }

    // 第二阶段：解析 types 部分
    for (xmlNodePtr child = root->children; child; child = child->next) {
        if (child->type != XML_ELEMENT_NODE) continue;

        std::string node_name = reinterpret_cast<const char*>(child->name);
        if (node_name == "types") {
            // 查找schema节点
            for (xmlNodePtr schema_child = child->children; schema_child; schema_child = schema_child->next) {
                if (schema_child->type == XML_ELEMENT_NODE &&
                    std::string(reinterpret_cast<const char*>(schema_child->name)) == "schema") {
                    parse_schema(file_info, schema_child);
                }
            }
        }
    }

    // 第三阶段：解析消息定义
    parse_messages(file_info, root);

    // 第四阶段：解析服务定义
    parse_services(file_info, root);

    return true;
}

bool WsdlParser::parse_xsd_file(std::shared_ptr<FileInfo> file_info, xmlNodePtr root) {
    std::string root_name = reinterpret_cast<const char*>(root->name);
    if (root_name != "schema") {
        std::cerr << "无效的XSD文件，根节点不是schema" << std::endl;
        return false;
    }
    
    parse_schema(file_info, root);
    return true;
}

void WsdlParser::collect_namespaces(std::shared_ptr<FileInfo> file_info, xmlNodePtr node) {
    // 收集命名空间声明
    for (xmlNsPtr ns = node->nsDef; ns; ns = ns->next) {
        if (ns->prefix && ns->href) {
            std::string prefix = reinterpret_cast<const char*>(ns->prefix);
            std::string uri = reinterpret_cast<const char*>(ns->href);
            
            file_info->namespaces[prefix] = uri;
            global_namespaces_[prefix] = uri;
        }
    }
}

void WsdlParser::parse_schema(std::shared_ptr<FileInfo> file_info, xmlNodePtr schema_node) {
    // 获取目标命名空间
    if (file_info->target_namespace.empty()) {
        file_info->target_namespace = get_node_attribute(schema_node, "targetNamespace");
    }

    // 解析子节点
    for (xmlNodePtr child = schema_node->children; child; child = child->next) {
        if (child->type != XML_ELEMENT_NODE) continue;
        
        std::string node_name = reinterpret_cast<const char*>(child->name);
        
        if (node_name == "import" || node_name == "include") {
            parse_import(file_info, child);
        } else if (node_name == "complexType") {
            parse_complex_type(file_info, child, file_info->target_namespace);
        } else if (node_name == "simpleType") {
            parse_simple_type(file_info, child, file_info->target_namespace);
        } else if (node_name == "element") {
            parse_top_level_element(file_info, child);
        }
    }
}

void WsdlParser::parse_complex_type(std::shared_ptr<FileInfo> file_info, 
                                   xmlNodePtr complex_type_node, 
                                   const std::string& target_ns) {
    WsdlType type;
    type.name = get_node_attribute(complex_type_node, "name");
    type.ns_uri = target_ns;
    type.source_file = file_info->file_path;

    if (type.name.empty()) {
        return; // 跳过匿名类型
    }
    
    // 检查mixed属性
    std::string mixed_attr = get_node_attribute(complex_type_node, "mixed");
    type.is_mixed = (mixed_attr == "true");
    
    // 解析内容
    for (xmlNodePtr child = complex_type_node->children; child; child = child->next) {
        if (child->type != XML_ELEMENT_NODE) continue;
        
        std::string node_name = reinterpret_cast<const char*>(child->name);
        
        if (node_name == "sequence") {
            for (xmlNodePtr seq_child = child->children; seq_child; seq_child = seq_child->next) {
                if (seq_child->type == XML_ELEMENT_NODE) {
                    std::string seq_node_name = reinterpret_cast<const char*>(seq_child->name);
                    if (seq_node_name == "element") {
                        parse_element(type, seq_child, file_info->namespace_prefix, file_info);
                    } else if (seq_node_name == "any") {
                        parse_any_element(type, seq_child, file_info->namespace_prefix);
                    }
                }
            }
        } else if (node_name == "attribute") {
            parse_attribute(file_info, type, child);
        } else if (node_name == "anyAttribute") {
            parse_any_attribute(type, child);
        } else if (node_name == "simpleContent" || node_name == "complexContent") {
            parse_inheritance(type, child, file_info->namespace_prefix, file_info);
        }
    }
    
    file_info->types.push_back(type);
    // 设置字段的父级类型引用以优化后续查找
}

void WsdlParser::parse_top_level_element(std::shared_ptr<FileInfo> file_info, xmlNodePtr element_node) {
    std::string element_name = get_node_attribute(element_node, "name");
    std::string element_type = get_node_attribute(element_node, "type");
    
    if (element_name.empty()) {
        return; // 跳过没有名称的元素
    }
    
    // 检查是否有内联复杂类型定义
    bool has_inline_complex_type = false;
    for (xmlNodePtr elem_child = element_node->children; elem_child; elem_child = elem_child->next) {
        if (elem_child->type == XML_ELEMENT_NODE &&
            std::string(reinterpret_cast<const char*>(elem_child->name)) == "complexType") {
            
            // 为内联复杂类型创建类型定义
            WsdlType type;
            type.name = element_name;
            type.ns_uri = file_info->target_namespace;
            type.source_file = file_info->file_path;
            
            // 检查mixed属性
            std::string mixed_attr = get_node_attribute(elem_child, "mixed");
            type.is_mixed = (mixed_attr == "true");
            
            // 解析complexType内容
            for (xmlNodePtr ct_child = elem_child->children; ct_child; ct_child = ct_child->next) {
                if (ct_child->type == XML_ELEMENT_NODE) {
                    std::string ct_node_name = reinterpret_cast<const char*>(ct_child->name);
                    if (ct_node_name == "sequence") {
                        for (xmlNodePtr seq_child = ct_child->children; seq_child; seq_child = seq_child->next) {
                            if (seq_child->type == XML_ELEMENT_NODE) {
                                std::string seq_node_name = reinterpret_cast<const char*>(seq_child->name);
                                if (seq_node_name == "element") {
                                    parse_element(type, seq_child, file_info->namespace_prefix, file_info);
                                } else if (seq_node_name == "any") {
                                    parse_any_element(type, seq_child, file_info->namespace_prefix);
                                }
                            }
                        }
                    } else if (ct_node_name == "attribute") {
                        parse_attribute(file_info, type, ct_child);
                    } else if (ct_node_name == "anyAttribute") {
                        parse_any_attribute(type, ct_child);
                    } else if (ct_node_name == "simpleContent" || ct_node_name == "complexContent") {
                        parse_inheritance(type, ct_child, file_info->namespace_prefix, file_info);
                    }
                }
            }
            
            file_info->types.push_back(type);
            // 设置字段的父级类型引用以优化后续查找
            has_inline_complex_type = true;
            break;
        }
    }
    
    // 如果没有内联复杂类型，但有类型引用，则创建类型别名
    if (!has_inline_complex_type && !element_type.empty()) {
        WsdlType alias_type;
        alias_type.name = element_name;
        alias_type.ns_uri = file_info->target_namespace;
        alias_type.source_file = file_info->file_path;
        alias_type.is_simple_type_rename = true;
        
        // 解析类型引用
        auto [type_ns_prefix, type_local_name] = TypeUtils::parse_type_ref(element_type);
        
        // 如果是基础XSD类型，直接映射到C++类型
        if (TypeUtils::is_basic_xsd_type(element_type)) {
            alias_type.base_simple_type = TypeUtils::convert_xsd_to_cpp_type(element_type);
        } else {
            // 如果element名称和引用的type名称相同，说明引用的是同名complexType
            // 这种情况下，不需要创建包装器，complexType已经会被单独处理
            if (type_local_name == element_name) {
                if (config_.verbose) {
                    std::cout << "元素引用同名complexType，跳过包装器创建: " << element_name 
                              << " -> " << element_type << std::endl;
                }
                return; // 不创建别名包装器，让complexType的定义直接生效
            }
            
            // 引用其他已定义的类型，需要解析为正确的C++类型名
            alias_type.base_simple_type = resolve_type_reference(element_type, file_info);
        }
        
        if (config_.verbose) {
            std::cout << "创建元素别名: " << element_name 
                      << " -> " << alias_type.base_simple_type << std::endl;
        }
        
        file_info->types.push_back(alias_type);
        // 设置字段的父级类型引用以优化后续查找
    }
    
    // 如果既没有内联类型也没有类型引用，可能是简单内容元素
    if (!has_inline_complex_type && element_type.empty()) {
        // 检查是否有内联简单类型
        for (xmlNodePtr elem_child = element_node->children; elem_child; elem_child = elem_child->next) {
            if (elem_child->type == XML_ELEMENT_NODE &&
                std::string(reinterpret_cast<const char*>(elem_child->name)) == "simpleType") {
                
                WsdlType type;
                type.name = element_name;
                type.ns_uri = file_info->target_namespace;
                type.source_file = file_info->file_path;
                type.is_simple_type = true;
                
                // 解析简单类型定义内容（内联逻辑）
                for (xmlNodePtr st_child = elem_child->children; st_child; st_child = st_child->next) {
                    if (st_child->type != XML_ELEMENT_NODE) continue;
                    
                    std::string st_node_name = reinterpret_cast<const char*>(st_child->name);
                    
                    if (st_node_name == "restriction") {
                        type.base_type = get_node_attribute(st_child, "base");
                        
                        // 解析限制条件
                        for (xmlNodePtr restrict_child = st_child->children; restrict_child; restrict_child = restrict_child->next) {
                            if (restrict_child->type != XML_ELEMENT_NODE) continue;
                            
                            std::string restrict_name = reinterpret_cast<const char*>(restrict_child->name);
                            
                            if (restrict_name == "enumeration") {
                                std::string value = get_node_attribute(restrict_child, "value");
                                if (!value.empty()) {
                                    type.enumeration.push_back(value);
                                    type.is_enum = true;
                                }
                            }
                        }
                        
                        if (!type.enumeration.empty()) {
                            type.is_enum = true;
                        } else {
                            type.is_simple_type_rename = true;
                            // 转换基础类型引用
                            if (TypeUtils::is_basic_xsd_type(type.base_type)) {
                                type.base_simple_type = TypeUtils::convert_xsd_to_cpp_type(type.base_type);
                            } else {
                                type.base_simple_type = resolve_type_reference(type.base_type, file_info);
                            }
                        }
                        break;
                    }
                }
                
                file_info->types.push_back(type);
                // 设置字段的父级类型引用以优化后续查找
                break;
            }
        }
    }
}

void WsdlParser::parse_simple_type(std::shared_ptr<FileInfo> file_info,
                                  xmlNodePtr simple_type_node,
                                  const std::string& target_ns) {
    WsdlType type;
    type.name = get_node_attribute(simple_type_node, "name");
    type.ns_uri = target_ns;
    type.is_simple_type = true;
    type.source_file = file_info->file_path;
    
    if (type.name.empty()) {
        return; // 跳过匿名类型
    }
    
    // 解析限制
    for (xmlNodePtr child = simple_type_node->children; child; child = child->next) {
        if (child->type != XML_ELEMENT_NODE) continue;
        
        std::string node_name = reinterpret_cast<const char*>(child->name);
        
        if (node_name == "restriction") {
            type.base_type = get_node_attribute(child, "base");
            
            // 解析限制条件
            bool has_enumeration = false;
            
            for (xmlNodePtr restrict_child = child->children; restrict_child; restrict_child = restrict_child->next) {
                if (restrict_child->type != XML_ELEMENT_NODE) continue;
                
                std::string restrict_name = reinterpret_cast<const char*>(restrict_child->name);
                
                if (restrict_name == "enumeration") {
                    std::string value = get_node_attribute(restrict_child, "value");
                    if (!value.empty()) {
                        type.enumeration.push_back(value);
                        has_enumeration = true;
                    }
                } else if (restrict_name == "maxLength") {
                    std::string value = get_node_attribute(restrict_child, "value");
                    if (!value.empty()) {
                        type.max_length = std::stoi(value);
                    }
                } else if (restrict_name == "minLength") {
                    std::string value = get_node_attribute(restrict_child, "value");
                    if (!value.empty()) {
                        type.min_length = std::stoi(value);
                    }
                }
            }
            
            // 确定类型特征
            if (has_enumeration) {
                type.is_enum = true;
            } else if (!type.base_type.empty()) {
                // 任何基于基本XSD类型的限制都应该使用包装器模式
                type.is_simple_type_rename = true;
                // 转换基础类型引用
                if (TypeUtils::is_basic_xsd_type(type.base_type)) {
                    type.base_simple_type = TypeUtils::convert_xsd_to_cpp_type(type.base_type);
                } else {
                    type.base_simple_type = resolve_type_reference(type.base_type, file_info);
                }
            }
            
        } else if (node_name == "list") {
            type.is_list = true;
            type.list_item_type = get_node_attribute(child, "itemType");
        }
    }
    
    file_info->types.push_back(type);
    // 设置字段的父级类型引用以优化后续查找
}

void WsdlParser::parse_element(WsdlType& type, xmlNodePtr element_node, const std::string& ns_prefix, std::shared_ptr<FileInfo> file_info) {
    WsdlField field;
    field.field_type = FieldType::ELEMENT;
    
    // 获取文件信息以便进行命名空间解析
    std::shared_ptr<FileInfo> current_file_info = file_info;
    if (!current_file_info) {
        // 后备方案：从已加载文件中找到最后一个（通常是当前正在处理的文件）
        for (const auto& [path, loaded_file_info] : loaded_files_) {
            current_file_info = loaded_file_info;
        }
    }
    
    // 检查是否为引用元素
    std::string ref_attr = get_node_attribute(element_node, "ref");
    if (!ref_attr.empty()) {
        // 处理引用元素
        auto [ref_ns_prefix, ref_local_name] = TypeUtils::parse_type_ref(ref_attr);
        field.name = ref_local_name;
        field.type = ref_attr;
        
        // 解析引用的命名空间前缀
        if (!ref_ns_prefix.empty()) {
            // 通过引用前缀查找对应的命名空间URI，然后查找配置的前缀
            if (current_file_info) {
                auto ns_it = current_file_info->namespaces.find(ref_ns_prefix);
                if (ns_it != current_file_info->namespaces.end()) {
                    std::string namespace_uri = ns_it->second;
                    // 通过URI查找正确配置的命名空间前缀
                    std::string correct_prefix = find_namespace_prefix_by_uri(current_file_info, namespace_uri);
                    if (!correct_prefix.empty()) {
                        field.ns_prefix = correct_prefix;
                        if (config_.verbose) {
                            std::cout << "引用元素 " << field.name 
                                      << " 命名空间: " << namespace_uri
                                      << " -> 配置前缀: " << correct_prefix 
                                      << " (原前缀: " << ref_ns_prefix << ")" << std::endl;
                        }
                    } else {
                        // 没找到配置前缀，使用原始前缀
                        std::replace(ref_ns_prefix.begin(), ref_ns_prefix.end(), '-', '_');
                        field.ns_prefix = ref_ns_prefix;
                    }
                } else {
                    // 没找到对应的URI，直接使用前缀
                    std::replace(ref_ns_prefix.begin(), ref_ns_prefix.end(), '-', '_');
                    field.ns_prefix = ref_ns_prefix;
                }
            } else {
                // 没有文件信息，直接处理前缀
                std::replace(ref_ns_prefix.begin(), ref_ns_prefix.end(), '-', '_');
                field.ns_prefix = ref_ns_prefix;
            }
        } else {
            // 如果引用没有前缀，使用传入的命名空间前缀
            field.ns_prefix = ns_prefix;
        }
        
        if (config_.verbose) {
            std::cout << "解析引用元素: " << field.name 
                      << ", 命名空间前缀: " << field.ns_prefix << std::endl;
        }
    } else {
        // 普通元素
        field.name = get_node_attribute(element_node, "name");
        field.type = get_node_attribute(element_node, "type");
        
        // 字段命名空间前缀应该始终使用父类型的命名空间前缀
        // 这是因为字段的命名空间上下文由其所属的父类型决定，而不是由其类型决定
        field.ns_prefix = ns_prefix;
        
        // 如果没有type属性，检查是否有内联定义
        if (field.type.empty()) {
            bool has_inline_definition = false;
            for (xmlNodePtr child = element_node->children; child; child = child->next) {
                if (child->type == XML_ELEMENT_NODE) {
                    std::string child_name = reinterpret_cast<const char*>(child->name);
                    if (child_name == "complexType") {
                        field.type = field.name; // 使用元素名作为类型名
                        has_inline_definition = true;
                        
                        // 创建内联复杂类型定义
                        WsdlType inline_type;
                        inline_type.name = field.name;
                        inline_type.ns_uri = current_file_info ? current_file_info->target_namespace : "";
                        inline_type.source_file = current_file_info ? current_file_info->file_path : "";
                        // 继承父类型的命名空间前缀
                        inline_type.ns_prefix = ns_prefix;
                        
                        // 检查内联complexType的mixed属性
                        std::string mixed_attr = get_node_attribute(child, "mixed");
                        inline_type.is_mixed = (mixed_attr == "true");
                        
                        // 解析内联complexType内容
                        for (xmlNodePtr ct_child = child->children; ct_child; ct_child = ct_child->next) {
                            if (ct_child->type != XML_ELEMENT_NODE) continue;
                            
                            std::string ct_node_name = reinterpret_cast<const char*>(ct_child->name);
                            if (ct_node_name == "sequence") {
                                for (xmlNodePtr seq_child = ct_child->children; seq_child; seq_child = seq_child->next) {
                                    if (seq_child->type == XML_ELEMENT_NODE) {
                                        std::string seq_node_name = reinterpret_cast<const char*>(seq_child->name);
                                        if (seq_node_name == "element") {
                                            parse_element(inline_type, seq_child, ns_prefix, current_file_info);
                                        } else if (seq_node_name == "any") {
                                            parse_any_element(inline_type, seq_child, ns_prefix);
                                        }
                                    }
                                }
                            } else if (ct_node_name == "attribute") {
                                parse_attribute(current_file_info, inline_type, ct_child);
                            } else if (ct_node_name == "anyAttribute") {
                                parse_any_attribute(inline_type, ct_child);
                            } else if (ct_node_name == "simpleContent" || ct_node_name == "complexContent") {
                                parse_inheritance(inline_type, ct_child, ns_prefix, current_file_info);
                            }
                        }
                        
                        // 将内联类型添加到文件类型列表中
                        if (current_file_info) {
                            current_file_info->types.push_back(inline_type);
                            // 设置字段的父级类型引用以优化后续查找
                        }
                        
                        break;
                    } else if (child_name == "simpleType") {
                        field.type = field.name; // 使用元素名作为类型名
                        has_inline_definition = true;
                        // TODO: 如需要可以添加simpleType的处理
                        break;
                    }
                }
            }
            
            // 如果没有内联定义也没有type属性，默认为string类型
            if (!has_inline_definition) {
                field.type = "xs:string";  // 默认使用string类型
                if (config_.verbose) {
                    std::cout << "元素 " << field.name 
                              << " 没有type属性，默认使用 xs:string" << std::endl;
                }
            }
        }
    }
    
    // 解析可选性和数组属性
    std::string min_occurs = get_node_attribute(element_node, "minOccurs");
    if (min_occurs == "0") {
        field.is_optional = true;
    }
    
    std::string max_occurs = get_node_attribute(element_node, "maxOccurs");
    if (max_occurs == "unbounded") {
        field.is_array = true;
    }
    
    // 获取文档
    field.doc = get_documentation(element_node);
    
    if (!field.name.empty()) {
        if (config_.verbose && !field.ns_prefix.empty()) {
            std::cout << "添加字段: " << field.name 
                      << ", 类型: " << field.type
                      << ", 命名空间前缀: " << field.ns_prefix << std::endl;
        }
        type.fields.push_back(field);
        
        // 记录元素类型使用上下文
        if (!field.type.empty()) {
            std::string location = type.name + "::" + field.name + " (element)";
            record_type_usage(current_file_info, field.type, false, location);
        }
    }
}

void WsdlParser::parse_attribute(std::shared_ptr<FileInfo> file_info, WsdlType& type, xmlNodePtr attribute_node) {
    WsdlField field;
    field.field_type = FieldType::ATTRIBUTE;
    
    // 检查是否为引用属性
    std::string ref_attr = get_node_attribute(attribute_node, "ref");
    if (!ref_attr.empty()) {
        // 处理引用属性
        auto [ref_ns_prefix, ref_local_name] = TypeUtils::parse_type_ref(ref_attr);
        field.name = ref_local_name;
        field.ns_prefix = ref_ns_prefix;
        
        // 对于引用属性，需要查找其定义来确定类型
        // 这里为了简化，对于已知的xmime:contentType使用string类型
        if (ref_attr == "xmime:contentType" || ref_local_name == "contentType") {
            field.type = "xs:string";
        } else {
            field.type = "xs:string"; // 默认类型
        }
    } else {
        // 直接定义的属性
        field.name = get_node_attribute(attribute_node, "name");
        field.type = get_node_attribute(attribute_node, "type");
        
        // 如果属性没有指定type，按照XSD规范默认为xs:string
        if (field.type.empty()) {
            field.type = "xs:string";
        }
    }
    
    std::string use = get_node_attribute(attribute_node, "use");
    if (use != "required") {
        field.is_optional = true;
    }
    
    field.default_value = get_node_attribute(attribute_node, "default");
    field.doc = get_documentation(attribute_node);
    
    type.fields.push_back(field);
    
    // 记录属性类型使用上下文
    if (!field.type.empty()) {
        std::string location = type.name + "::" + field.name + " (attribute)";
        record_type_usage(file_info, field.type, true, location);
    }
}

void WsdlParser::parse_any_element(WsdlType& type, xmlNodePtr any_node, const std::string& ns_prefix) {
    WsdlField field;
    field.field_type = FieldType::ANY_ELEMENT;
    field.ns_prefix = ns_prefix;
    
    // 获取命名空间限制
    field.any_namespace = get_node_attribute(any_node, "namespace");
    if (field.any_namespace.empty()) {
        field.any_namespace = "##any";
    }
    
    field.process_contents = get_node_attribute(any_node, "processContents");
    if (field.process_contents.empty()) {
        field.process_contents = "strict";
    }
    
    // 解析出现次数
    std::string min_occurs = get_node_attribute(any_node, "minOccurs");
    std::string max_occurs = get_node_attribute(any_node, "maxOccurs");
    
    bool is_optional = (min_occurs == "0");
    bool is_unbounded = (max_occurs == "unbounded");
    
    // 根据出现次数确定字段名和类型
    if (is_unbounded) {
        // maxOccurs="unbounded" 使用 AnyElementCollection
        field.name = "_any_";
        field.type = "std::vector<AnyElement>";
        field.is_array = true;
        field.is_optional = is_optional;
        field.doc = "Collection of any elements from namespace: " + field.any_namespace + 
                   " (processContents: " + field.process_contents + ")";
    } else {
        // 单个或固定数量的元素使用 AnyElement
        field.name = "_any_";
        field.type = "AnyElement";
        field.is_optional = is_optional;
        field.doc = "Any element from namespace: " + field.any_namespace + 
                   " (processContents: " + field.process_contents + ")";
    }
    
    if (config_.verbose) {
        std::cout << "解析 xs:any 元素: " << field.name 
                  << ", 类型: " << field.type
                  << ", 命名空间: " << field.any_namespace
                  << ", 可选: " << (field.is_optional ? "是" : "否")
                  << ", 数组: " << (field.is_array ? "是" : "否") << std::endl;
    }
    
    type.fields.push_back(field);
}

void WsdlParser::parse_any_attribute(WsdlType& type, xmlNodePtr any_attr_node) {
    WsdlField field;
    field.name = "_attrs_";
    field.type = "std::map<std::string, std::string>";
    field.field_type = FieldType::ANY_ATTRIBUTE;
    field.is_optional = true;
    
    field.any_namespace = get_node_attribute(any_attr_node, "namespace");
    if (field.any_namespace.empty()) {
        field.any_namespace = "##other";
    }
    
    field.process_contents = get_node_attribute(any_attr_node, "processContents");
    if (field.process_contents.empty()) {
        field.process_contents = "strict";
    }
    
    field.doc = "Any attributes allowed (namespace: " + field.any_namespace + 
               ", processContents: " + field.process_contents + ")";
    
    type.fields.push_back(field);
}

void WsdlParser::parse_inheritance(WsdlType& type, xmlNodePtr content_node, const std::string& ns_prefix, std::shared_ptr<FileInfo> file_info) {
    std::string content_node_name = reinterpret_cast<const char*>(content_node->name);
    bool is_simple_content = (content_node_name == "simpleContent");
    
    // 检查complexContent的mixed属性
    if (!is_simple_content) {
        std::string mixed_attr = get_node_attribute(content_node, "mixed");
        if (mixed_attr == "true") {
            type.is_mixed = true;
        }
    }
    
    // 查找extension节点
    for (xmlNodePtr child = content_node->children; child; child = child->next) {
        if (child->type != XML_ELEMENT_NODE) continue;
        
        std::string node_name = reinterpret_cast<const char*>(child->name);
        
        if (node_name == "extension") {
            std::string base_type_name = get_node_attribute(child, "base");
            
            if (is_simple_content) {
                // simpleContent扩展：添加值字段作为元素的文本内容
                WsdlField value_field;
                value_field.name = "value";
                value_field.type = base_type_name;
                value_field.field_type = FieldType::TEXT_CONTENT;  // 标记为文本内容
                value_field.doc = "Value content based on " + base_type_name;
                type.fields.push_back(value_field);

                if (config_.verbose) {
                    std::cout << "处理simpleContent扩展: " << type.name
                              << ", 基类型: " << base_type_name << " (文本内容)" << std::endl;
                }
            } else {
                // complexContent扩展：检查是否为mixed内容
                if (type.is_mixed && (base_type_name == "xs:anyType" || base_type_name == "xsd:anyType" || base_type_name == "AnyElement")) {
                    // mixed="true"且基类为anyType时，添加AnyElement字段而不是继承
                    WsdlField any_field;
                    any_field.name = "_any_";
                    any_field.type = "AnyElement";
                    any_field.field_type = FieldType::ANY_ELEMENT;
                    any_field.is_optional = true;
                    any_field.doc = "Mixed content any element";
                    type.fields.push_back(any_field);
                    
                    if (config_.verbose) {
                        std::cout << "处理mixed complexContent: " << type.name 
                                  << ", 添加AnyElement字段" << std::endl;
                    }
                } else {
                    // 普通complexContent扩展：设置继承关系
                    type.base_type = base_type_name;
                    
                    if (config_.verbose) {
                        std::cout << "处理complexContent扩展: " << type.name 
                                  << ", 基类型: " << base_type_name << std::endl;
                    }
                }
            }
            
            // 解析扩展内容
            for (xmlNodePtr ext_child = child->children; ext_child; ext_child = ext_child->next) {
                if (ext_child->type != XML_ELEMENT_NODE) continue;
                
                std::string ext_node_name = reinterpret_cast<const char*>(ext_child->name);
                
                if (ext_node_name == "sequence") {
                    for (xmlNodePtr seq_child = ext_child->children; seq_child; seq_child = seq_child->next) {
                        if (seq_child->type == XML_ELEMENT_NODE) {
                            std::string seq_name = reinterpret_cast<const char*>(seq_child->name);
                            if (seq_name == "element") {
                                parse_element(type, seq_child, ns_prefix, file_info);
                            } else if (seq_name == "any") {
                                parse_any_element(type, seq_child, ns_prefix);
                            }
                        }
                    }
                } else if (ext_node_name == "attribute") {
                    parse_attribute(file_info, type, ext_child);
                } else if (ext_node_name == "anyAttribute") {
                    parse_any_attribute(type, ext_child);
                }
            }
        }
    }
}

void WsdlParser::parse_wsdl_import(std::shared_ptr<FileInfo> file_info, xmlNodePtr import_node) {
    // wsdl:import 使用 location 属性（而不是 schemaLocation）
    std::string location = get_node_attribute(import_node, "location");
    std::string namespace_attr = get_node_attribute(import_node, "namespace");

    if (location.empty()) {
        if (config_.verbose) {
            std::cout << "警告: wsdl:import 缺少 location 属性";
            if (!namespace_attr.empty()) {
                std::cout << " (namespace: " << namespace_attr << ")";
            }
            std::cout << std::endl;
        }
        return;
    }

    // 构建完整路径
    std::string full_path;
    if (is_url(location)) {
        full_path = location;
    } else {
        // 相对路径处理 - 首先检查缓存目录
        std::string cache_path;

        // 提取相对路径中的文件名
        std::filesystem::path rel_path(location);
        std::string filename = rel_path.filename().string();

        if (!filename.empty()) {
            // 检查缓存目录中是否存在该文件
            cache_path = config_.cache_dir + "/" + filename;

            if (std::filesystem::exists(cache_path)) {
                if (config_.verbose) {
                    std::cout << "在缓存中找到 WSDL 依赖: " << location << " -> " << cache_path << std::endl;
                }
                full_path = std::filesystem::absolute(cache_path).string();
            } else {
                // 尝试查找文件名的变体
                std::string base_name = rel_path.stem().string();
                std::string extension = rel_path.extension().string();

                try {
                    for (const auto& entry : std::filesystem::directory_iterator(config_.cache_dir)) {
                        if (entry.is_regular_file()) {
                            std::string cached_filename = entry.path().filename().string();
                            std::string cached_base = entry.path().stem().string();
                            std::string cached_ext = entry.path().extension().string();

                            if (cached_ext == extension &&
                                (cached_base == base_name ||
                                 cached_base.find(base_name + "_") == 0)) {
                                cache_path = entry.path().string();
                                full_path = std::filesystem::absolute(cache_path).string();
                                if (config_.verbose) {
                                    std::cout << "在缓存中找到 WSDL 依赖变体: " << location
                                              << " -> " << cached_filename << std::endl;
                                }
                                break;
                            }
                        }
                    }
                } catch (const std::filesystem::filesystem_error& e) {
                    // 目录不存在或无法访问
                }
            }
        }

        // 如果缓存中没有找到，则按原有逻辑处理相对路径
        if (full_path.empty()) {
            if (is_url(file_info->network_url)) {
                // 当前文件是网络文件，基于网络URL构建依赖路径
                std::string base_url = file_info->network_url;
                auto last_slash = base_url.find_last_of('/');
                if (last_slash != std::string::npos) {
                    base_url = base_url.substr(0, last_slash + 1);
                }

                // 处理相对路径中的 "../"
                std::string resolved_path = location;
                while (resolved_path.find("../") == 0) {
                    resolved_path = resolved_path.substr(3);
                    auto prev_slash = base_url.find_last_of('/', base_url.length() - 2);
                    if (prev_slash != std::string::npos) {
                        base_url = base_url.substr(0, prev_slash + 1);
                    }
                }

                full_path = base_url + resolved_path;
            } else {
                // 本地文件，基于文件系统路径
                std::filesystem::path current_file(file_info->file_path);
                std::filesystem::path import_path = current_file.parent_path() / location;
                full_path = std::filesystem::absolute(import_path).string();
            }
        }
    }

    file_info->imports.insert(full_path);

    // 检查是否已经加载过这个文件
    if (loaded_files_.find(full_path) != loaded_files_.end()) {
        if (auto existing_file = loaded_files_[full_path]) {
            file_info->dependencies.push_back(existing_file);
            if (!existing_file->parent_file.lock()) {
                existing_file->parent_file = file_info;
            }
        }
        return;
    }

    // 检查是否正在处理中（防止循环依赖）
    if (processing_files_.find(full_path) != processing_files_.end()) {
        if (config_.verbose) {
            std::cout << "检测到循环依赖，跳过 wsdl:import: " << location << " -> " << full_path << std::endl;
        }
        return;
    }

    if (config_.verbose) {
        std::cout << "解析 wsdl:import 依赖: " << location << " -> " << full_path;
        if (!namespace_attr.empty()) {
            std::cout << " (namespace: " << namespace_attr << ")";
        }
        std::cout << std::endl;
    }

    if (auto dep_file = load_file(full_path)) {
        dep_file->parent_file = file_info;
        file_info->dependencies.push_back(dep_file);
        std::cout << "✅ 成功记录 wsdl:import 依赖: " << file_info->file_path << " -> " << dep_file->file_path << std::endl;
        parse_file(dep_file);

        // 将被导入WSDL的服务操作合并到父WSDL的第一个服务中
        if (!dep_file->services.empty() && !file_info->services.empty()) {
            if (config_.verbose) {
                std::cout << "合并 wsdl:import 的服务操作: " << dep_file->services.size()
                          << " 个服务 -> 父WSDL的主服务" << std::endl;
            }

            // 获取父文件的主服务（第一个服务）
            auto& parent_main_service = file_info->services[0];

            // 合并所有导入服务的操作到主服务
            for (const auto& imported_service : dep_file->services) {
                if (config_.verbose) {
                    std::cout << "  合并服务 " << imported_service.port_type
                              << " (namespace: " << imported_service.target_namespace << ")" << std::endl;
                }

                // 从父服务的命名空间映射中查找正确的前缀
                std::string correct_prefix = imported_service.namespace_prefix;
                if (correct_prefix.empty() || correct_prefix == "unknown") {
                    // 如果导入服务的前缀为空或unknown，尝试从父服务的namespaces中查找
                    for (const auto& [prefix, uri] : parent_main_service.namespaces) {
                        if (uri == imported_service.target_namespace) {
                            correct_prefix = prefix;
                            break;
                        }
                    }
                }

                // 合并操作
                for (auto op : imported_service.operations) {
                    // 检查是否重复（避免重复定义）
                    bool duplicate = false;
                    for (const auto& existing_op : parent_main_service.operations) {
                        if (existing_op.name == op.name) {
                            duplicate = true;
                            if (config_.verbose) {
                                std::cout << "    跳过重复操作: " << op.name << std::endl;
                            }
                            break;
                        }
                    }

                    if (!duplicate) {
                        // 设置操作的源命名空间信息（来自被导入的服务）
                        op.source_namespace = imported_service.target_namespace;
                        op.source_ns_prefix = correct_prefix;  // 使用从父服务查找到的正确前缀
                        parent_main_service.operations.push_back(op);

                        if (config_.verbose) {
                            std::cout << "    添加操作: " << op.name
                                      << " (ns: " << op.source_ns_prefix << ":" << op.source_namespace << ")" << std::endl;
                        }
                    }
                }

                // 合并命名空间映射（确保父服务能解析导入服务的命名空间）
                for (const auto& [prefix, uri] : imported_service.namespaces) {
                    if (parent_main_service.namespaces.find(prefix) == parent_main_service.namespaces.end()) {
                        parent_main_service.namespaces[prefix] = uri;
                    }
                }
            }
        } else if (!dep_file->services.empty() && file_info->services.empty()) {
            // 如果父文件还没有服务（在 parse_services 之前就调用了 wsdl:import）
            // 直接将导入的服务添加到父文件，标记为需要后续合并
            if (config_.verbose) {
                std::cout << "父文件尚未解析服务，暂存导入的服务供后续合并" << std::endl;
            }

            for (const auto& imported_service : dep_file->services) {
                WsdlService new_service = imported_service;

                // 从父文件的命名空间映射中查找正确的前缀
                std::string correct_prefix = imported_service.namespace_prefix;
                if (correct_prefix.empty() || correct_prefix == "unknown") {
                    // 如果导入服务的前缀为空或unknown，尝试从父文件的namespaces中查找
                    for (const auto& [prefix, uri] : file_info->namespaces) {
                        if (uri == imported_service.target_namespace) {
                            correct_prefix = prefix;
                            break;
                        }
                    }
                }

                // 为所有操作设置source_namespace
                for (auto& op : new_service.operations) {
                    if (op.source_namespace.empty()) {
                        op.source_namespace = imported_service.target_namespace;
                        op.source_ns_prefix = correct_prefix;
                    }
                }
                file_info->services.push_back(new_service);
            }
        }

        // 清空被导入文件的services列表，防止在generate_all_clients时重复生成
        // 因为服务已经合并到父文件中（或暂存到父文件待后续合并）
        if (!dep_file->services.empty()) {
            if (config_.verbose) {
                std::cout << "清空被导入文件的services列表，避免重复生成客户端" << std::endl;
            }
            dep_file->services.clear();
        }
    } else {
        std::cerr << "❌ 无法加载 wsdl:import 依赖文件: " << full_path << std::endl;
        if (!config_.ignore_missing_deps) {
            std::cerr << "警告: 无法加载 wsdl:import 依赖文件: " << full_path << std::endl;
        }
    }
}

void WsdlParser::parse_import(std::shared_ptr<FileInfo> file_info, xmlNodePtr import_node) {
    std::string schema_location = get_node_attribute(import_node, "schemaLocation");
    if (schema_location.empty()) {
        return;
    }
    
    // 构建完整路径
    std::string full_path;
    if (is_url(schema_location)) {
        full_path = schema_location;
    } else {
        // 相对路径处理 - 首先检查缓存目录
        std::string cache_path;
        
        // 提取相对路径中的文件名
        std::filesystem::path rel_path(schema_location);
        std::string filename = rel_path.filename().string();
        
        if (!filename.empty()) {
            // 检查缓存目录中是否存在该文件
            cache_path = config_.cache_dir + "/" + filename;
            
            if (std::filesystem::exists(cache_path)) {
                if (config_.verbose) {
                    std::cout << "在缓存中找到依赖文件: " << schema_location << " -> " << cache_path << std::endl;
                }
                full_path = std::filesystem::absolute(cache_path).string();
            } else {
                // 尝试查找文件名的变体，例如 onvif.xsd -> onvif_v10.xsd
                std::string base_name = rel_path.stem().string(); // 去掉扩展名
                std::string extension = rel_path.extension().string(); // 扩展名
                
                // 遍历缓存目录，查找匹配的文件
                try {
                    for (const auto& entry : std::filesystem::directory_iterator(config_.cache_dir)) {
                        if (entry.is_regular_file()) {
                            std::string cached_filename = entry.path().filename().string();
                            std::string cached_base = entry.path().stem().string();
                            std::string cached_ext = entry.path().extension().string();
                            
                            // 检查是否为相同基础名称的变体
                            // 例如: onvif.xsd 匹配 onvif_v10.xsd
                            if (cached_ext == extension && 
                                (cached_base == base_name || 
                                 cached_base.find(base_name + "_") == 0)) {
                                cache_path = entry.path().string();
                                full_path = std::filesystem::absolute(cache_path).string();
                                if (config_.verbose) {
                                    std::cout << "在缓存中找到依赖文件变体: " << schema_location 
                                              << " -> " << cached_filename << std::endl;
                                }
                                break;
                            }
                        }
                    }
                } catch (const std::filesystem::filesystem_error& e) {
                    // 目录不存在或无法访问，继续原有逻辑
                }
            }
        }
        
        // 如果缓存中没有找到，则按原有逻辑处理相对路径
        if (full_path.empty()) {
            if (is_url(file_info->network_url)) {
                // 当前文件是网络文件，基于网络URL构建依赖路径
                std::string base_url = file_info->network_url;
                auto last_slash = base_url.find_last_of('/');
                if (last_slash != std::string::npos) {
                    base_url = base_url.substr(0, last_slash + 1);
                }
                
                // 处理相对路径中的 "../" 
                std::string resolved_path = schema_location;
                while (resolved_path.find("../") == 0) {
                    resolved_path = resolved_path.substr(3);
                    auto prev_slash = base_url.find_last_of('/', base_url.length() - 2);
                    if (prev_slash != std::string::npos) {
                        base_url = base_url.substr(0, prev_slash + 1);
                    }
                }
                
                full_path = base_url + resolved_path;
            } else {
                // 本地文件，基于文件系统路径
                std::filesystem::path current_file(file_info->file_path);
                std::filesystem::path import_path = current_file.parent_path() / schema_location;
                full_path = std::filesystem::absolute(import_path).string();
            }
        }
    }
    
    file_info->imports.insert(full_path);
    
    // 加载依赖文件
    // 检查是否已经加载过这个文件
    if (loaded_files_.find(full_path) != loaded_files_.end()) {
        // 文件已经加载过，直接添加到依赖列表
        if (auto existing_file = loaded_files_[full_path]) {
            file_info->dependencies.push_back(existing_file);
            if (!existing_file->parent_file.lock()) {
                existing_file->parent_file = file_info; // 设置父文件
            }
        }
        return;
    }
    
    // 检查是否正在处理中（防止循环依赖）
    if (processing_files_.find(full_path) != processing_files_.end()) {
        if (config_.verbose) {
            std::cout << "检测到循环依赖，跳过: " << schema_location << " -> " << full_path << std::endl;
        }
        return;
    }
    
    if (config_.verbose) {
        std::cout << "解析依赖: " << schema_location << " -> " << full_path << std::endl;
    }

    if (auto dep_file = load_file(full_path)) {
        dep_file->parent_file = file_info; // 设置父文件
        file_info->dependencies.push_back(dep_file);
        std::cout << "✅ 成功记录依赖: " << file_info->file_path << " -> " << dep_file->file_path << std::endl;
        parse_file(dep_file);
    } else {
        std::cerr << "❌ 无法加载依赖文件: " << full_path << std::endl;
        if (!config_.ignore_missing_deps) {
            std::cerr << "警告: 无法加载依赖文件: " << full_path << std::endl;
        }
    }
}

void WsdlParser::parse_messages(std::shared_ptr<FileInfo> file_info, xmlNodePtr root) {
    for (xmlNodePtr child = root->children; child; child = child->next) {
        if (child->type != XML_ELEMENT_NODE) continue;
        
        std::string node_name = reinterpret_cast<const char*>(child->name);
        if (node_name == "message") {
            WsdlMessage message;
            message.name = get_node_attribute(child, "name");
            message.documentation = get_documentation(child);
            
            // 解析消息的part，获取element引用
            for (xmlNodePtr part_node = child->children; part_node; part_node = part_node->next) {
                if (part_node->type != XML_ELEMENT_NODE) continue;
                
                std::string part_name = reinterpret_cast<const char*>(part_node->name);
                if (part_name == "part") {
                    std::string element = get_node_attribute(part_node, "element");
                    if (!element.empty()) {
                        message.element_name = element;
                        break; // 通常一个消息只有一个part
                    }
                }
            }
            
            if (!message.element_name.empty()) {
                file_info->messages.push_back(message);
            }
        }
    }
}

std::string WsdlParser::find_element_by_message(std::shared_ptr<FileInfo> file_info, const std::string& message_name) {
    // 移除命名空间前缀（如果存在）
    std::string local_name = message_name;
    std::string prefix;
    size_t colon_pos = message_name.find(':');
    if (colon_pos != std::string::npos) {
        prefix = message_name.substr(0, colon_pos);
        local_name = message_name.substr(colon_pos + 1);
    }

    // 首先在当前文件中查找
    for (const auto& message : file_info->messages) {
        if (message.name == local_name) {
            return message.element_name;
        }
    }

    // 如果当前文件中没有找到，搜索所有已加载的文件
    // 优先匹配命名空间前缀
    if (!prefix.empty() && file_info->namespaces.count(prefix) > 0) {
        std::string target_namespace = file_info->namespaces.at(prefix);
        for (const auto& [path, loaded_file] : loaded_files_) {
            if (loaded_file->target_namespace == target_namespace) {
                for (const auto& message : loaded_file->messages) {
                    if (message.name == local_name) {
                        return message.element_name;
                    }
                }
            }
        }
    }

    // 如果没有前缀或按命名空间没找到，遍历所有文件查找
    for (const auto& [path, loaded_file] : loaded_files_) {
        for (const auto& message : loaded_file->messages) {
            if (message.name == local_name) {
                return message.element_name;
            }
        }
    }

    return ""; // 未找到
}

void WsdlParser::parse_services(std::shared_ptr<FileInfo> file_info, xmlNodePtr root) {
    // 记住在 wsdl:import 阶段暂存的服务数量
    size_t imported_service_count = file_info->services.size();

    // 第一遍：解析当前文件的所有 portType
    for (xmlNodePtr child = root->children; child; child = child->next) {
        if (child->type != XML_ELEMENT_NODE) continue;

        std::string node_name = reinterpret_cast<const char*>(child->name);

        if (node_name == "portType") {
            WsdlService service;
            service.target_namespace = file_info->target_namespace;
            service.namespace_prefix = file_info->namespace_prefix;
            service.namespaces = file_info->namespaces;
            service.source_file = file_info->file_path;

            parse_port_type(file_info, service, child);

            if (!service.operations.empty()) {
                file_info->services.push_back(service);
            }
        }
    }

    // 合并之前通过 wsdl:import 暂存的服务到主服务
    if (imported_service_count > 0 && file_info->services.size() > imported_service_count) {
        if (config_.verbose) {
            std::cout << "合并之前暂存的 " << imported_service_count << " 个导入服务到主服务" << std::endl;
        }

        // 找到第一个本地定义的服务（跳过导入的服务）
        auto& main_service = file_info->services[imported_service_count];

        // 合并所有导入的服务（索引 0 到 imported_service_count-1）
        for (size_t i = 0; i < imported_service_count; ++i) {
            const auto& imported_service = file_info->services[i];

            if (config_.verbose) {
                std::cout << "  合并导入服务 " << imported_service.port_type
                          << " 的 " << imported_service.operations.size() << " 个操作" << std::endl;
            }

            // 合并操作
            for (auto op : imported_service.operations) {
                // 检查是否重复
                bool duplicate = false;
                for (const auto& existing_op : main_service.operations) {
                    if (existing_op.name == op.name) {
                        duplicate = true;
                        break;
                    }
                }

                if (!duplicate) {
                    // 确保操作有正确的命名空间前缀（防御性检查）
                    if (op.source_ns_prefix.empty() || op.source_ns_prefix == "unknown") {
                        // 尝试从主服务的namespaces中查找
                        for (const auto& [prefix, uri] : main_service.namespaces) {
                            if (uri == op.source_namespace) {
                                op.source_ns_prefix = prefix;
                                break;
                            }
                        }
                    }
                    main_service.operations.push_back(op);
                }
            }

            // 合并命名空间
            for (const auto& [prefix, uri] : imported_service.namespaces) {
                if (main_service.namespaces.find(prefix) == main_service.namespaces.end()) {
                    main_service.namespaces[prefix] = uri;
                }
            }
        }

        // 移除已合并的导入服务
        file_info->services.erase(file_info->services.begin(), file_info->services.begin() + imported_service_count);
    }

    // 第二遍：解析所有 binding，将 soapAction 映射到 service 的操作
    for (xmlNodePtr child = root->children; child; child = child->next) {
        if (child->type != XML_ELEMENT_NODE) continue;

        std::string node_name = reinterpret_cast<const char*>(child->name);

        if (node_name == "binding") {
            // 获取 binding 的 type 属性，用于找到对应的 portType
            std::string binding_type = get_node_attribute(child, "type");

            // 移除命名空间前缀获取 portType 名称
            std::string port_type_name = binding_type;
            size_t colon_pos = binding_type.find(':');
            if (colon_pos != std::string::npos) {
                port_type_name = binding_type.substr(colon_pos + 1);
            }

            // 查找对应的 service
            for (auto& service : file_info->services) {
                if (service.port_type == port_type_name) {
                    parse_binding(service, child);
                    break;
                }
            }
        }
    }
}

void WsdlParser::parse_port_type(std::shared_ptr<FileInfo> file_info, WsdlService& service, xmlNodePtr port_type_node) {
    service.port_type = get_node_attribute(port_type_node, "name");
    service.name = service.port_type + "Service";
    service.documentation = get_documentation(port_type_node);
    
    // 解析操作（包括operation和notification）
    for (xmlNodePtr operation_node = port_type_node->children; operation_node; operation_node = operation_node->next) {
        if (operation_node->type != XML_ELEMENT_NODE) continue;

        std::string node_name = reinterpret_cast<const char*>(operation_node->name);
        if (node_name == "operation") {
            WsdlOperation operation;
            operation.name = get_node_attribute(operation_node, "name");
            operation.documentation = get_documentation(operation_node);

            // 解析input和output
            for (xmlNodePtr io_node = operation_node->children; io_node; io_node = io_node->next) {
                if (io_node->type != XML_ELEMENT_NODE) continue;

                std::string io_name = reinterpret_cast<const char*>(io_node->name);
                if (io_name == "input") {
                    operation.input_message = get_node_attribute(io_node, "message");
                    // 根据消息查找对应的元素名
                    std::string element_name = find_element_by_message(file_info, operation.input_message);
                    operation.input_type = element_name.empty() ? (operation.name + "Request") : element_name;
                } else if (io_name == "output") {
                    operation.output_message = get_node_attribute(io_node, "message");
                    // 根据消息查找对应的元素名
                    std::string element_name = find_element_by_message(file_info, operation.output_message);
                    operation.output_type = element_name.empty() ? (operation.name + "Response") : element_name;
                }
            }

            service.operations.push_back(operation);
        } else if (node_name == "notification") {
            // 处理单向通知操作（notification）
            WsdlOperation operation;
            operation.name = get_node_attribute(operation_node, "name");
            operation.documentation = get_documentation(operation_node);

            // notification 只有 output，没有 input
            for (xmlNodePtr io_node = operation_node->children; io_node; io_node = io_node->next) {
                if (io_node->type != XML_ELEMENT_NODE) continue;

                std::string io_name = reinterpret_cast<const char*>(io_node->name);
                if (io_name == "output") {
                    operation.output_message = get_node_attribute(io_node, "message");
                    // 根据消息查找对应的元素名
                    std::string element_name = find_element_by_message(file_info, operation.output_message);
                    operation.output_type = element_name.empty() ? (operation.name + "Message") : element_name;
                    // notification 没有 input，使用相同的类型
                    operation.input_type = operation.output_type;
                }
            }

            service.operations.push_back(operation);
        }
    }
}

void WsdlParser::parse_binding(WsdlService& service, xmlNodePtr binding_node) {
    service.binding = get_node_attribute(binding_node, "name");

    // 解析 binding 中的操作，提取 soapAction
    for (xmlNodePtr operation_node = binding_node->children; operation_node; operation_node = operation_node->next) {
        if (operation_node->type != XML_ELEMENT_NODE) continue;

        std::string node_name = reinterpret_cast<const char*>(operation_node->name);
        if (node_name == "operation") {
            std::string op_name = get_node_attribute(operation_node, "name");

            // 查找 soap:operation 子节点以获取 soapAction
            for (xmlNodePtr soap_node = operation_node->children; soap_node; soap_node = soap_node->next) {
                if (soap_node->type != XML_ELEMENT_NODE) continue;

                std::string soap_node_name = reinterpret_cast<const char*>(soap_node->name);
                if (soap_node_name == "operation") {
                    // 找到 soap:operation 节点
                    std::string soap_action = get_node_attribute(soap_node, "soapAction");

                    // 将 soapAction 映射到对应的操作
                    if (!soap_action.empty() && !op_name.empty()) {
                        for (auto& operation : service.operations) {
                            if (operation.name == op_name) {
                                operation.soap_action = soap_action;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
}

void WsdlParser::parse_service_node(WsdlService& service, xmlNodePtr service_node) {
    // 简化实现
    std::string service_name = get_node_attribute(service_node, "name");
    if (!service_name.empty()) {
        service.name = service_name;
    }
}

void WsdlParser::resolve_dependencies(std::vector<std::shared_ptr<FileInfo>>& files) {
    // 简单的依赖解析，实际项目中可以实现更复杂的逻辑
    for (auto& file : files) {
        for (const auto& import_path : file->imports) {
            auto it = loaded_files_.find(import_path);
            if (it != loaded_files_.end()) {
                file->dependencies.push_back(it->second);
            }
        }
    }
}

void WsdlParser::determine_namespace_info(std::shared_ptr<FileInfo> file_info) {
    if (file_info->target_namespace.empty()) {
        return;
    }
    
    if (config_.verbose) {
        std::cout << "确定命名空间信息 - 文件: " << file_info->file_path 
                  << ", 目标命名空间: " << file_info->target_namespace << std::endl;
    }
    
    // 优先级1: 配置文件指定
    auto schema_config = find_schema_config(config_, file_info->target_namespace);
    if (schema_config) {
        file_info->namespace_prefix = schema_config->ns_prefix;
        file_info->file_prefix_name = schema_config->output_name;
        if (config_.verbose) {
            std::cout << "找到配置匹配 - 前缀: " << schema_config->ns_prefix 
                      << ", 文件名: " << schema_config->output_name << std::endl;
        }
    } else {
        if (auto parent_file = file_info->parent_file.lock()) {
            const auto it = std::find_if(parent_file->namespaces.begin(), parent_file->namespaces.end(),
                                   [&](const auto& ns) {
                                       return ns.second == file_info->target_namespace;
                                   });
            if (it!= parent_file->namespaces.end()) {
                file_info->namespace_prefix = it->first;
                file_info->file_prefix_name = it->first;
                if (config_.verbose) {
                    std::cout << "从父文件继承命名空间 - 前缀: " << it->first
                              << ", 文件名: " << it->first << std::endl;
                }
            }
        }
        if (file_info->namespace_prefix.empty()) {
            // 优先级2: 命名空间声明中查找
            for (const auto& [prefix, uri] : file_info->namespaces) {
                if (uri == file_info->target_namespace) {
                    file_info->namespace_prefix = prefix;
                    break;
                }
            }
        }

        // 优先级3: 从URL生成
        if (file_info->namespace_prefix.empty()) {
            file_info->namespace_prefix = generate_name_from_url(file_info->target_namespace);
        }
        
        if (file_info->file_prefix_name.empty()) {
            file_info->file_prefix_name = generate_name_from_url(file_info->target_namespace);
        }
        
        if (config_.verbose) {
            std::cout << "未找到配置匹配，使用生成前缀: " << file_info->namespace_prefix 
                      << ", 文件名: " << file_info->file_prefix_name << std::endl;
        }
    }
    
    // 确保所有类型都有正确的命名空间前缀，并完善所有字段的命名空间信息
    for (auto& type : file_info->types) {
        // 设置类型的命名空间前缀
        if (type.ns_prefix.empty()) {
            type.ns_prefix = file_info->namespace_prefix;
        }
        // Replace hyphens with underscores in namespace prefix
        std::replace(type.ns_prefix.begin(), type.ns_prefix.end(), '-', '_');
        
        // 完善所有字段的命名空间前缀和类型信息
        for (auto& field : type.fields) {
            resolve_field_namespace_and_type(field, file_info);
        }
        
        // 处理基类型的命名空间前缀
        if (!type.base_type.empty()) {
            type.base_type = resolve_type_reference(type.base_type, file_info);
        }
        
        // 处理列表元素类型的命名空间前缀
        if (!type.list_item_type.empty()) {
            type.list_item_type = resolve_type_reference(type.list_item_type, file_info);
        }
        
        if (config_.verbose) {
            std::cout << "设置类型前缀: " << type.name << " -> " << type.ns_prefix << "_" << type.name << std::endl;
        }
    }
}

std::string WsdlParser::get_node_attribute(xmlNodePtr node, const std::string& attr_name) const {
    xmlChar* value = xmlGetProp(node, reinterpret_cast<const xmlChar*>(attr_name.c_str()));
    if (value) {
        std::string result = reinterpret_cast<const char*>(value);
        xmlFree(value);
        return result;
    }
    return "";
}

std::string WsdlParser::get_documentation(xmlNodePtr node) const {
    // 查找annotation/documentation
    for (xmlNodePtr child = node->children; child; child = child->next) {
        if (child->type == XML_ELEMENT_NODE && 
            std::string(reinterpret_cast<const char*>(child->name)) == "annotation") {
            
            for (xmlNodePtr anno_child = child->children; anno_child; anno_child = anno_child->next) {
                if (anno_child->type == XML_ELEMENT_NODE && 
                    std::string(reinterpret_cast<const char*>(anno_child->name)) == "documentation") {
                    
                    xmlChar* content = xmlNodeGetContent(anno_child);
                    if (content) {
                        std::string result = reinterpret_cast<const char*>(content);
                        xmlFree(content);
                        // 清理空白
                        result.erase(0, result.find_first_not_of(" \t\n\r"));
                        result.erase(result.find_last_not_of(" \t\n\r") + 1);
                        return result;
                    }
                }
            }
        }
    }
    return "";
}


std::string WsdlParser::find_namespace_prefix_by_uri(std::shared_ptr<FileInfo> file_info, const std::string& namespace_uri) const {
    if (namespace_uri.empty()) {
        return "";
    }
    
    // 1. 首先查找配置文件中的命名空间映射
    for (const auto& schema_config : config_.schema_configs) {
        if (schema_config.ns_url == namespace_uri) {
            std::string prefix = schema_config.ns_prefix;
            // Replace hyphens with underscores in namespace prefix
            std::replace(prefix.begin(), prefix.end(), '-', '_');
            // for (auto item = file_info->namespaces.begin(); item != file_info->namespaces.end(); ++item) {
            //     if (item->second == namespace_uri) {
            //         file_info->namespaces.erase(item);
            //         break;
            //     }
            // }
            // file_info->namespace_prefix = schema_config.ns_prefix; // 更新文件的命名空间前缀
            // file_info->namespaces[schema_config.ns_prefix] = namespace_uri; // 更新文件的命名空间映射
            return prefix;
        }
    }
    if (auto parent_file = file_info->parent_file.lock()) {
        for (auto &it : parent_file->namespaces) {
            if (it.second == namespace_uri) {
                std::string result_prefix = it.first;
                // Replace hyphens with underscores in namespace prefix
                std::replace(result_prefix.begin(), result_prefix.end(), '-', '_');
                // file_info->namespace_prefix = it.first; // 更新文件的命名空间前缀
                // for (auto item = file_info->namespaces.begin(); item != file_info->namespaces.end(); ++item) {
                //     if (item->second == namespace_uri) {
                //         file_info->namespaces.erase(item);
                //         break;
                //     }
                // }
                // file_info->namespace_prefix = it.first; // 更新文件的命名空间前缀
                // file_info->namespaces[it.first] = namespace_uri; // 更新文件的命名空间映射
                return result_prefix;
            }
        }
    }
    
    // 2. 在文件的命名空间声明中查找
    for (const auto& [prefix, uri] : file_info->namespaces) {
        if (uri == namespace_uri) {
            std::string result_prefix = prefix;
            // Replace hyphens with underscores in namespace prefix
            std::replace(result_prefix.begin(), result_prefix.end(), '-', '_');
            return result_prefix;
        }
    }
    
    // 3. 如果是目标命名空间，使用文件的命名空间前缀
    if (namespace_uri == file_info->target_namespace) {
        return file_info->namespace_prefix;
    }
    
    return "";
}

std::string WsdlParser::get_node_namespace_uri(xmlNodePtr node) const {
    if (!node || !node->ns) {
        return "";
    }
    
    if (node->ns->href) {
        return reinterpret_cast<const char*>(node->ns->href);
    }
    
    return "";
}

bool WsdlParser::is_url(const std::string& path) const {
    return path.find("://") != std::string::npos;
}

std::string WsdlParser::detect_file_type_by_content(const std::string& file_path) const {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        return "";
    }
    
    // 读取文件前几行来检查内容
    std::string line;
    std::string content;
    int lines_read = 0;
    const int max_lines = 30; // 读取足够的行数来检测内容
    
    while (std::getline(file, line) && lines_read < max_lines) {
        content += line + "\n";
        lines_read++;
    }
    file.close();
    
    // 检查是否为XML文件 (可能没有XML声明)
    bool has_xml_declaration = content.find("<?xml") != std::string::npos;
    bool has_xml_elements = content.find("<") != std::string::npos && content.find(">") != std::string::npos;
    
    if (!has_xml_declaration && !has_xml_elements) {
        return ""; // 不是XML文件
    }
    
    // 检查是否为WSDL文件
    if (content.find("<definitions") != std::string::npos ||
        content.find("http://schemas.xmlsoap.org/wsdl/") != std::string::npos) {
        return "wsdl";
    }
    
    // 检查是否为XSD文件
    if (content.find("http://www.w3.org/2001/XMLSchema") != std::string::npos ||
        content.find("<xs:schema") != std::string::npos ||
        content.find("<xsd:schema") != std::string::npos ||
        content.find("<schema") != std::string::npos) {
        return "xsd";
    }
    
    // 特殊检查：已知的W3C schema文件
    if (content.find("http://www.w3.org/2003/05/soap-envelope") != std::string::npos ||
        content.find("soap-envelope") != std::string::npos ||
        content.find("http://www.w3.org/2005/05/xmlmime") != std::string::npos ||
        content.find("xmlmime") != std::string::npos) {
        return "xsd";
    }
    
    return ""; // 未知类型
}

/**
 * @brief 解析字段的命名空间和类型信息
 * @param field 要处理的字段
 * @param file_info 当前文件信息
 */
void WsdlParser::resolve_field_namespace_and_type(WsdlField& field, std::shared_ptr<FileInfo> file_info) {
    // 检查是否已经是C++标准库类型或系统类型，如果是则跳过处理
    static const std::set<std::string> CPP_SYSTEM_TYPES = {
        "std::string", "std::vector", "std::optional", "std::map", "std::set",
        "int32_t", "int64_t", "uint32_t", "uint64_t", "float", "double", "bool",
        "AnyElement", "DateTime", "TimePart", "Base64Binary", "HexBinary"
    };
    
    if (CPP_SYSTEM_TYPES.find(field.type) != CPP_SYSTEM_TYPES.end()) {
        return;
    }
    
    // 如果字段已经有完整的命名空间前缀，就不需要再处理
    if (!field.ns_prefix.empty() && field.ns_prefix.find('_') != std::string::npos) {
        return;
    }
    
    // 处理字段类型的命名空间解析
    if (!field.type.empty()) {
        field.type = resolve_type_reference(field.type, file_info);
        // 当类型信息变更时清除缓存
        field.clear_cache();
    }
    
    // 如果字段没有命名空间前缀，使用文件的默认命名空间前缀
    // 字段命名空间应该由其所属的父类型决定，而不是由字段类型决定
    if (field.ns_prefix.empty()) {
        field.ns_prefix = file_info->namespace_prefix;
        field.clear_cache(); // 命名空间变更时清除缓存
    }
    
    // 确保命名空间前缀符合C++标识符规范
    if (!field.ns_prefix.empty()) {
        std::replace(field.ns_prefix.begin(), field.ns_prefix.end(), '-', '_');
    }
}

/**
 * @brief 解析类型引用，返回完整的类型名（包含命名空间前缀）
 * @param type_ref 类型引用字符串
 * @param file_info 当前文件信息
 * @return 解析后的完整类型名
 */
std::string WsdlParser::resolve_type_reference(const std::string& type_ref, std::shared_ptr<FileInfo> file_info) {
    if (type_ref.empty()) {
        return type_ref;
    }
    
    // 首先检查是否为已转换的C++类型（包含::的类型）
    if (type_ref.find("::") != std::string::npos) {
        return type_ref; // 已经是C++类型，直接返回
    }
    
    // 检查是否为C++标准库或系统类型
    static const std::set<std::string> CPP_SYSTEM_TYPES = {
        "std::string", "std::vector", "std::optional", "std::map", "std::set",
        "int32_t", "int64_t", "uint32_t", "uint64_t", "float", "double", "bool",
        "AnyElement", "DateTime", "TimePart", "Base64Binary", "HexBinary"
    };
    
    if (CPP_SYSTEM_TYPES.find(type_ref) != CPP_SYSTEM_TYPES.end()) {
        return type_ref; // C++系统类型不需要命名空间前缀
    }
    
    // 检查是否为基础XSD类型，如果是则转换为C++类型
    if (TypeUtils::is_basic_xsd_type(type_ref)) {
        auto cpp_type = TypeUtils::convert_xsd_to_cpp_type(type_ref);
        return cpp_type; // 返回转换后的C++类型，不再进行命名空间处理
    }
    
    auto [ns_prefix, local_name] = TypeUtils::parse_type_ref(type_ref);
    
    if (!ns_prefix.empty()) {
        // 类型已经有命名空间前缀，解析其对应的URI并查找配置的前缀
        auto ns_it = file_info->namespaces.find(ns_prefix);
        if (ns_it != file_info->namespaces.end()) {
            std::string namespace_uri = ns_it->second;
            
            // 查找配置中的前缀
            for (const auto& schema_config : config_.schema_configs) {
                if (schema_config.ns_url == namespace_uri) {
                    std::string final_prefix = schema_config.ns_prefix;
                    std::replace(final_prefix.begin(), final_prefix.end(), '-', '_');
                    std::replace(local_name.begin(), local_name.end(), '-', '_');
                    return final_prefix + "_" + local_name;
                }
            }
            
            // 如果没有找到配置，从父文件查找
            if (auto parent_file = file_info->parent_file.lock()) {
                for (const auto& parent_ns : parent_file->namespaces) {
                    if (parent_ns.second == namespace_uri) {
                        std::string final_prefix = parent_ns.first;
                        std::replace(final_prefix.begin(), final_prefix.end(), '-', '_');
                        std::replace(local_name.begin(), local_name.end(), '-', '_');
                        return final_prefix + "_" + local_name;
                    }
                }
            }
            
            // 使用原始前缀
            std::replace(ns_prefix.begin(), ns_prefix.end(), '-', '_');
            std::replace(local_name.begin(), local_name.end(), '-', '_');
            return ns_prefix + "_" + local_name;
        }
    } else {
        // 没有命名空间前缀，检查是否是同文件内的类型
        for (const auto& file_type : file_info->types) {
            if (file_type.name == type_ref) {
                // 找到同文件内的类型，使用其完整前缀名
                std::string type_ns_prefix = file_type.ns_prefix.empty() ? file_info->namespace_prefix : file_type.ns_prefix;
                std::replace(type_ns_prefix.begin(), type_ns_prefix.end(), '-', '_');
                std::string clean_name = local_name;
                std::replace(clean_name.begin(), clean_name.end(), '-', '_');
                
                if (!type_ns_prefix.empty()) {
                    return type_ns_prefix + "_" + clean_name;
                }
                return clean_name;
            }
        }
        
        // 如果是没有前缀的类型引用，使用文件的默认命名空间前缀
        if (!file_info->namespace_prefix.empty()) {
            std::string file_prefix = file_info->namespace_prefix;
            std::replace(file_prefix.begin(), file_prefix.end(), '-', '_');
            std::string clean_name = type_ref;
            std::replace(clean_name.begin(), clean_name.end(), '-', '_');
            return file_prefix + "_" + clean_name;
        }
    }
    
    // 默认情况，直接返回清理后的类型名
    std::string result = type_ref;
    std::replace(result.begin(), result.end(), '-', '_');
    return result;
}

void WsdlParser::record_type_usage(std::shared_ptr<FileInfo> file_info, 
                                  const std::string& type_name, 
                                  bool is_attribute, 
                                  const std::string& location) {
    if (type_name.empty()) return;
    
    // 跳过基础类型（xs:string, xs:int等）
    if (type_name.find("xs:") == 0 || type_name.find("xsd:") == 0) {
        return;
    }
    
    auto& usage = file_info->type_usage[type_name];
    if (is_attribute) {
        usage.add_attribute_usage(location);
    } else {
        usage.add_element_usage(location);  
    }
}

} // namespace wsdl_parser2