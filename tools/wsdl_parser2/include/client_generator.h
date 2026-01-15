/**
 * @file client_generator.h
 * @brief 服务客户端代码生成器
 */

#pragma once

#include "file_info.h"
#include "config.h"
#include "type_generator.h"
#include <string>
#include <vector>

namespace wsdl_parser2 {

/**
 * @brief 客户端代码生成器
 */
class ClientGenerator {
public:
    /**
     * @brief 构造函数
     * @param config 解析器配置
     */
    explicit ClientGenerator(const ParserConfig& config);
    
    /**
     * @brief 生成单个服务的客户端代码
     * @param service 服务定义
     * @param header_file 头文件路径
     * @param source_file 源文件路径
     * @return 是否成功
     */
    bool generate_service_client(
        const WsdlService& service,
        const std::string& header_file,
        const std::string& source_file) const;
    
    /**
     * @brief 生成所有服务客户端
     * @param files 所有文件信息
     * @param header_dir 头文件目录
     * @param source_dir 源文件目录
     * @return 生成的文件数量
     */
    int generate_all_clients(
        const std::vector<std::shared_ptr<FileInfo>>& files) const;

private:
    /**
     * @brief 生成客户端头文件
     * @param service 服务定义
     * @return 头文件代码
     */
    std::string generate_client_header(const WsdlService& service) const;
    
    /**
     * @brief 生成客户端源文件
     * @param service 服务定义
     * @param header_filename 头文件名
     * @return 源文件代码
     */
    std::string generate_client_source(const WsdlService& service, 
                                      const std::string& header_filename) const;
    
    /**
     * @brief 生成操作方法声明
     * @param operation 操作定义
     * @return 方法声明代码
     */
    std::string generate_operation_declaration(const WsdlOperation& operation) const;

    /**
     * @brief 生成操作方法实现（用于 .cpp 文件）
     * @param service 服务定义
     * @param operation 操作定义
     * @return 方法实现代码
     */
    std::string generate_operation_implementation(
        const WsdlService& service,
        const WsdlOperation& operation) const;

    /**
     * @brief 生成操作方法内联实现（用于 header-only 模式）
     * @param service 服务定义
     * @param operation 操作定义
     * @return 方法实现代码
     */
    std::string generate_operation_inline_implementation(
        const WsdlService& service,
        const WsdlOperation& operation) const;
    
    /**
     * @brief 获取客户端类名
     * @param service 服务定义
     * @return 客户端类名
     */
    std::string get_client_class_name(const WsdlService& service) const;
    
    /**
     * @brief 映射消息类型到C++类型
     * @param message_name 消息名称
     * @return C++类型名
     */
    std::string map_message_to_cpp_type(const std::string& message_name) const;

    /**
     * @brief 生成服务自动注册代码
     * @param service 服务定义
     * @param class_name 客户端类名
     * @return 注册代码
     */
    std::string generate_service_registration(
        const WsdlService& service,
        const std::string& class_name) const;

    /**
     * @brief 从服务中提取命名空间前缀作为友好名称
     * @param service 服务定义
     * @return 命名空间前缀（如 "trt", "tds", "tptz"）转为友好名称（如 "Media", "Device", "PTZ"）
     */
    std::string extract_namespace_prefix(const WsdlService& service) const;

private:
    ParserConfig config_;                   // 解析器配置
    TypeGenerator type_generator_;          // 类型生成器（用于统一的头文件命名）
};

} // namespace wsdl_parser2