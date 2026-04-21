/**
 * @file tse.h
 * @brief 从 search_v10.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver10/search/wsdl
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

// 依赖的类型定义
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
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetServiceCapabilities {
};


// XmlTraits for tse_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<tse_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_Capabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<bool> MetadataSearch;
    // Indicates support for general virtual property events in the FindEvents method.
    std::optional<bool> GeneralStartEvents;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tse_Capabilities
template<>
struct xml_convert::XmlTraits<tse_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tse_Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("MetadataSearch", &tse_Capabilities::MetadataSearch, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("GeneralStartEvents", &tse_Capabilities::GeneralStartEvents, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tse_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetServiceCapabilitiesResponse {
    // The capabilities for the search service is returned in the Capabilities element.
    tse_Capabilities Capabilities;
};


// XmlTraits for tse_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<tse_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &tse_GetServiceCapabilitiesResponse::Capabilities, "tse", xml_convert::serialize_type::full)
    );
};


// GetRecordingSummary 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetRecordingSummary {
};


// XmlTraits for tse_GetRecordingSummary
template<>
struct xml_convert::XmlTraits<tse_GetRecordingSummary> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRecordingSummaryResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetRecordingSummaryResponse {
    tt_RecordingSummary Summary;
};


// XmlTraits for tse_GetRecordingSummaryResponse
template<>
struct xml_convert::XmlTraits<tse_GetRecordingSummaryResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Summary", &tse_GetRecordingSummaryResponse::Summary, "tse", xml_convert::serialize_type::full)
    );
};


// GetRecordingInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetRecordingInformation {
    tt_RecordingReference RecordingToken;
};


// XmlTraits for tse_GetRecordingInformation
template<>
struct xml_convert::XmlTraits<tse_GetRecordingInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &tse_GetRecordingInformation::RecordingToken, "tse", xml_convert::serialize_type::full)
    );
};


// GetRecordingInformationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetRecordingInformationResponse {
    tt_RecordingInformation RecordingInformation;
};


// XmlTraits for tse_GetRecordingInformationResponse
template<>
struct xml_convert::XmlTraits<tse_GetRecordingInformationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingInformation", &tse_GetRecordingInformationResponse::RecordingInformation, "tse", xml_convert::serialize_type::full)
    );
};


// GetMediaAttributes 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetMediaAttributes {
    std::vector<tt_RecordingReference> RecordingTokens;
    std::string Time;
};


// XmlTraits for tse_GetMediaAttributes
template<>
struct xml_convert::XmlTraits<tse_GetMediaAttributes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingTokens", &tse_GetMediaAttributes::RecordingTokens, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Time", &tse_GetMediaAttributes::Time, "tse", xml_convert::serialize_type::full)
    );
};


// GetMediaAttributesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetMediaAttributesResponse {
    std::vector<tt_MediaAttributes> MediaAttributes;
};


// XmlTraits for tse_GetMediaAttributesResponse
template<>
struct xml_convert::XmlTraits<tse_GetMediaAttributesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MediaAttributes", &tse_GetMediaAttributesResponse::MediaAttributes, "tse", xml_convert::serialize_type::full)
    );
};


// FindRecordings 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_FindRecordings {
    // Scope defines the dataset to consider for this search.
    tt_SearchScope Scope;
    // The search will be completed after this many matches. If not specified, the search will continue until reaching the endpoint or until the session expires.
    std::optional<int32_t> MaxMatches;
    // The time the search session will be kept alive after responding to this and subsequent requests. A device shall support at least values up to ten seconds.
    my_Duration KeepAliveTime;
};


// XmlTraits for tse_FindRecordings
template<>
struct xml_convert::XmlTraits<tse_FindRecordings> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Scope", &tse_FindRecordings::Scope, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxMatches", &tse_FindRecordings::MaxMatches, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("KeepAliveTime", &tse_FindRecordings::KeepAliveTime, "tse", xml_convert::serialize_type::full)
    );
};


// FindRecordingsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_FindRecordingsResponse {
    tt_JobToken SearchToken;
};


// XmlTraits for tse_FindRecordingsResponse
template<>
struct xml_convert::XmlTraits<tse_FindRecordingsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchToken", &tse_FindRecordingsResponse::SearchToken, "tse", xml_convert::serialize_type::full)
    );
};


// GetRecordingSearchResults 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetRecordingSearchResults {
    // The search session to get results from.
    tt_JobToken SearchToken;
    // The minimum number of results to return in one response.
    std::optional<int32_t> MinResults;
    // The maximum number of results to return in one response.
    std::optional<int32_t> MaxResults;
    // The maximum time before responding to the request, even if the MinResults parameter is not fulfilled.
    std::optional<my_Duration> WaitTime;
};


// XmlTraits for tse_GetRecordingSearchResults
template<>
struct xml_convert::XmlTraits<tse_GetRecordingSearchResults> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchToken", &tse_GetRecordingSearchResults::SearchToken, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinResults", &tse_GetRecordingSearchResults::MinResults, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxResults", &tse_GetRecordingSearchResults::MaxResults, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WaitTime", &tse_GetRecordingSearchResults::WaitTime, "tse", xml_convert::serialize_type::full)
    );
};


// GetRecordingSearchResultsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetRecordingSearchResultsResponse {
    tt_FindRecordingResultList ResultList;
};


// XmlTraits for tse_GetRecordingSearchResultsResponse
template<>
struct xml_convert::XmlTraits<tse_GetRecordingSearchResultsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ResultList", &tse_GetRecordingSearchResultsResponse::ResultList, "tse", xml_convert::serialize_type::full)
    );
};


// FindEvents 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_FindEvents {
    // The point of time where the search will start.
    std::string StartPoint;
    // The point of time where the search will stop. This can be a time before the StartPoint, in which case the search is performed backwards in time.
    std::optional<std::string> EndPoint;
    tt_SearchScope Scope;
    tt_EventFilter SearchFilter;
    // Setting IncludeStartState to true means that the server should return virtual events representing the start state for any recording included in the scope. Start state events are limited to the topics defined in the SearchFilter that have the IsProperty flag set to true.
    bool IncludeStartState {};
    // The search will be completed after this many matches. If not specified, the search will continue until reaching the endpoint or until the session expires.
    std::optional<int32_t> MaxMatches;
    // The time the search session will be kept alive after responding to this and subsequent requests. A device shall support at least values up to ten seconds.
    my_Duration KeepAliveTime;
};


// XmlTraits for tse_FindEvents
template<>
struct xml_convert::XmlTraits<tse_FindEvents> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StartPoint", &tse_FindEvents::StartPoint, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EndPoint", &tse_FindEvents::EndPoint, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Scope", &tse_FindEvents::Scope, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SearchFilter", &tse_FindEvents::SearchFilter, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IncludeStartState", &tse_FindEvents::IncludeStartState, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxMatches", &tse_FindEvents::MaxMatches, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("KeepAliveTime", &tse_FindEvents::KeepAliveTime, "tse", xml_convert::serialize_type::full)
    );
};


// FindEventsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_FindEventsResponse {
    // A unique reference to the search session created by this request.
    tt_JobToken SearchToken;
};


// XmlTraits for tse_FindEventsResponse
template<>
struct xml_convert::XmlTraits<tse_FindEventsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchToken", &tse_FindEventsResponse::SearchToken, "tse", xml_convert::serialize_type::full)
    );
};


// GetEventSearchResults 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetEventSearchResults {
    // The search session to get results from.
    tt_JobToken SearchToken;
    // The minimum number of results to return in one response.
    std::optional<int32_t> MinResults;
    // The maximum number of results to return in one response.
    std::optional<int32_t> MaxResults;
    // The maximum time before responding to the request, even if the MinResults parameter is not fulfilled.
    std::optional<my_Duration> WaitTime;
};


// XmlTraits for tse_GetEventSearchResults
template<>
struct xml_convert::XmlTraits<tse_GetEventSearchResults> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchToken", &tse_GetEventSearchResults::SearchToken, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinResults", &tse_GetEventSearchResults::MinResults, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxResults", &tse_GetEventSearchResults::MaxResults, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WaitTime", &tse_GetEventSearchResults::WaitTime, "tse", xml_convert::serialize_type::full)
    );
};


// GetEventSearchResultsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetEventSearchResultsResponse {
    tt_FindEventResultList ResultList;
};


// XmlTraits for tse_GetEventSearchResultsResponse
template<>
struct xml_convert::XmlTraits<tse_GetEventSearchResultsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ResultList", &tse_GetEventSearchResultsResponse::ResultList, "tse", xml_convert::serialize_type::full)
    );
};


// FindPTZPosition 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_FindPTZPosition {
    // The point of time where the search will start.
    std::string StartPoint;
    // The point of time where the search will stop. This can be a time before the StartPoint, in which case the search is performed backwards in time.
    std::optional<std::string> EndPoint;
    tt_SearchScope Scope;
    tt_PTZPositionFilter SearchFilter;
    // The search will be completed after this many matches. If not specified, the search will continue until reaching the endpoint or until the session expires.
    std::optional<int32_t> MaxMatches;
    // The time the search session will be kept alive after responding to this and subsequent requests. A device shall support at least values up to ten seconds.
    my_Duration KeepAliveTime;
};


// XmlTraits for tse_FindPTZPosition
template<>
struct xml_convert::XmlTraits<tse_FindPTZPosition> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StartPoint", &tse_FindPTZPosition::StartPoint, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EndPoint", &tse_FindPTZPosition::EndPoint, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Scope", &tse_FindPTZPosition::Scope, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SearchFilter", &tse_FindPTZPosition::SearchFilter, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxMatches", &tse_FindPTZPosition::MaxMatches, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("KeepAliveTime", &tse_FindPTZPosition::KeepAliveTime, "tse", xml_convert::serialize_type::full)
    );
};


// FindPTZPositionResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_FindPTZPositionResponse {
    // A unique reference to the search session created by this request.
    tt_JobToken SearchToken;
};


// XmlTraits for tse_FindPTZPositionResponse
template<>
struct xml_convert::XmlTraits<tse_FindPTZPositionResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchToken", &tse_FindPTZPositionResponse::SearchToken, "tse", xml_convert::serialize_type::full)
    );
};


// GetPTZPositionSearchResults 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetPTZPositionSearchResults {
    // The search session to get results from.
    tt_JobToken SearchToken;
    // The minimum number of results to return in one response.
    std::optional<int32_t> MinResults;
    // The maximum number of results to return in one response.
    std::optional<int32_t> MaxResults;
    // The maximum time before responding to the request, even if the MinResults parameter is not fulfilled.
    std::optional<my_Duration> WaitTime;
};


// XmlTraits for tse_GetPTZPositionSearchResults
template<>
struct xml_convert::XmlTraits<tse_GetPTZPositionSearchResults> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchToken", &tse_GetPTZPositionSearchResults::SearchToken, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinResults", &tse_GetPTZPositionSearchResults::MinResults, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxResults", &tse_GetPTZPositionSearchResults::MaxResults, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WaitTime", &tse_GetPTZPositionSearchResults::WaitTime, "tse", xml_convert::serialize_type::full)
    );
};


// GetPTZPositionSearchResultsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetPTZPositionSearchResultsResponse {
    tt_FindPTZPositionResultList ResultList;
};


// XmlTraits for tse_GetPTZPositionSearchResultsResponse
template<>
struct xml_convert::XmlTraits<tse_GetPTZPositionSearchResultsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ResultList", &tse_GetPTZPositionSearchResultsResponse::ResultList, "tse", xml_convert::serialize_type::full)
    );
};


// FindMetadata 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_FindMetadata {
    // The point of time where the search will start.
    std::string StartPoint;
    // The point of time where the search will stop. This can be a time before the StartPoint, in which case the search is performed backwards in time.
    std::optional<std::string> EndPoint;
    tt_SearchScope Scope;
    tt_MetadataFilter MetadataFilter;
    // The search will be completed after this many matches. If not specified, the search will continue until reaching the endpoint or until the session expires.
    std::optional<int32_t> MaxMatches;
    // The time the search session will be kept alive after responding to this and subsequent requests. A device shall support at least values up to ten seconds.
    my_Duration KeepAliveTime;
};


// XmlTraits for tse_FindMetadata
template<>
struct xml_convert::XmlTraits<tse_FindMetadata> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StartPoint", &tse_FindMetadata::StartPoint, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EndPoint", &tse_FindMetadata::EndPoint, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Scope", &tse_FindMetadata::Scope, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MetadataFilter", &tse_FindMetadata::MetadataFilter, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxMatches", &tse_FindMetadata::MaxMatches, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("KeepAliveTime", &tse_FindMetadata::KeepAliveTime, "tse", xml_convert::serialize_type::full)
    );
};


// FindMetadataResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_FindMetadataResponse {
    // A unique reference to the search session created by this request.
    tt_JobToken SearchToken;
};


// XmlTraits for tse_FindMetadataResponse
template<>
struct xml_convert::XmlTraits<tse_FindMetadataResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchToken", &tse_FindMetadataResponse::SearchToken, "tse", xml_convert::serialize_type::full)
    );
};


// GetMetadataSearchResults 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetMetadataSearchResults {
    // The search session to get results from.
    tt_JobToken SearchToken;
    // The minimum number of results to return in one response.
    std::optional<int32_t> MinResults;
    // The maximum number of results to return in one response.
    std::optional<int32_t> MaxResults;
    // The maximum time before responding to the request, even if the MinResults parameter is not fulfilled.
    std::optional<my_Duration> WaitTime;
};


// XmlTraits for tse_GetMetadataSearchResults
template<>
struct xml_convert::XmlTraits<tse_GetMetadataSearchResults> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchToken", &tse_GetMetadataSearchResults::SearchToken, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinResults", &tse_GetMetadataSearchResults::MinResults, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxResults", &tse_GetMetadataSearchResults::MaxResults, "tse", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WaitTime", &tse_GetMetadataSearchResults::WaitTime, "tse", xml_convert::serialize_type::full)
    );
};


// GetMetadataSearchResultsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetMetadataSearchResultsResponse {
    tt_FindMetadataResultList ResultList;
};


// XmlTraits for tse_GetMetadataSearchResultsResponse
template<>
struct xml_convert::XmlTraits<tse_GetMetadataSearchResultsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ResultList", &tse_GetMetadataSearchResultsResponse::ResultList, "tse", xml_convert::serialize_type::full)
    );
};


// GetSearchState 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetSearchState {
    // The search session to get the state from.
    tt_JobToken SearchToken;
};


// XmlTraits for tse_GetSearchState
template<>
struct xml_convert::XmlTraits<tse_GetSearchState> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchToken", &tse_GetSearchState::SearchToken, "tse", xml_convert::serialize_type::full)
    );
};


// GetSearchStateResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_GetSearchStateResponse {
    tt_SearchState State;
};


// XmlTraits for tse_GetSearchStateResponse
template<>
struct xml_convert::XmlTraits<tse_GetSearchStateResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("State", &tse_GetSearchStateResponse::State, "tse", xml_convert::serialize_type::full)
    );
};


// EndSearch 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_EndSearch {
    // The search session to end.
    tt_JobToken SearchToken;
};


// XmlTraits for tse_EndSearch
template<>
struct xml_convert::XmlTraits<tse_EndSearch> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchToken", &tse_EndSearch::SearchToken, "tse", xml_convert::serialize_type::full)
    );
};


// EndSearchResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/search/wsdl
// 源文件: search_v10.wsdl
struct tse_EndSearchResponse {
    // The point of time the search had reached when it was ended. It is equal to the EndPoint specified in Find-operation if the search was completed.
    std::string Endpoint;
};


// XmlTraits for tse_EndSearchResponse
template<>
struct xml_convert::XmlTraits<tse_EndSearchResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Endpoint", &tse_EndSearchResponse::Endpoint, "tse", xml_convert::serialize_type::full)
    );
};


} // namespace libonvif_client
