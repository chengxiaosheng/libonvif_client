/**
 * @file trt.h
 * @brief 从 media_v10.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver10/media/wsdl
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
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetServiceCapabilities {
};


// XmlTraits for trt_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<trt_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// ProfileCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_ProfileCapabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Maximum number of profiles supported.
    std::optional<int32_t> MaximumNumberOfProfiles;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for trt_ProfileCapabilities
template<>
struct xml_convert::XmlTraits<trt_ProfileCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &trt_ProfileCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("MaximumNumberOfProfiles", &trt_ProfileCapabilities::MaximumNumberOfProfiles, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &trt_ProfileCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// StreamingCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_StreamingCapabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicates support for RTP multicast.
    std::optional<bool> RTPMulticast;
    // Indicates support for RTP over TCP.
    std::optional<bool> RTP_TCP;
    // Indicates support for RTP/RTSP/TCP.
    std::optional<bool> RTP_RTSP_TCP;
    // Indicates support for non aggregate RTSP control.
    std::optional<bool> NonAggregateControl;
    // Indicates the device does not support live media streaming via RTSP.
    std::optional<bool> NoRTSPStreaming;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for trt_StreamingCapabilities
template<>
struct xml_convert::XmlTraits<trt_StreamingCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &trt_StreamingCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("RTPMulticast", &trt_StreamingCapabilities::RTPMulticast, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RTP_TCP", &trt_StreamingCapabilities::RTP_TCP, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RTP_RTSP_TCP", &trt_StreamingCapabilities::RTP_RTSP_TCP, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("NonAggregateControl", &trt_StreamingCapabilities::NonAggregateControl, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("NoRTSPStreaming", &trt_StreamingCapabilities::NoRTSPStreaming, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &trt_StreamingCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_Capabilities {
    // Media profile capabilities.
    trt_ProfileCapabilities ProfileCapabilities;
    // Streaming capabilities.
    trt_StreamingCapabilities StreamingCapabilities;
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
    // Indicates the support for the Efficient XML Interchange (EXI) binary XML format.
    std::optional<bool> EXICompression;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for trt_Capabilities
template<>
struct xml_convert::XmlTraits<trt_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileCapabilities", &trt_Capabilities::ProfileCapabilities, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StreamingCapabilities", &trt_Capabilities::StreamingCapabilities, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trt_Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("SnapshotUri", &trt_Capabilities::SnapshotUri, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Rotation", &trt_Capabilities::Rotation, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("VideoSourceMode", &trt_Capabilities::VideoSourceMode, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("OSD", &trt_Capabilities::OSD, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("TemporaryOSDText", &trt_Capabilities::TemporaryOSDText, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("EXICompression", &trt_Capabilities::EXICompression, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &trt_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetServiceCapabilitiesResponse {
    // The capabilities for the media service is returned in the Capabilities element.
    trt_Capabilities Capabilities;
};


// XmlTraits for trt_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<trt_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &trt_GetServiceCapabilitiesResponse::Capabilities, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoSources 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoSources {
};


// XmlTraits for trt_GetVideoSources
template<>
struct xml_convert::XmlTraits<trt_GetVideoSources> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetVideoSourcesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoSourcesResponse {
    // List of existing Video Sources
    std::vector<tt_VideoSource> VideoSources;
};


// XmlTraits for trt_GetVideoSourcesResponse
template<>
struct xml_convert::XmlTraits<trt_GetVideoSourcesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSources", &trt_GetVideoSourcesResponse::VideoSources, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioSources 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioSources {
};


// XmlTraits for trt_GetAudioSources
template<>
struct xml_convert::XmlTraits<trt_GetAudioSources> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAudioSourcesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioSourcesResponse {
    // List of existing Audio Sources
    std::vector<tt_AudioSource> AudioSources;
};


// XmlTraits for trt_GetAudioSourcesResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioSourcesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AudioSources", &trt_GetAudioSourcesResponse::AudioSources, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioOutputs 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioOutputs {
};


// XmlTraits for trt_GetAudioOutputs
template<>
struct xml_convert::XmlTraits<trt_GetAudioOutputs> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAudioOutputsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioOutputsResponse {
    // List of existing Audio Outputs
    std::vector<tt_AudioOutput> AudioOutputs;
};


// XmlTraits for trt_GetAudioOutputsResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioOutputsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AudioOutputs", &trt_GetAudioOutputsResponse::AudioOutputs, "trt", xml_convert::serialize_type::full)
    );
};


// CreateProfile 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_CreateProfile {
    // friendly name of the profile to be created
    tt_Name Name;
    // Optional token, specifying the unique identifier of the new profile. A device supports at least a token length of 12 characters and characters "A-Z" | "a-z" | "0-9" | "-.".
    std::optional<tt_ReferenceToken> Token;
};


// XmlTraits for trt_CreateProfile
template<>
struct xml_convert::XmlTraits<trt_CreateProfile> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &trt_CreateProfile::Name, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Token", &trt_CreateProfile::Token, "trt", xml_convert::serialize_type::full)
    );
};


// CreateProfileResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_CreateProfileResponse {
    // returns the new created profile
    tt_Profile Profile;
};


// XmlTraits for trt_CreateProfileResponse
template<>
struct xml_convert::XmlTraits<trt_CreateProfileResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Profile", &trt_CreateProfileResponse::Profile, "trt", xml_convert::serialize_type::full)
    );
};


// GetProfile 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetProfile {
    // this command requests a specific profile
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetProfile
template<>
struct xml_convert::XmlTraits<trt_GetProfile> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_GetProfile::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetProfileResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetProfileResponse {
    // returns the requested media profile
    tt_Profile Profile;
};


// XmlTraits for trt_GetProfileResponse
template<>
struct xml_convert::XmlTraits<trt_GetProfileResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Profile", &trt_GetProfileResponse::Profile, "trt", xml_convert::serialize_type::full)
    );
};


// GetProfiles 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetProfiles {
};


// XmlTraits for trt_GetProfiles
template<>
struct xml_convert::XmlTraits<trt_GetProfiles> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetProfilesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetProfilesResponse {
    // lists all profiles that exist in the media service
    std::vector<tt_Profile> Profiles;
};


// XmlTraits for trt_GetProfilesResponse
template<>
struct xml_convert::XmlTraits<trt_GetProfilesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Profiles", &trt_GetProfilesResponse::Profiles, "trt", xml_convert::serialize_type::full)
    );
};


// AddVideoEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddVideoEncoderConfiguration {
    // Reference to the profile where the configuration should be added
    tt_ReferenceToken ProfileToken;
    // Contains a reference to the VideoEncoderConfiguration to add
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_AddVideoEncoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_AddVideoEncoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_AddVideoEncoderConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &trt_AddVideoEncoderConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// AddVideoEncoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddVideoEncoderConfigurationResponse {
};


// XmlTraits for trt_AddVideoEncoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_AddVideoEncoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveVideoEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveVideoEncoderConfiguration {
    /*
     * Contains a reference to the media profile from which the
     * VideoEncoderConfiguration shall be removed.
     */
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_RemoveVideoEncoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_RemoveVideoEncoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_RemoveVideoEncoderConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// RemoveVideoEncoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveVideoEncoderConfigurationResponse {
};


