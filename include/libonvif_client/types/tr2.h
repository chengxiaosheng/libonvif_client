/**
 * @file tr2.h
 * @brief 从 media_v20.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver20/media/wsdl
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

// 前置声明（循环依赖的类型）
struct tr2_ReceiverConfiguration;

// GetServiceCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetServiceCapabilities {
};


// XmlTraits for tr2_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<tr2_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// ProfileCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_ProfileCapabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Maximum number of profiles supported.
    std::optional<int32_t> MaximumNumberOfProfiles;
    // The configurations supported by the device as defined by tr2:ConfigurationEnumeration. The enumeration value "All" shall not be included in this list.
    std::optional<tt_StringAttrList> ConfigurationsSupported;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_ProfileCapabilities
template<>
struct xml_convert::XmlTraits<tr2_ProfileCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tr2_ProfileCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("MaximumNumberOfProfiles", &tr2_ProfileCapabilities::MaximumNumberOfProfiles, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("ConfigurationsSupported", &tr2_ProfileCapabilities::ConfigurationsSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_ProfileCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// StreamingCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_StreamingCapabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicates support for live media streaming via RTSP.
    std::optional<bool> RTSPStreaming;
    // Indicates support for RTP multicast.
    std::optional<bool> RTPMulticast;
    // Indicates support for RTP/RTSP/TCP.
    std::optional<bool> RTP_RTSP_TCP;
    // Indicates support for non aggregate RTSP control.
    std::optional<bool> NonAggregateControl;
    // If streaming over WebSocket is supported, this shall return the RTSP WebSocket URI as described in Streaming Specification Section 5.1.1.5.
    std::optional<std::string> RTSPWebSocketUri;
    // Indicates support for non-RTSP controlled multicast streaming.
    std::optional<bool> AutoStartMulticast;
    // Indicates support for live media streaming via RTSPS and SRTP.
    std::optional<bool> SecureRTSPStreaming;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_StreamingCapabilities
template<>
struct xml_convert::XmlTraits<tr2_StreamingCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tr2_StreamingCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("RTSPStreaming", &tr2_StreamingCapabilities::RTSPStreaming, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RTPMulticast", &tr2_StreamingCapabilities::RTPMulticast, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RTP_RTSP_TCP", &tr2_StreamingCapabilities::RTP_RTSP_TCP, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("NonAggregateControl", &tr2_StreamingCapabilities::NonAggregateControl, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RTSPWebSocketUri", &tr2_StreamingCapabilities::RTSPWebSocketUri, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AutoStartMulticast", &tr2_StreamingCapabilities::AutoStartMulticast, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SecureRTSPStreaming", &tr2_StreamingCapabilities::SecureRTSPStreaming, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_StreamingCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MediaSigningCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_MediaSigningCapabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicates whether the device supports signing of media according to the Media Signing Specification.
    std::optional<bool> MediaSigningSupported;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_MediaSigningCapabilities
template<>
struct xml_convert::XmlTraits<tr2_MediaSigningCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tr2_MediaSigningCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("MediaSigningSupported", &tr2_MediaSigningCapabilities::MediaSigningSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_MediaSigningCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioClipCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_AudioClipCapabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicates the maximum number of audio clips that can be uploaded to the device.
    std::optional<int32_t> MaxAudioClipLimit;
    // Indicates the maximum size of the audio clip that can be uploaded, in KB.
    std::optional<float> MaxAudioClipSize;
    // Enumerates the supported audio clip formats. See tr2: SupportedAudioClipFormat.
    std::optional<tt_StringAttrList> SupportedAudioClipFormat;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_AudioClipCapabilities
template<>
struct xml_convert::XmlTraits<tr2_AudioClipCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tr2_AudioClipCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("MaxAudioClipLimit", &tr2_AudioClipCapabilities::MaxAudioClipLimit, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxAudioClipSize", &tr2_AudioClipCapabilities::MaxAudioClipSize, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SupportedAudioClipFormat", &tr2_AudioClipCapabilities::SupportedAudioClipFormat, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_AudioClipCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MulticastAudioDecoderCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_MulticastAudioDecoderCapabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicates support for multicast audio decoder.
    std::optional<bool> MulticastAudioDecoder;
    // Indicates whether the SRTP is supported in MulticastAudioDecoder or not.
    std::optional<bool> SRTP;
    // Indicates whether the IPv6 is supported in MulticastAudioDecoder or not.
    std::optional<bool> IPv6;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_MulticastAudioDecoderCapabilities
template<>
struct xml_convert::XmlTraits<tr2_MulticastAudioDecoderCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tr2_MulticastAudioDecoderCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("MulticastAudioDecoder", &tr2_MulticastAudioDecoderCapabilities::MulticastAudioDecoder, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SRTP", &tr2_MulticastAudioDecoderCapabilities::SRTP, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("IPv6", &tr2_MulticastAudioDecoderCapabilities::IPv6, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_MulticastAudioDecoderCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Capabilities2 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_Capabilities2 {
    // Media profile capabilities.
    tr2_ProfileCapabilities ProfileCapabilities;
    // Streaming capabilities.
    tr2_StreamingCapabilities StreamingCapabilities;
    // Media signing capabilities.
    std::optional<tr2_MediaSigningCapabilities> MediaSigningCapabilities;
    // Audio clip capabilities.
    std::optional<tr2_AudioClipCapabilities> AudioClipCapabilities;
    // MulticastAudioDecoder capabilities.
    std::optional<tr2_MulticastAudioDecoderCapabilities> MulticastAudioDecoderCapabilities;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicates if GetSnapshotUri is supported.
    std::optional<bool> SnapshotUri;
    // Indicates whether or not Rotation feature is supported.
    std::optional<bool> Rotation;
    // Indicates the support for changing video source mode.
    std::optional<bool> VideoSourceMode;
    // Indicates if OSD is supported.
    std::optional<bool> OSD;
    // Indicates the support for temporary osd text configuration.
    std::optional<bool> TemporaryOSDText;
    // Indicates if Masking is supported.
    std::optional<bool> Mask;
    /*
     * Indicates that privacy masks are only supported at the video source level and not the video source configuration level.
     * If this is true any addition, deletion or change of a privacy mask done for one video source configuration will automatically be
     * applied by the device to a corresponding privacy mask for all other video source configuration associated with the same video source.
     */
    std::optional<bool> SourceMask;
    // Indicates number of supported WebRTC configurations.
    std::optional<int32_t> WebRTC;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_Capabilities2
