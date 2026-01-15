/**
 * @file trp.h
 * @brief 从 replay_v10.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver10/replay/wsdl
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/common.h>
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
// 命名空间: http://www.onvif.org/ver10/replay/wsdl
// 源文件: replay_v10.wsdl
struct trp_GetServiceCapabilities {
};


// XmlTraits for trp_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<trp_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/replay/wsdl
// 源文件: replay_v10.wsdl
struct trp_Capabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicator that the Device supports reverse playback as defined in the ONVIF Streaming Specification.
    std::optional<bool> ReversePlayback;
    // The list contains two elements defining the minimum and maximum valid values supported as session timeout in seconds.
    std::optional<tt_FloatList> SessionTimeoutRange;
    // Indicates support for RTP/RTSP/TCP.
    std::optional<bool> RTP_RTSP_TCP;
    // If playback streaming over WebSocket is supported, this shall return the RTSP WebSocket URI as described in Streaming Specification Section 5.1.1.5.
    std::optional<std::string> RTSPWebSocketUri;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for trp_Capabilities
template<>
struct xml_convert::XmlTraits<trp_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &trp_Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("ReversePlayback", &trp_Capabilities::ReversePlayback, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SessionTimeoutRange", &trp_Capabilities::SessionTimeoutRange, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RTP_RTSP_TCP", &trp_Capabilities::RTP_RTSP_TCP, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RTSPWebSocketUri", &trp_Capabilities::RTSPWebSocketUri, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &trp_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/replay/wsdl
// 源文件: replay_v10.wsdl
struct trp_GetServiceCapabilitiesResponse {
    // The capabilities for the replay service is returned in the Capabilities element.
    trp_Capabilities Capabilities;
};


// XmlTraits for trp_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<trp_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &trp_GetServiceCapabilitiesResponse::Capabilities, "trp", xml_convert::serialize_type::full)
    );
};


// GetReplayUri 类型定义
// 命名空间: http://www.onvif.org/ver10/replay/wsdl
// 源文件: replay_v10.wsdl
struct trp_GetReplayUri {
    // Specifies the connection parameters to be used for the stream. The URI that is returned may depend on these parameters.
    tt_StreamSetup StreamSetup;
    // The identifier of the recording to be streamed.
    tt_ReferenceToken RecordingToken;
};


// XmlTraits for trp_GetReplayUri
template<>
struct xml_convert::XmlTraits<trp_GetReplayUri> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StreamSetup", &trp_GetReplayUri::StreamSetup, "trp", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RecordingToken", &trp_GetReplayUri::RecordingToken, "trp", xml_convert::serialize_type::full)
    );
};


// GetReplayUriResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/replay/wsdl
// 源文件: replay_v10.wsdl
struct trp_GetReplayUriResponse {
    // The URI to which the client should connect in order to stream the recording.
    std::string Uri;
};


// XmlTraits for trp_GetReplayUriResponse
template<>
struct xml_convert::XmlTraits<trp_GetReplayUriResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Uri", &trp_GetReplayUriResponse::Uri, "trp", xml_convert::serialize_type::full)
    );
};


// SetReplayConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/replay/wsdl
// 源文件: replay_v10.wsdl
struct trp_SetReplayConfiguration {
    // Description of the new replay configuration parameters.
    tt_ReplayConfiguration Configuration;
};


// XmlTraits for trp_SetReplayConfiguration
template<>
struct xml_convert::XmlTraits<trp_SetReplayConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trp_SetReplayConfiguration::Configuration, "trp", xml_convert::serialize_type::full)
    );
};


// SetReplayConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/replay/wsdl
// 源文件: replay_v10.wsdl
struct trp_SetReplayConfigurationResponse {
};


// XmlTraits for trp_SetReplayConfigurationResponse
template<>
struct xml_convert::XmlTraits<trp_SetReplayConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetReplayConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/replay/wsdl
// 源文件: replay_v10.wsdl
struct trp_GetReplayConfiguration {
};


// XmlTraits for trp_GetReplayConfiguration
template<>
struct xml_convert::XmlTraits<trp_GetReplayConfiguration> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetReplayConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/replay/wsdl
// 源文件: replay_v10.wsdl
struct trp_GetReplayConfigurationResponse {
    // The current replay configuration parameters.
    tt_ReplayConfiguration Configuration;
};


// XmlTraits for trp_GetReplayConfigurationResponse
template<>
struct xml_convert::XmlTraits<trp_GetReplayConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trp_GetReplayConfigurationResponse::Configuration, "trp", xml_convert::serialize_type::full)
    );
};


} // namespace libonvif_client
