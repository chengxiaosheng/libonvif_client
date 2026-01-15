/**
 * @file trc.h
 * @brief 从 recording_v10.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver10/recording/wsdl
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
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetServiceCapabilities {
};


// XmlTraits for trc_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<trc_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_Capabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indication if the device supports dynamic creation and deletion of recordings
    std::optional<bool> DynamicRecordings;
    // Indication if the device supports dynamic creation and deletion of tracks
    std::optional<bool> DynamicTracks;
    // Indication which encodings are supported for recording. The list may contain one or more enumeration values of tt:VideoEncoding and tt:AudioEncoding. For encodings that are neither defined in tt:VideoEncoding nor tt:AudioEncoding the device shall use the IANA defintions. Note, that a device without audio support shall not return audio encodings.
    std::optional<tt_StringList> Encoding;
    // Maximum supported bit rate for all tracks of a recording in kBit/s.
    std::optional<float> MaxRate;
    // Maximum supported bit rate for all recordings in kBit/s.
    std::optional<float> MaxTotalRate;
    // Maximum number of recordings supported. (Integer values only.)
    std::optional<float> MaxRecordings;
    // Maximum total number of supported recording jobs by the device.
    std::optional<int32_t> MaxRecordingJobs;
    // Indication if the device supports the GetRecordingOptions command.
    std::optional<bool> Options;
    // Indication if the device supports recording metadata.
    std::optional<bool> MetadataRecording;
    /*
     * Indication that the device supports ExportRecordedData command for the listed export file formats.
     * The list shall return at least one export file format value. The value of 'ONVIF' refers to
     * ONVIF Export File Format specification.
     */
    std::optional<tt_StringAttrList> SupportedExportFileFormats;
    // Indication that the device supports event triggered recording.
    std::optional<bool> EventRecording;
    // If present a device shall support configuring before event durations up to the given value.
    std::optional<std::string> BeforeEventLimit;
    // If present a device shall support configuring after event durations up to the given value.
    std::optional<std::string> AfterEventLimit;
    /*
     * List of formats supported by the device for recording to an external target.
     * See tt:TargetFormat for a list of definitions.
     */
    std::optional<tt_StringAttrList> SupportedTargetFormats;
    /*
     * Number of encryption entries supported per recording.
     * By specifying multiple encryption entries per recording, different tracks can be encrypted with different configurations.
     */
    std::optional<int32_t> EncryptionEntryLimit;
    /*
     * Indicates supported encryption modes.
     * See tt:EncryptionMode for a list of definitions.
     */
    std::optional<tt_StringAttrList> SupportedEncryptionModes;
    // Indicates if the device supports the OverrideSegmentDuration command.
    std::optional<bool> OverrideSegmentDuration;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for trc_Capabilities
template<>
struct xml_convert::XmlTraits<trc_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &trc_Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("DynamicRecordings", &trc_Capabilities::DynamicRecordings, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("DynamicTracks", &trc_Capabilities::DynamicTracks, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Encoding", &trc_Capabilities::Encoding, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxRate", &trc_Capabilities::MaxRate, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxTotalRate", &trc_Capabilities::MaxTotalRate, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxRecordings", &trc_Capabilities::MaxRecordings, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxRecordingJobs", &trc_Capabilities::MaxRecordingJobs, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Options", &trc_Capabilities::Options, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MetadataRecording", &trc_Capabilities::MetadataRecording, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SupportedExportFileFormats", &trc_Capabilities::SupportedExportFileFormats, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("EventRecording", &trc_Capabilities::EventRecording, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("BeforeEventLimit", &trc_Capabilities::BeforeEventLimit, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AfterEventLimit", &trc_Capabilities::AfterEventLimit, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SupportedTargetFormats", &trc_Capabilities::SupportedTargetFormats, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("EncryptionEntryLimit", &trc_Capabilities::EncryptionEntryLimit, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SupportedEncryptionModes", &trc_Capabilities::SupportedEncryptionModes, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("OverrideSegmentDuration", &trc_Capabilities::OverrideSegmentDuration, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &trc_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetServiceCapabilitiesResponse {
    // The capabilities for the recording service is returned in the Capabilities element.
    trc_Capabilities Capabilities;
};


// XmlTraits for trc_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<trc_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &trc_GetServiceCapabilitiesResponse::Capabilities, "trc", xml_convert::serialize_type::full)
    );
};


// CreateRecording 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_CreateRecording {
    // Initial configuration for the recording.
    tt_RecordingConfiguration RecordingConfiguration;
};


// XmlTraits for trc_CreateRecording
template<>
struct xml_convert::XmlTraits<trc_CreateRecording> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingConfiguration", &trc_CreateRecording::RecordingConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// CreateRecordingResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_CreateRecordingResponse {
    // The reference to the created recording.
    tt_RecordingReference RecordingToken;
};


