/**
 * @file type_utils.h
 * @brief 统一的类型工具类 - 消除重复代码
 */

#pragma once

#include <string>
#include <map>
#include <set>
#include <utility>

namespace wsdl_parser2 {

/**
 * @brief 类型工具类 - 统一管理类型转换和检查逻辑
 */
class TypeUtils {
public:
    /**
     * @brief 检查是否为基础XSD类型
     */
    static bool is_basic_xsd_type(const std::string& type_name);
    
    /**
     * @brief 检查是否为基础C++类型
     */
    static bool is_basic_cpp_type(const std::string& type_name);
    
    /**
     * @brief 将XSD类型转换为C++类型
     */
    static std::string convert_xsd_to_cpp_type(const std::string& xsd_type);
    
    /**
     * @brief 解析类型引用，返回(命名空间前缀, 类型名)
     */
    static std::pair<std::string, std::string> parse_type_ref(const std::string& type_ref);
    
    /**
     * @brief 清理类型名称，移除容器包装和命名空间前缀
     */
    static std::string clean_type_name(const std::string& type_name);

    /**
     * @brief 检查类型是否需要 {} 初始化以避免未初始化警告
     * @param type_name C++ 类型名（已经转换后的）
     * @return true 如果需要 {} 初始化（基础数值类型、bool、枚举等）
     */
    static bool needs_brace_initialization(const std::string& type_name);

private:
    // 基础XSD类型集合
    static const std::set<std::string> BASIC_XSD_TYPES;
    
    // 基础C++类型集合  
    static const std::set<std::string> BASIC_CPP_TYPES;
    
    // XSD到C++类型映射
    static const std::map<std::string, std::string> XSD_TO_CPP_TYPES;
};

} // namespace wsdl_parser2