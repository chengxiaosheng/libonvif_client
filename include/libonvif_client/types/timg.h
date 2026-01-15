/**
 * @file timg.h
 * @brief 从 imaging_v20.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver20/imaging/wsdl
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
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetServiceCapabilities {
};


// XmlTraits for timg_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<timg_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_Capabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    /*
     * Indicates whether or not Image Stabilization feature is supported.
     * The use of this capability is deprecated, a client should use GetOption to find out if image stabilization is supported.
     */
    std::optional<bool> ImageStabilization;
    // Indicates whether or not Imaging Presets feature is supported.
    std::optional<bool> Presets;
    // Indicates whether or not imaging preset settings can be updated.
    std::optional<bool> AdaptablePreset;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for timg_Capabilities
template<>
struct xml_convert::XmlTraits<timg_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &timg_Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("ImageStabilization", &timg_Capabilities::ImageStabilization, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Presets", &timg_Capabilities::Presets, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AdaptablePreset", &timg_Capabilities::AdaptablePreset, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &timg_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetServiceCapabilitiesResponse {
    // The capabilities for the imaging service is returned in the Capabilities element.
    timg_Capabilities Capabilities;
};


// XmlTraits for timg_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<timg_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &timg_GetServiceCapabilitiesResponse::Capabilities, "timg", xml_convert::serialize_type::full)
    );
};


// GetImagingSettings 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetImagingSettings {
    // Reference token to the VideoSource for which the ImagingSettings.
    tt_ReferenceToken VideoSourceToken;
};


// XmlTraits for timg_GetImagingSettings
template<>
struct xml_convert::XmlTraits<timg_GetImagingSettings> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &timg_GetImagingSettings::VideoSourceToken, "timg", xml_convert::serialize_type::full)
    );
};


// GetImagingSettingsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetImagingSettingsResponse {
    // ImagingSettings for the VideoSource that was requested.
    tt_ImagingSettings20 ImagingSettings;
};


// XmlTraits for timg_GetImagingSettingsResponse
template<>
struct xml_convert::XmlTraits<timg_GetImagingSettingsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ImagingSettings", &timg_GetImagingSettingsResponse::ImagingSettings, "timg", xml_convert::serialize_type::full)
    );
};


// SetImagingSettings 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_SetImagingSettings {
    tt_ReferenceToken VideoSourceToken;
    tt_ImagingSettings20 ImagingSettings;
    std::optional<bool> ForcePersistence;
};


// XmlTraits for timg_SetImagingSettings
template<>
struct xml_convert::XmlTraits<timg_SetImagingSettings> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &timg_SetImagingSettings::VideoSourceToken, "timg", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ImagingSettings", &timg_SetImagingSettings::ImagingSettings, "timg", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &timg_SetImagingSettings::ForcePersistence, "timg", xml_convert::serialize_type::full)
    );
};


// SetImagingSettingsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_SetImagingSettingsResponse {
};


// XmlTraits for timg_SetImagingSettingsResponse
template<>
struct xml_convert::XmlTraits<timg_SetImagingSettingsResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetOptions {
    // Reference token to the VideoSource for which the imaging parameter options are requested.
    tt_ReferenceToken VideoSourceToken;
};


// XmlTraits for timg_GetOptions
template<>
struct xml_convert::XmlTraits<timg_GetOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &timg_GetOptions::VideoSourceToken, "timg", xml_convert::serialize_type::full)
    );
};


// GetOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetOptionsResponse {
    // Valid ranges for the imaging parameters that are categorized as device specific.
    tt_ImagingOptions20 ImagingOptions;
};


// XmlTraits for timg_GetOptionsResponse
template<>
struct xml_convert::XmlTraits<timg_GetOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ImagingOptions", &timg_GetOptionsResponse::ImagingOptions, "timg", xml_convert::serialize_type::full)
    );
};


// Move 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_Move {
    // Reference to the VideoSource for the requested move (focus) operation.
    tt_ReferenceToken VideoSourceToken;
    // Content of the requested move (focus) operation.
    tt_FocusMove Focus;
};


// XmlTraits for timg_Move
template<>
struct xml_convert::XmlTraits<timg_Move> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &timg_Move::VideoSourceToken, "timg", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Focus", &timg_Move::Focus, "timg", xml_convert::serialize_type::full)
    );
};


// MoveResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_MoveResponse {
};


// XmlTraits for timg_MoveResponse
template<>
struct xml_convert::XmlTraits<timg_MoveResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetMoveOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetMoveOptions {
    // Reference token to the VideoSource for the requested move options.
    tt_ReferenceToken VideoSourceToken;
};


// XmlTraits for timg_GetMoveOptions
template<>
struct xml_convert::XmlTraits<timg_GetMoveOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &timg_GetMoveOptions::VideoSourceToken, "timg", xml_convert::serialize_type::full)
    );
};


// GetMoveOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetMoveOptionsResponse {
    // Valid ranges for the focus lens move options.
    tt_MoveOptions20 MoveOptions;
};