// XmlTraits for trc_CreateRecordingResponse
template<>
struct xml_convert::XmlTraits<trc_CreateRecordingResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &trc_CreateRecordingResponse::RecordingToken, "trc", xml_convert::serialize_type::full)
    );
};


// DeleteRecording 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_DeleteRecording {
    // The reference of the recording to be deleted.
    tt_RecordingReference RecordingToken;
};


// XmlTraits for trc_DeleteRecording
template<>
struct xml_convert::XmlTraits<trc_DeleteRecording> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &trc_DeleteRecording::RecordingToken, "trc", xml_convert::serialize_type::full)
    );
};


// DeleteRecordingResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_DeleteRecordingResponse {
};


// XmlTraits for trc_DeleteRecordingResponse
template<>
struct xml_convert::XmlTraits<trc_DeleteRecordingResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRecordings 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordings {
};


// XmlTraits for trc_GetRecordings
template<>
struct xml_convert::XmlTraits<trc_GetRecordings> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRecordingsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingsResponse {
    // List of recording items.
    std::vector<tt_GetRecordingsResponseItem> RecordingItem;
};


// XmlTraits for trc_GetRecordingsResponse
template<>
struct xml_convert::XmlTraits<trc_GetRecordingsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingItem", &trc_GetRecordingsResponse::RecordingItem, "trc", xml_convert::serialize_type::full)
    );
};


// SetRecordingConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_SetRecordingConfiguration {
    // Token of the recording that shall be changed.
    tt_RecordingReference RecordingToken;
    // The new configuration.
    tt_RecordingConfiguration RecordingConfiguration;
};


// XmlTraits for trc_SetRecordingConfiguration
template<>
struct xml_convert::XmlTraits<trc_SetRecordingConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &trc_SetRecordingConfiguration::RecordingToken, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RecordingConfiguration", &trc_SetRecordingConfiguration::RecordingConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// SetRecordingConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_SetRecordingConfigurationResponse {
};


// XmlTraits for trc_SetRecordingConfigurationResponse
template<>
struct xml_convert::XmlTraits<trc_SetRecordingConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRecordingConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingConfiguration {
    // Token of the configuration to be retrieved.
    tt_RecordingReference RecordingToken;
};


// XmlTraits for trc_GetRecordingConfiguration
template<>
struct xml_convert::XmlTraits<trc_GetRecordingConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &trc_GetRecordingConfiguration::RecordingToken, "trc", xml_convert::serialize_type::full)
    );
};


// GetRecordingConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingConfigurationResponse {
    // Configuration of the recording.
    tt_RecordingConfiguration RecordingConfiguration;
};


// XmlTraits for trc_GetRecordingConfigurationResponse
template<>
struct xml_convert::XmlTraits<trc_GetRecordingConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingConfiguration", &trc_GetRecordingConfigurationResponse::RecordingConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// CreateTrack 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_CreateTrack {
    // Identifies the recording to which a track shall be added.
    tt_RecordingReference RecordingToken;
    // The configuration of the new track.
    tt_TrackConfiguration TrackConfiguration;
};


