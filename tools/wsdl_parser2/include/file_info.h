/**
 * @file file_info.h
 * @brief 文件信息和类型定义
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include <optional>
#include <memory>
#include <libxml/tree.h>

namespace wsdl_parser2 {

/**
 * @brief 字段类型
 */
enum class FieldType {
    ELEMENT,        // 普通元素
    ATTRIBUTE,      // XML属性
    ANY_ELEMENT,    // xs:any
    ANY_ATTRIBUTE,  // xs:anyAttribute
    TEXT_CONTENT    // 元素的文本内容（simpleContent）
};
struct WsdlType;

/**
 * @brief WSDL/XSD 字段定义
 */
struct WsdlField {
    std::string name;                           // 字段名称
    std::string type;                           // 字段类型
    std::string ns_prefix;                      // 命名空间前缀
    std::string doc;                            // 文档说明
    bool is_optional = false;                   // 是否可选
    bool is_array = false;                      // 是否数组
    FieldType field_type = FieldType::ELEMENT;  // 字段类型
    std::string default_value;                  // 默认值
    
    // 优化：缓存计算结果，避免重复计算
    mutable std::string cached_cpp_type;        // 缓存的C++类型
    mutable std::string cached_cpp_field_name;  // 缓存的C++字段名
    mutable bool cpp_type_cached = false;       // C++类型是否已缓存
    mutable bool cpp_field_name_cached = false; // C++字段名是否已缓存

    std::string any_namespace;
    std::string process_contents;               // 处理内容方式（strict/lax/skip）
    
    // 优化：添加父级WsdlType的指针引用，避免重复查找
    WsdlType* parent_type = nullptr;            // 父级类型引用
    
    /**
     * @brief 获取C++类型名（带缓存优化）
     */
    std::string get_cpp_type() const;
    
    /**
     * @brief 获取C++字段名（转换为下划线风格，带缓存优化）
     */
    std::string get_cpp_field_name() const;
    
    /**
     * @brief 清除缓存（当字段信息变更时调用）
     */
    void clear_cache() const;
};

/**
 * @brief WSDL/XSD 类型定义
 */
struct WsdlType {
    std::string name;                       // 类型名称
    std::string ns_prefix;                  // 命名空间前缀
    std::string ns_uri;                     // 命名空间URI
    std::string base_type;                  // 基类型
    std::string source_file;                // 源文件路径
    std::vector<WsdlField> fields;          // 字段列表
    std::vector<std::string> enumeration;   // 枚举值（如果是枚举）
    
    // 类型特征
    bool is_simple_type = false;            // 是否简单类型
    bool is_enum = false;                   // 是否枚举
    bool is_list = false;                   // 是否列表类型
    bool is_mixed = false;                  // 是否混合内容
    bool is_simple_type_rename = false;     // 是否简单类型重命名
    
    // 简单类型属性
    std::string base_simple_type;           // 基础简单类型
    std::string list_item_type;             // 列表元素类型
    int max_length = -1;                    // 最大长度限制
    int min_length = -1;                    // 最小长度限制
    
    // 优化：缓存生成的C++类型名
    mutable std::string cached_cpp_type_name;
    mutable bool cpp_type_name_cached = false;
    
    /**
     * @brief 获取C++类型名（带缓存）
     */
    std::string get_cpp_type_name() const;
    
    /**
     * @brief 设置字段的父级类型引用
     */
    void setup_field_parent_references();
};

/**
 * @brief 类型使用上下文 - 跟踪类型在XML中的使用方式（优化版）
 */
struct TypeUsageContext {
    bool used_as_element = false;      // 是否用作XML元素
    bool used_as_attribute = false;    // 是否用作XML属性
    
    // 位置信息 - 保留用于类型验证和调试
    std::set<std::string> attribute_locations;
    std::set<std::string> element_locations;
    
    // 添加元素使用记录（优化版 - 支持空参数调用）
    void add_element_usage(const std::string& location = "") {
        used_as_element = true;
        if (!location.empty()) {
            element_locations.insert(location);
        }
    }
    
