/**
 * @file onvif_service_base.h
 * @brief ONVIF服务基类定义（header-only）
 * @note 所有ONVIF服务客户端的基类，处理SOAP协议细节
 */

#pragma once

#include <map>
#include <memory>
#include <string>
#include "libonvif_client/utils/common.h"
#include <libonvif_client/xml_convert.h>
#include <libonvif_client/core/http_client.h>
#include <libonvif_client/core/onvif_callback.h>
#include <libonvif_client/client/namespaces.h>

namespace libonvif_client {

    /**
     * @brief ONVIF服务基类
     *
     * 提供所有ONVIF服务的通用功能，包括：
     * - SOAP消息构建和解析
     * - HTTP请求处理
     * - 认证管理
     * - 错误处理
     *
     * 此类被所有生成的服务客户端继承使用。
     */
    class OnvifServiceBase : public std::enable_shared_from_this<OnvifServiceBase> {
    public:
        /**
         * @brief 构造函数
         * @param service_url ONVIF服务端点URL
         * @param http_client HTTP客户端实现（用户提供）
         * @param username 认证用户名（可选）
         * @param password 认证密码（可选）
         */
        OnvifServiceBase(const std::string& service_url,
                         const std::shared_ptr<IHttpClient>& http_client,
                         const std::string& username = "",
                         const std::string& password = "")
            : service_url_(service_url)
            , http_client_(http_client)
            , username_(username)
            , password_(password)
            , timeout_ms_(30000) {
        }

        /**
         * @brief 虚析构函数
         */
        virtual ~OnvifServiceBase() = default;

        /**
         * @brief 获取当前服务端点URL
         * @return 服务URL
         */
        [[nodiscard]] const std::string& get_service_url() const { return service_url_; }

        /**
         * @brief 设置认证信息
         * @param username 用户名
         * @param password 密码
         */
        void set_credentials(const std::string& username, const std::string& password) {
            username_ = username;
            password_ = password;
        }

        /**
         * @brief 设置请求超时时间
         * @param timeout_ms 超时时间（毫秒）
         */
        void set_timeout(int timeout_ms) { timeout_ms_ = timeout_ms; }

        /**
         * @brief 获取当前超时时间
         * @return 超时时间（毫秒）
         */
        int get_timeout() const { return timeout_ms_; }

        /**
         * @brief 设置HTTP客户端
         * @param http_client 新的HTTP客户端实现
         * @note 允许运行时替换HTTP客户端实现
         */
        void set_http_client(std::shared_ptr<IHttpClient> http_client) {
            if (http_client) {
                http_client_ = std::move(http_client);
            }
        }

        /**
         * @brief 获取当前HTTP客户端
         * @return HTTP客户端共享指针
         */
        [[nodiscard]] std::shared_ptr<IHttpClient> get_http_client() const { return http_client_; }

        [[nodiscard]] virtual const char * get_namespace_uri() const = 0;
        [[nodiscard]] virtual const char * get_namespace_prefix() const = 0;

    protected:
        /**
         * @brief 核心服务调用方法
         *
         * 此方法供生成的服务客户端使用，处理完整的SOAP请求-响应流程。
         *
         * @tparam TRequest 请求类型
         * @tparam TResponse 响应类型
         * @param soap_action SOAP Action头值
         * @param request 请求对象
         * @param request_element_name 请求元素名称
         * @param response_element_name 响应元素名称（用于解析）
         * @param callback 响应回调函数
         */
        template<typename TRequest, typename TResponse>
        void call_service(const std::string& soap_action,
                         const TRequest& request,
                         const char* request_element_name,
                         const std::string& response_element_name,
                         OnvifCallback<TResponse> callback) {
            if (!callback) {
                return; // 无回调函数，直接返回
            }
            // 创建HTTP请求，使用传入的元素名和命名空间前缀
            IHttpClient::Request http_request;
            http_request.url = service_url_;
            http_request.action = soap_action;
            http_request.timeout_ms = timeout_ms_;
            http_request.xml_doc = build_request(request, soap_action, request_element_name, get_namespace_prefix());
            call(std::move(http_request), response_element_name, std::move(callback));
        }