// XmlTraits for trc_CreateTrack
template<>
struct xml_convert::XmlTraits<trc_CreateTrack> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &trc_CreateTrack::RecordingToken, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TrackConfiguration", &trc_CreateTrack::TrackConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// CreateTrackResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_CreateTrackResponse {
    /*
     * The TrackToken shall identify the newly created track. The
     * TrackToken shall be unique within the recoding to which
     * the new track belongs.
     */
    tt_TrackReference TrackToken;
};


// XmlTraits for trc_CreateTrackResponse
template<>
struct xml_convert::XmlTraits<trc_CreateTrackResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TrackToken", &trc_CreateTrackResponse::TrackToken, "trc", xml_convert::serialize_type::full)
    );
};


// DeleteTrack 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_DeleteTrack {
    // Token of the recording the track belongs to.
    tt_RecordingReference RecordingToken;
    // Token of the track to be deleted.
    tt_TrackReference TrackToken;
};


// XmlTraits for trc_DeleteTrack
template<>
struct xml_convert::XmlTraits<trc_DeleteTrack> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &trc_DeleteTrack::RecordingToken, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TrackToken", &trc_DeleteTrack::TrackToken, "trc", xml_convert::serialize_type::full)
    );
};


// DeleteTrackResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_DeleteTrackResponse {
};


// XmlTraits for trc_DeleteTrackResponse
template<>
struct xml_convert::XmlTraits<trc_DeleteTrackResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetTrackConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetTrackConfiguration {
    // Token of the recording the track belongs to.
    tt_RecordingReference RecordingToken;
    // Token of the track.
    tt_TrackReference TrackToken;
};


// XmlTraits for trc_GetTrackConfiguration
template<>
struct xml_convert::XmlTraits<trc_GetTrackConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &trc_GetTrackConfiguration::RecordingToken, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TrackToken", &trc_GetTrackConfiguration::TrackToken, "trc", xml_convert::serialize_type::full)
    );
};


// GetTrackConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetTrackConfigurationResponse {
    // Configuration of the track.
    tt_TrackConfiguration TrackConfiguration;
};


// XmlTraits for trc_GetTrackConfigurationResponse
template<>
struct xml_convert::XmlTraits<trc_GetTrackConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TrackConfiguration", &trc_GetTrackConfigurationResponse::TrackConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// SetTrackConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_SetTrackConfiguration {
    // Token of the recording the track belongs to.
    tt_RecordingReference RecordingToken;
    // Token of the track to be modified.
    tt_TrackReference TrackToken;
    // New configuration for the track.
    tt_TrackConfiguration TrackConfiguration;
};


// XmlTraits for trc_SetTrackConfiguration
template<>
struct xml_convert::XmlTraits<trc_SetTrackConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &trc_SetTrackConfiguration::RecordingToken, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TrackToken", &trc_SetTrackConfiguration::TrackToken, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TrackConfiguration", &trc_SetTrackConfiguration::TrackConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// SetTrackConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_SetTrackConfigurationResponse {
};


// XmlTraits for trc_SetTrackConfigurationResponse
template<>
struct xml_convert::XmlTraits<trc_SetTrackConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// CreateRecordingJob 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_CreateRecordingJob {
    // The initial configuration of the new recording job.
    tt_RecordingJobConfiguration JobConfiguration;
};


// XmlTraits for trc_CreateRecordingJob
template<>
struct xml_convert::XmlTraits<trc_CreateRecordingJob> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobConfiguration", &trc_CreateRecordingJob::JobConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// CreateRecordingJobResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_CreateRecordingJobResponse {
    // The JobToken shall identify the created recording job.
    tt_RecordingJobReference JobToken;
    /*
     * The JobConfiguration structure shall be the configuration as it is used by the device. This may be different from the
     * JobConfiguration passed to CreateRecordingJob.
     */
    tt_RecordingJobConfiguration JobConfiguration;
};


// XmlTraits for trc_CreateRecordingJobResponse
template<>
struct xml_convert::XmlTraits<trc_CreateRecordingJobResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobToken", &trc_CreateRecordingJobResponse::JobToken, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("JobConfiguration", &trc_CreateRecordingJobResponse::JobConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// DeleteRecordingJob 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_DeleteRecordingJob {
    // The token of the job to be deleted.
    tt_RecordingJobReference JobToken;
};


