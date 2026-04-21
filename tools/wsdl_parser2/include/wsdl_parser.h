/**
 * @file wsdl_parser.h
 * @brief 统一的WSDL/XSD解析器
 */

#pragma once

#include "config.h"
#include "file_info.h"
#include "downloader.h"
#include "type_utils.h"
#include <memory>
#include <vector>
#include <map>
#include <set>

namespace wsdl_parser2 {

/**
 * @brief 解析结果
 */
struct ParseResult {
    bool success = false;                   // 是否成功
    std::string error_message;              // 错误信息
    std::vector<std::string> warnings;     // 警告信息
    std::vector<std::shared_ptr<FileInfo>> files; // 解析的文件
    std::map<std::string, std::string> global_namespaces; // 全局命名空间映射
    
    /**
     * @brief 获取所有类型定义
     */
    std::vector<WsdlType> get_all_types() const;
    
    /**
     * @brief 获取所有服务定义
     */
    std::vector<WsdlService> get_all_services() const;
};

/**
 * @brief WSDL/XSD解析器
 */
class WsdlParser {
public:
    /**
     * @brief 构造函数
     * @param config 解析器配置
     */
    explicit WsdlParser(const ParserConfig& config);
    
    /**
     * @brief 析构函数
     */
    ~WsdlParser();
    
    /**
     * @brief 解析WSDL/XSD文件
     * @param file_path 文件路径或URL
     * @return 解析结果
     */
    ParseResult parse(const std::string& file_path);
    
    /**
     * @brief 批量解析文件
     * @param file_paths 文件路径或URL列表
     * @return 解析结果
     */
    ParseResult parse_multiple(const std::vector<std::string>& file_paths);

private:
    /**
     * @brief 加载文件（本地或网络）
     * @param file_path 文件路径或URL
     * @return 文件信息
     */
    std::shared_ptr<FileInfo> load_file(const std::string& file_path);
    
    /**
     * @brief 解析单个文件
     * @param file_info 文件信息
     * @return 是否成功
     */
    bool parse_file(std::shared_ptr<FileInfo> file_info);
    
    /**
     * @brief 解析WSDL文件
     * @param file_info 文件信息
     * @param root XML根节点
     * @return 是否成功
     */
    bool parse_wsdl_file(std::shared_ptr<FileInfo> file_info, xmlNodePtr root);
    
    /**
     * @brief 解析XSD文件
     * @param file_info 文件信息
     * @param root XML根节点
     * @return 是否成功
     */
    bool parse_xsd_file(std::shared_ptr<FileInfo> file_info, xmlNodePtr root);
    
    /**
     * @brief 收集命名空间信息
     * @param file_info 文件信息
     * @param node XML节点
     */
    void collect_namespaces(std::shared_ptr<FileInfo> file_info, xmlNodePtr node);
    
    /**
     * @brief 解析schema节点
     * @param file_info 文件信息
     * @param schema_node schema节点
     */
    void parse_schema(std::shared_ptr<FileInfo> file_info, xmlNodePtr schema_node);
    
    /**
     * @brief 解析复杂类型
     * @param file_info 文件信息
     * @param complex_type_node complexType节点
     * @param target_ns 目标命名空间
     */
    void parse_complex_type(std::shared_ptr<FileInfo> file_info, 
                           xmlNodePtr complex_type_node, 
                           const std::string& target_ns);
    
    /**
     * @brief 解析简单类型
     * @param file_info 文件信息
     * @param simple_type_node simpleType节点
     * @param target_ns 目标命名空间
     */
    void parse_simple_type(std::shared_ptr<FileInfo> file_info,
                          xmlNodePtr simple_type_node,
                          const std::string& target_ns);
    
    /**
     * @brief 解析顶级元素声明
     * @param file_info 文件信息
     * @param element_node element节点
     */
    void parse_top_level_element(std::shared_ptr<FileInfo> file_info, xmlNodePtr element_node);
    
    /**
     * @brief 记录类型使用上下文
     * @param file_info 文件信息
     * @param type_name 类型名称
     * @param is_attribute 是否用作属性
     * @param location 使用位置信息
     */
    void record_type_usage(std::shared_ptr<FileInfo> file_info, 
                          const std::string& type_name, 
                          bool is_attribute, 
                          const std::string& location);
    
    /**
     * @brief 解析元素
     * @param type 类型定义
     * @param element_node element节点
     * @param ns_prefix 命名空间前缀
     * @param file_info 文件信息（用于命名空间解析）
     */
    void parse_element(WsdlType& type, xmlNodePtr element_node, const std::string& ns_prefix, std::shared_ptr<FileInfo> file_info = nullptr);
    
    /**
     * @brief 解析属性
     * @param type 类型定义
     * @param attribute_node attribute节点
     */
    void parse_attribute(std::shared_ptr<FileInfo> file_info, WsdlType& type, xmlNodePtr attribute_node);
    
    /**
     * @brief 解析xs:any元素
     * @param type 类型定义
     * @param any_node any节点
     * @param ns_prefix 命名空间前缀
     */
    void parse_any_element(WsdlType& type, xmlNodePtr any_node, const std::string& ns_prefix);

    /**
     * @brief 解析sequence节点的子节点（element/any/choice）
     * @param type 类型定义
     * @param sequence_node sequence节点
     * @param ns_prefix 命名空间前缀
     * @param file_info 文件信息
     */
    void parse_sequence_children(WsdlType& type, xmlNodePtr sequence_node,
                                  const std::string& ns_prefix,
                                  std::shared_ptr<FileInfo> file_info);

