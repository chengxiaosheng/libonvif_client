#pragma once

#include <optional>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <libonvif_client/xml_convert.h>
#include <libonvif_client/types/tt.h>
#include <libonvif_client/types/tse.h>
#include <libonvif_client/client/SearchPortClient.h>

namespace onvif_demo {

// SimpleItem — Name/Value as XML attributes
struct demo_SimpleItem {
    std::string Name;
    std::string Value;
    std::vector<libonvif_client::AnyElement> _any_;
    std::optional<std::map<std::string, std::string>> _attrs_;
};

// MessageSource — contains SimpleItem vector
struct demo_MessageSource {
    std::vector<demo_SimpleItem> SimpleItem;
    std::vector<libonvif_client::AnyElement> _any_;
    std::optional<std::map<std::string, std::string>> _attrs_;
};

// MessageData — contains SimpleItem vector
struct demo_MessageData {
    std::vector<demo_SimpleItem> SimpleItem;
    std::vector<libonvif_client::AnyElement> _any_;
    std::optional<std::map<std::string, std::string>> _attrs_;
};

// demo_tt_Message — parsed tt:Message (Source + Data + attributes)
struct demo_tt_Message {
    std::optional<demo_MessageSource> Source;
    std::optional<demo_MessageData> Data;
    std::vector<libonvif_client::AnyElement> _any_;
    std::optional<std::map<std::string, std::string>> _attrs_;
};

// demo_wsnt_Message — extends wsnt_Message, adds named Message field for <tt:Message>
struct demo_wsnt_Message : public libonvif_client::wsnt_Message {
    std::optional<demo_tt_Message> Message;
};

// demo_NotificationMessage — shadows Message field
struct demo_NotificationMessage : public libonvif_client::wsnt_NotificationMessageHolderType {
    demo_wsnt_Message Message;
};

// demo_FindEventResult — shadows Event field
struct demo_FindEventResult : public libonvif_client::tt_FindEventResult {
    demo_NotificationMessage Event;
};

// demo_FindEventResultList — shadows Result field
struct demo_FindEventResultList : public libonvif_client::tt_FindEventResultList {
    std::vector<demo_FindEventResult> Result;
};

// demo_GetEventSearchResultsResponse — shadows ResultList field
struct demo_GetEventSearchResultsResponse : public libonvif_client::tse_GetEventSearchResultsResponse {
    demo_FindEventResultList ResultList;
};

// CustomSearchClient — uses custom response type for GetEventSearchResults
class CustomSearchClient : public libonvif_client::SearchPortClient {
public:
    using SearchPortClient::SearchPortClient;

    void GetEventSearchResultsCustom(
        const libonvif_client::tse_GetEventSearchResults& request,
        libonvif_client::OnvifCallback<demo_GetEventSearchResultsResponse> callback);
};

} // namespace onvif_demo

// XmlTraits specializations — must be in xml_convert namespace
template<> struct libonvif_client::xml_convert::XmlTraits<onvif_demo::demo_SimpleItem> {
    static constexpr auto fields = std::make_tuple(
        libonvif_client::xml_convert::make_field_desc("Name",  &onvif_demo::demo_SimpleItem::Name,  nullptr, libonvif_client::xml_convert::serialize_type::full | libonvif_client::xml_convert::serialize_type::attribute),
        libonvif_client::xml_convert::make_field_desc("Value", &onvif_demo::demo_SimpleItem::Value, nullptr, libonvif_client::xml_convert::serialize_type::full | libonvif_client::xml_convert::serialize_type::attribute),
        libonvif_client::xml_convert::make_field_desc("_any_", &onvif_demo::demo_SimpleItem::_any_, nullptr, libonvif_client::xml_convert::serialize_type::full | libonvif_client::xml_convert::serialize_type::any_element),
        libonvif_client::xml_convert::make_field_desc("_attrs_", &onvif_demo::demo_SimpleItem::_attrs_, nullptr, libonvif_client::xml_convert::serialize_type::attribute)
    );
};

