/**
 * @file tev.h
 * @brief 从 event_v10.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver10/events/wsdl
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/wsa.h>
#include <libonvif_client/types/wsnt.h>
#include <libonvif_client/types/wsntw.h>
#include <libonvif_client/types/wsrf_rw.h>
#include <libonvif_client/types/wstop.h>

// 标准库头文件
#include <string>
#include <vector>
#include <optional>
#include <memory>
#include <map>
#include <cstdint>
#include <sstream>

// libonvif_client框架头文件
#include <libonvif_client/xml_convert.h>
#include "libonvif_client/base_types.h"

namespace libonvif_client {

// GetServiceCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_GetServiceCapabilities {
};


// XmlTraits for tev_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<tev_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_Capabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicates that the WS Subscription policy is supported.
    std::optional<bool> WSSubscriptionPolicySupport;
    // Indicates that the WS Pausable Subscription Manager Interface is supported.
    std::optional<bool> WSPausableSubscriptionManagerInterfaceSupport;
    // Maximum number of supported notification producers as defined by WS-BaseNotification.
    std::optional<int32_t> MaxNotificationProducers;
    // Maximum supported number of notification pull points.
    std::optional<int32_t> MaxPullPoints;
    // Indication if the device supports persistent notification storage.
    std::optional<bool> PersistentNotificationStorage;
    // A space separated list of supported event broker protocols as defined by the tev:EventBrokerProtocol datatype.
    std::optional<std::string> EventBrokerProtocols;
    // Maxiumum number of event broker configurations that can be added to the device.
    std::optional<int32_t> MaxEventBrokers;
    // Indicates that metadata streaming over MQTT is supported
    std::optional<bool> MetadataOverMQTT;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tev_Capabilities
template<>
struct xml_convert::XmlTraits<tev_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tev_Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("WSSubscriptionPolicySupport", &tev_Capabilities::WSSubscriptionPolicySupport, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("WSPausableSubscriptionManagerInterfaceSupport", &tev_Capabilities::WSPausableSubscriptionManagerInterfaceSupport, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxNotificationProducers", &tev_Capabilities::MaxNotificationProducers, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxPullPoints", &tev_Capabilities::MaxPullPoints, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("PersistentNotificationStorage", &tev_Capabilities::PersistentNotificationStorage, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("EventBrokerProtocols", &tev_Capabilities::EventBrokerProtocols, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxEventBrokers", &tev_Capabilities::MaxEventBrokers, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MetadataOverMQTT", &tev_Capabilities::MetadataOverMQTT, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tev_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_GetServiceCapabilitiesResponse {
    // The capabilities for the event service is returned in the Capabilities element.
    tev_Capabilities Capabilities;
};


// XmlTraits for tev_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<tev_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &tev_GetServiceCapabilitiesResponse::Capabilities, "tev", xml_convert::serialize_type::full)
    );
};


// SubscriptionPolicy 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_SubscriptionPolicy {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tev_SubscriptionPolicy
template<>
struct xml_convert::XmlTraits<tev_SubscriptionPolicy> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tev_SubscriptionPolicy::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// CreatePullPointSubscription 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_CreatePullPointSubscription {
    // Optional XPATH expression to select specific topics.
    std::optional<wsnt_FilterType> Filter;
    // Initial termination time.
    std::optional<wsnt_AbsoluteOrRelativeTimeType> InitialTerminationTime;
    // Refer to Web Services Base Notification 1.3 (WS-BaseNotification).
    std::optional<tev_SubscriptionPolicy> SubscriptionPolicy;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tev_CreatePullPointSubscription
template<>
struct xml_convert::XmlTraits<tev_CreatePullPointSubscription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Filter", &tev_CreatePullPointSubscription::Filter, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("InitialTerminationTime", &tev_CreatePullPointSubscription::InitialTerminationTime, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SubscriptionPolicy", &tev_CreatePullPointSubscription::SubscriptionPolicy, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tev_CreatePullPointSubscription::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// CreatePullPointSubscriptionResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_CreatePullPointSubscriptionResponse {
    // Endpoint reference of the subscription to be used for pulling the messages.
    wsa_EndpointReferenceType SubscriptionReference;
    // Current time of the server for synchronization purposes.
    wsnt_CurrentTime CurrentTime;
    // Date time when the PullPoint will be shut down without further pull requests.
    wsnt_TerminationTime TerminationTime;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tev_CreatePullPointSubscriptionResponse
template<>
struct xml_convert::XmlTraits<tev_CreatePullPointSubscriptionResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SubscriptionReference", &tev_CreatePullPointSubscriptionResponse::SubscriptionReference, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CurrentTime", &tev_CreatePullPointSubscriptionResponse::CurrentTime, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TerminationTime", &tev_CreatePullPointSubscriptionResponse::TerminationTime, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tev_CreatePullPointSubscriptionResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PullMessages 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_PullMessages {
    // Maximum time to block until this method returns.
    std::string Timeout;
    // Upper limit for the number of messages to return at once. A server implementation may decide to return less messages.
    int32_t MessageLimit {};
    // Collection of any elements from namespace: ##other (processContents: strict)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tev_PullMessages
template<>
struct xml_convert::XmlTraits<tev_PullMessages> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Timeout", &tev_PullMessages::Timeout, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MessageLimit", &tev_PullMessages::MessageLimit, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tev_PullMessages::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PullMessagesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_PullMessagesResponse {
    // The date and time when the messages have been delivered by the web server to the client.
    std::string CurrentTime;
    // Date time when the PullPoint will be shut down without further pull requests.
    std::string TerminationTime;
    // List of messages. This list shall be empty in case of a timeout.
    std::vector<wsnt_NotificationMessage> NotificationMessage;
};


// XmlTraits for tev_PullMessagesResponse
template<>
struct xml_convert::XmlTraits<tev_PullMessagesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CurrentTime", &tev_PullMessagesResponse::CurrentTime, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TerminationTime", &tev_PullMessagesResponse::TerminationTime, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NotificationMessage", &tev_PullMessagesResponse::NotificationMessage, "wsnt", xml_convert::serialize_type::full)
    );
};


// PullMessagesFaultResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_PullMessagesFaultResponse {
    // Maximum timeout supported by the device.
    std::string MaxTimeout;
    // Maximum message limit supported by the device.
    int32_t MaxMessageLimit {};
    // Collection of any elements from namespace: ##other (processContents: strict)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tev_PullMessagesFaultResponse
template<>
struct xml_convert::XmlTraits<tev_PullMessagesFaultResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MaxTimeout", &tev_PullMessagesFaultResponse::MaxTimeout, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxMessageLimit", &tev_PullMessagesFaultResponse::MaxMessageLimit, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tev_PullMessagesFaultResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Seek 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_Seek {
    // The date and time to match against stored messages.
    std::string UtcTime;
    // Reverse the pull direction of PullMessages.
    std::optional<bool> Reverse;
    // Collection of any elements from namespace: ##other (processContents: strict)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tev_Seek
template<>
struct xml_convert::XmlTraits<tev_Seek> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("UtcTime", &tev_Seek::UtcTime, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Reverse", &tev_Seek::Reverse, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tev_Seek::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SeekResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_SeekResponse {
};


// XmlTraits for tev_SeekResponse
template<>
struct xml_convert::XmlTraits<tev_SeekResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetSynchronizationPoint 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_SetSynchronizationPoint {
};


// XmlTraits for tev_SetSynchronizationPoint
template<>
struct xml_convert::XmlTraits<tev_SetSynchronizationPoint> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetSynchronizationPointResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_SetSynchronizationPointResponse {
};


// XmlTraits for tev_SetSynchronizationPointResponse
template<>
struct xml_convert::XmlTraits<tev_SetSynchronizationPointResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetEventProperties 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_GetEventProperties {
};


// XmlTraits for tev_GetEventProperties
template<>
struct xml_convert::XmlTraits<tev_GetEventProperties> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetEventPropertiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_GetEventPropertiesResponse {
    // List of topic namespaces supported.
    std::vector<std::string> TopicNamespaceLocation;
    // True when topicset is fixed for all times.
    wsnt_FixedTopicSet FixedTopicSet;
    // Set of topics supported.
    wstop_TopicSet TopicSet;
    /*
     * Defines the XPath expression syntax supported for matching topic expressions.
     * The following TopicExpressionDialects are mandatory for an ONVIF compliant device :
     *
     * http://docs.oasis-open.org/wsn/t-1/TopicExpression/Concrete
     * http://www.onvif.org/ver10/tev/topicExpression/ConcreteSet.
     */
    std::vector<wsnt_TopicExpressionDialect> TopicExpressionDialect;
    /*
     * Defines the XPath function set supported for message content filtering.
     * The following MessageContentFilterDialects should be returned if a device supports the message content filtering:
     *
     * http://www.onvif.org/ver10/tev/messageContentFilter/ItemFilter.
     *
     * A device that does not support any MessageContentFilterDialect returns a single empty url.
     */
    std::vector<std::string> MessageContentFilterDialect;
    // Optional ProducerPropertiesDialects. Refer to Web Services Base Notification 1.3 (WS-BaseNotification) for advanced filtering.
    std::vector<std::string> ProducerPropertiesFilterDialect;
    /*
     * The Message Content Description Language allows referencing
     * of vendor-specific types. In order to ease the integration of such types into a client application,
     * the GetEventPropertiesResponse shall list all URI locations to schema files whose types are
     * used in the description of notifications, with MessageContentSchemaLocation elements.
     * This list shall at least contain the URI of the ONVIF schema file.
     */
    std::vector<std::string> MessageContentSchemaLocation;
    // Collection of any elements from namespace: ##other (processContents: strict)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tev_GetEventPropertiesResponse