        /**
         * @brief 核心服务调用方法（指定命名空间版本）
         *
         * 此方法用于支持wsdl:import场景，当操作来自不同命名空间时使用。
         *
         * @tparam TRequest 请求类型
         * @tparam TResponse 响应类型
         * @param soap_action SOAP Action头值
         * @param request 请求对象
         * @param request_element_name 请求元素名称
         * @param response_element_name 响应元素名称（用于解析）
         * @param namespace_prefix 命名空间前缀（显式指定）
         * @param callback 响应回调函数
         */
        template<typename TRequest, typename TResponse>
        void call_service_ex(const std::string& soap_action,
                            const TRequest& request,
                            const char* request_element_name,
                            const std::string& response_element_name,
                            const char* namespace_prefix,
                            OnvifCallback<TResponse> callback) {
            if (!callback) {
                return; // 无回调函数，直接返回
            }
            IHttpClient::Request http_request;
            http_request.url = service_url_;
            http_request.action = soap_action;
            http_request.timeout_ms = timeout_ms_;
            http_request.xml_doc = build_request(request, soap_action, request_element_name, namespace_prefix);
            call(std::move(http_request), response_element_name, std::move(callback));
        }

        /**
         * @brief 核心调用实现（零拷贝 + 统一错误处理）
         *
         * @tparam TResponse 响应类型
         * @param request HTTP请求
         * @param response_element_name 响应元素名称
         * @param callback 结果回调函数
         */
        template<typename TResponse>
        void call(IHttpClient::Request&& request,
                  const std::string& response_element_name,
                  OnvifCallback<TResponse> callback) {
            if (!callback) {
                return;
            }

            // 使用 weak_ptr 安全捕获 this
            auto weak_this = weak_from_this();
            auto ns_prefix_str = std::string(get_namespace_prefix());

            // 发送HTTP请求
            http_client_->request_async(std::move(request),
                [weak_this, callback = std::move(callback), response_element_name, ns_prefix_str]
                (const IHttpClient::Response& http_response) mutable {

                    auto self = weak_this.lock();
                    OnvifResult<TResponse> result;

                    // 1. 检查服务对象生命周期
                    if (!self) {
                        result.soap_fault = std::make_unique<SoapFault>();
                        result.soap_fault->set_owned_error("Client", "Service object destroyed");
                        callback(std::move(result));
                        return;
                    }

                    // 2. 检查 HTTP 层错误（转换为 SoapFault）
                    if (!http_response.is_success()) {
                        result.soap_fault = self->make_fault_from_http_error(http_response);
                        callback(std::move(result));
                        return;
                    }

                    // 3. 解析 XML（保留文档所有权）
                    result.xml_doc = std::shared_ptr<xmlDoc>(
                        xmlReadMemory(http_response.body.data(),
                                    http_response.body.size(),
                                    nullptr, nullptr,
                                    XML_PARSE_NOWARNING | XML_PARSE_NOERROR | XML_PARSE_RECOVER),
                        xmlFreeDoc
                    );

                    if (!result.xml_doc) {
                        result.soap_fault = std::make_unique<SoapFault>();
                        result.soap_fault->set_owned_error("Client", "Failed to parse SOAP XML");
                        callback(std::move(result));
                        return;
                    }

                    auto root = xmlDocGetRootElement(result.xml_doc.get());
                    if (!root) {
                        result.soap_fault = std::make_unique<SoapFault>();
                        result.soap_fault->set_owned_error("Client", "No root element in SOAP XML");
                        callback(std::move(result));
                        return;
                    }

                    // 4. 查找 SOAP Body
                    xmlNodePtr body = self->find_soap_body(root);
                    if (!body) {
                        result.soap_fault = std::make_unique<SoapFault>();
                        result.soap_fault->set_owned_error("Client", "No Body element in SOAP envelope");
                        callback(std::move(result));
                        return;
                    }

                    // 5. 检查 SOAP Fault（零拷贝解析）
                    if (xmlNodePtr fault_node = self->find_soap_fault(body)) {
                        result.soap_fault = self->parse_soap_fault_zero_copy(fault_node);
                        result.response_node = fault_node;
                        callback(std::move(result));
                        return;
                    }

                    // 6. 解析成功响应
                    result.response_node = body;
                    auto data = std::make_unique<TResponse>();

                    if (xml_convert::from_xml_val(*data, body, response_element_name.c_str(),
                                                 ns_prefix_str.c_str(), get_namespace_map())) {
                        result.data = std::move(data);
                    } else {
                        result.soap_fault = std::make_unique<SoapFault>();
                        result.soap_fault->set_owned_error(
                            "Client",
                            "Failed to parse response element: " + response_element_name);
                    }

                    callback(std::move(result));
                });
        }