template<> struct libonvif_client::xml_convert::XmlTraits<onvif_demo::demo_MessageSource> {
    static constexpr auto fields = std::make_tuple(
        libonvif_client::xml_convert::make_field_desc("SimpleItem", &onvif_demo::demo_MessageSource::SimpleItem, "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("_any_", &onvif_demo::demo_MessageSource::_any_, nullptr, libonvif_client::xml_convert::serialize_type::full | libonvif_client::xml_convert::serialize_type::any_element),
        libonvif_client::xml_convert::make_field_desc("_attrs_", &onvif_demo::demo_MessageSource::_attrs_, nullptr, libonvif_client::xml_convert::serialize_type::attribute)
    );
};

template<> struct libonvif_client::xml_convert::XmlTraits<onvif_demo::demo_MessageData> {
    static constexpr auto fields = std::make_tuple(
        libonvif_client::xml_convert::make_field_desc("SimpleItem", &onvif_demo::demo_MessageData::SimpleItem, "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("_any_", &onvif_demo::demo_MessageData::_any_, nullptr, libonvif_client::xml_convert::serialize_type::full | libonvif_client::xml_convert::serialize_type::any_element),
        libonvif_client::xml_convert::make_field_desc("_attrs_", &onvif_demo::demo_MessageData::_attrs_, nullptr, libonvif_client::xml_convert::serialize_type::attribute)
    );
};

template<> struct libonvif_client::xml_convert::XmlTraits<onvif_demo::demo_tt_Message> {
    static constexpr auto fields = std::make_tuple(
        libonvif_client::xml_convert::make_field_desc("Source",  &onvif_demo::demo_tt_Message::Source,  "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("Data",    &onvif_demo::demo_tt_Message::Data,    "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("_any_",   &onvif_demo::demo_tt_Message::_any_,   nullptr, libonvif_client::xml_convert::serialize_type::full | libonvif_client::xml_convert::serialize_type::any_element),
        libonvif_client::xml_convert::make_field_desc("_attrs_", &onvif_demo::demo_tt_Message::_attrs_, nullptr, libonvif_client::xml_convert::serialize_type::attribute)
    );
};

template<> struct libonvif_client::xml_convert::XmlTraits<onvif_demo::demo_wsnt_Message> {
    static constexpr auto fields = std::make_tuple(
        libonvif_client::xml_convert::make_field_desc("Message", &onvif_demo::demo_wsnt_Message::Message, "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("_any_", &onvif_demo::demo_wsnt_Message::_any_, nullptr, libonvif_client::xml_convert::serialize_type::full | libonvif_client::xml_convert::serialize_type::any_element)
    );
};

template<> struct libonvif_client::xml_convert::XmlTraits<onvif_demo::demo_NotificationMessage> {
    static constexpr auto fields = std::make_tuple(
        libonvif_client::xml_convert::make_field_desc("Topic", &onvif_demo::demo_NotificationMessage::Topic, "wsnt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("Message", &onvif_demo::demo_NotificationMessage::Message, "wsnt", libonvif_client::xml_convert::serialize_type::full)
    );
};

template<> struct libonvif_client::xml_convert::XmlTraits<onvif_demo::demo_FindEventResult> {
    static constexpr auto fields = std::make_tuple(
        libonvif_client::xml_convert::make_field_desc("RecordingToken",  &onvif_demo::demo_FindEventResult::RecordingToken,  "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("TrackToken",      &onvif_demo::demo_FindEventResult::TrackToken,      "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("Time",            &onvif_demo::demo_FindEventResult::Time,            "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("Event",           &onvif_demo::demo_FindEventResult::Event,           "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("StartStateEvent", &onvif_demo::demo_FindEventResult::StartStateEvent, "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("_any_", &onvif_demo::demo_FindEventResult::_any_, nullptr, libonvif_client::xml_convert::serialize_type::full | libonvif_client::xml_convert::serialize_type::any_element),
        libonvif_client::xml_convert::make_field_desc("_attrs_", &onvif_demo::demo_FindEventResult::_attrs_, nullptr, libonvif_client::xml_convert::serialize_type::attribute)
    );
};

template<> struct libonvif_client::xml_convert::XmlTraits<onvif_demo::demo_FindEventResultList> {
    static constexpr auto fields = std::make_tuple(
        libonvif_client::xml_convert::make_field_desc("SearchState", &onvif_demo::demo_FindEventResultList::SearchState, "tt", libonvif_client::xml_convert::serialize_type::full),
        libonvif_client::xml_convert::make_field_desc("Result", &onvif_demo::demo_FindEventResultList::Result, "tt", libonvif_client::xml_convert::serialize_type::full)
    );
};

template<> struct libonvif_client::xml_convert::XmlTraits<onvif_demo::demo_GetEventSearchResultsResponse> {
    static constexpr auto fields = std::make_tuple(
    libonvif_client::xml_convert::make_field_desc("ResultList", &onvif_demo::demo_GetEventSearchResultsResponse::ResultList, "tse", libonvif_client::xml_convert::serialize_type::full)
    );
};