// XmlTraits for trt_RemoveVideoEncoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_RemoveVideoEncoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AddVideoSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddVideoSourceConfiguration {
    // Reference to the profile where the configuration should be added
    tt_ReferenceToken ProfileToken;
    // Contains a reference to the VideoSourceConfiguration to add
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_AddVideoSourceConfiguration
template<>
struct xml_convert::XmlTraits<trt_AddVideoSourceConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_AddVideoSourceConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &trt_AddVideoSourceConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// AddVideoSourceConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddVideoSourceConfigurationResponse {
};


// XmlTraits for trt_AddVideoSourceConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_AddVideoSourceConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveVideoSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveVideoSourceConfiguration {
    /*
     * Contains a reference to the media profile from which the
     * VideoSourceConfiguration shall be removed.
     */
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_RemoveVideoSourceConfiguration
template<>
struct xml_convert::XmlTraits<trt_RemoveVideoSourceConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_RemoveVideoSourceConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// RemoveVideoSourceConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveVideoSourceConfigurationResponse {
};


// XmlTraits for trt_RemoveVideoSourceConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_RemoveVideoSourceConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AddAudioEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddAudioEncoderConfiguration {
    // Reference to the profile where the configuration should be added
    tt_ReferenceToken ProfileToken;
    // Contains a reference to the AudioEncoderConfiguration to add
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_AddAudioEncoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_AddAudioEncoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_AddAudioEncoderConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &trt_AddAudioEncoderConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// AddAudioEncoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddAudioEncoderConfigurationResponse {
};


// XmlTraits for trt_AddAudioEncoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_AddAudioEncoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveAudioEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveAudioEncoderConfiguration {
    /*
     * Contains a reference to the media profile from which the
     * AudioEncoderConfiguration shall be removed.
     */
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_RemoveAudioEncoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_RemoveAudioEncoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_RemoveAudioEncoderConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// RemoveAudioEncoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveAudioEncoderConfigurationResponse {
};


// XmlTraits for trt_RemoveAudioEncoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_RemoveAudioEncoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AddAudioSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddAudioSourceConfiguration {
    // Reference to the profile where the configuration should be added
    tt_ReferenceToken ProfileToken;
    // Contains a reference to the AudioSourceConfiguration to add
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_AddAudioSourceConfiguration
template<>
struct xml_convert::XmlTraits<trt_AddAudioSourceConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_AddAudioSourceConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &trt_AddAudioSourceConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// AddAudioSourceConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddAudioSourceConfigurationResponse {
};


// XmlTraits for trt_AddAudioSourceConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_AddAudioSourceConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveAudioSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveAudioSourceConfiguration {
    /*
     * Contains a reference to the media profile from which the
     * AudioSourceConfiguration shall be removed.
     */
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_RemoveAudioSourceConfiguration
template<>
struct xml_convert::XmlTraits<trt_RemoveAudioSourceConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_RemoveAudioSourceConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// RemoveAudioSourceConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveAudioSourceConfigurationResponse {
};


// XmlTraits for trt_RemoveAudioSourceConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_RemoveAudioSourceConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AddPTZConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddPTZConfiguration {
    // Reference to the profile where the configuration should be added
    tt_ReferenceToken ProfileToken;
    // Contains a reference to the PTZConfiguration to add
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_AddPTZConfiguration
template<>
struct xml_convert::XmlTraits<trt_AddPTZConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_AddPTZConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &trt_AddPTZConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// AddPTZConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddPTZConfigurationResponse {
};


// XmlTraits for trt_AddPTZConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_AddPTZConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemovePTZConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemovePTZConfiguration {
    /*
     * Contains a reference to the media profile from which the
     * PTZConfiguration shall be removed.
     */
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_RemovePTZConfiguration
template<>
struct xml_convert::XmlTraits<trt_RemovePTZConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_RemovePTZConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// RemovePTZConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemovePTZConfigurationResponse {
};


// XmlTraits for trt_RemovePTZConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_RemovePTZConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AddVideoAnalyticsConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddVideoAnalyticsConfiguration {
    // Reference to the profile where the configuration should be added
    tt_ReferenceToken ProfileToken;
    // Contains a reference to the VideoAnalyticsConfiguration to add
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_AddVideoAnalyticsConfiguration
template<>
struct xml_convert::XmlTraits<trt_AddVideoAnalyticsConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_AddVideoAnalyticsConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &trt_AddVideoAnalyticsConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// AddVideoAnalyticsConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddVideoAnalyticsConfigurationResponse {
};


// XmlTraits for trt_AddVideoAnalyticsConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_AddVideoAnalyticsConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveVideoAnalyticsConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveVideoAnalyticsConfiguration {
    /*
     * Contains a reference to the media profile from which the
     * VideoAnalyticsConfiguration shall be removed.
     */
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_RemoveVideoAnalyticsConfiguration
template<>
struct xml_convert::XmlTraits<trt_RemoveVideoAnalyticsConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_RemoveVideoAnalyticsConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// RemoveVideoAnalyticsConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveVideoAnalyticsConfigurationResponse {
};


// XmlTraits for trt_RemoveVideoAnalyticsConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_RemoveVideoAnalyticsConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AddMetadataConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddMetadataConfiguration {
    // Reference to the profile where the configuration should be added
    tt_ReferenceToken ProfileToken;
    // Contains a reference to the MetadataConfiguration to add
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_AddMetadataConfiguration
template<>
struct xml_convert::XmlTraits<trt_AddMetadataConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_AddMetadataConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &trt_AddMetadataConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// AddMetadataConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddMetadataConfigurationResponse {
};


// XmlTraits for trt_AddMetadataConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_AddMetadataConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveMetadataConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveMetadataConfiguration {
    /*
     * Contains a reference to the media profile from which the
     * MetadataConfiguration shall be removed.
     */
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_RemoveMetadataConfiguration
template<>
struct xml_convert::XmlTraits<trt_RemoveMetadataConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_RemoveMetadataConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// RemoveMetadataConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveMetadataConfigurationResponse {
};


