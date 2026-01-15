/**
 * @file wsa.h
 * @brief 从 ws-addr.xsd 生成的类型定义
 * @namespace http://www.w3.org/2005/08/addressing
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

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

// AttributedURIType 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_AttributedURIType {
    // Value content based on xs:anyURI
    std::string value;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsa_AttributedURIType
template<>
struct xml_convert::XmlTraits<wsa_AttributedURIType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &wsa_AttributedURIType::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &wsa_AttributedURIType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ReferenceParametersType 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_ReferenceParametersType {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsa_ReferenceParametersType
template<>
struct xml_convert::XmlTraits<wsa_ReferenceParametersType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsa_ReferenceParametersType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &wsa_ReferenceParametersType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MetadataType 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_MetadataType {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsa_MetadataType
template<>
struct xml_convert::XmlTraits<wsa_MetadataType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsa_MetadataType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &wsa_MetadataType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Metadata 类型别名
// 基础类型: wsa_MetadataType
using wsa_Metadata = wsa_MetadataType;


// EndpointReferenceType 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_EndpointReferenceType {
    wsa_AttributedURIType Address;
    std::optional<wsa_ReferenceParametersType> ReferenceParameters;
    std::optional<wsa_Metadata> Metadata;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsa_EndpointReferenceType
template<>
struct xml_convert::XmlTraits<wsa_EndpointReferenceType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Address", &wsa_EndpointReferenceType::Address, "wsa", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ReferenceParameters", &wsa_EndpointReferenceType::ReferenceParameters, "wsa", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Metadata", &wsa_EndpointReferenceType::Metadata, "wsa", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wsa_EndpointReferenceType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &wsa_EndpointReferenceType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// EndpointReference 类型别名
// 基础类型: wsa_EndpointReferenceType
using wsa_EndpointReference = wsa_EndpointReferenceType;


// MessageID 类型别名
// 基础类型: wsa_AttributedURIType
using wsa_MessageID = wsa_AttributedURIType;


// RelationshipTypeOpenEnum 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_RelationshipTypeOpenEnum {
};


// XmlTraits for wsa_RelationshipTypeOpenEnum
template<>
struct xml_convert::XmlTraits<wsa_RelationshipTypeOpenEnum> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RelatesToType 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_RelatesToType {
    // Value content based on xs:anyURI
    std::string value;
    std::optional<wsa_RelationshipTypeOpenEnum> RelationshipType;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsa_RelatesToType
template<>
struct xml_convert::XmlTraits<wsa_RelatesToType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &wsa_RelatesToType::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RelationshipType", &wsa_RelatesToType::RelationshipType, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &wsa_RelatesToType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RelatesTo 类型别名
// 基础类型: wsa_RelatesToType
using wsa_RelatesTo = wsa_RelatesToType;


// RelationshipType 枚举类型
// 基础类型: std::string
enum class  wsa_RelationshipType {
    http_www_w3_org_2005_08_addressing_reply // http://www.w3.org/2005/08/addressing/reply
};

// 字符串转换函数
inline std::string to_string(wsa_RelationshipType value) {
    switch (value) {
        case wsa_RelationshipType::http_www_w3_org_2005_08_addressing_reply: return "http://www.w3.org/2005/08/addressing/reply";
        default: return "";
    }
}

inline bool from_string(wsa_RelationshipType& value, const std::string& str) {
    if (str == "http://www.w3.org/2005/08/addressing/reply") { value = wsa_RelationshipType::http_www_w3_org_2005_08_addressing_reply; return true; }
    return false;
}


// XmlValueAdapter specialization for enum wsa_RelationshipType
template<>
struct xml_convert::XmlValueAdapter<wsa_RelationshipType> {
    static bool from_xml_val(wsa_RelationshipType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const wsa_RelationshipType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum wsa_RelationshipType
template<>
struct xml_convert::XmlAttributeAdapter<wsa_RelationshipType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const wsa_RelationshipType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(wsa_RelationshipType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ReplyTo 类型别名
// 基础类型: wsa_EndpointReferenceType
using wsa_ReplyTo = wsa_EndpointReferenceType;


// From 类型别名
// 基础类型: wsa_EndpointReferenceType
using wsa_From = wsa_EndpointReferenceType;


// FaultTo 类型别名
// 基础类型: wsa_EndpointReferenceType
using wsa_FaultTo = wsa_EndpointReferenceType;


// To 类型别名
// 基础类型: wsa_AttributedURIType
using wsa_To = wsa_AttributedURIType;


// Action 类型别名
// 基础类型: wsa_AttributedURIType
using wsa_Action = wsa_AttributedURIType;


// FaultCodesOpenEnumType 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_FaultCodesOpenEnumType {
};


// XmlTraits for wsa_FaultCodesOpenEnumType
template<>
struct xml_convert::XmlTraits<wsa_FaultCodesOpenEnumType> {
    static constexpr auto fields = std::make_tuple(

    );
};


// FaultCodesType 枚举类型
// 基础类型: std::string
enum class  wsa_FaultCodesType {
    tns_InvalidAddressingHeader, // tns:InvalidAddressingHeader
    tns_InvalidAddress, // tns:InvalidAddress
    tns_InvalidEPR, // tns:InvalidEPR
    tns_InvalidCardinality, // tns:InvalidCardinality
    tns_MissingAddressInEPR, // tns:MissingAddressInEPR
    tns_DuplicateMessageID, // tns:DuplicateMessageID
    tns_ActionMismatch, // tns:ActionMismatch
    tns_MessageAddressingHeaderRequired, // tns:MessageAddressingHeaderRequired
    tns_DestinationUnreachable, // tns:DestinationUnreachable
    tns_ActionNotSupported, // tns:ActionNotSupported
    tns_EndpointUnavailable // tns:EndpointUnavailable
};

// 字符串转换函数
inline std::string to_string(wsa_FaultCodesType value) {
    switch (value) {
        case wsa_FaultCodesType::tns_InvalidAddressingHeader: return "tns:InvalidAddressingHeader";
        case wsa_FaultCodesType::tns_InvalidAddress: return "tns:InvalidAddress";
        case wsa_FaultCodesType::tns_InvalidEPR: return "tns:InvalidEPR";
        case wsa_FaultCodesType::tns_InvalidCardinality: return "tns:InvalidCardinality";
        case wsa_FaultCodesType::tns_MissingAddressInEPR: return "tns:MissingAddressInEPR";
        case wsa_FaultCodesType::tns_DuplicateMessageID: return "tns:DuplicateMessageID";
        case wsa_FaultCodesType::tns_ActionMismatch: return "tns:ActionMismatch";
        case wsa_FaultCodesType::tns_MessageAddressingHeaderRequired: return "tns:MessageAddressingHeaderRequired";
        case wsa_FaultCodesType::tns_DestinationUnreachable: return "tns:DestinationUnreachable";
        case wsa_FaultCodesType::tns_ActionNotSupported: return "tns:ActionNotSupported";
        case wsa_FaultCodesType::tns_EndpointUnavailable: return "tns:EndpointUnavailable";
        default: return "";
    }
}

inline bool from_string(wsa_FaultCodesType& value, const std::string& str) {
    if (str == "tns:InvalidAddressingHeader") { value = wsa_FaultCodesType::tns_InvalidAddressingHeader; return true; }
    if (str == "tns:InvalidAddress") { value = wsa_FaultCodesType::tns_InvalidAddress; return true; }
    if (str == "tns:InvalidEPR") { value = wsa_FaultCodesType::tns_InvalidEPR; return true; }
    if (str == "tns:InvalidCardinality") { value = wsa_FaultCodesType::tns_InvalidCardinality; return true; }
    if (str == "tns:MissingAddressInEPR") { value = wsa_FaultCodesType::tns_MissingAddressInEPR; return true; }
    if (str == "tns:DuplicateMessageID") { value = wsa_FaultCodesType::tns_DuplicateMessageID; return true; }
    if (str == "tns:ActionMismatch") { value = wsa_FaultCodesType::tns_ActionMismatch; return true; }
    if (str == "tns:MessageAddressingHeaderRequired") { value = wsa_FaultCodesType::tns_MessageAddressingHeaderRequired; return true; }
    if (str == "tns:DestinationUnreachable") { value = wsa_FaultCodesType::tns_DestinationUnreachable; return true; }
    if (str == "tns:ActionNotSupported") { value = wsa_FaultCodesType::tns_ActionNotSupported; return true; }
    if (str == "tns:EndpointUnavailable") { value = wsa_FaultCodesType::tns_EndpointUnavailable; return true; }
    return false;
}


// XmlValueAdapter specialization for enum wsa_FaultCodesType
template<>
struct xml_convert::XmlValueAdapter<wsa_FaultCodesType> {
    static bool from_xml_val(wsa_FaultCodesType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const wsa_FaultCodesType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum wsa_FaultCodesType
template<>
struct xml_convert::XmlAttributeAdapter<wsa_FaultCodesType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const wsa_FaultCodesType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(wsa_FaultCodesType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// AttributedUnsignedLongType 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_AttributedUnsignedLongType {
    // Value content based on xs:unsignedLong
    uint64_t value {};
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsa_AttributedUnsignedLongType
template<>
struct xml_convert::XmlTraits<wsa_AttributedUnsignedLongType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &wsa_AttributedUnsignedLongType::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &wsa_AttributedUnsignedLongType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RetryAfter 类型别名
// 基础类型: wsa_AttributedUnsignedLongType
using wsa_RetryAfter = wsa_AttributedUnsignedLongType;


// AttributedQNameType 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_AttributedQNameType {
    // Value content based on xs:QName
    std::string value;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsa_AttributedQNameType
template<>
struct xml_convert::XmlTraits<wsa_AttributedQNameType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &wsa_AttributedQNameType::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &wsa_AttributedQNameType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ProblemHeaderQName 类型别名
// 基础类型: wsa_AttributedQNameType
using wsa_ProblemHeaderQName = wsa_AttributedQNameType;


// AttributedAnyType 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_AttributedAnyType {
    // Any element from namespace: ##any (processContents: lax)
    AnyElement _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsa_AttributedAnyType
template<>
struct xml_convert::XmlTraits<wsa_AttributedAnyType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsa_AttributedAnyType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &wsa_AttributedAnyType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ProblemHeader 类型别名
// 基础类型: wsa_AttributedAnyType
using wsa_ProblemHeader = wsa_AttributedAnyType;


// ProblemIRI 类型别名
// 基础类型: wsa_AttributedURIType
using wsa_ProblemIRI = wsa_AttributedURIType;


// ProblemActionType 类型定义
// 命名空间: http://www.w3.org/2005/08/addressing
// 源文件: ws-addr.xsd
struct wsa_ProblemActionType {
    std::optional<wsa_Action> Action;
    std::optional<std::string> SoapAction;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsa_ProblemActionType
template<>
struct xml_convert::XmlTraits<wsa_ProblemActionType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Action", &wsa_ProblemActionType::Action, "wsa", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SoapAction", &wsa_ProblemActionType::SoapAction, "wsa", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &wsa_ProblemActionType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ProblemAction 类型别名
// 基础类型: wsa_ProblemActionType
using wsa_ProblemAction = wsa_ProblemActionType;


} // namespace libonvif_client