template<>
struct xml_convert::XmlTraits<tr2_Capabilities2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileCapabilities", &tr2_Capabilities2::ProfileCapabilities, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StreamingCapabilities", &tr2_Capabilities2::StreamingCapabilities, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MediaSigningCapabilities", &tr2_Capabilities2::MediaSigningCapabilities, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioClipCapabilities", &tr2_Capabilities2::AudioClipCapabilities, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MulticastAudioDecoderCapabilities", &tr2_Capabilities2::MulticastAudioDecoderCapabilities, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tr2_Capabilities2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("SnapshotUri", &tr2_Capabilities2::SnapshotUri, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Rotation", &tr2_Capabilities2::Rotation, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("VideoSourceMode", &tr2_Capabilities2::VideoSourceMode, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("OSD", &tr2_Capabilities2::OSD, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("TemporaryOSDText", &tr2_Capabilities2::TemporaryOSDText, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Mask", &tr2_Capabilities2::Mask, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SourceMask", &tr2_Capabilities2::SourceMask, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("WebRTC", &tr2_Capabilities2::WebRTC, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_Capabilities2::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetServiceCapabilitiesResponse {
    // The capabilities for the media service is returned in the Capabilities element.
    tr2_Capabilities2 Capabilities;
};


// XmlTraits for tr2_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<tr2_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &tr2_GetServiceCapabilitiesResponse::Capabilities, "tr2", xml_convert::serialize_type::full)
    );
};


// Capabilities 类型别名
// 基础类型: tr2_Capabilities2
using tr2_Capabilities = tr2_Capabilities2;


// SupportedAudioClipFormat 枚举类型
// 基础类型: std::string
enum class  tr2_SupportedAudioClipFormat {
    audio_vnd_wave_codec_1, // audio/vnd.wave;codec=1
    audio_vnd_wave_codec_7, // audio/vnd.wave;codec=7
    audio_mpeg, // audio/mpeg
    audio_ogg_codecs_opus, // audio/ogg;codecs=opus
    audio_ogg_codecs_vorbis, // audio/ogg;codecs=vorbis
    audio_ogg_codecs_flac, // audio/ogg;codecs=flac
    audio_ogg_codecs_speex // audio/ogg;codecs=speex
};

// 字符串转换函数
inline std::string to_string(tr2_SupportedAudioClipFormat value) {
    switch (value) {
        case tr2_SupportedAudioClipFormat::audio_vnd_wave_codec_1: return "audio/vnd.wave;codec=1";
        case tr2_SupportedAudioClipFormat::audio_vnd_wave_codec_7: return "audio/vnd.wave;codec=7";
        case tr2_SupportedAudioClipFormat::audio_mpeg: return "audio/mpeg";
        case tr2_SupportedAudioClipFormat::audio_ogg_codecs_opus: return "audio/ogg;codecs=opus";
        case tr2_SupportedAudioClipFormat::audio_ogg_codecs_vorbis: return "audio/ogg;codecs=vorbis";
        case tr2_SupportedAudioClipFormat::audio_ogg_codecs_flac: return "audio/ogg;codecs=flac";
        case tr2_SupportedAudioClipFormat::audio_ogg_codecs_speex: return "audio/ogg;codecs=speex";
        default: return "";
    }
}

inline bool from_string(tr2_SupportedAudioClipFormat& value, const std::string& str) {
    if (str == "audio/vnd.wave;codec=1") { value = tr2_SupportedAudioClipFormat::audio_vnd_wave_codec_1; return true; }
    if (str == "audio/vnd.wave;codec=7") { value = tr2_SupportedAudioClipFormat::audio_vnd_wave_codec_7; return true; }
    if (str == "audio/mpeg") { value = tr2_SupportedAudioClipFormat::audio_mpeg; return true; }
    if (str == "audio/ogg;codecs=opus") { value = tr2_SupportedAudioClipFormat::audio_ogg_codecs_opus; return true; }
    if (str == "audio/ogg;codecs=vorbis") { value = tr2_SupportedAudioClipFormat::audio_ogg_codecs_vorbis; return true; }
    if (str == "audio/ogg;codecs=flac") { value = tr2_SupportedAudioClipFormat::audio_ogg_codecs_flac; return true; }
    if (str == "audio/ogg;codecs=speex") { value = tr2_SupportedAudioClipFormat::audio_ogg_codecs_speex; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tr2_SupportedAudioClipFormat
template<>
struct xml_convert::XmlValueAdapter<tr2_SupportedAudioClipFormat> {
    static bool from_xml_val(tr2_SupportedAudioClipFormat& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tr2_SupportedAudioClipFormat& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tr2_SupportedAudioClipFormat
template<>
struct xml_convert::XmlAttributeAdapter<tr2_SupportedAudioClipFormat> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tr2_SupportedAudioClipFormat& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tr2_SupportedAudioClipFormat& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ConfigurationEnumeration 枚举类型
// 基础类型: std::string
enum class  tr2_ConfigurationEnumeration {
    All,
    VideoSource,
    VideoEncoder,
    AudioSource,
    AudioEncoder,
    AudioOutput,
    AudioDecoder,
    Metadata,
    Analytics,
    PTZ,
    Receiver
};

// 字符串转换函数
inline std::string to_string(tr2_ConfigurationEnumeration value) {
    switch (value) {
        case tr2_ConfigurationEnumeration::All: return "All";
        case tr2_ConfigurationEnumeration::VideoSource: return "VideoSource";
        case tr2_ConfigurationEnumeration::VideoEncoder: return "VideoEncoder";
        case tr2_ConfigurationEnumeration::AudioSource: return "AudioSource";
        case tr2_ConfigurationEnumeration::AudioEncoder: return "AudioEncoder";
        case tr2_ConfigurationEnumeration::AudioOutput: return "AudioOutput";
        case tr2_ConfigurationEnumeration::AudioDecoder: return "AudioDecoder";
        case tr2_ConfigurationEnumeration::Metadata: return "Metadata";
        case tr2_ConfigurationEnumeration::Analytics: return "Analytics";
        case tr2_ConfigurationEnumeration::PTZ: return "PTZ";
        case tr2_ConfigurationEnumeration::Receiver: return "Receiver";
        default: return "";
    }
}

inline bool from_string(tr2_ConfigurationEnumeration& value, const std::string& str) {
    if (str == "All") { value = tr2_ConfigurationEnumeration::All; return true; }
    if (str == "VideoSource") { value = tr2_ConfigurationEnumeration::VideoSource; return true; }
    if (str == "VideoEncoder") { value = tr2_ConfigurationEnumeration::VideoEncoder; return true; }
    if (str == "AudioSource") { value = tr2_ConfigurationEnumeration::AudioSource; return true; }
    if (str == "AudioEncoder") { value = tr2_ConfigurationEnumeration::AudioEncoder; return true; }
    if (str == "AudioOutput") { value = tr2_ConfigurationEnumeration::AudioOutput; return true; }
    if (str == "AudioDecoder") { value = tr2_ConfigurationEnumeration::AudioDecoder; return true; }
    if (str == "Metadata") { value = tr2_ConfigurationEnumeration::Metadata; return true; }
    if (str == "Analytics") { value = tr2_ConfigurationEnumeration::Analytics; return true; }
    if (str == "PTZ") { value = tr2_ConfigurationEnumeration::PTZ; return true; }
    if (str == "Receiver") { value = tr2_ConfigurationEnumeration::Receiver; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tr2_ConfigurationEnumeration
template<>
struct xml_convert::XmlValueAdapter<tr2_ConfigurationEnumeration> {
    static bool from_xml_val(tr2_ConfigurationEnumeration& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tr2_ConfigurationEnumeration& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tr2_ConfigurationEnumeration
template<>
struct xml_convert::XmlAttributeAdapter<tr2_ConfigurationEnumeration> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tr2_ConfigurationEnumeration& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tr2_ConfigurationEnumeration& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ConfigurationRef 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_ConfigurationRef {
    // Type of the configuration as defined by tr2:ConfigurationEnumeration.
    std::string Type;
    /*
     * Reference token of an existing configuration.
     * Token shall be included in the AddConfiguration request along with the type.
     * Token shall be included in the CreateProfile request when Configuration elements are included and type is selected.
     * Token is optional for RemoveConfiguration request. If no token is provided in RemoveConfiguration request, device shall
     * remove the configuration of the type included in the profile.
     */
    std::optional<tt_ReferenceToken> Token;
};


// XmlTraits for tr2_ConfigurationRef
template<>
struct xml_convert::XmlTraits<tr2_ConfigurationRef> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tr2_ConfigurationRef::Type, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Token", &tr2_ConfigurationRef::Token, "tr2", xml_convert::serialize_type::full)
    );
};


// ReceiverConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_ReceiverConfiguration : public tt_ReceiverConfiguration {
    std::optional<tt_ReferenceToken> token;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_ReceiverConfiguration
template<>
struct xml_convert::XmlTraits<tr2_ReceiverConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ReceiverConfiguration>::fields, std::make_tuple(
        xml_convert::make_field_desc("token", &tr2_ReceiverConfiguration::token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_ReceiverConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// ConfigurationSet 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_ConfigurationSet {
    // Optional configuration of the Video input.
    std::optional<tt_VideoSourceConfiguration> VideoSource;
    // Optional configuration of the Audio input.
    std::optional<tt_AudioSourceConfiguration> AudioSource;
    // Optional configuration of the Video encoder.
    std::optional<tt_VideoEncoder2Configuration> VideoEncoder;
    // Optional configuration of the Audio encoder.
    std::optional<tt_AudioEncoder2Configuration> AudioEncoder;
    // Optional configuration of the analytics module and rule engine.
    std::optional<tt_VideoAnalyticsConfiguration> Analytics;
    // Optional configuration of the pan tilt zoom unit.
    std::optional<tt_PTZConfiguration> PTZ;
    // Optional configuration of the metadata stream.
    std::optional<tt_MetadataConfiguration> Metadata;
    // Optional configuration of the Audio output.
    std::optional<tt_AudioOutputConfiguration> AudioOutput;
    // Optional configuration of the Audio decoder.
    std::optional<tt_AudioDecoderConfiguration> AudioDecoder;
    // Optional configuration of the Receiver.
    std::optional<tr2_ReceiverConfiguration> Receiver;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_ConfigurationSet
template<>
struct xml_convert::XmlTraits<tr2_ConfigurationSet> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSource", &tr2_ConfigurationSet::VideoSource, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioSource", &tr2_ConfigurationSet::AudioSource, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoEncoder", &tr2_ConfigurationSet::VideoEncoder, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioEncoder", &tr2_ConfigurationSet::AudioEncoder, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Analytics", &tr2_ConfigurationSet::Analytics, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PTZ", &tr2_ConfigurationSet::PTZ, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Metadata", &tr2_ConfigurationSet::Metadata, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioOutput", &tr2_ConfigurationSet::AudioOutput, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioDecoder", &tr2_ConfigurationSet::AudioDecoder, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Receiver", &tr2_ConfigurationSet::Receiver, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tr2_ConfigurationSet::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tr2_ConfigurationSet::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MediaProfile 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_MediaProfile {
    // User readable name of the profile.
    tt_Name Name;
    // The configurations assigned to the profile.
    std::optional<tr2_ConfigurationSet> Configurations;
    // Unique identifier of the profile.
    tt_ReferenceToken token;
    // A value of true signals that the profile cannot be deleted. Default is false.
    std::optional<bool> fixed;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_MediaProfile
template<>
struct xml_convert::XmlTraits<tr2_MediaProfile> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tr2_MediaProfile::Name, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configurations", &tr2_MediaProfile::Configurations, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("token", &tr2_MediaProfile::token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("fixed", &tr2_MediaProfile::fixed, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_MediaProfile::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CreateProfile 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_CreateProfile {
    // friendly name of the profile to be created
    tt_Name Name;
    // Optional set of configurations to be assigned to the profile. List entries with tr2:ConfigurationEnumeration value "All" shall be ignored.
    std::vector<tr2_ConfigurationRef> Configuration;
};


// XmlTraits for tr2_CreateProfile
template<>
struct xml_convert::XmlTraits<tr2_CreateProfile> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tr2_CreateProfile::Name, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configuration", &tr2_CreateProfile::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// CreateProfileResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_CreateProfileResponse {
    // Token assigned by the device for the newly created profile.
    tt_ReferenceToken Token;
};


// XmlTraits for tr2_CreateProfileResponse
template<>
struct xml_convert::XmlTraits<tr2_CreateProfileResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_CreateProfileResponse::Token, "tr2", xml_convert::serialize_type::full)
    );
};


// GetProfiles 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetProfiles {
    // Optional token of the requested profile.
    std::optional<tt_ReferenceToken> Token;
    // The types shall be provided as defined by tr2:ConfigurationEnumeration.
    std::vector<std::string> Type;
};


// XmlTraits for tr2_GetProfiles
template<>
struct xml_convert::XmlTraits<tr2_GetProfiles> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_GetProfiles::Token, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Type", &tr2_GetProfiles::Type, "tr2", xml_convert::serialize_type::full)
    );
};


// GetProfilesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetProfilesResponse {
    /*
     * Lists all profiles that exist in the media service. The response provides the requested types of Configurations as far as available.
     * If a profile doesn't contain a type no error shall be provided.
     */
    std::vector<tr2_MediaProfile> Profiles;
};


// XmlTraits for tr2_GetProfilesResponse
template<>
struct xml_convert::XmlTraits<tr2_GetProfilesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Profiles", &tr2_GetProfilesResponse::Profiles, "tr2", xml_convert::serialize_type::full)
    );
};


// AddConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_AddConfiguration {
    // Reference to the profile where the configuration should be added
    tt_ReferenceToken ProfileToken;
    // Optional item. If present updates the Name property of the profile.
    std::optional<tt_Name> Name;
    // List of configurations to be added. The types shall be provided in the order defined by tr2:ConfigurationEnumeration. List entries with tr2:ConfigurationEnumeration value "All" shall be ignored.
    std::vector<tr2_ConfigurationRef> Configuration;
};


// XmlTraits for tr2_AddConfiguration
template<>
struct xml_convert::XmlTraits<tr2_AddConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tr2_AddConfiguration::ProfileToken, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Name", &tr2_AddConfiguration::Name, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configuration", &tr2_AddConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// AddConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_AddConfigurationResponse {
};


// XmlTraits for tr2_AddConfigurationResponse
template<>
struct xml_convert::XmlTraits<tr2_AddConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_RemoveConfiguration {
    // This element contains a  reference to the media profile from which the configuration shall be removed.
    tt_ReferenceToken ProfileToken;
    // List of configurations to be removed. The types shall be provided in the order defined by tr2:ConfigurationEnumeration. Tokens appearing in the configuration list shall be ignored. Presence of the "All" type shall result in an empty profile.
    std::vector<tr2_ConfigurationRef> Configuration;
};


// XmlTraits for tr2_RemoveConfiguration
template<>
struct xml_convert::XmlTraits<tr2_RemoveConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tr2_RemoveConfiguration::ProfileToken, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configuration", &tr2_RemoveConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// RemoveConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_RemoveConfigurationResponse {
};


// XmlTraits for tr2_RemoveConfigurationResponse
template<>
struct xml_convert::XmlTraits<tr2_RemoveConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteProfile 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_DeleteProfile {
    // This element contains a  reference to the profile that should be deleted.
    tt_ReferenceToken Token;
};


// XmlTraits for tr2_DeleteProfile
template<>
struct xml_convert::XmlTraits<tr2_DeleteProfile> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_DeleteProfile::Token, "tr2", xml_convert::serialize_type::full)
    );
};


// DeleteProfileResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_DeleteProfileResponse {
};


// XmlTraits for tr2_DeleteProfileResponse
template<>
struct xml_convert::XmlTraits<tr2_DeleteProfileResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetConfiguration {
    // Token of the requested configuration.
    std::optional<tt_ReferenceToken> ConfigurationToken;
    // Contains the token of an existing media profile the configurations shall be compatible with.
    std::optional<tt_ReferenceToken> ProfileToken;
};


// XmlTraits for tr2_GetConfiguration
template<>
struct xml_convert::XmlTraits<tr2_GetConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tr2_GetConfiguration::ConfigurationToken, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProfileToken", &tr2_GetConfiguration::ProfileToken, "tr2", xml_convert::serialize_type::full)
    );
};


// GetVideoEncoderConfigurations 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetVideoEncoderConfigurations = tr2_GetConfiguration;


// GetVideoEncoderConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetVideoEncoderConfigurationsResponse {
    // This element contains a list of video encoder configurations.
    std::vector<tt_VideoEncoder2Configuration> Configurations;
};


// XmlTraits for tr2_GetVideoEncoderConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetVideoEncoderConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &tr2_GetVideoEncoderConfigurationsResponse::Configurations, "tr2", xml_convert::serialize_type::full)
    );
};


// GetVideoSourceConfigurations 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetVideoSourceConfigurations = tr2_GetConfiguration;


// GetVideoSourceConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetVideoSourceConfigurationsResponse {
    // This element contains a list of video source configurations.
    std::vector<tt_VideoSourceConfiguration> Configurations;
};


// XmlTraits for tr2_GetVideoSourceConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetVideoSourceConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &tr2_GetVideoSourceConfigurationsResponse::Configurations, "tr2", xml_convert::serialize_type::full)
    );
};


// GetAudioEncoderConfigurations 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetAudioEncoderConfigurations = tr2_GetConfiguration;


// GetAudioEncoderConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioEncoderConfigurationsResponse {
    // This element contains a list of audio encoder configurations.
    std::vector<tt_AudioEncoder2Configuration> Configurations;
};


// XmlTraits for tr2_GetAudioEncoderConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetAudioEncoderConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &tr2_GetAudioEncoderConfigurationsResponse::Configurations, "tr2", xml_convert::serialize_type::full)
    );
};


// GetAudioSourceConfigurations 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetAudioSourceConfigurations = tr2_GetConfiguration;


// GetAudioSourceConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioSourceConfigurationsResponse {
    // This element contains a list of audio source configurations.
    std::vector<tt_AudioSourceConfiguration> Configurations;
};


// XmlTraits for tr2_GetAudioSourceConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetAudioSourceConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &tr2_GetAudioSourceConfigurationsResponse::Configurations, "tr2", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsConfigurations 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetAnalyticsConfigurations = tr2_GetConfiguration;


// GetAnalyticsConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAnalyticsConfigurationsResponse {
    // This element contains a list of Analytics configurations.
    std::vector<tt_VideoAnalyticsConfiguration> Configurations;
};


// XmlTraits for tr2_GetAnalyticsConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetAnalyticsConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &tr2_GetAnalyticsConfigurationsResponse::Configurations, "tr2", xml_convert::serialize_type::full)
    );
};


// GetMetadataConfigurations 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetMetadataConfigurations = tr2_GetConfiguration;


// GetMetadataConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetMetadataConfigurationsResponse {
    // This element contains a list of metadata configurations
    std::vector<tt_MetadataConfiguration> Configurations;
};


// XmlTraits for tr2_GetMetadataConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetMetadataConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &tr2_GetMetadataConfigurationsResponse::Configurations, "tr2", xml_convert::serialize_type::full)
    );
};


// GetAudioOutputConfigurations 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetAudioOutputConfigurations = tr2_GetConfiguration;


// GetAudioOutputConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioOutputConfigurationsResponse {
    // This element contains a list of audio output configurations
    std::vector<tt_AudioOutputConfiguration> Configurations;
};


// XmlTraits for tr2_GetAudioOutputConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetAudioOutputConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &tr2_GetAudioOutputConfigurationsResponse::Configurations, "tr2", xml_convert::serialize_type::full)
    );
};


// GetAudioDecoderConfigurations 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetAudioDecoderConfigurations = tr2_GetConfiguration;


// GetAudioDecoderConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioDecoderConfigurationsResponse {
    // This element contains a list of audio decoder configurations
    std::vector<tt_AudioDecoderConfiguration> Configurations;
};


// XmlTraits for tr2_GetAudioDecoderConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetAudioDecoderConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &tr2_GetAudioDecoderConfigurationsResponse::Configurations, "tr2", xml_convert::serialize_type::full)
    );
};


// SetVideoEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetVideoEncoderConfiguration {
    // Contains the modified video encoder configuration. The configuration shall exist in the device.
    tt_VideoEncoder2Configuration Configuration;
};


// XmlTraits for tr2_SetVideoEncoderConfiguration
template<>
struct xml_convert::XmlTraits<tr2_SetVideoEncoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tr2_SetVideoEncoderConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetConfigurationResponse {
};


// XmlTraits for tr2_SetConfigurationResponse
template<>
struct xml_convert::XmlTraits<tr2_SetConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetVideoEncoderConfigurationResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetVideoEncoderConfigurationResponse = tr2_SetConfigurationResponse;


// SetVideoSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetVideoSourceConfiguration {
    // Contains the modified video source configuration. The configuration shall exist in the device.
    tt_VideoSourceConfiguration Configuration;
};


// XmlTraits for tr2_SetVideoSourceConfiguration
template<>
struct xml_convert::XmlTraits<tr2_SetVideoSourceConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tr2_SetVideoSourceConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetVideoSourceConfigurationResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetVideoSourceConfigurationResponse = tr2_SetConfigurationResponse;


// SetAudioEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetAudioEncoderConfiguration {
    // Contains the modified audio encoder configuration. The configuration shall exist in the device.
    tt_AudioEncoder2Configuration Configuration;
};


// XmlTraits for tr2_SetAudioEncoderConfiguration
template<>
struct xml_convert::XmlTraits<tr2_SetAudioEncoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tr2_SetAudioEncoderConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetAudioEncoderConfigurationResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetAudioEncoderConfigurationResponse = tr2_SetConfigurationResponse;


// SetAudioSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetAudioSourceConfiguration {
    // Contains the modified audio source configuration. The configuration shall exist in the device.
    tt_AudioSourceConfiguration Configuration;
};


// XmlTraits for tr2_SetAudioSourceConfiguration
template<>
struct xml_convert::XmlTraits<tr2_SetAudioSourceConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tr2_SetAudioSourceConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetAudioSourceConfigurationResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetAudioSourceConfigurationResponse = tr2_SetConfigurationResponse;


// SetMetadataConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetMetadataConfiguration {
    // Contains the modified metadata configuration. The configuration shall exist in the device.
    tt_MetadataConfiguration Configuration;
};


// XmlTraits for tr2_SetMetadataConfiguration
template<>
struct xml_convert::XmlTraits<tr2_SetMetadataConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tr2_SetMetadataConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetMetadataConfigurationResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetMetadataConfigurationResponse = tr2_SetConfigurationResponse;


// SetAudioOutputConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetAudioOutputConfiguration {
    // Contains the modified audio output configuration. The configuration shall exist in the device.
    tt_AudioOutputConfiguration Configuration;
};


// XmlTraits for tr2_SetAudioOutputConfiguration
template<>
struct xml_convert::XmlTraits<tr2_SetAudioOutputConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tr2_SetAudioOutputConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetAudioOutputConfigurationResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetAudioOutputConfigurationResponse = tr2_SetConfigurationResponse;


// SetAudioDecoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetAudioDecoderConfiguration {
    // Contains the modified audio decoder configuration. The configuration shall exist in the device.
    tt_AudioDecoderConfiguration Configuration;
};


// XmlTraits for tr2_SetAudioDecoderConfiguration
template<>
struct xml_convert::XmlTraits<tr2_SetAudioDecoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tr2_SetAudioDecoderConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetAudioDecoderConfigurationResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetAudioDecoderConfigurationResponse = tr2_SetConfigurationResponse;


// SetEQPresetConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetEQPresetConfiguration {
    // Contains the modified EQ Preset configuration.
    tt_EQPreset Configuration;
};


// XmlTraits for tr2_SetEQPresetConfiguration
template<>
struct xml_convert::XmlTraits<tr2_SetEQPresetConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tr2_SetEQPresetConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetEQPresetConfigurationResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetEQPresetConfigurationResponse = tr2_SetConfigurationResponse;


// GetVideoSourceConfigurationOptions 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetVideoSourceConfigurationOptions = tr2_GetConfiguration;


// GetVideoSourceConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetVideoSourceConfigurationOptionsResponse {
    // This message contains the video source configuration options. If a video source configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    tt_VideoSourceConfigurationOptions Options;
};


// XmlTraits for tr2_GetVideoSourceConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetVideoSourceConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tr2_GetVideoSourceConfigurationOptionsResponse::Options, "tr2", xml_convert::serialize_type::full)
    );
};


// GetVideoEncoderConfigurationOptions 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetVideoEncoderConfigurationOptions = tr2_GetConfiguration;


// GetVideoEncoderConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetVideoEncoderConfigurationOptionsResponse {
    std::vector<tt_VideoEncoder2ConfigurationOptions> Options;
};


// XmlTraits for tr2_GetVideoEncoderConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetVideoEncoderConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tr2_GetVideoEncoderConfigurationOptionsResponse::Options, "tr2", xml_convert::serialize_type::full)
    );
};


// GetAudioSourceConfigurationOptions 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetAudioSourceConfigurationOptions = tr2_GetConfiguration;


// GetAudioSourceConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioSourceConfigurationOptionsResponse {
    // This message contains the audio source configuration options. If a audio source configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    tt_AudioSourceConfigurationOptions Options;
};


// XmlTraits for tr2_GetAudioSourceConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetAudioSourceConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tr2_GetAudioSourceConfigurationOptionsResponse::Options, "tr2", xml_convert::serialize_type::full)
    );
};


// GetAudioEncoderConfigurationOptions 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetAudioEncoderConfigurationOptions = tr2_GetConfiguration;


// GetAudioEncoderConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioEncoderConfigurationOptionsResponse {
    // This message contains the audio encoder configuration options. If a audio encoder configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    std::vector<tt_AudioEncoder2ConfigurationOptions> Options;
};


// XmlTraits for tr2_GetAudioEncoderConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetAudioEncoderConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tr2_GetAudioEncoderConfigurationOptionsResponse::Options, "tr2", xml_convert::serialize_type::full)
    );
};


// GetMetadataConfigurationOptions 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetMetadataConfigurationOptions = tr2_GetConfiguration;


// GetMetadataConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetMetadataConfigurationOptionsResponse {
    // This message contains the metadata configuration options. If a metadata configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    tt_MetadataConfigurationOptions Options;
};


// XmlTraits for tr2_GetMetadataConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetMetadataConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tr2_GetMetadataConfigurationOptionsResponse::Options, "tr2", xml_convert::serialize_type::full)
    );
};


// GetAudioOutputConfigurationOptions 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetAudioOutputConfigurationOptions = tr2_GetConfiguration;


// GetAudioOutputConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioOutputConfigurationOptionsResponse {
    // This message contains the audio output configuration options. If a audio output configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    tt_AudioOutputConfigurationOptions Options;
};


// XmlTraits for tr2_GetAudioOutputConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetAudioOutputConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tr2_GetAudioOutputConfigurationOptionsResponse::Options, "tr2", xml_convert::serialize_type::full)
    );
};


// GetAudioDecoderConfigurationOptions 类型别名
// 基础类型: tr2_GetConfiguration
using tr2_GetAudioDecoderConfigurationOptions = tr2_GetConfiguration;


// GetAudioDecoderConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioDecoderConfigurationOptionsResponse {
    // This message contains the audio decoder configuration options. If a audio decoder configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    std::vector<tt_AudioEncoder2ConfigurationOptions> Options;
};


// XmlTraits for tr2_GetAudioDecoderConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetAudioDecoderConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tr2_GetAudioDecoderConfigurationOptionsResponse::Options, "tr2", xml_convert::serialize_type::full)
    );
};


