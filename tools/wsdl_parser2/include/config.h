/**
 * @file config.h
 * @brief WSDL解析器配置管理
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <optional>
#include <chrono>

namespace wsdl_parser2 {

/**
 * @brief 统一的Schema配置 - 每个文件都分离生成
 */
struct SchemaConfig {
    std::string comment;                       // 注释说明
    std::string ns_url;                        // 命名空间URL（唯一标识）
    std::string ns_prefix;                     // 命名空间前缀
    std::string output_name;                   // 输出文件名前缀
    std::vector<std::string> source_files;     // 源文件列表（可选，用于明确指定）
    int priority = 5;                          // 优先级（用于排序）
    std::vector<std::string> dependencies;     // 依赖的其他类型文件
    std::string client_class_name;             // 客户端类名（可选，如果不指定则使用第一个portType的名字）
};

/**
 * @brief 解析器配置
 */
struct ParserConfig {
    std::vector<SchemaConfig> schema_configs;  // 统一的Schema配置
    bool generate_types = true;                // 生成类型定义
    bool generate_clients = true;              // 生成客户端代码
    bool verbose = false;                      // 详细输出
    bool ignore_missing_deps = false;          // 忽略缺失依赖
    bool detect_duplicates = true;             // 检测重复
    bool smart_merge = true;                   // 智能合并
    std::chrono::seconds download_timeout{30}; // 下载超时时间
    std::string cache_dir = "./cache";         // 缓存目录

    std::string output_types_header_dir = "./generated/include/types";
    std::string output_client_header_dir = "./generated/include/client"; // 客户端代码输出目录
    std::string output_client_source_dir = "./generated/src/client"; // 客户端代码输出目录
    std::string output_client_include_prefix_path = "<libonvif_client/client>"; // 客户端源文件包含头文件时的前缀路径

    std::string base_client_path = "<libonvif_client/client/service_client_base.h>";
    std::string base_types_path = "<libonvif_client/base_types.h>"; // 基础类型头文件路径
    std::string result_type_path = "<libonvif_client/types/result.h>"; // 结果类型头文件路径
    std::string xml_convert_path = "<libonvif_client/xml_convert.h>"; // XML转换头文件路径

    std::string include_types_dir = "<libonvif_client/types>"; // 生成的类型头文件目录
    std::string include_clients_dir = "<libonvif_client/client>"; // 生成的客户端头文件目录

    std::string export_directive = ""; // 导出指令, 一般应该是宏定义
    std::string client_namespace = "xml_convert"; // 客户端代码命名空间
};

ParserConfig& config();
/**
 * 从文件中加载配置
 * @param config_file
 */
ParserConfig& load_from_file(const std::string &config_file);

void save_to_file(const std::string &config_file);

std::optional<SchemaConfig> find_schema_config(const ParserConfig& config, const std::string& ns_url);

std::string generate_name_from_url(const std::string& ns_url);

std::string generate_types_include_path(const std::string &header);

std::string generate_clients_include_path(const std::string &header);

std::string generate_client_source_include_path(const std::string &header_name);

} // namespace wsdl_parser2