// XmlTraits for timg_GetMoveOptionsResponse
template<>
struct xml_convert::XmlTraits<timg_GetMoveOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MoveOptions", &timg_GetMoveOptionsResponse::MoveOptions, "timg", xml_convert::serialize_type::full)
    );
};


// Stop 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_Stop {
    // Reference token to the VideoSource where the focus movement should be stopped.
    tt_ReferenceToken VideoSourceToken;
};


// XmlTraits for timg_Stop
template<>
struct xml_convert::XmlTraits<timg_Stop> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &timg_Stop::VideoSourceToken, "timg", xml_convert::serialize_type::full)
    );
};


// StopResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_StopResponse {
};


// XmlTraits for timg_StopResponse
template<>
struct xml_convert::XmlTraits<timg_StopResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetStatus 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetStatus {
    // Reference token to the VideoSource where the imaging status should be requested.
    tt_ReferenceToken VideoSourceToken;
};


// XmlTraits for timg_GetStatus
template<>
struct xml_convert::XmlTraits<timg_GetStatus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &timg_GetStatus::VideoSourceToken, "timg", xml_convert::serialize_type::full)
    );
};


// GetStatusResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetStatusResponse {
    // Requested imaging status.
    tt_ImagingStatus20 Status;
};


// XmlTraits for timg_GetStatusResponse
template<>
struct xml_convert::XmlTraits<timg_GetStatusResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Status", &timg_GetStatusResponse::Status, "timg", xml_convert::serialize_type::full)
    );
};


// ImagingPresetType 枚举类型
// 基础类型: std::string
enum class  timg_ImagingPresetType {
    Custom,
    ClearWeather,
    Cloudy,
    Fog,
    Rain,
    Snowing,
    Snow,
    WDR,
    Shade,
    Night,
    Indoor,
    Fluorescent,
    Incandescent,
    Sodium_Natrium, // Sodium(Natrium)
    Sunrise_Horizon, // Sunrise(Horizon)
    Sunset_Rear, // Sunset(Rear)
    ExtremeHot,
    ExtremeCold,
    Underwater,
    CloseUp,
    Motion,
    FlickerFree50,
    FlickerFree60
};

// 字符串转换函数
inline std::string to_string(timg_ImagingPresetType value) {
    switch (value) {
        case timg_ImagingPresetType::Custom: return "Custom";
        case timg_ImagingPresetType::ClearWeather: return "ClearWeather";
        case timg_ImagingPresetType::Cloudy: return "Cloudy";
        case timg_ImagingPresetType::Fog: return "Fog";
        case timg_ImagingPresetType::Rain: return "Rain";
        case timg_ImagingPresetType::Snowing: return "Snowing";
        case timg_ImagingPresetType::Snow: return "Snow";
        case timg_ImagingPresetType::WDR: return "WDR";
        case timg_ImagingPresetType::Shade: return "Shade";
        case timg_ImagingPresetType::Night: return "Night";
        case timg_ImagingPresetType::Indoor: return "Indoor";
        case timg_ImagingPresetType::Fluorescent: return "Fluorescent";
        case timg_ImagingPresetType::Incandescent: return "Incandescent";
        case timg_ImagingPresetType::Sodium_Natrium: return "Sodium(Natrium)";
        case timg_ImagingPresetType::Sunrise_Horizon: return "Sunrise(Horizon)";
        case timg_ImagingPresetType::Sunset_Rear: return "Sunset(Rear)";
        case timg_ImagingPresetType::ExtremeHot: return "ExtremeHot";
        case timg_ImagingPresetType::ExtremeCold: return "ExtremeCold";
        case timg_ImagingPresetType::Underwater: return "Underwater";
        case timg_ImagingPresetType::CloseUp: return "CloseUp";
        case timg_ImagingPresetType::Motion: return "Motion";
        case timg_ImagingPresetType::FlickerFree50: return "FlickerFree50";
        case timg_ImagingPresetType::FlickerFree60: return "FlickerFree60";
        default: return "";
    }
}

