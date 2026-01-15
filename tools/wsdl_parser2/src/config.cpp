/**
 * @file config.cpp
 * @brief 配置管理器实现
 */

#include "config.h"
#include <atomic>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <mutex>
#include <regex>
#include <sstream>



namespace wsdl_parser2 {

    ParserConfig create_default_config() {
        ParserConfig config;

        // 添加默认的Schema配置
        config.schema_configs = {
            // {"", "http://www.onvif.org/ver10/schema", "tt", "common_types", {}, 10, {}},
            // {"", "http://www.onvif.org/ver10/device/wsdl", "tds", "device_v10", {}, 9, {}},
            // {"", "http://www.onvif.org/ver10/media/wsdl", "trt", "media_v10", {}, 6, {}},
            // {"", "http://www.onvif.org/ver10/events/wsdl", "tev", "events_v10", {}, 6, {}},
            // {"", "http://www.onvif.org/ver20/ptz/wsdl", "tptz", "ptz_v20", {}, 6, {}},
            // {"", "http://www.onvif.org/ver20/imaging/wsdl", "timg", "imaging_v20", {}, 6, {}},
            // {"", "http://www.w3.org/2005/08/addressing", "wsa", "wsa_types", {}, 1, {}},
            // {"", "http://docs.oasis-open.org/wsn/b-2", "wsnt", "wsnt_types", {}, 2, {}}
        };
        return config;
    }

    ParserConfig &config() {
        static ParserConfig config_;
        static std::once_flag init_flag;
        std::call_once(init_flag, []() { config_ = create_default_config(); });
        return config_;
    }

    void make_include_str(std::string & path) {
        if (path.empty()) return;
        if (path[0] != '"' && path[0] != '<') {
            path = "\"" + path + "\"";
        }
    }


    ParserConfig &load_from_file(const std::string &config_file) {

        static std::atomic_bool loaded(false);
        // 禁止重复加载配置文件
        if (loaded.exchange(true)) {
            std::cerr << "已加载过文件: " << config_file << std::endl;
            return config();
        }
        if (!std::filesystem::exists(config_file)) {
            return config();
        }

        std::ifstream file(config_file);
        if (!file.is_open()) {
            std::cerr << "Unable to open config file: " << config_file << std::endl;
            return config();
        }
        Json::Value root;
        file >> root;
        if (file.fail()) {
            std::cerr << "Failed to parse config file: " << config_file << std::endl;
            return config();
        }
        file.close();

        config().cache_dir = root.get("cache_dir", config().cache_dir).asString();
        config().generate_types = root.get("generate_types", config().generate_types).asBool();
        config().generate_clients = root.get("generate_clients", config().generate_clients).asBool();
        config().verbose = root.get("verbose", config().verbose).asBool();
        config().ignore_missing_deps = root.get("ignore_missing_deps", config().ignore_missing_deps).asBool();
        config().detect_duplicates = root.get("detect_duplicates", config().detect_duplicates).asBool();
        config().smart_merge = root.get("smart_merge", config().smart_merge).asBool();
        config().download_timeout =
                std::chrono::seconds(root.get("download_timeout", config().download_timeout.count()).asInt());
        config().base_client_path = root.get("base_client_path", config().base_client_path).asString();
        make_include_str(config().base_client_path);

        config().base_types_path = root.get("base_types_path", config().base_types_path).asString();
        make_include_str(config().base_types_path);

        config().result_type_path = root.get("result_type_path", config().result_type_path).asString();
        make_include_str(config().result_type_path);

        config().xml_convert_path = root.get("xml_convert_path", config().xml_convert_path).asString();
        make_include_str(config().xml_convert_path);

        config().output_types_header_dir = root.get("output_types_header_dir", config().output_types_header_dir).asString();
        config().output_client_header_dir = root.get("output_client_header_dir", config().output_client_header_dir).asString();
        config().output_client_source_dir = root.get("output_client_source_dir", config().output_client_source_dir).asString();
        config().output_client_include_prefix_path = root.get("output_client_include_prefix_path", config().output_client_include_prefix_path).asString();

        std::filesystem::create_directories(config().output_types_header_dir);
        std::filesystem::create_directories(config().output_client_header_dir);
        std::filesystem::create_directories(config().output_client_source_dir);

        config().export_directive = root.get("export_directive", config().export_directive).asString();
        config().client_namespace = root.get("client_namespace", config().client_namespace).asString();
        config().include_clients_dir = root.get("include_clients_dir", config().include_clients_dir).asString();
        config().include_types_dir = root.get("include_types_dir", config().include_types_dir).asString();

        // 解析统一的 schema_configs 配置
        for (auto &it: root.get("schema_configs", Json::arrayValue)) {
            SchemaConfig schema_config{};
            schema_config.comment = it.get("comment", "").asString();
            schema_config.ns_url = it.get("ns_url", "").asString();
            schema_config.ns_prefix = it.get("ns_prefix", "").asString();
            schema_config.output_name = it.get("output_name", "").asString();
            schema_config.priority = it.get("priority", 5).asInt();
            schema_config.client_class_name = it.get("client_class_name", "").asString();

            // 解析源文件列表
            for (auto &file : it.get("source_files", Json::arrayValue)) {
                schema_config.source_files.push_back(file.asString());
            }

            // 解析依赖列表
            for (auto &dep : it.get("dependencies", Json::arrayValue)) {
                schema_config.dependencies.push_back(dep.asString());
            }

            config().schema_configs.emplace_back(std::move(schema_config));
        }
        
        // config().from_file = true;
        return config();
    }

