/**
 * @file soap.h
 * @brief 从 soap-envelope.xml 生成的类型定义
 * @namespace http://www.w3.org/2003/05/soap-envelope
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/xs.h>

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
struct soap_subcode;

// Header 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_Header {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for soap_Header
template<>
struct xml_convert::XmlTraits<soap_Header> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &soap_Header::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &soap_Header::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Body 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_Body {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for soap_Body
template<>
struct xml_convert::XmlTraits<soap_Body> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &soap_Body::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &soap_Body::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Envelope 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_Envelope {
    std::optional<soap_Header> Header;
    soap_Body Body;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for soap_Envelope
template<>
struct xml_convert::XmlTraits<soap_Envelope> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Header", &soap_Envelope::Header, "soap", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Body", &soap_Envelope::Body, "soap", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &soap_Envelope::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// faultcodeEnum 枚举类型
// 基础类型: std::string
enum class  soap_faultcodeEnum {
    tns_DataEncodingUnknown, // tns:DataEncodingUnknown
    tns_MustUnderstand, // tns:MustUnderstand
    tns_Receiver, // tns:Receiver
    tns_Sender, // tns:Sender
    tns_VersionMismatch // tns:VersionMismatch
};

// 字符串转换函数
inline std::string to_string(soap_faultcodeEnum value) {
    switch (value) {
        case soap_faultcodeEnum::tns_DataEncodingUnknown: return "tns:DataEncodingUnknown";
        case soap_faultcodeEnum::tns_MustUnderstand: return "tns:MustUnderstand";
        case soap_faultcodeEnum::tns_Receiver: return "tns:Receiver";
        case soap_faultcodeEnum::tns_Sender: return "tns:Sender";
        case soap_faultcodeEnum::tns_VersionMismatch: return "tns:VersionMismatch";
        default: return "";
    }
}

inline bool from_string(soap_faultcodeEnum& value, const std::string& str) {
    if (str == "tns:DataEncodingUnknown") { value = soap_faultcodeEnum::tns_DataEncodingUnknown; return true; }
    if (str == "tns:MustUnderstand") { value = soap_faultcodeEnum::tns_MustUnderstand; return true; }
    if (str == "tns:Receiver") { value = soap_faultcodeEnum::tns_Receiver; return true; }
    if (str == "tns:Sender") { value = soap_faultcodeEnum::tns_Sender; return true; }
    if (str == "tns:VersionMismatch") { value = soap_faultcodeEnum::tns_VersionMismatch; return true; }
    return false;
}


// XmlValueAdapter specialization for enum soap_faultcodeEnum
template<>
struct xml_convert::XmlValueAdapter<soap_faultcodeEnum> {
    static bool from_xml_val(soap_faultcodeEnum& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const soap_faultcodeEnum& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum soap_faultcodeEnum
template<>
struct xml_convert::XmlAttributeAdapter<soap_faultcodeEnum> {
    static bool to_attribute(xmlNodePtr element, const char* name, const soap_faultcodeEnum& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(soap_faultcodeEnum& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// subcode 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_subcode {
    std::string Value;
    std::unique_ptr<soap_subcode> Subcode;
};


// XmlTraits for soap_subcode
template<>
struct xml_convert::XmlTraits<soap_subcode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Value", &soap_subcode::Value, "soap", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Subcode", &soap_subcode::Subcode, "soap", xml_convert::serialize_type::full)
    );
};


// faultcode 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_faultcode {
    soap_faultcodeEnum Value;
    std::optional<soap_subcode> Subcode;
};


// XmlTraits for soap_faultcode
template<>
struct xml_convert::XmlTraits<soap_faultcode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Value", &soap_faultcode::Value, "soap", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Subcode", &soap_faultcode::Subcode, "soap", xml_convert::serialize_type::full)
    );
};


// reasontext 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_reasontext {
    // Value content based on xs:string
    std::string value;
    std::string lang;
};


// XmlTraits for soap_reasontext
template<>
struct xml_convert::XmlTraits<soap_reasontext> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &soap_reasontext::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("lang", &soap_reasontext::lang, nullptr, xml_convert::serialize_type::attribute)
    );
};


// faultreason 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_faultreason {
    std::vector<soap_reasontext> Text;
};


// XmlTraits for soap_faultreason
template<>
struct xml_convert::XmlTraits<soap_faultreason> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Text", &soap_faultreason::Text, "soap", xml_convert::serialize_type::full)
    );
};


// detail 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_detail {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for soap_detail
template<>
struct xml_convert::XmlTraits<soap_detail> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &soap_detail::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &soap_detail::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Fault 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_Fault {
    soap_faultcode Code;
    soap_faultreason Reason;
    std::optional<std::string> Node;
    std::optional<std::string> Role;
    std::optional<soap_detail> Detail;
};


// XmlTraits for soap_Fault
template<>
struct xml_convert::XmlTraits<soap_Fault> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Code", &soap_Fault::Code, "soap", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Reason", &soap_Fault::Reason, "soap", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Node", &soap_Fault::Node, "soap", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Role", &soap_Fault::Role, "soap", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Detail", &soap_Fault::Detail, "soap", xml_convert::serialize_type::full)
    );
};


// NotUnderstoodType 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_NotUnderstoodType {
    std::string qname;
};


// XmlTraits for soap_NotUnderstoodType
template<>
struct xml_convert::XmlTraits<soap_NotUnderstoodType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("qname", &soap_NotUnderstoodType::qname, nullptr, xml_convert::serialize_type::attribute)
    );
};


// NotUnderstood 类型别名
// 基础类型: soap_NotUnderstoodType
using soap_NotUnderstood = soap_NotUnderstoodType;


// SupportedEnvType 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_SupportedEnvType {
    std::string qname;
};


// XmlTraits for soap_SupportedEnvType
template<>
struct xml_convert::XmlTraits<soap_SupportedEnvType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("qname", &soap_SupportedEnvType::qname, nullptr, xml_convert::serialize_type::attribute)
    );
};


// UpgradeType 类型定义
// 命名空间: http://www.w3.org/2003/05/soap-envelope
// 源文件: soap-envelope.xml
struct soap_UpgradeType {
    std::vector<soap_SupportedEnvType> SupportedEnvelope;
};


// XmlTraits for soap_UpgradeType
template<>
struct xml_convert::XmlTraits<soap_UpgradeType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SupportedEnvelope", &soap_UpgradeType::SupportedEnvelope, "soap", xml_convert::serialize_type::full)
    );
};


// Upgrade 类型别名
// 基础类型: soap_UpgradeType
using soap_Upgrade = soap_UpgradeType;


} // namespace libonvif_client
