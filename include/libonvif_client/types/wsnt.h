/**
 * @file wsnt.h
 * @brief 从 b-2.xsd 生成的类型定义
 * @namespace http://docs.oasis-open.org/wsn/b-2
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/wsa.h>
#include <libonvif_client/types/wsrf_bf.h>
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

// QueryExpressionType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_QueryExpressionType {
    // Any element from namespace: ##any (processContents: lax)
    std::optional<AnyElement> _any_;
    std::string Dialect;
};


// XmlTraits for wsnt_QueryExpressionType
template<>
struct xml_convert::XmlTraits<wsnt_QueryExpressionType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_QueryExpressionType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Dialect", &wsnt_QueryExpressionType::Dialect, nullptr, xml_convert::serialize_type::attribute)
    );
};


// TopicExpressionType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_TopicExpressionType {
    // Any element from namespace: ##any (processContents: lax)
    std::optional<AnyElement> _any_;
    std::string Dialect;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsnt_TopicExpressionType
template<>
struct xml_convert::XmlTraits<wsnt_TopicExpressionType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_TopicExpressionType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Dialect", &wsnt_TopicExpressionType::Dialect, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &wsnt_TopicExpressionType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// FilterType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_FilterType {
    // Collection of any elements from namespace: ##any (processContents: strict)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_FilterType
template<>
struct xml_convert::XmlTraits<wsnt_FilterType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_FilterType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SubscriptionPolicyType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_SubscriptionPolicyType {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_SubscriptionPolicyType
template<>
struct xml_convert::XmlTraits<wsnt_SubscriptionPolicyType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_SubscriptionPolicyType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// TopicExpression 类型别名
// 基础类型: wsnt_TopicExpressionType
using wsnt_TopicExpression = wsnt_TopicExpressionType;


// FixedTopicSet 类型别名
// 基础类型: bool
using wsnt_FixedTopicSet = bool;


// TopicExpressionDialect 类型别名
// 基础类型: std::string
using wsnt_TopicExpressionDialect = std::string;


// NotificationProducerRP 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_NotificationProducerRP {
    std::vector<wsnt_TopicExpression> TopicExpression;
    std::optional<wsnt_FixedTopicSet> FixedTopicSet;
    std::vector<wsnt_TopicExpressionDialect> TopicExpressionDialect;
    std::optional<wstop_TopicSet> TopicSet;
};


// XmlTraits for wsnt_NotificationProducerRP
template<>
struct xml_convert::XmlTraits<wsnt_NotificationProducerRP> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TopicExpression", &wsnt_NotificationProducerRP::TopicExpression, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FixedTopicSet", &wsnt_NotificationProducerRP::FixedTopicSet, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TopicExpressionDialect", &wsnt_NotificationProducerRP::TopicExpressionDialect, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TopicSet", &wsnt_NotificationProducerRP::TopicSet, "wstop", xml_convert::serialize_type::full)
    );
};


// ConsumerReference 类型别名
// 基础类型: wsa_EndpointReferenceType
using wsnt_ConsumerReference = wsa_EndpointReferenceType;


// Filter 类型别名
// 基础类型: wsnt_FilterType
using wsnt_Filter = wsnt_FilterType;


// SubscriptionPolicy 类型别名
// 基础类型: wsnt_SubscriptionPolicyType
using wsnt_SubscriptionPolicy = wsnt_SubscriptionPolicyType;


// CreationTime 类型别名
// 基础类型: std::string
using wsnt_CreationTime = std::string;


// SubscriptionManagerRP 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_SubscriptionManagerRP {
    wsnt_ConsumerReference ConsumerReference;
    std::optional<wsnt_Filter> Filter;
    std::optional<wsnt_SubscriptionPolicy> SubscriptionPolicy;
    std::optional<wsnt_CreationTime> CreationTime;
};


// XmlTraits for wsnt_SubscriptionManagerRP
template<>
struct xml_convert::XmlTraits<wsnt_SubscriptionManagerRP> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConsumerReference", &wsnt_SubscriptionManagerRP::ConsumerReference, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Filter", &wsnt_SubscriptionManagerRP::Filter, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SubscriptionPolicy", &wsnt_SubscriptionManagerRP::SubscriptionPolicy, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CreationTime", &wsnt_SubscriptionManagerRP::CreationTime, "wsnt", xml_convert::serialize_type::full)
    );
};


// SubscriptionReference 类型别名
// 基础类型: wsa_EndpointReferenceType
using wsnt_SubscriptionReference = wsa_EndpointReferenceType;


// Topic 类型别名
// 基础类型: wsnt_TopicExpressionType
using wsnt_Topic = wsnt_TopicExpressionType;


// ProducerReference 类型别名
// 基础类型: wsa_EndpointReferenceType
using wsnt_ProducerReference = wsa_EndpointReferenceType;


// Message 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_Message {
    // Any element from namespace: ##any (processContents: lax)
    AnyElement _any_;
};


// XmlTraits for wsnt_Message
template<>
struct xml_convert::XmlTraits<wsnt_Message> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_Message::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// NotificationMessageHolderType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_NotificationMessageHolderType {
    std::optional<wsnt_SubscriptionReference> SubscriptionReference;
    std::optional<wsnt_Topic> Topic;
    std::optional<wsnt_ProducerReference> ProducerReference;
    wsnt_Message Message;
};


// XmlTraits for wsnt_NotificationMessageHolderType
template<>
struct xml_convert::XmlTraits<wsnt_NotificationMessageHolderType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SubscriptionReference", &wsnt_NotificationMessageHolderType::SubscriptionReference, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Topic", &wsnt_NotificationMessageHolderType::Topic, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProducerReference", &wsnt_NotificationMessageHolderType::ProducerReference, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Message", &wsnt_NotificationMessageHolderType::Message, "wsnt", xml_convert::serialize_type::full)
    );
};


// NotificationMessage 类型别名
// 基础类型: wsnt_NotificationMessageHolderType
using wsnt_NotificationMessage = wsnt_NotificationMessageHolderType;


// Notify 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_Notify {
    std::vector<wsnt_NotificationMessage> NotificationMessage;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_Notify
template<>
struct xml_convert::XmlTraits<wsnt_Notify> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NotificationMessage", &wsnt_Notify::NotificationMessage, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wsnt_Notify::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// AbsoluteOrRelativeTimeType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_AbsoluteOrRelativeTimeType {
};


// XmlTraits for wsnt_AbsoluteOrRelativeTimeType
template<>
struct xml_convert::XmlTraits<wsnt_AbsoluteOrRelativeTimeType> {
    static constexpr auto fields = std::make_tuple(

    );
};


// CurrentTime 类型别名
// 基础类型: std::string
using wsnt_CurrentTime = std::string;


// TerminationTime 类型别名
// 基础类型: std::string
using wsnt_TerminationTime = std::string;


// ProducerProperties 类型别名
// 基础类型: wsnt_QueryExpressionType
using wsnt_ProducerProperties = wsnt_QueryExpressionType;


// MessageContent 类型别名
// 基础类型: wsnt_QueryExpressionType
using wsnt_MessageContent = wsnt_QueryExpressionType;


// UseRaw 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_UseRaw {
};


// XmlTraits for wsnt_UseRaw
template<>
struct xml_convert::XmlTraits<wsnt_UseRaw> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Subscribe 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_Subscribe {
    wsa_EndpointReferenceType ConsumerReference;
    std::optional<wsnt_FilterType> Filter;
    std::optional<wsnt_AbsoluteOrRelativeTimeType> InitialTerminationTime;
    std::optional<wsnt_SubscriptionPolicy> SubscriptionPolicy;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_Subscribe
template<>
struct xml_convert::XmlTraits<wsnt_Subscribe> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConsumerReference", &wsnt_Subscribe::ConsumerReference, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Filter", &wsnt_Subscribe::Filter, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("InitialTerminationTime", &wsnt_Subscribe::InitialTerminationTime, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SubscriptionPolicy", &wsnt_Subscribe::SubscriptionPolicy, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wsnt_Subscribe::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SubscribeResponse 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_SubscribeResponse {
    wsa_EndpointReferenceType SubscriptionReference;
    std::optional<wsnt_CurrentTime> CurrentTime;
    std::optional<wsnt_TerminationTime> TerminationTime;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_SubscribeResponse
template<>
struct xml_convert::XmlTraits<wsnt_SubscribeResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SubscriptionReference", &wsnt_SubscribeResponse::SubscriptionReference, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CurrentTime", &wsnt_SubscribeResponse::CurrentTime, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TerminationTime", &wsnt_SubscribeResponse::TerminationTime, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wsnt_SubscribeResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// GetCurrentMessage 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_GetCurrentMessage {
    wsnt_TopicExpressionType Topic;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_GetCurrentMessage
template<>
struct xml_convert::XmlTraits<wsnt_GetCurrentMessage> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Topic", &wsnt_GetCurrentMessage::Topic, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wsnt_GetCurrentMessage::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// GetCurrentMessageResponse 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_GetCurrentMessageResponse {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_GetCurrentMessageResponse
template<>
struct xml_convert::XmlTraits<wsnt_GetCurrentMessageResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_GetCurrentMessageResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SubscribeCreationFailedFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_SubscribeCreationFailedFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_SubscribeCreationFailedFaultType
template<>
struct xml_convert::XmlTraits<wsnt_SubscribeCreationFailedFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// SubscribeCreationFailedFault 类型别名
// 基础类型: wsnt_SubscribeCreationFailedFaultType
using wsnt_SubscribeCreationFailedFault = wsnt_SubscribeCreationFailedFaultType;


// InvalidFilterFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_InvalidFilterFaultType : public wsrf_bf_BaseFaultType {
    std::vector<std::string> UnknownFilter;
};


// XmlTraits for wsnt_InvalidFilterFaultType
template<>
struct xml_convert::XmlTraits<wsnt_InvalidFilterFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
        xml_convert::make_field_desc("UnknownFilter", &wsnt_InvalidFilterFaultType::UnknownFilter, "wsnt", xml_convert::serialize_type::full))
    );
};


// InvalidFilterFault 类型别名
// 基础类型: wsnt_InvalidFilterFaultType
using wsnt_InvalidFilterFault = wsnt_InvalidFilterFaultType;


// TopicExpressionDialectUnknownFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_TopicExpressionDialectUnknownFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_TopicExpressionDialectUnknownFaultType
template<>
struct xml_convert::XmlTraits<wsnt_TopicExpressionDialectUnknownFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// TopicExpressionDialectUnknownFault 类型别名
// 基础类型: wsnt_TopicExpressionDialectUnknownFaultType
using wsnt_TopicExpressionDialectUnknownFault = wsnt_TopicExpressionDialectUnknownFaultType;


// InvalidTopicExpressionFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_InvalidTopicExpressionFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_InvalidTopicExpressionFaultType
template<>
struct xml_convert::XmlTraits<wsnt_InvalidTopicExpressionFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// InvalidTopicExpressionFault 类型别名
// 基础类型: wsnt_InvalidTopicExpressionFaultType
using wsnt_InvalidTopicExpressionFault = wsnt_InvalidTopicExpressionFaultType;


// TopicNotSupportedFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_TopicNotSupportedFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_TopicNotSupportedFaultType
template<>
struct xml_convert::XmlTraits<wsnt_TopicNotSupportedFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// TopicNotSupportedFault 类型别名
// 基础类型: wsnt_TopicNotSupportedFaultType
using wsnt_TopicNotSupportedFault = wsnt_TopicNotSupportedFaultType;


// MultipleTopicsSpecifiedFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_MultipleTopicsSpecifiedFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_MultipleTopicsSpecifiedFaultType
template<>
struct xml_convert::XmlTraits<wsnt_MultipleTopicsSpecifiedFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// MultipleTopicsSpecifiedFault 类型别名
// 基础类型: wsnt_MultipleTopicsSpecifiedFaultType
using wsnt_MultipleTopicsSpecifiedFault = wsnt_MultipleTopicsSpecifiedFaultType;


// InvalidProducerPropertiesExpressionFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_InvalidProducerPropertiesExpressionFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_InvalidProducerPropertiesExpressionFaultType
template<>
struct xml_convert::XmlTraits<wsnt_InvalidProducerPropertiesExpressionFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// InvalidProducerPropertiesExpressionFault 类型别名
// 基础类型: wsnt_InvalidProducerPropertiesExpressionFaultType
using wsnt_InvalidProducerPropertiesExpressionFault = wsnt_InvalidProducerPropertiesExpressionFaultType;


// InvalidMessageContentExpressionFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_InvalidMessageContentExpressionFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_InvalidMessageContentExpressionFaultType
template<>
struct xml_convert::XmlTraits<wsnt_InvalidMessageContentExpressionFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// InvalidMessageContentExpressionFault 类型别名
// 基础类型: wsnt_InvalidMessageContentExpressionFaultType
using wsnt_InvalidMessageContentExpressionFault = wsnt_InvalidMessageContentExpressionFaultType;


// UnrecognizedPolicyRequestFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_UnrecognizedPolicyRequestFaultType : public wsrf_bf_BaseFaultType {
    std::vector<std::string> UnrecognizedPolicy;
};


// XmlTraits for wsnt_UnrecognizedPolicyRequestFaultType
template<>
struct xml_convert::XmlTraits<wsnt_UnrecognizedPolicyRequestFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
        xml_convert::make_field_desc("UnrecognizedPolicy", &wsnt_UnrecognizedPolicyRequestFaultType::UnrecognizedPolicy, "wsnt", xml_convert::serialize_type::full))
    );
};


// UnrecognizedPolicyRequestFault 类型别名
// 基础类型: wsnt_UnrecognizedPolicyRequestFaultType
using wsnt_UnrecognizedPolicyRequestFault = wsnt_UnrecognizedPolicyRequestFaultType;


// UnsupportedPolicyRequestFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_UnsupportedPolicyRequestFaultType : public wsrf_bf_BaseFaultType {
    std::vector<std::string> UnsupportedPolicy;
};


// XmlTraits for wsnt_UnsupportedPolicyRequestFaultType
template<>
struct xml_convert::XmlTraits<wsnt_UnsupportedPolicyRequestFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
        xml_convert::make_field_desc("UnsupportedPolicy", &wsnt_UnsupportedPolicyRequestFaultType::UnsupportedPolicy, "wsnt", xml_convert::serialize_type::full))
    );
};


// UnsupportedPolicyRequestFault 类型别名
// 基础类型: wsnt_UnsupportedPolicyRequestFaultType
using wsnt_UnsupportedPolicyRequestFault = wsnt_UnsupportedPolicyRequestFaultType;


// NotifyMessageNotSupportedFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_NotifyMessageNotSupportedFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_NotifyMessageNotSupportedFaultType
template<>
struct xml_convert::XmlTraits<wsnt_NotifyMessageNotSupportedFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// NotifyMessageNotSupportedFault 类型别名
// 基础类型: wsnt_NotifyMessageNotSupportedFaultType
using wsnt_NotifyMessageNotSupportedFault = wsnt_NotifyMessageNotSupportedFaultType;


// UnacceptableInitialTerminationTimeFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_UnacceptableInitialTerminationTimeFaultType : public wsrf_bf_BaseFaultType {
    std::string MinimumTime;
    std::optional<std::string> MaximumTime;
};


// XmlTraits for wsnt_UnacceptableInitialTerminationTimeFaultType
template<>
struct xml_convert::XmlTraits<wsnt_UnacceptableInitialTerminationTimeFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
        xml_convert::make_field_desc("MinimumTime", &wsnt_UnacceptableInitialTerminationTimeFaultType::MinimumTime, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaximumTime", &wsnt_UnacceptableInitialTerminationTimeFaultType::MaximumTime, "wsnt", xml_convert::serialize_type::full))
    );
};


// UnacceptableInitialTerminationTimeFault 类型别名
// 基础类型: wsnt_UnacceptableInitialTerminationTimeFaultType
using wsnt_UnacceptableInitialTerminationTimeFault = wsnt_UnacceptableInitialTerminationTimeFaultType;


// NoCurrentMessageOnTopicFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_NoCurrentMessageOnTopicFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_NoCurrentMessageOnTopicFaultType
template<>
struct xml_convert::XmlTraits<wsnt_NoCurrentMessageOnTopicFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// NoCurrentMessageOnTopicFault 类型别名
// 基础类型: wsnt_NoCurrentMessageOnTopicFaultType
using wsnt_NoCurrentMessageOnTopicFault = wsnt_NoCurrentMessageOnTopicFaultType;


// GetMessages 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_GetMessages {
    std::optional<uint64_t> MaximumNumber;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsnt_GetMessages
template<>
struct xml_convert::XmlTraits<wsnt_GetMessages> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MaximumNumber", &wsnt_GetMessages::MaximumNumber, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wsnt_GetMessages::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &wsnt_GetMessages::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetMessagesResponse 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_GetMessagesResponse {
    std::vector<wsnt_NotificationMessage> NotificationMessage;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsnt_GetMessagesResponse
template<>
struct xml_convert::XmlTraits<wsnt_GetMessagesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NotificationMessage", &wsnt_GetMessagesResponse::NotificationMessage, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wsnt_GetMessagesResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &wsnt_GetMessagesResponse::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// DestroyPullPoint 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_DestroyPullPoint {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsnt_DestroyPullPoint
template<>
struct xml_convert::XmlTraits<wsnt_DestroyPullPoint> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_DestroyPullPoint::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &wsnt_DestroyPullPoint::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// DestroyPullPointResponse 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_DestroyPullPointResponse {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsnt_DestroyPullPointResponse
template<>
struct xml_convert::XmlTraits<wsnt_DestroyPullPointResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_DestroyPullPointResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &wsnt_DestroyPullPointResponse::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// UnableToGetMessagesFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_UnableToGetMessagesFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_UnableToGetMessagesFaultType
template<>
struct xml_convert::XmlTraits<wsnt_UnableToGetMessagesFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// UnableToGetMessagesFault 类型别名
// 基础类型: wsnt_UnableToGetMessagesFaultType
using wsnt_UnableToGetMessagesFault = wsnt_UnableToGetMessagesFaultType;


// UnableToDestroyPullPointFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_UnableToDestroyPullPointFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_UnableToDestroyPullPointFaultType
template<>
struct xml_convert::XmlTraits<wsnt_UnableToDestroyPullPointFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// UnableToDestroyPullPointFault 类型别名
// 基础类型: wsnt_UnableToDestroyPullPointFaultType
using wsnt_UnableToDestroyPullPointFault = wsnt_UnableToDestroyPullPointFaultType;


// CreatePullPoint 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_CreatePullPoint {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsnt_CreatePullPoint
template<>
struct xml_convert::XmlTraits<wsnt_CreatePullPoint> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_CreatePullPoint::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &wsnt_CreatePullPoint::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CreatePullPointResponse 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_CreatePullPointResponse {
    wsa_EndpointReferenceType PullPoint;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsnt_CreatePullPointResponse
template<>
struct xml_convert::XmlTraits<wsnt_CreatePullPointResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PullPoint", &wsnt_CreatePullPointResponse::PullPoint, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wsnt_CreatePullPointResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &wsnt_CreatePullPointResponse::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// UnableToCreatePullPointFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_UnableToCreatePullPointFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_UnableToCreatePullPointFaultType
template<>
struct xml_convert::XmlTraits<wsnt_UnableToCreatePullPointFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// UnableToCreatePullPointFault 类型别名
// 基础类型: wsnt_UnableToCreatePullPointFaultType
using wsnt_UnableToCreatePullPointFault = wsnt_UnableToCreatePullPointFaultType;


// Renew 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_Renew {
    wsnt_AbsoluteOrRelativeTimeType TerminationTime;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_Renew
template<>
struct xml_convert::XmlTraits<wsnt_Renew> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TerminationTime", &wsnt_Renew::TerminationTime, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wsnt_Renew::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// RenewResponse 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_RenewResponse {
    wsnt_TerminationTime TerminationTime;
    std::optional<wsnt_CurrentTime> CurrentTime;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_RenewResponse
template<>
struct xml_convert::XmlTraits<wsnt_RenewResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TerminationTime", &wsnt_RenewResponse::TerminationTime, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CurrentTime", &wsnt_RenewResponse::CurrentTime, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wsnt_RenewResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// UnacceptableTerminationTimeFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_UnacceptableTerminationTimeFaultType : public wsrf_bf_BaseFaultType {
    std::string MinimumTime;
    std::optional<std::string> MaximumTime;
};


// XmlTraits for wsnt_UnacceptableTerminationTimeFaultType
template<>
struct xml_convert::XmlTraits<wsnt_UnacceptableTerminationTimeFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
        xml_convert::make_field_desc("MinimumTime", &wsnt_UnacceptableTerminationTimeFaultType::MinimumTime, "wsnt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaximumTime", &wsnt_UnacceptableTerminationTimeFaultType::MaximumTime, "wsnt", xml_convert::serialize_type::full))
    );
};


// UnacceptableTerminationTimeFault 类型别名
// 基础类型: wsnt_UnacceptableTerminationTimeFaultType
using wsnt_UnacceptableTerminationTimeFault = wsnt_UnacceptableTerminationTimeFaultType;


// Unsubscribe 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_Unsubscribe {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_Unsubscribe
template<>
struct xml_convert::XmlTraits<wsnt_Unsubscribe> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_Unsubscribe::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// UnsubscribeResponse 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_UnsubscribeResponse {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_UnsubscribeResponse
template<>
struct xml_convert::XmlTraits<wsnt_UnsubscribeResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_UnsubscribeResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// UnableToDestroySubscriptionFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_UnableToDestroySubscriptionFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_UnableToDestroySubscriptionFaultType
template<>
struct xml_convert::XmlTraits<wsnt_UnableToDestroySubscriptionFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// UnableToDestroySubscriptionFault 类型别名
// 基础类型: wsnt_UnableToDestroySubscriptionFaultType
using wsnt_UnableToDestroySubscriptionFault = wsnt_UnableToDestroySubscriptionFaultType;


// PauseSubscription 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_PauseSubscription {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_PauseSubscription
template<>
struct xml_convert::XmlTraits<wsnt_PauseSubscription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_PauseSubscription::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PauseSubscriptionResponse 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_PauseSubscriptionResponse {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_PauseSubscriptionResponse
template<>
struct xml_convert::XmlTraits<wsnt_PauseSubscriptionResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_PauseSubscriptionResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ResumeSubscription 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_ResumeSubscription {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_ResumeSubscription
template<>
struct xml_convert::XmlTraits<wsnt_ResumeSubscription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_ResumeSubscription::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ResumeSubscriptionResponse 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_ResumeSubscriptionResponse {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wsnt_ResumeSubscriptionResponse
template<>
struct xml_convert::XmlTraits<wsnt_ResumeSubscriptionResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsnt_ResumeSubscriptionResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PauseFailedFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_PauseFailedFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_PauseFailedFaultType
template<>
struct xml_convert::XmlTraits<wsnt_PauseFailedFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// PauseFailedFault 类型别名
// 基础类型: wsnt_PauseFailedFaultType
using wsnt_PauseFailedFault = wsnt_PauseFailedFaultType;


// ResumeFailedFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/b-2
// 源文件: b-2.xsd
struct wsnt_ResumeFailedFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsnt_ResumeFailedFaultType
template<>
struct xml_convert::XmlTraits<wsnt_ResumeFailedFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// ResumeFailedFault 类型别名
// 基础类型: wsnt_ResumeFailedFaultType
using wsnt_ResumeFailedFault = wsnt_ResumeFailedFaultType;


} // namespace libonvif_client