// XmlTraits for trc_DeleteRecordingJob
template<>
struct xml_convert::XmlTraits<trc_DeleteRecordingJob> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobToken", &trc_DeleteRecordingJob::JobToken, "trc", xml_convert::serialize_type::full)
    );
};


// DeleteRecordingJobResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_DeleteRecordingJobResponse {
};


// XmlTraits for trc_DeleteRecordingJobResponse
template<>
struct xml_convert::XmlTraits<trc_DeleteRecordingJobResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRecordingJobs 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingJobs {
};


// XmlTraits for trc_GetRecordingJobs
template<>
struct xml_convert::XmlTraits<trc_GetRecordingJobs> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRecordingJobsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingJobsResponse {
    // List of recording jobs.
    std::vector<tt_GetRecordingJobsResponseItem> JobItem;
};


// XmlTraits for trc_GetRecordingJobsResponse
template<>
struct xml_convert::XmlTraits<trc_GetRecordingJobsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobItem", &trc_GetRecordingJobsResponse::JobItem, "trc", xml_convert::serialize_type::full)
    );
};


// SetRecordingJobConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_SetRecordingJobConfiguration {
    // Token of the job to be modified.
    tt_RecordingJobReference JobToken;
    // New configuration of the recording job.
    tt_RecordingJobConfiguration JobConfiguration;
};


// XmlTraits for trc_SetRecordingJobConfiguration
template<>
struct xml_convert::XmlTraits<trc_SetRecordingJobConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobToken", &trc_SetRecordingJobConfiguration::JobToken, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("JobConfiguration", &trc_SetRecordingJobConfiguration::JobConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// SetRecordingJobConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_SetRecordingJobConfigurationResponse {
    /*
     * The JobConfiguration structure shall be the configuration
     * as it is used by the device. This may be different from the JobConfiguration passed to SetRecordingJobConfiguration.
     */
    tt_RecordingJobConfiguration JobConfiguration;
};


// XmlTraits for trc_SetRecordingJobConfigurationResponse
template<>
struct xml_convert::XmlTraits<trc_SetRecordingJobConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobConfiguration", &trc_SetRecordingJobConfigurationResponse::JobConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// GetRecordingJobConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingJobConfiguration {
    // Token of the recording job.
    tt_RecordingJobReference JobToken;
};


// XmlTraits for trc_GetRecordingJobConfiguration
template<>
struct xml_convert::XmlTraits<trc_GetRecordingJobConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobToken", &trc_GetRecordingJobConfiguration::JobToken, "trc", xml_convert::serialize_type::full)
    );
};


// GetRecordingJobConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingJobConfigurationResponse {
    // Current configuration of the recording job.
    tt_RecordingJobConfiguration JobConfiguration;
};


// XmlTraits for trc_GetRecordingJobConfigurationResponse
template<>
struct xml_convert::XmlTraits<trc_GetRecordingJobConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobConfiguration", &trc_GetRecordingJobConfigurationResponse::JobConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// SetRecordingJobMode 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_SetRecordingJobMode {
    // Token of the recording job.
    tt_RecordingJobReference JobToken;
    // The new mode for the recording job.
    tt_RecordingJobMode Mode;
};


// XmlTraits for trc_SetRecordingJobMode
template<>
struct xml_convert::XmlTraits<trc_SetRecordingJobMode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobToken", &trc_SetRecordingJobMode::JobToken, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mode", &trc_SetRecordingJobMode::Mode, "trc", xml_convert::serialize_type::full)
    );
};


// SetRecordingJobModeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_SetRecordingJobModeResponse {
};


// XmlTraits for trc_SetRecordingJobModeResponse
template<>
struct xml_convert::XmlTraits<trc_SetRecordingJobModeResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRecordingJobState 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingJobState {
    // Token of the recording job.
    tt_RecordingJobReference JobToken;
};