// TransportProtocol 枚举类型
// 基础类型: std::string
enum class  tr2_TransportProtocol {
    RtspUnicast,
    RtspMulticast,
    RtspsUnicast,
    RtspsMulticast,
    RTSP,
    RtspOverHttp
};

// 字符串转换函数
inline std::string to_string(tr2_TransportProtocol value) {
    switch (value) {
        case tr2_TransportProtocol::RtspUnicast: return "RtspUnicast";
        case tr2_TransportProtocol::RtspMulticast: return "RtspMulticast";
        case tr2_TransportProtocol::RtspsUnicast: return "RtspsUnicast";
        case tr2_TransportProtocol::RtspsMulticast: return "RtspsMulticast";
        case tr2_TransportProtocol::RTSP: return "RTSP";
        case tr2_TransportProtocol::RtspOverHttp: return "RtspOverHttp";
        default: return "";
    }
}

inline bool from_string(tr2_TransportProtocol& value, const std::string& str) {
    if (str == "RtspUnicast") { value = tr2_TransportProtocol::RtspUnicast; return true; }
    if (str == "RtspMulticast") { value = tr2_TransportProtocol::RtspMulticast; return true; }
    if (str == "RtspsUnicast") { value = tr2_TransportProtocol::RtspsUnicast; return true; }
    if (str == "RtspsMulticast") { value = tr2_TransportProtocol::RtspsMulticast; return true; }
    if (str == "RTSP") { value = tr2_TransportProtocol::RTSP; return true; }
    if (str == "RtspOverHttp") { value = tr2_TransportProtocol::RtspOverHttp; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tr2_TransportProtocol
template<>
struct xml_convert::XmlValueAdapter<tr2_TransportProtocol> {
    static bool from_xml_val(tr2_TransportProtocol& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tr2_TransportProtocol& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tr2_TransportProtocol
template<>
struct xml_convert::XmlAttributeAdapter<tr2_TransportProtocol> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tr2_TransportProtocol& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tr2_TransportProtocol& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// GetVideoEncoderInstances 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetVideoEncoderInstances {
    // Token of the video source configuration
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tr2_GetVideoEncoderInstances
template<>
struct xml_convert::XmlTraits<tr2_GetVideoEncoderInstances> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tr2_GetVideoEncoderInstances::ConfigurationToken, "tr2", xml_convert::serialize_type::full)
    );
};


// EncoderInstance 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_EncoderInstance {
    // Video Media Subtype for the video format. For definitions see tt:VideoEncodingMimeNames and  IANA Media Types.
    std::string Encoding;
    // The minimum guaranteed number of encoder instances (applications) for the VideoSourceConfiguration.
    int32_t Number {};
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_EncoderInstance
template<>
struct xml_convert::XmlTraits<tr2_EncoderInstance> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Encoding", &tr2_EncoderInstance::Encoding, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Number", &tr2_EncoderInstance::Number, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tr2_EncoderInstance::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// EncoderInstanceInfo 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_EncoderInstanceInfo {
    // If a device limits the number of instances for respective Video Codecs the response contains the information how many streams can be set up at the same time per VideoSource.
    std::vector<tr2_EncoderInstance> Codec;
    // The minimum guaranteed total number of encoder instances (applications) per VideoSourceConfiguration. The device is able to deliver the Total number of streams
    int32_t Total {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_EncoderInstanceInfo
template<>
struct xml_convert::XmlTraits<tr2_EncoderInstanceInfo> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Codec", &tr2_EncoderInstanceInfo::Codec, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Total", &tr2_EncoderInstanceInfo::Total, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tr2_EncoderInstanceInfo::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tr2_EncoderInstanceInfo::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetVideoEncoderInstancesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetVideoEncoderInstancesResponse {
    // The minimum guaranteed total number of encoder instances (applications) per VideoSourceConfiguration.
    tr2_EncoderInstanceInfo Info;
};


// XmlTraits for tr2_GetVideoEncoderInstancesResponse
template<>
struct xml_convert::XmlTraits<tr2_GetVideoEncoderInstancesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Info", &tr2_GetVideoEncoderInstancesResponse::Info, "tr2", xml_convert::serialize_type::full)
    );
};


// GetStreamUri 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetStreamUri {
    // Defines the network protocol for streaming as defined by tr2:TransportProtocol
    std::string Protocol;
    // The ProfileToken element indicates the media profile to use and will define the configuration of the content of the stream.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for tr2_GetStreamUri
template<>
struct xml_convert::XmlTraits<tr2_GetStreamUri> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Protocol", &tr2_GetStreamUri::Protocol, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProfileToken", &tr2_GetStreamUri::ProfileToken, "tr2", xml_convert::serialize_type::full)
    );
};


// GetStreamUriResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetStreamUriResponse {
    // Stable Uri to be used for requesting the media stream
    std::string Uri;
};


// XmlTraits for tr2_GetStreamUriResponse
template<>
struct xml_convert::XmlTraits<tr2_GetStreamUriResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Uri", &tr2_GetStreamUriResponse::Uri, "tr2", xml_convert::serialize_type::full)
    );
};


// SetSynchronizationPoint 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetSynchronizationPoint {
    // Contains a Profile reference for which a Synchronization Point is requested.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for tr2_SetSynchronizationPoint
template<>
struct xml_convert::XmlTraits<tr2_SetSynchronizationPoint> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tr2_SetSynchronizationPoint::ProfileToken, "tr2", xml_convert::serialize_type::full)
    );
};


// SetSynchronizationPointResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetSynchronizationPointResponse {
};


// XmlTraits for tr2_SetSynchronizationPointResponse
template<>
struct xml_convert::XmlTraits<tr2_SetSynchronizationPointResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetSnapshotUri 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetSnapshotUri {
    // The ProfileToken element indicates the media profile to use and will define the source and dimensions of the snapshot.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for tr2_GetSnapshotUri
template<>
struct xml_convert::XmlTraits<tr2_GetSnapshotUri> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tr2_GetSnapshotUri::ProfileToken, "tr2", xml_convert::serialize_type::full)
    );
};


// GetSnapshotUriResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetSnapshotUriResponse {
    // Stable Uri to be used for requesting snapshot images.
    std::string Uri;
};


// XmlTraits for tr2_GetSnapshotUriResponse
template<>
struct xml_convert::XmlTraits<tr2_GetSnapshotUriResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Uri", &tr2_GetSnapshotUriResponse::Uri, "tr2", xml_convert::serialize_type::full)
    );
};


// StartStopMulticastStreaming 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_StartStopMulticastStreaming {
    // Contains the token of the Profile that is used to define the multicast stream.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for tr2_StartStopMulticastStreaming
template<>
struct xml_convert::XmlTraits<tr2_StartStopMulticastStreaming> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tr2_StartStopMulticastStreaming::ProfileToken, "tr2", xml_convert::serialize_type::full)
    );
};


// StartMulticastStreaming 类型别名
// 基础类型: tr2_StartStopMulticastStreaming
using tr2_StartMulticastStreaming = tr2_StartStopMulticastStreaming;


// StartMulticastStreamingResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_StartMulticastStreamingResponse = tr2_SetConfigurationResponse;


// StopMulticastStreaming 类型别名
// 基础类型: tr2_StartStopMulticastStreaming
using tr2_StopMulticastStreaming = tr2_StartStopMulticastStreaming;


// StopMulticastStreamingResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_StopMulticastStreamingResponse = tr2_SetConfigurationResponse;


// GetVideoSourceModes 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetVideoSourceModes {
    // Contains a video source reference for which a video source mode is requested.
    tt_ReferenceToken VideoSourceToken;
};


// XmlTraits for tr2_GetVideoSourceModes
template<>
struct xml_convert::XmlTraits<tr2_GetVideoSourceModes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &tr2_GetVideoSourceModes::VideoSourceToken, "tr2", xml_convert::serialize_type::full)
    );
};


// VideoSourceMode 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_VideoSourceMode {
    // Max frame rate in frames per second for this video source mode.
    float MaxFramerate {};
    // Max horizontal and vertical resolution for this video source mode.
    tt_VideoResolution MaxResolution;
    // List of one or more encodings supported for this video source.  For name definitions see tt:VideoEncodingMimeNames, and see IANA Media Types.
    tt_StringList Encodings;
    // After setting the mode if a device starts to reboot this value is true. If a device change the mode without rebooting this value is false. If true, configured parameters may not be guaranteed by the device after rebooting.
    bool Reboot {};
    // Informative description of this video source mode. This field should be described in English.
    std::optional<tt_Description> Description;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicate token for video source mode.
    tt_ReferenceToken token;
    // Indication of whether this mode is active. If active this value is true. In case of non-indication, it means as false. The value of true shall be had by only one video source mode.
    std::optional<bool> Enabled;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_VideoSourceMode
