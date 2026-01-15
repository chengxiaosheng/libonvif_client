/**
 * @file bd.h
 * @brief 从 humanbody_v20.xsd 生成的类型定义
 * @namespace http://www.onvif.org/ver20/analytics/humanbody
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/common.h>

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

// BodyShape 枚举类型
// 基础类型: std::string
enum class  bd_BodyShape {
    Fat,
    Thin,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_BodyShape value) {
    switch (value) {
        case bd_BodyShape::Fat: return "Fat";
        case bd_BodyShape::Thin: return "Thin";
        case bd_BodyShape::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_BodyShape& value, const std::string& str) {
    if (str == "Fat") { value = bd_BodyShape::Fat; return true; }
    if (str == "Thin") { value = bd_BodyShape::Thin; return true; }
    if (str == "Other") { value = bd_BodyShape::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_BodyShape
template<>
struct xml_convert::XmlValueAdapter<bd_BodyShape> {
    static bool from_xml_val(bd_BodyShape& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_BodyShape& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_BodyShape
template<>
struct xml_convert::XmlAttributeAdapter<bd_BodyShape> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_BodyShape& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_BodyShape& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// BodyMetric 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_BodyMetric {
    // Describe the Stature of the body, the unit is centimeter.
    std::optional<int32_t> Height;
    // Describle the Shape of the body, acceptable values are defined in bd:BodyShape.
    std::optional<std::string> BodyShape;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_BodyMetric
template<>
struct xml_convert::XmlTraits<bd_BodyMetric> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Height", &bd_BodyMetric::Height, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BodyShape", &bd_BodyMetric::BodyShape, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_BodyMetric::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_BodyMetric::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Scarf 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Scarf {
    // Describe the Color of the Scarf, acceptable values are defined in ColorDescriptor.
    std::optional<tt_ColorDescriptor> Color;
    // Describe if the body wears the Scarf.
    std::optional<bool> Wear;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Scarf
template<>
struct xml_convert::XmlTraits<bd_Scarf> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Color", &bd_Scarf::Color, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Wear", &bd_Scarf::Wear, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Scarf::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Scarf::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Gloves 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Gloves {
    // Describe the Color of Gloves, acceptable values are defined in tt:ColorDescriptor.
    std::optional<tt_ColorDescriptor> Color;
    // Describe if the body wears Gloves.
    std::optional<bool> Wear;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Gloves
template<>
struct xml_convert::XmlTraits<bd_Gloves> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Color", &bd_Gloves::Color, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Wear", &bd_Gloves::Wear, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Gloves::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Gloves::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// TopsCategory 枚举类型
// 基础类型: std::string
enum class  bd_TopsCategory {
    LongSleeve,
    ShortSleeve,
    Sleeveless,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_TopsCategory value) {
    switch (value) {
        case bd_TopsCategory::LongSleeve: return "LongSleeve";
        case bd_TopsCategory::ShortSleeve: return "ShortSleeve";
        case bd_TopsCategory::Sleeveless: return "Sleeveless";
        case bd_TopsCategory::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_TopsCategory& value, const std::string& str) {
    if (str == "LongSleeve") { value = bd_TopsCategory::LongSleeve; return true; }
    if (str == "ShortSleeve") { value = bd_TopsCategory::ShortSleeve; return true; }
    if (str == "Sleeveless") { value = bd_TopsCategory::Sleeveless; return true; }
    if (str == "Other") { value = bd_TopsCategory::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_TopsCategory
template<>
struct xml_convert::XmlValueAdapter<bd_TopsCategory> {
    static bool from_xml_val(bd_TopsCategory& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_TopsCategory& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_TopsCategory
template<>
struct xml_convert::XmlAttributeAdapter<bd_TopsCategory> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_TopsCategory& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_TopsCategory& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Grain 枚举类型
// 基础类型: std::string
enum class  bd_Grain {
    Stria,
    Plaid,
    PureColour,
    Decal,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_Grain value) {
    switch (value) {
        case bd_Grain::Stria: return "Stria";
        case bd_Grain::Plaid: return "Plaid";
        case bd_Grain::PureColour: return "PureColour";
        case bd_Grain::Decal: return "Decal";
        case bd_Grain::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_Grain& value, const std::string& str) {
    if (str == "Stria") { value = bd_Grain::Stria; return true; }
    if (str == "Plaid") { value = bd_Grain::Plaid; return true; }
    if (str == "PureColour") { value = bd_Grain::PureColour; return true; }
    if (str == "Decal") { value = bd_Grain::Decal; return true; }
    if (str == "Other") { value = bd_Grain::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_Grain
template<>
struct xml_convert::XmlValueAdapter<bd_Grain> {
    static bool from_xml_val(bd_Grain& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_Grain& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_Grain
template<>
struct xml_convert::XmlAttributeAdapter<bd_Grain> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_Grain& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_Grain& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// TopsStyle 枚举类型
// 基础类型: std::string
enum class  bd_TopsStyle {
    Tailor,
    Jacket,
    Shirt,
    Sweater,
    Overcoat,
    Dress,
    Vest,
    SafetyVest,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_TopsStyle value) {
    switch (value) {
        case bd_TopsStyle::Tailor: return "Tailor";
        case bd_TopsStyle::Jacket: return "Jacket";
        case bd_TopsStyle::Shirt: return "Shirt";
        case bd_TopsStyle::Sweater: return "Sweater";
        case bd_TopsStyle::Overcoat: return "Overcoat";
        case bd_TopsStyle::Dress: return "Dress";
        case bd_TopsStyle::Vest: return "Vest";
        case bd_TopsStyle::SafetyVest: return "SafetyVest";
        case bd_TopsStyle::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_TopsStyle& value, const std::string& str) {
    if (str == "Tailor") { value = bd_TopsStyle::Tailor; return true; }
    if (str == "Jacket") { value = bd_TopsStyle::Jacket; return true; }
    if (str == "Shirt") { value = bd_TopsStyle::Shirt; return true; }
    if (str == "Sweater") { value = bd_TopsStyle::Sweater; return true; }
    if (str == "Overcoat") { value = bd_TopsStyle::Overcoat; return true; }
    if (str == "Dress") { value = bd_TopsStyle::Dress; return true; }
    if (str == "Vest") { value = bd_TopsStyle::Vest; return true; }
    if (str == "SafetyVest") { value = bd_TopsStyle::SafetyVest; return true; }
    if (str == "Other") { value = bd_TopsStyle::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_TopsStyle
template<>
struct xml_convert::XmlValueAdapter<bd_TopsStyle> {
    static bool from_xml_val(bd_TopsStyle& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_TopsStyle& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_TopsStyle
template<>
struct xml_convert::XmlAttributeAdapter<bd_TopsStyle> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_TopsStyle& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_TopsStyle& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Tops 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Tops {
    // Describe the Category of the Tops, acceptable values are defined in bd:TopsCategory.
    std::optional<std::string> Category;
    // Describe the Color of the Tops, acceptable values are defined in tt:ColorDescriptor.
    std::optional<tt_ColorDescriptor> Color;
    // Describe the Grain of the Tops, acceptable values are defined in bd:Grain.
    std::optional<std::string> Grain;
    // Describe the Style of the Tops, acceptable values are defined in bd:TopsStyle.
    std::optional<std::string> Style;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Tops
template<>
struct xml_convert::XmlTraits<bd_Tops> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Category", &bd_Tops::Category, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &bd_Tops::Color, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Grain", &bd_Tops::Grain, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Style", &bd_Tops::Style, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Tops::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Tops::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// BottomsCategory 枚举类型
// 基础类型: std::string
enum class  bd_BottomsCategory {
    Trousers,
    Shorts,
    Skirt,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_BottomsCategory value) {
    switch (value) {
        case bd_BottomsCategory::Trousers: return "Trousers";
        case bd_BottomsCategory::Shorts: return "Shorts";
        case bd_BottomsCategory::Skirt: return "Skirt";
        case bd_BottomsCategory::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_BottomsCategory& value, const std::string& str) {
    if (str == "Trousers") { value = bd_BottomsCategory::Trousers; return true; }
    if (str == "Shorts") { value = bd_BottomsCategory::Shorts; return true; }
    if (str == "Skirt") { value = bd_BottomsCategory::Skirt; return true; }
    if (str == "Other") { value = bd_BottomsCategory::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_BottomsCategory
template<>
struct xml_convert::XmlValueAdapter<bd_BottomsCategory> {
    static bool from_xml_val(bd_BottomsCategory& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_BottomsCategory& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_BottomsCategory
template<>
struct xml_convert::XmlAttributeAdapter<bd_BottomsCategory> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_BottomsCategory& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_BottomsCategory& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// BottomsStyle 枚举类型
// 基础类型: std::string
enum class  bd_BottomsStyle {
    FormalPants,
    Jeans,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_BottomsStyle value) {
    switch (value) {
        case bd_BottomsStyle::FormalPants: return "FormalPants";
        case bd_BottomsStyle::Jeans: return "Jeans";
        case bd_BottomsStyle::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_BottomsStyle& value, const std::string& str) {
    if (str == "FormalPants") { value = bd_BottomsStyle::FormalPants; return true; }
    if (str == "Jeans") { value = bd_BottomsStyle::Jeans; return true; }
    if (str == "Other") { value = bd_BottomsStyle::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_BottomsStyle
template<>
struct xml_convert::XmlValueAdapter<bd_BottomsStyle> {
    static bool from_xml_val(bd_BottomsStyle& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_BottomsStyle& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_BottomsStyle
template<>
struct xml_convert::XmlAttributeAdapter<bd_BottomsStyle> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_BottomsStyle& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_BottomsStyle& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Bottoms 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Bottoms {
    // Describe the Category of the Bottoms, acceptable values are defined in bd:BottomsCategory.
    std::optional<std::string> Category;
    // Describe the Color of the Bottoms, acceptable values are defined in tt:ColorDescriptor.
    std::optional<tt_ColorDescriptor> Color;
    // Describe the Grain of the Bottoms, acceptable values are defined in bd:Grain.
    std::optional<std::string> Grain;
    // Describe the Style of the Bottoms, acceptable values are defined in bd:BottomsStyle.
    std::optional<std::string> Style;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Bottoms
template<>
struct xml_convert::XmlTraits<bd_Bottoms> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Category", &bd_Bottoms::Category, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &bd_Bottoms::Color, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Grain", &bd_Bottoms::Grain, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Style", &bd_Bottoms::Style, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Bottoms::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Bottoms::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ShoesCategory 枚举类型
// 基础类型: std::string
enum class  bd_ShoesCategory {
    Boots,
    LeatherShoes,
    Sneakers,
    Sandal,
    Slipper,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_ShoesCategory value) {
    switch (value) {
        case bd_ShoesCategory::Boots: return "Boots";
        case bd_ShoesCategory::LeatherShoes: return "LeatherShoes";
        case bd_ShoesCategory::Sneakers: return "Sneakers";
        case bd_ShoesCategory::Sandal: return "Sandal";
        case bd_ShoesCategory::Slipper: return "Slipper";
        case bd_ShoesCategory::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_ShoesCategory& value, const std::string& str) {
    if (str == "Boots") { value = bd_ShoesCategory::Boots; return true; }
    if (str == "LeatherShoes") { value = bd_ShoesCategory::LeatherShoes; return true; }
    if (str == "Sneakers") { value = bd_ShoesCategory::Sneakers; return true; }
    if (str == "Sandal") { value = bd_ShoesCategory::Sandal; return true; }
    if (str == "Slipper") { value = bd_ShoesCategory::Slipper; return true; }
    if (str == "Other") { value = bd_ShoesCategory::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_ShoesCategory
template<>
struct xml_convert::XmlValueAdapter<bd_ShoesCategory> {
    static bool from_xml_val(bd_ShoesCategory& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_ShoesCategory& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_ShoesCategory
template<>
struct xml_convert::XmlAttributeAdapter<bd_ShoesCategory> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_ShoesCategory& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_ShoesCategory& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Shoes 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Shoes {
    // Describe the Category of the Shoes, acceptable values are defined in bd:ShoesCategory.
    std::optional<std::string> Category;
    // Describe the Color of the Shoes, acceptable values are defined in tt:ColorDescriptor.
    std::optional<tt_ColorDescriptor> Color;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Shoes
template<>
struct xml_convert::XmlTraits<bd_Shoes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Category", &bd_Shoes::Category, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &bd_Shoes::Color, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Shoes::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Shoes::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Clothing 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Clothing {
    // Describe the Scarf of the body,acceptable values are defined in bd:Scarf.
    std::optional<bd_Scarf> Scarf;
    // Describe Gloves of the body,acceptable values are defined in bd:Gloves.
    std::optional<bd_Gloves> Gloves;
    // Describe the Tops of the body,acceptable values are defined in bd:Tops.
    std::optional<bd_Tops> Tops;
    // Describe the Bottoms of the body,acceptable values are defined in bd:Bottoms.
    std::optional<bd_Bottoms> Bottoms;
    // Describe the Shoes of the body,acceptable values are defined in bd:Shoes.
    std::optional<bd_Shoes> Shoes;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Clothing
template<>
struct xml_convert::XmlTraits<bd_Clothing> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Scarf", &bd_Clothing::Scarf, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Gloves", &bd_Clothing::Gloves, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Tops", &bd_Clothing::Tops, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Bottoms", &bd_Clothing::Bottoms, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Shoes", &bd_Clothing::Shoes, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Clothing::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Clothing::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// BagCategory 枚举类型
// 基础类型: std::string
enum class  bd_BagCategory {
    ShoulderBag,
    Backpack,
    ToteBag,
    Briefcase,
    Suitcase,
    SingleShoulderBag,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_BagCategory value) {
    switch (value) {
        case bd_BagCategory::ShoulderBag: return "ShoulderBag";
        case bd_BagCategory::Backpack: return "Backpack";
        case bd_BagCategory::ToteBag: return "ToteBag";
        case bd_BagCategory::Briefcase: return "Briefcase";
        case bd_BagCategory::Suitcase: return "Suitcase";
        case bd_BagCategory::SingleShoulderBag: return "SingleShoulderBag";
        case bd_BagCategory::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_BagCategory& value, const std::string& str) {
    if (str == "ShoulderBag") { value = bd_BagCategory::ShoulderBag; return true; }
    if (str == "Backpack") { value = bd_BagCategory::Backpack; return true; }
    if (str == "ToteBag") { value = bd_BagCategory::ToteBag; return true; }
    if (str == "Briefcase") { value = bd_BagCategory::Briefcase; return true; }
    if (str == "Suitcase") { value = bd_BagCategory::Suitcase; return true; }
    if (str == "SingleShoulderBag") { value = bd_BagCategory::SingleShoulderBag; return true; }
    if (str == "Other") { value = bd_BagCategory::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_BagCategory
template<>
struct xml_convert::XmlValueAdapter<bd_BagCategory> {
    static bool from_xml_val(bd_BagCategory& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_BagCategory& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_BagCategory
template<>
struct xml_convert::XmlAttributeAdapter<bd_BagCategory> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_BagCategory& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_BagCategory& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Bag 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Bag {
    // Describe the Category of the Bag, acceptable values are defined in bd:BagCategory.
    std::optional<std::string> Category;
    // Describe the Colour of the Bag, acceptable values are defined in tt:ColorDescriptor.
    std::optional<tt_ColorDescriptor> Color;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Bag
template<>
struct xml_convert::XmlTraits<bd_Bag> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Category", &bd_Bag::Category, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &bd_Bag::Color, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Bag::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Bag::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Umbrella 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Umbrella {
    // Describe the Color of the Bag, acceptable values are defined in tt:ColorDescriptor.
    std::optional<tt_ColorDescriptor> Color;
    // Describe if the body Opens the Umbrella.
    std::optional<bool> Open;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Umbrella
template<>
struct xml_convert::XmlTraits<bd_Umbrella> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Color", &bd_Umbrella::Color, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Open", &bd_Umbrella::Open, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Umbrella::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Umbrella::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Box 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Box {
    // Describe the Color of the Box, acceptable values are defined in tt:ColorDescriptor.
    std::optional<tt_ColorDescriptor> Color;
    // Describe if the body Lugs the Box.
    std::optional<bool> Lug;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Box
template<>
struct xml_convert::XmlTraits<bd_Box> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Color", &bd_Box::Color, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Lug", &bd_Box::Lug, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Box::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Box::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CartCategory 枚举类型
// 基础类型: std::string
enum class  bd_CartCategory {
    BabyCarriage,
    TwoWheelVehicle,
    Tricyle,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_CartCategory value) {
    switch (value) {
        case bd_CartCategory::BabyCarriage: return "BabyCarriage";
        case bd_CartCategory::TwoWheelVehicle: return "TwoWheelVehicle";
        case bd_CartCategory::Tricyle: return "Tricyle";
        case bd_CartCategory::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_CartCategory& value, const std::string& str) {
    if (str == "BabyCarriage") { value = bd_CartCategory::BabyCarriage; return true; }
    if (str == "TwoWheelVehicle") { value = bd_CartCategory::TwoWheelVehicle; return true; }
    if (str == "Tricyle") { value = bd_CartCategory::Tricyle; return true; }
    if (str == "Other") { value = bd_CartCategory::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_CartCategory
template<>
struct xml_convert::XmlValueAdapter<bd_CartCategory> {
    static bool from_xml_val(bd_CartCategory& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_CartCategory& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_CartCategory
template<>
struct xml_convert::XmlAttributeAdapter<bd_CartCategory> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_CartCategory& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_CartCategory& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Cart 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Cart {
    // Describe the Category of the Cart, acceptable values are defined in bd:CartCategory.
    std::optional<std::string> Category;
    // Describe the Color of the Cart, acceptable values are defined in tt:ColorDescriptor.
    std::optional<tt_ColorDescriptor> Color;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Cart
template<>
struct xml_convert::XmlTraits<bd_Cart> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Category", &bd_Cart::Category, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &bd_Cart::Color, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Cart::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Cart::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// WeaponCategory 枚举类型
// 基础类型: std::string
enum class  bd_WeaponCategory {
    Knife,
    Rifle,
    Pistol,
    Revolver
};

// 字符串转换函数
inline std::string to_string(bd_WeaponCategory value) {
    switch (value) {
        case bd_WeaponCategory::Knife: return "Knife";
        case bd_WeaponCategory::Rifle: return "Rifle";
        case bd_WeaponCategory::Pistol: return "Pistol";
        case bd_WeaponCategory::Revolver: return "Revolver";
        default: return "";
    }
}

inline bool from_string(bd_WeaponCategory& value, const std::string& str) {
    if (str == "Knife") { value = bd_WeaponCategory::Knife; return true; }
    if (str == "Rifle") { value = bd_WeaponCategory::Rifle; return true; }
    if (str == "Pistol") { value = bd_WeaponCategory::Pistol; return true; }
    if (str == "Revolver") { value = bd_WeaponCategory::Revolver; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_WeaponCategory
template<>
struct xml_convert::XmlValueAdapter<bd_WeaponCategory> {
    static bool from_xml_val(bd_WeaponCategory& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_WeaponCategory& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_WeaponCategory
template<>
struct xml_convert::XmlAttributeAdapter<bd_WeaponCategory> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_WeaponCategory& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_WeaponCategory& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// WeaponPose 枚举类型
// 基础类型: std::string
enum class  bd_WeaponPose {
    InHolster,
    InHand,
    Aiming
};

// 字符串转换函数
inline std::string to_string(bd_WeaponPose value) {
    switch (value) {
        case bd_WeaponPose::InHolster: return "InHolster";
        case bd_WeaponPose::InHand: return "InHand";
        case bd_WeaponPose::Aiming: return "Aiming";
        default: return "";
    }
}

inline bool from_string(bd_WeaponPose& value, const std::string& str) {
    if (str == "InHolster") { value = bd_WeaponPose::InHolster; return true; }
    if (str == "InHand") { value = bd_WeaponPose::InHand; return true; }
    if (str == "Aiming") { value = bd_WeaponPose::Aiming; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_WeaponPose
template<>
struct xml_convert::XmlValueAdapter<bd_WeaponPose> {
    static bool from_xml_val(bd_WeaponPose& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_WeaponPose& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_WeaponPose
template<>
struct xml_convert::XmlAttributeAdapter<bd_WeaponPose> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_WeaponPose& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_WeaponPose& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Weapon 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Weapon {
    // Describe the Category of the Weapon, acceptable values are defined in bd:WeaponCategory.
    std::optional<std::string> Category;
    // Describe the Color of the weapon, acceptable values are defined in tt:ColorDescriptor.
    std::optional<tt_ColorDescriptor> Color;
    // Describes how the weapon is held. Acceptable values are defined in bd:WeaponPose.
    std::optional<std::string> Pose;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Weapon
template<>
struct xml_convert::XmlTraits<bd_Weapon> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Category", &bd_Weapon::Category, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &bd_Weapon::Color, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Pose", &bd_Weapon::Pose, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Weapon::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Weapon::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Belonging 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Belonging {
    // Describe the Bag of the body,acceptable values are defined in bd:Bag
    std::optional<bd_Bag> Bag;
    // Describe the Umbrella carried by the body,acceptable values are defined in bd:Umbrella.
    std::optional<bd_Umbrella> Umbrella;
    // Describe if the body Lifts something.
    std::optional<bool> LiftSomething;
    // Describe the Box luffed by the body,acceptable values are defined in bd:Box.
    std::optional<bd_Box> Box;
    // Describe the Cart pushed by the body,acceptable values are defined in bd:Cart.
    std::optional<bd_Cart> Cart;
    // Describe if the body carries the Weapon.
    std::optional<bool> Weapon;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Belonging
template<>
struct xml_convert::XmlTraits<bd_Belonging> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Bag", &bd_Belonging::Bag, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Umbrella", &bd_Belonging::Umbrella, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("LiftSomething", &bd_Belonging::LiftSomething, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Box", &bd_Belonging::Box, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Cart", &bd_Belonging::Cart, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Weapon", &bd_Belonging::Weapon, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Belonging::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Belonging::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Belongings 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Belongings {
    // Describes a bag the body is wearing.
    std::vector<bd_Bag> Bag;
    // Describes an umbrella carried by the body.
    std::optional<bd_Umbrella> Umbrella;
    // Describes a cart pushed by the body.
    std::optional<bd_Cart> Cart;
    // Describe a waepon the body carries.
    std::vector<bd_Weapon> Weapon;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Belongings
template<>
struct xml_convert::XmlTraits<bd_Belongings> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Bag", &bd_Belongings::Bag, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Umbrella", &bd_Belongings::Umbrella, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Cart", &bd_Belongings::Cart, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Weapon", &bd_Belongings::Weapon, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Belongings::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Belongings::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Smoking 枚举类型
// 基础类型: std::string
enum class  bd_Smoking {
    NoSmoking,
    Cigar,
    ElectronicCigarettes,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_Smoking value) {
    switch (value) {
        case bd_Smoking::NoSmoking: return "NoSmoking";
        case bd_Smoking::Cigar: return "Cigar";
        case bd_Smoking::ElectronicCigarettes: return "ElectronicCigarettes";
        case bd_Smoking::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_Smoking& value, const std::string& str) {
    if (str == "NoSmoking") { value = bd_Smoking::NoSmoking; return true; }
    if (str == "Cigar") { value = bd_Smoking::Cigar; return true; }
    if (str == "ElectronicCigarettes") { value = bd_Smoking::ElectronicCigarettes; return true; }
    if (str == "Other") { value = bd_Smoking::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_Smoking
template<>
struct xml_convert::XmlValueAdapter<bd_Smoking> {
    static bool from_xml_val(bd_Smoking& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_Smoking& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_Smoking
template<>
struct xml_convert::XmlAttributeAdapter<bd_Smoking> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_Smoking& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_Smoking& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// UsingMobile 枚举类型
// 基础类型: std::string
enum class  bd_UsingMobile {
    ByLeftHand,
    ByRightHand,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_UsingMobile value) {
    switch (value) {
        case bd_UsingMobile::ByLeftHand: return "ByLeftHand";
        case bd_UsingMobile::ByRightHand: return "ByRightHand";
        case bd_UsingMobile::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_UsingMobile& value, const std::string& str) {
    if (str == "ByLeftHand") { value = bd_UsingMobile::ByLeftHand; return true; }
    if (str == "ByRightHand") { value = bd_UsingMobile::ByRightHand; return true; }
    if (str == "Other") { value = bd_UsingMobile::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_UsingMobile
template<>
struct xml_convert::XmlValueAdapter<bd_UsingMobile> {
    static bool from_xml_val(bd_UsingMobile& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_UsingMobile& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_UsingMobile
template<>
struct xml_convert::XmlAttributeAdapter<bd_UsingMobile> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_UsingMobile& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_UsingMobile& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// HumanActivity 枚举类型
// 基础类型: std::string
enum class  bd_HumanActivity {
    Walking,
    Running,
    Fallen,
    Squatting,
    Sitting,
    Standing,
    Driving,
    Other
};

// 字符串转换函数
inline std::string to_string(bd_HumanActivity value) {
    switch (value) {
        case bd_HumanActivity::Walking: return "Walking";
        case bd_HumanActivity::Running: return "Running";
        case bd_HumanActivity::Fallen: return "Fallen";
        case bd_HumanActivity::Squatting: return "Squatting";
        case bd_HumanActivity::Sitting: return "Sitting";
        case bd_HumanActivity::Standing: return "Standing";
        case bd_HumanActivity::Driving: return "Driving";
        case bd_HumanActivity::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(bd_HumanActivity& value, const std::string& str) {
    if (str == "Walking") { value = bd_HumanActivity::Walking; return true; }
    if (str == "Running") { value = bd_HumanActivity::Running; return true; }
    if (str == "Fallen") { value = bd_HumanActivity::Fallen; return true; }
    if (str == "Squatting") { value = bd_HumanActivity::Squatting; return true; }
    if (str == "Sitting") { value = bd_HumanActivity::Sitting; return true; }
    if (str == "Standing") { value = bd_HumanActivity::Standing; return true; }
    if (str == "Driving") { value = bd_HumanActivity::Driving; return true; }
    if (str == "Other") { value = bd_HumanActivity::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum bd_HumanActivity
template<>
struct xml_convert::XmlValueAdapter<bd_HumanActivity> {
    static bool from_xml_val(bd_HumanActivity& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const bd_HumanActivity& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum bd_HumanActivity
template<>
struct xml_convert::XmlAttributeAdapter<bd_HumanActivity> {
    static bool to_attribute(xmlNodePtr element, const char* name, const bd_HumanActivity& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(bd_HumanActivity& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Behaviour 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_Behaviour {
    // Acceptable values are defined in bd:Smoking.
    std::optional<std::string> Smoking;
    // Acceptable values are defined in bd:UsingMobile.
    std::optional<std::string> UsingMobile;
    // Describe the activity of the body, Acceptable values are defined in bd:HumanActivity.
    std::optional<std::string> Activity;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_Behaviour
template<>
struct xml_convert::XmlTraits<bd_Behaviour> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Smoking", &bd_Behaviour::Smoking, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UsingMobile", &bd_Behaviour::UsingMobile, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Activity", &bd_Behaviour::Activity, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_Behaviour::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_Behaviour::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// HumanBody 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanbody
// 源文件: humanbody_v20.xsd
struct bd_HumanBody {
    // Describe the body metric of the body.
    std::optional<bd_BodyMetric> BodyMetric;
    // Describe the Clothing of the body.
    std::optional<bd_Clothing> Clothing;
    // Deprecated set of belongings. Use Belongings.
    std::optional<bd_Belonging> Belonging;
    // Describe the Behaviour of the body.
    std::optional<bd_Behaviour> Behaviour;
    // Set of belongings.
    std::optional<bd_Belongings> Belongings;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for bd_HumanBody
template<>
struct xml_convert::XmlTraits<bd_HumanBody> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BodyMetric", &bd_HumanBody::BodyMetric, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Clothing", &bd_HumanBody::Clothing, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Belonging", &bd_HumanBody::Belonging, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Behaviour", &bd_HumanBody::Behaviour, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Belongings", &bd_HumanBody::Belongings, "bd", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &bd_HumanBody::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &bd_HumanBody::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


} // namespace libonvif_client