    // 添加属性使用记录（优化版 - 支持空参数调用）
    void add_attribute_usage(const std::string& location = "") {
        used_as_attribute = true;
        if (!location.empty()) {
            attribute_locations.insert(location);
        }
    }
    
    // 判断是否需要双重适配器支持
    bool needs_both_adapters() const {
        return used_as_attribute && used_as_element;
    }
};

/**
 * @brief WSDL 操作定义
 */
struct WsdlOperation {
    std::string name;                       // 操作名称
    std::string input_message;              // 输入消息
    std::string output_message;             // 输出消息
    std::string input_type;                 // 输入类型（消息映射的元素）
    std::string output_type;                // 输出类型（消息映射的元素）
    std::string soap_action;                // SOAP Action
    std::string documentation;              // 文档说明
    std::string source_namespace;           // 操作来源的命名空间URI
    std::string source_ns_prefix;           // 操作来源的命名空间前缀
};

/**
 * @brief WSDL 消息定义
 */
struct WsdlMessage {
    std::string name;                       // 消息名称
    std::string element_name;               // 引用的元素名（带命名空间前缀）
    std::string documentation;              // 文档说明
};

/**
 * @brief WSDL 服务定义
 */
struct WsdlService {
    std::string name;                       // 服务名称
    std::string port_type;                  // PortType名称
    std::string binding;                    // Binding名称
    std::string target_namespace;           // 目标命名空间
    std::string namespace_prefix;           // 目标命名空间前缀
    std::string service_url;                // 服务URL
    std::string documentation;              // 文档说明
    std::string source_file;                // 源文件路径
    std::vector<WsdlOperation> operations;  // 操作列表
    std::map<std::string, std::string> namespaces; // 命名空间映射
};

/**
 * @brief 文件处理状态
 */
enum class FileStatus {
    PENDING,        // 等待处理
    PROCESSING,     // 正在处理
    COMPLETED,      // 处理完成
    FAILED,         // 处理失败
    BLOCKED         // 被依赖阻塞
};

/**
 * @brief 文件信息
 */
struct FileInfo {
    // 基本信息
    std::string file_path;                  // 文件路径
    std::string network_url;                // 网络URL（如果是下载的）
    std::string file_name;                  // 文件名（不含扩展名）
    std::string file_type;                  // 文件类型（wsdl/xsd）
    
    // 解析内容
    std::vector<WsdlType> types;            // 类型定义
    std::vector<WsdlService> services;      // 服务定义
    std::vector<WsdlMessage> messages;      // 消息定义
    std::set<std::string> imports;          // 导入的文件路径
    std::map<std::string, std::string> namespaces; // 命名空间映射
    
    // 类型使用上下文
    std::map<std::string, TypeUsageContext> type_usage; // 类型使用上下文映射
    
    // 命名空间信息
    std::string target_namespace;           // 目标命名空间
    std::string namespace_prefix;           // 使用的命名空间前缀
    std::string file_prefix_name;           // 文件前缀名称
    
    // 依赖关系
    std::vector<std::shared_ptr<FileInfo>> dependencies; // 依赖的文件

    // 父文件指针
    std::weak_ptr<FileInfo> parent_file; // 父文件指针（如果有）
    
    // 状态管理
    FileStatus status = FileStatus::PENDING; // 处理状态
    std::string error_message;              // 错误信息
    std::vector<std::string> warnings;     // 警告信息
    
    // XML文档
    std::shared_ptr<xmlDoc> xml_doc;        // XML文档指针
    
    // 构造函数
    FileInfo() = default;
    
    // 析构函数
    ~FileInfo() = default;
    
    // 禁止拷贝
    FileInfo(const FileInfo&) = delete;
    FileInfo& operator=(const FileInfo&) = delete;
    
    // 允许移动
    FileInfo(FileInfo&&) = default;
    FileInfo& operator=(FileInfo&&) = default;
};

} // namespace wsdl_parser2