/**
 * @file metadata.h
 * @brief 从 metadatastream_v10.xsd 生成的类型定义
 * @namespace http://www.onvif.org/ver10/schema
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/bd.h>
#include <libonvif_client/types/common.h>
#include <libonvif_client/types/fc.h>
#include <libonvif_client/types/wsnt.h>

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

// ShapeDescriptorExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_ShapeDescriptorExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ShapeDescriptorExtension
template<>
struct xml_convert::XmlTraits<tt_ShapeDescriptorExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ShapeDescriptorExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ShapeDescriptor 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_ShapeDescriptor {
    tt_Rectangle BoundingBox;
    tt_Vector CenterOfGravity;
    std::vector<tt_Polygon> Polygon;
    std::optional<tt_ShapeDescriptorExtension> Extension;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ShapeDescriptor
template<>
struct xml_convert::XmlTraits<tt_ShapeDescriptor> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BoundingBox", &tt_ShapeDescriptor::BoundingBox, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CenterOfGravity", &tt_ShapeDescriptor::CenterOfGravity, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Polygon", &tt_ShapeDescriptor::Polygon, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ShapeDescriptor::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ShapeDescriptor::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ShapeDescriptor::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ClassType 枚举类型
// 基础类型: std::string
enum class  tt_ClassType {
    Animal,
    Face,
    Human,
    Vehical,
    Other
};

// 字符串转换函数
inline std::string to_string(tt_ClassType value) {
    switch (value) {
        case tt_ClassType::Animal: return "Animal";
        case tt_ClassType::Face: return "Face";
        case tt_ClassType::Human: return "Human";
        case tt_ClassType::Vehical: return "Vehical";
        case tt_ClassType::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(tt_ClassType& value, const std::string& str) {
    if (str == "Animal") { value = tt_ClassType::Animal; return true; }
    if (str == "Face") { value = tt_ClassType::Face; return true; }
    if (str == "Human") { value = tt_ClassType::Human; return true; }
    if (str == "Vehical") { value = tt_ClassType::Vehical; return true; }
    if (str == "Other") { value = tt_ClassType::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ClassType
template<>
struct xml_convert::XmlValueAdapter<tt_ClassType> {
    static bool from_xml_val(tt_ClassType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ClassType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ClassType
template<>
struct xml_convert::XmlAttributeAdapter<tt_ClassType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ClassType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ClassType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ClassCandidate 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_ClassCandidate {
    tt_ClassType Type;
    float Likelihood {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ClassCandidate
template<>
struct xml_convert::XmlTraits<tt_ClassCandidate> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_ClassCandidate::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Likelihood", &tt_ClassCandidate::Likelihood, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ClassCandidate::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// OtherType 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_OtherType {
    // Object Class Type
    std::string Type;
    // A likelihood/probability that the corresponding object belongs to this class. The sum of the likelihoods shall NOT exceed 1
    float Likelihood {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OtherType
template<>
struct xml_convert::XmlTraits<tt_OtherType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_OtherType::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Likelihood", &tt_OtherType::Likelihood, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_OtherType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_OtherType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ClassDescriptorExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_ClassDescriptorExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::vector<tt_OtherType> OtherTypes;
};


// XmlTraits for tt_ClassDescriptorExtension
template<>
struct xml_convert::XmlTraits<tt_ClassDescriptorExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ClassDescriptorExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("OtherTypes", &tt_ClassDescriptorExtension::OtherTypes, "tt", xml_convert::serialize_type::full)
    );
};


// StringLikelihood 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_StringLikelihood {
    // Value content based on xs:string
    std::string value;
    std::optional<float> Likelihood;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_StringLikelihood
template<>
struct xml_convert::XmlTraits<tt_StringLikelihood> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &tt_StringLikelihood::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Likelihood", &tt_StringLikelihood::Likelihood, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_StringLikelihood::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ClassDescriptor 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_ClassDescriptor {
    std::vector<tt_ClassCandidate> ClassCandidate;
    std::optional<tt_ClassDescriptorExtension> Extension;
    // For well-defined values see tt:ObjectType. Other type definitions like tt:VehicleType may be applied as well.
    std::vector<tt_StringLikelihood> Type;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ClassDescriptor
template<>
struct xml_convert::XmlTraits<tt_ClassDescriptor> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ClassCandidate", &tt_ClassDescriptor::ClassCandidate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ClassDescriptor::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Type", &tt_ClassDescriptor::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ClassDescriptor::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// AppearanceExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_AppearanceExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_AppearanceExtension
template<>
struct xml_convert::XmlTraits<tt_AppearanceExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AppearanceExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// VehicleInfo 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_VehicleInfo {
    tt_StringLikelihood Type;
    std::optional<tt_StringLikelihood> Brand;
    std::optional<tt_StringLikelihood> Model;
    std::optional<tt_ColorDescriptor> Color;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VehicleInfo
template<>
struct xml_convert::XmlTraits<tt_VehicleInfo> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_VehicleInfo::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Brand", &tt_VehicleInfo::Brand, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Model", &tt_VehicleInfo::Model, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &tt_VehicleInfo::Color, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VehicleInfo::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_VehicleInfo::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// LicensePlateInfo 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_LicensePlateInfo {
    // A string of vehicle license plate number.
    tt_StringLikelihood PlateNumber;
    // A description of the vehicle license plate, e.g., "Normal", "Police", "Diplomat"
    std::optional<tt_StringLikelihood> PlateType;
    // Describe the country of the license plate, in order to avoid the same license plate number.
    std::optional<tt_StringLikelihood> CountryCode;
    // State province or authority that issue the license plate.
    std::optional<tt_StringLikelihood> IssuingEntity;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_LicensePlateInfo
template<>
struct xml_convert::XmlTraits<tt_LicensePlateInfo> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PlateNumber", &tt_LicensePlateInfo::PlateNumber, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PlateType", &tt_LicensePlateInfo::PlateType, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CountryCode", &tt_LicensePlateInfo::CountryCode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IssuingEntity", &tt_LicensePlateInfo::IssuingEntity, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_LicensePlateInfo::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_LicensePlateInfo::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// BarcodeInfo 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_BarcodeInfo {
    // Information encoded in barcode
    tt_StringLikelihood Data;
    // Acceptable values are defined in tt:BarcodeType
    std::optional<tt_StringLikelihood> Type;
    // Refers to the pixels per module
    std::optional<float> PPM;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_BarcodeInfo
template<>
struct xml_convert::XmlTraits<tt_BarcodeInfo> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Data", &tt_BarcodeInfo::Data, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Type", &tt_BarcodeInfo::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PPM", &tt_BarcodeInfo::PPM, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_BarcodeInfo::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_BarcodeInfo::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// LabelInfo 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_LabelInfo {
    std::string Authority;
    std::string ID;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<float> Likelihood;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_LabelInfo
template<>
struct xml_convert::XmlTraits<tt_LabelInfo> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Authority", &tt_LabelInfo::Authority, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ID", &tt_LabelInfo::ID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_LabelInfo::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Likelihood", &tt_LabelInfo::Likelihood, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_LabelInfo::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Appearance 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_Appearance {
    std::optional<tt_Transformation> Transformation;
    std::optional<tt_ShapeDescriptor> Shape;
    std::optional<tt_ColorDescriptor> Color;
    std::optional<tt_ClassDescriptor> Class;
    std::optional<tt_AppearanceExtension> Extension;
    std::optional<tt_GeoLocation> GeoLocation;
    std::vector<tt_VehicleInfo> VehicleInfo;
    std::optional<tt_LicensePlateInfo> LicensePlateInfo;
    std::optional<fc_HumanFace> HumanFace;
    std::optional<bd_HumanBody> HumanBody;
    std::optional<std::string> ImageRef;
    std::optional<std::string> Image;
    std::optional<tt_BarcodeInfo> BarcodeInfo;
    std::optional<tt_SphericalCoordinate> SphericalCoordinate;
    std::vector<tt_LabelInfo> Label;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Appearance
template<>
struct xml_convert::XmlTraits<tt_Appearance> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Transformation", &tt_Appearance::Transformation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Shape", &tt_Appearance::Shape, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &tt_Appearance::Color, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Class", &tt_Appearance::Class, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Appearance::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("GeoLocation", &tt_Appearance::GeoLocation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VehicleInfo", &tt_Appearance::VehicleInfo, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("LicensePlateInfo", &tt_Appearance::LicensePlateInfo, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("HumanFace", &tt_Appearance::HumanFace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("HumanBody", &tt_Appearance::HumanBody, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ImageRef", &tt_Appearance::ImageRef, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Image", &tt_Appearance::Image, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BarcodeInfo", &tt_Appearance::BarcodeInfo, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SphericalCoordinate", &tt_Appearance::SphericalCoordinate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Label", &tt_Appearance::Label, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Appearance::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Appearance::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VehicleType 枚举类型
// 基础类型: std::string
enum class  tt_VehicleType {
    Bus,
    Car,
    Truck,
    Bicycle,
    Motorcycle
};

// 字符串转换函数
inline std::string to_string(tt_VehicleType value) {
    switch (value) {
        case tt_VehicleType::Bus: return "Bus";
        case tt_VehicleType::Car: return "Car";
        case tt_VehicleType::Truck: return "Truck";
        case tt_VehicleType::Bicycle: return "Bicycle";
        case tt_VehicleType::Motorcycle: return "Motorcycle";
        default: return "";
    }
}

inline bool from_string(tt_VehicleType& value, const std::string& str) {
    if (str == "Bus") { value = tt_VehicleType::Bus; return true; }
    if (str == "Car") { value = tt_VehicleType::Car; return true; }
    if (str == "Truck") { value = tt_VehicleType::Truck; return true; }
    if (str == "Bicycle") { value = tt_VehicleType::Bicycle; return true; }
    if (str == "Motorcycle") { value = tt_VehicleType::Motorcycle; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_VehicleType
template<>
struct xml_convert::XmlValueAdapter<tt_VehicleType> {
    static bool from_xml_val(tt_VehicleType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_VehicleType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_VehicleType
template<>
struct xml_convert::XmlAttributeAdapter<tt_VehicleType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_VehicleType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_VehicleType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// PlateType 枚举类型
// 基础类型: std::string
enum class  tt_PlateType {
    Normal,
    Police,
    Diplomat,
    Temporary
};

// 字符串转换函数
inline std::string to_string(tt_PlateType value) {
    switch (value) {
        case tt_PlateType::Normal: return "Normal";
        case tt_PlateType::Police: return "Police";
        case tt_PlateType::Diplomat: return "Diplomat";
        case tt_PlateType::Temporary: return "Temporary";
        default: return "";
    }
}

inline bool from_string(tt_PlateType& value, const std::string& str) {
    if (str == "Normal") { value = tt_PlateType::Normal; return true; }
    if (str == "Police") { value = tt_PlateType::Police; return true; }
    if (str == "Diplomat") { value = tt_PlateType::Diplomat; return true; }
    if (str == "Temporary") { value = tt_PlateType::Temporary; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_PlateType
template<>
struct xml_convert::XmlValueAdapter<tt_PlateType> {
    static bool from_xml_val(tt_PlateType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_PlateType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_PlateType
template<>
struct xml_convert::XmlAttributeAdapter<tt_PlateType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_PlateType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_PlateType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// BarcodeType 枚举类型
// 基础类型: std::string
enum class  tt_BarcodeType {
    Code_39, // Code-39
    Code_49, // Code-49
    Code_93, // Code-93
    Code_128, // Code-128
    Code_11, // Code-11
    Code_25_Interleaved, // Code-25-Interleaved
    Code_25_NonInterleaved, // Code-25-NonInterleaved
    DataMatrix,
    Maxicode,
    Postnet,
    RM4SCC,
    ISBN_13, // ISBN-13
    ISBN_13_Dual, // ISBN-13-Dual
    ISBN_10, // ISBN-10
    ITF_14, // ITF-14
    EAN_2, // EAN-2
    EAN_8, // EAN-8
    EAN_13, // EAN-13
    EAN_14, // EAN-14
    EAN_18, // EAN-18
    EAN_99, // EAN-99
    EAN_128, // EAN-128
    SCC_14, // SCC-14
    SSCC_18, // SSCC-18
    UPC_A, // UPC-A
    UPC_E, // UPC-E
    PDF417,
    QRCode
};

// 字符串转换函数
inline std::string to_string(tt_BarcodeType value) {
    switch (value) {
        case tt_BarcodeType::Code_39: return "Code-39";
        case tt_BarcodeType::Code_49: return "Code-49";
        case tt_BarcodeType::Code_93: return "Code-93";
        case tt_BarcodeType::Code_128: return "Code-128";
        case tt_BarcodeType::Code_11: return "Code-11";
        case tt_BarcodeType::Code_25_Interleaved: return "Code-25-Interleaved";
        case tt_BarcodeType::Code_25_NonInterleaved: return "Code-25-NonInterleaved";
        case tt_BarcodeType::DataMatrix: return "DataMatrix";
        case tt_BarcodeType::Maxicode: return "Maxicode";
        case tt_BarcodeType::Postnet: return "Postnet";
        case tt_BarcodeType::RM4SCC: return "RM4SCC";
        case tt_BarcodeType::ISBN_13: return "ISBN-13";
        case tt_BarcodeType::ISBN_13_Dual: return "ISBN-13-Dual";
        case tt_BarcodeType::ISBN_10: return "ISBN-10";
        case tt_BarcodeType::ITF_14: return "ITF-14";
        case tt_BarcodeType::EAN_2: return "EAN-2";
        case tt_BarcodeType::EAN_8: return "EAN-8";
        case tt_BarcodeType::EAN_13: return "EAN-13";
        case tt_BarcodeType::EAN_14: return "EAN-14";
        case tt_BarcodeType::EAN_18: return "EAN-18";
        case tt_BarcodeType::EAN_99: return "EAN-99";
        case tt_BarcodeType::EAN_128: return "EAN-128";
        case tt_BarcodeType::SCC_14: return "SCC-14";
        case tt_BarcodeType::SSCC_18: return "SSCC-18";
        case tt_BarcodeType::UPC_A: return "UPC-A";
        case tt_BarcodeType::UPC_E: return "UPC-E";
        case tt_BarcodeType::PDF417: return "PDF417";
        case tt_BarcodeType::QRCode: return "QRCode";
        default: return "";
    }
}

inline bool from_string(tt_BarcodeType& value, const std::string& str) {
    if (str == "Code-39") { value = tt_BarcodeType::Code_39; return true; }
    if (str == "Code-49") { value = tt_BarcodeType::Code_49; return true; }
    if (str == "Code-93") { value = tt_BarcodeType::Code_93; return true; }
    if (str == "Code-128") { value = tt_BarcodeType::Code_128; return true; }
    if (str == "Code-11") { value = tt_BarcodeType::Code_11; return true; }
    if (str == "Code-25-Interleaved") { value = tt_BarcodeType::Code_25_Interleaved; return true; }
    if (str == "Code-25-NonInterleaved") { value = tt_BarcodeType::Code_25_NonInterleaved; return true; }
    if (str == "DataMatrix") { value = tt_BarcodeType::DataMatrix; return true; }
    if (str == "Maxicode") { value = tt_BarcodeType::Maxicode; return true; }
    if (str == "Postnet") { value = tt_BarcodeType::Postnet; return true; }
    if (str == "RM4SCC") { value = tt_BarcodeType::RM4SCC; return true; }
    if (str == "ISBN-13") { value = tt_BarcodeType::ISBN_13; return true; }
    if (str == "ISBN-13-Dual") { value = tt_BarcodeType::ISBN_13_Dual; return true; }
    if (str == "ISBN-10") { value = tt_BarcodeType::ISBN_10; return true; }
    if (str == "ITF-14") { value = tt_BarcodeType::ITF_14; return true; }
    if (str == "EAN-2") { value = tt_BarcodeType::EAN_2; return true; }
    if (str == "EAN-8") { value = tt_BarcodeType::EAN_8; return true; }
    if (str == "EAN-13") { value = tt_BarcodeType::EAN_13; return true; }
    if (str == "EAN-14") { value = tt_BarcodeType::EAN_14; return true; }
    if (str == "EAN-18") { value = tt_BarcodeType::EAN_18; return true; }
    if (str == "EAN-99") { value = tt_BarcodeType::EAN_99; return true; }
    if (str == "EAN-128") { value = tt_BarcodeType::EAN_128; return true; }
    if (str == "SCC-14") { value = tt_BarcodeType::SCC_14; return true; }
    if (str == "SSCC-18") { value = tt_BarcodeType::SSCC_18; return true; }
    if (str == "UPC-A") { value = tt_BarcodeType::UPC_A; return true; }
    if (str == "UPC-E") { value = tt_BarcodeType::UPC_E; return true; }
    if (str == "PDF417") { value = tt_BarcodeType::PDF417; return true; }
    if (str == "QRCode") { value = tt_BarcodeType::QRCode; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_BarcodeType
template<>
struct xml_convert::XmlValueAdapter<tt_BarcodeType> {
    static bool from_xml_val(tt_BarcodeType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_BarcodeType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_BarcodeType
template<>
struct xml_convert::XmlAttributeAdapter<tt_BarcodeType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_BarcodeType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_BarcodeType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// LabelAuthority 枚举类型
// 基础类型: std::string
enum class  tt_LabelAuthority {
    ISO_3864,
    ISO_7010,
    UNECE_ADR,
    UNECE_GHS
};

// 字符串转换函数
inline std::string to_string(tt_LabelAuthority value) {
    switch (value) {
        case tt_LabelAuthority::ISO_3864: return "ISO_3864";
        case tt_LabelAuthority::ISO_7010: return "ISO_7010";
        case tt_LabelAuthority::UNECE_ADR: return "UNECE_ADR";
        case tt_LabelAuthority::UNECE_GHS: return "UNECE_GHS";
        default: return "";
    }
}

inline bool from_string(tt_LabelAuthority& value, const std::string& str) {
    if (str == "ISO_3864") { value = tt_LabelAuthority::ISO_3864; return true; }
    if (str == "ISO_7010") { value = tt_LabelAuthority::ISO_7010; return true; }
    if (str == "UNECE_ADR") { value = tt_LabelAuthority::UNECE_ADR; return true; }
    if (str == "UNECE_GHS") { value = tt_LabelAuthority::UNECE_GHS; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_LabelAuthority
template<>
struct xml_convert::XmlValueAdapter<tt_LabelAuthority> {
    static bool from_xml_val(tt_LabelAuthority& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_LabelAuthority& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_LabelAuthority
template<>
struct xml_convert::XmlAttributeAdapter<tt_LabelAuthority> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_LabelAuthority& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_LabelAuthority& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ObjectType 枚举类型
// 基础类型: std::string
enum class  tt_ObjectType {
    Animal,
    HumanFace,
    Human,
    Bicycle,
    Vehicle,
    LicensePlate,
    Bike,
    Barcode
};

// 字符串转换函数
inline std::string to_string(tt_ObjectType value) {
    switch (value) {
        case tt_ObjectType::Animal: return "Animal";
        case tt_ObjectType::HumanFace: return "HumanFace";
        case tt_ObjectType::Human: return "Human";
        case tt_ObjectType::Bicycle: return "Bicycle";
        case tt_ObjectType::Vehicle: return "Vehicle";
        case tt_ObjectType::LicensePlate: return "LicensePlate";
        case tt_ObjectType::Bike: return "Bike";
        case tt_ObjectType::Barcode: return "Barcode";
        default: return "";
    }
}

inline bool from_string(tt_ObjectType& value, const std::string& str) {
    if (str == "Animal") { value = tt_ObjectType::Animal; return true; }
    if (str == "HumanFace") { value = tt_ObjectType::HumanFace; return true; }
    if (str == "Human") { value = tt_ObjectType::Human; return true; }
    if (str == "Bicycle") { value = tt_ObjectType::Bicycle; return true; }
    if (str == "Vehicle") { value = tt_ObjectType::Vehicle; return true; }
    if (str == "LicensePlate") { value = tt_ObjectType::LicensePlate; return true; }
    if (str == "Bike") { value = tt_ObjectType::Bike; return true; }
    if (str == "Barcode") { value = tt_ObjectType::Barcode; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ObjectType
template<>
struct xml_convert::XmlValueAdapter<tt_ObjectType> {
    static bool from_xml_val(tt_ObjectType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ObjectType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ObjectType
template<>
struct xml_convert::XmlAttributeAdapter<tt_ObjectType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ObjectType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ObjectType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ObjectId 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_ObjectId {
    std::optional<int64_t> ObjectId;
    // Object unique identifier.
    std::optional<std::string> UUID;
};


// XmlTraits for tt_ObjectId
template<>
struct xml_convert::XmlTraits<tt_ObjectId> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ObjectId", &tt_ObjectId::ObjectId, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("UUID", &tt_ObjectId::UUID, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Removed 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_Removed {
    // Collection of any elements from namespace: ##other (processContents: strict)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_Removed
template<>
struct xml_convert::XmlTraits<tt_Removed> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_Removed::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Idle 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_Idle {
    // Collection of any elements from namespace: ##other (processContents: strict)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_Idle
template<>
struct xml_convert::XmlTraits<tt_Idle> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_Idle::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// BehaviourExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_BehaviourExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_BehaviourExtension
template<>
struct xml_convert::XmlTraits<tt_BehaviourExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_BehaviourExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Behaviour 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_Behaviour {
    std::optional<tt_Removed> Removed;
    std::optional<tt_Idle> Idle;
    std::optional<tt_BehaviourExtension> Extension;
    std::optional<float> Speed;
    // Direction the object is moving. Yaw describes the horizontal direction in the range [-180..180] where 0 is towards the right of the device and 90 is away from the device. Pitch describes the vertical direction in the range [-90..90] where 90 is upwards.
    std::optional<tt_GeoOrientation> Direction;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Behaviour
template<>
struct xml_convert::XmlTraits<tt_Behaviour> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Removed", &tt_Behaviour::Removed, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Idle", &tt_Behaviour::Idle, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Behaviour::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tt_Behaviour::Speed, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Direction", &tt_Behaviour::Direction, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Behaviour::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Behaviour::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ObjectExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_ObjectExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ObjectExtension
template<>
struct xml_convert::XmlTraits<tt_ObjectExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ObjectExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Object 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_Object : public tt_ObjectId {
    std::optional<tt_Appearance> Appearance;
    std::optional<tt_Behaviour> Behaviour;
    std::optional<tt_ObjectExtension> Extension;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Object ID of the parent object. eg: License plate object has Vehicle object as parent.
    std::optional<int64_t> Parent;
    // Object UUID of the parent object. eg: License plate object has Vehicle object as parent.
    std::optional<std::string> ParentUUID;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Object
template<>
struct xml_convert::XmlTraits<tt_Object> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ObjectId>::fields, std::make_tuple(
        xml_convert::make_field_desc("Appearance", &tt_Object::Appearance, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Behaviour", &tt_Object::Behaviour, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Object::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Object::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Parent", &tt_Object::Parent, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("ParentUUID", &tt_Object::ParentUUID, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_Object::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// Rename 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_Rename {
    tt_ObjectId from;
    tt_ObjectId to;
};


// XmlTraits for tt_Rename
template<>
struct xml_convert::XmlTraits<tt_Rename> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("from", &tt_Rename::from, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("to", &tt_Rename::to, "tt", xml_convert::serialize_type::full)
    );
};


// Split 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_Split {
    tt_ObjectId from;
    std::vector<tt_ObjectId> to;
};


// XmlTraits for tt_Split
template<>
struct xml_convert::XmlTraits<tt_Split> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("from", &tt_Split::from, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("to", &tt_Split::to, "tt", xml_convert::serialize_type::full)
    );
};


// Merge 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_Merge {
    std::vector<tt_ObjectId> from;
    tt_ObjectId to;
};


// XmlTraits for tt_Merge
template<>
struct xml_convert::XmlTraits<tt_Merge> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("from", &tt_Merge::from, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("to", &tt_Merge::to, "tt", xml_convert::serialize_type::full)
    );
};


// ObjectTreeExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_ObjectTreeExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ObjectTreeExtension
template<>
struct xml_convert::XmlTraits<tt_ObjectTreeExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ObjectTreeExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ObjectTree 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_ObjectTree {
    std::vector<tt_Rename> Rename;
    std::vector<tt_Split> Split;
    std::vector<tt_Merge> Merge;
    std::vector<tt_ObjectId> Delete;
    std::optional<tt_ObjectTreeExtension> Extension;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ObjectTree
template<>
struct xml_convert::XmlTraits<tt_ObjectTree> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Rename", &tt_ObjectTree::Rename, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Split", &tt_ObjectTree::Split, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Merge", &tt_ObjectTree::Merge, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Delete", &tt_ObjectTree::Delete, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ObjectTree::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ObjectTree::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ObjectTree::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MotionInCells 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_MotionInCells {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Number of columns of the cell grid (x dimension)
    int64_t Columns {};
    // Number of rows of the cell grid (y dimension)
    int64_t Rows {};
    // A “1” denotes a cell where motion is detected and a “0” an empty cell. The first cell is in the upper left corner. Then the cell order goes first from left to right and then from up to down.  If the number of cells is not a multiple of 8 the last byte is filled with zeros. The information is run length encoded according to Packbit coding in ISO 12369 (TIFF, Revision 6.0).
    std::string Cells;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MotionInCells
template<>
struct xml_convert::XmlTraits<tt_MotionInCells> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_MotionInCells::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Columns", &tt_MotionInCells::Columns, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Rows", &tt_MotionInCells::Rows, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Cells", &tt_MotionInCells::Cells, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_MotionInCells::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// FrameExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_FrameExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_FrameExtension2
template<>
struct xml_convert::XmlTraits<tt_FrameExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_FrameExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// FrameExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_FrameExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<tt_MotionInCells> MotionInCells;
    std::optional<tt_FrameExtension2> Extension;
};


// XmlTraits for tt_FrameExtension
template<>
struct xml_convert::XmlTraits<tt_FrameExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_FrameExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("MotionInCells", &tt_FrameExtension::MotionInCells, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_FrameExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// Frame 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_Frame {
    std::optional<tt_PTZStatus> PTZStatus;
    std::optional<tt_Transformation> Transformation;
    std::vector<tt_Object> Object;
    std::optional<tt_ObjectTree> ObjectTree;
    std::optional<tt_FrameExtension> Extension;
    std::optional<std::string> SceneImageRef;
    std::optional<std::string> SceneImage;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    std::string UtcTime;
    // Default color space of Color definitions in frame. Valid values are "RGB" and "YCbCr". Defaults to "YCbCr".
    std::optional<std::string> Colorspace;
    // Optional name of the analytics module that generated this frame.
    std::optional<std::string> Source;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Frame
template<>
struct xml_convert::XmlTraits<tt_Frame> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZStatus", &tt_Frame::PTZStatus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Transformation", &tt_Frame::Transformation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Object", &tt_Frame::Object, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ObjectTree", &tt_Frame::ObjectTree, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Frame::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SceneImageRef", &tt_Frame::SceneImageRef, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SceneImage", &tt_Frame::SceneImage, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Frame::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("UtcTime", &tt_Frame::UtcTime, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Colorspace", &tt_Frame::Colorspace, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Source", &tt_Frame::Source, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_Frame::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MetadataStream 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_MetadataStream {
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MetadataStream
template<>
struct xml_convert::XmlTraits<tt_MetadataStream> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_attrs_", &tt_MetadataStream::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioDescriptor 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_AudioDescriptor {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    std::string UtcTime;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioDescriptor
template<>
struct xml_convert::XmlTraits<tt_AudioDescriptor> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AudioDescriptor::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("UtcTime", &tt_AudioDescriptor::UtcTime, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_AudioDescriptor::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioAnalyticsStreamExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_AudioAnalyticsStreamExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioAnalyticsStreamExtension
template<>
struct xml_convert::XmlTraits<tt_AudioAnalyticsStreamExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AudioAnalyticsStreamExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioAnalyticsStreamExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioAnalyticsStream 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_AudioAnalyticsStream {
    std::vector<tt_AudioDescriptor> AudioDescriptor;
    std::optional<tt_AudioAnalyticsStreamExtension> Extension;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioAnalyticsStream
template<>
struct xml_convert::XmlTraits<tt_AudioAnalyticsStream> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AudioDescriptor", &tt_AudioAnalyticsStream::AudioDescriptor, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_AudioAnalyticsStream::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioAnalyticsStream::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioAnalyticsStream::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MetadataStreamExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_MetadataStreamExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MetadataStreamExtension2
template<>
struct xml_convert::XmlTraits<tt_MetadataStreamExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_MetadataStreamExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_MetadataStreamExtension2::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MetadataStreamExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_MetadataStreamExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<tt_AudioAnalyticsStream> AudioAnalyticsStream;
    std::optional<tt_MetadataStreamExtension2> Extension;
};


// XmlTraits for tt_MetadataStreamExtension
template<>
struct xml_convert::XmlTraits<tt_MetadataStreamExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_MetadataStreamExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("AudioAnalyticsStream", &tt_MetadataStreamExtension::AudioAnalyticsStream, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_MetadataStreamExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// VideoAnalyticsStream 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_VideoAnalyticsStream {
};


// XmlTraits for tt_VideoAnalyticsStream
template<>
struct xml_convert::XmlTraits<tt_VideoAnalyticsStream> {
    static constexpr auto fields = std::make_tuple(

    );
};


// VideoAnalyticsStreamExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_VideoAnalyticsStreamExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_VideoAnalyticsStreamExtension
template<>
struct xml_convert::XmlTraits<tt_VideoAnalyticsStreamExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_VideoAnalyticsStreamExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZStream 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_PTZStream {
};


// XmlTraits for tt_PTZStream
template<>
struct xml_convert::XmlTraits<tt_PTZStream> {
    static constexpr auto fields = std::make_tuple(

    );
};


// PTZStreamExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_PTZStreamExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZStreamExtension
template<>
struct xml_convert::XmlTraits<tt_PTZStreamExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZStreamExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// EventStream 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_EventStream {
};


// XmlTraits for tt_EventStream
template<>
struct xml_convert::XmlTraits<tt_EventStream> {
    static constexpr auto fields = std::make_tuple(

    );
};


// EventStreamExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: metadatastream_v10.xsd
struct tt_EventStreamExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_EventStreamExtension
template<>
struct xml_convert::XmlTraits<tt_EventStreamExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_EventStreamExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


} // namespace libonvif_client
