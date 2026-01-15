/**
 * @file drogon_http_client.cpp
 * @brief 基于Drogon的HTTP客户端实现
 */

#include "drogon_http_client.h"
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <regex>
#include <sstream>

#include "drogon/HttpAppFramework.h"

namespace libonvif_client {

DrogonHttpClient::DrogonHttpClient(bool use_ssl)
    : use_ssl_(use_ssl)
    , ssl_verify_(false)  // ONVIF设备通常使用自签名证书
    , connection_pool_size_(10) {
}

void DrogonHttpClient::request_async(Request request, Callback callback) {
    if (!callback) {
        return;  // 无回调函数，直接返回
    }

    try {
        // 1. 创建Drogon HTTP请求
        auto drogon_req = create_drogon_request(request);
        if (!drogon_req) {
            callback(create_error_response("Failed to create HTTP request"));
            return;
        }

        // 2. 获取HTTP客户端
        auto http_client = get_http_client(request.url);
        if (!http_client) {
            callback(create_error_response("Failed to create HTTP client for URL: " + request.url));
            return;
        }

        // 3. 发送异步请求
        http_client->sendRequest(drogon_req,
            [callback, this](drogon::ReqResult result, const drogon::HttpResponsePtr& resp) {
                // 处理请求结果
                if (result == drogon::ReqResult::Ok && resp) {
                    // 请求成功，转换响应
                    callback(convert_response(resp));
                } else {
                    // 请求失败，创建错误响应
                    std::string error_msg;
                    switch (result) {
                        case drogon::ReqResult::BadResponse:
                            error_msg = "Bad HTTP response";
                            break;
                        case drogon::ReqResult::NetworkFailure:
                            error_msg = "Network failure";
                            break;
                        case drogon::ReqResult::BadServerAddress:
                            error_msg = "Bad server address";
                            break;
                        case drogon::ReqResult::Timeout:
                            error_msg = "Request timeout";
                            break;
                        default:
                            error_msg = "Unknown error";
                            break;
                    }
                    callback(create_error_response(error_msg));
                }
            },
            request.timeout_ms / 1000.0  // 转换为秒
        );

    } catch (const std::exception& e) {
        callback(create_error_response(std::string("Exception: ") + e.what()));
    }
}

void DrogonHttpClient::set_ssl_verify(bool verify) {
    ssl_verify_ = verify;
}

void DrogonHttpClient::set_connection_pool_size(size_t pool_size) {
    connection_pool_size_ = pool_size;
}

drogon::HttpRequestPtr DrogonHttpClient::create_drogon_request(const Request& req) {
    // 创建HTTP请求
    auto drogon_req = drogon::HttpRequest::newHttpRequest();
    drogon_req->setMethod(drogon::Post);
    drogon_req->addHeader("soap-action", req.action);
    drogon_req->setContentTypeCode(drogon::CT_TEXT_XML);

    // 解析URL获取路径
    std::string host, path;
    uint16_t port;
    if (parse_url(req.url, host, port, path)) {
        drogon_req->setPath(path);
    } else {
        drogon_req->setPath("/");
    }
    drogon_req->setBody(req.buffer()->view.data());
    return drogon_req;
}

drogon::HttpClientPtr DrogonHttpClient::get_http_client(const std::string& url) {
    std::string host;
    uint16_t port;
    std::string path;

    if (!parse_url(url, host, port, path)) {
        return nullptr;
    }

    // 创建HTTP客户端
    auto client = drogon::HttpClient::newHttpClient(
        (use_ssl_ ? "https://" : "http://") + host + ":" + std::to_string(port)
    );

    return client;
}

IHttpClient::Response DrogonHttpClient::convert_response(const drogon::HttpResponsePtr& resp) {
    Response response;

    if (!resp) {
        response.error = "Null response pointer";
        return response;
    }

    // 设置状态码
    response.status_code = static_cast<int>(resp->getStatusCode());

    // 设置响应体
    response.body = resp->getBody();

    // 根据状态码设置错误信息
    if (response.status_code >= 400) {
        std::ostringstream oss;
        oss << "HTTP " << response.status_code;
        if (response.status_code == 401) {
            oss << " Unauthorized";
        } else if (response.status_code == 404) {
            oss << " Not Found";
        } else if (response.status_code >= 500) {
            oss << " Server Error";
        } else {
            oss << " Error";
        }
        response.error = oss.str();
    }

    return response;
}

IHttpClient::Response DrogonHttpClient::create_error_response(const std::string& error_message) {
    Response response;
    response.status_code = 0;
    response.error = error_message;
    return response;
}

bool DrogonHttpClient::parse_url(const std::string& url,
                                  std::string& host,
                                  uint16_t& port,
                                  std::string& path) {
    // 正则表达式匹配URL: (http|https)://host[:port][/path]
    std::regex url_regex(R"(^(https?://)?([^:/]+)(?::(\d+))?(/.*)?$)");
    std::smatch matches;

    if (!std::regex_match(url, matches, url_regex)) {
        return false;
    }

    // 提取主机
    host = matches[2].str();

    // 提取端口
    if (matches[3].matched) {
        port = static_cast<uint16_t>(std::stoi(matches[3].str()));
    } else {
        // 根据协议确定默认端口
        bool is_https = matches[1].str() == "https://";
        port = is_https ? 443 : 80;
    }

    // 提取路径
    if (matches[4].matched) {
        path = matches[4].str();
    } else {
        path = "/";
    }

    return true;
}

} // namespace libonvif_client