template<>
struct xml_convert::XmlTraits<tev_GetEventPropertiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TopicNamespaceLocation", &tev_GetEventPropertiesResponse::TopicNamespaceLocation, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FixedTopicSet", &tev_GetEventPropertiesResponse::FixedTopicSet, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TopicSet", &tev_GetEventPropertiesResponse::TopicSet, "wstop", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TopicExpressionDialect", &tev_GetEventPropertiesResponse::TopicExpressionDialect, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MessageContentFilterDialect", &tev_GetEventPropertiesResponse::MessageContentFilterDialect, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProducerPropertiesFilterDialect", &tev_GetEventPropertiesResponse::ProducerPropertiesFilterDialect, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MessageContentSchemaLocation", &tev_GetEventPropertiesResponse::MessageContentSchemaLocation, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tev_GetEventPropertiesResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// EventBrokerConfig 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_EventBrokerConfig {
    // Event broker address in the format "scheme://host:port[/resource]". The supported schemes shall be returned by the EventBrokerProtocols capability. The resource part of the URL is only valid when using websocket. The Address must be unique.
    std::string Address;
    // Prefix that will be prepended to all topics before they are published. This is used to make published topics unique for each device. TopicPrefix is not allowed to be empty.
    std::string TopicPrefix;
    // User name for the event broker.
    std::optional<std::string> UserName;
    // Password for the event broker. Password shall not be included when returned with GetEventBrokers.
    std::optional<std::string> Password;
    // Optional certificate ID in the key store pointing to a client certificate to be used for authenticating the device at the message broker.
    std::optional<std::string> CertificateID;
    // Concrete Topic Expression to select specific event topics to publish.
    std::optional<wsnt_FilterType> PublishFilter;
    // Quality of service level to use when publishing. This defines the guarantee of delivery for a specific message: 0 = At most once, 1 = At least once, 2 = Exactly once.
    std::optional<int32_t> QoS;
    // Current connection status (see tev:ConnectionStatus for possible values).
    std::optional<std::string> Status;
    // The ID of the certification path validation policy used to validate the broker certificate. In case encryption is used but no validation policy is specified, the device shall not validate the broker certificate.
    std::optional<std::string> CertPathValidationPolicyID;
    // Concrete Topic Expression to select specific metadata topics to publish.
    std::optional<wsnt_FilterType> MetadataFilter;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tev_EventBrokerConfig