        /**
         * @brief 核心调用实现（void 响应特化）
         *
         * 用于无返回数据的 ONVIF 操作（如 Notify）
         *
         * @param request HTTP请求
         * @param response_element_name 响应元素名称（用于验证）
         * @param callback 结果回调函数
         */
        void call(IHttpClient::Request&& request,
                  const std::string& response_element_name,
                  OnvifCallback<void> callback) {
            if (!callback) {
                return;
            }

            // 使用 weak_ptr 安全捕获 this
            auto weak_this = weak_from_this();

            // 发送HTTP请求
            http_client_->request_async(std::move(request),
                [weak_this, callback = std::move(callback), response_element_name]
                (const IHttpClient::Response& http_response) mutable {

                    auto self = weak_this.lock();
                    OnvifResult<void> result;

                    // 1. 检查服务对象生命周期
                    if (!self) {
                        result.soap_fault = std::make_unique<SoapFault>();
                        result.soap_fault->set_owned_error("Client", "Service object destroyed");
                        callback(std::move(result));
                        return;
                    }

                    // 2. 检查 HTTP 层错误（转换为 SoapFault）
                    if (!http_response.is_success()) {
                        result.soap_fault = self->make_fault_from_http_error(http_response);
                        callback(std::move(result));
                        return;
                    }

                    // 3. 解析 XML（保留文档所有权）
                    result.xml_doc = std::shared_ptr<xmlDoc>(
                        xmlReadMemory(http_response.body.data(),
                                    http_response.body.size(),
                                    nullptr, nullptr,
                                    XML_PARSE_NOWARNING | XML_PARSE_NOERROR | XML_PARSE_RECOVER),
                        xmlFreeDoc
                    );

                    if (!result.xml_doc) {
                        result.soap_fault = std::make_unique<SoapFault>();
                        result.soap_fault->set_owned_error("Client", "Failed to parse SOAP XML");
                        callback(std::move(result));
                        return;
                    }

                    auto root = xmlDocGetRootElement(result.xml_doc.get());
                    if (!root) {
                        result.soap_fault = std::make_unique<SoapFault>();
                        result.soap_fault->set_owned_error("Client", "No root element in SOAP XML");
                        callback(std::move(result));
                        return;
                    }

                    // 4. 查找 SOAP Body
                    xmlNodePtr body = self->find_soap_body(root);
                    if (!body) {
                        result.soap_fault = std::make_unique<SoapFault>();
                        result.soap_fault->set_owned_error("Client", "No Body element in SOAP envelope");
                        callback(std::move(result));
                        return;
                    }

                    // 5. 检查 SOAP Fault（零拷贝解析）
                    if (xmlNodePtr fault_node = self->find_soap_fault(body)) {
                        result.soap_fault = self->parse_soap_fault_zero_copy(fault_node);
                        result.response_node = fault_node;
                        callback(std::move(result));
                        return;
                    }

                    // 6. void 响应：只需验证响应元素存在即可
                    result.response_node = body;

                    // 成功：soap_fault 为空表示成功
                    callback(std::move(result));
                });
        }

    private:
        std::string service_url_;                    ///< 服务端点URL
        std::shared_ptr<IHttpClient> http_client_;   ///< HTTP客户端共享指针
        std::string username_;                       ///< 认证用户名
        std::string password_;                       ///< 认证密码
        int timeout_ms_;                             ///< 请求超时时间（毫秒）
        char reserved[4]{};