template<>
struct xml_convert::XmlTraits<tr2_VideoSourceMode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MaxFramerate", &tr2_VideoSourceMode::MaxFramerate, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxResolution", &tr2_VideoSourceMode::MaxResolution, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Encodings", &tr2_VideoSourceMode::Encodings, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Reboot", &tr2_VideoSourceMode::Reboot, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Description", &tr2_VideoSourceMode::Description, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tr2_VideoSourceMode::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("token", &tr2_VideoSourceMode::token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Enabled", &tr2_VideoSourceMode::Enabled, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_VideoSourceMode::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetVideoSourceModesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetVideoSourceModesResponse {
    // Return the information for specified video source mode.
    std::vector<tr2_VideoSourceMode> VideoSourceModes;
};


// XmlTraits for tr2_GetVideoSourceModesResponse
template<>
struct xml_convert::XmlTraits<tr2_GetVideoSourceModesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceModes", &tr2_GetVideoSourceModesResponse::VideoSourceModes, "tr2", xml_convert::serialize_type::full)
    );
};


// SetVideoSourceMode 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetVideoSourceMode {
    // Contains a video source reference for which a video source mode is requested.
    tt_ReferenceToken VideoSourceToken;
    // Indicate video source mode.
    tt_ReferenceToken VideoSourceModeToken;
};


// XmlTraits for tr2_SetVideoSourceMode
template<>
struct xml_convert::XmlTraits<tr2_SetVideoSourceMode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &tr2_SetVideoSourceMode::VideoSourceToken, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoSourceModeToken", &tr2_SetVideoSourceMode::VideoSourceModeToken, "tr2", xml_convert::serialize_type::full)
    );
};


// SetVideoSourceModeResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetVideoSourceModeResponse {
    // The response contains information about rebooting after returning response. When Reboot is set true, a device will reboot automatically after setting mode.
    bool Reboot {};
};


// XmlTraits for tr2_SetVideoSourceModeResponse
template<>
struct xml_convert::XmlTraits<tr2_SetVideoSourceModeResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Reboot", &tr2_SetVideoSourceModeResponse::Reboot, "tr2", xml_convert::serialize_type::full)
    );
};


// GetOSDs 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetOSDs {
    // The GetOSDs command fetches the OSD configuration if the OSD token is known.
    std::optional<tt_ReferenceToken> OSDToken;
    // Token of the Video Source Configuration, which has OSDs associated with are requested. If token not exist, request all available OSDs.
    std::optional<tt_ReferenceToken> ConfigurationToken;
};


// XmlTraits for tr2_GetOSDs
template<>
struct xml_convert::XmlTraits<tr2_GetOSDs> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSDToken", &tr2_GetOSDs::OSDToken, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &tr2_GetOSDs::ConfigurationToken, "tr2", xml_convert::serialize_type::full)
    );
};


// GetOSDsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetOSDsResponse {
    // This element contains a list of requested OSDs.
    std::vector<tt_OSDConfiguration> OSDs;
};


// XmlTraits for tr2_GetOSDsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetOSDsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSDs", &tr2_GetOSDsResponse::OSDs, "tr2", xml_convert::serialize_type::full)
    );
};


// SetOSD 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetOSD {
    // Contains the modified OSD configuration.
    tt_OSDConfiguration OSD;
};


// XmlTraits for tr2_SetOSD
template<>
struct xml_convert::XmlTraits<tr2_SetOSD> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSD", &tr2_SetOSD::OSD, "tr2", xml_convert::serialize_type::full)
    );
};


// SetOSDResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetOSDResponse = tr2_SetConfigurationResponse;


// GetOSDOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetOSDOptions {
    // Video Source Configuration Token that specifies an existing video source configuration that the options shall be compatible with.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tr2_GetOSDOptions
template<>
struct xml_convert::XmlTraits<tr2_GetOSDOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tr2_GetOSDOptions::ConfigurationToken, "tr2", xml_convert::serialize_type::full)
    );
};


// GetOSDOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetOSDOptionsResponse {
    tt_OSDConfigurationOptions OSDOptions;
};


// XmlTraits for tr2_GetOSDOptionsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetOSDOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSDOptions", &tr2_GetOSDOptionsResponse::OSDOptions, "tr2", xml_convert::serialize_type::full)
    );
};


// CreateOSD 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_CreateOSD {
    // Contain the initial OSD configuration for create.
    tt_OSDConfiguration OSD;
};


// XmlTraits for tr2_CreateOSD
template<>
struct xml_convert::XmlTraits<tr2_CreateOSD> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSD", &tr2_CreateOSD::OSD, "tr2", xml_convert::serialize_type::full)
    );
};


// CreateOSDResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_CreateOSDResponse {
    // Returns Token of the newly created OSD
    tt_ReferenceToken OSDToken;
};


// XmlTraits for tr2_CreateOSDResponse
template<>
struct xml_convert::XmlTraits<tr2_CreateOSDResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSDToken", &tr2_CreateOSDResponse::OSDToken, "tr2", xml_convert::serialize_type::full)
    );
};


// DeleteOSD 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_DeleteOSD {
    // This element contains a reference to the OSD configuration that should be deleted.
    tt_ReferenceToken OSDToken;
};


// XmlTraits for tr2_DeleteOSD
template<>
struct xml_convert::XmlTraits<tr2_DeleteOSD> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSDToken", &tr2_DeleteOSD::OSDToken, "tr2", xml_convert::serialize_type::full)
    );
};


// DeleteOSDResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_DeleteOSDResponse = tr2_SetConfigurationResponse;


// MaskType 枚举类型
// 基础类型: std::string
enum class  tr2_MaskType {
    Color,
    Pixelated,
    Blurred
};

// 字符串转换函数
inline std::string to_string(tr2_MaskType value) {
    switch (value) {
        case tr2_MaskType::Color: return "Color";
        case tr2_MaskType::Pixelated: return "Pixelated";
        case tr2_MaskType::Blurred: return "Blurred";
        default: return "";
    }
}

inline bool from_string(tr2_MaskType& value, const std::string& str) {
    if (str == "Color") { value = tr2_MaskType::Color; return true; }
    if (str == "Pixelated") { value = tr2_MaskType::Pixelated; return true; }
    if (str == "Blurred") { value = tr2_MaskType::Blurred; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tr2_MaskType
template<>
struct xml_convert::XmlValueAdapter<tr2_MaskType> {
    static bool from_xml_val(tr2_MaskType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tr2_MaskType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tr2_MaskType
template<>
struct xml_convert::XmlAttributeAdapter<tr2_MaskType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tr2_MaskType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tr2_MaskType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Mask 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_Mask {
    // Token of the VideoSourceConfiguration the Mask is associated with.
    tt_ReferenceToken ConfigurationToken;
    // Geometric representation of the mask area.
    tt_Polygon Polygon;
    /*
     * Type of masking as defined by tr2:MaskType:
     *
     * Color - The masked area is colored with color defined by the Color field.
     * Pixelated - The masked area is filled in mosaic style to hide details.
     * Blurred - The masked area is low pass filtered to hide details.
     */
    std::string Type;
    // Color of the masked area.
    std::optional<tt_Color> Color;
    // If set the mask will cover the image, otherwise it will be fully transparent.
    bool Enabled {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Token of the mask.
    std::optional<tt_ReferenceToken> token;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_Mask
template<>
struct xml_convert::XmlTraits<tr2_Mask> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tr2_Mask::ConfigurationToken, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Polygon", &tr2_Mask::Polygon, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Type", &tr2_Mask::Type, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &tr2_Mask::Color, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Enabled", &tr2_Mask::Enabled, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tr2_Mask::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("token", &tr2_Mask::token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_Mask::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetMasks 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetMasks {
    // Optional mask token of an existing mask.
    std::optional<tt_ReferenceToken> Token;
    // Optional token of a Video Source Configuration.
    std::optional<tt_ReferenceToken> ConfigurationToken;
};


// XmlTraits for tr2_GetMasks
template<>
struct xml_convert::XmlTraits<tr2_GetMasks> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_GetMasks::Token, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &tr2_GetMasks::ConfigurationToken, "tr2", xml_convert::serialize_type::full)
    );
};


// GetMasksResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetMasksResponse {
    // List of Mask configurations.
    std::vector<tr2_Mask> Masks;
};


// XmlTraits for tr2_GetMasksResponse
template<>
struct xml_convert::XmlTraits<tr2_GetMasksResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Masks", &tr2_GetMasksResponse::Masks, "tr2", xml_convert::serialize_type::full)
    );
};


// SetMask 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetMask {
    // Mask to be updated.
    tr2_Mask Mask;
};


