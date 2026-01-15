/**
 * @file downloader.h
 * @brief 文件下载器
 */

#pragma once

#include <string>
#include <chrono>
#include <optional>
#include <functional>

namespace wsdl_parser2 {

/**
 * @brief 下载结果
 */
struct DownloadResult {
    bool success = false;                   // 是否成功
    std::string error_message;              // 错误信息
    std::string local_path;                 // 本地文件路径
    size_t downloaded_size = 0;             // 下载的文件大小
};

/**
 * @brief 下载进度回调
 * @param downloaded 已下载字节数
 * @param total 总字节数（可能为0表示未知）
 */
using ProgressCallback = std::function<void(size_t downloaded, size_t total)>;

/**
 * @brief 文件下载器
 */
class Downloader {
public:
    /**
     * @brief 构造函数
     * @param cache_dir 缓存目录
     * @param timeout 下载超时时间
     */
    Downloader(const std::string& cache_dir, std::chrono::seconds timeout = std::chrono::seconds(30));
    
    /**
     * @brief 下载文件
     * @param url 文件URL
     * @param force_refresh 是否强制刷新（忽略缓存）
     * @param progress_callback 进度回调（可选）
     * @return 下载结果
     */
    DownloadResult download(const std::string& url, 
                           bool force_refresh = false,
                           ProgressCallback progress_callback = nullptr);
    
    /**
     * @brief 获取缓存文件路径
     * @param url 文件URL
     * @return 缓存文件路径
     */
    std::string get_cache_path(const std::string& url) const;
    
    /**
     * @brief 检查缓存是否存在
     * @param url 文件URL
     * @return 是否存在缓存
     */
    bool has_cache(const std::string& url) const;
    

private:
    /**
     * @brief 从URL生成缓存文件名
     * @param url 文件URL
     * @return 缓存文件名
     */
    std::string generate_cache_filename(const std::string& url) const;
    
    /**
     * @brief 执行实际下载
     * @param url 文件URL
     * @param local_path 本地保存路径
     * @param progress_callback 进度回调
     * @return 是否成功
     */
    bool download_to_file(const std::string& url, 
                         const std::string& local_path,
                         ProgressCallback progress_callback);
    
    /**
     * @brief 检查文件内容并确保正确的扩展名
     * @param file_path 文件路径
     * @param original_url 原始URL
     * @return 正确的文件路径
     */
    std::string ensure_proper_extension(const std::string& file_path, const std::string& original_url);

private:
    std::string cache_dir_;                 // 缓存目录
    std::chrono::seconds timeout_;          // 下载超时时间
};

} // namespace wsdl_parser2