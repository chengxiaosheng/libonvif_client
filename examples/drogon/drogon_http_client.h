/**
 * @file drogon_http_client.h
 * @brief 基于Drogon的HTTP客户端实现
 * @note 实现IHttpClient接口，使用drogon::HttpClient进行HTTP请求
 */

#pragma once

#include <libonvif_client/core/http_client.h>
#include <drogon/HttpClient.h>
#include <memory>
#include <string>

namespace libonvif_client {

/**
 * @brief 基于Drogon的HTTP客户端实现
 *
 * 此类使用drogon::HttpClient实现IHttpClient接口，
 * 提供完整的异步HTTP请求能力，包括：
 * - 异步非阻塞请求
 * - 超时控制
 * - HTTP基本认证
 * - SSL/TLS支持
 * - 自动错误处理
 */
class DrogonHttpClient : public IHttpClient {
public:
    /**
     * @brief 构造函数
     * @param use_ssl 是否使用SSL/TLS（默认true）
     */
    explicit DrogonHttpClient(bool use_ssl = true);

    /**
     * @brief 析构函数
     */
    ~DrogonHttpClient() override = default;


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
     * @brief 设置连接池大小
     * @param pool_size 连接池大小（默认10）
     */
    void set_connection_pool_size(size_t pool_size);

private:
    bool use_ssl_;                              ///< 是否使用SSL
    bool ssl_verify_;                           ///< 是否验证SSL证书
    size_t connection_pool_size_;               ///< 连接池大小

    /**
     * @brief 创建Drogon HTTP请求
     * @param req IHttpClient请求
     * @return Drogon HTTP请求指针
     */
    drogon::HttpRequestPtr create_drogon_request(const Request& req);

    /**
     * @brief 获取或创建HTTP客户端
     * @param url 目标URL
     * @return Drogon HTTP客户端指针
     */
    drogon::HttpClientPtr get_http_client(const std::string& url);

    /**
     * @brief 转换Drogon响应为IHttpClient::Response
     * @param resp Drogon HTTP响应
     * @return IHttpClient响应结构
     */
    Response convert_response(const drogon::HttpResponsePtr& resp);

    /**
     * @brief 创建错误响应
     * @param error_message 错误消息
     * @return 错误响应结构
     */
    Response create_error_response(const std::string& error_message);

    /**
     * @brief 从URL提取主机和端口
     * @param url 完整URL
     * @param[out] host 主机名
     * @param[out] port 端口号
     * @param[out] path 路径
     * @return true表示解析成功
     */
    bool parse_url(const std::string& url, std::string& host,
                   uint16_t& port, std::string& path);
};

} // namespace libonvif_client
