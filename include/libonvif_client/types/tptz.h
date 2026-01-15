/**
 * @file tptz.h
 * @brief 从 ptz_v20.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver20/ptz/wsdl
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
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetServiceCapabilities {
};


// XmlTraits for tptz_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<tptz_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_Capabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicates whether or not EFlip is supported.
    std::optional<bool> EFlip;
    // Indicates whether or not reversing of PT control direction is supported.
    std::optional<bool> Reverse;
    // Indicates support for the GetCompatibleConfigurations command.
    std::optional<bool> GetCompatibleConfigurations;
    // Indicates that the PTZStatus includes MoveStatus information.
    std::optional<bool> MoveStatus;
    // Indicates that the PTZStatus includes Position information.
    std::optional<bool> StatusPosition;
    // Indication of the methods of MoveAndTrack that are supported, acceptable values are defined in tt:MoveAndTrackMethod.
    std::optional<tt_StringList> MoveAndTrack;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tptz_Capabilities
template<>
struct xml_convert::XmlTraits<tptz_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tptz_Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("EFlip", &tptz_Capabilities::EFlip, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Reverse", &tptz_Capabilities::Reverse, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("GetCompatibleConfigurations", &tptz_Capabilities::GetCompatibleConfigurations, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MoveStatus", &tptz_Capabilities::MoveStatus, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("StatusPosition", &tptz_Capabilities::StatusPosition, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MoveAndTrack", &tptz_Capabilities::MoveAndTrack, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tptz_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetServiceCapabilitiesResponse {
    // The capabilities for the PTZ service is returned in the Capabilities element.
    tptz_Capabilities Capabilities;
};


// XmlTraits for tptz_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<tptz_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &tptz_GetServiceCapabilitiesResponse::Capabilities, "tptz", xml_convert::serialize_type::full)
    );
};


// GetNodes 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetNodes {
};


// XmlTraits for tptz_GetNodes
template<>
struct xml_convert::XmlTraits<tptz_GetNodes> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetNodesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetNodesResponse {
    // A list of the existing PTZ Nodes on the device.
    std::vector<tt_PTZNode> PTZNode;
};


// XmlTraits for tptz_GetNodesResponse
template<>
struct xml_convert::XmlTraits<tptz_GetNodesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZNode", &tptz_GetNodesResponse::PTZNode, "tptz", xml_convert::serialize_type::full)
    );
};


// GetNode 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetNode {
    // Token of the requested PTZNode.
    tt_ReferenceToken NodeToken;
};


// XmlTraits for tptz_GetNode
template<>
struct xml_convert::XmlTraits<tptz_GetNode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NodeToken", &tptz_GetNode::NodeToken, "tptz", xml_convert::serialize_type::full)
    );
};


// GetNodeResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetNodeResponse {
    // A requested PTZNode.
    tt_PTZNode PTZNode;
};


// XmlTraits for tptz_GetNodeResponse
template<>
struct xml_convert::XmlTraits<tptz_GetNodeResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZNode", &tptz_GetNodeResponse::PTZNode, "tptz", xml_convert::serialize_type::full)
    );
};


// GetConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetConfigurations {
};


// XmlTraits for tptz_GetConfigurations
template<>
struct xml_convert::XmlTraits<tptz_GetConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetConfigurationsResponse {
    // A list of all existing PTZConfigurations on the device.
    std::vector<tt_PTZConfiguration> PTZConfiguration;
};


// XmlTraits for tptz_GetConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tptz_GetConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZConfiguration", &tptz_GetConfigurationsResponse::PTZConfiguration, "tptz", xml_convert::serialize_type::full)
    );
};


// GetConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetConfiguration {
    // Token of the requested PTZConfiguration.
    tt_ReferenceToken PTZConfigurationToken;
};


// XmlTraits for tptz_GetConfiguration
template<>
struct xml_convert::XmlTraits<tptz_GetConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZConfigurationToken", &tptz_GetConfiguration::PTZConfigurationToken, "tptz", xml_convert::serialize_type::full)
    );
};


// GetConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetConfigurationResponse {
    // A requested PTZConfiguration.
    tt_PTZConfiguration PTZConfiguration;
};


// XmlTraits for tptz_GetConfigurationResponse
template<>
struct xml_convert::XmlTraits<tptz_GetConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZConfiguration", &tptz_GetConfigurationResponse::PTZConfiguration, "tptz", xml_convert::serialize_type::full)
    );
};


// SetConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_SetConfiguration {
    tt_PTZConfiguration PTZConfiguration;
    // Flag that makes configuration persistent. Example: User wants the configuration to exist after reboot.
    bool ForcePersistence {};
};


// XmlTraits for tptz_SetConfiguration
template<>
struct xml_convert::XmlTraits<tptz_SetConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZConfiguration", &tptz_SetConfiguration::PTZConfiguration, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &tptz_SetConfiguration::ForcePersistence, "tptz", xml_convert::serialize_type::full)
    );
};


// SetConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_SetConfigurationResponse {
};


// XmlTraits for tptz_SetConfigurationResponse
template<>
struct xml_convert::XmlTraits<tptz_SetConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetConfigurationOptions {
    // Token of an existing configuration that the options are intended for.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tptz_GetConfigurationOptions
template<>
struct xml_convert::XmlTraits<tptz_GetConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tptz_GetConfigurationOptions::ConfigurationToken, "tptz", xml_convert::serialize_type::full)
    );
};


// GetConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetConfigurationOptionsResponse {
    // The requested PTZ configuration options.
    tt_PTZConfigurationOptions PTZConfigurationOptions;
};


// XmlTraits for tptz_GetConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<tptz_GetConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZConfigurationOptions", &tptz_GetConfigurationOptionsResponse::PTZConfigurationOptions, "tptz", xml_convert::serialize_type::full)
    );
};


// SendAuxiliaryCommand 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_SendAuxiliaryCommand {
    // A reference to the MediaProfile where the operation should take place.
    tt_ReferenceToken ProfileToken;
    // The Auxiliary request data.
    tt_AuxiliaryData AuxiliaryData;
};


// XmlTraits for tptz_SendAuxiliaryCommand
template<>
struct xml_convert::XmlTraits<tptz_SendAuxiliaryCommand> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_SendAuxiliaryCommand::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AuxiliaryData", &tptz_SendAuxiliaryCommand::AuxiliaryData, "tptz", xml_convert::serialize_type::full)
    );
};


// SendAuxiliaryCommandResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_SendAuxiliaryCommandResponse {
    // The response contains the auxiliary response.
    tt_AuxiliaryData AuxiliaryResponse;
};


// XmlTraits for tptz_SendAuxiliaryCommandResponse
template<>
struct xml_convert::XmlTraits<tptz_SendAuxiliaryCommandResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AuxiliaryResponse", &tptz_SendAuxiliaryCommandResponse::AuxiliaryResponse, "tptz", xml_convert::serialize_type::full)
    );
};


// GetPresets 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetPresets {
    // A reference to the MediaProfile where the operation should take place.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for tptz_GetPresets
template<>
struct xml_convert::XmlTraits<tptz_GetPresets> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_GetPresets::ProfileToken, "tptz", xml_convert::serialize_type::full)
    );
};


// GetPresetsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetPresetsResponse {
    // A list of presets which are available for the requested MediaProfile.
    std::vector<tt_PTZPreset> Preset;
};


// XmlTraits for tptz_GetPresetsResponse
template<>
struct xml_convert::XmlTraits<tptz_GetPresetsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Preset", &tptz_GetPresetsResponse::Preset, "tptz", xml_convert::serialize_type::full)
    );
};


// SetPreset 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_SetPreset {
    // A reference to the MediaProfile where the operation should take place.
    tt_ReferenceToken ProfileToken;
    // A requested preset name.
    std::optional<std::string> PresetName;
    // A requested preset token.
    std::optional<tt_ReferenceToken> PresetToken;
};


// XmlTraits for tptz_SetPreset
template<>
struct xml_convert::XmlTraits<tptz_SetPreset> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_SetPreset::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetName", &tptz_SetPreset::PresetName, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetToken", &tptz_SetPreset::PresetToken, "tptz", xml_convert::serialize_type::full)
    );
};


// SetPresetResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_SetPresetResponse {
    // A token to the Preset which has been set.
    tt_ReferenceToken PresetToken;
};


// XmlTraits for tptz_SetPresetResponse
template<>
struct xml_convert::XmlTraits<tptz_SetPresetResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PresetToken", &tptz_SetPresetResponse::PresetToken, "tptz", xml_convert::serialize_type::full)
    );
};


// RemovePreset 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_RemovePreset {
    // A reference to the MediaProfile where the operation should take place.
    tt_ReferenceToken ProfileToken;
    // A requested preset token.
    tt_ReferenceToken PresetToken;
};


// XmlTraits for tptz_RemovePreset
template<>
struct xml_convert::XmlTraits<tptz_RemovePreset> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_RemovePreset::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetToken", &tptz_RemovePreset::PresetToken, "tptz", xml_convert::serialize_type::full)
    );
};


// RemovePresetResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_RemovePresetResponse {
};


// XmlTraits for tptz_RemovePresetResponse
template<>
struct xml_convert::XmlTraits<tptz_RemovePresetResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GotoPreset 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GotoPreset {
    // A reference to the MediaProfile where the operation should take place.
    tt_ReferenceToken ProfileToken;
    // A requested preset token.
    tt_ReferenceToken PresetToken;
    // A requested speed.The speed parameter can only be specified when Speed Spaces are available for the PTZ Node.
    std::optional<tt_PTZSpeed> Speed;
};


// XmlTraits for tptz_GotoPreset
template<>
struct xml_convert::XmlTraits<tptz_GotoPreset> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_GotoPreset::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetToken", &tptz_GotoPreset::PresetToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tptz_GotoPreset::Speed, "tptz", xml_convert::serialize_type::full)
    );
};


// GotoPresetResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GotoPresetResponse {
};


// XmlTraits for tptz_GotoPresetResponse
template<>
struct xml_convert::XmlTraits<tptz_GotoPresetResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetStatus 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetStatus {
    // A reference to the MediaProfile where the PTZStatus should be requested.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for tptz_GetStatus
template<>
struct xml_convert::XmlTraits<tptz_GetStatus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_GetStatus::ProfileToken, "tptz", xml_convert::serialize_type::full)
    );
};


// GetStatusResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetStatusResponse {
    // The PTZStatus for the requested MediaProfile.
    tt_PTZStatus PTZStatus;
};


// XmlTraits for tptz_GetStatusResponse
template<>
struct xml_convert::XmlTraits<tptz_GetStatusResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZStatus", &tptz_GetStatusResponse::PTZStatus, "tptz", xml_convert::serialize_type::full)
    );
};


// GotoHomePosition 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GotoHomePosition {
    // A reference to the MediaProfile where the operation should take place.
    tt_ReferenceToken ProfileToken;
    // A requested speed.The speed parameter can only be specified when Speed Spaces are available for the PTZ Node.
    std::optional<tt_PTZSpeed> Speed;
};


// XmlTraits for tptz_GotoHomePosition
template<>
struct xml_convert::XmlTraits<tptz_GotoHomePosition> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_GotoHomePosition::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tptz_GotoHomePosition::Speed, "tptz", xml_convert::serialize_type::full)
    );
};


// GotoHomePositionResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GotoHomePositionResponse {
};


// XmlTraits for tptz_GotoHomePositionResponse
template<>
struct xml_convert::XmlTraits<tptz_GotoHomePositionResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetHomePosition 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_SetHomePosition {
    // A reference to the MediaProfile where the home position should be set.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for tptz_SetHomePosition
template<>
struct xml_convert::XmlTraits<tptz_SetHomePosition> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_SetHomePosition::ProfileToken, "tptz", xml_convert::serialize_type::full)
    );
};


// SetHomePositionResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_SetHomePositionResponse {
};


// XmlTraits for tptz_SetHomePositionResponse
template<>
struct xml_convert::XmlTraits<tptz_SetHomePositionResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// ContinuousMove 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_ContinuousMove {
    // A reference to the MediaProfile.
    tt_ReferenceToken ProfileToken;
    // A Velocity vector specifying the velocity of pan, tilt and zoom.
    tt_PTZSpeed Velocity;
    // An optional Timeout parameter.
    std::optional<std::string> Timeout;
};


// XmlTraits for tptz_ContinuousMove
template<>
struct xml_convert::XmlTraits<tptz_ContinuousMove> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_ContinuousMove::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Velocity", &tptz_ContinuousMove::Velocity, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Timeout", &tptz_ContinuousMove::Timeout, "tptz", xml_convert::serialize_type::full)
    );
};


// ContinuousMoveResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_ContinuousMoveResponse {
};


// XmlTraits for tptz_ContinuousMoveResponse
template<>
struct xml_convert::XmlTraits<tptz_ContinuousMoveResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RelativeMove 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_RelativeMove {
    // A reference to the MediaProfile.
    tt_ReferenceToken ProfileToken;
    // A positional Translation relative to the current position
    tt_PTZVector Translation;
    // An optional Speed parameter.
    std::optional<tt_PTZSpeed> Speed;
};


// XmlTraits for tptz_RelativeMove
template<>
struct xml_convert::XmlTraits<tptz_RelativeMove> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_RelativeMove::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Translation", &tptz_RelativeMove::Translation, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tptz_RelativeMove::Speed, "tptz", xml_convert::serialize_type::full)
    );
};


// RelativeMoveResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_RelativeMoveResponse {
};


// XmlTraits for tptz_RelativeMoveResponse
template<>
struct xml_convert::XmlTraits<tptz_RelativeMoveResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AbsoluteMove 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_AbsoluteMove {
    // A reference to the MediaProfile.
    tt_ReferenceToken ProfileToken;
    // A Position vector specifying the absolute target position.
    tt_PTZVector Position;
    // An optional Speed.
    std::optional<tt_PTZSpeed> Speed;
};


// XmlTraits for tptz_AbsoluteMove
template<>
struct xml_convert::XmlTraits<tptz_AbsoluteMove> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_AbsoluteMove::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Position", &tptz_AbsoluteMove::Position, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tptz_AbsoluteMove::Speed, "tptz", xml_convert::serialize_type::full)
    );
};


// AbsoluteMoveResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_AbsoluteMoveResponse {
};


// XmlTraits for tptz_AbsoluteMoveResponse
template<>
struct xml_convert::XmlTraits<tptz_AbsoluteMoveResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GeoMove 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GeoMove {
    // A reference to the MediaProfile.
    tt_ReferenceToken ProfileToken;
    // The geolocation of the target position.
    tt_GeoLocation Target;
    // An optional Speed.
    std::optional<tt_PTZSpeed> Speed;
    // An optional indication of the height of the target/area.
    std::optional<float> AreaHeight;
    // An optional indication of the width of the target/area.
    std::optional<float> AreaWidth;
};


// XmlTraits for tptz_GeoMove
template<>
struct xml_convert::XmlTraits<tptz_GeoMove> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_GeoMove::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Target", &tptz_GeoMove::Target, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tptz_GeoMove::Speed, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AreaHeight", &tptz_GeoMove::AreaHeight, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AreaWidth", &tptz_GeoMove::AreaWidth, "tptz", xml_convert::serialize_type::full)
    );
};


// GeoMoveResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GeoMoveResponse {
};


// XmlTraits for tptz_GeoMoveResponse
template<>
struct xml_convert::XmlTraits<tptz_GeoMoveResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Stop 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_Stop {
    // A reference to the MediaProfile that indicate what should be stopped.
    tt_ReferenceToken ProfileToken;
    // Set true when we want to stop ongoing pan and tilt movements.If PanTilt arguments are not present, this command stops these movements.
    std::optional<bool> PanTilt;
    // Set true when we want to stop ongoing zoom movement.If Zoom arguments are not present, this command stops ongoing zoom movement.
    std::optional<bool> Zoom;
};


// XmlTraits for tptz_Stop
template<>
struct xml_convert::XmlTraits<tptz_Stop> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_Stop::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PanTilt", &tptz_Stop::PanTilt, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Zoom", &tptz_Stop::Zoom, "tptz", xml_convert::serialize_type::full)
    );
};


// StopResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_StopResponse {
};


// XmlTraits for tptz_StopResponse
template<>
struct xml_convert::XmlTraits<tptz_StopResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetPresetTours 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetPresetTours {
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for tptz_GetPresetTours
template<>
struct xml_convert::XmlTraits<tptz_GetPresetTours> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_GetPresetTours::ProfileToken, "tptz", xml_convert::serialize_type::full)
    );
};


// GetPresetToursResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetPresetToursResponse {
    std::vector<tt_PresetTour> PresetTour;
};


// XmlTraits for tptz_GetPresetToursResponse
template<>
struct xml_convert::XmlTraits<tptz_GetPresetToursResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PresetTour", &tptz_GetPresetToursResponse::PresetTour, "tptz", xml_convert::serialize_type::full)
    );
};


// GetPresetTour 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetPresetTour {
    tt_ReferenceToken ProfileToken;
    tt_ReferenceToken PresetTourToken;
};


// XmlTraits for tptz_GetPresetTour
template<>
struct xml_convert::XmlTraits<tptz_GetPresetTour> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_GetPresetTour::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetTourToken", &tptz_GetPresetTour::PresetTourToken, "tptz", xml_convert::serialize_type::full)
    );
};


// GetPresetTourResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetPresetTourResponse {
    tt_PresetTour PresetTour;
};


// XmlTraits for tptz_GetPresetTourResponse
template<>
struct xml_convert::XmlTraits<tptz_GetPresetTourResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PresetTour", &tptz_GetPresetTourResponse::PresetTour, "tptz", xml_convert::serialize_type::full)
    );
};


// GetPresetTourOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetPresetTourOptions {
    tt_ReferenceToken ProfileToken;
    std::optional<tt_ReferenceToken> PresetTourToken;
};


// XmlTraits for tptz_GetPresetTourOptions
template<>
struct xml_convert::XmlTraits<tptz_GetPresetTourOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_GetPresetTourOptions::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetTourToken", &tptz_GetPresetTourOptions::PresetTourToken, "tptz", xml_convert::serialize_type::full)
    );
};


// GetPresetTourOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetPresetTourOptionsResponse {
    tt_PTZPresetTourOptions Options;
};


// XmlTraits for tptz_GetPresetTourOptionsResponse
template<>
struct xml_convert::XmlTraits<tptz_GetPresetTourOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tptz_GetPresetTourOptionsResponse::Options, "tptz", xml_convert::serialize_type::full)
    );
};


// CreatePresetTour 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_CreatePresetTour {
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for tptz_CreatePresetTour
template<>
struct xml_convert::XmlTraits<tptz_CreatePresetTour> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_CreatePresetTour::ProfileToken, "tptz", xml_convert::serialize_type::full)
    );
};


// CreatePresetTourResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_CreatePresetTourResponse {
    tt_ReferenceToken PresetTourToken;
};


// XmlTraits for tptz_CreatePresetTourResponse
template<>
struct xml_convert::XmlTraits<tptz_CreatePresetTourResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PresetTourToken", &tptz_CreatePresetTourResponse::PresetTourToken, "tptz", xml_convert::serialize_type::full)
    );
};


// ModifyPresetTour 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_ModifyPresetTour {
    tt_ReferenceToken ProfileToken;
    tt_PresetTour PresetTour;
};


// XmlTraits for tptz_ModifyPresetTour
template<>
struct xml_convert::XmlTraits<tptz_ModifyPresetTour> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_ModifyPresetTour::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetTour", &tptz_ModifyPresetTour::PresetTour, "tptz", xml_convert::serialize_type::full)
    );
};


// ModifyPresetTourResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_ModifyPresetTourResponse {
};


// XmlTraits for tptz_ModifyPresetTourResponse
template<>
struct xml_convert::XmlTraits<tptz_ModifyPresetTourResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// OperatePresetTour 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_OperatePresetTour {
    tt_ReferenceToken ProfileToken;
    tt_ReferenceToken PresetTourToken;
    tt_PTZPresetTourOperation Operation;
};


// XmlTraits for tptz_OperatePresetTour
template<>
struct xml_convert::XmlTraits<tptz_OperatePresetTour> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_OperatePresetTour::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetTourToken", &tptz_OperatePresetTour::PresetTourToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Operation", &tptz_OperatePresetTour::Operation, "tptz", xml_convert::serialize_type::full)
    );
};


// OperatePresetTourResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_OperatePresetTourResponse {
};


// XmlTraits for tptz_OperatePresetTourResponse
template<>
struct xml_convert::XmlTraits<tptz_OperatePresetTourResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemovePresetTour 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_RemovePresetTour {
    tt_ReferenceToken ProfileToken;
    tt_ReferenceToken PresetTourToken;
};


// XmlTraits for tptz_RemovePresetTour
template<>
struct xml_convert::XmlTraits<tptz_RemovePresetTour> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_RemovePresetTour::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetTourToken", &tptz_RemovePresetTour::PresetTourToken, "tptz", xml_convert::serialize_type::full)
    );
};


// RemovePresetTourResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_RemovePresetTourResponse {
};


// XmlTraits for tptz_RemovePresetTourResponse
template<>
struct xml_convert::XmlTraits<tptz_RemovePresetTourResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetCompatibleConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetCompatibleConfigurations {
    // Contains the token of an existing media profile the configurations shall be compatible with.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for tptz_GetCompatibleConfigurations
template<>
struct xml_convert::XmlTraits<tptz_GetCompatibleConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_GetCompatibleConfigurations::ProfileToken, "tptz", xml_convert::serialize_type::full)
    );
};


// GetCompatibleConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_GetCompatibleConfigurationsResponse {
    // A list of all existing PTZConfigurations on the NVT that is suitable to be added to the addressed media profile.
    std::vector<tt_PTZConfiguration> PTZConfiguration;
};


// XmlTraits for tptz_GetCompatibleConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tptz_GetCompatibleConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZConfiguration", &tptz_GetCompatibleConfigurationsResponse::PTZConfiguration, "tptz", xml_convert::serialize_type::full)
    );
};


// MoveAndStartTracking 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_MoveAndStartTracking {
    // A reference to the MediaProfile where the operation should take place.
    tt_ReferenceToken ProfileToken;
    // A preset token.
    std::optional<tt_ReferenceToken> PresetToken;
    // The geolocation of the target position.
    std::optional<tt_GeoLocation> GeoLocation;
    // A Position vector specifying the absolute target position.
    std::optional<tt_PTZVector> TargetPosition;
    // Speed vector specifying the velocity of pan, tilt and zoom.
    std::optional<tt_PTZSpeed> Speed;
    // Object ID of the object to track.
    std::optional<int64_t> ObjectID;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tptz_MoveAndStartTracking
template<>
struct xml_convert::XmlTraits<tptz_MoveAndStartTracking> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &tptz_MoveAndStartTracking::ProfileToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PresetToken", &tptz_MoveAndStartTracking::PresetToken, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("GeoLocation", &tptz_MoveAndStartTracking::GeoLocation, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TargetPosition", &tptz_MoveAndStartTracking::TargetPosition, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tptz_MoveAndStartTracking::Speed, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ObjectID", &tptz_MoveAndStartTracking::ObjectID, "tptz", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tptz_MoveAndStartTracking::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// MoveAndStartTrackingResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/ptz/wsdl
// 源文件: ptz_v20.wsdl
struct tptz_MoveAndStartTrackingResponse {
};


// XmlTraits for tptz_MoveAndStartTrackingResponse
template<>
struct xml_convert::XmlTraits<tptz_MoveAndStartTrackingResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


} // namespace libonvif_client