// XmlTraits for trt_RemoveMetadataConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_RemoveMetadataConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AddAudioOutputConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddAudioOutputConfiguration {
    // Reference to the profile where the configuration should be added
    tt_ReferenceToken ProfileToken;
    // Contains a reference to the AudioOutputConfiguration to add
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_AddAudioOutputConfiguration
template<>
struct xml_convert::XmlTraits<trt_AddAudioOutputConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_AddAudioOutputConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &trt_AddAudioOutputConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// AddAudioOutputConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddAudioOutputConfigurationResponse {
};


// XmlTraits for trt_AddAudioOutputConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_AddAudioOutputConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveAudioOutputConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveAudioOutputConfiguration {
    /*
     * Contains a reference to the media profile from which the
     * AudioOutputConfiguration shall be removed.
     */
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_RemoveAudioOutputConfiguration
template<>
struct xml_convert::XmlTraits<trt_RemoveAudioOutputConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_RemoveAudioOutputConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// RemoveAudioOutputConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveAudioOutputConfigurationResponse {
};


// XmlTraits for trt_RemoveAudioOutputConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_RemoveAudioOutputConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AddAudioDecoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddAudioDecoderConfiguration {
    // This element contains a reference to the profile where the configuration should be added.
    tt_ReferenceToken ProfileToken;
    // This element contains a reference to the AudioDecoderConfiguration to add.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_AddAudioDecoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_AddAudioDecoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_AddAudioDecoderConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &trt_AddAudioDecoderConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// AddAudioDecoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_AddAudioDecoderConfigurationResponse {
};


// XmlTraits for trt_AddAudioDecoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_AddAudioDecoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveAudioDecoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveAudioDecoderConfiguration {
    // This element contains a  reference to the media profile from which the AudioDecoderConfiguration shall be removed.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_RemoveAudioDecoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_RemoveAudioDecoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_RemoveAudioDecoderConfiguration::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// RemoveAudioDecoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_RemoveAudioDecoderConfigurationResponse {
};


// XmlTraits for trt_RemoveAudioDecoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_RemoveAudioDecoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteProfile 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_DeleteProfile {
    // This element contains a  reference to the profile that should be deleted.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_DeleteProfile
template<>
struct xml_convert::XmlTraits<trt_DeleteProfile> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_DeleteProfile::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// DeleteProfileResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_DeleteProfileResponse {
};


// XmlTraits for trt_DeleteProfileResponse
template<>
struct xml_convert::XmlTraits<trt_DeleteProfileResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetVideoEncoderConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoEncoderConfigurations {
};


// XmlTraits for trt_GetVideoEncoderConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetVideoEncoderConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetVideoEncoderConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoEncoderConfigurationsResponse {
    // This element contains a list of video encoder configurations.
    std::vector<tt_VideoEncoderConfiguration> Configurations;
};


// XmlTraits for trt_GetVideoEncoderConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetVideoEncoderConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetVideoEncoderConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoSourceConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoSourceConfigurations {
};


// XmlTraits for trt_GetVideoSourceConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetVideoSourceConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetVideoSourceConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoSourceConfigurationsResponse {
    // This element contains a list of video source configurations.
    std::vector<tt_VideoSourceConfiguration> Configurations;
};


// XmlTraits for trt_GetVideoSourceConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetVideoSourceConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetVideoSourceConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioEncoderConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioEncoderConfigurations {
};


// XmlTraits for trt_GetAudioEncoderConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetAudioEncoderConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAudioEncoderConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioEncoderConfigurationsResponse {
    // This element contains a list of audio encoder configurations.
    std::vector<tt_AudioEncoderConfiguration> Configurations;
};


// XmlTraits for trt_GetAudioEncoderConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioEncoderConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetAudioEncoderConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioSourceConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioSourceConfigurations {
};


// XmlTraits for trt_GetAudioSourceConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetAudioSourceConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAudioSourceConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioSourceConfigurationsResponse {
    // This element contains a list of audio source configurations.
    std::vector<tt_AudioSourceConfiguration> Configurations;
};


// XmlTraits for trt_GetAudioSourceConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioSourceConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetAudioSourceConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoAnalyticsConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoAnalyticsConfigurations {
};


// XmlTraits for trt_GetVideoAnalyticsConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetVideoAnalyticsConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetVideoAnalyticsConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoAnalyticsConfigurationsResponse {
    // This element contains a list of VideoAnalytics configurations.
    std::vector<tt_VideoAnalyticsConfiguration> Configurations;
};


// XmlTraits for trt_GetVideoAnalyticsConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetVideoAnalyticsConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetVideoAnalyticsConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetMetadataConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetMetadataConfigurations {
};


// XmlTraits for trt_GetMetadataConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetMetadataConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetMetadataConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetMetadataConfigurationsResponse {
    // This element contains a list of metadata configurations
    std::vector<tt_MetadataConfiguration> Configurations;
};


// XmlTraits for trt_GetMetadataConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetMetadataConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetMetadataConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioOutputConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioOutputConfigurations {
};


// XmlTraits for trt_GetAudioOutputConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetAudioOutputConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAudioOutputConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioOutputConfigurationsResponse {
    // This element contains a list of audio output configurations
    std::vector<tt_AudioOutputConfiguration> Configurations;
};


// XmlTraits for trt_GetAudioOutputConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioOutputConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetAudioOutputConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioDecoderConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioDecoderConfigurations {
};


// XmlTraits for trt_GetAudioDecoderConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetAudioDecoderConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAudioDecoderConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioDecoderConfigurationsResponse {
    // This element contains a list of audio decoder configurations
    std::vector<tt_AudioDecoderConfiguration> Configurations;
};


// XmlTraits for trt_GetAudioDecoderConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioDecoderConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetAudioDecoderConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoSourceConfiguration {
    // Token of the requested video source configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_GetVideoSourceConfiguration
template<>
struct xml_convert::XmlTraits<trt_GetVideoSourceConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetVideoSourceConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoSourceConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoSourceConfigurationResponse {
    // The requested video source configuration.
    tt_VideoSourceConfiguration Configuration;
};


// XmlTraits for trt_GetVideoSourceConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_GetVideoSourceConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_GetVideoSourceConfigurationResponse::Configuration, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoEncoderConfiguration {
    // Token of the requested video encoder configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_GetVideoEncoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_GetVideoEncoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetVideoEncoderConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoEncoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoEncoderConfigurationResponse {
    // The requested video encoder configuration.
    tt_VideoEncoderConfiguration Configuration;
};


// XmlTraits for trt_GetVideoEncoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_GetVideoEncoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_GetVideoEncoderConfigurationResponse::Configuration, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioSourceConfiguration {
    // Token of the requested audio source configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_GetAudioSourceConfiguration
