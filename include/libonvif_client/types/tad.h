/**
 * @file tad.h
 * @brief 从 analyticsdevice_v10.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver10/analyticsdevice/wsdl
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
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetServiceCapabilities {
};


// XmlTraits for tad_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<tad_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_Capabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tad_Capabilities
template<>
struct xml_convert::XmlTraits<tad_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tad_Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tad_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetServiceCapabilitiesResponse {
    // The capabilities for the analytics device service is returned in the Capabilities element.
    tad_Capabilities Capabilities;
};


// XmlTraits for tad_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<tad_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &tad_GetServiceCapabilitiesResponse::Capabilities, "tad", xml_convert::serialize_type::full)
    );
};


// DeleteAnalyticsEngineControl 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_DeleteAnalyticsEngineControl {
    // Token of the Analytics Engine Control configuration to be deleted.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tad_DeleteAnalyticsEngineControl
template<>
struct xml_convert::XmlTraits<tad_DeleteAnalyticsEngineControl> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tad_DeleteAnalyticsEngineControl::ConfigurationToken, "tad", xml_convert::serialize_type::full)
    );
};


// DeleteAnalyticsEngineControlResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_DeleteAnalyticsEngineControlResponse {
};


// XmlTraits for tad_DeleteAnalyticsEngineControlResponse
template<>
struct xml_convert::XmlTraits<tad_DeleteAnalyticsEngineControlResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// CreateAnalyticsEngineInputs 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_CreateAnalyticsEngineInputs {
    // Settings of the configurations to be created.
    std::vector<tt_AnalyticsEngineInput> Configuration;
    std::vector<bool> ForcePersistence;
};


// XmlTraits for tad_CreateAnalyticsEngineInputs
template<>
struct xml_convert::XmlTraits<tad_CreateAnalyticsEngineInputs> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_CreateAnalyticsEngineInputs::Configuration, "tad", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &tad_CreateAnalyticsEngineInputs::ForcePersistence, "tad", xml_convert::serialize_type::full)
    );
};


// CreateAnalyticsEngineInputsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_CreateAnalyticsEngineInputsResponse {
    // Configurations containing token generated.
    std::vector<tt_AnalyticsEngineInput> Configuration;
};


// XmlTraits for tad_CreateAnalyticsEngineInputsResponse
template<>
struct xml_convert::XmlTraits<tad_CreateAnalyticsEngineInputsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_CreateAnalyticsEngineInputsResponse::Configuration, "tad", xml_convert::serialize_type::full)
    );
};


// CreateAnalyticsEngineControl 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_CreateAnalyticsEngineControl {
    // Settings of the Analytics Engine Control configuration to be created. Mode shall be set to "idle".
    tt_AnalyticsEngineControl Configuration;
};


// XmlTraits for tad_CreateAnalyticsEngineControl
template<>
struct xml_convert::XmlTraits<tad_CreateAnalyticsEngineControl> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_CreateAnalyticsEngineControl::Configuration, "tad", xml_convert::serialize_type::full)
    );
};


// CreateAnalyticsEngineControlResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_CreateAnalyticsEngineControlResponse {
    // Configuration containing token generated.
    std::vector<tt_AnalyticsEngineInput> Configuration;
};


// XmlTraits for tad_CreateAnalyticsEngineControlResponse
template<>
struct xml_convert::XmlTraits<tad_CreateAnalyticsEngineControlResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_CreateAnalyticsEngineControlResponse::Configuration, "tad", xml_convert::serialize_type::full)
    );
};


// SetAnalyticsEngineControl 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_SetAnalyticsEngineControl {
    // Contains the modified Analytics Engine Control configuration.
    tt_AnalyticsEngineControl Configuration;
    bool ForcePersistence {};
};


// XmlTraits for tad_SetAnalyticsEngineControl
template<>
struct xml_convert::XmlTraits<tad_SetAnalyticsEngineControl> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_SetAnalyticsEngineControl::Configuration, "tad", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &tad_SetAnalyticsEngineControl::ForcePersistence, "tad", xml_convert::serialize_type::full)
    );
};


// SetAnalyticsEngineControlResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_SetAnalyticsEngineControlResponse {
};


// XmlTraits for tad_SetAnalyticsEngineControlResponse
template<>
struct xml_convert::XmlTraits<tad_SetAnalyticsEngineControlResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAnalyticsEngineControl 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngineControl {
    // Token of the requested AnalyticsEngineControl configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tad_GetAnalyticsEngineControl
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngineControl> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tad_GetAnalyticsEngineControl::ConfigurationToken, "tad", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsEngineControlResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngineControlResponse {
    // Configuration of the AnalyticsEngineControl.
    tt_AnalyticsEngineControl Configuration;
};


// XmlTraits for tad_GetAnalyticsEngineControlResponse
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngineControlResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_GetAnalyticsEngineControlResponse::Configuration, "tad", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsEngineControls 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngineControls {
};


// XmlTraits for tad_GetAnalyticsEngineControls
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngineControls> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAnalyticsEngineControlsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngineControlsResponse {
    // List of available AnalyticsEngineControl configurations.
    std::vector<tt_AnalyticsEngineControl> AnalyticsEngineControls;
};


// XmlTraits for tad_GetAnalyticsEngineControlsResponse
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngineControlsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AnalyticsEngineControls", &tad_GetAnalyticsEngineControlsResponse::AnalyticsEngineControls, "tad", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsEngine 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngine {
    // Token of the requested AnalyticsEngine configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tad_GetAnalyticsEngine
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngine> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tad_GetAnalyticsEngine::ConfigurationToken, "tad", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsEngineResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngineResponse {
    // Configuration of the AnalyticsEngine.
    tt_AnalyticsEngine Configuration;
};


// XmlTraits for tad_GetAnalyticsEngineResponse
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngineResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_GetAnalyticsEngineResponse::Configuration, "tad", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsEngines 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngines {
};


// XmlTraits for tad_GetAnalyticsEngines
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngines> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAnalyticsEnginesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEnginesResponse {
    // List of available AnalyticsEngine configurations.
    std::vector<tt_AnalyticsEngine> Configuration;
};


// XmlTraits for tad_GetAnalyticsEnginesResponse
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEnginesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_GetAnalyticsEnginesResponse::Configuration, "tad", xml_convert::serialize_type::full)
    );
};


// SetVideoAnalyticsConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_SetVideoAnalyticsConfiguration {
    // Contains the modified video analytics configuration. The configuration shall exist in the device.
    tt_VideoAnalyticsConfiguration Configuration;
    bool ForcePersistence {};
};


// XmlTraits for tad_SetVideoAnalyticsConfiguration
template<>
struct xml_convert::XmlTraits<tad_SetVideoAnalyticsConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_SetVideoAnalyticsConfiguration::Configuration, "tad", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &tad_SetVideoAnalyticsConfiguration::ForcePersistence, "tad", xml_convert::serialize_type::full)
    );
};


// SetVideoAnalyticsConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_SetVideoAnalyticsConfigurationResponse {
};


// XmlTraits for tad_SetVideoAnalyticsConfigurationResponse
template<>
struct xml_convert::XmlTraits<tad_SetVideoAnalyticsConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetAnalyticsEngineInput 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_SetAnalyticsEngineInput {
    // Contains the modified Analytics Engine Input configuration. The configuration shall exist in the device.
    tt_AnalyticsEngineInput Configuration;
    bool ForcePersistence {};
};


// XmlTraits for tad_SetAnalyticsEngineInput
template<>
struct xml_convert::XmlTraits<tad_SetAnalyticsEngineInput> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_SetAnalyticsEngineInput::Configuration, "tad", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &tad_SetAnalyticsEngineInput::ForcePersistence, "tad", xml_convert::serialize_type::full)
    );
};


// SetAnalyticsEngineInputResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_SetAnalyticsEngineInputResponse {
};


// XmlTraits for tad_SetAnalyticsEngineInputResponse
template<>
struct xml_convert::XmlTraits<tad_SetAnalyticsEngineInputResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAnalyticsEngineInput 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngineInput {
    // Token of the requested AnalyticsEngineInput configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tad_GetAnalyticsEngineInput
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngineInput> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tad_GetAnalyticsEngineInput::ConfigurationToken, "tad", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsEngineInputResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngineInputResponse {
    // Configuration of the AnalyticsEngineInput.
    tt_AnalyticsEngineInput Configuration;
};


// XmlTraits for tad_GetAnalyticsEngineInputResponse
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngineInputResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_GetAnalyticsEngineInputResponse::Configuration, "tad", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsEngineInputs 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngineInputs {
};


// XmlTraits for tad_GetAnalyticsEngineInputs
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngineInputs> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAnalyticsEngineInputsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsEngineInputsResponse {
    // List of available AnalyticsEngineInput configurations.
    std::vector<tt_AnalyticsEngineInput> Configuration;
};


// XmlTraits for tad_GetAnalyticsEngineInputsResponse
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsEngineInputsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_GetAnalyticsEngineInputsResponse::Configuration, "tad", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsDeviceStreamUri 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsDeviceStreamUri {
    // Configuration of the URI requested.
    tt_StreamSetup StreamSetup;
    // Token of the AnalyticsEngineControl whose URI is requested.
    tt_ReferenceToken AnalyticsEngineControlToken;
};


// XmlTraits for tad_GetAnalyticsDeviceStreamUri
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsDeviceStreamUri> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StreamSetup", &tad_GetAnalyticsDeviceStreamUri::StreamSetup, "tad", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AnalyticsEngineControlToken", &tad_GetAnalyticsDeviceStreamUri::AnalyticsEngineControlToken, "tad", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsDeviceStreamUriResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsDeviceStreamUriResponse {
    // Streaming URI.
    std::string Uri;
};


// XmlTraits for tad_GetAnalyticsDeviceStreamUriResponse
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsDeviceStreamUriResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Uri", &tad_GetAnalyticsDeviceStreamUriResponse::Uri, "tad", xml_convert::serialize_type::full)
    );
};


// GetVideoAnalyticsConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetVideoAnalyticsConfiguration {
    // Token of the VideoAnalyticsConfiguration requested.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tad_GetVideoAnalyticsConfiguration
template<>
struct xml_convert::XmlTraits<tad_GetVideoAnalyticsConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tad_GetVideoAnalyticsConfiguration::ConfigurationToken, "tad", xml_convert::serialize_type::full)
    );
};


// GetVideoAnalyticsConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetVideoAnalyticsConfigurationResponse {
    // Settings of the VideoAnalyticsConfiguration.
    tt_VideoAnalyticsConfiguration Configuration;
};


// XmlTraits for tad_GetVideoAnalyticsConfigurationResponse
template<>
struct xml_convert::XmlTraits<tad_GetVideoAnalyticsConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &tad_GetVideoAnalyticsConfigurationResponse::Configuration, "tad", xml_convert::serialize_type::full)
    );
};


// DeleteAnalyticsEngineInputs 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_DeleteAnalyticsEngineInputs {
    // LIst of tokens of Analytics Engine Input configurations to be deleted.
    std::vector<tt_ReferenceToken> ConfigurationToken;
};


// XmlTraits for tad_DeleteAnalyticsEngineInputs
template<>
struct xml_convert::XmlTraits<tad_DeleteAnalyticsEngineInputs> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tad_DeleteAnalyticsEngineInputs::ConfigurationToken, "tad", xml_convert::serialize_type::full)
    );
};


// DeleteAnalyticsEngineInputsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_DeleteAnalyticsEngineInputsResponse {
};


// XmlTraits for tad_DeleteAnalyticsEngineInputsResponse
template<>
struct xml_convert::XmlTraits<tad_DeleteAnalyticsEngineInputsResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAnalyticsState 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsState {
    // Token of the AnalyticsEngineControl whose state information is requested.
    tt_ReferenceToken AnalyticsEngineControlToken;
};


// XmlTraits for tad_GetAnalyticsState
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsState> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AnalyticsEngineControlToken", &tad_GetAnalyticsState::AnalyticsEngineControlToken, "tad", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsStateResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/analyticsdevice/wsdl
// 源文件: analyticsdevice_v10.wsdl
struct tad_GetAnalyticsStateResponse {
    // Current status information.
    tt_AnalyticsStateInformation State;
};


// XmlTraits for tad_GetAnalyticsStateResponse
template<>
struct xml_convert::XmlTraits<tad_GetAnalyticsStateResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("State", &tad_GetAnalyticsStateResponse::State, "tad", xml_convert::serialize_type::full)
    );
};


} // namespace libonvif_client
