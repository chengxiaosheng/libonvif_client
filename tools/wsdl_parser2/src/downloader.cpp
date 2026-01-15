/**
 * @file downloader.cpp
 * @brief 文件下载器实现
 */

#include "../include/downloader.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <memory>
#include <cstdlib>
#include <sstream>

namespace wsdl_parser2 {

namespace {
    // 计算URL的哈希值作为缓存文件名
    std::string url_hash(const std::string& url) {
        std::hash<std::string> hasher;
        auto hash_val = hasher(url);
        
        // 将哈希值转换为十六进制字符串
        std::stringstream ss;
        ss << std::hex << hash_val;
        return ss.str();
    }
}

Downloader::Downloader(const std::string& cache_dir, std::chrono::seconds timeout)
    : cache_dir_(cache_dir), timeout_(timeout) {
    
    // 确保缓存目录存在
    std::filesystem::create_directories(cache_dir_);
}

DownloadResult Downloader::download(const std::string& url, 
                                   bool force_refresh,
                                   ProgressCallback progress_callback) {
    DownloadResult result;
    
    try {
        // 获取缓存路径
        std::string cache_path = get_cache_path(url);
        result.local_path = cache_path;
        
        // 检查缓存
        if (!force_refresh && std::filesystem::exists(cache_path)) {
            // 验证缓存文件是否确实对应这个URL（通过内容哈希或其他方式）
            // 这里简化处理：如果文件存在且大小>0，则认为是有效缓存
            auto file_size = std::filesystem::file_size(cache_path);
            if (file_size > 0) {
                result.success = true;
                result.downloaded_size = file_size;
                return result;
            }
        }
        
        // 执行下载
        if (download_to_file(url, cache_path, progress_callback)) {
            result.success = true;
            
            // 检查并修正文件扩展名
            std::string corrected_path = ensure_proper_extension(cache_path, url);
            result.local_path = corrected_path; // 更新返回的路径
            
            if (std::filesystem::exists(corrected_path)) {
                result.downloaded_size = std::filesystem::file_size(corrected_path);
            }
        } else {
            result.error_message = "下载失败";
        }
        
    } catch (const std::exception& e) {
        result.error_message = std::string("下载异常: ") + e.what();
    }
    
    return result;
}

std::string Downloader::get_cache_path(const std::string& url) const {
    return cache_dir_ + "/" + generate_cache_filename(url);
}

bool Downloader::has_cache(const std::string& url) const {
    return std::filesystem::exists(get_cache_path(url));
}


std::string Downloader::generate_cache_filename(const std::string& url) const {
    // 从URL提取文件名
    std::string original_filename;
    auto pos = url.find_last_of('/');
    if (pos != std::string::npos) {
        original_filename = url.substr(pos + 1);
    } else {
        original_filename = "downloaded_file";
    }
    
    // 清理文件名，移除查询参数
    auto query_pos = original_filename.find('?');
    if (query_pos != std::string::npos) {
        original_filename = original_filename.substr(0, query_pos);
    }
    
    // 提取扩展名
    std::string extension = ".xml"; // 默认扩展名
    auto ext_pos = original_filename.find_last_of('.');
    if (ext_pos != std::string::npos) {
        extension = original_filename.substr(ext_pos);
    } else {
        // 尝试从URL路径判断类型
        if (url.find(".wsdl") != std::string::npos) {
            extension = ".wsdl";
        } else if (url.find(".xsd") != std::string::npos) {
            extension = ".xsd";
        }
    }
    
    // 优先使用原始文件名，仅在需要时添加区分符
    std::string base_name;
    if (!original_filename.empty() && original_filename != "downloaded_file") {
        // 移除扩展名
        if (ext_pos != std::string::npos) {
            base_name = original_filename.substr(0, ext_pos);
        } else {
            base_name = original_filename;
        }
        
        // 限制长度
        if (base_name.length() > 50) {
            base_name = base_name.substr(0, 50);
        }
    } else {
        base_name = "downloaded_file";
    }
    
    // 仅在需要时添加版本区分符
    std::string distinguisher;
    
    // 如果URL包含版本信息，添加版本区分符
    if (url.find("/ver10/") != std::string::npos) {
        distinguisher = "v10";
    } else if (url.find("/ver20/") != std::string::npos) {
        distinguisher = "v20";
    }
    
    // 最终文件名：如果有版本区分符则使用，否则直接使用原始名
    std::string final_name;
    if (!distinguisher.empty()) {
        final_name = base_name + "_" + distinguisher + extension;
    } else {
        final_name = base_name + extension;
    }
    
    return final_name;
}

bool Downloader::download_to_file(const std::string& url, 
                                  const std::string& local_path,
                                  ProgressCallback progress_callback) {
    // 检测操作系统并选择合适的下载工具
    std::string command;
    
#ifdef _WIN32
    // Windows平台 - 使用PowerShell的Invoke-WebRequest
    command = "powershell -Command \"Invoke-WebRequest -Uri '" + url + 
              "' -OutFile '" + local_path + "' -TimeoutSec " + 
              std::to_string(timeout_.count()) + "\"";
#else
    // Unix-like平台 - 尝试curl，失败则用wget
    
    // 先检查curl是否可用
    int curl_check = std::system("which curl > /dev/null 2>&1");
    if (curl_check == 0) {
        // 使用curl下载
        command = "curl -L --max-time " + std::to_string(timeout_.count()) + 
                  " --output \"" + local_path + "\" \"" + url + "\"";
    } else {
        // 检查wget是否可用
        int wget_check = std::system("which wget > /dev/null 2>&1");
        if (wget_check == 0) {
            // 使用wget下载
            command = "wget --timeout=" + std::to_string(timeout_.count()) + 
                      " -O \"" + local_path + "\" \"" + url + "\"";
        } else {
            std::cerr << "错误: 系统中既没有curl也没有wget工具" << std::endl;
            std::cerr << "请安装curl或wget: " << std::endl;
            std::cerr << "  Ubuntu/Debian: sudo apt-get install curl" << std::endl;
            std::cerr << "  CentOS/RHEL: sudo yum install curl" << std::endl;
            std::cerr << "  macOS: curl已预装 或 brew install wget" << std::endl;
            return false;
        }
    }
#endif

    std::cout << "下载: " << url << " -> " << local_path << std::endl;
    std::cout << "执行命令: " << command << std::endl;
    
    // 执行下载命令
    int result = std::system(command.c_str());
    
    if (result == 0) {
        // 检查文件是否成功创建
        if (std::filesystem::exists(local_path)) {
            auto file_size = std::filesystem::file_size(local_path);
            if (file_size > 0) {
                // 检查是否需要添加.xsd扩展名
                std::string corrected_path = ensure_proper_extension(local_path, url);
                std::cout << "下载成功: " << corrected_path << " (" << file_size << " 字节)" << std::endl;
                return true;
            } else {
                std::cerr << "Download failed: file size is 0" << std::endl;
                std::filesystem::remove(local_path);
                return false;
            }
        } else {
            std::cerr << "Download failed: file not created" << std::endl;
            return false;
        }
    } else {
        std::cerr << "Download failed: command returned code " << result << std::endl;
        
        // 给出具体的错误提示
        if (result == 127) {
            std::cerr << "Hint: download tool not found, please ensure curl or wget is installed" << std::endl;
        } else if (result == 7) {
            std::cerr << "Hint: cannot connect to server, please check network connection and URL" << std::endl;
        } else if (result == 28) {
            std::cerr << "Hint: download timeout, please check network connection or increase timeout" << std::endl;
        }
        
        // 清理可能存在的部分文件
        if (std::filesystem::exists(local_path)) {
            std::filesystem::remove(local_path);
        }
        
        return false;
    }
}

std::string Downloader::ensure_proper_extension(const std::string& file_path, const std::string& original_url) {
    std::filesystem::path path(file_path);
    std::string extension = path.extension().string();
    
    // 如果已经有扩展名，不需要检查
    if (!extension.empty()) {
        return file_path;
    }
    
    // 检查文件内容以确定类型
    std::ifstream file(file_path);
    if (!file.is_open()) {
        return file_path;
    }
    
    // 读取文件前几行来检查内容
    std::string line;
    std::string content;
    int lines_read = 0;
    const int max_lines = 20; // 只读取前20行来判断
    
    while (std::getline(file, line) && lines_read < max_lines) {
        content += line + "\n";
        lines_read++;
    }
    file.close();
    
    // 检查是否为XML Schema (XSD)文件
    bool is_xsd = false;
    
    // 检查XML声明和schema根元素
    if (content.find("<?xml") != std::string::npos) {
        // 检查是否包含schema相关的命名空间或元素
        if (content.find("http://www.w3.org/2001/XMLSchema") != std::string::npos ||
            content.find("<xs:schema") != std::string::npos ||
            content.find("<xsd:schema") != std::string::npos ||
            content.find("<schema") != std::string::npos) {
            is_xsd = true;
        }
        
        // 特殊检查：SOAP envelope schema
        if (content.find("http://www.w3.org/2003/05/soap-envelope") != std::string::npos ||
            content.find("soap-envelope") != std::string::npos) {
            is_xsd = true;
        }
        
        // 特殊检查：XML MIME schema
        if (content.find("http://www.w3.org/2005/05/xmlmime") != std::string::npos ||
            content.find("xmlmime") != std::string::npos) {
            is_xsd = true;
        }
    }
    
    // 如果检测到是XSD文件，添加.xsd扩展名
    if (is_xsd) {
        std::string new_path = file_path + ".xsd";
        
        try {
            std::filesystem::rename(file_path, new_path);
            return new_path;
        } catch (const std::exception& e) {
            std::cerr << "重命名文件失败: " << e.what() << std::endl;
        }
    }
    
    return file_path;
}

} // namespace wsdl_parser2