template<>
struct xml_convert::XmlTraits<tev_EventBrokerConfig> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Address", &tev_EventBrokerConfig::Address, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TopicPrefix", &tev_EventBrokerConfig::TopicPrefix, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UserName", &tev_EventBrokerConfig::UserName, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Password", &tev_EventBrokerConfig::Password, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CertificateID", &tev_EventBrokerConfig::CertificateID, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PublishFilter", &tev_EventBrokerConfig::PublishFilter, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("QoS", &tev_EventBrokerConfig::QoS, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Status", &tev_EventBrokerConfig::Status, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CertPathValidationPolicyID", &tev_EventBrokerConfig::CertPathValidationPolicyID, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MetadataFilter", &tev_EventBrokerConfig::MetadataFilter, "tev", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tev_EventBrokerConfig::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tev_EventBrokerConfig::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AddEventBroker 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_AddEventBroker {
    tev_EventBrokerConfig EventBroker;
};


// XmlTraits for tev_AddEventBroker
template<>
struct xml_convert::XmlTraits<tev_AddEventBroker> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("EventBroker", &tev_AddEventBroker::EventBroker, "tev", xml_convert::serialize_type::full)
    );
};


// AddEventBrokerResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_AddEventBrokerResponse {
};


// XmlTraits for tev_AddEventBrokerResponse
template<>
struct xml_convert::XmlTraits<tev_AddEventBrokerResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteEventBroker 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_DeleteEventBroker {
    std::string Address;
};