        template<typename T>
        std::shared_ptr<xmlDoc> build_request(const T & data,
                                 const std::string& soap_action,
                                 const char* element_name,
                                 const char* ns_prefix) {
            auto xml_ptr = std::shared_ptr<xmlDoc>(xmlNewDoc(BAD_CAST "1.0"), xmlFreeDoc);
            auto envelope = xmlNewNode(nullptr, BAD_CAST"Envelope");
            xmlDocSetRootElement(xml_ptr.get(), envelope);

            xmlNsPtr envelope_ns = xmlNewNs(envelope, BAD_CAST soap_envelope_namespace.data(), BAD_CAST find_ns_prefix(soap_envelope_namespace.data()));
            xmlSetNs(envelope, envelope_ns);
            auto wsa_ns = xmlNewNs(envelope, BAD_CAST soap_wsa_namespace.data(), BAD_CAST find_ns_prefix(soap_wsa_namespace.data()));

            xmlNodePtr header = xmlNewChild(envelope, envelope_ns, BAD_CAST "Header", nullptr);
            xmlNewChild(header, wsa_ns, BAD_CAST "Action", BAD_CAST soap_action.c_str());
            xmlNewChild(header, wsa_ns, BAD_CAST "To", BAD_CAST service_url_.c_str());
            if (!username_.empty()) {
                build_ws_security_header(header);
            }
            auto body = xmlNewChild(envelope, envelope_ns, BAD_CAST "Body", nullptr);

            // 使用传入的 element_name 和 ns_prefix
            xml_convert::to_xml_val(data, body, element_name, ns_prefix, get_namespace_map());
            return xml_ptr;
        }

        /**
         * @brief 获取命名空间映射（静态单例，从 constexpr 数组初始化）
         */
        static const std::map<std::string_view, std::string_view>& get_namespace_map() {
            static const std::map<std::string_view, std::string_view> ns_map = [] {
                std::map<std::string_view, std::string_view> map;
                for (const auto& [prefix, uri] : g_namespace_mappings) {
                    map[prefix] = uri;
                }
                return map;
            }();
            return ns_map;
        }

        /**
         * @brief 设置WS认证
         * @param header XML头节点
         */
        void build_ws_security_header(const xmlNodePtr header) {
            auto security = xmlNewChild(header, nullptr, BAD_CAST "Security", BAD_CAST nullptr);
            auto wsse_ns = xmlNewNs(security, BAD_CAST soap_wsse_namespace.data(), BAD_CAST find_ns_prefix(soap_wsse_namespace.data()));
            auto wsu_ns = xmlNewNs(security, BAD_CAST soap_wsu_namespace.data(), BAD_CAST find_ns_prefix(soap_wsu_namespace.data()));
            xmlSetNs(security, wsse_ns);
            auto username_token = xmlNewChild(security, wsse_ns, BAD_CAST "UsernameToken", BAD_CAST nullptr);
            xmlNewChild(username_token, wsse_ns, BAD_CAST "Username", BAD_CAST username_.data());

            std::string nonce = generate_nonce();
            std::string created = get_current_timestamp();
            std::string password_digest = compute_password_digest(nonce, created, password_);

            if (auto node = xmlNewChild(username_token, wsse_ns, BAD_CAST "Password", BAD_CAST password_digest.data())) {
                xmlSetProp(node, BAD_CAST "Type", BAD_CAST "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordDigest");
            }
            if (auto node = xmlNewChild(username_token, wsse_ns, BAD_CAST "Nonce", BAD_CAST nonce.data())) {
                xmlSetProp(node, BAD_CAST "EncodingType", BAD_CAST "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-soap-message-security-1.0#Base64Binary");
            }
            xmlNewChild(username_token, wsu_ns, BAD_CAST "Created", BAD_CAST created.data());
        }

        /**
         * @brief 从 HTTP 错误创建 SoapFault（统一错误表示）
         * @param http_response HTTP响应
         * @return SoapFault 实例
         */
        std::unique_ptr<SoapFault> make_fault_from_http_error(
            const IHttpClient::Response& http_response) {

            auto fault = std::make_unique<SoapFault>();

            if (http_response.timeout) {
                fault->set_owned_error("Client", http_response.error, "Timeout");
            } else if (http_response.status_code == 401 || http_response.status_code == 403) {
                std::string reason = http_response.error.empty()
                    ? (http_response.status_code == 401 ? "Authentication required" : "Access denied")
                    : http_response.error;
                fault->set_owned_error("Client", std::move(reason), "Unauthorized");
            } else if (http_response.status_code >= 500) {
                std::string reason = http_response.error.empty()
                    ? "Server error"
                    : http_response.error;
                fault->set_owned_error("Server", std::move(reason), std::to_string(http_response.status_code));
            } else if (http_response.status_code >= 400) {
                std::string reason = http_response.error.empty()
                    ? "Client error"
                    : http_response.error;
                fault->set_owned_error("Client", std::move(reason), std::to_string(http_response.status_code));
            } else {
                std::string reason = http_response.error.empty()
                    ? "HTTP error"
                    : http_response.error;
                fault->set_owned_error("Client", std::move(reason));
            }

            return fault;
        }

