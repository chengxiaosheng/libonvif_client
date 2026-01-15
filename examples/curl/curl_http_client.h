/**
 * @file curl_http_client.h
 * @brief 基于libcurl的HTTP客户端实现
 * @note 实现IHttpClient接口，使用libcurl进行HTTP请求
 */

#pragma once

#include <libonvif_client/core/http_client.h>
#include <curl/curl.h>
#include <memory>
#include <string>
#include <map>
#include <mutex>

namespace libonvif_client {

/**
 * @brief 基于libcurl的HTTP客户端实现
 *
 * 此类使用libcurl实现IHttpClient接口，
 * 提供完整的异步HTTP请求能力，包括：
 * - 异步非阻塞请求（使用线程池模拟）
 * - 超时控制
 * - HTTP基本认证
 * - SSL/TLS支持
 * - 自动错误处理
 */
class CurlHttpClient : public IHttpClient {
public:
    /**
     * @brief 构造函数
     * @param use_ssl 是否使用SSL/TLS（默认true）
     * @param thread_pool_size 线程池大小（默认4）
     */
    explicit CurlHttpClient(bool use_ssl = true, size_t thread_pool_size = 4);

    /**
     * @brief 析构函数
     */
    ~CurlHttpClient() override;

    /**
     * @brief 执行异步HTTP请求
     * @param request HTTP请求结构
     * @param callback 完成回调函数
     */
    void request_async(Request request, Callback callback) override;

    /**
     * @brief 设置是否验证SSL证书
     * @param verify true表示验证证书，false表示不验证
     * @note ONVIF设备常使用自签名证书，建议设置为false
     */
    void set_ssl_verify(bool verify);

    /**
     * @brief 设置代理服务器
     * @param proxy 代理地址，格式：http://proxy.example.com:8080
     */
    void set_proxy(const std::string& proxy);

    /**
     * @brief 设置连接超时时间
     * @param timeout_secs 连接超时时间（秒）
     */
    void set_connect_timeout(long timeout_secs);

private:
    bool use_ssl_;                              ///< 是否使用SSL
    bool ssl_verify_;                           ///< 是否验证SSL证书
    size_t thread_pool_size_;                   ///< 线程池大小
    std::string proxy_;                         ///< 代理服务器地址
    long connect_timeout_;                      ///< 连接超时时间
    std::mutex curl_mutex_;                     ///< CURL全局初始化锁

    /**
     * @brief 初始化CURL（线程安全）
     */
    void init_curl();

    /**
     * @brief 清理CURL（线程安全）
     */
    void cleanup_curl();

    /**
     * @brief 执行HTTP请求（在后台线程中运行）
     * @param request HTTP请求
     * @param callback 回调函数
     */
    void perform_request(const Request& request, Callback callback);

    /**
     * @brief 创建CURL句柄并配置选项
     * @param request HTTP请求
     * @return CURL句柄
     */
    CURL* create_curl_handle(const Request& request);

    /**
     * @brief 设置请求头
     * @param curl CURL句柄
     * @param request HTTP请求
     */
    void set_request_headers(CURL* curl, const Request& request);

    /**
     * @brief 设置认证信息
     * @param curl CURL句柄
     * @param username 用户名
     * @param password 密码
     */
    void set_authentication(CURL* curl, const std::string& username,
                           const std::string& password);

    /**
     * @brief 处理CURL响应
     * @param curl CURL句柄
     * @param response 响应结构（输出）
     * @return true表示成功
     */
    bool handle_response(CURL* curl, Response& response);

    /**
     * @brief libcurl写数据回调函数
     */
    static size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp);

    /**
     * @brief libcurl读数据回调函数（用于POST）
     */
    static size_t read_callback(void* ptr, size_t size, size_t nmemb, void* userp);

    /**
     * @brief 从URL提取主机名
     * @param url 完整URL
     * @return 主机名
     */
    std::string extract_host(const std::string& url);
};

} // namespace libonvif_client