// XmlTraits for tev_DeleteEventBroker
template<>
struct xml_convert::XmlTraits<tev_DeleteEventBroker> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Address", &tev_DeleteEventBroker::Address, "tev", xml_convert::serialize_type::full)
    );
};


// DeleteEventBrokerResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_DeleteEventBrokerResponse {
};


// XmlTraits for tev_DeleteEventBrokerResponse
template<>
struct xml_convert::XmlTraits<tev_DeleteEventBrokerResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetEventBrokers 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_GetEventBrokers {
    std::optional<std::string> Address;
};


// XmlTraits for tev_GetEventBrokers
template<>
struct xml_convert::XmlTraits<tev_GetEventBrokers> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Address", &tev_GetEventBrokers::Address, "tev", xml_convert::serialize_type::full)
    );
};


// GetEventBrokersResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/events/wsdl
// 源文件: event_v10.wsdl
struct tev_GetEventBrokersResponse {
    std::vector<tev_EventBrokerConfig> EventBroker;
};


// XmlTraits for tev_GetEventBrokersResponse
template<>
struct xml_convert::XmlTraits<tev_GetEventBrokersResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("EventBroker", &tev_GetEventBrokersResponse::EventBroker, "tev", xml_convert::serialize_type::full)
    );
};


// EventBrokerProtocol 枚举类型
// 基础类型: std::string
enum class  tev_EventBrokerProtocol {
    mqtt,
    mqtts,
    ws,
    wss
};

// 字符串转换函数
inline std::string to_string(tev_EventBrokerProtocol value) {
    switch (value) {
        case tev_EventBrokerProtocol::mqtt: return "mqtt";
        case tev_EventBrokerProtocol::mqtts: return "mqtts";
        case tev_EventBrokerProtocol::ws: return "ws";
        case tev_EventBrokerProtocol::wss: return "wss";
        default: return "";
    }
}