    /**
     * @brief 解析xs:choice元素
     * @param type 类型定义
     * @param choice_node choice节点
     * @param ns_prefix 命名空间前缀
     * @param file_info 文件信息
     */
    void parse_choice(WsdlType& type, xmlNodePtr choice_node,
                       const std::string& ns_prefix,
                       std::shared_ptr<FileInfo> file_info);

    /**
     * @brief 解析xs:anyAttribute
     * @param type 类型定义
     * @param any_attr_node anyAttribute节点
     */
    void parse_any_attribute(WsdlType& type, xmlNodePtr any_attr_node);
    
    /**
     * @brief 解析继承关系
     * @param type 类型定义
     * @param content_node complexContent/simpleContent节点
     * @param ns_prefix 命名空间前缀
     * @param file_info 文件信息（用于命名空间解析）
     */
    void parse_inheritance(WsdlType& type, xmlNodePtr content_node, const std::string& ns_prefix, std::shared_ptr<FileInfo> file_info = nullptr);
    
    /**
     * @brief 解析import/include
     * @param file_info 文件信息
     * @param import_node import/include节点
     */
    void parse_import(std::shared_ptr<FileInfo> file_info, xmlNodePtr import_node);

    /**
     * @brief 解析wsdl:import节点（用于WSDL）
     * @param file_info 文件信息
     * @param import_node wsdl:import节点
     */
    void parse_wsdl_import(std::shared_ptr<FileInfo> file_info, xmlNodePtr import_node);

    /**
     * @brief 解析消息定义（WSDL特有）
     * @param file_info 文件信息
     * @param root WSDL根节点
     */
    void parse_messages(std::shared_ptr<FileInfo> file_info, xmlNodePtr root);
    
    /**
     * @brief 根据消息名查找对应的元素名
     * @param file_info 文件信息
     * @param message_name 消息名称（可能带命名空间前缀）
     * @return 对应的元素名，如果未找到返回空字符串
     */
    std::string find_element_by_message(std::shared_ptr<FileInfo> file_info, const std::string& message_name);
    
    /**
     * @brief 解析服务定义（WSDL特有）
     * @param file_info 文件信息
     * @param root WSDL根节点
     */
    void parse_services(std::shared_ptr<FileInfo> file_info, xmlNodePtr root);
    
    /**
     * @brief 解析PortType
     * @param file_info 文件信息（用于消息查找）
     * @param service 服务定义
     * @param port_type_node portType节点
     */
    void parse_port_type(std::shared_ptr<FileInfo> file_info, WsdlService& service, xmlNodePtr port_type_node);
    
    /**
     * @brief 解析Binding
     * @param service 服务定义
     * @param binding_node binding节点
     */
    void parse_binding(WsdlService& service, xmlNodePtr binding_node);
    
    /**
     * @brief 解析Service
     * @param service 服务定义
     * @param service_node service节点
     */
    void parse_service_node(WsdlService& service, xmlNodePtr service_node);
    
    /**
     * @brief 处理依赖关系
     * @param files 文件列表
     */
    void resolve_dependencies(std::vector<std::shared_ptr<FileInfo>>& files);
    
    /**
     * @brief 确定命名空间前缀和文件名
     * @param file_info 文件信息
     */
    void determine_namespace_info(std::shared_ptr<FileInfo> file_info);
    
    /**
     * @brief 获取节点属性
     * @param node XML节点
     * @param attr_name 属性名
     * @return 属性值
     */
    std::string get_node_attribute(xmlNodePtr node, const std::string& attr_name) const;
    
    /**
     * @brief 获取文档说明
     * @param node XML节点
     * @return 文档说明
     */
    std::string get_documentation(xmlNodePtr node) const;
    
    
    /**
     * @brief 根据命名空间URI查找对应的前缀
     * @param file_info 文件信息
     * @param namespace_uri 命名空间URI
     * @return 命名空间前缀，如果未找到返回空字符串
     */
    std::string find_namespace_prefix_by_uri(std::shared_ptr<FileInfo> file_info, const std::string& namespace_uri) const;
    
    /**
     * @brief 获取XML节点的命名空间URI
     * @param node XML节点
     * @return 命名空间URI
     */
    std::string get_node_namespace_uri(xmlNodePtr node) const;
    
    /**
     * @brief 是否为URL
     * @param path 路径字符串
     * @return 是否为URL
     */
    bool is_url(const std::string& path) const;
    
    /**
     * @brief 通过文件内容检测文件类型
     * @param file_path 文件路径
     * @return 检测到的文件类型 ("wsdl", "xsd", 或空字符串表示未知)
     */
    std::string detect_file_type_by_content(const std::string& file_path) const;
    
    /**
     * @brief 解析字段的命名空间和类型信息
     * @param field 要处理的字段
     * @param file_info 当前文件信息
     */
    void resolve_field_namespace_and_type(WsdlField& field, std::shared_ptr<FileInfo> file_info);
    
    /**
     * @brief 解析类型引用，返回完整的类型名（包含命名空间前缀）
     * @param type_ref 类型引用字符串
     * @param file_info 当前文件信息
     * @return 解析后的完整类型名
     */
    std::string resolve_type_reference(const std::string& type_ref, std::shared_ptr<FileInfo> file_info);

private:
    ParserConfig config_;                   // 解析器配置
    std::unique_ptr<Downloader> downloader_; // 文件下载器
    std::map<std::string, std::shared_ptr<FileInfo>> loaded_files_; // 已加载的文件
    std::map<std::string, std::string> global_namespaces_; // 全局命名空间映射
    std::set<std::string> processing_files_; // 正在处理的文件（防止循环依赖）
};

} // namespace wsdl_parser2