inline bool from_string(timg_ImagingPresetType& value, const std::string& str) {
    if (str == "Custom") { value = timg_ImagingPresetType::Custom; return true; }
    if (str == "ClearWeather") { value = timg_ImagingPresetType::ClearWeather; return true; }
    if (str == "Cloudy") { value = timg_ImagingPresetType::Cloudy; return true; }
    if (str == "Fog") { value = timg_ImagingPresetType::Fog; return true; }
    if (str == "Rain") { value = timg_ImagingPresetType::Rain; return true; }
    if (str == "Snowing") { value = timg_ImagingPresetType::Snowing; return true; }
    if (str == "Snow") { value = timg_ImagingPresetType::Snow; return true; }
    if (str == "WDR") { value = timg_ImagingPresetType::WDR; return true; }
    if (str == "Shade") { value = timg_ImagingPresetType::Shade; return true; }
    if (str == "Night") { value = timg_ImagingPresetType::Night; return true; }
    if (str == "Indoor") { value = timg_ImagingPresetType::Indoor; return true; }
    if (str == "Fluorescent") { value = timg_ImagingPresetType::Fluorescent; return true; }
    if (str == "Incandescent") { value = timg_ImagingPresetType::Incandescent; return true; }
    if (str == "Sodium(Natrium)") { value = timg_ImagingPresetType::Sodium_Natrium; return true; }
    if (str == "Sunrise(Horizon)") { value = timg_ImagingPresetType::Sunrise_Horizon; return true; }
    if (str == "Sunset(Rear)") { value = timg_ImagingPresetType::Sunset_Rear; return true; }
    if (str == "ExtremeHot") { value = timg_ImagingPresetType::ExtremeHot; return true; }
    if (str == "ExtremeCold") { value = timg_ImagingPresetType::ExtremeCold; return true; }
    if (str == "Underwater") { value = timg_ImagingPresetType::Underwater; return true; }
    if (str == "CloseUp") { value = timg_ImagingPresetType::CloseUp; return true; }
    if (str == "Motion") { value = timg_ImagingPresetType::Motion; return true; }
    if (str == "FlickerFree50") { value = timg_ImagingPresetType::FlickerFree50; return true; }
    if (str == "FlickerFree60") { value = timg_ImagingPresetType::FlickerFree60; return true; }
    return false;
}


// XmlValueAdapter specialization for enum timg_ImagingPresetType
template<>
struct xml_convert::XmlValueAdapter<timg_ImagingPresetType> {
    static bool from_xml_val(timg_ImagingPresetType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const timg_ImagingPresetType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum timg_ImagingPresetType
template<>
struct xml_convert::XmlAttributeAdapter<timg_ImagingPresetType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const timg_ImagingPresetType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(timg_ImagingPresetType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ImagingPreset 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_ImagingPreset {
    // Human readable name of the Imaging Preset.
    tt_Name Name;
    // Unique identifier of this Imaging Preset.
    tt_ReferenceToken token;
    /*
     * Indicates Imaging Preset Type. Use timg:ImagingPresetType.
     * Used for multi-language support and display.
     */
    std::string type;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for timg_ImagingPreset
template<>
struct xml_convert::XmlTraits<timg_ImagingPreset> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &timg_ImagingPreset::Name, "timg", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("token", &timg_ImagingPreset::token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("type", &timg_ImagingPreset::type, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &timg_ImagingPreset::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetPresets 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetPresets {
    // A reference to the VideoSource where the operation should take place.
    tt_ReferenceToken VideoSourceToken;
};


// XmlTraits for timg_GetPresets
template<>
struct xml_convert::XmlTraits<timg_GetPresets> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &timg_GetPresets::VideoSourceToken, "timg", xml_convert::serialize_type::full)
    );
};


// GetPresetsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetPresetsResponse {
    // List of Imaging Presets which are available for the requested VideoSource.
    std::vector<timg_ImagingPreset> Preset;
};


// XmlTraits for timg_GetPresetsResponse
template<>
struct xml_convert::XmlTraits<timg_GetPresetsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Preset", &timg_GetPresetsResponse::Preset, "timg", xml_convert::serialize_type::full)
    );
};


// GetCurrentPreset 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetCurrentPreset {
    // Reference token to the VideoSource where the current Imaging Preset should be requested.
    tt_ReferenceToken VideoSourceToken;
};


// XmlTraits for timg_GetCurrentPreset
template<>
struct xml_convert::XmlTraits<timg_GetCurrentPreset> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &timg_GetCurrentPreset::VideoSourceToken, "timg", xml_convert::serialize_type::full)
    );
};


// GetCurrentPresetResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_GetCurrentPresetResponse {
    // Current Imaging Preset in use for the specified Video Source.
    std::optional<timg_ImagingPreset> Preset;
};


// XmlTraits for timg_GetCurrentPresetResponse
template<>
struct xml_convert::XmlTraits<timg_GetCurrentPresetResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Preset", &timg_GetCurrentPresetResponse::Preset, "timg", xml_convert::serialize_type::full)
    );
};


// SetCurrentPreset 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_SetCurrentPreset {
    // Reference token to the VideoSource to which the specified Imaging Preset should be applied.
    tt_ReferenceToken VideoSourceToken;
    // Reference token to the Imaging Preset to be applied to the specified Video Source.
    tt_ReferenceToken PresetToken;
};


// XmlTraits for timg_SetCurrentPreset
template<>
struct xml_convert::XmlTraits<timg_SetCurrentPreset> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &timg_SetCurrentPreset::VideoSourceToken, "timg", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetToken", &timg_SetCurrentPreset::PresetToken, "timg", xml_convert::serialize_type::full)
    );
};


// SetCurrentPresetResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/imaging/wsdl
// 源文件: imaging_v20.wsdl
struct timg_SetCurrentPresetResponse {
};


// XmlTraits for timg_SetCurrentPresetResponse
template<>
struct xml_convert::XmlTraits<timg_SetCurrentPresetResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


} // namespace libonvif_client