    void save_to_file(const std::string &config_file) {
        Json::Value json;
        json["cache_dir"] = config().cache_dir;
        json["cache_dir"].setComment(std::string("// 缓存目录"), Json::CommentPlacement::commentBefore);
        json["generate_types"] = config().generate_types;
        json["generate_types"].setComment(std::string("// 是否生成类型"), Json::CommentPlacement::commentBefore);
        json["generate_clients"] = config().generate_clients;
        json["generate_clients"].setComment(std::string("// 是否生成客户端"), Json::CommentPlacement::commentBefore);
        json["verbose"] = config().verbose;
        json["verbose"].setComment(std::string("// 是否输出详细信息"), Json::CommentPlacement::commentBefore);
        json["ignore_missing_deps"] = config().ignore_missing_deps;
        json["ignore_missing_deps"].setComment(std::string("// 是否忽略缺失的依赖"),
                                               Json::CommentPlacement::commentBefore);
        json["detect_duplicates"] = config().detect_duplicates;
        json["detect_duplicates"].setComment(std::string("// 是否检测重复的类型"),
                                             Json::CommentPlacement::commentBefore);
        json["smart_merge"] = config().smart_merge;
        json["smart_merge"].setComment(std::string("// 是否智能合并类型"), Json::CommentPlacement::commentBefore);
        json["download_timeout"] = config().download_timeout.count();
        json["download_timeout"].setComment(std::string("// 下载超时时间"), Json::CommentPlacement::commentBefore);
        json["base_client_path"] = config().base_client_path;
        json["base_client_path"].setComment(std::string("// 基础客户端路径"), Json::CommentPlacement::commentBefore);
        json["base_types_path"] = config().base_types_path;
        json["base_types_path"].setComment(std::string("// 基础类型路径"), Json::CommentPlacement::commentBefore);
        json["result_type_path"] = config().result_type_path;
        json["result_type_path"].setComment(std::string("// 结果类型路径"), Json::CommentPlacement::commentBefore);
        json["export_directive"] = config().export_directive;
        json["export_directive"].setComment(std::string("// 导出指令"), Json::CommentPlacement::commentBefore);
        json["export_directive"] = config().export_directive;
        json["export_directive"].setComment(std::string("// 导出指令"), Json::CommentPlacement::commentBefore);
        json["client_namespace"] = config().client_namespace;
        json["client_namespace"].setComment(std::string("// 客户端命名空间"), Json::CommentPlacement::commentBefore);
        
        // 保存 schema_configs 配置
        Json::Value schema_configs_json(Json::arrayValue);
        for (const auto &schema_config : config().schema_configs) {
            Json::Value config_json;
            if (!schema_config.comment.empty()) {
                config_json["comment"] = schema_config.comment;
            }
            config_json["ns_url"] = schema_config.ns_url;
            config_json["ns_prefix"] = schema_config.ns_prefix;
            config_json["output_name"] = schema_config.output_name;
            config_json["priority"] = schema_config.priority;

            if (!schema_config.client_class_name.empty()) {
                config_json["client_class_name"] = schema_config.client_class_name;
            }

            if (!schema_config.source_files.empty()) {
                Json::Value source_files_json(Json::arrayValue);
                for (const auto &file : schema_config.source_files) {
                    source_files_json.append(file);
                }
                config_json["source_files"] = source_files_json;
            }

            if (!schema_config.dependencies.empty()) {
                Json::Value deps_json(Json::arrayValue);
                for (const auto &dep : schema_config.dependencies) {
                    deps_json.append(dep);
                }
                config_json["dependencies"] = deps_json;
            }

            schema_configs_json.append(config_json);
        }
        json["schema_configs"] = schema_configs_json;
        std::ofstream file(config_file);
        if (!file.is_open()) {
            std::cerr << "Unable to create config file: " << config_file << std::endl;
            return;
        }
        file << json;
        file.close();
    }