inline bool from_string(tev_EventBrokerProtocol& value, const std::string& str) {
    if (str == "mqtt") { value = tev_EventBrokerProtocol::mqtt; return true; }
    if (str == "mqtts") { value = tev_EventBrokerProtocol::mqtts; return true; }
    if (str == "ws") { value = tev_EventBrokerProtocol::ws; return true; }
    if (str == "wss") { value = tev_EventBrokerProtocol::wss; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tev_EventBrokerProtocol
template<>
struct xml_convert::XmlValueAdapter<tev_EventBrokerProtocol> {
    static bool from_xml_val(tev_EventBrokerProtocol& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        xmlNodePtr targetElement = name ? 
            xmlGetChildElementByName(element, name) : element;
        if (!targetElement) return false;
        xmlChar* content = xmlNodeGetContent(targetElement);
        if (!content) return false;
        std::string str_val(reinterpret_cast<char*>(content));
        xmlFree(content);
        return from_string(val, str_val);
    }
    
    static bool to_xml_val(const tev_EventBrokerProtocol& val, xmlNodePtr parent, const char* name,
                           const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;
        xmlNodePtr element = create_element_with_ns(parent, name, ns_prefix, namespaces);
        if (!element) return false;
        xmlNodeSetContent(element, BAD_CAST to_string(val).c_str());
        return true;
    }
    
private:
    static xmlNodePtr create_element_with_ns(xmlNodePtr parent, const char* name, 
                                            const char* ns_prefix, const std::map<std::string_view, std::string_view>& namespaces) {
        xmlNodePtr element = xmlNewChild(parent, nullptr, BAD_CAST name, nullptr);
        if (element && ns_prefix) {
            auto it = namespaces.find(ns_prefix);
            if (it != namespaces.end()) {
                xmlNsPtr ns = xmlNewNs(element, BAD_CAST it->second.data(), BAD_CAST ns_prefix);
                xmlSetNs(element, ns);
            }
        }
        return element;
    }
    
    static xmlNodePtr xmlGetChildElementByName(xmlNodePtr parent, const char* name) {
        if (!parent || !name) return nullptr;
        for (xmlNodePtr child = parent->children; child; child = child->next) {
            if (child->type == XML_ELEMENT_NODE && 
                xmlStrcmp(child->name, BAD_CAST name) == 0) {
                return child;
            }
        }
        return nullptr;
    }
};

// XmlAttributeAdapter specialization for enum tev_EventBrokerProtocol
template<>
struct xml_convert::XmlAttributeAdapter<tev_EventBrokerProtocol> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tev_EventBrokerProtocol& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tev_EventBrokerProtocol& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ConnectionStatus 枚举类型
// 基础类型: std::string
enum class  tev_ConnectionStatus {
    Offline,
    Connecting,
    Connected
};

// 字符串转换函数
inline std::string to_string(tev_ConnectionStatus value) {
    switch (value) {
        case tev_ConnectionStatus::Offline: return "Offline";
        case tev_ConnectionStatus::Connecting: return "Connecting";
        case tev_ConnectionStatus::Connected: return "Connected";
        default: return "";
    }
}

inline bool from_string(tev_ConnectionStatus& value, const std::string& str) {
    if (str == "Offline") { value = tev_ConnectionStatus::Offline; return true; }
    if (str == "Connecting") { value = tev_ConnectionStatus::Connecting; return true; }
    if (str == "Connected") { value = tev_ConnectionStatus::Connected; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tev_ConnectionStatus
template<>
struct xml_convert::XmlValueAdapter<tev_ConnectionStatus> {
    static bool from_xml_val(tev_ConnectionStatus& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        xmlNodePtr targetElement = name ? 
            xmlGetChildElementByName(element, name) : element;
        if (!targetElement) return false;
        xmlChar* content = xmlNodeGetContent(targetElement);
        if (!content) return false;
        std::string str_val(reinterpret_cast<char*>(content));
        xmlFree(content);
        return from_string(val, str_val);
    }
    
    static bool to_xml_val(const tev_ConnectionStatus& val, xmlNodePtr parent, const char* name,
                           const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;
        xmlNodePtr element = create_element_with_ns(parent, name, ns_prefix, namespaces);
        if (!element) return false;
        xmlNodeSetContent(element, BAD_CAST to_string(val).c_str());
        return true;
    }
    
private:
    static xmlNodePtr create_element_with_ns(xmlNodePtr parent, const char* name, 
                                            const char* ns_prefix, const std::map<std::string_view, std::string_view>& namespaces) {
        xmlNodePtr element = xmlNewChild(parent, nullptr, BAD_CAST name, nullptr);
        if (element && ns_prefix) {
            auto it = namespaces.find(ns_prefix);
            if (it != namespaces.end()) {
                xmlNsPtr ns = xmlNewNs(element, BAD_CAST it->second.data(), BAD_CAST ns_prefix);
                xmlSetNs(element, ns);
            }
        }
        return element;
    }
    
    static xmlNodePtr xmlGetChildElementByName(xmlNodePtr parent, const char* name) {
        if (!parent || !name) return nullptr;
        for (xmlNodePtr child = parent->children; child; child = child->next) {
            if (child->type == XML_ELEMENT_NODE && 
                xmlStrcmp(child->name, BAD_CAST name) == 0) {
                return child;
            }
        }
        return nullptr;
    }
};

// XmlAttributeAdapter specialization for enum tev_ConnectionStatus
template<>
struct xml_convert::XmlAttributeAdapter<tev_ConnectionStatus> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tev_ConnectionStatus& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tev_ConnectionStatus& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


} // namespace libonvif_client