template<>
struct xml_convert::XmlTraits<trt_GetAudioSourceConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetAudioSourceConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioSourceConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioSourceConfigurationResponse {
    // The requested audio source configuration.
    tt_AudioSourceConfiguration Configuration;
};


// XmlTraits for trt_GetAudioSourceConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioSourceConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_GetAudioSourceConfigurationResponse::Configuration, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioEncoderConfiguration {
    // Token of the requested audio encoder configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_GetAudioEncoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_GetAudioEncoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetAudioEncoderConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioEncoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioEncoderConfigurationResponse {
    // The requested audio encoder configuration
    tt_AudioEncoderConfiguration Configuration;
};


// XmlTraits for trt_GetAudioEncoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioEncoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_GetAudioEncoderConfigurationResponse::Configuration, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoAnalyticsConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoAnalyticsConfiguration {
    // Token of the requested video analytics configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_GetVideoAnalyticsConfiguration
template<>
struct xml_convert::XmlTraits<trt_GetVideoAnalyticsConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetVideoAnalyticsConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoAnalyticsConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoAnalyticsConfigurationResponse {
    // The requested video analytics configuration.
    tt_VideoAnalyticsConfiguration Configuration;
};


// XmlTraits for trt_GetVideoAnalyticsConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_GetVideoAnalyticsConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_GetVideoAnalyticsConfigurationResponse::Configuration, "trt", xml_convert::serialize_type::full)
    );
};


// GetMetadataConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetMetadataConfiguration {
    // Token of the requested metadata configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_GetMetadataConfiguration
template<>
struct xml_convert::XmlTraits<trt_GetMetadataConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetMetadataConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetMetadataConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetMetadataConfigurationResponse {
    // The requested metadata configuration.
    tt_MetadataConfiguration Configuration;
};


// XmlTraits for trt_GetMetadataConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_GetMetadataConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_GetMetadataConfigurationResponse::Configuration, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioOutputConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioOutputConfiguration {
    // Token of the requested audio output configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_GetAudioOutputConfiguration
template<>
struct xml_convert::XmlTraits<trt_GetAudioOutputConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetAudioOutputConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioOutputConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioOutputConfigurationResponse {
    // The requested audio output configuration.
    tt_AudioOutputConfiguration Configuration;
};


// XmlTraits for trt_GetAudioOutputConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioOutputConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_GetAudioOutputConfigurationResponse::Configuration, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioDecoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioDecoderConfiguration {
    // Token of the requested audio decoder configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_GetAudioDecoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_GetAudioDecoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetAudioDecoderConfiguration::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioDecoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioDecoderConfigurationResponse {
    // The requested audio decoder configuration
    tt_AudioDecoderConfiguration Configuration;
};


// XmlTraits for trt_GetAudioDecoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioDecoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_GetAudioDecoderConfigurationResponse::Configuration, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleVideoEncoderConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleVideoEncoderConfigurations {
    // Contains the token of an existing media profile the configurations shall be compatible with.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetCompatibleVideoEncoderConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleVideoEncoderConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_GetCompatibleVideoEncoderConfigurations::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleVideoEncoderConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleVideoEncoderConfigurationsResponse {
    // Contains a list of video encoder configurations that are compatible with the specified media profile.
    std::vector<tt_VideoEncoderConfiguration> Configurations;
};


// XmlTraits for trt_GetCompatibleVideoEncoderConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleVideoEncoderConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetCompatibleVideoEncoderConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleVideoSourceConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleVideoSourceConfigurations {
    // Contains the token of an existing media profile the configurations shall be compatible with.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetCompatibleVideoSourceConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleVideoSourceConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_GetCompatibleVideoSourceConfigurations::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleVideoSourceConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleVideoSourceConfigurationsResponse {
    // Contains a list of video source configurations that are compatible with the specified media profile.
    std::vector<tt_VideoSourceConfiguration> Configurations;
};


// XmlTraits for trt_GetCompatibleVideoSourceConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleVideoSourceConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetCompatibleVideoSourceConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleAudioEncoderConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleAudioEncoderConfigurations {
    // Contains the token of an existing media profile the configurations shall be compatible with.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetCompatibleAudioEncoderConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleAudioEncoderConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_GetCompatibleAudioEncoderConfigurations::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleAudioEncoderConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleAudioEncoderConfigurationsResponse {
    // Contains a list of audio encoder configurations that are compatible with the specified media profile.
    std::vector<tt_AudioEncoderConfiguration> Configurations;
};


// XmlTraits for trt_GetCompatibleAudioEncoderConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleAudioEncoderConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetCompatibleAudioEncoderConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleAudioSourceConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleAudioSourceConfigurations {
    // Contains the token of an existing media profile the configurations shall be compatible with.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetCompatibleAudioSourceConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleAudioSourceConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_GetCompatibleAudioSourceConfigurations::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleAudioSourceConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleAudioSourceConfigurationsResponse {
    // Contains a list of audio source configurations that are compatible with the specified media profile.
    std::vector<tt_AudioSourceConfiguration> Configurations;
};


// XmlTraits for trt_GetCompatibleAudioSourceConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleAudioSourceConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetCompatibleAudioSourceConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleVideoAnalyticsConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleVideoAnalyticsConfigurations {
    // Contains the token of an existing media profile the configurations shall be compatible with.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetCompatibleVideoAnalyticsConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleVideoAnalyticsConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_GetCompatibleVideoAnalyticsConfigurations::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleVideoAnalyticsConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleVideoAnalyticsConfigurationsResponse {
    // Contains a list of video analytics configurations that are compatible with the specified media profile.
    std::vector<tt_VideoAnalyticsConfiguration> Configurations;
};


// XmlTraits for trt_GetCompatibleVideoAnalyticsConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleVideoAnalyticsConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetCompatibleVideoAnalyticsConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleMetadataConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleMetadataConfigurations {
    // Contains the token of an existing media profile the configurations shall be compatible with.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetCompatibleMetadataConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleMetadataConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_GetCompatibleMetadataConfigurations::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleMetadataConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleMetadataConfigurationsResponse {
    // Contains a list of metadata configurations that are compatible with the specified media profile.
    std::vector<tt_MetadataConfiguration> Configurations;
};


// XmlTraits for trt_GetCompatibleMetadataConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleMetadataConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetCompatibleMetadataConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleAudioOutputConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleAudioOutputConfigurations {
    // Contains the token of an existing media profile the configurations shall be compatible with.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetCompatibleAudioOutputConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleAudioOutputConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_GetCompatibleAudioOutputConfigurations::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleAudioOutputConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleAudioOutputConfigurationsResponse {
    // Contains a list of audio output configurations that are compatible with the specified media profile.
    std::vector<tt_AudioOutputConfiguration> Configurations;
};


