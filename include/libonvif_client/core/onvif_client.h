/**
 * @file onvif_client.h
 * @brief ONVIF主客户端类（header-only）
 * @note 提供服务发现和客户端管理功能
 */

#pragma once
#include <functional>
#include <libonvif_client/core/onvif_callback.h>
#include <libonvif_client/core/onvif_service_base.h>
#include <libonvif_client/client/DeviceClient.h>
#include <map>
#include <memory>
#include <string>

namespace libonvif_client {

// 前向声明
class DeviceClient;

/**
 * @brief ONVIF主客户端类
 *
 * 核心职责：
 * 1. 初始化：通过 DeviceClient.GetServices 自动发现并创建所有服务客户端
 * 2. 管理：提供访问各个服务客户端的统一接口
 *
 * 不负责：
 * - 网络连接状态管理（每个请求独立）
 * - 连接生命周期管理（无状态设计）
 */
class OnvifClient {
public:
    /**
     * @brief ONVIF客户端配置
     */
    struct Config {
        std::string device_url;         ///< 设备服务端点URL
        std::string username;           ///< 认证用户名
        std::string password;           ///< 认证密码

        bool is_valid() const {
            return !device_url.empty();
        }
    };

    /**
     * @brief 构造函数
     * @param device_url 设备服务端点URL
     * @param username 认证用户名
     * @param password 认证密码
     * @param http_client HTTP客户端实现（用户提供）
     */
    OnvifClient(std::string device_url,
                std::string username,
                std::string password,
                std::shared_ptr<IHttpClient> http_client)
        : http_client_(std::move(http_client))
        , device_url_(std::move(device_url))
        , username_(std::move(username))
        , password_(std::move(password)) {

        if (!http_client_) {
            throw std::invalid_argument("HTTP client cannot be null");
        }

        if (device_url_.empty()) {
            throw std::invalid_argument("Device URL cannot be empty");
        }
    }

    /**
     * @brief 析构函数
     */
    ~OnvifClient() = default;

    /**
     * @brief 初始化客户端
     *
     * 通过 DeviceClient.GetServices 自动发现所有可用服务，
     * 并根据 ServiceClientFactory 中注册的客户端自动创建实例。
     *
     * @param callback 初始化结果回调
     */
    void initialize(const OnvifCallback<tds_GetServicesResponse>& callback) {
        // 创建临时 DeviceClient 用于服务发现
        auto device_client = create_device_client();

        // 使用 DeviceClient.GetServices 发现所有服务
        tds_GetServices request;
        request.IncludeCapability = false;  // 我们只需要端点信息

        device_client->GetServices(request,
            [this, device_client, callback](OnvifResult<tds_GetServicesResponse>&& result) {
                if (!result.is_success()) {
                    if (callback) {
                        callback(std::move(result));
                    }
                    return;
                }

                if (!result.data) {
                    if (callback) {
                        callback(std::move(result));
                    }
                    return;
                }

                // 解析服务列表
                for (const auto& service : result.data->Service) {
                    if (!service.Namespace.empty() && !service.XAddr.empty()) {
                        std::string endpoint = service.XAddr;
                        service_endpoints_[service.Namespace] = service.XAddr;
                    }
                }
                // 初始化成功
                if (callback) {
                    callback(std::move(result));
                }
            }
        );
    }

    // ========================================================================
    // 服务客户端访问器 - 按需创建，用完即销毁
    // ========================================================================

    /**
     * @brief 创建设备服务客户端（每次创建新实例）
     * @param http_client 可选的HTTP客户端，不指定则使用默认客户端
     * @return 设备客户端共享指针
     */
    [[nodiscard]] std::shared_ptr<DeviceClient> create_device_client(
        const std::shared_ptr<IHttpClient>& http_client = nullptr) const {
        // 使用指定的HTTP客户端或默认客户端
        auto client = http_client ? http_client : http_client_;
        return std::make_shared<DeviceClient>(
            device_url_, client, username_, password_
        );
    }

    /**
     * @brief 根据服务名称创建客户端（类型安全）
     */
    template<typename T>
    std::shared_ptr<T> create_service(const std::shared_ptr<IHttpClient>& http_client = nullptr) const {
        if (auto it = service_endpoints_.find(T::TARGET_NAMESPACE); it != service_endpoints_.end()) {
            return std::make_shared<T>(it->second, http_client ? http_client : http_client_ , username_, password_);
        }
        return nullptr;
    }

    // ========================================================================
    // 服务信息查询
    // ========================================================================

    /**
     * @brief 获取可用服务列表
     */
    [[nodiscard]] std::map<std::string, std::string> get_available_services() const {
        return service_endpoints_;
    }

    /**
     * @brief 检查指定服务是否可用
     */
    [[nodiscard]] bool is_service_available(const std::string& namespace_uri) const {
        return service_endpoints_.find(namespace_uri) != service_endpoints_.end();
    }

    /**
     * @brief 获取服务端点URL
     */
    [[nodiscard]] std::string get_service_endpoint(const std::string& namespace_uri) const {
        auto it = service_endpoints_.find(namespace_uri);
        if (it != service_endpoints_.end()) {
            return it->second;
        }
        return "";
    }

private:
    std::shared_ptr<IHttpClient> http_client_;      ///< HTTP客户端
    std::string device_url_;                        ///< 设备URL
    std::string username_;                          ///< 认证用户名
    std::string password_;                          ///< 认证密码

    // 服务信息映射：友好名称 -> 端点信息
    struct ServiceEndpointInfo {
        std::string namespace_uri;  ///< ONVIF 命名空间
        std::string endpoint;       ///< 服务端点URL
    };
    std::map<std::string, std::string> service_endpoints_;
};

} // namespace libonvif_client