    std::optional<SchemaConfig> find_schema_config(const ParserConfig &config, const std::string &ns_url) {
        for (const auto &schema_config : config.schema_configs) {
            if (schema_config.ns_url == ns_url) {
                return schema_config;
            }
        }
        return std::nullopt;
    }

    std::string generate_name_from_url(const std::string &ns_url) {
        // 从URL中提取有意义的部分作为名称
        std::string name;

        // 移除协议部分
        std::string url = ns_url;
        auto pos = url.find("://");
        if (pos != std::string::npos) {
            url = url.substr(pos + 3);
        }

        // 移除域名部分，保留路径
        pos = url.find('/');
        if (pos != std::string::npos) {
            url = url.substr(pos + 1);
        }

        // 提取最后一个有意义的部分
        std::vector<std::string> parts;
        std::stringstream ss(url);
        std::string part;

        while (std::getline(ss, part, '/')) {
            if (!part.empty() && part != "wsdl" && part != "schema") {
                parts.push_back(part);
            }
        }

        if (!parts.empty()) {
            name = parts.back();

            // 移除版本号
            std::regex version_regex(R"(ver\d+)");
            name = std::regex_replace(name, version_regex, "");

            // 清理特殊字符
            std::regex special_chars_regex(R"([^a-zA-Z0-9])");
            name = std::regex_replace(name, special_chars_regex, "_");

            // 移除前后的空白字符和下划线
            // 移除前导空白字符
            auto start = name.find_first_not_of(" \t\n\r_");
            if (start == std::string::npos) {
                name = "";
            } else {
                // 移除尾随空白字符
                auto end = name.find_last_not_of(" \t\n\r_");
                name = name.substr(start, end - start + 1);
            }
        }

        // 如果无法提取有效名称，使用默认值
        if (name.empty()) {
            name = "unknown";
        }

        return name;
    }



    std::string merge_path(const std::string &header, const std::string &prefix) {
        if (prefix.empty()) {
            return header;
        }
        std::string path(prefix);
        if (path.back() == '>' || path.back() == '"') path.pop_back();
        if (path.back() != '/') {
            path += '/';
        }
        if (path[0] == '<') return path + header + '>';
        return path + header + "\"";
    }
    std::string generate_types_include_path(const std::string &header) {
        return merge_path(header, config().include_types_dir);
    }

    std::string generate_clients_include_path(const std::string &header) {
        return merge_path(header, config().include_clients_dir);
    }
    std::string generate_client_source_include_path(const std::string &header_name) {
        return merge_path(header_name, config().output_client_include_prefix_path);
    }
} // namespace wsdl_parser2