// XmlTraits for trt_GetCompatibleAudioOutputConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleAudioOutputConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetCompatibleAudioOutputConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleAudioDecoderConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleAudioDecoderConfigurations {
    // Contains the token of an existing media profile the configurations shall be compatible with.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetCompatibleAudioDecoderConfigurations
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleAudioDecoderConfigurations> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_GetCompatibleAudioDecoderConfigurations::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetCompatibleAudioDecoderConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetCompatibleAudioDecoderConfigurationsResponse {
    // Contains a list of audio decoder configurations that are compatible with the specified media profile.
    std::vector<tt_AudioDecoderConfiguration> Configurations;
};


// XmlTraits for trt_GetCompatibleAudioDecoderConfigurationsResponse
template<>
struct xml_convert::XmlTraits<trt_GetCompatibleAudioDecoderConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configurations", &trt_GetCompatibleAudioDecoderConfigurationsResponse::Configurations, "trt", xml_convert::serialize_type::full)
    );
};


// SetVideoEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetVideoEncoderConfiguration {
    // Contains the modified video encoder configuration. The configuration shall exist in the device.
    tt_VideoEncoderConfiguration Configuration;
    // The ForcePersistence element is obsolete and should always be assumed to be true.
    bool ForcePersistence {};
};


// XmlTraits for trt_SetVideoEncoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_SetVideoEncoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_SetVideoEncoderConfiguration::Configuration, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &trt_SetVideoEncoderConfiguration::ForcePersistence, "trt", xml_convert::serialize_type::full)
    );
};


// SetVideoEncoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetVideoEncoderConfigurationResponse {
};


// XmlTraits for trt_SetVideoEncoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_SetVideoEncoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetVideoSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetVideoSourceConfiguration {
    // Contains the modified video source configuration. The configuration shall exist in the device.
    tt_VideoSourceConfiguration Configuration;
    // The ForcePersistence element is obsolete and should always be assumed to be true.
    bool ForcePersistence {};
};


// XmlTraits for trt_SetVideoSourceConfiguration
template<>
struct xml_convert::XmlTraits<trt_SetVideoSourceConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_SetVideoSourceConfiguration::Configuration, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &trt_SetVideoSourceConfiguration::ForcePersistence, "trt", xml_convert::serialize_type::full)
    );
};


// SetVideoSourceConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetVideoSourceConfigurationResponse {
};


// XmlTraits for trt_SetVideoSourceConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_SetVideoSourceConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetAudioEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetAudioEncoderConfiguration {
    // Contains the modified audio encoder configuration. The configuration shall exist in the device.
    tt_AudioEncoderConfiguration Configuration;
    // The ForcePersistence element is obsolete and should always be assumed to be true.
    bool ForcePersistence {};
};


// XmlTraits for trt_SetAudioEncoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_SetAudioEncoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_SetAudioEncoderConfiguration::Configuration, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &trt_SetAudioEncoderConfiguration::ForcePersistence, "trt", xml_convert::serialize_type::full)
    );
};


// SetAudioEncoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetAudioEncoderConfigurationResponse {
};


// XmlTraits for trt_SetAudioEncoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_SetAudioEncoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetAudioSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetAudioSourceConfiguration {
    // Contains the modified audio source configuration. The configuration shall exist in the device.
    tt_AudioSourceConfiguration Configuration;
    // The ForcePersistence element is obsolete and should always be assumed to be true.
    bool ForcePersistence {};
};


// XmlTraits for trt_SetAudioSourceConfiguration
template<>
struct xml_convert::XmlTraits<trt_SetAudioSourceConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_SetAudioSourceConfiguration::Configuration, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &trt_SetAudioSourceConfiguration::ForcePersistence, "trt", xml_convert::serialize_type::full)
    );
};


// SetAudioSourceConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetAudioSourceConfigurationResponse {
};


// XmlTraits for trt_SetAudioSourceConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_SetAudioSourceConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetVideoAnalyticsConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetVideoAnalyticsConfiguration {
    // Contains the modified video analytics configuration. The configuration shall exist in the device.
    tt_VideoAnalyticsConfiguration Configuration;
    // The ForcePersistence element is obsolete and should always be assumed to be true.
    bool ForcePersistence {};
};


// XmlTraits for trt_SetVideoAnalyticsConfiguration
template<>
struct xml_convert::XmlTraits<trt_SetVideoAnalyticsConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_SetVideoAnalyticsConfiguration::Configuration, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &trt_SetVideoAnalyticsConfiguration::ForcePersistence, "trt", xml_convert::serialize_type::full)
    );
};


// SetVideoAnalyticsConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetVideoAnalyticsConfigurationResponse {
};


// XmlTraits for trt_SetVideoAnalyticsConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_SetVideoAnalyticsConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetMetadataConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetMetadataConfiguration {
    // Contains the modified metadata configuration. The configuration shall exist in the device.
    tt_MetadataConfiguration Configuration;
    // The ForcePersistence element is obsolete and should always be assumed to be true.
    bool ForcePersistence {};
};


// XmlTraits for trt_SetMetadataConfiguration
template<>
struct xml_convert::XmlTraits<trt_SetMetadataConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_SetMetadataConfiguration::Configuration, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &trt_SetMetadataConfiguration::ForcePersistence, "trt", xml_convert::serialize_type::full)
    );
};


// SetMetadataConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetMetadataConfigurationResponse {
};


// XmlTraits for trt_SetMetadataConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_SetMetadataConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetAudioOutputConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetAudioOutputConfiguration {
    // Contains the modified audio output configuration. The configuration shall exist in the device.
    tt_AudioOutputConfiguration Configuration;
    // The ForcePersistence element is obsolete and should always be assumed to be true.
    bool ForcePersistence {};
};


// XmlTraits for trt_SetAudioOutputConfiguration
template<>
struct xml_convert::XmlTraits<trt_SetAudioOutputConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_SetAudioOutputConfiguration::Configuration, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &trt_SetAudioOutputConfiguration::ForcePersistence, "trt", xml_convert::serialize_type::full)
    );
};


// SetAudioOutputConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetAudioOutputConfigurationResponse {
};


// XmlTraits for trt_SetAudioOutputConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_SetAudioOutputConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetAudioDecoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetAudioDecoderConfiguration {
    // Contains the modified audio decoder configuration. The configuration shall exist in the device.
    tt_AudioDecoderConfiguration Configuration;
    // The ForcePersistence element is obsolete and should always be assumed to be true.
    bool ForcePersistence {};
};


