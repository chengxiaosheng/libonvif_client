/**
 * @file curl_http_client.cpp
 * @brief 基于libcurl的HTTP客户端实现
 */

#include "curl_http_client.h"
#include <cstring>
#include <future>
#include <iostream>
#include <regex>
#include <thread>

namespace libonvif_client {

// ============================================================================
// 写数据回调函数（用于接收响应体）
// ============================================================================
size_t CurlHttpClient::write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t total_size = size * nmemb;
    auto* response_body = static_cast<std::string*>(userp);
    response_body->append(static_cast<char*>(contents), total_size);
    return total_size;
}

// ============================================================================
// 读数据回调函数（用于发送请求体）
// ============================================================================
size_t CurlHttpClient::read_callback(void* ptr, size_t size, size_t nmemb, void* userp) {
    auto* read_data = static_cast<std::pair<const char*, size_t>*>(userp);
    size_t copy_size = (read_data->second < size * nmemb) ? read_data->second : size * nmemb;

    if (copy_size > 0) {
        std::memcpy(ptr, read_data->first, copy_size);
        read_data->first += copy_size;
        read_data->second -= copy_size;
    }

    return copy_size;
}

// ============================================================================
// 构造函数
// ============================================================================
CurlHttpClient::CurlHttpClient(bool use_ssl, size_t thread_pool_size)
    : use_ssl_(use_ssl)
    , ssl_verify_(false)  // ONVIF设备常使用自签名证书
    , thread_pool_size_(thread_pool_size)
    , connect_timeout_(30)
{
    init_curl();
}

// ============================================================================
// 析构函数
// ============================================================================
CurlHttpClient::~CurlHttpClient() {
    cleanup_curl();
}

// ============================================================================
// 初始化CURL（线程安全）
// ============================================================================
void CurlHttpClient::init_curl() {
    std::lock_guard<std::mutex> lock(curl_mutex_);
    static bool curl_initialized = false;
    if (!curl_initialized) {
        curl_global_init(CURL_GLOBAL_ALL);
        curl_initialized = true;
    }
}

// ============================================================================
// 清理CURL
// ============================================================================
void CurlHttpClient::cleanup_curl() {
    // 注意：不调用 curl_global_cleanup()，因为可能有其他CurlHttpClient实例
    // curl_global_cleanup() 应该在程序退出时调用一次
}

// ============================================================================
// 设置SSL证书验证
// ============================================================================
void CurlHttpClient::set_ssl_verify(bool verify) {
    ssl_verify_ = verify;
}

// ============================================================================
// 设置代理
// ============================================================================
void CurlHttpClient::set_proxy(const std::string& proxy) {
    proxy_ = proxy;
}

// ============================================================================
// 设置连接超时
// ============================================================================
void CurlHttpClient::set_connect_timeout(long timeout_secs) {
    connect_timeout_ = timeout_secs;
}

// ============================================================================
// 异步HTTP请求
// ============================================================================
void CurlHttpClient::request_async(Request request, Callback callback) {
    // 在后台线程中执行请求（模拟异步）
    std::thread([this, request = std::move(request), callback = std::move(callback)]() {
        perform_request(request, callback);
    }).detach();
}

// ============================================================================
// 执行HTTP请求（在后台线程中运行）
// ============================================================================
void CurlHttpClient::perform_request(const Request& request, Callback callback) {
    CURL* curl = nullptr;
    Response response;
    std::string response_body;
    try {
        curl = create_curl_handle(request);
        if (!curl) {
            response.error = "Failed to create CURL handle";
            callback(response);
            return;
        }

        // 设置请求头
        set_request_headers(curl, request);

        // 获取XML buffer
        auto xml_buffer = request.buffer();
        if (!xml_buffer || !xml_buffer->view.data()) {
            response.error = "Failed to serialize XML document";
            curl_easy_cleanup(curl);
            callback(response);
            return;
        }

        // 设置POST数据
        std::pair<const char*, size_t> read_data{
            xml_buffer->view.data(),
            xml_buffer->view.size()
        };

        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE,
                        static_cast<curl_off_t>(xml_buffer->view.size()));
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
        curl_easy_setopt(curl, CURLOPT_READDATA, &read_data);

        // 设置写入回调
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_body);

        // 设置超时
        curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, static_cast<long>(request.timeout_ms));

        // 执行请求
        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            response.error = curl_easy_strerror(res);
            response.timeout = (res == CURLE_OPERATION_TIMEDOUT);
        } else {
            // 获取响应状态码
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            response.status_code = static_cast<int>(http_code);
            response.body = response_body;  // 这里的生命周期在callback执行期间有效
        }

    } catch (const std::exception& e) {
        response.error = std::string("Exception: ") + e.what();
    }

    if (curl) {
        curl_easy_cleanup(curl);
    }
    callback(response);
}

// ============================================================================
// 创建CURL句柄并配置选项
// ============================================================================
CURL* CurlHttpClient::create_curl_handle(const Request& request) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        return nullptr;
    }

    // 设置URL
    curl_easy_setopt(curl, CURLOPT_URL, request.url.c_str());

    // SSL设置
    if (use_ssl_) {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, ssl_verify_ ? 1L : 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, ssl_verify_ ? 2L : 0L);
    }

    // 设置代理
    if (!proxy_.empty()) {
        curl_easy_setopt(curl, CURLOPT_PROXY, proxy_.c_str());
    }

    // 连接超时
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, connect_timeout_);

    // 禁用信号处理（多线程环境必需）
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

    // 跟踪重定向
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 5L);

    return curl;
}

// ============================================================================
// 设置请求头
// ============================================================================
void CurlHttpClient::set_request_headers(CURL* curl, const Request& request) {
    struct curl_slist* headers = nullptr;

    // Content-Type
    headers = curl_slist_append(headers, "Content-Type: application/soap+xml; charset=utf-8");

    // SOAP Action
    if (!request.action.empty()) {
        std::string soap_action = "SOAPAction: " + request.action;
        headers = curl_slist_append(headers, soap_action.c_str());
    }

    // 其他标准头
    headers = curl_slist_append(headers, "Accept: application/soap+xml, application/xml");
    headers = curl_slist_append(headers, "Connection: Keep-Alive");
    headers = curl_slist_append(headers, "User-Agent: ONVIF-Client/1.0");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // 注意：headers 会在 curl_easy_cleanup 后自动释放
}

// ============================================================================
// 设置认证信息
// ============================================================================
void CurlHttpClient::set_authentication(CURL* curl, const std::string& username,
                                       const std::string& password) {
    if (!username.empty()) {
        curl_easy_setopt(curl, CURLOPT_USERNAME, username.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_ANY);
    }
}

// ============================================================================
// 处理CURL响应
// ============================================================================
bool CurlHttpClient::handle_response(CURL* curl, Response& response) {
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    response.status_code = static_cast<int>(http_code);

    return (http_code >= 200 && http_code < 300);
}

// ============================================================================
// 从URL提取主机名
// ============================================================================
std::string CurlHttpClient::extract_host(const std::string& url) {
    static const std::regex url_regex(
        R"(^(?:https?://)?([^:/\?#]+)(?::\d+)?(?:[/?#]|$))"
    );

    std::smatch match;
    if (std::regex_search(url, match, url_regex) && match.size() > 1) {
        return match[1].str();
    }

    return url;
}

} // namespace libonvif_client
