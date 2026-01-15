/**
 * @file fc.h
 * @brief 从 humanface_v20.xsd 生成的类型定义
 * @namespace http://www.onvif.org/ver20/analytics/humanface
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 * @comment ONVIF Analytics相关Schema
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

// Gender 枚举类型
// 基础类型: std::string
enum class  fc_Gender {
    Male,
    Female
};

// 字符串转换函数
inline std::string to_string(fc_Gender value) {
    switch (value) {
        case fc_Gender::Male: return "Male";
        case fc_Gender::Female: return "Female";
        default: return "";
    }
}

inline bool from_string(fc_Gender& value, const std::string& str) {
    if (str == "Male") { value = fc_Gender::Male; return true; }
    if (str == "Female") { value = fc_Gender::Female; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_Gender
template<>
struct xml_convert::XmlValueAdapter<fc_Gender> {
    static bool from_xml_val(fc_Gender& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_Gender& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_Gender
template<>
struct xml_convert::XmlAttributeAdapter<fc_Gender> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_Gender& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_Gender& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Complexion 枚举类型
// 基础类型: std::string
enum class  fc_Complexion {
    White,
    Black,
    Asian,
    Other
};

// 字符串转换函数
inline std::string to_string(fc_Complexion value) {
    switch (value) {
        case fc_Complexion::White: return "White";
        case fc_Complexion::Black: return "Black";
        case fc_Complexion::Asian: return "Asian";
        case fc_Complexion::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(fc_Complexion& value, const std::string& str) {
    if (str == "White") { value = fc_Complexion::White; return true; }
    if (str == "Black") { value = fc_Complexion::Black; return true; }
    if (str == "Asian") { value = fc_Complexion::Asian; return true; }
    if (str == "Other") { value = fc_Complexion::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_Complexion
template<>
struct xml_convert::XmlValueAdapter<fc_Complexion> {
    static bool from_xml_val(fc_Complexion& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_Complexion& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_Complexion
template<>
struct xml_convert::XmlAttributeAdapter<fc_Complexion> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_Complexion& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_Complexion& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// FacialShape 枚举类型
// 基础类型: std::string
enum class  fc_FacialShape {
    Long,
    Round,
    Square,
    Oval,
    Other
};

// 字符串转换函数
inline std::string to_string(fc_FacialShape value) {
    switch (value) {
        case fc_FacialShape::Long: return "Long";
        case fc_FacialShape::Round: return "Round";
        case fc_FacialShape::Square: return "Square";
        case fc_FacialShape::Oval: return "Oval";
        case fc_FacialShape::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(fc_FacialShape& value, const std::string& str) {
    if (str == "Long") { value = fc_FacialShape::Long; return true; }
    if (str == "Round") { value = fc_FacialShape::Round; return true; }
    if (str == "Square") { value = fc_FacialShape::Square; return true; }
    if (str == "Oval") { value = fc_FacialShape::Oval; return true; }
    if (str == "Other") { value = fc_FacialShape::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_FacialShape
template<>
struct xml_convert::XmlValueAdapter<fc_FacialShape> {
    static bool from_xml_val(fc_FacialShape& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_FacialShape& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_FacialShape
template<>
struct xml_convert::XmlAttributeAdapter<fc_FacialShape> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_FacialShape& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_FacialShape& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Length 枚举类型
// 基础类型: std::string
enum class  fc_Length {
    Long,
    Medium,
    Short
};

// 字符串转换函数
inline std::string to_string(fc_Length value) {
    switch (value) {
        case fc_Length::Long: return "Long";
        case fc_Length::Medium: return "Medium";
        case fc_Length::Short: return "Short";
        default: return "";
    }
}

inline bool from_string(fc_Length& value, const std::string& str) {
    if (str == "Long") { value = fc_Length::Long; return true; }
    if (str == "Medium") { value = fc_Length::Medium; return true; }
    if (str == "Short") { value = fc_Length::Short; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_Length
template<>
struct xml_convert::XmlValueAdapter<fc_Length> {
    static bool from_xml_val(fc_Length& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_Length& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_Length
template<>
struct xml_convert::XmlAttributeAdapter<fc_Length> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_Length& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_Length& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// HairStyle 枚举类型
// 基础类型: std::string
enum class  fc_HairStyle {
    Straight,
    Wave,
    Curly,
    CrewCut,
    Bald,
    Ponytail,
    Pigtail,
    Other
};

// 字符串转换函数
inline std::string to_string(fc_HairStyle value) {
    switch (value) {
        case fc_HairStyle::Straight: return "Straight";
        case fc_HairStyle::Wave: return "Wave";
        case fc_HairStyle::Curly: return "Curly";
        case fc_HairStyle::CrewCut: return "CrewCut";
        case fc_HairStyle::Bald: return "Bald";
        case fc_HairStyle::Ponytail: return "Ponytail";
        case fc_HairStyle::Pigtail: return "Pigtail";
        case fc_HairStyle::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(fc_HairStyle& value, const std::string& str) {
    if (str == "Straight") { value = fc_HairStyle::Straight; return true; }
    if (str == "Wave") { value = fc_HairStyle::Wave; return true; }
    if (str == "Curly") { value = fc_HairStyle::Curly; return true; }
    if (str == "CrewCut") { value = fc_HairStyle::CrewCut; return true; }
    if (str == "Bald") { value = fc_HairStyle::Bald; return true; }
    if (str == "Ponytail") { value = fc_HairStyle::Ponytail; return true; }
    if (str == "Pigtail") { value = fc_HairStyle::Pigtail; return true; }
    if (str == "Other") { value = fc_HairStyle::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_HairStyle
template<>
struct xml_convert::XmlValueAdapter<fc_HairStyle> {
    static bool from_xml_val(fc_HairStyle& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_HairStyle& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_HairStyle
template<>
struct xml_convert::XmlAttributeAdapter<fc_HairStyle> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_HairStyle& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_HairStyle& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Hair 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanface
// 源文件: humanface_v20.xsd
struct fc_Hair {
    /*
     * Describe the length of the Hair, acceptable values are defined in fc:Length. Short usually means that the end of the hair doesn’t exceed the shoulder.
     * Medium usually means that the end of the hair is parallel with the shoulder. Long usually means that the end of the hair exceeds the chest.
     */
    std::optional<std::string> Length;
    // Describe the style of the Hair, acceptable values are defined in fc:HairStyle.
    std::optional<std::string> Style;
    // Describe the color of the Hair.
    std::optional<tt_ColorDescriptor> Color;
    // Describe the bangs of the Hair
    std::optional<bool> Bangs;
};


