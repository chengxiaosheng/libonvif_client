/**
 * @file type_utils.cpp
 * @brief 统一的类型工具类实现
 */

#include "type_utils.h"
#include <regex>
#include <algorithm>

namespace wsdl_parser2 {

// 基础XSD类型集合 - 统一定义
const std::set<std::string> TypeUtils::BASIC_XSD_TYPES = {
    "xs:string", "xsd:string", "xs:token", "xsd:token",
    "xs:anyURI", "xsd:anyURI", "xs:QName", "xsd:QName", "xsd:NCName",
    "xs:duration", "xsd:duration", "xs:int", "xsd:int",
    "xs:integer", "xsd:integer", "xs:long", "xsd:long",
    "xs:short", "xsd:short", "xs:byte", "xsd:byte",
    "xs:unsignedInt", "xsd:unsignedInt", "xs:unsignedLong", "xsd:unsignedLong",
    "xs:unsignedShort", "xsd:unsignedShort", "xs:unsignedByte", "xsd:unsignedByte",
    "xs:float", "xsd:float", "xs:double", "xsd:double",
    "xs:nonNegativeInteger", "xsd:nonNegativeInteger",
    "xs:decimal", "xsd:decimal", "xs:boolean", "xsd:boolean",
    "xs:dateTime", "xsd:dateTime", "xs:date", "xsd:date",
    "xs:time", "xsd:time", "xs:base64Binary", "xsd:base64Binary",
    "xs:hexBinary", "xsd:hexBinary", "xs:anyType", "xsd:anyType",
    "xs:anySimpleType", "xsd:anySimpleType"
};

// 基础C++类型集合
const std::set<std::string> TypeUtils::BASIC_CPP_TYPES = {
    "std::string", "int32_t", "int64_t", "int16_t", "int8_t",
    "uint32_t", "uint64_t", "uint16_t", "uint8_t",
    "float", "double", "bool", "char", "int", "long",
    "std::vector", "std::optional"
};

// XSD到C++类型映射 - 统一定义
const std::map<std::string, std::string> TypeUtils::XSD_TO_CPP_TYPES = {
    // 字符串类型
    {"xs:string", "std::string"}, {"xsd:string", "std::string"},
    {"xs:token", "std::string"}, {"xsd:token", "std::string"},
    {"xs:anyURI", "std::string"}, {"xsd:anyURI", "std::string"},
    {"xs:QName", "std::string"}, {"xsd:QName", "std::string"}, {"xsd:NCName", "std::string"},
    {"xs:duration", "std::string"}, {"xsd:duration", "std::string"},
    
    // 数值类型
    {"xs:int", "int32_t"}, {"xsd:int", "int32_t"},
    {"xs:integer", "int64_t"}, {"xsd:integer", "int64_t"},
    {"xs:long", "int64_t"}, {"xsd:long", "int64_t"},
    {"xs:short", "int16_t"}, {"xsd:short", "int16_t"},
    {"xs:byte", "int8_t"}, {"xsd:byte", "int8_t"},
    
    // 无符号数值类型
    {"xs:unsignedInt", "uint32_t"}, {"xsd:unsignedInt", "uint32_t"},
    {"xs:unsignedLong", "uint64_t"}, {"xsd:unsignedLong", "uint64_t"},
    {"xs:unsignedShort", "uint16_t"}, {"xsd:unsignedShort", "uint16_t"},
    {"xs:unsignedByte", "uint8_t"}, {"xsd:unsignedByte", "uint8_t"},
    {"xs:nonNegativeInteger", "uint64_t"}, {"xsd:nonNegativeInteger", "uint64_t"},
    
    // 浮点类型
    {"xs:float", "float"}, {"xsd:float", "float"},
    {"xs:double", "double"}, {"xsd:double", "double"},
    {"xs:decimal", "double"}, {"xsd:decimal", "double"},
    
    // 布尔类型
    {"xs:boolean", "bool"}, {"xsd:boolean", "bool"},
    
    // 日期时间类型
    {"xs:dateTime", "std::string"}, {"xsd:dateTime", "std::string"},
    {"xs:date", "std::string"}, {"xsd:date", "std::string"},
    {"xs:time", "std::string"}, {"xsd:time", "std::string"},
    
    // 二进制类型
    {"xs:base64Binary", "std::string"}, {"xsd:base64Binary", "std::string"},
    {"xs:hexBinary", "std::string"}, {"xsd:hexBinary", "std::string"},
    
    // 通用类型
    {"xs:anyType", "std::string"}, {"xsd:anyType", "std::string"},
    {"xs:anySimpleType", "std::string"}, {"xsd:anySimpleType", "std::string"}
};

bool TypeUtils::is_basic_xsd_type(const std::string& type_name) {
    return BASIC_XSD_TYPES.count(type_name) > 0;
}

bool TypeUtils::is_basic_cpp_type(const std::string& type_name) {
    // 检查是否为基础C++类型
    if (BASIC_CPP_TYPES.count(type_name) > 0) {
        return true;
    }
    
    // 检查是否为容器类型
    if (type_name.find("std::vector<") == 0 || 
        type_name.find("std::optional<") == 0) {
        return true;
    }
    
    return false;
}

std::string TypeUtils::convert_xsd_to_cpp_type(const std::string& xsd_type) {
    auto it = XSD_TO_CPP_TYPES.find(xsd_type);
    if (it != XSD_TO_CPP_TYPES.end()) {
        return it->second;
    }
    
    // 如果没有找到映射，返回原类型名
    return xsd_type;
}

std::pair<std::string, std::string> TypeUtils::parse_type_ref(const std::string& type_ref) {
    size_t pos = type_ref.find(':');
    if (pos != std::string::npos) {
        return {type_ref.substr(0, pos), type_ref.substr(pos + 1)};
    }
    return {"", type_ref};
}

std::string TypeUtils::clean_type_name(const std::string& type_name) {
    std::string clean_name = type_name;
    
    // 移除std::vector<...>包装
    std::regex vector_regex(R"(std::vector<(.+)>)");
    std::smatch match;
    if (std::regex_match(clean_name, match, vector_regex)) {
        clean_name = match[1].str();
    }
    
    // 移除std::optional<...>包装
    std::regex optional_regex(R"(std::optional<(.+)>)");
    if (std::regex_match(clean_name, match, optional_regex)) {
        clean_name = match[1].str();
    }
    
    // 移除命名空间前缀
    auto [ns_prefix, local_name] = parse_type_ref(clean_name);
    return local_name;
}
bool TypeUtils::needs_brace_initialization(const std::string& type_name) {
    // 需要 {} 初始化的类型：基础数值类型、bool
    static const std::set<std::string> types_need_init = {
        // 整型
        "int32_t", "int64_t", "int16_t", "int8_t",
        "uint32_t", "uint64_t", "uint16_t", "uint8_t",
        "int", "long", "short", "char",
        "unsigned int", "unsigned long", "unsigned short", "unsigned char",
        "size_t", "ssize_t",
        // 浮点型
        "float", "double", "long double",
        // 布尔型
        "bool"
    };

    // 直接匹配基础类型
    if (types_need_init.count(type_name) > 0) {
        return true;
    }

    // 检查是否为枚举类型（通常以 _prefix 开头，且不包含 std:: 或 <>）
    // 枚举类型也需要初始化
    if (type_name.find("std::") == std::string::npos &&
        type_name.find('<') == std::string::npos &&
        type_name.find('>') == std::string::npos) {
        // 可能是自定义类型（结构体或枚举）
        // 枚举类型通常不会有下划线开头，但这里保守处理
        // 实际上枚举应该由调用者判断，这里不做处理
        // 返回 false，让结构体自己初始化
        return false;
    }

    // 不需要初始化的类型：
    // - std::string, std::vector, std::optional, std::map 等容器
    // - 自定义结构体（它们应该有自己的默认构造函数）
    return false;
}

} // namespace wsdl_parser2