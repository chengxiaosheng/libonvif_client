/**
 * @file file_info.cpp
 * @brief 文件信息实现
 */

#include "../include/file_info.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>

namespace wsdl_parser2 {

// 性能优化的字符串工具
namespace {
    // 预编译的关键字集合，避免每次函数调用时重新构建
    const std::set<std::string>& get_cpp_keywords() {
        static const std::set<std::string> keywords = {
            "class", "struct", "enum", "union", "typedef", "template",
            "namespace", "using", "const", "static", "virtual", "override",
            "public", "private", "protected", "friend", "inline", "extern",
            "register", "auto", "volatile", "mutable", "explicit", "operator",
            "new", "delete", "this", "throw", "try", "catch", "sizeof",
            "typeid", "const_cast", "dynamic_cast", "reinterpret_cast",
            "static_cast", "true", "false", "nullptr", "and", "or", "not",
            "bitand", "bitor", "xor", "compl", "and_eq", "or_eq", "xor_eq",
            "not_eq", "alignof", "alignas", "decltype", "noexcept", "thread_local"
        };
        return keywords;
    }
    
    // 预编译的C++系统类型集合
    const std::set<std::string>& get_cpp_system_types() {
        static const std::set<std::string> cpp_system_types = {
            "std::string", "std::vector", "std::optional", "std::map", "std::set",
            "int32_t", "int64_t", "uint32_t", "uint64_t", "float", "double", "bool",
            "AnyElement", "DateTime", "TimePart", "Base64Binary", "HexBinary"
        };
        return cpp_system_types;
    }
}

std::string WsdlField::get_cpp_type() const {
    // 使用缓存避免重复计算
    if (cpp_type_cached) {
        return cached_cpp_type;
    }
    // 处理xs:any和xs:anyAttribute的特殊情况
    if (field_type == FieldType::ANY_ELEMENT) {
        // xs:any的类型在wsdl_parser.cpp中已经设置好了
        std::string cpp_type = type;
        
        // 处理数组
        if (is_array && cpp_type.find("std::vector<") != 0) {
            cpp_type = "std::vector<" + cpp_type + ">";
        }
        
        // 处理可选类型
        if (is_optional && !is_array && cpp_type.find("std::optional<") != 0) {
            cpp_type = "std::optional<" + cpp_type + ">";
        }
        
        // 缓存结果
        cached_cpp_type = cpp_type;
        cpp_type_cached = true;
        return cpp_type;
    }
    
    if (field_type == FieldType::ANY_ATTRIBUTE) {
        // xs:anyAttribute固定使用map存储属性
        std::string cpp_type = "std::map<std::string, std::string>";
        
        if (is_optional) {
            cpp_type = "std::optional<" + cpp_type + ">";
        }
        
        // 缓存结果
        cached_cpp_type = cpp_type;
        cpp_type_cached = true;
        return cpp_type;
    }
    
    // 基础类型映射
    static const std::map<std::string, std::string> TYPE_MAP = {
        // 字符串类型
        {"xs:string", "std::string"}, {"xsd:string", "std::string"},
        {"xs:token", "std::string"}, {"xsd:token", "std::string"},{"xsd:NCName", "std::string"},
        {"xs:anyURI", "std::string"}, {"xsd:anyURI", "std::string"},
        {"xs:QName", "std::string"}, {"xsd:QName", "std::string"},
        {"xs:duration", "std::string"}, {"xsd:duration", "std::string"},
        
        // 数值类型
        {"xs:int", "int32_t"}, {"xsd:int", "int32_t"},
        {"xs:integer", "int64_t"}, {"xsd:integer", "int64_t"},
        {"xs:long", "int64_t"}, {"xsd:long", "int64_t"},
        {"xs:short", "int16_t"}, {"xsd:short", "int16_t"},
        {"xs:byte", "int8_t"}, {"xsd:byte", "int8_t"},
        {"xs:unsignedInt", "uint32_t"}, {"xsd:unsignedInt", "uint32_t"},
        {"xs:unsignedLong", "uint64_t"}, {"xsd:unsignedLong", "uint64_t"},
        {"xs:unsignedShort", "uint16_t"}, {"xsd:unsignedShort", "uint16_t"},
        {"xs:unsignedByte", "uint8_t"}, {"xsd:unsignedByte", "uint8_t"},
        {"xs:float", "float"}, {"xsd:float", "float"},
        {"xs:double", "double"}, {"xsd:double", "double"},
        {"xs:decimal", "double"}, {"xsd:decimal", "double"},
        {"xs:nonNegativeInteger", "uint64_t"}, {"xsd:nonNegativeInteger", "uint64_t"},

        
        // 布尔类型
        {"xs:boolean", "bool"}, {"xsd:boolean", "bool"},
        
        // 日期时间类型（使用libonvif_client的类型）
        {"xs:dateTime", "DateTime"}, {"xsd:dateTime", "DateTime"},
        {"xs:date", "DateTime"}, {"xsd:date", "DateTime"},
        {"xs:time", "TimePart"}, {"xsd:time", "TimePart"},
        
        // 二进制类型
        {"xs:base64Binary", "Base64Binary"}, {"xsd:base64Binary", "Base64Binary"},
        {"xs:hexBinary", "HexBinary"}, {"xsd:hexBinary", "HexBinary"},
        
        // ONVIF特定类型
        {"xs:anyType", "AnyElement"}, {"xsd:anyType", "AnyElement"}
    };
    
    std::string cpp_type;
    
    // 尝试直接映射基础类型
    auto it = TYPE_MAP.find(type);
    if (it != TYPE_MAP.end()) {
        cpp_type = it->second;
    } else {
        // 检查是否为C++标准库类型，避免错误替换
        const auto& cpp_system_types = get_cpp_system_types();
        if (cpp_system_types.find(type) != cpp_system_types.end()) {
            cpp_type = type; // C++系统类型不进行字符替换
        } else {
            // 对于自定义类型，直接使用type字段（在wsdl_parser中已经处理过命名空间）
            // 确保字符合C++标识符规范
            cpp_type = type;
            std::replace(cpp_type.begin(), cpp_type.end(), '-', '_');
            std::replace(cpp_type.begin(), cpp_type.end(), ':', '_');
        }
    }

    // 检测递归引用：字段类型是否与父类型相同
    bool is_recursive = false;
    if (parent_type != nullptr && !parent_type->name.empty()) {
        std::string parent_name = parent_type->get_cpp_type_name();
        // 比较清理后的类型名
        if (cpp_type == parent_name) {
            is_recursive = true;
        }
    }

    // 处理数组
    if (is_array) {
        cpp_type = "std::vector<" + cpp_type + ">";
    }

    // 处理可选类型：递归引用使用unique_ptr，非递归使用optional
    if (is_optional && !is_array) {
        if (is_recursive) {
            // 递归引用使用unique_ptr避免不完整类型问题
            cpp_type = "std::unique_ptr<" + cpp_type + ">";
        } else {
            cpp_type = "std::optional<" + cpp_type + ">";
        }
    }
    
    // 缓存结果
    cached_cpp_type = cpp_type;
    cpp_type_cached = true;
    
    return cpp_type;
}

std::string WsdlField::get_cpp_field_name() const {
    // 使用缓存避免重复计算
    if (cpp_field_name_cached) {
        return cached_cpp_field_name;
    }
    // 转换为小写下划线风格
    std::string result(name);
    for (size_t i = 0; i < result.length(); ++i) {
        char  c = result[i];
        if ((i == 0 && isdigit(c)) || !(isdigit(c) || (c >= 'a' && c <= 'z') ||
              (c >= 'A' && c <= 'Z') || c == '_')) {
            result[i] = '_';
        }
    }
    
    // Replace hyphens with underscores to ensure valid C++ identifiers
    std::replace(result.begin(), result.end(), '-', '_');
    
    // 处理特殊关键字
    const auto& keywords = get_cpp_keywords();
    if (keywords.find(result) != keywords.end()) {
        result += "_";
    }
    
    // 缓存结果
    cached_cpp_field_name = result;
    cpp_field_name_cached = true;
    
    return result;
}

void WsdlField::clear_cache() const {
    cpp_type_cached = false;
    cpp_field_name_cached = false;
    cached_cpp_type.clear();
    cached_cpp_field_name.clear();
}

std::string WsdlType::get_cpp_type_name() const {
    if (cpp_type_name_cached) {
        return cached_cpp_type_name;
    }

    std::string cpp_name = name;
    // 处理命名空间和特殊字符
    std::replace(cpp_name.begin(), cpp_name.end(), '-', '_');
    std::replace(cpp_name.begin(), cpp_name.end(), ':', '_');

    // 如果有命名空间前缀，添加到类型名前面
    if (!ns_prefix.empty()) {
        std::string prefix = ns_prefix;
        std::replace(prefix.begin(), prefix.end(), '-', '_');
        std::replace(prefix.begin(), prefix.end(), ':', '_');
        cpp_name = prefix + "_" + cpp_name;
    }

    // 缓存结果
    cached_cpp_type_name = cpp_name;
    cpp_type_name_cached = true;

    return cpp_name;
}

void WsdlType::setup_field_parent_references() {
    for (auto& field : fields) {
        field.parent_type = this;
        // 设置父类型后清除缓存，因为递归检测结果可能改变
        field.clear_cache();
    }
}

} // namespace wsdl_parser2