// XmlTraits for tr2_SetMask
template<>
struct xml_convert::XmlTraits<tr2_SetMask> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mask", &tr2_SetMask::Mask, "tr2", xml_convert::serialize_type::full)
    );
};


// SetMaskResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetMaskResponse = tr2_SetConfigurationResponse;


// GetMaskOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetMaskOptions {
    // Video Source Configuration Token that specifies an existing video source configuration that the options shall be compatible with.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tr2_GetMaskOptions
template<>
struct xml_convert::XmlTraits<tr2_GetMaskOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tr2_GetMaskOptions::ConfigurationToken, "tr2", xml_convert::serialize_type::full)
    );
};


// MaskOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_MaskOptions {
    // Maximum supported number of masks per VideoSourceConfiguration.
    int32_t MaxMasks {};
    // Maximum supported number of points per mask.
    int32_t MaxPoints {};
    // Information which types of tr2:MaskType are supported. Valid values are 'Color', 'Pixelated' and 'Blurred'.
    std::vector<std::string> Types;
    // Colors supported.
    tt_ColorOptions Color;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Information whether the polygon must have four points and a rectangular shape.
    std::optional<bool> RectangleOnly;
    // Indicates the device capability of change in color of privacy mask for one video source configuration will automatically be applied to all the privacy masks associated with the same video source configuration.
    std::optional<bool> SingleColorOnly;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_MaskOptions
template<>
struct xml_convert::XmlTraits<tr2_MaskOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MaxMasks", &tr2_MaskOptions::MaxMasks, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxPoints", &tr2_MaskOptions::MaxPoints, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Types", &tr2_MaskOptions::Types, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &tr2_MaskOptions::Color, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tr2_MaskOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("RectangleOnly", &tr2_MaskOptions::RectangleOnly, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SingleColorOnly", &tr2_MaskOptions::SingleColorOnly, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tr2_MaskOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetMaskOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetMaskOptionsResponse {
    tr2_MaskOptions Options;
};


// XmlTraits for tr2_GetMaskOptionsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetMaskOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tr2_GetMaskOptionsResponse::Options, "tr2", xml_convert::serialize_type::full)
    );
};


// CreateMask 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_CreateMask {
    // Contain the initial mask configuration for create.
    tr2_Mask Mask;
};


// XmlTraits for tr2_CreateMask
template<>
struct xml_convert::XmlTraits<tr2_CreateMask> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mask", &tr2_CreateMask::Mask, "tr2", xml_convert::serialize_type::full)
    );
};


// CreateMaskResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_CreateMaskResponse {
    // Returns Token of the newly created Mask
    tt_ReferenceToken Token;
};


// XmlTraits for tr2_CreateMaskResponse
template<>
struct xml_convert::XmlTraits<tr2_CreateMaskResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_CreateMaskResponse::Token, "tr2", xml_convert::serialize_type::full)
    );
};


// DeleteMask 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_DeleteMask {
    // This element contains a reference to the Mask configuration that should be deleted.
    tt_ReferenceToken Token;
};


// XmlTraits for tr2_DeleteMask
template<>
struct xml_convert::XmlTraits<tr2_DeleteMask> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_DeleteMask::Token, "tr2", xml_convert::serialize_type::full)
    );
};


// DeleteMaskResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_DeleteMaskResponse = tr2_SetConfigurationResponse;


// WebRTCConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_WebRTCConfiguration {
    // The signaling server URI.
    std::string SignalingServer;
    // The CertPathValidationPolicyID for validating the signaling server certificate.
    std::optional<std::string> CertPathValidationPolicyID;
    // The Authorization Server to use for getting access tokens. This refers to an entity in the list of configured Authorization Servers in the [ONVIF Security Service Specification].
    tt_ReferenceToken AuthorizationServer;
    // The default media profile to use for streaming if no specific profile is specified when initializing a session.
    tt_ReferenceToken DefaultProfile;
    // Enables/disables the configuration.
    bool Enabled {};
    // Indicates if the device is connected to the server. This parameter is read-only.
    std::optional<bool> Connected;
    // Optional user readable error information (readonly).
    std::optional<std::string> Error;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_WebRTCConfiguration
template<>
struct xml_convert::XmlTraits<tr2_WebRTCConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SignalingServer", &tr2_WebRTCConfiguration::SignalingServer, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CertPathValidationPolicyID", &tr2_WebRTCConfiguration::CertPathValidationPolicyID, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AuthorizationServer", &tr2_WebRTCConfiguration::AuthorizationServer, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultProfile", &tr2_WebRTCConfiguration::DefaultProfile, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Enabled", &tr2_WebRTCConfiguration::Enabled, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Connected", &tr2_WebRTCConfiguration::Connected, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Error", &tr2_WebRTCConfiguration::Error, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tr2_WebRTCConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tr2_WebRTCConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetWebRTCConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetWebRTCConfigurations {
};


// XmlTraits for tr2_GetWebRTCConfigurations
template<>
struct xml_convert::XmlTraits<tr2_GetWebRTCConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetWebRTCConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetWebRTCConfigurationsResponse {
    // Video Source Configuration Token that specifies an existing video source configuration that the options shall be compatible with.
    std::vector<tr2_WebRTCConfiguration> WebRTCConfiguration;
};


// XmlTraits for tr2_GetWebRTCConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetWebRTCConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("WebRTCConfiguration", &tr2_GetWebRTCConfigurationsResponse::WebRTCConfiguration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetWebRTCConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetWebRTCConfigurations {
    // This message contains the WebRTC configurations to use for the device. If empty, existing WebRTC configurations are deleted.
    std::vector<tr2_WebRTCConfiguration> WebRTCConfiguration;
};


// XmlTraits for tr2_SetWebRTCConfigurations
template<>
struct xml_convert::XmlTraits<tr2_SetWebRTCConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("WebRTCConfiguration", &tr2_SetWebRTCConfigurations::WebRTCConfiguration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetWebRTCConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetWebRTCConfigurationsResponse {
};


// XmlTraits for tr2_SetWebRTCConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_SetWebRTCConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AudioClip 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_AudioClip {
    // Enables/disables the audio clip.
    bool Enabled {};
    // Name of the audio clip.
    std::string Name;
    // Optional token list of physical audio outputs.
    std::vector<tt_ReferenceToken> AudioOutputToken;
    // Format of the audio clip. For definitions see tr2:SupportedAudioClipFormat parameter.
    std::string Type;
    // The number of times the audio clip can be repeated when it is played. A value of 0 means no repeat (i.e., the audio clip plays once and does not repeat). A value of 1 means the audio clip plays once and repeats once after the first play. A value of -1 means the audio clip repeats infinitely after the first play until it is stopped by the user.
    int32_t RepeatCycles {};
    // Optional time interval, in seconds, between audio clips when the audio clip is repeated.
    std::optional<int32_t> RepeatInterval;
    // Optional level to control the volume of the audio clip when it is played.
    std::optional<int32_t> AudioOutputLevel;
    // Optional schedule token associated with the audio clip configuration. The audio clip should be played when the configured schedule is triggered.
    std::optional<tt_ReferenceToken> ScheduleToken;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_AudioClip
template<>
struct xml_convert::XmlTraits<tr2_AudioClip> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tr2_AudioClip::Enabled, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Name", &tr2_AudioClip::Name, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioOutputToken", &tr2_AudioClip::AudioOutputToken, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Type", &tr2_AudioClip::Type, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RepeatCycles", &tr2_AudioClip::RepeatCycles, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RepeatInterval", &tr2_AudioClip::RepeatInterval, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioOutputLevel", &tr2_AudioClip::AudioOutputLevel, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ScheduleToken", &tr2_AudioClip::ScheduleToken, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tr2_AudioClip::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tr2_AudioClip::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetAudioClipsResponseItem 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioClipsResponseItem {
    // Unique token associated with the audio clip.
    tt_ReferenceToken Token;
    // Configuration of the audio clip.
    tr2_AudioClip Configuration;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_GetAudioClipsResponseItem
template<>
struct xml_convert::XmlTraits<tr2_GetAudioClipsResponseItem> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_GetAudioClipsResponseItem::Token, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configuration", &tr2_GetAudioClipsResponseItem::Configuration, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tr2_GetAudioClipsResponseItem::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tr2_GetAudioClipsResponseItem::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PlayingAudioClips 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_PlayingAudioClips {
    // Unique token associated with the audio clip.
    tt_ReferenceToken Token;
    // Name of the audio clip.
    std::string Name;
    // Token list of physical audio outputs.
    std::vector<tt_ReferenceToken> AudioOutputToken;
    // Output level to control the volume of the audio clip when it is played.
    int32_t AudioOutputLevel {};
    // Number of repeat cycles left while playing the audio clip.
    int32_t RepeatsLeft {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tr2_PlayingAudioClips
template<>
struct xml_convert::XmlTraits<tr2_PlayingAudioClips> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_PlayingAudioClips::Token, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Name", &tr2_PlayingAudioClips::Name, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioOutputToken", &tr2_PlayingAudioClips::AudioOutputToken, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioOutputLevel", &tr2_PlayingAudioClips::AudioOutputLevel, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RepeatsLeft", &tr2_PlayingAudioClips::RepeatsLeft, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tr2_PlayingAudioClips::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tr2_PlayingAudioClips::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetAudioClips 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioClips {
    // Audio clip token.
    std::optional<tt_ReferenceToken> Token;
};


// XmlTraits for tr2_GetAudioClips
template<>
struct xml_convert::XmlTraits<tr2_GetAudioClips> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_GetAudioClips::Token, "tr2", xml_convert::serialize_type::full)
    );
};


// GetAudioClipsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetAudioClipsResponse {
    // List of audio clip items.
    std::vector<tr2_GetAudioClipsResponseItem> AudioClipItem;
};


// XmlTraits for tr2_GetAudioClipsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetAudioClipsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AudioClipItem", &tr2_GetAudioClipsResponse::AudioClipItem, "tr2", xml_convert::serialize_type::full)
    );
};


// AddAudioClip 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_AddAudioClip {
    // Optional token associated with the audio clip.
    std::optional<tt_ReferenceToken> Token;
    // Audio clip configuration to add.
    tr2_AudioClip Configuration;
};


// XmlTraits for tr2_AddAudioClip
template<>
struct xml_convert::XmlTraits<tr2_AddAudioClip> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_AddAudioClip::Token, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configuration", &tr2_AddAudioClip::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// AddAudioClipResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_AddAudioClipResponse {
    // Unique token of the audio clip to be uploaded.
    tt_ReferenceToken Token;
    // A URL to which the audio clip can be uploaded.
    std::string UploadUri;
    // Expiry time by which the client should upload the audio clip to the device.
    std::string ExpiryTime;
};


// XmlTraits for tr2_AddAudioClipResponse
template<>
struct xml_convert::XmlTraits<tr2_AddAudioClipResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_AddAudioClipResponse::Token, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UploadUri", &tr2_AddAudioClipResponse::UploadUri, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ExpiryTime", &tr2_AddAudioClipResponse::ExpiryTime, "tr2", xml_convert::serialize_type::full)
    );
};


// SetAudioClip 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetAudioClip {
    // Unique token associated with the audio clip.
    tt_ReferenceToken Token;
    // Audio clip configuration to modify.
    tr2_AudioClip Configuration;
};


// XmlTraits for tr2_SetAudioClip
template<>
struct xml_convert::XmlTraits<tr2_SetAudioClip> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_SetAudioClip::Token, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configuration", &tr2_SetAudioClip::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetAudioClipResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetAudioClipResponse {
};


// XmlTraits for tr2_SetAudioClipResponse
template<>
struct xml_convert::XmlTraits<tr2_SetAudioClipResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteAudioClip 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_DeleteAudioClip {
    // Token of the audio clip to be deleted from the device.
    tt_ReferenceToken Token;
};


// XmlTraits for tr2_DeleteAudioClip
template<>
struct xml_convert::XmlTraits<tr2_DeleteAudioClip> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_DeleteAudioClip::Token, "tr2", xml_convert::serialize_type::full)
    );
};


// DeleteAudioClipResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_DeleteAudioClipResponse {
};


// XmlTraits for tr2_DeleteAudioClipResponse
template<>
struct xml_convert::XmlTraits<tr2_DeleteAudioClipResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// PlayAudioClip 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_PlayAudioClip {
    // Token of the audio clip to be played or stopped.
    tt_ReferenceToken Token;
    // Optional token list of physical audio outputs. If the AudioOutputToken is not provided in the API request, the AudioOutputToken from the audio clip configuration will be used.
    std::vector<tt_ReferenceToken> AudioOutputToken;
    // If it is true, play the audio clip; if it is false, stop the ongoing audio clip.
    bool Play {};
    // Optional RepeatCycles to be used for the current play operation. If RepeatCycles is not provided in the API request, the RepeatCycles specified in the audio clip configuration will be used for the current play operation.
    std::optional<int32_t> RepeatCycles;
};


// XmlTraits for tr2_PlayAudioClip
template<>
struct xml_convert::XmlTraits<tr2_PlayAudioClip> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tr2_PlayAudioClip::Token, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioOutputToken", &tr2_PlayAudioClip::AudioOutputToken, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Play", &tr2_PlayAudioClip::Play, "tr2", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RepeatCycles", &tr2_PlayAudioClip::RepeatCycles, "tr2", xml_convert::serialize_type::full)
    );
};


// PlayAudioClipResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_PlayAudioClipResponse {
};


// XmlTraits for tr2_PlayAudioClipResponse
template<>
struct xml_convert::XmlTraits<tr2_PlayAudioClipResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetPlayingAudioClips 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetPlayingAudioClips {
};


// XmlTraits for tr2_GetPlayingAudioClips
template<>
struct xml_convert::XmlTraits<tr2_GetPlayingAudioClips> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetPlayingAudioClipsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetPlayingAudioClipsResponse {
    // List of audio clips currently playing in the device.
    std::vector<tr2_PlayingAudioClips> PlayingAudioClips;
};


// XmlTraits for tr2_GetPlayingAudioClipsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetPlayingAudioClipsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PlayingAudioClips", &tr2_GetPlayingAudioClipsResponse::PlayingAudioClips, "tr2", xml_convert::serialize_type::full)
    );
};


// GetMulticastAudioDecoderConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetMulticastAudioDecoderConfigurations {
    // Unique token of the multicast audio decoder configuration. If not passed, device shall respond with all configurations.
    std::optional<tt_ReferenceToken> ConfigurationToken;
};


// XmlTraits for tr2_GetMulticastAudioDecoderConfigurations
template<>
struct xml_convert::XmlTraits<tr2_GetMulticastAudioDecoderConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tr2_GetMulticastAudioDecoderConfigurations::ConfigurationToken, "tr2", xml_convert::serialize_type::full)
    );
};


// GetMulticastAudioDecoderConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetMulticastAudioDecoderConfigurationsResponse {
    // This message contains the list of multicast audio decoder configurations.
    std::vector<tt_MulticastAudioDecoderConfiguration> Configurations;
};


// XmlTraits for tr2_GetMulticastAudioDecoderConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetMulticastAudioDecoderConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &tr2_GetMulticastAudioDecoderConfigurationsResponse::Configurations, "tr2", xml_convert::serialize_type::full)
    );
};


// GetMulticastAudioDecoderConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetMulticastAudioDecoderConfigurationOptions {
    // This response contains the available MulticastAudioDecoderConfigurationOptions. If a multicast audio decoder configuration is specified, the options shall concern that particular configuration.
    std::optional<tt_ReferenceToken> ConfigurationToken;
};


// XmlTraits for tr2_GetMulticastAudioDecoderConfigurationOptions
template<>
struct xml_convert::XmlTraits<tr2_GetMulticastAudioDecoderConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tr2_GetMulticastAudioDecoderConfigurationOptions::ConfigurationToken, "tr2", xml_convert::serialize_type::full)
    );
};


// GetMulticastAudioDecoderConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_GetMulticastAudioDecoderConfigurationOptionsResponse {
    std::vector<tt_MulticastAudioDecoderConfigurationOptions> Options;
};


// XmlTraits for tr2_GetMulticastAudioDecoderConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<tr2_GetMulticastAudioDecoderConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tr2_GetMulticastAudioDecoderConfigurationOptionsResponse::Options, "tr2", xml_convert::serialize_type::full)
    );
};


// SetMulticastAudioDecoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/media/wsdl
// 源文件: media_v20.wsdl
struct tr2_SetMulticastAudioDecoderConfiguration {
    // Contains the modified multicast audio decoder configuration. The configuration shall exist in the device.
    tt_MulticastAudioDecoderConfiguration Configuration;
};


// XmlTraits for tr2_SetMulticastAudioDecoderConfiguration
template<>
struct xml_convert::XmlTraits<tr2_SetMulticastAudioDecoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tr2_SetMulticastAudioDecoderConfiguration::Configuration, "tr2", xml_convert::serialize_type::full)
    );
};


// SetMulticastAudioDecoderConfigurationResponse 类型别名
// 基础类型: tr2_SetConfigurationResponse
using tr2_SetMulticastAudioDecoderConfigurationResponse = tr2_SetConfigurationResponse;


} // namespace libonvif_client
