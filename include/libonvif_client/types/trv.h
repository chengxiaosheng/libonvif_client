/**
 * @file trv.h
 * @brief 从 receiver_v10.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver10/receiver/wsdl
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/common.h>
#include <libonvif_client/types/tr2.h>
#include <libonvif_client/types/tt.h>

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
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_GetServiceCapabilities {
};


// XmlTraits for trv_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<trv_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_Capabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicates that the device can receive RTP multicast streams.
    std::optional<bool> RTP_Multicast;
    // Indicates that the device can receive RTP/TCP streams
    std::optional<bool> RTP_TCP;
    // Indicates that the device can receive RTP/RTSP/TCP streams.
    std::optional<bool> RTP_RTSP_TCP;
    // The maximum number of receivers supported by the device.
    int32_t SupportedReceivers {};
    // The maximum allowed length for RTSP URIs (Minimum and default value is 128 octet).
    std::optional<int32_t> MaximumRTSPURILength;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for trv_Capabilities
template<>
struct xml_convert::XmlTraits<trv_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &trv_Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("RTP_Multicast", &trv_Capabilities::RTP_Multicast, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RTP_TCP", &trv_Capabilities::RTP_TCP, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RTP_RTSP_TCP", &trv_Capabilities::RTP_RTSP_TCP, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SupportedReceivers", &trv_Capabilities::SupportedReceivers, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaximumRTSPURILength", &trv_Capabilities::MaximumRTSPURILength, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &trv_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_GetServiceCapabilitiesResponse {
    // The capabilities for the receiver service is returned in the Capabilities element.
    trv_Capabilities Capabilities;
};


// XmlTraits for trv_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<trv_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &trv_GetServiceCapabilitiesResponse::Capabilities, "trv", xml_convert::serialize_type::full)
    );
};


// GetReceivers 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_GetReceivers {
};


// XmlTraits for trv_GetReceivers
template<>
struct xml_convert::XmlTraits<trv_GetReceivers> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetReceiversResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_GetReceiversResponse {
    // A list of all receivers that currently exist on the device.
    std::vector<tt_Receiver> Receivers;
};


// XmlTraits for trv_GetReceiversResponse
template<>
struct xml_convert::XmlTraits<trv_GetReceiversResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Receivers", &trv_GetReceiversResponse::Receivers, "trv", xml_convert::serialize_type::full)
    );
};


// GetReceiver 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_GetReceiver {
    // The token of the receiver to be retrieved.
    tt_ReferenceToken ReceiverToken;
};


// XmlTraits for trv_GetReceiver
template<>
struct xml_convert::XmlTraits<trv_GetReceiver> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ReceiverToken", &trv_GetReceiver::ReceiverToken, "trv", xml_convert::serialize_type::full)
    );
};


// GetReceiverResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_GetReceiverResponse {
    // The details of the receiver.
    tt_Receiver Receiver;
};


// XmlTraits for trv_GetReceiverResponse
template<>
struct xml_convert::XmlTraits<trv_GetReceiverResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Receiver", &trv_GetReceiverResponse::Receiver, "trv", xml_convert::serialize_type::full)
    );
};


// CreateReceiver 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_CreateReceiver {
    // The initial configuration for the new receiver.
    tt_ReceiverConfiguration Configuration;
};


// XmlTraits for trv_CreateReceiver
template<>
struct xml_convert::XmlTraits<trv_CreateReceiver> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trv_CreateReceiver::Configuration, "trv", xml_convert::serialize_type::full)
    );
};


// CreateReceiverResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_CreateReceiverResponse {
    // The details of the receiver that was created.
    tt_Receiver Receiver;
};


// XmlTraits for trv_CreateReceiverResponse
template<>
struct xml_convert::XmlTraits<trv_CreateReceiverResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Receiver", &trv_CreateReceiverResponse::Receiver, "trv", xml_convert::serialize_type::full)
    );
};


// DeleteReceiver 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_DeleteReceiver {
    // The token of the receiver to be deleted.
    tt_ReferenceToken ReceiverToken;
};


// XmlTraits for trv_DeleteReceiver
template<>
struct xml_convert::XmlTraits<trv_DeleteReceiver> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ReceiverToken", &trv_DeleteReceiver::ReceiverToken, "trv", xml_convert::serialize_type::full)
    );
};


// DeleteReceiverResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_DeleteReceiverResponse {
};


// XmlTraits for trv_DeleteReceiverResponse
template<>
struct xml_convert::XmlTraits<trv_DeleteReceiverResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// ConfigureReceiver 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_ConfigureReceiver {
    // The token of the receiver to be configured.
    tt_ReferenceToken ReceiverToken;
    // The new configuration for the receiver.
    tt_ReceiverConfiguration Configuration;
};


// XmlTraits for trv_ConfigureReceiver
template<>
struct xml_convert::XmlTraits<trv_ConfigureReceiver> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ReceiverToken", &trv_ConfigureReceiver::ReceiverToken, "trv", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configuration", &trv_ConfigureReceiver::Configuration, "trv", xml_convert::serialize_type::full)
    );
};


// ConfigureReceiverResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_ConfigureReceiverResponse {
};


// XmlTraits for trv_ConfigureReceiverResponse
template<>
struct xml_convert::XmlTraits<trv_ConfigureReceiverResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetReceiverMode 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_SetReceiverMode {
    // The token of the receiver to be changed.
    tt_ReferenceToken ReceiverToken;
    // The new receiver mode. Options available are:
    tt_ReceiverMode Mode;
};


// XmlTraits for trv_SetReceiverMode
template<>
struct xml_convert::XmlTraits<trv_SetReceiverMode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ReceiverToken", &trv_SetReceiverMode::ReceiverToken, "trv", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mode", &trv_SetReceiverMode::Mode, "trv", xml_convert::serialize_type::full)
    );
};


// SetReceiverModeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_SetReceiverModeResponse {
};


// XmlTraits for trv_SetReceiverModeResponse
template<>
struct xml_convert::XmlTraits<trv_SetReceiverModeResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetReceiverState 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_GetReceiverState {
    // The token of the receiver to be queried.
    tt_ReferenceToken ReceiverToken;
};


// XmlTraits for trv_GetReceiverState
template<>
struct xml_convert::XmlTraits<trv_GetReceiverState> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ReceiverToken", &trv_GetReceiverState::ReceiverToken, "trv", xml_convert::serialize_type::full)
    );
};


// GetReceiverStateResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/receiver/wsdl
// 源文件: receiver_v10.wsdl
struct trv_GetReceiverStateResponse {
    // Description of the current receiver state.
    tt_ReceiverStateInformation ReceiverState;
};


// XmlTraits for trv_GetReceiverStateResponse
template<>
struct xml_convert::XmlTraits<trv_GetReceiverStateResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ReceiverState", &trv_GetReceiverStateResponse::ReceiverState, "trv", xml_convert::serialize_type::full)
    );
};


} // namespace libonvif_client