        /**
         * @brief 零拷贝解析 SOAP Fault
         *
         * 关键：使用 string_view 直接引用 XML 节点内容
         * 生命周期：依赖 OnvifResult::xml_doc 保持 XML 文档存活
         *
         * @param fault SOAP Fault 节点
         * @return SoapFault 实例（零拷贝）
         */
        std::unique_ptr<SoapFault> parse_soap_fault_zero_copy(xmlNodePtr fault) {
            auto result = std::make_unique<SoapFault>();

            for (xmlNodePtr child = fault->children; child; child = child->next) {
                if (child->type != XML_ELEMENT_NODE) continue;

                // SOAP 1.2: <Code>
                if (xmlStrcmp(child->name, BAD_CAST "Code") == 0) {
                    if (auto value_node = find_child(child, "Value")) {
                        result->code = get_node_content_view(value_node);
                    }
                    if (auto subcode_node = find_child(child, "Subcode")) {
                        if (auto value_node = find_child(subcode_node, "Value")) {
                            result->subcode = get_node_content_view(value_node);
                        }
                    }
                }
                // SOAP 1.2: <Reason>
                else if (xmlStrcmp(child->name, BAD_CAST "Reason") == 0) {
                    if (auto text_node = find_child(child, "Text")) {
                        result->reason = get_node_content_view(text_node);
                    }
                }
                // SOAP 1.2: <Detail>
                else if (xmlStrcmp(child->name, BAD_CAST "Detail") == 0) {
                    result->detail_node = child;
                }
                // SOAP 1.1: <faultcode>
                else if (xmlStrcmp(child->name, BAD_CAST "faultcode") == 0) {
                    result->code = get_node_content_view(child);
                }
                // SOAP 1.1: <faultstring>
                else if (xmlStrcmp(child->name, BAD_CAST "faultstring") == 0) {
                    result->reason = get_node_content_view(child);
                }
                // SOAP 1.1: <faultdetail> or <detail>
                else if (xmlStrcmp(child->name, BAD_CAST "detail") == 0 ||
                         xmlStrcmp(child->name, BAD_CAST "faultdetail") == 0) {
                    result->detail_node = child;
                }
            }

            return result;
        }

        /**
         * @brief 零拷贝获取 XML 节点内容（string_view）
         *
         * @param node XML 节点
         * @return 节点内容的 string_view
         */
        static std::string_view get_node_content_view(xmlNodePtr node) {
            xmlChar* content = xmlNodeGetContent(node);
            if (!content) return "";
            return std::string_view(reinterpret_cast<const char*>(content));
        }

        /**
         * @brief 查找子节点
         * @param parent 父节点
         * @param name 子节点名称
         * @return 找到的子节点，未找到返回nullptr
         */
        static xmlNodePtr find_child(xmlNodePtr parent, const char* name) {
            for (xmlNodePtr child = parent->children; child; child = child->next) {
                if (child->type == XML_ELEMENT_NODE &&
                    xmlStrcmp(child->name, BAD_CAST name) == 0) {
                    return child;
                }
            }
            return nullptr;
        }

        /**
         * @brief 查找 SOAP Body
         * @param root 根节点
         * @return Body 节点，未找到返回nullptr
         */
        static xmlNodePtr find_soap_body(xmlNodePtr root) {
            for (xmlNodePtr child = root->children; child; child = child->next) {
                if (child->type == XML_ELEMENT_NODE &&
                    xmlStrcmp(child->name, BAD_CAST "Body") == 0) {
                    return child;
                }
            }
            return nullptr;
        }

        /**
         * @brief 查找 SOAP Fault
         * @param body Body 节点
         * @return Fault 节点，未找到返回nullptr
         */
        static xmlNodePtr find_soap_fault(xmlNodePtr body) {
            for (xmlNodePtr child = body->children; child; child = child->next) {
                if (child->type == XML_ELEMENT_NODE &&
                    xmlStrcmp(child->name, BAD_CAST "Fault") == 0) {
                    return child;
                }
            }
            return nullptr;
        }
    };

} // namespace libonvif_client