// XmlTraits for trt_SetAudioDecoderConfiguration
template<>
struct xml_convert::XmlTraits<trt_SetAudioDecoderConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Configuration", &trt_SetAudioDecoderConfiguration::Configuration, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ForcePersistence", &trt_SetAudioDecoderConfiguration::ForcePersistence, "trt", xml_convert::serialize_type::full)
    );
};


// SetAudioDecoderConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetAudioDecoderConfigurationResponse {
};


// XmlTraits for trt_SetAudioDecoderConfigurationResponse
template<>
struct xml_convert::XmlTraits<trt_SetAudioDecoderConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetVideoSourceConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoSourceConfigurationOptions {
    // Optional video source configurationToken that specifies an existing configuration that the options are intended for.
    std::optional<tt_ReferenceToken> ConfigurationToken;
    // Optional ProfileToken that specifies an existing media profile that the options shall be compatible with.
    std::optional<tt_ReferenceToken> ProfileToken;
};


// XmlTraits for trt_GetVideoSourceConfigurationOptions
template<>
struct xml_convert::XmlTraits<trt_GetVideoSourceConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetVideoSourceConfigurationOptions::ConfigurationToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProfileToken", &trt_GetVideoSourceConfigurationOptions::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoSourceConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoSourceConfigurationOptionsResponse {
    // This message contains the video source configuration options. If a video source configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    tt_VideoSourceConfigurationOptions Options;
};


// XmlTraits for trt_GetVideoSourceConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<trt_GetVideoSourceConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &trt_GetVideoSourceConfigurationOptionsResponse::Options, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoEncoderConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoEncoderConfigurationOptions {
    // Optional video encoder configuration token that specifies an existing configuration that the options are intended for.
    std::optional<tt_ReferenceToken> ConfigurationToken;
    // Optional ProfileToken that specifies an existing media profile that the options shall be compatible with.
    std::optional<tt_ReferenceToken> ProfileToken;
};


// XmlTraits for trt_GetVideoEncoderConfigurationOptions
template<>
struct xml_convert::XmlTraits<trt_GetVideoEncoderConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetVideoEncoderConfigurationOptions::ConfigurationToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProfileToken", &trt_GetVideoEncoderConfigurationOptions::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoEncoderConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoEncoderConfigurationOptionsResponse {
    tt_VideoEncoderConfigurationOptions Options;
};


// XmlTraits for trt_GetVideoEncoderConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<trt_GetVideoEncoderConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &trt_GetVideoEncoderConfigurationOptionsResponse::Options, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioSourceConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioSourceConfigurationOptions {
    // Optional audio source configuration token that specifies an existing configuration that the options are intended for.
    std::optional<tt_ReferenceToken> ConfigurationToken;
    // Optional ProfileToken that specifies an existing media profile that the options shall be compatible with.
    std::optional<tt_ReferenceToken> ProfileToken;
};


// XmlTraits for trt_GetAudioSourceConfigurationOptions
template<>
struct xml_convert::XmlTraits<trt_GetAudioSourceConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetAudioSourceConfigurationOptions::ConfigurationToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProfileToken", &trt_GetAudioSourceConfigurationOptions::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioSourceConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioSourceConfigurationOptionsResponse {
    // This message contains the audio source configuration options. If a audio source configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    tt_AudioSourceConfigurationOptions Options;
};


// XmlTraits for trt_GetAudioSourceConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioSourceConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &trt_GetAudioSourceConfigurationOptionsResponse::Options, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioEncoderConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioEncoderConfigurationOptions {
    // Optional audio encoder configuration token that specifies an existing configuration that the options are intended for.
    std::optional<tt_ReferenceToken> ConfigurationToken;
    // Optional ProfileToken that specifies an existing media profile that the options shall be compatible with.
    std::optional<tt_ReferenceToken> ProfileToken;
};


// XmlTraits for trt_GetAudioEncoderConfigurationOptions
template<>
struct xml_convert::XmlTraits<trt_GetAudioEncoderConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetAudioEncoderConfigurationOptions::ConfigurationToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProfileToken", &trt_GetAudioEncoderConfigurationOptions::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioEncoderConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioEncoderConfigurationOptionsResponse {
    // This message contains the audio encoder configuration options. If a audio encoder configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    tt_AudioEncoderConfigurationOptions Options;
};


// XmlTraits for trt_GetAudioEncoderConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioEncoderConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &trt_GetAudioEncoderConfigurationOptionsResponse::Options, "trt", xml_convert::serialize_type::full)
    );
};


// GetMetadataConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetMetadataConfigurationOptions {
    // Optional metadata configuration token that specifies an existing configuration that the options are intended for.
    std::optional<tt_ReferenceToken> ConfigurationToken;
    // Optional ProfileToken that specifies an existing media profile that the options shall be compatible with.
    std::optional<tt_ReferenceToken> ProfileToken;
};


// XmlTraits for trt_GetMetadataConfigurationOptions
template<>
struct xml_convert::XmlTraits<trt_GetMetadataConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetMetadataConfigurationOptions::ConfigurationToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProfileToken", &trt_GetMetadataConfigurationOptions::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetMetadataConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetMetadataConfigurationOptionsResponse {
    // This message contains the metadata configuration options. If a metadata configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    tt_MetadataConfigurationOptions Options;
};


// XmlTraits for trt_GetMetadataConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<trt_GetMetadataConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &trt_GetMetadataConfigurationOptionsResponse::Options, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioOutputConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioOutputConfigurationOptions {
    // Optional audio output configuration token that specifies an existing configuration that the options are intended for.
    std::optional<tt_ReferenceToken> ConfigurationToken;
    // Optional ProfileToken that specifies an existing media profile that the options shall be compatible with.
    std::optional<tt_ReferenceToken> ProfileToken;
};


// XmlTraits for trt_GetAudioOutputConfigurationOptions
template<>
struct xml_convert::XmlTraits<trt_GetAudioOutputConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetAudioOutputConfigurationOptions::ConfigurationToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProfileToken", &trt_GetAudioOutputConfigurationOptions::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioOutputConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioOutputConfigurationOptionsResponse {
    // This message contains the audio output configuration options. If a audio output configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    tt_AudioOutputConfigurationOptions Options;
};


// XmlTraits for trt_GetAudioOutputConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioOutputConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &trt_GetAudioOutputConfigurationOptionsResponse::Options, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioDecoderConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioDecoderConfigurationOptions {
    // Optional audio decoder configuration token that specifies an existing configuration that the options are intended for.
    std::optional<tt_ReferenceToken> ConfigurationToken;
    // Optional ProfileToken that specifies an existing media profile that the options shall be compatible with.
    std::optional<tt_ReferenceToken> ProfileToken;
};