// XmlTraits for trc_GetRecordingJobState
template<>
struct xml_convert::XmlTraits<trc_GetRecordingJobState> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobToken", &trc_GetRecordingJobState::JobToken, "trc", xml_convert::serialize_type::full)
    );
};


// GetRecordingJobStateResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingJobStateResponse {
    // The current state of the recording job.
    tt_RecordingJobStateInformation State;
};


// XmlTraits for trc_GetRecordingJobStateResponse
template<>
struct xml_convert::XmlTraits<trc_GetRecordingJobStateResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("State", &trc_GetRecordingJobStateResponse::State, "trc", xml_convert::serialize_type::full)
    );
};


// GetRecordingOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingOptions {
    // Token of the recording.
    tt_RecordingReference RecordingToken;
};


// XmlTraits for trc_GetRecordingOptions
template<>
struct xml_convert::XmlTraits<trc_GetRecordingOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &trc_GetRecordingOptions::RecordingToken, "trc", xml_convert::serialize_type::full)
    );
};


// JobOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_JobOptions {
    // Number of spare jobs that can be created for the recording.
    std::optional<int32_t> Spare;
    // A device that supports recording of a restricted set of Media/Media2 Service Profiles returns the list of profiles that can be recorded on the given Recording.
    std::optional<tt_StringAttrList> CompatibleSources;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for trc_JobOptions
template<>
struct xml_convert::XmlTraits<trc_JobOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Spare", &trc_JobOptions::Spare, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("CompatibleSources", &trc_JobOptions::CompatibleSources, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &trc_JobOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// TrackOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_TrackOptions {
    // Total spare number of tracks that can be added to this recording.
    std::optional<int32_t> SpareTotal;
    // Number of spare Video tracks that can be added to this recording.
    std::optional<int32_t> SpareVideo;
    // Number of spare Aduio tracks that can be added to this recording.
    std::optional<int32_t> SpareAudio;
    // Number of spare Metadata tracks that can be added to this recording.
    std::optional<int32_t> SpareMetadata;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for trc_TrackOptions
template<>
struct xml_convert::XmlTraits<trc_TrackOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SpareTotal", &trc_TrackOptions::SpareTotal, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SpareVideo", &trc_TrackOptions::SpareVideo, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SpareAudio", &trc_TrackOptions::SpareAudio, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SpareMetadata", &trc_TrackOptions::SpareMetadata, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &trc_TrackOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_RecordingOptions {
    trc_JobOptions Job;
    trc_TrackOptions Track;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trc_RecordingOptions
template<>
struct xml_convert::XmlTraits<trc_RecordingOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Job", &trc_RecordingOptions::Job, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Track", &trc_RecordingOptions::Track, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trc_RecordingOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// GetRecordingOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetRecordingOptionsResponse {
    // Configuration of the recording.
    trc_RecordingOptions Options;
};


// XmlTraits for trc_GetRecordingOptionsResponse
template<>
struct xml_convert::XmlTraits<trc_GetRecordingOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &trc_GetRecordingOptionsResponse::Options, "trc", xml_convert::serialize_type::full)
    );
};


// ExportRecordedData 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_ExportRecordedData {
    // Optional parameter that specifies start time for the exporting.
    std::optional<std::string> StartPoint;
    // Optional parameter that specifies end time for the exporting.
    std::optional<std::string> EndPoint;
    // Indicates the selection criterion on the existing recordings. .
    tt_SearchScope SearchScope;
    // Indicates which export file format to be used.
    std::string FileFormat;
    // Indicates the target storage and relative directory path.
    tt_StorageReferencePath StorageDestination;
};


// XmlTraits for trc_ExportRecordedData
template<>
struct xml_convert::XmlTraits<trc_ExportRecordedData> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StartPoint", &trc_ExportRecordedData::StartPoint, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EndPoint", &trc_ExportRecordedData::EndPoint, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SearchScope", &trc_ExportRecordedData::SearchScope, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FileFormat", &trc_ExportRecordedData::FileFormat, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StorageDestination", &trc_ExportRecordedData::StorageDestination, "trc", xml_convert::serialize_type::full)
    );
};