// XmlTraits for fc_Hair
template<>
struct xml_convert::XmlTraits<fc_Hair> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Length", &fc_Hair::Length, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Style", &fc_Hair::Style, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &fc_Hair::Color, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Bangs", &fc_Hair::Bangs, "fc", xml_convert::serialize_type::full)
    );
};


// EyebrowWidth 枚举类型
// 基础类型: std::string
enum class  fc_EyebrowWidth {
    Long,
    Short
};

// 字符串转换函数
inline std::string to_string(fc_EyebrowWidth value) {
    switch (value) {
        case fc_EyebrowWidth::Long: return "Long";
        case fc_EyebrowWidth::Short: return "Short";
        default: return "";
    }
}

inline bool from_string(fc_EyebrowWidth& value, const std::string& str) {
    if (str == "Long") { value = fc_EyebrowWidth::Long; return true; }
    if (str == "Short") { value = fc_EyebrowWidth::Short; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_EyebrowWidth
template<>
struct xml_convert::XmlValueAdapter<fc_EyebrowWidth> {
    static bool from_xml_val(fc_EyebrowWidth& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_EyebrowWidth& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_EyebrowWidth
template<>
struct xml_convert::XmlAttributeAdapter<fc_EyebrowWidth> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_EyebrowWidth& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_EyebrowWidth& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// EyebrowSpace 枚举类型
// 基础类型: std::string
enum class  fc_EyebrowSpace {
    Joint,
    Separate
};

// 字符串转换函数
inline std::string to_string(fc_EyebrowSpace value) {
    switch (value) {
        case fc_EyebrowSpace::Joint: return "Joint";
        case fc_EyebrowSpace::Separate: return "Separate";
        default: return "";
    }
}

inline bool from_string(fc_EyebrowSpace& value, const std::string& str) {
    if (str == "Joint") { value = fc_EyebrowSpace::Joint; return true; }
    if (str == "Separate") { value = fc_EyebrowSpace::Separate; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_EyebrowSpace
template<>
struct xml_convert::XmlValueAdapter<fc_EyebrowSpace> {
    static bool from_xml_val(fc_EyebrowSpace& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_EyebrowSpace& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_EyebrowSpace
template<>
struct xml_convert::XmlAttributeAdapter<fc_EyebrowSpace> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_EyebrowSpace& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_EyebrowSpace& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Eyebrow 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanface
// 源文件: humanface_v20.xsd
struct fc_Eyebrow {
    /*
     * Describe the shape of the eyebrow, Short usually means that the width of eye brow is shorter than the length of eye.
     * Long usually means that the width of eye brow is equal to or longer than the length of eye.acceptable values are defined in fc:EyebrowWidth.
     */
    std::optional<std::string> Width;
    // Describe the Color of the eyebrow.
    std::optional<tt_ColorDescriptor> Color;
    // Describe the space of two eyebrows, acceptable values are defined in fc:EyebrowSpace.
    std::optional<std::string> Space;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for fc_Eyebrow
template<>
struct xml_convert::XmlTraits<fc_Eyebrow> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Width", &fc_Eyebrow::Width, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &fc_Eyebrow::Color, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Space", &fc_Eyebrow::Space, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &fc_Eyebrow::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &fc_Eyebrow::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// EyeShape 枚举类型
// 基础类型: std::string
enum class  fc_EyeShape {
    Almond,
    Round,
    Other
};

// 字符串转换函数
inline std::string to_string(fc_EyeShape value) {
    switch (value) {
        case fc_EyeShape::Almond: return "Almond";
        case fc_EyeShape::Round: return "Round";
        case fc_EyeShape::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(fc_EyeShape& value, const std::string& str) {
    if (str == "Almond") { value = fc_EyeShape::Almond; return true; }
    if (str == "Round") { value = fc_EyeShape::Round; return true; }
    if (str == "Other") { value = fc_EyeShape::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_EyeShape
template<>
struct xml_convert::XmlValueAdapter<fc_EyeShape> {
    static bool from_xml_val(fc_EyeShape& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_EyeShape& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_EyeShape
template<>
struct xml_convert::XmlAttributeAdapter<fc_EyeShape> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_EyeShape& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_EyeShape& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Eyelid 枚举类型
// 基础类型: std::string
enum class  fc_Eyelid {
    Single,
    Double,
    Other
};

// 字符串转换函数
inline std::string to_string(fc_Eyelid value) {
    switch (value) {
        case fc_Eyelid::Single: return "Single";
        case fc_Eyelid::Double: return "Double";
        case fc_Eyelid::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(fc_Eyelid& value, const std::string& str) {
    if (str == "Single") { value = fc_Eyelid::Single; return true; }
    if (str == "Double") { value = fc_Eyelid::Double; return true; }
    if (str == "Other") { value = fc_Eyelid::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_Eyelid
template<>
struct xml_convert::XmlValueAdapter<fc_Eyelid> {
    static bool from_xml_val(fc_Eyelid& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_Eyelid& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_Eyelid
template<>
struct xml_convert::XmlAttributeAdapter<fc_Eyelid> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_Eyelid& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_Eyelid& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Eyeball 枚举类型
// 基础类型: std::string
enum class  fc_Eyeball {
    Black,
    Blue,
    Brown,
    Gray,
    Green,
    Pink,
    Other
};

// 字符串转换函数
inline std::string to_string(fc_Eyeball value) {
    switch (value) {
        case fc_Eyeball::Black: return "Black";
        case fc_Eyeball::Blue: return "Blue";
        case fc_Eyeball::Brown: return "Brown";
        case fc_Eyeball::Gray: return "Gray";
        case fc_Eyeball::Green: return "Green";
        case fc_Eyeball::Pink: return "Pink";
        case fc_Eyeball::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(fc_Eyeball& value, const std::string& str) {
    if (str == "Black") { value = fc_Eyeball::Black; return true; }
    if (str == "Blue") { value = fc_Eyeball::Blue; return true; }
    if (str == "Brown") { value = fc_Eyeball::Brown; return true; }
    if (str == "Gray") { value = fc_Eyeball::Gray; return true; }
    if (str == "Green") { value = fc_Eyeball::Green; return true; }
    if (str == "Pink") { value = fc_Eyeball::Pink; return true; }
    if (str == "Other") { value = fc_Eyeball::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_Eyeball
template<>
struct xml_convert::XmlValueAdapter<fc_Eyeball> {
    static bool from_xml_val(fc_Eyeball& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_Eyeball& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_Eyeball
template<>
struct xml_convert::XmlAttributeAdapter<fc_Eyeball> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_Eyeball& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_Eyeball& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Eye 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanface
// 源文件: humanface_v20.xsd
struct fc_Eye {
    // Describe the shape of the eye, acceptable values are defined in fc:EyeShape.
    std::optional<std::string> Shape;
    // Describe the eyelid of the eye, acceptable values are defined in fc:Eyelid.
    std::optional<std::string> Eyelid;
    // Describe the eyeball of the eye, acceptable values are defined in fc:Eyeball.
    std::optional<std::string> Eyeball;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for fc_Eye
template<>
struct xml_convert::XmlTraits<fc_Eye> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Shape", &fc_Eye::Shape, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Eyelid", &fc_Eye::Eyelid, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Eyeball", &fc_Eye::Eyeball, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &fc_Eye::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &fc_Eye::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// EarShape 枚举类型
// 基础类型: std::string
enum class  fc_EarShape {
    Round,
    Pointed,
    Narrow,
    BroadLobe,
    Other
};

// 字符串转换函数
inline std::string to_string(fc_EarShape value) {
    switch (value) {
        case fc_EarShape::Round: return "Round";
        case fc_EarShape::Pointed: return "Pointed";
        case fc_EarShape::Narrow: return "Narrow";
        case fc_EarShape::BroadLobe: return "BroadLobe";
        case fc_EarShape::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(fc_EarShape& value, const std::string& str) {
    if (str == "Round") { value = fc_EarShape::Round; return true; }
    if (str == "Pointed") { value = fc_EarShape::Pointed; return true; }
    if (str == "Narrow") { value = fc_EarShape::Narrow; return true; }
    if (str == "BroadLobe") { value = fc_EarShape::BroadLobe; return true; }
    if (str == "Other") { value = fc_EarShape::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_EarShape
template<>
struct xml_convert::XmlValueAdapter<fc_EarShape> {
    static bool from_xml_val(fc_EarShape& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_EarShape& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_EarShape
template<>
struct xml_convert::XmlAttributeAdapter<fc_EarShape> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_EarShape& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_EarShape& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// NoseLength 枚举类型
// 基础类型: std::string
enum class  fc_NoseLength {
    Short,
    Long
};

// 字符串转换函数
inline std::string to_string(fc_NoseLength value) {
    switch (value) {
        case fc_NoseLength::Short: return "Short";
        case fc_NoseLength::Long: return "Long";
        default: return "";
    }
}

inline bool from_string(fc_NoseLength& value, const std::string& str) {
    if (str == "Short") { value = fc_NoseLength::Short; return true; }
    if (str == "Long") { value = fc_NoseLength::Long; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_NoseLength
template<>
struct xml_convert::XmlValueAdapter<fc_NoseLength> {
    static bool from_xml_val(fc_NoseLength& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_NoseLength& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_NoseLength
template<>
struct xml_convert::XmlAttributeAdapter<fc_NoseLength> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_NoseLength& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_NoseLength& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// NoseBridge 枚举类型
// 基础类型: std::string
enum class  fc_NoseBridge {
    Straight,
    Arch
};

// 字符串转换函数
inline std::string to_string(fc_NoseBridge value) {
    switch (value) {
        case fc_NoseBridge::Straight: return "Straight";
        case fc_NoseBridge::Arch: return "Arch";
        default: return "";
    }
}

inline bool from_string(fc_NoseBridge& value, const std::string& str) {
    if (str == "Straight") { value = fc_NoseBridge::Straight; return true; }
    if (str == "Arch") { value = fc_NoseBridge::Arch; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_NoseBridge
template<>
struct xml_convert::XmlValueAdapter<fc_NoseBridge> {
    static bool from_xml_val(fc_NoseBridge& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_NoseBridge& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_NoseBridge
template<>
struct xml_convert::XmlAttributeAdapter<fc_NoseBridge> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_NoseBridge& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_NoseBridge& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// NoseWing 枚举类型
// 基础类型: std::string
enum class  fc_NoseWing {
    Narrow,
    Broad
};

// 字符串转换函数
inline std::string to_string(fc_NoseWing value) {
    switch (value) {
        case fc_NoseWing::Narrow: return "Narrow";
        case fc_NoseWing::Broad: return "Broad";
        default: return "";
    }
}

inline bool from_string(fc_NoseWing& value, const std::string& str) {
    if (str == "Narrow") { value = fc_NoseWing::Narrow; return true; }
    if (str == "Broad") { value = fc_NoseWing::Broad; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_NoseWing
template<>
struct xml_convert::XmlValueAdapter<fc_NoseWing> {
    static bool from_xml_val(fc_NoseWing& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_NoseWing& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_NoseWing
template<>
struct xml_convert::XmlAttributeAdapter<fc_NoseWing> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_NoseWing& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_NoseWing& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// NoseEnd 枚举类型
// 基础类型: std::string
enum class  fc_NoseEnd {
    Snub,
    Turnedup,
    Flat,
    Hooked,
    Other
};

// 字符串转换函数
inline std::string to_string(fc_NoseEnd value) {
    switch (value) {
        case fc_NoseEnd::Snub: return "Snub";
        case fc_NoseEnd::Turnedup: return "Turnedup";
        case fc_NoseEnd::Flat: return "Flat";
        case fc_NoseEnd::Hooked: return "Hooked";
        case fc_NoseEnd::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(fc_NoseEnd& value, const std::string& str) {
    if (str == "Snub") { value = fc_NoseEnd::Snub; return true; }
    if (str == "Turnedup") { value = fc_NoseEnd::Turnedup; return true; }
    if (str == "Flat") { value = fc_NoseEnd::Flat; return true; }
    if (str == "Hooked") { value = fc_NoseEnd::Hooked; return true; }
    if (str == "Other") { value = fc_NoseEnd::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_NoseEnd
template<>
struct xml_convert::XmlValueAdapter<fc_NoseEnd> {
    static bool from_xml_val(fc_NoseEnd& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_NoseEnd& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_NoseEnd
template<>
struct xml_convert::XmlAttributeAdapter<fc_NoseEnd> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_NoseEnd& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_NoseEnd& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Nose 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanface
// 源文件: humanface_v20.xsd
struct fc_Nose {
    /*
     * Describe the length of the nose, acceptable values are defined in fc:NoseLength.
     * Long usually means that the length of the nose is longer than 1/3 of the length of the face.
     * short usually means that the length of the nose is shorter than 1/3 of the length of the face.
     */
    std::optional<std::string> Length;
    // Describe the bridge of the nose, acceptable values are defined in fc:NoseBridge.
    std::optional<std::string> NoseBridge;
    // Describe the wing of the nose, acceptable values are defined in fc:NoseWing.
    std::optional<std::string> NoseWing;
    // Describe the end of the nose, acceptable values are defined in fc:NoseEnd.
    std::optional<std::string> NoseEnd;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for fc_Nose
template<>
struct xml_convert::XmlTraits<fc_Nose> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Length", &fc_Nose::Length, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NoseBridge", &fc_Nose::NoseBridge, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NoseWing", &fc_Nose::NoseWing, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NoseEnd", &fc_Nose::NoseEnd, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &fc_Nose::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &fc_Nose::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// FacialHair 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanface
// 源文件: humanface_v20.xsd
struct fc_FacialHair {
    // Describe if there is mustache on the face.
    std::optional<bool> Mustache;
    // Describe if there are Beard on the face.
    std::optional<bool> Beard;
    // Describe if there are sideburns on the face.
    std::optional<bool> Sideburn;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for fc_FacialHair
template<>
struct xml_convert::XmlTraits<fc_FacialHair> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mustache", &fc_FacialHair::Mustache, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Beard", &fc_FacialHair::Beard, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Sideburn", &fc_FacialHair::Sideburn, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &fc_FacialHair::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &fc_FacialHair::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Lip 枚举类型
// 基础类型: std::string
enum class  fc_Lip {
    Full,
    Medium,
    Thin
};

// 字符串转换函数
inline std::string to_string(fc_Lip value) {
    switch (value) {
        case fc_Lip::Full: return "Full";
        case fc_Lip::Medium: return "Medium";
        case fc_Lip::Thin: return "Thin";
        default: return "";
    }
}

inline bool from_string(fc_Lip& value, const std::string& str) {
    if (str == "Full") { value = fc_Lip::Full; return true; }
    if (str == "Medium") { value = fc_Lip::Medium; return true; }
    if (str == "Thin") { value = fc_Lip::Thin; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_Lip
template<>
struct xml_convert::XmlValueAdapter<fc_Lip> {
    static bool from_xml_val(fc_Lip& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_Lip& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_Lip
template<>
struct xml_convert::XmlAttributeAdapter<fc_Lip> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_Lip& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_Lip& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Chin 枚举类型
// 基础类型: std::string
enum class  fc_Chin {
    Double,
    Pointed,
    Round
};

// 字符串转换函数
inline std::string to_string(fc_Chin value) {
    switch (value) {
        case fc_Chin::Double: return "Double";
        case fc_Chin::Pointed: return "Pointed";
        case fc_Chin::Round: return "Round";
        default: return "";
    }
}

inline bool from_string(fc_Chin& value, const std::string& str) {
    if (str == "Double") { value = fc_Chin::Double; return true; }
    if (str == "Pointed") { value = fc_Chin::Pointed; return true; }
    if (str == "Round") { value = fc_Chin::Round; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_Chin
template<>
struct xml_convert::XmlValueAdapter<fc_Chin> {
    static bool from_xml_val(fc_Chin& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_Chin& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_Chin
template<>
struct xml_convert::XmlAttributeAdapter<fc_Chin> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_Chin& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_Chin& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Expression 枚举类型
// 基础类型: std::string
enum class  fc_Expression {
    Natural,
    Smile,
    RaisedEyebrows,
    Squint,
    Frown,
    Other
};

// 字符串转换函数
inline std::string to_string(fc_Expression value) {
    switch (value) {
        case fc_Expression::Natural: return "Natural";
        case fc_Expression::Smile: return "Smile";
        case fc_Expression::RaisedEyebrows: return "RaisedEyebrows";
        case fc_Expression::Squint: return "Squint";
        case fc_Expression::Frown: return "Frown";
        case fc_Expression::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(fc_Expression& value, const std::string& str) {
    if (str == "Natural") { value = fc_Expression::Natural; return true; }
    if (str == "Smile") { value = fc_Expression::Smile; return true; }
    if (str == "RaisedEyebrows") { value = fc_Expression::RaisedEyebrows; return true; }
    if (str == "Squint") { value = fc_Expression::Squint; return true; }
    if (str == "Frown") { value = fc_Expression::Frown; return true; }
    if (str == "Other") { value = fc_Expression::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_Expression
template<>
struct xml_convert::XmlValueAdapter<fc_Expression> {
    static bool from_xml_val(fc_Expression& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_Expression& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_Expression
template<>
struct xml_convert::XmlAttributeAdapter<fc_Expression> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_Expression& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_Expression& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// HatType 枚举类型
// 基础类型: std::string
enum class  fc_HatType {
    Cap
};

// 字符串转换函数
inline std::string to_string(fc_HatType value) {
    switch (value) {
        case fc_HatType::Cap: return "Cap";
        default: return "";
    }
}

inline bool from_string(fc_HatType& value, const std::string& str) {
    if (str == "Cap") { value = fc_HatType::Cap; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_HatType
template<>
struct xml_convert::XmlValueAdapter<fc_HatType> {
    static bool from_xml_val(fc_HatType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_HatType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_HatType
template<>
struct xml_convert::XmlAttributeAdapter<fc_HatType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_HatType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_HatType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// HelmetType 枚举类型
// 基础类型: std::string
enum class  fc_HelmetType {
    ConstructionCap,
    CycleCap,
    RidingHat
};

// 字符串转换函数
inline std::string to_string(fc_HelmetType value) {
    switch (value) {
        case fc_HelmetType::ConstructionCap: return "ConstructionCap";
        case fc_HelmetType::CycleCap: return "CycleCap";
        case fc_HelmetType::RidingHat: return "RidingHat";
        default: return "";
    }
}

inline bool from_string(fc_HelmetType& value, const std::string& str) {
    if (str == "ConstructionCap") { value = fc_HelmetType::ConstructionCap; return true; }
    if (str == "CycleCap") { value = fc_HelmetType::CycleCap; return true; }
    if (str == "RidingHat") { value = fc_HelmetType::RidingHat; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_HelmetType
template<>
struct xml_convert::XmlValueAdapter<fc_HelmetType> {
    static bool from_xml_val(fc_HelmetType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_HelmetType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_HelmetType
template<>
struct xml_convert::XmlAttributeAdapter<fc_HelmetType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_HelmetType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_HelmetType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// PoseAngle 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanface
// 源文件: humanface_v20.xsd
struct fc_PoseAngle {
    // Describe the pose angle of the face.
    std::optional<tt_GeoOrientation> PoseAngles;
    // Describe the expected degree of uncertainty of the pose angle yaw, pitch, and roll.
    std::optional<tt_GeoOrientation> Uncertainty;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for fc_PoseAngle
template<>
struct xml_convert::XmlTraits<fc_PoseAngle> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PoseAngles", &fc_PoseAngle::PoseAngles, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Uncertainty", &fc_PoseAngle::Uncertainty, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &fc_PoseAngle::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &fc_PoseAngle::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AccessoryDescription 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanface
// 源文件: humanface_v20.xsd
struct fc_AccessoryDescription {
    // Describe if the object wear a accessory .
    std::optional<bool> Wear;
    // Describe the Color of the accessory.
    std::optional<tt_ColorDescriptor> Color;
    /*
     * Optional subtype of the accessory. For definitions refer enumerations starting with
     * the accessory name followed by 'Type' like fc:HatType or fc:HelmetType.
     */
    std::optional<std::string> Subtype;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for fc_AccessoryDescription
template<>
struct xml_convert::XmlTraits<fc_AccessoryDescription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Wear", &fc_AccessoryDescription::Wear, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Color", &fc_AccessoryDescription::Color, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Subtype", &fc_AccessoryDescription::Subtype, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &fc_AccessoryDescription::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &fc_AccessoryDescription::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Accessory 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanface
// 源文件: humanface_v20.xsd
struct fc_Accessory {
    // Describe if the object wear opticals.
    std::optional<fc_AccessoryDescription> Opticals;
    // Describe if the object wear hat.
    std::optional<fc_AccessoryDescription> Hat;
    // Describe if the object wear mask.
    std::optional<fc_AccessoryDescription> Mask;
    // Describe if the object wear hijab.
    std::optional<fc_AccessoryDescription> Hijab;
    // Describe if the object wear Helmet.
    std::optional<fc_AccessoryDescription> Helmet;
    // Describe if the object wear Kerchief.
    std::optional<fc_AccessoryDescription> Kerchief;
    // Describe if there is a patch on the right eye.
    std::optional<fc_AccessoryDescription> RightEyePatch;
    // Describe if there is a patch on the left eye.
    std::optional<fc_AccessoryDescription> LeftEyePatch;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for fc_Accessory
template<>
struct xml_convert::XmlTraits<fc_Accessory> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Opticals", &fc_Accessory::Opticals, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Hat", &fc_Accessory::Hat, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mask", &fc_Accessory::Mask, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Hijab", &fc_Accessory::Hijab, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Helmet", &fc_Accessory::Helmet, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Kerchief", &fc_Accessory::Kerchief, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RightEyePatch", &fc_Accessory::RightEyePatch, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("LeftEyePatch", &fc_Accessory::LeftEyePatch, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &fc_Accessory::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &fc_Accessory::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// FrecklesType 枚举类型
// 基础类型: std::string
enum class  fc_FrecklesType {
    AroundCheek,
    Nose,
    forehead,
    Other
};

// 字符串转换函数
inline std::string to_string(fc_FrecklesType value) {
    switch (value) {
        case fc_FrecklesType::AroundCheek: return "AroundCheek";
        case fc_FrecklesType::Nose: return "Nose";
        case fc_FrecklesType::forehead: return "forehead";
        case fc_FrecklesType::Other: return "Other";
        default: return "";
    }
}

inline bool from_string(fc_FrecklesType& value, const std::string& str) {
    if (str == "AroundCheek") { value = fc_FrecklesType::AroundCheek; return true; }
    if (str == "Nose") { value = fc_FrecklesType::Nose; return true; }
    if (str == "forehead") { value = fc_FrecklesType::forehead; return true; }
    if (str == "Other") { value = fc_FrecklesType::Other; return true; }
    return false;
}


// XmlValueAdapter specialization for enum fc_FrecklesType
template<>
struct xml_convert::XmlValueAdapter<fc_FrecklesType> {
    static bool from_xml_val(fc_FrecklesType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const fc_FrecklesType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum fc_FrecklesType
template<>
struct xml_convert::XmlAttributeAdapter<fc_FrecklesType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const fc_FrecklesType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(fc_FrecklesType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// AdditionalFeatures 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanface
// 源文件: humanface_v20.xsd
struct fc_AdditionalFeatures {
    // Is there scar on the face.
    std::optional<bool> Scar;
    // Is there mole on the face.
    std::optional<bool> Mole;
    // Is there Tattoo on the face.
    std::optional<bool> Tattoo;
    // Describe freckles on the face, acceptable values are defined in fc:FrecklesType.
    std::optional<std::string> Freckles;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for fc_AdditionalFeatures
template<>
struct xml_convert::XmlTraits<fc_AdditionalFeatures> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Scar", &fc_AdditionalFeatures::Scar, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mole", &fc_AdditionalFeatures::Mole, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Tattoo", &fc_AdditionalFeatures::Tattoo, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Freckles", &fc_AdditionalFeatures::Freckles, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &fc_AdditionalFeatures::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &fc_AdditionalFeatures::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// HumanFace 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/humanface
// 源文件: humanface_v20.xsd
struct fc_HumanFace {
    // Describe the age of the face.
    std::optional<tt_IntRange> Age;
    // Describe the gender of the face, acceptable values are defined in fc:Gender.
    std::optional<std::string> Gender;
    // Describe the temperature of the face, in Kelvin.
    std::optional<float> Temperature;
    // Describe the complexion of the face, acceptable values are defined in fc:Complexion.
    std::optional<std::string> Complexion;
    // Describe the FacialShape, acceptable values are defined fc:FacialShape.
    std::optional<std::string> FacialShape;
    // Describe the hair of the face.
    std::optional<fc_Hair> Hair;
    // Describe the eyebrow of the face.
    std::optional<fc_Eyebrow> Eyebrow;
    // Describe the eye of the face.
    std::optional<fc_Eye> Eye;
    // Describe the Ear of the face. For definitions see fc:EarShape.
    std::optional<std::string> Ear;
    // Describe the nose of the face.
    std::optional<fc_Nose> Nose;
    // Describe the facial hair of the face.
    std::optional<fc_FacialHair> FacialHair;
    // Describe the lip of the face, acceptable values are defined in fc:Lip.
    std::optional<std::string> Lip;
    // Describe the Chin of the face, acceptable values are defined in fc:Chin.
    std::optional<std::string> Chin;
    // Describe the expression on the face, acceptable values are defined in fc:Expression.
    std::optional<std::string> Expression;
    // Describe the pose angle of the face.
    std::optional<fc_PoseAngle> PoseAngle;
    // Describe the Accessory of the face.
    std::optional<fc_Accessory> Accessory;
    // Describe the other features, eg scar, mole etc of the face.
    std::optional<fc_AdditionalFeatures> AdditionalFeatures;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for fc_HumanFace
template<>
struct xml_convert::XmlTraits<fc_HumanFace> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Age", &fc_HumanFace::Age, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Gender", &fc_HumanFace::Gender, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Temperature", &fc_HumanFace::Temperature, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Complexion", &fc_HumanFace::Complexion, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FacialShape", &fc_HumanFace::FacialShape, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Hair", &fc_HumanFace::Hair, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Eyebrow", &fc_HumanFace::Eyebrow, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Eye", &fc_HumanFace::Eye, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Ear", &fc_HumanFace::Ear, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Nose", &fc_HumanFace::Nose, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FacialHair", &fc_HumanFace::FacialHair, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Lip", &fc_HumanFace::Lip, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Chin", &fc_HumanFace::Chin, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Expression", &fc_HumanFace::Expression, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PoseAngle", &fc_HumanFace::PoseAngle, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Accessory", &fc_HumanFace::Accessory, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AdditionalFeatures", &fc_HumanFace::AdditionalFeatures, "fc", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &fc_HumanFace::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &fc_HumanFace::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


} // namespace libonvif_client