// XmlTraits for trt_GetAudioDecoderConfigurationOptions
template<>
struct xml_convert::XmlTraits<trt_GetAudioDecoderConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetAudioDecoderConfigurationOptions::ConfigurationToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProfileToken", &trt_GetAudioDecoderConfigurationOptions::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetAudioDecoderConfigurationOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetAudioDecoderConfigurationOptionsResponse {
    // This message contains the audio decoder configuration options. If a audio decoder configuration is specified, the options shall concern that particular configuration. If a media profile is specified, the options shall be compatible with that media profile. If no tokens are specified, the options shall be considered generic for the device.
    tt_AudioDecoderConfigurationOptions Options;
};


// XmlTraits for trt_GetAudioDecoderConfigurationOptionsResponse
template<>
struct xml_convert::XmlTraits<trt_GetAudioDecoderConfigurationOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &trt_GetAudioDecoderConfigurationOptionsResponse::Options, "trt", xml_convert::serialize_type::full)
    );
};


// GetGuaranteedNumberOfVideoEncoderInstances 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetGuaranteedNumberOfVideoEncoderInstances {
    // Token of the video source configuration
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for trt_GetGuaranteedNumberOfVideoEncoderInstances
template<>
struct xml_convert::XmlTraits<trt_GetGuaranteedNumberOfVideoEncoderInstances> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetGuaranteedNumberOfVideoEncoderInstances::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetGuaranteedNumberOfVideoEncoderInstancesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetGuaranteedNumberOfVideoEncoderInstancesResponse {
    // The minimum guaranteed total number of encoder instances (applications) per VideoSourceConfiguration. The device is able to deliver the TotalNumber of streams
    int32_t TotalNumber {};
    // If a device limits the number of instances for respective Video Codecs the response contains the information how many Jpeg streams can be set up at the same time per VideoSource.
    std::optional<int32_t> JPEG;
    // If a device limits the number of instances for respective Video Codecs the response contains the information how many H264 streams can be set up at the same time per VideoSource.
    std::optional<int32_t> H264;
    // If a device limits the number of instances for respective Video Codecs the response contains the information how many Mpeg4 streams can be set up at the same time per VideoSource.
    std::optional<int32_t> MPEG4;
};


// XmlTraits for trt_GetGuaranteedNumberOfVideoEncoderInstancesResponse
template<>
struct xml_convert::XmlTraits<trt_GetGuaranteedNumberOfVideoEncoderInstancesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TotalNumber", &trt_GetGuaranteedNumberOfVideoEncoderInstancesResponse::TotalNumber, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("JPEG", &trt_GetGuaranteedNumberOfVideoEncoderInstancesResponse::JPEG, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("H264", &trt_GetGuaranteedNumberOfVideoEncoderInstancesResponse::H264, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MPEG4", &trt_GetGuaranteedNumberOfVideoEncoderInstancesResponse::MPEG4, "trt", xml_convert::serialize_type::full)
    );
};


// GetStreamUri 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetStreamUri {
    // Stream Setup that should be used with the uri
    tt_StreamSetup StreamSetup;
    // The ProfileToken element indicates the media profile to use and will define the configuration of the content of the stream.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetStreamUri
template<>
struct xml_convert::XmlTraits<trt_GetStreamUri> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StreamSetup", &trt_GetStreamUri::StreamSetup, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ProfileToken", &trt_GetStreamUri::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetStreamUriResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetStreamUriResponse {
    tt_MediaUri MediaUri;
};


// XmlTraits for trt_GetStreamUriResponse
template<>
struct xml_convert::XmlTraits<trt_GetStreamUriResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MediaUri", &trt_GetStreamUriResponse::MediaUri, "trt", xml_convert::serialize_type::full)
    );
};


// StartMulticastStreaming 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_StartMulticastStreaming {
    // Contains the token of the Profile that is used to define the multicast stream.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_StartMulticastStreaming
template<>
struct xml_convert::XmlTraits<trt_StartMulticastStreaming> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_StartMulticastStreaming::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// StartMulticastStreamingResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_StartMulticastStreamingResponse {
};


// XmlTraits for trt_StartMulticastStreamingResponse
template<>
struct xml_convert::XmlTraits<trt_StartMulticastStreamingResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// StopMulticastStreaming 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_StopMulticastStreaming {
    // Contains the token of the Profile that is used to define the multicast stream.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_StopMulticastStreaming
template<>
struct xml_convert::XmlTraits<trt_StopMulticastStreaming> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_StopMulticastStreaming::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// StopMulticastStreamingResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_StopMulticastStreamingResponse {
};


// XmlTraits for trt_StopMulticastStreamingResponse
template<>
struct xml_convert::XmlTraits<trt_StopMulticastStreamingResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetSynchronizationPoint 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetSynchronizationPoint {
    // Contains a Profile reference for which a Synchronization Point is requested.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_SetSynchronizationPoint
template<>
struct xml_convert::XmlTraits<trt_SetSynchronizationPoint> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_SetSynchronizationPoint::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// SetSynchronizationPointResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetSynchronizationPointResponse {
};


// XmlTraits for trt_SetSynchronizationPointResponse
template<>
struct xml_convert::XmlTraits<trt_SetSynchronizationPointResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetSnapshotUri 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetSnapshotUri {
    // The ProfileToken element indicates the media profile to use and will define the source and dimensions of the snapshot.
    tt_ReferenceToken ProfileToken;
};


// XmlTraits for trt_GetSnapshotUri
template<>
struct xml_convert::XmlTraits<trt_GetSnapshotUri> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileToken", &trt_GetSnapshotUri::ProfileToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetSnapshotUriResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetSnapshotUriResponse {
    tt_MediaUri MediaUri;
};


// XmlTraits for trt_GetSnapshotUriResponse
template<>
struct xml_convert::XmlTraits<trt_GetSnapshotUriResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MediaUri", &trt_GetSnapshotUriResponse::MediaUri, "trt", xml_convert::serialize_type::full)
    );
};


// GetVideoSourceModes 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoSourceModes {
    // Contains a video source reference for which a video source mode is requested.
    tt_ReferenceToken VideoSourceToken;
};


// XmlTraits for trt_GetVideoSourceModes
template<>
struct xml_convert::XmlTraits<trt_GetVideoSourceModes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &trt_GetVideoSourceModes::VideoSourceToken, "trt", xml_convert::serialize_type::full)
    );
};


// VideoSourceModeExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_VideoSourceModeExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_VideoSourceModeExtension
template<>
struct xml_convert::XmlTraits<trt_VideoSourceModeExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &trt_VideoSourceModeExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// VideoSourceMode 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_VideoSourceMode {
    // Max frame rate in frames per second for this video source mode.
    float MaxFramerate {};
    // Max horizontal and vertical resolution for this video source mode.
    tt_VideoResolution MaxResolution;
    // Indication which encodings are supported for this video source. The list may contain one or more enumeration values of tt:VideoEncoding.
    tt_StringList Encodings;
    // After setting the mode if a device starts to reboot this value is true. If a device change the mode without rebooting this value is false. If true, configured parameters may not be guaranteed by the device after rebooting.
    bool Reboot {};
    // Informative description of this video source mode. This field should be described in English.
    std::optional<tt_Description> Description;
    std::optional<trt_VideoSourceModeExtension> Extension;
    // Indicate token for video source mode.
    tt_ReferenceToken token;
    // Indication of whether this mode is active. If active this value is true. In case of non-indication, it means as false. The value of true shall be had by only one video source mode.
    std::optional<bool> Enabled;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for trt_VideoSourceMode
template<>
struct xml_convert::XmlTraits<trt_VideoSourceMode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MaxFramerate", &trt_VideoSourceMode::MaxFramerate, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxResolution", &trt_VideoSourceMode::MaxResolution, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Encodings", &trt_VideoSourceMode::Encodings, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Reboot", &trt_VideoSourceMode::Reboot, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Description", &trt_VideoSourceMode::Description, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &trt_VideoSourceMode::Extension, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("token", &trt_VideoSourceMode::token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Enabled", &trt_VideoSourceMode::Enabled, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &trt_VideoSourceMode::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetVideoSourceModesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetVideoSourceModesResponse {
    // Return the information for specified video source mode.
    std::vector<trt_VideoSourceMode> VideoSourceModes;
};


// XmlTraits for trt_GetVideoSourceModesResponse
template<>
struct xml_convert::XmlTraits<trt_GetVideoSourceModesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceModes", &trt_GetVideoSourceModesResponse::VideoSourceModes, "trt", xml_convert::serialize_type::full)
    );
};


// SetVideoSourceMode 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetVideoSourceMode {
    // Contains a video source reference for which a video source mode is requested.
    tt_ReferenceToken VideoSourceToken;
    // Indicate video source mode.
    tt_ReferenceToken VideoSourceModeToken;
};


// XmlTraits for trt_SetVideoSourceMode
template<>
struct xml_convert::XmlTraits<trt_SetVideoSourceMode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoSourceToken", &trt_SetVideoSourceMode::VideoSourceToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoSourceModeToken", &trt_SetVideoSourceMode::VideoSourceModeToken, "trt", xml_convert::serialize_type::full)
    );
};


// SetVideoSourceModeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetVideoSourceModeResponse {
    // The response contains information about rebooting after returning response. When Reboot is set true, a device will reboot automatically after setting mode.
    bool Reboot {};
};


// XmlTraits for trt_SetVideoSourceModeResponse
template<>
struct xml_convert::XmlTraits<trt_SetVideoSourceModeResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Reboot", &trt_SetVideoSourceModeResponse::Reboot, "trt", xml_convert::serialize_type::full)
    );
};


// GetOSDs 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetOSDs {
    // Token of the Video Source Configuration, which has OSDs associated with are requested. If token not exist, request all available OSDs.
    std::optional<tt_ReferenceToken> ConfigurationToken;
};


// XmlTraits for trt_GetOSDs
template<>
struct xml_convert::XmlTraits<trt_GetOSDs> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetOSDs::ConfigurationToken, "trt", xml_convert::serialize_type::full)
    );
};


// GetOSDsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetOSDsResponse {
    // This element contains a list of requested OSDs.
    std::vector<tt_OSDConfiguration> OSDs;
};


// XmlTraits for trt_GetOSDsResponse
template<>
struct xml_convert::XmlTraits<trt_GetOSDsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSDs", &trt_GetOSDsResponse::OSDs, "trt", xml_convert::serialize_type::full)
    );
};


// GetOSD 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetOSD {
    // The GetOSD command fetches the OSD configuration if the OSD token is known.
    tt_ReferenceToken OSDToken;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_GetOSD
template<>
struct xml_convert::XmlTraits<trt_GetOSD> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSDToken", &trt_GetOSD::OSDToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trt_GetOSD::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// GetOSDResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetOSDResponse {
    // The requested OSD configuration.
    tt_OSDConfiguration OSD;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_GetOSDResponse
template<>
struct xml_convert::XmlTraits<trt_GetOSDResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSD", &trt_GetOSDResponse::OSD, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trt_GetOSDResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SetOSD 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetOSD {
    // Contains the modified OSD configuration.
    tt_OSDConfiguration OSD;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_SetOSD
template<>
struct xml_convert::XmlTraits<trt_SetOSD> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSD", &trt_SetOSD::OSD, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trt_SetOSD::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SetOSDResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_SetOSDResponse {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_SetOSDResponse
template<>
struct xml_convert::XmlTraits<trt_SetOSDResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &trt_SetOSDResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// GetOSDOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetOSDOptions {
    // Video Source Configuration Token that specifies an existing video source configuration that the options shall be compatible with.
    tt_ReferenceToken ConfigurationToken;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_GetOSDOptions
template<>
struct xml_convert::XmlTraits<trt_GetOSDOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &trt_GetOSDOptions::ConfigurationToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trt_GetOSDOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// GetOSDOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_GetOSDOptionsResponse {
    tt_OSDConfigurationOptions OSDOptions;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_GetOSDOptionsResponse
template<>
struct xml_convert::XmlTraits<trt_GetOSDOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSDOptions", &trt_GetOSDOptionsResponse::OSDOptions, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trt_GetOSDOptionsResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// CreateOSD 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_CreateOSD {
    // Contain the initial OSD configuration for create.
    tt_OSDConfiguration OSD;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_CreateOSD
template<>
struct xml_convert::XmlTraits<trt_CreateOSD> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSD", &trt_CreateOSD::OSD, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trt_CreateOSD::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// CreateOSDResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_CreateOSDResponse {
    // Returns Token of the newly created OSD
    tt_ReferenceToken OSDToken;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_CreateOSDResponse
template<>
struct xml_convert::XmlTraits<trt_CreateOSDResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSDToken", &trt_CreateOSDResponse::OSDToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trt_CreateOSDResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// DeleteOSD 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_DeleteOSD {
    // This element contains a reference to the OSD configuration that should be deleted.
    tt_ReferenceToken OSDToken;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_DeleteOSD
template<>
struct xml_convert::XmlTraits<trt_DeleteOSD> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OSDToken", &trt_DeleteOSD::OSDToken, "trt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trt_DeleteOSD::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// DeleteOSDResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/media/wsdl
// 源文件: media_v10.wsdl
struct trt_DeleteOSDResponse {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trt_DeleteOSDResponse
template<>
struct xml_convert::XmlTraits<trt_DeleteOSDResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &trt_DeleteOSDResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


} // namespace libonvif_client