// Extension 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_Extension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trc_Extension
template<>
struct xml_convert::XmlTraits<trc_Extension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &trc_Extension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ExportRecordedDataResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_ExportRecordedDataResponse {
    // Unique operation token for client to associate the relevant events.
    tt_ReferenceToken OperationToken;
    // List of exported file names. The device can also use AsyncronousOperationStatus event to publish this list.
    std::vector<std::string> FileNames;
    std::optional<trc_Extension> Extension;
};


// XmlTraits for trc_ExportRecordedDataResponse
template<>
struct xml_convert::XmlTraits<trc_ExportRecordedDataResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OperationToken", &trc_ExportRecordedDataResponse::OperationToken, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FileNames", &trc_ExportRecordedDataResponse::FileNames, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &trc_ExportRecordedDataResponse::Extension, "trc", xml_convert::serialize_type::full)
    );
};


// StopExportRecordedData 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_StopExportRecordedData {
    // Unique ExportRecordedData operation token
    tt_ReferenceToken OperationToken;
};


// XmlTraits for trc_StopExportRecordedData
template<>
struct xml_convert::XmlTraits<trc_StopExportRecordedData> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OperationToken", &trc_StopExportRecordedData::OperationToken, "trc", xml_convert::serialize_type::full)
    );
};


// StopExportRecordedDataResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_StopExportRecordedDataResponse {
    // Progress percentage of ExportRecordedData operation.
    float Progress {};
    tt_ArrayOfFileProgress FileProgressStatus;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trc_StopExportRecordedDataResponse
template<>
struct xml_convert::XmlTraits<trc_StopExportRecordedDataResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Progress", &trc_StopExportRecordedDataResponse::Progress, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FileProgressStatus", &trc_StopExportRecordedDataResponse::FileProgressStatus, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trc_StopExportRecordedDataResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// GetExportRecordedDataState 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetExportRecordedDataState {
    // Unique ExportRecordedData operation token
    tt_ReferenceToken OperationToken;
};


// XmlTraits for trc_GetExportRecordedDataState
template<>
struct xml_convert::XmlTraits<trc_GetExportRecordedDataState> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OperationToken", &trc_GetExportRecordedDataState::OperationToken, "trc", xml_convert::serialize_type::full)
    );
};


// GetExportRecordedDataStateResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_GetExportRecordedDataStateResponse {
    // Progress percentage of ExportRecordedData operation.
    float Progress {};
    tt_ArrayOfFileProgress FileProgressStatus;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for trc_GetExportRecordedDataStateResponse
template<>
struct xml_convert::XmlTraits<trc_GetExportRecordedDataStateResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Progress", &trc_GetExportRecordedDataStateResponse::Progress, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FileProgressStatus", &trc_GetExportRecordedDataStateResponse::FileProgressStatus, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &trc_GetExportRecordedDataStateResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// OverrideSegmentDuration 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_OverrideSegmentDuration {
    // The new target duration for recorded segments.
    std::string TargetSegmentDuration;
    // The length of time during which the override request is to be in effect.
    std::string Expiration;
    // The recording configuration for which the override is requested.
    tt_RecordingReference RecordingConfiguration;
};


// XmlTraits for trc_OverrideSegmentDuration
template<>
struct xml_convert::XmlTraits<trc_OverrideSegmentDuration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TargetSegmentDuration", &trc_OverrideSegmentDuration::TargetSegmentDuration, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Expiration", &trc_OverrideSegmentDuration::Expiration, "trc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RecordingConfiguration", &trc_OverrideSegmentDuration::RecordingConfiguration, "trc", xml_convert::serialize_type::full)
    );
};


// OverrideSegmentDurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/recording/wsdl
// 源文件: recording_v10.wsdl
struct trc_OverrideSegmentDurationResponse {
};


// XmlTraits for trc_OverrideSegmentDurationResponse
template<>
struct xml_convert::XmlTraits<trc_OverrideSegmentDurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


} // namespace libonvif_client
