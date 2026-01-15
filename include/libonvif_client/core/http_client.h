/**
 * @file http_client.h
 * @brief 用户HTTP客户端抽象接口
 * @note 用户需要实现此接口以集成自己的HTTP库
 */

#pragma once

#include <functional>
#include <libxml/tree.h>
#include <map>
#include <memory>
#include <string>

namespace libonvif_client {

    struct XmlStringView {
        xmlChar* buffer;
        std::string_view view;

        XmlStringView(xmlChar* buf, int len)
            : buffer(buf), view(reinterpret_cast<const char*>(buf), len) {}

        ~XmlStringView() {
            if (buffer) xmlFree(buffer);
        }
    };

/**
 * @brief 用户HTTP客户端抽象接口
 * 
 * 这是用户唯一需要实现的接口，支持任何异步HTTP库的集成。
 * 用户可以基于libcurl、boost::asio、drogon或任何其他HTTP库来实现此接口。
 */
class IHttpClient {
public:
    /**
     * @brief HTTP请求结构
     */
    struct Request {
        std::string url;                                    ///< 请求URL
        std::string action;
        std::shared_ptr<xmlDoc> xml_doc;                    ///< libxml2 文档对象, 用户在发送请求前可以对其进行修改
        int timeout_ms = 5000;                             ///< 超时时间（毫秒），默认5秒

    private:
        mutable std::shared_ptr<XmlStringView> cached_buffer_;  ///< 缓存的 XML buffer

    public:
        /**
         * 将xml输出为buffer（缓存结果，多次调用返回同一份）
         * @return XML buffer，失败返回 nullptr
         * @note 返回的生命周期绑定到 Request 对象
         */
        [[nodiscard]] const std::shared_ptr<XmlStringView>& buffer() const {
            if (!cached_buffer_) {
                xmlChar* buffer;
                int buffer_len;
                xmlDocDumpMemory(xml_doc.get(), &buffer, &buffer_len);
                if (buffer && buffer_len > 0) {
                    cached_buffer_ = std::make_shared<XmlStringView>(buffer, buffer_len);
                }
            }
            return cached_buffer_;
        }
    };
    
    /**
     * @brief HTTP响应结构
     */
    struct Response {
        int status_code = 0;                                ///< HTTP状态码, 由HttpClient实例提供
        bool timeout = false;                               ///< 是否超时, 由HttpClient实例提供
        std::string_view body;                              ///< 响应体, 由HttpClient实例提供
        /// @note body 的生命周期由 HttpClient 实现者保证，必须在回调函数执行期间有效
        /// @note 典型实现：body 指向存储在 Response 对象内部或由拥有该数据的 shared_ptr 管理的内存
        std::string error;                                  ///< 错误信息，空字符串表示成功， 由HttpClient实例提供
        
        /**
         * @brief 检查响应是否成功
         * @return true表示成功（无错误且状态码2xx）
         */
        [[nodiscard]] bool is_success() const {
            return error.empty() && status_code >= 200 && status_code < 300;
        }

        /**
         * @brief 检查是否是HTTP错误状态码
         * @return true表示HTTP状态码表示错误（4xx或5xx）
         */
        [[nodiscard]] bool has_http_error() const {
            return error.empty() && (status_code >= 400);
        }
    };
    
    /**
     * @brief 异步响应回调函数类型
     * @param response HTTP响应结构
     */
    using Callback = std::function<void(const Response&)>;
    
    /**
     * @brief 执行异步HTTP请求
     * 
     * 此方法应该是非阻塞的，通过回调返回结果。
     * 实现者应该处理所有网络错误，并通过Response结构返回适当的错误信息。
     * 
     * @param request HTTP请求结构
     * @param callback 完成回调，无论成功或失败都会被调用
     * 
     * @note 回调函数可能在任何线程中被调用，实现者需要确保线程安全
     * @note 超时应该通过request.timeout_ms来处理
     * @note 认证应该通过request.headers中的Authorization头来处理
     */
    virtual void request_async(Request request, Callback callback) = 0;
    
    /**
     * @brief 虚析构函数
     */
    virtual ~IHttpClient() noexcept = default;

protected:
    /**
     * @brief 受保护的构造函数，防止直接实例化
     */
    IHttpClient() = default;
};

} // namespace libonvif_client