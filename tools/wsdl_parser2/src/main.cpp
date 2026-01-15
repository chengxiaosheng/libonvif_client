/**
 * @file main.cpp
 * @brief WSDL解析器2.0主程序
 */

#include "../include/config.h"
#include "../include/wsdl_parser.h"
#include "../include/type_generator.h"
#include "../include/client_generator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#include <locale.h>
#endif

using namespace wsdl_parser2;

/**
 * @brief 简化的命令行选项
 */
struct AppOptions {
    std::vector<std::string> input_files;      // Input WSDL/XSD files
    std::string config_file = "./config.json"; // Config file
    std::string cache_dir = "./cache";         // Cache directory
    bool generate_types = true;                // Generate type definitions
    bool generate_clients = true;              // Generate client code
    bool verbose = false;                      // Verbose output
    bool ignore_missing_deps = false;          // Ignore missing dependencies
    bool help = false;                         // Show help
};

void print_help(const char* program_name) {
    std::cout << R"(
WSDL解析器 2.0 - 简洁高效的ONVIF代码生成工具

用法:
    )" << program_name << R"( [选项] <wsdl_file>...

描述:
    从WSDL/XSD文件生成C++类型定义和服务客户端代码
    支持本地文件和网络URL，自动处理依赖关系

参数:
    <wsdl_file>...          要解析的WSDL/XSD文件（支持多个）

选项:
    -h, --help              显示此帮助信息
    -v, --verbose           启用详细输出
    -o, --output <dir>      输出目录 (默认: ./generated)
    -c, --config <file>     配置文件路径 (默认: ./wsdl_parser_config.json)
    --cache-dir <dir>       缓存目录 (默认: ./cache)
    --types-only            仅生成类型定义
    --clients-only          仅生成客户端代码
    --ignore-missing-deps   忽略缺失的依赖文件

示例:
    # 基本用法
    )" << program_name << R"( devicemgmt.wsdl

    # 生成到指定目录
    )" << program_name << R"( -o ./include devicemgmt.wsdl ptz.wsdl

    # 使用自定义配置
    )" << program_name << R"( -c my_config.json devicemgmt.wsdl

    # 网络文件
    )" << program_name << R"( https://www.onvif.org/ver10/device/wsdl/devicemgmt.wsdl

    # 仅生成类型定义
    )" << program_name << R"( --types-only common.xsd

配置文件格式:
    {
        "output_dir": "./generated",
        "cache_dir": "./cache",
        "generate_types": true,
        "generate_clients": true,
        "verbose": false,
        "ignore_missing_deps": false,
        "namespaces": [
            {
                "ns_url": "http://www.onvif.org/ver10/schema",
                "ns": "tt",
                "name": "common"
            }
        ]
    }

注意:
    • 生成的代码依赖 libonvif_client 框架
    • 支持ONVIF标准的所有WSDL/XSD文件
    • 自动下载和缓存网络依赖文件
    • 使用配置文件可以自定义命名空间映射
)";
}

bool parse_arguments(int argc, char* argv[], AppOptions& options) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            options.help = true;
            return true;
        }
        else if (arg == "-v" || arg == "--verbose") {
            options.verbose = true;
        }
        else if (arg == "-c" || arg == "--config") {
            if (i + 1 >= argc) {
                std::cerr << "错误: " << arg << " 需要指定配置文件参数" << std::endl;
                return false;
            }
            options.config_file = argv[++i];
        }
        else if (arg == "--cache-dir") {
            if (i + 1 >= argc) {
                std::cerr << "错误: --cache-dir 需要指定目录参数" << std::endl;
                return false;
            }
            options.cache_dir = argv[++i];
        }
        else if (arg == "--types-only") {
            options.generate_types = true;
            options.generate_clients = false;
        }
        else if (arg == "--clients-only") {
            options.generate_types = false;
            options.generate_clients = true;
        }
        else if (arg == "--ignore-missing-deps") {
            options.ignore_missing_deps = true;
        }
        else if (!arg.empty() && arg[0] == '-') {
            std::cerr << "错误: 未知选项 " << arg << std::endl;
            return false;
        }
        else {
            // 输入文件
            options.input_files.push_back(arg);
        }
    }
    
    return true;
}

int main(int argc, char* argv[]) {
#ifdef _WIN32
    // 设置控制台输出编码为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置C运行时库的locale为UTF-8
    setlocale(LC_ALL, ".UTF8");
#endif

    AppOptions options;
    
    // 解析命令行参数
    if (!parse_arguments(argc, argv, options)) {
        return 1;
    }
    
    // 显示帮助
    if (options.help || options.input_files.empty()) {
        print_help(argv[0]);
        return options.help ? 0 : 1;
    }
    
    auto start_time = std::chrono::high_resolution_clock::now();
    
    try {
        // 加载配置
        ParserConfig & config = load_from_file(options.config_file);

        // 应用命令行选项覆盖配置
        config.cache_dir = options.cache_dir;
        config.generate_types = options.generate_types;
        config.generate_clients = options.generate_clients;
        config.verbose = options.verbose;
        config.ignore_missing_deps = options.ignore_missing_deps;
        
        // 创建输出目录
        std::filesystem::create_directories(config.cache_dir);
        
        // 显示配置信息
        std::cout << "🚀 WSDL解析器 启动" << std::endl;
        std::cout << "📁 输出目录: " << std::endl ;
        std::cout << "    - " <<config.output_types_header_dir << std::endl;
        std::cout << "    - " <<config.output_client_header_dir << std::endl;
        std::cout << "    - " <<config.output_client_source_dir << std::endl;
        std::cout << "📁 缓存目录: " << config.cache_dir << std::endl;
        std::cout << "⚙️ 生成类型: " << (config.generate_types ? "是" : "否") << std::endl;
        std::cout << "⚙️ 生成客户端: " << (config.generate_clients ? "是" : "否") << std::endl;
        std::cout << "📄 输入文件数量: " << options.input_files.size() << std::endl;
        
        if (config.verbose) {
            std::cout << "📋 输入文件列表:" << std::endl;
            for (const auto& file : options.input_files) {
                std::cout << "  - " << file << std::endl;
            }
            std::cout << "🔧 Schema配置数量: " << config.schema_configs.size() << std::endl;
        }
        
        // 创建解析器并解析文件
        std::cout << "\n🔍 开始解析文件..." << std::endl;
        WsdlParser parser(config);
        auto parse_result = parser.parse_multiple(options.input_files);
        
        if (!parse_result.success) {
            std::cerr << "❌ 解析失败: " << parse_result.error_message << std::endl;
            return 1;
        }
        
        // 显示解析结果
        auto all_types = parse_result.get_all_types();
        auto all_services = parse_result.get_all_services();
        
        std::cout << "✅ 解析完成!" << std::endl;
        std::cout << "📊 解析统计:" << std::endl;
        std::cout << "  - 文件数量: " << parse_result.files.size() << std::endl;
        std::cout << "  - 类型数量: " << all_types.size() << std::endl;
        std::cout << "  - 服务数量: " << all_services.size() << std::endl;
        
        if (!parse_result.warnings.empty()) {
            std::cout << "⚠️ 警告信息:" << std::endl;
            for (const auto& warning : parse_result.warnings) {
                std::cout << "  - " << warning << std::endl;
            }
        }
        
        // 生成代码
        int generated_files = 0;
        
        if (config.generate_types && !all_types.empty()) {
            std::cout << "\n🏗️ 生成类型定义..." << std::endl;

            // 在生成代码前，统一设置所有类型的字段父级引用
            // 这样可以避免 vector 扩容导致的指针失效问题
            std::cout << "🔗 设置字段父级引用..." << std::endl;
            for (auto& file_info : parse_result.files) {
                for (auto& type : file_info->types) {
                    type.setup_field_parent_references();
                }
            }

            GeneratorOptions gen_options;
            TypeGenerator type_generator(config, gen_options);

            int type_files = type_generator.generate_all_type_files(
                parse_result.files
            );

            generated_files += type_files;
            std::cout << "✅ 生成了 " << type_files << " 个类型文件" << std::endl;

            // 生成全局命名空间映射文件
            std::cout << "🔗 生成命名空间映射..." << std::endl;

            // 生成 header-only 的 namespaces.h
            std::string ns_header = type_generator.generate_namespace_mappings_header(parse_result.files);

            std::filesystem::path ns_header_path = std::filesystem::path(config.output_client_header_dir) / "namespaces.h";
            std::filesystem::create_directories(ns_header_path.parent_path());

            std::ofstream ns_h_file(ns_header_path);
            if (ns_h_file) {
                ns_h_file << ns_header;
                ns_h_file.close();
                std::cout << "✅ 生成命名空间映射头文件: " << ns_header_path.string() << std::endl;
                generated_files++;
            } else {
                std::cerr << "⚠️ 无法写入命名空间映射头文件: " << ns_header_path.string() << std::endl;
            }

            // 注意：不再生成 onvif_namespaces.cpp，使用 header-only 的 namespaces.h
        }
        
        if (config.generate_clients && !all_services.empty()) {
            std::cout << "\n🏗️ 生成服务客户端..." << std::endl;
            
            ClientGenerator client_generator(config);
            
            int client_files = client_generator.generate_all_clients(
                parse_result.files
            );
            
            generated_files += client_files;
            std::cout << "✅ 生成了 " << client_files << " 个客户端" << std::endl;
        }
        
        // 计算耗时
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        
        std::cout << "\n🎉 代码生成完成!" << std::endl;
        std::cout << "📄 生成文件: " << generated_files << " 个" << std::endl;
        std::cout << "⏱️ 总耗时: " << duration.count() << " ms" << std::endl;
        
        if (generated_files > 0) {
            std::cout << "\n💡 使用提示:" << std::endl;
            std::cout << "1. 将生成的头文件添加到你的项目中" << std::endl;
            std::cout << "2. 链接 libonvif_client 库" << std::endl;
            std::cout << "3. 参考生成的客户端代码使用服务" << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "❌ 程序异常: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}