/**
 * @file tt.h
 * @brief 从 onvif_v10.xsd 生成的类型定义
 * @namespace http://www.onvif.org/ver10/schema
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 * @comment ONVIF核心Schema - 分离生成以避免循环依赖
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/common.h>
#include <libonvif_client/types/soap.h>
#include <libonvif_client/types/wsnt.h>
#include <libonvif_client/types/xmime.h>
#include <libonvif_client/types/xop.h>

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
struct tt_NetworkZeroConfiguration;
struct tt_Transport;

// DeviceEntity 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DeviceEntity {
    // Unique identifier referencing the physical entity.
    tt_ReferenceToken token;
};


// XmlTraits for tt_DeviceEntity
template<>
struct xml_convert::XmlTraits<tt_DeviceEntity> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("token", &tt_DeviceEntity::token, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Name 类型别名
// 基础类型: std::string
using tt_Name = std::string;


// IntRectangle 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IntRectangle {
    int32_t x {};
    int32_t y {};
    int32_t width {};
    int32_t height {};
};


// XmlTraits for tt_IntRectangle
template<>
struct xml_convert::XmlTraits<tt_IntRectangle> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("x", &tt_IntRectangle::x, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("y", &tt_IntRectangle::y, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("width", &tt_IntRectangle::width, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("height", &tt_IntRectangle::height, nullptr, xml_convert::serialize_type::attribute)
    );
};


// IntRectangleRange 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IntRectangleRange {
    // Range of X-axis.
    tt_IntRange XRange;
    // Range of Y-axis.
    tt_IntRange YRange;
    // Range of width.
    tt_IntRange WidthRange;
    // Range of height.
    tt_IntRange HeightRange;
};


// XmlTraits for tt_IntRectangleRange
template<>
struct xml_convert::XmlTraits<tt_IntRectangleRange> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XRange", &tt_IntRectangleRange::XRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("YRange", &tt_IntRectangleRange::YRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WidthRange", &tt_IntRectangleRange::WidthRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("HeightRange", &tt_IntRectangleRange::HeightRange, "tt", xml_convert::serialize_type::full)
    );
};


// FloatRange 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FloatRange {
    float Min {};
    float Max {};
};


// XmlTraits for tt_FloatRange
template<>
struct xml_convert::XmlTraits<tt_FloatRange> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Min", &tt_FloatRange::Min, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Max", &tt_FloatRange::Max, "tt", xml_convert::serialize_type::full)
    );
};


// DurationRange 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DurationRange {
    my_Duration Min;
    my_Duration Max;
};


// XmlTraits for tt_DurationRange
template<>
struct xml_convert::XmlTraits<tt_DurationRange> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Min", &tt_DurationRange::Min, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Max", &tt_DurationRange::Max, "tt", xml_convert::serialize_type::full)
    );
};


// IntItems 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IntItems {
    std::vector<int32_t> Items;
};


// XmlTraits for tt_IntItems
template<>
struct xml_convert::XmlTraits<tt_IntItems> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Items", &tt_IntItems::Items, "tt", xml_convert::serialize_type::full)
    );
};


// IntList 列表类型别名
// 元素类型: int32_t
using tt_IntList = std::vector<int32_t>;


// XmlValueAdapter specialization for list tt_IntList
template<>
struct xml_convert::XmlValueAdapter<tt_IntList> {
    static bool from_xml_val(tt_IntList& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        xmlNodePtr targetElement = name ? 
            xmlGetChildElementByName(element, name) : element;
        if (!targetElement) return false;
        val.clear();  // 直接操作vector，不再是val.value
        xmlChar* content = xmlNodeGetContent(targetElement);
        if (!content) return true;
        std::string str_val(reinterpret_cast<char*>(content));
        xmlFree(content);
        std::istringstream iss(str_val);
        std::string item;
        while (iss >> item) {
            try {
                val.push_back(std::stoll(item));
            } catch (...) { return false; }
        }
        return true;
    }
    
    static bool to_xml_val(const tt_IntList& val, xmlNodePtr parent, const char* name,
                           const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;
        xmlNodePtr element = create_element_with_ns(parent, name, ns_prefix, namespaces);
        if (!element) return false;
        std::ostringstream oss;
        for (size_t i = 0; i < val.size(); ++i) {
            if (i > 0) oss << " ";
            oss << std::to_string(val[i]);
        }
        xmlNodeSetContent(element, BAD_CAST oss.str().c_str());
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
// XmlAttributeAdapter specialization for list tt_IntList
template<>
struct xml_convert::XmlAttributeAdapter<tt_IntList> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_IntList& value) {
        bool is_first = false; std::ostringstream oss; 
        for (const auto& item : value) {
            if(!is_first) oss << " ";
                is_first = true;
                oss << item;
        }
        return xml_convert::XmlAttributeAdapter<std::string>::to_attribute(element, name, oss.str());
    }
    static bool from_attribute(tt_IntList& val, xmlNodePtr element, const char* name) {
        std::string str_val;
        if (!xml_convert::XmlAttributeAdapter<std::string>::from_attribute(str_val, element, name)) return false;
        val.clear();  // 直接操作vector
        size_t pos = 0, start = 0;
        while(pos < str_val.size()) {
            if (str_val[pos] == ' ') {
                std::string_view sub(str_val.data() + start, pos - start);
                start = pos + 1;
                val.push_back(std::stoll(sub.data()));
            }
            pos++;
        }
        return true;
    }
};


// FloatList 列表类型别名
// 元素类型: float
using tt_FloatList = std::vector<float>;


// XmlValueAdapter specialization for list tt_FloatList
template<>
struct xml_convert::XmlValueAdapter<tt_FloatList> {
    static bool from_xml_val(tt_FloatList& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        xmlNodePtr targetElement = name ? 
            xmlGetChildElementByName(element, name) : element;
        if (!targetElement) return false;
        val.clear();  // 直接操作vector，不再是val.value
        xmlChar* content = xmlNodeGetContent(targetElement);
        if (!content) return true;
        std::string str_val(reinterpret_cast<char*>(content));
        xmlFree(content);
        std::istringstream iss(str_val);
        std::string item;
        while (iss >> item) {
            try {
                val.push_back(std::stod(item));
            } catch (...) { return false; }
        }
        return true;
    }
    
    static bool to_xml_val(const tt_FloatList& val, xmlNodePtr parent, const char* name,
                           const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;
        xmlNodePtr element = create_element_with_ns(parent, name, ns_prefix, namespaces);
        if (!element) return false;
        std::ostringstream oss;
        for (size_t i = 0; i < val.size(); ++i) {
            if (i > 0) oss << " ";
            oss << std::to_string(val[i]);
        }
        xmlNodeSetContent(element, BAD_CAST oss.str().c_str());
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
// XmlAttributeAdapter specialization for list tt_FloatList
template<>
struct xml_convert::XmlAttributeAdapter<tt_FloatList> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_FloatList& value) {
        bool is_first = false; std::ostringstream oss; 
        for (const auto& item : value) {
            if(!is_first) oss << " ";
                is_first = true;
                oss << item;
        }
        return xml_convert::XmlAttributeAdapter<std::string>::to_attribute(element, name, oss.str());
    }
    static bool from_attribute(tt_FloatList& val, xmlNodePtr element, const char* name) {
        std::string str_val;
        if (!xml_convert::XmlAttributeAdapter<std::string>::from_attribute(str_val, element, name)) return false;
        val.clear();  // 直接操作vector
        size_t pos = 0, start = 0;
        while(pos < str_val.size()) {
            if (str_val[pos] == ' ') {
                std::string_view sub(str_val.data() + start, pos - start);
                start = pos + 1;
                val.push_back(std::stod(sub.data()));
            }
            pos++;
        }
        return true;
    }
};


// StringAttrList 列表类型别名
// 元素类型: std::string
using tt_StringAttrList = std::vector<std::string>;


// XmlValueAdapter specialization for list tt_StringAttrList
template<>
struct xml_convert::XmlValueAdapter<tt_StringAttrList> {
    static bool from_xml_val(tt_StringAttrList& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        xmlNodePtr targetElement = name ? 
            xmlGetChildElementByName(element, name) : element;
        if (!targetElement) return false;
        val.clear();  // 直接操作vector，不再是val.value
        xmlChar* content = xmlNodeGetContent(targetElement);
        if (!content) return true;
        std::string str_val(reinterpret_cast<char*>(content));
        xmlFree(content);
        std::istringstream iss(str_val);
        std::string item;
        while (iss >> item) {
            val.push_back(item);
        }
        return true;
    }
    
    static bool to_xml_val(const tt_StringAttrList& val, xmlNodePtr parent, const char* name,
                           const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;
        xmlNodePtr element = create_element_with_ns(parent, name, ns_prefix, namespaces);
        if (!element) return false;
        std::ostringstream oss;
        for (size_t i = 0; i < val.size(); ++i) {
            if (i > 0) oss << " ";
            oss << val[i];
        }
        xmlNodeSetContent(element, BAD_CAST oss.str().c_str());
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
// XmlAttributeAdapter specialization for list tt_StringAttrList
template<>
struct xml_convert::XmlAttributeAdapter<tt_StringAttrList> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_StringAttrList& value) {
        bool is_first = false; std::ostringstream oss; 
        for (const auto& item : value) {
            if(!is_first) oss << " ";
                is_first = true;
                oss << item;
        }
        return xml_convert::XmlAttributeAdapter<std::string>::to_attribute(element, name, oss.str());
    }
    static bool from_attribute(tt_StringAttrList& val, xmlNodePtr element, const char* name) {
        std::string str_val;
        if (!xml_convert::XmlAttributeAdapter<std::string>::from_attribute(str_val, element, name)) return false;
        val.clear();  // 直接操作vector
        size_t pos = 0, start = 0;
        while(pos < str_val.size()) {
            if (str_val[pos] == ' ') {
                std::string_view sub(str_val.data() + start, pos - start);
                start = pos + 1;
                val.push_back(std::string(std::string(sub)));
            }
            pos++;
        }
        return true;
    }
};


// StringList 列表类型别名（与 tt_StringAttrList 相同）
// 元素类型: std::string
using tt_StringList = tt_StringAttrList;

// Note: tt_StringList shares XmlValueAdapter with tt_StringAttrList

// ReferenceTokenList 列表类型别名
// 元素类型: tt_ReferenceToken
using tt_ReferenceTokenList = std::vector<tt_ReferenceToken>;


// Note: tt_ReferenceTokenList uses generic std::vector adapter (element type is complex)

// FloatItems 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FloatItems {
    std::vector<float> Items;
};


// XmlTraits for tt_FloatItems
template<>
struct xml_convert::XmlTraits<tt_FloatItems> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Items", &tt_FloatItems::Items, "tt", xml_convert::serialize_type::full)
    );
};


// StringItems 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_StringItems {
    std::vector<std::string> Item;
};


// XmlTraits for tt_StringItems
template<>
struct xml_convert::XmlTraits<tt_StringItems> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Item", &tt_StringItems::Item, "tt", xml_convert::serialize_type::full)
    );
};


// AnyHolder 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnyHolder {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnyHolder
template<>
struct xml_convert::XmlTraits<tt_AnyHolder> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AnyHolder::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AnyHolder::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoResolution 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoResolution {
    // Number of the columns of the Video image. If there is a 90-degree rotation, this represents the number of lines of the Video image.
    int32_t Width {};
    // Number of the lines of the Video image. If there is a 90-degree rotation, this represents the number of columns of the Video image.
    int32_t Height {};
};


// XmlTraits for tt_VideoResolution
template<>
struct xml_convert::XmlTraits<tt_VideoResolution> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Width", &tt_VideoResolution::Width, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Height", &tt_VideoResolution::Height, "tt", xml_convert::serialize_type::full)
    );
};


// BacklightCompensationMode 枚举类型
// 基础类型: std::string
enum class  tt_BacklightCompensationMode {
    OFF,
    ON
};

// 字符串转换函数
inline std::string to_string(tt_BacklightCompensationMode value) {
    switch (value) {
        case tt_BacklightCompensationMode::OFF: return "OFF";
        case tt_BacklightCompensationMode::ON: return "ON";
        default: return "";
    }
}

inline bool from_string(tt_BacklightCompensationMode& value, const std::string& str) {
    if (str == "OFF") { value = tt_BacklightCompensationMode::OFF; return true; }
    if (str == "ON") { value = tt_BacklightCompensationMode::ON; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_BacklightCompensationMode
template<>
struct xml_convert::XmlValueAdapter<tt_BacklightCompensationMode> {
    static bool from_xml_val(tt_BacklightCompensationMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_BacklightCompensationMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_BacklightCompensationMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_BacklightCompensationMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_BacklightCompensationMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_BacklightCompensationMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// BacklightCompensation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_BacklightCompensation {
    // Backlight compensation mode (on/off).
    tt_BacklightCompensationMode Mode;
    // Optional level parameter (unit unspecified).
    float Level {};
};


// XmlTraits for tt_BacklightCompensation
template<>
struct xml_convert::XmlTraits<tt_BacklightCompensation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_BacklightCompensation::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_BacklightCompensation::Level, "tt", xml_convert::serialize_type::full)
    );
};


// ExposureMode 枚举类型
// 基础类型: std::string
enum class  tt_ExposureMode {
    AUTO,
    MANUAL
};

// 字符串转换函数
inline std::string to_string(tt_ExposureMode value) {
    switch (value) {
        case tt_ExposureMode::AUTO: return "AUTO";
        case tt_ExposureMode::MANUAL: return "MANUAL";
        default: return "";
    }
}

inline bool from_string(tt_ExposureMode& value, const std::string& str) {
    if (str == "AUTO") { value = tt_ExposureMode::AUTO; return true; }
    if (str == "MANUAL") { value = tt_ExposureMode::MANUAL; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ExposureMode
template<>
struct xml_convert::XmlValueAdapter<tt_ExposureMode> {
    static bool from_xml_val(tt_ExposureMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ExposureMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ExposureMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_ExposureMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ExposureMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ExposureMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ExposurePriority 枚举类型
// 基础类型: std::string
enum class  tt_ExposurePriority {
    LowNoise,
    FrameRate
};

// 字符串转换函数
inline std::string to_string(tt_ExposurePriority value) {
    switch (value) {
        case tt_ExposurePriority::LowNoise: return "LowNoise";
        case tt_ExposurePriority::FrameRate: return "FrameRate";
        default: return "";
    }
}

inline bool from_string(tt_ExposurePriority& value, const std::string& str) {
    if (str == "LowNoise") { value = tt_ExposurePriority::LowNoise; return true; }
    if (str == "FrameRate") { value = tt_ExposurePriority::FrameRate; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ExposurePriority
template<>
struct xml_convert::XmlValueAdapter<tt_ExposurePriority> {
    static bool from_xml_val(tt_ExposurePriority& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ExposurePriority& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ExposurePriority
template<>
struct xml_convert::XmlAttributeAdapter<tt_ExposurePriority> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ExposurePriority& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ExposurePriority& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Exposure 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Exposure {
    /*
     * Exposure Mode
     *
     * Auto – Enabled the exposure algorithm on the NVT.
     * Manual – Disabled exposure algorithm on the NVT.
     */
    tt_ExposureMode Mode;
    // The exposure priority mode (low noise/framerate).
    tt_ExposurePriority Priority;
    // Rectangular exposure mask.
    tt_Rectangle Window;
    // Minimum value of exposure time range allowed to be used by the algorithm.
    float MinExposureTime {};
    // Maximum value of exposure time range allowed to be used by the algorithm.
    float MaxExposureTime {};
    // Minimum value of the sensor gain range that is allowed to be used by the algorithm.
    float MinGain {};
    // Maximum value of the sensor gain range that is allowed to be used by the algorithm.
    float MaxGain {};
    // Minimum value of the iris range allowed to be used by the algorithm.
    float MinIris {};
    // Maximum value of the iris range allowed to be used by the algorithm.
    float MaxIris {};
    // The fixed exposure time used by the image sensor (μs).
    float ExposureTime {};
    // The fixed gain used by the image sensor (dB).
    float Gain {};
    // The fixed attenuation of input light affected by the iris (dB). 0dB maps to a fully opened iris.
    float Iris {};
};


// XmlTraits for tt_Exposure
template<>
struct xml_convert::XmlTraits<tt_Exposure> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_Exposure::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Priority", &tt_Exposure::Priority, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Window", &tt_Exposure::Window, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinExposureTime", &tt_Exposure::MinExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxExposureTime", &tt_Exposure::MaxExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinGain", &tt_Exposure::MinGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxGain", &tt_Exposure::MaxGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinIris", &tt_Exposure::MinIris, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxIris", &tt_Exposure::MaxIris, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ExposureTime", &tt_Exposure::ExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Gain", &tt_Exposure::Gain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Iris", &tt_Exposure::Iris, "tt", xml_convert::serialize_type::full)
    );
};


// AutoFocusMode 枚举类型
// 基础类型: std::string
enum class  tt_AutoFocusMode {
    AUTO,
    MANUAL
};

// 字符串转换函数
inline std::string to_string(tt_AutoFocusMode value) {
    switch (value) {
        case tt_AutoFocusMode::AUTO: return "AUTO";
        case tt_AutoFocusMode::MANUAL: return "MANUAL";
        default: return "";
    }
}

inline bool from_string(tt_AutoFocusMode& value, const std::string& str) {
    if (str == "AUTO") { value = tt_AutoFocusMode::AUTO; return true; }
    if (str == "MANUAL") { value = tt_AutoFocusMode::MANUAL; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_AutoFocusMode
template<>
struct xml_convert::XmlValueAdapter<tt_AutoFocusMode> {
    static bool from_xml_val(tt_AutoFocusMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_AutoFocusMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_AutoFocusMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_AutoFocusMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_AutoFocusMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_AutoFocusMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// FocusConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FocusConfiguration {
    tt_AutoFocusMode AutoFocusMode;
    float DefaultSpeed {};
    // Parameter to set autofocus near limit (unit: meter).
    float NearLimit {};
    /*
     * Parameter to set autofocus far limit (unit: meter).
     * If set to 0.0, infinity will be used.
     */
    float FarLimit {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_FocusConfiguration
template<>
struct xml_convert::XmlTraits<tt_FocusConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AutoFocusMode", &tt_FocusConfiguration::AutoFocusMode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultSpeed", &tt_FocusConfiguration::DefaultSpeed, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NearLimit", &tt_FocusConfiguration::NearLimit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FarLimit", &tt_FocusConfiguration::FarLimit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_FocusConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_FocusConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// IrCutFilterMode 枚举类型
// 基础类型: std::string
enum class  tt_IrCutFilterMode {
    ON,
    OFF,
    AUTO
};

// 字符串转换函数
inline std::string to_string(tt_IrCutFilterMode value) {
    switch (value) {
        case tt_IrCutFilterMode::ON: return "ON";
        case tt_IrCutFilterMode::OFF: return "OFF";
        case tt_IrCutFilterMode::AUTO: return "AUTO";
        default: return "";
    }
}

inline bool from_string(tt_IrCutFilterMode& value, const std::string& str) {
    if (str == "ON") { value = tt_IrCutFilterMode::ON; return true; }
    if (str == "OFF") { value = tt_IrCutFilterMode::OFF; return true; }
    if (str == "AUTO") { value = tt_IrCutFilterMode::AUTO; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_IrCutFilterMode
template<>
struct xml_convert::XmlValueAdapter<tt_IrCutFilterMode> {
    static bool from_xml_val(tt_IrCutFilterMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_IrCutFilterMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_IrCutFilterMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_IrCutFilterMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_IrCutFilterMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_IrCutFilterMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// WideDynamicMode 枚举类型
// 基础类型: std::string
enum class  tt_WideDynamicMode {
    OFF,
    ON
};

// 字符串转换函数
inline std::string to_string(tt_WideDynamicMode value) {
    switch (value) {
        case tt_WideDynamicMode::OFF: return "OFF";
        case tt_WideDynamicMode::ON: return "ON";
        default: return "";
    }
}

inline bool from_string(tt_WideDynamicMode& value, const std::string& str) {
    if (str == "OFF") { value = tt_WideDynamicMode::OFF; return true; }
    if (str == "ON") { value = tt_WideDynamicMode::ON; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_WideDynamicMode
template<>
struct xml_convert::XmlValueAdapter<tt_WideDynamicMode> {
    static bool from_xml_val(tt_WideDynamicMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_WideDynamicMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_WideDynamicMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_WideDynamicMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_WideDynamicMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_WideDynamicMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// WideDynamicRange 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_WideDynamicRange {
    // White dynamic range (on/off)
    tt_WideDynamicMode Mode;
    // Optional level parameter (unitless)
    float Level {};
};


// XmlTraits for tt_WideDynamicRange
template<>
struct xml_convert::XmlTraits<tt_WideDynamicRange> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_WideDynamicRange::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_WideDynamicRange::Level, "tt", xml_convert::serialize_type::full)
    );
};


// WhiteBalanceMode 枚举类型
// 基础类型: std::string
enum class  tt_WhiteBalanceMode {
    AUTO,
    MANUAL
};

// 字符串转换函数
inline std::string to_string(tt_WhiteBalanceMode value) {
    switch (value) {
        case tt_WhiteBalanceMode::AUTO: return "AUTO";
        case tt_WhiteBalanceMode::MANUAL: return "MANUAL";
        default: return "";
    }
}

inline bool from_string(tt_WhiteBalanceMode& value, const std::string& str) {
    if (str == "AUTO") { value = tt_WhiteBalanceMode::AUTO; return true; }
    if (str == "MANUAL") { value = tt_WhiteBalanceMode::MANUAL; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_WhiteBalanceMode
template<>
struct xml_convert::XmlValueAdapter<tt_WhiteBalanceMode> {
    static bool from_xml_val(tt_WhiteBalanceMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_WhiteBalanceMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_WhiteBalanceMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_WhiteBalanceMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_WhiteBalanceMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_WhiteBalanceMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// WhiteBalance 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_WhiteBalance {
    // Auto whitebalancing mode (auto/manual).
    tt_WhiteBalanceMode Mode;
    // Rgain (unitless).
    float CrGain {};
    // Bgain (unitless).
    float CbGain {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_WhiteBalance
template<>
struct xml_convert::XmlTraits<tt_WhiteBalance> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_WhiteBalance::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CrGain", &tt_WhiteBalance::CrGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CbGain", &tt_WhiteBalance::CbGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_WhiteBalance::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_WhiteBalance::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ImagingSettingsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingSettingsExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ImagingSettingsExtension
template<>
struct xml_convert::XmlTraits<tt_ImagingSettingsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ImagingSettingsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ImagingSettings 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingSettings {
    // Enabled/disabled BLC mode (on/off).
    std::optional<tt_BacklightCompensation> BacklightCompensation;
    // Image brightness (unit unspecified).
    std::optional<float> Brightness;
    // Color saturation of the image (unit unspecified).
    std::optional<float> ColorSaturation;
    // Contrast of the image (unit unspecified).
    std::optional<float> Contrast;
    // Exposure mode of the device.
    std::optional<tt_Exposure> Exposure;
    // Focus configuration.
    std::optional<tt_FocusConfiguration> Focus;
    // Infrared Cutoff Filter settings.
    std::optional<tt_IrCutFilterMode> IrCutFilter;
    // Sharpness of the Video image.
    std::optional<float> Sharpness;
    // WDR settings.
    std::optional<tt_WideDynamicRange> WideDynamicRange;
    // White balance settings.
    std::optional<tt_WhiteBalance> WhiteBalance;
    std::optional<tt_ImagingSettingsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ImagingSettings
template<>
struct xml_convert::XmlTraits<tt_ImagingSettings> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BacklightCompensation", &tt_ImagingSettings::BacklightCompensation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Brightness", &tt_ImagingSettings::Brightness, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ColorSaturation", &tt_ImagingSettings::ColorSaturation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Contrast", &tt_ImagingSettings::Contrast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Exposure", &tt_ImagingSettings::Exposure, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Focus", &tt_ImagingSettings::Focus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IrCutFilter", &tt_ImagingSettings::IrCutFilter, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Sharpness", &tt_ImagingSettings::Sharpness, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WideDynamicRange", &tt_ImagingSettings::WideDynamicRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WhiteBalance", &tt_ImagingSettings::WhiteBalance, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImagingSettings::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ImagingSettings::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// BacklightCompensation20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_BacklightCompensation20 {
    // Backlight compensation mode (on/off).
    tt_BacklightCompensationMode Mode;
    // Optional level parameter (unit unspecified).
    std::optional<float> Level;
};


// XmlTraits for tt_BacklightCompensation20
template<>
struct xml_convert::XmlTraits<tt_BacklightCompensation20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_BacklightCompensation20::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_BacklightCompensation20::Level, "tt", xml_convert::serialize_type::full)
    );
};


// Exposure20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Exposure20 {
    /*
     * Exposure Mode
     *
     * Auto – Enabled the exposure algorithm on the device.
     * Manual – Disabled exposure algorithm on the device.
     */
    tt_ExposureMode Mode;
    // The exposure priority mode (low noise/framerate).
    std::optional<tt_ExposurePriority> Priority;
    // Rectangular exposure mask.
    std::optional<tt_Rectangle> Window;
    // Minimum value of exposure time range allowed to be used by the algorithm.
    std::optional<float> MinExposureTime;
    // Maximum value of exposure time range allowed to be used by the algorithm.
    std::optional<float> MaxExposureTime;
    // Minimum value of the sensor gain range that is allowed to be used by the algorithm.
    std::optional<float> MinGain;
    // Maximum value of the sensor gain range that is allowed to be used by the algorithm.
    std::optional<float> MaxGain;
    // Minimum value of the iris range allowed to be used by the algorithm.  0dB maps to a fully opened iris and positive values map to higher attenuation.
    std::optional<float> MinIris;
    // Maximum value of the iris range allowed to be used by the algorithm. 0dB maps to a fully opened iris and positive values map to higher attenuation.
    std::optional<float> MaxIris;
    // The fixed exposure time used by the image sensor (μs).
    std::optional<float> ExposureTime;
    // The fixed gain used by the image sensor (dB).
    std::optional<float> Gain;
    // The fixed attenuation of input light affected by the iris (dB). 0dB maps to a fully opened iris and positive values map to higher attenuation.
    std::optional<float> Iris;
};


// XmlTraits for tt_Exposure20
template<>
struct xml_convert::XmlTraits<tt_Exposure20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_Exposure20::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Priority", &tt_Exposure20::Priority, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Window", &tt_Exposure20::Window, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinExposureTime", &tt_Exposure20::MinExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxExposureTime", &tt_Exposure20::MaxExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinGain", &tt_Exposure20::MinGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxGain", &tt_Exposure20::MaxGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinIris", &tt_Exposure20::MinIris, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxIris", &tt_Exposure20::MaxIris, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ExposureTime", &tt_Exposure20::ExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Gain", &tt_Exposure20::Gain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Iris", &tt_Exposure20::Iris, "tt", xml_convert::serialize_type::full)
    );
};


// FocusConfiguration20Extension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FocusConfiguration20Extension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_FocusConfiguration20Extension
template<>
struct xml_convert::XmlTraits<tt_FocusConfiguration20Extension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_FocusConfiguration20Extension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// FocusConfiguration20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FocusConfiguration20 {
    /*
     * Mode of auto focus.
     *
     * AUTO - The device automatically adjusts focus.
     * MANUAL - The device does not automatically adjust focus.
     *
     * Note: for devices supporting both manual and auto operation at the same time manual operation may be supported even if the Mode parameter is set to Auto.
     */
    tt_AutoFocusMode AutoFocusMode;
    std::optional<float> DefaultSpeed;
    // Parameter to set autofocus near limit (unit: meter).
    std::optional<float> NearLimit;
    // Parameter to set autofocus far limit (unit: meter).
    std::optional<float> FarLimit;
    std::optional<tt_FocusConfiguration20Extension> Extension;
    // Zero or more modes as defined in enumeration tt:AFModes.
    std::optional<tt_StringAttrList> AFMode;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_FocusConfiguration20
template<>
struct xml_convert::XmlTraits<tt_FocusConfiguration20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AutoFocusMode", &tt_FocusConfiguration20::AutoFocusMode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultSpeed", &tt_FocusConfiguration20::DefaultSpeed, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NearLimit", &tt_FocusConfiguration20::NearLimit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FarLimit", &tt_FocusConfiguration20::FarLimit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_FocusConfiguration20::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AFMode", &tt_FocusConfiguration20::AFMode, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_FocusConfiguration20::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// WideDynamicRange20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_WideDynamicRange20 {
    // Wide dynamic range mode (on/off).
    tt_WideDynamicMode Mode;
    // Optional level parameter (unit unspecified).
    std::optional<float> Level;
};


// XmlTraits for tt_WideDynamicRange20
template<>
struct xml_convert::XmlTraits<tt_WideDynamicRange20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_WideDynamicRange20::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_WideDynamicRange20::Level, "tt", xml_convert::serialize_type::full)
    );
};


// WhiteBalance20Extension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_WhiteBalance20Extension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_WhiteBalance20Extension
template<>
struct xml_convert::XmlTraits<tt_WhiteBalance20Extension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_WhiteBalance20Extension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// WhiteBalance20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_WhiteBalance20 {
    // 'AUTO' or 'MANUAL'
    tt_WhiteBalanceMode Mode;
    // Rgain (unitless).
    std::optional<float> CrGain;
    // Bgain (unitless).
    std::optional<float> CbGain;
    std::optional<tt_WhiteBalance20Extension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_WhiteBalance20
template<>
struct xml_convert::XmlTraits<tt_WhiteBalance20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_WhiteBalance20::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CrGain", &tt_WhiteBalance20::CrGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CbGain", &tt_WhiteBalance20::CbGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_WhiteBalance20::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_WhiteBalance20::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ImageStabilizationMode 枚举类型
// 基础类型: std::string
enum class  tt_ImageStabilizationMode {
    OFF,
    ON,
    AUTO,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_ImageStabilizationMode value) {
    switch (value) {
        case tt_ImageStabilizationMode::OFF: return "OFF";
        case tt_ImageStabilizationMode::ON: return "ON";
        case tt_ImageStabilizationMode::AUTO: return "AUTO";
        case tt_ImageStabilizationMode::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_ImageStabilizationMode& value, const std::string& str) {
    if (str == "OFF") { value = tt_ImageStabilizationMode::OFF; return true; }
    if (str == "ON") { value = tt_ImageStabilizationMode::ON; return true; }
    if (str == "AUTO") { value = tt_ImageStabilizationMode::AUTO; return true; }
    if (str == "Extended") { value = tt_ImageStabilizationMode::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ImageStabilizationMode
template<>
struct xml_convert::XmlValueAdapter<tt_ImageStabilizationMode> {
    static bool from_xml_val(tt_ImageStabilizationMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ImageStabilizationMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ImageStabilizationMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_ImageStabilizationMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ImageStabilizationMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ImageStabilizationMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ImageStabilizationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImageStabilizationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ImageStabilizationExtension
template<>
struct xml_convert::XmlTraits<tt_ImageStabilizationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ImageStabilizationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ImageStabilization 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImageStabilization {
    // Parameter to enable/disable Image Stabilization feature.
    tt_ImageStabilizationMode Mode;
    // Optional level parameter (unit unspecified)
    std::optional<float> Level;
    std::optional<tt_ImageStabilizationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ImageStabilization
template<>
struct xml_convert::XmlTraits<tt_ImageStabilization> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_ImageStabilization::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_ImageStabilization::Level, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImageStabilization::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ImageStabilization::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// IrCutFilterAutoAdjustmentExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IrCutFilterAutoAdjustmentExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_IrCutFilterAutoAdjustmentExtension
template<>
struct xml_convert::XmlTraits<tt_IrCutFilterAutoAdjustmentExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_IrCutFilterAutoAdjustmentExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// IrCutFilterAutoAdjustment 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IrCutFilterAutoAdjustment {
    // Specifies which boundaries to automatically toggle Ir cut filter following parameters are applied to. Its options shall be chosen from tt:IrCutFilterAutoBoundaryType.
    std::string BoundaryType;
    // Adjusts boundary exposure level for toggling Ir cut filter to on/off specified with unitless normalized value from +1.0 to -1.0. Zero is default and -1.0 is the darkest adjustment (Unitless).
    std::optional<float> BoundaryOffset;
    // Delay time of toggling Ir cut filter to on/off after crossing of the boundary exposure levels.
    std::optional<my_Duration> ResponseTime;
    std::optional<tt_IrCutFilterAutoAdjustmentExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_IrCutFilterAutoAdjustment
template<>
struct xml_convert::XmlTraits<tt_IrCutFilterAutoAdjustment> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BoundaryType", &tt_IrCutFilterAutoAdjustment::BoundaryType, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BoundaryOffset", &tt_IrCutFilterAutoAdjustment::BoundaryOffset, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ResponseTime", &tt_IrCutFilterAutoAdjustment::ResponseTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_IrCutFilterAutoAdjustment::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_IrCutFilterAutoAdjustment::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ToneCompensationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ToneCompensationExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ToneCompensationExtension
template<>
struct xml_convert::XmlTraits<tt_ToneCompensationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ToneCompensationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ToneCompensation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ToneCompensation {
    // Parameter to enable/disable or automatic ToneCompensation feature. Its options shall be chosen from tt:ToneCompensationMode Type.
    std::string Mode;
    // Optional level parameter specified with unitless normalized value from 0.0 to +1.0.
    std::optional<float> Level;
    std::optional<tt_ToneCompensationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ToneCompensation
template<>
struct xml_convert::XmlTraits<tt_ToneCompensation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_ToneCompensation::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_ToneCompensation::Level, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ToneCompensation::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ToneCompensation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// DefoggingExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DefoggingExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_DefoggingExtension
template<>
struct xml_convert::XmlTraits<tt_DefoggingExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_DefoggingExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Defogging 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Defogging {
    // Parameter to enable/disable or automatic Defogging feature. Its options shall be chosen from tt:DefoggingMode Type.
    std::string Mode;
    // Optional level parameter specified with unitless normalized value from 0.0 to +1.0.
    std::optional<float> Level;
    std::optional<tt_DefoggingExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Defogging
template<>
struct xml_convert::XmlTraits<tt_Defogging> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_Defogging::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_Defogging::Level, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Defogging::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_Defogging::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// NoiseReduction 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NoiseReduction {
    // Level parameter specified with unitless normalized value from 0.0 to +1.0. Level=0 means no noise reduction or minimal noise reduction.
    float Level {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_NoiseReduction
template<>
struct xml_convert::XmlTraits<tt_NoiseReduction> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Level", &tt_NoiseReduction::Level, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_NoiseReduction::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_NoiseReduction::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ImagingSettingsExtension204 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingSettingsExtension204 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ImagingSettingsExtension204
template<>
struct xml_convert::XmlTraits<tt_ImagingSettingsExtension204> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ImagingSettingsExtension204::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ImagingSettingsExtension203 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingSettingsExtension203 {
    // Optional element to configure Image Contrast Compensation.
    std::optional<tt_ToneCompensation> ToneCompensation;
    // Optional element to configure Image Defogging.
    std::optional<tt_Defogging> Defogging;
    // Optional element to configure Image Noise Reduction.
    std::optional<tt_NoiseReduction> NoiseReduction;
    std::optional<tt_ImagingSettingsExtension204> Extension;
};


// XmlTraits for tt_ImagingSettingsExtension203
template<>
struct xml_convert::XmlTraits<tt_ImagingSettingsExtension203> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ToneCompensation", &tt_ImagingSettingsExtension203::ToneCompensation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Defogging", &tt_ImagingSettingsExtension203::Defogging, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NoiseReduction", &tt_ImagingSettingsExtension203::NoiseReduction, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImagingSettingsExtension203::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// ImagingSettingsExtension202 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingSettingsExtension202 {
    // An optional parameter applied to only auto mode to adjust timing of toggling Ir cut filter.
    std::vector<tt_IrCutFilterAutoAdjustment> IrCutFilterAutoAdjustment;
    std::optional<tt_ImagingSettingsExtension203> Extension;
};


// XmlTraits for tt_ImagingSettingsExtension202
template<>
struct xml_convert::XmlTraits<tt_ImagingSettingsExtension202> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IrCutFilterAutoAdjustment", &tt_ImagingSettingsExtension202::IrCutFilterAutoAdjustment, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImagingSettingsExtension202::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// ImagingSettingsExtension20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingSettingsExtension20 {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Optional element to configure Image Stabilization feature.
    std::optional<tt_ImageStabilization> ImageStabilization;
    std::optional<tt_ImagingSettingsExtension202> Extension;
};


// XmlTraits for tt_ImagingSettingsExtension20
template<>
struct xml_convert::XmlTraits<tt_ImagingSettingsExtension20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ImagingSettingsExtension20::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("ImageStabilization", &tt_ImagingSettingsExtension20::ImageStabilization, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImagingSettingsExtension20::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// ImagingSettings20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingSettings20 {
    // Enabled/disabled BLC mode (on/off).
    std::optional<tt_BacklightCompensation20> BacklightCompensation;
    // Image brightness (unit unspecified).
    std::optional<float> Brightness;
    // Color saturation of the image (unit unspecified).
    std::optional<float> ColorSaturation;
    // Contrast of the image (unit unspecified).
    std::optional<float> Contrast;
    // Exposure mode of the device.
    std::optional<tt_Exposure20> Exposure;
    // Focus configuration.
    std::optional<tt_FocusConfiguration20> Focus;
    // Infrared Cutoff Filter settings.
    std::optional<tt_IrCutFilterMode> IrCutFilter;
    // Sharpness of the Video image.
    std::optional<float> Sharpness;
    // WDR settings.
    std::optional<tt_WideDynamicRange20> WideDynamicRange;
    // White balance settings.
    std::optional<tt_WhiteBalance20> WhiteBalance;
    std::optional<tt_ImagingSettingsExtension20> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ImagingSettings20
template<>
struct xml_convert::XmlTraits<tt_ImagingSettings20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BacklightCompensation", &tt_ImagingSettings20::BacklightCompensation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Brightness", &tt_ImagingSettings20::Brightness, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ColorSaturation", &tt_ImagingSettings20::ColorSaturation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Contrast", &tt_ImagingSettings20::Contrast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Exposure", &tt_ImagingSettings20::Exposure, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Focus", &tt_ImagingSettings20::Focus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IrCutFilter", &tt_ImagingSettings20::IrCutFilter, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Sharpness", &tt_ImagingSettings20::Sharpness, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WideDynamicRange", &tt_ImagingSettings20::WideDynamicRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WhiteBalance", &tt_ImagingSettings20::WhiteBalance, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImagingSettings20::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ImagingSettings20::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoSourceExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoSourceExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_VideoSourceExtension2
template<>
struct xml_convert::XmlTraits<tt_VideoSourceExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_VideoSourceExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// VideoSourceExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoSourceExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Optional configuration of the image sensor. To be used if imaging service 2.00 is supported.
    std::optional<tt_ImagingSettings20> Imaging;
    std::optional<tt_VideoSourceExtension2> Extension;
};


// XmlTraits for tt_VideoSourceExtension
template<>
struct xml_convert::XmlTraits<tt_VideoSourceExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_VideoSourceExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Imaging", &tt_VideoSourceExtension::Imaging, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_VideoSourceExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// VideoSource 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoSource : public tt_DeviceEntity {
    // Frame rate in frames per second.
    float Framerate {};
    // Horizontal and vertical resolution
    tt_VideoResolution Resolution;
    // Optional configuration of the image sensor.
    std::optional<tt_ImagingSettings> Imaging;
    std::optional<tt_VideoSourceExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoSource
template<>
struct xml_convert::XmlTraits<tt_VideoSource> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_DeviceEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Framerate", &tt_VideoSource::Framerate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Resolution", &tt_VideoSource::Resolution, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Imaging", &tt_VideoSource::Imaging, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_VideoSource::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_VideoSource::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// AudioSource 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioSource : public tt_DeviceEntity {
    // number of available audio channels. (1: mono, 2: stereo)
    int32_t Channels {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioSource
template<>
struct xml_convert::XmlTraits<tt_AudioSource> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_DeviceEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Channels", &tt_AudioSource::Channels, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioSource::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioSource::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// ConfigurationEntity 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ConfigurationEntity {
    // User readable name. Length up to 64 characters.
    tt_Name Name;
    // Number of internal references currently using this configuration. This informational parameter is read-only. Deprecated for Media2 Service.
    int32_t UseCount {};
    // Token that uniquely references this configuration. Length up to 64 characters.
    tt_ReferenceToken token;
};


// XmlTraits for tt_ConfigurationEntity
template<>
struct xml_convert::XmlTraits<tt_ConfigurationEntity> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_ConfigurationEntity::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UseCount", &tt_ConfigurationEntity::UseCount, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("token", &tt_ConfigurationEntity::token, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RotateMode 枚举类型
// 基础类型: std::string
enum class  tt_RotateMode {
    OFF,
    ON,
    AUTO
};

// 字符串转换函数
inline std::string to_string(tt_RotateMode value) {
    switch (value) {
        case tt_RotateMode::OFF: return "OFF";
        case tt_RotateMode::ON: return "ON";
        case tt_RotateMode::AUTO: return "AUTO";
        default: return "";
    }
}

inline bool from_string(tt_RotateMode& value, const std::string& str) {
    if (str == "OFF") { value = tt_RotateMode::OFF; return true; }
    if (str == "ON") { value = tt_RotateMode::ON; return true; }
    if (str == "AUTO") { value = tt_RotateMode::AUTO; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_RotateMode
template<>
struct xml_convert::XmlValueAdapter<tt_RotateMode> {
    static bool from_xml_val(tt_RotateMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_RotateMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_RotateMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_RotateMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_RotateMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_RotateMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// RotateExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RotateExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_RotateExtension
template<>
struct xml_convert::XmlTraits<tt_RotateExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_RotateExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Rotate 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Rotate {
    // Parameter to enable/disable Rotation feature.
    tt_RotateMode Mode;
    // Optional parameter to configure how much degree of clockwise rotation of image  for On mode. Omitting this parameter for On mode means 180 degree rotation.
    std::optional<int32_t> Degree;
    std::optional<tt_RotateExtension> Extension;
    /*
     * When enabled, the video will be flipped horizontally. If applied alongside rotation, the mirror effect shall be executed after the rotation. Additionally,
     * when Mirror is enabled and Reverse=Auto is set in PTControlDirection or if the device doesn’t support Reverse in PTControlDirection, the device shall automatically adjust the pan direction.
     */
    std::optional<bool> Mirror;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Rotate
template<>
struct xml_convert::XmlTraits<tt_Rotate> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_Rotate::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Degree", &tt_Rotate::Degree, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Rotate::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mirror", &tt_Rotate::Mirror, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_Rotate::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// LensOffset 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_LensOffset {
    // Optional horizontal offset of the lens center in normalized coordinates.
    std::optional<float> x;
    // Optional vertical offset of the lens center in normalized coordinates.
    std::optional<float> y;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_LensOffset
template<>
struct xml_convert::XmlTraits<tt_LensOffset> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("x", &tt_LensOffset::x, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("y", &tt_LensOffset::y, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_LensOffset::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// LensProjection 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_LensProjection {
    // Angle of incidence.
    float Angle {};
    // Mapping radius as a consequence of the emergent angle.
    float Radius {};
    // Optional ray absorption at the given angle due to vignetting. A value of one means no absorption.
    std::optional<float> Transmittance;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_LensProjection
template<>
struct xml_convert::XmlTraits<tt_LensProjection> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Angle", &tt_LensProjection::Angle, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Radius", &tt_LensProjection::Radius, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Transmittance", &tt_LensProjection::Transmittance, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_LensProjection::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_LensProjection::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// LensDescription 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_LensDescription {
    // Offset of the lens center to the imager center in normalized coordinates.
    tt_LensOffset Offset;
    /*
     * Radial description of the projection characteristics. The resulting curve is defined by the B-Spline interpolation
     * over the given elements. The element for Radius zero shall not be provided. The projection points shall be ordered with ascending Radius.
     * Items outside the last projection Radius shall be assumed to be invisible (black).
     */
    std::vector<tt_LensProjection> Projection;
    // Compensation of the x coordinate needed for the ONVIF normalized coordinate system.
    float XFactor {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Optional focal length of the optical system.
    std::optional<float> FocalLength;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_LensDescription
template<>
struct xml_convert::XmlTraits<tt_LensDescription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Offset", &tt_LensDescription::Offset, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Projection", &tt_LensDescription::Projection, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("XFactor", &tt_LensDescription::XFactor, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_LensDescription::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("FocalLength", &tt_LensDescription::FocalLength, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_LensDescription::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SceneOrientationMode 枚举类型
// 基础类型: std::string
enum class  tt_SceneOrientationMode {
    MANUAL,
    AUTO
};

// 字符串转换函数
inline std::string to_string(tt_SceneOrientationMode value) {
    switch (value) {
        case tt_SceneOrientationMode::MANUAL: return "MANUAL";
        case tt_SceneOrientationMode::AUTO: return "AUTO";
        default: return "";
    }
}

inline bool from_string(tt_SceneOrientationMode& value, const std::string& str) {
    if (str == "MANUAL") { value = tt_SceneOrientationMode::MANUAL; return true; }
    if (str == "AUTO") { value = tt_SceneOrientationMode::AUTO; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_SceneOrientationMode
template<>
struct xml_convert::XmlValueAdapter<tt_SceneOrientationMode> {
    static bool from_xml_val(tt_SceneOrientationMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_SceneOrientationMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_SceneOrientationMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_SceneOrientationMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_SceneOrientationMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_SceneOrientationMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// SceneOrientation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SceneOrientation {
    // Parameter to assign the way the camera determines the scene orientation.
    tt_SceneOrientationMode Mode;
    /*
     * Assigned or determined scene orientation based on the Mode. When assigning the Mode to AUTO, this field
     * is optional and will be ignored by the device. When assigning the Mode to MANUAL, this field is required
     * and the device will return an InvalidArgs fault if missing.
     */
    std::optional<std::string> Orientation;
};


// XmlTraits for tt_SceneOrientation
template<>
struct xml_convert::XmlTraits<tt_SceneOrientation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_SceneOrientation::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Orientation", &tt_SceneOrientation::Orientation, "tt", xml_convert::serialize_type::full)
    );
};


// VideoSourceConfigurationExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoSourceConfigurationExtension2 {
    // Optional element describing the geometric lens distortion. Multiple instances for future variable lens support.
    std::vector<tt_LensDescription> LensDescription;
    // Optional element describing the scene orientation in the camera’s field of view.
    std::optional<tt_SceneOrientation> SceneOrientation;
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_VideoSourceConfigurationExtension2
template<>
struct xml_convert::XmlTraits<tt_VideoSourceConfigurationExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("LensDescription", &tt_VideoSourceConfigurationExtension2::LensDescription, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SceneOrientation", &tt_VideoSourceConfigurationExtension2::SceneOrientation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoSourceConfigurationExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// VideoSourceConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoSourceConfigurationExtension {
    /*
     * Optional element to configure rotation of captured image.
     * What resolutions a device supports shall be unaffected by the Rotate parameters.
     * If a device is configured with Rotate=AUTO, the device shall take control over the Degree parameter and automatically update it so that a client can query current rotation.
     * The device shall automatically apply the same rotation to its pan/tilt control direction depending on the following condition:
     * if Reverse=AUTO in PTControlDirection or if the device doesn’t support Reverse in PTControlDirection
     */
    std::optional<tt_Rotate> Rotate;
    std::optional<tt_VideoSourceConfigurationExtension2> Extension;
};


// XmlTraits for tt_VideoSourceConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_VideoSourceConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Rotate", &tt_VideoSourceConfigurationExtension::Rotate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_VideoSourceConfigurationExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// VideoSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoSourceConfiguration : public tt_ConfigurationEntity {
    // Reference to the physical input.
    tt_ReferenceToken SourceToken;
    // Rectangle specifying the Video capturing area. The capturing area shall not be larger than the whole Video source area.
    tt_IntRectangle Bounds;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<tt_VideoSourceConfigurationExtension> Extension;
    // Readonly parameter signalling Source configuration's view mode, for devices supporting different view modes as defined in tt:viewModes.
    std::optional<std::string> ViewMode;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoSourceConfiguration
template<>
struct xml_convert::XmlTraits<tt_VideoSourceConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("SourceToken", &tt_VideoSourceConfiguration::SourceToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Bounds", &tt_VideoSourceConfiguration::Bounds, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoSourceConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Extension", &tt_VideoSourceConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ViewMode", &tt_VideoSourceConfiguration::ViewMode, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_VideoSourceConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// AudioSourceConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioSourceConfiguration : public tt_ConfigurationEntity {
    // Token of the Audio Source the configuration applies to
    tt_ReferenceToken SourceToken;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioSourceConfiguration
template<>
struct xml_convert::XmlTraits<tt_AudioSourceConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("SourceToken", &tt_AudioSourceConfiguration::SourceToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioSourceConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioSourceConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// VideoEncoding 枚举类型
// 基础类型: std::string
enum class  tt_VideoEncoding {
    JPEG,
    MPEG4,
    H264
};

// 字符串转换函数
inline std::string to_string(tt_VideoEncoding value) {
    switch (value) {
        case tt_VideoEncoding::JPEG: return "JPEG";
        case tt_VideoEncoding::MPEG4: return "MPEG4";
        case tt_VideoEncoding::H264: return "H264";
        default: return "";
    }
}

inline bool from_string(tt_VideoEncoding& value, const std::string& str) {
    if (str == "JPEG") { value = tt_VideoEncoding::JPEG; return true; }
    if (str == "MPEG4") { value = tt_VideoEncoding::MPEG4; return true; }
    if (str == "H264") { value = tt_VideoEncoding::H264; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_VideoEncoding
template<>
struct xml_convert::XmlValueAdapter<tt_VideoEncoding> {
    static bool from_xml_val(tt_VideoEncoding& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_VideoEncoding& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_VideoEncoding
template<>
struct xml_convert::XmlAttributeAdapter<tt_VideoEncoding> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_VideoEncoding& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_VideoEncoding& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// VideoRateControl 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoRateControl {
    // Maximum output framerate in fps. If an EncodingInterval is provided the resulting encoded framerate will be reduced by the given factor.
    int32_t FrameRateLimit {};
    // Interval at which images are encoded and transmitted. (A value of 1 means that every frame is encoded, a value of 2 means that every 2nd frame is encoded ...)
    int32_t EncodingInterval {};
    // the maximum output bitrate in kbps
    int32_t BitrateLimit {};
};


// XmlTraits for tt_VideoRateControl
template<>
struct xml_convert::XmlTraits<tt_VideoRateControl> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FrameRateLimit", &tt_VideoRateControl::FrameRateLimit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EncodingInterval", &tt_VideoRateControl::EncodingInterval, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BitrateLimit", &tt_VideoRateControl::BitrateLimit, "tt", xml_convert::serialize_type::full)
    );
};


// Mpeg4Profile 枚举类型
// 基础类型: std::string
enum class  tt_Mpeg4Profile {
    SP,
    ASP
};

// 字符串转换函数
inline std::string to_string(tt_Mpeg4Profile value) {
    switch (value) {
        case tt_Mpeg4Profile::SP: return "SP";
        case tt_Mpeg4Profile::ASP: return "ASP";
        default: return "";
    }
}

inline bool from_string(tt_Mpeg4Profile& value, const std::string& str) {
    if (str == "SP") { value = tt_Mpeg4Profile::SP; return true; }
    if (str == "ASP") { value = tt_Mpeg4Profile::ASP; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_Mpeg4Profile
template<>
struct xml_convert::XmlValueAdapter<tt_Mpeg4Profile> {
    static bool from_xml_val(tt_Mpeg4Profile& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_Mpeg4Profile& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_Mpeg4Profile
template<>
struct xml_convert::XmlAttributeAdapter<tt_Mpeg4Profile> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_Mpeg4Profile& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_Mpeg4Profile& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Mpeg4Configuration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Mpeg4Configuration {
    // Determines the interval in which the I-Frames will be coded. An entry of 1 indicates I-Frames are continuously generated. An entry of 2 indicates that every 2nd image is an I-Frame, and 3 only every 3rd frame, etc. The frames in between are coded as P or B Frames.
    int32_t GovLength {};
    // the Mpeg4 profile, either simple profile (SP) or advanced simple profile (ASP)
    tt_Mpeg4Profile Mpeg4Profile;
};


// XmlTraits for tt_Mpeg4Configuration
template<>
struct xml_convert::XmlTraits<tt_Mpeg4Configuration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("GovLength", &tt_Mpeg4Configuration::GovLength, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mpeg4Profile", &tt_Mpeg4Configuration::Mpeg4Profile, "tt", xml_convert::serialize_type::full)
    );
};


// H264Profile 枚举类型
// 基础类型: std::string
enum class  tt_H264Profile {
    Baseline,
    Main,
    Extended,
    High
};

// 字符串转换函数
inline std::string to_string(tt_H264Profile value) {
    switch (value) {
        case tt_H264Profile::Baseline: return "Baseline";
        case tt_H264Profile::Main: return "Main";
        case tt_H264Profile::Extended: return "Extended";
        case tt_H264Profile::High: return "High";
        default: return "";
    }
}

inline bool from_string(tt_H264Profile& value, const std::string& str) {
    if (str == "Baseline") { value = tt_H264Profile::Baseline; return true; }
    if (str == "Main") { value = tt_H264Profile::Main; return true; }
    if (str == "Extended") { value = tt_H264Profile::Extended; return true; }
    if (str == "High") { value = tt_H264Profile::High; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_H264Profile
template<>
struct xml_convert::XmlValueAdapter<tt_H264Profile> {
    static bool from_xml_val(tt_H264Profile& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_H264Profile& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_H264Profile
template<>
struct xml_convert::XmlAttributeAdapter<tt_H264Profile> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_H264Profile& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_H264Profile& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// H264Configuration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_H264Configuration {
    // Group of Video frames length. Determines typically the interval in which the I-Frames will be coded. An entry of 1 indicates I-Frames are continuously generated. An entry of 2 indicates that every 2nd image is an I-Frame, and 3 only every 3rd frame, etc. The frames in between are coded as P or B Frames.
    int32_t GovLength {};
    // the H.264 profile, either baseline, main, extended or high
    tt_H264Profile H264Profile;
};


// XmlTraits for tt_H264Configuration
template<>
struct xml_convert::XmlTraits<tt_H264Configuration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("GovLength", &tt_H264Configuration::GovLength, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("H264Profile", &tt_H264Configuration::H264Profile, "tt", xml_convert::serialize_type::full)
    );
};


// IPType 枚举类型
// 基础类型: std::string
enum class  tt_IPType {
    IPv4,
    IPv6
};

// 字符串转换函数
inline std::string to_string(tt_IPType value) {
    switch (value) {
        case tt_IPType::IPv4: return "IPv4";
        case tt_IPType::IPv6: return "IPv6";
        default: return "";
    }
}

inline bool from_string(tt_IPType& value, const std::string& str) {
    if (str == "IPv4") { value = tt_IPType::IPv4; return true; }
    if (str == "IPv6") { value = tt_IPType::IPv6; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_IPType
template<>
struct xml_convert::XmlValueAdapter<tt_IPType> {
    static bool from_xml_val(tt_IPType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_IPType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_IPType
template<>
struct xml_convert::XmlAttributeAdapter<tt_IPType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_IPType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_IPType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// IPv4Address 类型别名
// 基础类型: std::string
using tt_IPv4Address = std::string;


// IPv6Address 类型别名
// 基础类型: std::string
using tt_IPv6Address = std::string;


// IPAddress 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IPAddress {
    // Indicates if the address is an IPv4 or IPv6 address.
    tt_IPType Type;
    // IPv4 address.
    std::optional<tt_IPv4Address> IPv4Address;
    // IPv6 address
    std::optional<tt_IPv6Address> IPv6Address;
};


// XmlTraits for tt_IPAddress
template<>
struct xml_convert::XmlTraits<tt_IPAddress> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_IPAddress::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv4Address", &tt_IPAddress::IPv4Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv6Address", &tt_IPAddress::IPv6Address, "tt", xml_convert::serialize_type::full)
    );
};


// MulticastConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MulticastConfiguration {
    // The multicast address (if this address is set to 0 no multicast streaming is enaled)
    tt_IPAddress Address;
    // The RTP mutlicast destination port. A device may support RTCP. In this case the port value shall be even to allow the corresponding RTCP stream to be mapped to the next higher (odd) destination port number as defined in the RTSP specification.
    int32_t Port {};
    // In case of IPv6 the TTL value is assumed as the hop limit. Note that for IPV6 and administratively scoped IPv4 multicast the primary use for hop limit / TTL is to prevent packets from (endlessly) circulating and not limiting scope. In these cases the address contains the scope.
    int32_t TTL {};
    // Read only property signalling that streaming is persistant. Use the methods StartMulticastStreaming and StopMulticastStreaming to switch its state.
    bool AutoStart {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MulticastConfiguration
template<>
struct xml_convert::XmlTraits<tt_MulticastConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Address", &tt_MulticastConfiguration::Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Port", &tt_MulticastConfiguration::Port, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TTL", &tt_MulticastConfiguration::TTL, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AutoStart", &tt_MulticastConfiguration::AutoStart, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MulticastConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_MulticastConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoEncoderConfiguration : public tt_ConfigurationEntity {
    // Used video codec, either Jpeg, H.264 or Mpeg4
    tt_VideoEncoding Encoding;
    // Configured video resolution
    tt_VideoResolution Resolution;
    // Relative value for the video quantizers and the quality of the video. A high value within supported quality range means higher quality
    float Quality {};
    // Optional element to configure rate control related parameters.
    std::optional<tt_VideoRateControl> RateControl;
    // Optional element to configure Mpeg4 related parameters.
    std::optional<tt_Mpeg4Configuration> MPEG4;
    // Optional element to configure H.264 related parameters.
    std::optional<tt_H264Configuration> H264;
    // Defines the multicast settings that could be used for video streaming.
    tt_MulticastConfiguration Multicast;
    // The rtsp session timeout for the related video stream
    my_Duration SessionTimeout;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    /*
     * A value of true indicates that frame rate is a fixed value rather than an upper limit,
     * and that the video encoder shall prioritize frame rate over all other adaptable
     * configuration values such as bitrate.  Default is false.
     */
    std::optional<bool> GuaranteedFrameRate;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoEncoderConfiguration
template<>
struct xml_convert::XmlTraits<tt_VideoEncoderConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Encoding", &tt_VideoEncoderConfiguration::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Resolution", &tt_VideoEncoderConfiguration::Resolution, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Quality", &tt_VideoEncoderConfiguration::Quality, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RateControl", &tt_VideoEncoderConfiguration::RateControl, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MPEG4", &tt_VideoEncoderConfiguration::MPEG4, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("H264", &tt_VideoEncoderConfiguration::H264, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Multicast", &tt_VideoEncoderConfiguration::Multicast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SessionTimeout", &tt_VideoEncoderConfiguration::SessionTimeout, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoEncoderConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("GuaranteedFrameRate", &tt_VideoEncoderConfiguration::GuaranteedFrameRate, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_VideoEncoderConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// AudioEncoding 枚举类型
// 基础类型: std::string
enum class  tt_AudioEncoding {
    G711,
    G726,
    AAC
};

// 字符串转换函数
inline std::string to_string(tt_AudioEncoding value) {
    switch (value) {
        case tt_AudioEncoding::G711: return "G711";
        case tt_AudioEncoding::G726: return "G726";
        case tt_AudioEncoding::AAC: return "AAC";
        default: return "";
    }
}

inline bool from_string(tt_AudioEncoding& value, const std::string& str) {
    if (str == "G711") { value = tt_AudioEncoding::G711; return true; }
    if (str == "G726") { value = tt_AudioEncoding::G726; return true; }
    if (str == "AAC") { value = tt_AudioEncoding::AAC; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_AudioEncoding
template<>
struct xml_convert::XmlValueAdapter<tt_AudioEncoding> {
    static bool from_xml_val(tt_AudioEncoding& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_AudioEncoding& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_AudioEncoding
template<>
struct xml_convert::XmlAttributeAdapter<tt_AudioEncoding> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_AudioEncoding& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_AudioEncoding& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// AudioEncoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioEncoderConfiguration : public tt_ConfigurationEntity {
    // Audio codec used for encoding the audio input (either G.711, G.726 or AAC)
    tt_AudioEncoding Encoding;
    // The output bitrate in kbps.
    int32_t Bitrate {};
    // The output sample rate in kHz.
    int32_t SampleRate {};
    // Defines the multicast settings that could be used for video streaming.
    tt_MulticastConfiguration Multicast;
    // The rtsp session timeout for the related audio stream
    my_Duration SessionTimeout;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioEncoderConfiguration
template<>
struct xml_convert::XmlTraits<tt_AudioEncoderConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Encoding", &tt_AudioEncoderConfiguration::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Bitrate", &tt_AudioEncoderConfiguration::Bitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SampleRate", &tt_AudioEncoderConfiguration::SampleRate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Multicast", &tt_AudioEncoderConfiguration::Multicast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SessionTimeout", &tt_AudioEncoderConfiguration::SessionTimeout, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioEncoderConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioEncoderConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// SimpleItem 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SimpleItem {
    // Item name.
    std::string Name;
    // Item value. The type is defined in the corresponding description.
    std::string Value;
};


// XmlTraits for tt_SimpleItem
template<>
struct xml_convert::XmlTraits<tt_SimpleItem> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_SimpleItem::Name, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Value", &tt_SimpleItem::Value, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ElementItem 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ElementItem {
    // Any element from namespace: ##any (processContents: lax)
    AnyElement _any_;
    // Item name.
    std::string Name;
};


// XmlTraits for tt_ElementItem
template<>
struct xml_convert::XmlTraits<tt_ElementItem> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ElementItem::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Name", &tt_ElementItem::Name, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ItemListExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ItemListExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ItemListExtension
template<>
struct xml_convert::XmlTraits<tt_ItemListExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ItemListExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ItemList 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ItemList {
    // Value name pair as defined by the corresponding description.
    std::vector<tt_SimpleItem> SimpleItem;
    // Complex value structure.
    std::vector<tt_ElementItem> ElementItem;
    std::optional<tt_ItemListExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ItemList
template<>
struct xml_convert::XmlTraits<tt_ItemList> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SimpleItem", &tt_ItemList::SimpleItem, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ElementItem", &tt_ItemList::ElementItem, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ItemList::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ItemList::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Config 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Config {
    // List of configuration parameters as defined in the corresponding description.
    tt_ItemList Parameters;
    // Name of the configuration.
    std::string Name;
    // The Type attribute specifies the type of rule and shall be equal to value of one of Name attributes of ConfigDescription elements returned by GetSupportedRules and GetSupportedAnalyticsModules command.
    std::string Type;
};


// XmlTraits for tt_Config
template<>
struct xml_convert::XmlTraits<tt_Config> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Parameters", &tt_Config::Parameters, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Name", &tt_Config::Name, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Type", &tt_Config::Type, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AnalyticsEngineConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsEngineConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_AnalyticsEngineConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_AnalyticsEngineConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AnalyticsEngineConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// AnalyticsEngineConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsEngineConfiguration {
    std::vector<tt_Config> AnalyticsModule;
    std::optional<tt_AnalyticsEngineConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnalyticsEngineConfiguration
template<>
struct xml_convert::XmlTraits<tt_AnalyticsEngineConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AnalyticsModule", &tt_AnalyticsEngineConfiguration::AnalyticsModule, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_AnalyticsEngineConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_AnalyticsEngineConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RuleEngineConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RuleEngineConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_RuleEngineConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_RuleEngineConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_RuleEngineConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// RuleEngineConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RuleEngineConfiguration {
    std::vector<tt_Config> Rule;
    std::optional<tt_RuleEngineConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RuleEngineConfiguration
template<>
struct xml_convert::XmlTraits<tt_RuleEngineConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Rule", &tt_RuleEngineConfiguration::Rule, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_RuleEngineConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_RuleEngineConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoAnalyticsConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoAnalyticsConfiguration : public tt_ConfigurationEntity {
    tt_AnalyticsEngineConfiguration AnalyticsEngineConfiguration;
    tt_RuleEngineConfiguration RuleEngineConfiguration;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoAnalyticsConfiguration
template<>
struct xml_convert::XmlTraits<tt_VideoAnalyticsConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("AnalyticsEngineConfiguration", &tt_VideoAnalyticsConfiguration::AnalyticsEngineConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RuleEngineConfiguration", &tt_VideoAnalyticsConfiguration::RuleEngineConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoAnalyticsConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_VideoAnalyticsConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// PTZSpeed 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZSpeed {
    // Pan and tilt speed. The x component corresponds to pan and the y component to tilt. If omitted in a request, the current (if any) PanTilt movement should not be affected.
    std::optional<tt_Vector2D> PanTilt;
    // A zoom speed. If omitted in a request, the current (if any) Zoom movement should not be affected.
    std::optional<tt_Vector1D> Zoom;
};


// XmlTraits for tt_PTZSpeed
template<>
struct xml_convert::XmlTraits<tt_PTZSpeed> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PanTilt", &tt_PTZSpeed::PanTilt, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Zoom", &tt_PTZSpeed::Zoom, "tt", xml_convert::serialize_type::full)
    );
};


// Space2DDescription 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Space2DDescription {
    // A URI of coordinate systems.
    std::string URI;
    // A range of x-axis.
    tt_FloatRange XRange;
    // A range of y-axis.
    tt_FloatRange YRange;
};


// XmlTraits for tt_Space2DDescription
template<>
struct xml_convert::XmlTraits<tt_Space2DDescription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("URI", &tt_Space2DDescription::URI, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("XRange", &tt_Space2DDescription::XRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("YRange", &tt_Space2DDescription::YRange, "tt", xml_convert::serialize_type::full)
    );
};


// PanTiltLimits 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PanTiltLimits {
    // A range of pan tilt limits.
    tt_Space2DDescription Range;
};


// XmlTraits for tt_PanTiltLimits
template<>
struct xml_convert::XmlTraits<tt_PanTiltLimits> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Range", &tt_PanTiltLimits::Range, "tt", xml_convert::serialize_type::full)
    );
};


// Space1DDescription 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Space1DDescription {
    // A URI of coordinate systems.
    std::string URI;
    // A range of x-axis.
    tt_FloatRange XRange;
};


// XmlTraits for tt_Space1DDescription
template<>
struct xml_convert::XmlTraits<tt_Space1DDescription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("URI", &tt_Space1DDescription::URI, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("XRange", &tt_Space1DDescription::XRange, "tt", xml_convert::serialize_type::full)
    );
};


// ZoomLimits 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ZoomLimits {
    // A range of zoom limit
    tt_Space1DDescription Range;
};


// XmlTraits for tt_ZoomLimits
template<>
struct xml_convert::XmlTraits<tt_ZoomLimits> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Range", &tt_ZoomLimits::Range, "tt", xml_convert::serialize_type::full)
    );
};


// EFlipMode 枚举类型
// 基础类型: std::string
enum class  tt_EFlipMode {
    OFF,
    ON,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_EFlipMode value) {
    switch (value) {
        case tt_EFlipMode::OFF: return "OFF";
        case tt_EFlipMode::ON: return "ON";
        case tt_EFlipMode::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_EFlipMode& value, const std::string& str) {
    if (str == "OFF") { value = tt_EFlipMode::OFF; return true; }
    if (str == "ON") { value = tt_EFlipMode::ON; return true; }
    if (str == "Extended") { value = tt_EFlipMode::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_EFlipMode
template<>
struct xml_convert::XmlValueAdapter<tt_EFlipMode> {
    static bool from_xml_val(tt_EFlipMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_EFlipMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_EFlipMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_EFlipMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_EFlipMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_EFlipMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// EFlip 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_EFlip {
    // Parameter to enable/disable E-Flip feature.
    tt_EFlipMode Mode;
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_EFlip
template<>
struct xml_convert::XmlTraits<tt_EFlip> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_EFlip::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_EFlip::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_EFlip::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ReverseMode 枚举类型
// 基础类型: std::string
enum class  tt_ReverseMode {
    OFF,
    ON,
    AUTO,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_ReverseMode value) {
    switch (value) {
        case tt_ReverseMode::OFF: return "OFF";
        case tt_ReverseMode::ON: return "ON";
        case tt_ReverseMode::AUTO: return "AUTO";
        case tt_ReverseMode::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_ReverseMode& value, const std::string& str) {
    if (str == "OFF") { value = tt_ReverseMode::OFF; return true; }
    if (str == "ON") { value = tt_ReverseMode::ON; return true; }
    if (str == "AUTO") { value = tt_ReverseMode::AUTO; return true; }
    if (str == "Extended") { value = tt_ReverseMode::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ReverseMode
template<>
struct xml_convert::XmlValueAdapter<tt_ReverseMode> {
    static bool from_xml_val(tt_ReverseMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ReverseMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ReverseMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_ReverseMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ReverseMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ReverseMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Reverse 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Reverse {
    // Parameter to enable/disable Reverse feature.
    tt_ReverseMode Mode;
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Reverse
template<>
struct xml_convert::XmlTraits<tt_Reverse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_Reverse::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Reverse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Reverse::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTControlDirectionExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTControlDirectionExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTControlDirectionExtension
template<>
struct xml_convert::XmlTraits<tt_PTControlDirectionExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTControlDirectionExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_PTControlDirectionExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTControlDirection 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTControlDirection {
    // Optional element to configure related parameters for E-Flip.
    std::optional<tt_EFlip> EFlip;
    // Optional element to configure related parameters for reversing of PT Control Direction.
    std::optional<tt_Reverse> Reverse;
    std::optional<tt_PTControlDirectionExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTControlDirection
template<>
struct xml_convert::XmlTraits<tt_PTControlDirection> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("EFlip", &tt_PTControlDirection::EFlip, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Reverse", &tt_PTControlDirection::Reverse, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTControlDirection::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PTControlDirection::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZConfigurationExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZConfigurationExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZConfigurationExtension2
template<>
struct xml_convert::XmlTraits<tt_PTZConfigurationExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZConfigurationExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZConfigurationExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Optional element to configure PT Control Direction related features.
    std::optional<tt_PTControlDirection> PTControlDirection;
    std::optional<tt_PTZConfigurationExtension2> Extension;
};


// XmlTraits for tt_PTZConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_PTZConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("PTControlDirection", &tt_PTZConfigurationExtension::PTControlDirection, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZConfigurationExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// PTZConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZConfiguration : public tt_ConfigurationEntity {
    // A mandatory reference to the PTZ Node that the PTZ Configuration belongs to.
    tt_ReferenceToken NodeToken;
    // If the PTZ Node supports absolute Pan/Tilt movements, it shall specify one Absolute Pan/Tilt Position Space as default.
    std::optional<std::string> DefaultAbsolutePantTiltPositionSpace;
    // If the PTZ Node supports absolute zoom movements, it shall specify one Absolute Zoom Position Space as default.
    std::optional<std::string> DefaultAbsoluteZoomPositionSpace;
    // If the PTZ Node supports relative Pan/Tilt movements, it shall specify one RelativePan/Tilt Translation Space as default.
    std::optional<std::string> DefaultRelativePanTiltTranslationSpace;
    // If the PTZ Node supports relative zoom movements, it shall specify one Relative Zoom Translation Space as default.
    std::optional<std::string> DefaultRelativeZoomTranslationSpace;
    // If the PTZ Node supports continuous Pan/Tilt movements, it shall specify one Continuous Pan/Tilt Velocity Space as default.
    std::optional<std::string> DefaultContinuousPanTiltVelocitySpace;
    // If the PTZ Node supports continuous zoom movements, it shall specify one Continuous Zoom Velocity Space as default.
    std::optional<std::string> DefaultContinuousZoomVelocitySpace;
    // If the PTZ Node supports absolute or relative PTZ movements, it shall specify corresponding default Pan/Tilt and Zoom speeds.
    std::optional<tt_PTZSpeed> DefaultPTZSpeed;
    // If the PTZ Node supports continuous movements, it shall specify a default timeout, after which the movement stops.
    std::optional<my_Duration> DefaultPTZTimeout;
    // The Pan/Tilt limits element should be present for a PTZ Node that supports an absolute Pan/Tilt. If the element is present it signals the support for configurable Pan/Tilt limits. If limits are enabled, the Pan/Tilt movements shall always stay within the specified range. The Pan/Tilt limits are disabled by setting the limits to –INF or +INF.
    std::optional<tt_PanTiltLimits> PanTiltLimits;
    // The Zoom limits element should be present for a PTZ Node that supports absolute zoom. If the element is present it signals the supports for configurable Zoom limits. If limits are enabled the zoom movements shall always stay within the specified range. The Zoom limits are disabled by settings the limits to -INF and +INF.
    std::optional<tt_ZoomLimits> ZoomLimits;
    std::optional<tt_PTZConfigurationExtension> Extension;
    // The optional acceleration ramp used by the device when moving.
    std::optional<int32_t> MoveRamp;
    // The optional acceleration ramp used by the device when recalling presets.
    std::optional<int32_t> PresetRamp;
    // The optional acceleration ramp used by the device when executing PresetTours.
    std::optional<int32_t> PresetTourRamp;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZConfiguration
template<>
struct xml_convert::XmlTraits<tt_PTZConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("NodeToken", &tt_PTZConfiguration::NodeToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultAbsolutePantTiltPositionSpace", &tt_PTZConfiguration::DefaultAbsolutePantTiltPositionSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultAbsoluteZoomPositionSpace", &tt_PTZConfiguration::DefaultAbsoluteZoomPositionSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultRelativePanTiltTranslationSpace", &tt_PTZConfiguration::DefaultRelativePanTiltTranslationSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultRelativeZoomTranslationSpace", &tt_PTZConfiguration::DefaultRelativeZoomTranslationSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultContinuousPanTiltVelocitySpace", &tt_PTZConfiguration::DefaultContinuousPanTiltVelocitySpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultContinuousZoomVelocitySpace", &tt_PTZConfiguration::DefaultContinuousZoomVelocitySpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultPTZSpeed", &tt_PTZConfiguration::DefaultPTZSpeed, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultPTZTimeout", &tt_PTZConfiguration::DefaultPTZTimeout, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PanTiltLimits", &tt_PTZConfiguration::PanTiltLimits, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ZoomLimits", &tt_PTZConfiguration::ZoomLimits, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MoveRamp", &tt_PTZConfiguration::MoveRamp, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("PresetRamp", &tt_PTZConfiguration::PresetRamp, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("PresetTourRamp", &tt_PTZConfiguration::PresetTourRamp, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_PTZConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// PTZFilter 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZFilter {
    // True if the metadata stream shall contain the PTZ status (IDLE, MOVING or UNKNOWN)
    bool Status {};
    // True if the metadata stream shall contain the PTZ position
    bool Position {};
    // True if the metadata stream shall contain the field-of-view information
    std::optional<bool> FieldOfView;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZFilter
template<>
struct xml_convert::XmlTraits<tt_PTZFilter> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Status", &tt_PTZFilter::Status, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Position", &tt_PTZFilter::Position, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FieldOfView", &tt_PTZFilter::FieldOfView, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PTZFilter::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SubscriptionPolicy 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SubscriptionPolicy {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_SubscriptionPolicy
template<>
struct xml_convert::XmlTraits<tt_SubscriptionPolicy> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_SubscriptionPolicy::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// EventSubscription 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_EventSubscription {
    std::optional<wsnt_FilterType> Filter;
    std::optional<tt_SubscriptionPolicy> SubscriptionPolicy;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_EventSubscription
template<>
struct xml_convert::XmlTraits<tt_EventSubscription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Filter", &tt_EventSubscription::Filter, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SubscriptionPolicy", &tt_EventSubscription::SubscriptionPolicy, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_EventSubscription::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_EventSubscription::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MetadataConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MetadataConfigurationExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_MetadataConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_MetadataConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_MetadataConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// MetadataConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MetadataConfiguration : public tt_ConfigurationEntity {
    // optional element to configure which PTZ related data is to include in the metadata stream
    std::optional<tt_PTZFilter> PTZStatus;
    /*
     * Optional element to configure the streaming of events. A client might be interested in receiving all,
     * none or some of the events produced by the device:
     * To get all events: Include the Events element but do not include a filter.
     * To get no events: Do not include the Events element.
     * To get only some events: Include the Events element and include a filter in the element.
     */
    std::optional<tt_EventSubscription> Events;
    // Defines whether the streamed metadata will include metadata from the analytics engines (video, cell motion, audio etc.)
    std::optional<bool> Analytics;
    // Defines the multicast settings that could be used for video streaming.
    tt_MulticastConfiguration Multicast;
    // The rtsp session timeout for the related audio stream (when using Media2 Service, this value is deprecated and ignored)
    my_Duration SessionTimeout;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    /*
     * Indication which AnalyticsModules shall output metadata.
     * Note that the streaming behavior is undefined if the list includes items that are not part of the associated AnalyticsConfiguration.
     */
    std::optional<tt_AnalyticsEngineConfiguration> AnalyticsEngineConfiguration;
    std::optional<tt_MetadataConfigurationExtension> Extension;
    // Optional parameter to configure compression type of Metadata payload. Use values from enumeration MetadataCompressionType.
    std::optional<std::string> CompressionType;
    // Optional parameter to configure if the metadata stream shall contain the Geo Location coordinates of each target.
    std::optional<bool> GeoLocation;
    // Optional parameter to configure if the generated metadata stream should contain shape information as polygon.
    std::optional<bool> ShapePolygon;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MetadataConfiguration
template<>
struct xml_convert::XmlTraits<tt_MetadataConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("PTZStatus", &tt_MetadataConfiguration::PTZStatus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Events", &tt_MetadataConfiguration::Events, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Analytics", &tt_MetadataConfiguration::Analytics, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Multicast", &tt_MetadataConfiguration::Multicast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SessionTimeout", &tt_MetadataConfiguration::SessionTimeout, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MetadataConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("AnalyticsEngineConfiguration", &tt_MetadataConfiguration::AnalyticsEngineConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_MetadataConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CompressionType", &tt_MetadataConfiguration::CompressionType, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("GeoLocation", &tt_MetadataConfiguration::GeoLocation, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("ShapePolygon", &tt_MetadataConfiguration::ShapePolygon, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_MetadataConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// AudioOutputConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioOutputConfiguration : public tt_ConfigurationEntity {
    // Token of the phsycial Audio output.
    tt_ReferenceToken OutputToken;
    /*
     * An audio channel MAY support different types of audio transmission. While for full duplex
     * operation no special handling is required, in half duplex operation the transmission direction
     * needs to be switched.
     * The optional SendPrimacy parameter inside the AudioOutputConfiguration indicates which
     * direction is currently active. An NVC can switch between different modes by setting the
     * AudioOutputConfiguration.
     * The following modes for the Send-Primacy are defined:
     * www.onvif.org/ver20/HalfDuplex/Server
     * The server is allowed to send audio data to the client. The client shall not send
     * audio data via the backchannel to the NVT in this mode.
     * www.onvif.org/ver20/HalfDuplex/Client
     * The client is allowed to send audio data via the backchannel to the server. The
     * NVT shall not send audio data to the client in this mode.
     * www.onvif.org/ver20/HalfDuplex/Auto
     * It is up to the device how to deal with sending and receiving audio data.
     *
     * Acoustic echo cancellation is out of ONVIF scope.
     */
    std::optional<std::string> SendPrimacy;
    // Volume setting of the output. The applicable range is defined via the option AudioOutputOptions.OutputLevelRange.
    int32_t OutputLevel {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioOutputConfiguration
template<>
struct xml_convert::XmlTraits<tt_AudioOutputConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("OutputToken", &tt_AudioOutputConfiguration::OutputToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SendPrimacy", &tt_AudioOutputConfiguration::SendPrimacy, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("OutputLevel", &tt_AudioOutputConfiguration::OutputLevel, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioOutputConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioOutputConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// AudioDecoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioDecoderConfiguration : public tt_ConfigurationEntity {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioDecoderConfiguration
template<>
struct xml_convert::XmlTraits<tt_AudioDecoderConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AudioDecoderConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioDecoderConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// ProfileExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ProfileExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ProfileExtension2
template<>
struct xml_convert::XmlTraits<tt_ProfileExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ProfileExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ProfileExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ProfileExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Optional configuration of the Audio output.
    std::optional<tt_AudioOutputConfiguration> AudioOutputConfiguration;
    // Optional configuration of the Audio decoder.
    std::optional<tt_AudioDecoderConfiguration> AudioDecoderConfiguration;
    std::optional<tt_ProfileExtension2> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ProfileExtension
template<>
struct xml_convert::XmlTraits<tt_ProfileExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ProfileExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("AudioOutputConfiguration", &tt_ProfileExtension::AudioOutputConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioDecoderConfiguration", &tt_ProfileExtension::AudioDecoderConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ProfileExtension::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ProfileExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Profile 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Profile {
    // User readable name of the profile.
    tt_Name Name;
    // Optional configuration of the Video input.
    std::optional<tt_VideoSourceConfiguration> VideoSourceConfiguration;
    // Optional configuration of the Audio input.
    std::optional<tt_AudioSourceConfiguration> AudioSourceConfiguration;
    // Optional configuration of the Video encoder.
    std::optional<tt_VideoEncoderConfiguration> VideoEncoderConfiguration;
    // Optional configuration of the Audio encoder.
    std::optional<tt_AudioEncoderConfiguration> AudioEncoderConfiguration;
    // Optional configuration of the video analytics module and rule engine.
    std::optional<tt_VideoAnalyticsConfiguration> VideoAnalyticsConfiguration;
    // Optional configuration of the pan tilt zoom unit.
    std::optional<tt_PTZConfiguration> PTZConfiguration;
    // Optional configuration of the metadata stream.
    std::optional<tt_MetadataConfiguration> MetadataConfiguration;
    // Extensions defined in ONVIF 2.0
    std::optional<tt_ProfileExtension> Extension;
    // Unique identifier of the profile.
    tt_ReferenceToken token;
    // A value of true signals that the profile cannot be deleted. Default is false.
    std::optional<bool> fixed;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Profile
template<>
struct xml_convert::XmlTraits<tt_Profile> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_Profile::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoSourceConfiguration", &tt_Profile::VideoSourceConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioSourceConfiguration", &tt_Profile::AudioSourceConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoEncoderConfiguration", &tt_Profile::VideoEncoderConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioEncoderConfiguration", &tt_Profile::AudioEncoderConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoAnalyticsConfiguration", &tt_Profile::VideoAnalyticsConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PTZConfiguration", &tt_Profile::PTZConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MetadataConfiguration", &tt_Profile::MetadataConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Profile::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("token", &tt_Profile::token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("fixed", &tt_Profile::fixed, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_Profile::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RotateOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RotateOptionsExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_RotateOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_RotateOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_RotateOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// RotateOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RotateOptions {
    // Supported options of Rotate mode parameter.
    std::vector<tt_RotateMode> Mode;
    // List of supported degree value for rotation.
    std::optional<tt_IntItems> DegreeList;
    std::optional<tt_RotateOptionsExtension> Extension;
    /*
     * Signals if a device requires a reboot after changing the rotation or mirror.
     * If a device can handle rotation changes or mirror changes without rebooting this value shall be set to false.
     */
    std::optional<bool> Reboot;
    // Signals if video source mirroring is supported.
    std::optional<bool> Mirror;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RotateOptions
template<>
struct xml_convert::XmlTraits<tt_RotateOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_RotateOptions::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DegreeList", &tt_RotateOptions::DegreeList, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_RotateOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Reboot", &tt_RotateOptions::Reboot, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Mirror", &tt_RotateOptions::Mirror, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_RotateOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoSourceConfigurationOptionsExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoSourceConfigurationOptionsExtension2 {
    // Scene orientation modes supported by the device for this configuration.
    std::vector<tt_SceneOrientationMode> SceneOrientationMode;
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_VideoSourceConfigurationOptionsExtension2
template<>
struct xml_convert::XmlTraits<tt_VideoSourceConfigurationOptionsExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SceneOrientationMode", &tt_VideoSourceConfigurationOptionsExtension2::SceneOrientationMode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoSourceConfigurationOptionsExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// VideoSourceConfigurationOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoSourceConfigurationOptionsExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Options of parameters for Rotation feature.
    std::optional<tt_RotateOptions> Rotate;
    std::optional<tt_VideoSourceConfigurationOptionsExtension2> Extension;
};


// XmlTraits for tt_VideoSourceConfigurationOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_VideoSourceConfigurationOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_VideoSourceConfigurationOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Rotate", &tt_VideoSourceConfigurationOptionsExtension::Rotate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_VideoSourceConfigurationOptionsExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// VideoSourceConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoSourceConfigurationOptions {
    /*
     * Supported range for the capturing area.
     * Device that does not support cropped streaming shall express BoundsRange option as mentioned below
     * BoundsRange->XRange and BoundsRange->YRange with same Min/Max values HeightRange and WidthRange Min/Max values same as VideoSource Height and Width Limits.
     */
    tt_IntRectangleRange BoundsRange;
    // List of physical inputs.
    std::vector<tt_ReferenceToken> VideoSourceTokensAvailable;
    std::optional<tt_VideoSourceConfigurationOptionsExtension> Extension;
    // Maximum number of profiles.
    std::optional<int32_t> MaximumNumberOfProfiles;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoSourceConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_VideoSourceConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BoundsRange", &tt_VideoSourceConfigurationOptions::BoundsRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoSourceTokensAvailable", &tt_VideoSourceConfigurationOptions::VideoSourceTokensAvailable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_VideoSourceConfigurationOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaximumNumberOfProfiles", &tt_VideoSourceConfigurationOptions::MaximumNumberOfProfiles, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_VideoSourceConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SceneOrientationOption 枚举类型
// 基础类型: std::string
enum class  tt_SceneOrientationOption {
    Below,
    Horizon,
    Above
};

// 字符串转换函数
inline std::string to_string(tt_SceneOrientationOption value) {
    switch (value) {
        case tt_SceneOrientationOption::Below: return "Below";
        case tt_SceneOrientationOption::Horizon: return "Horizon";
        case tt_SceneOrientationOption::Above: return "Above";
        default: return "";
    }
}

inline bool from_string(tt_SceneOrientationOption& value, const std::string& str) {
    if (str == "Below") { value = tt_SceneOrientationOption::Below; return true; }
    if (str == "Horizon") { value = tt_SceneOrientationOption::Horizon; return true; }
    if (str == "Above") { value = tt_SceneOrientationOption::Above; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_SceneOrientationOption
template<>
struct xml_convert::XmlValueAdapter<tt_SceneOrientationOption> {
    static bool from_xml_val(tt_SceneOrientationOption& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_SceneOrientationOption& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_SceneOrientationOption
template<>
struct xml_convert::XmlAttributeAdapter<tt_SceneOrientationOption> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_SceneOrientationOption& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_SceneOrientationOption& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ViewModes 枚举类型
// 基础类型: std::string
enum class  tt_ViewModes {
    tt_Fisheye, // tt:Fisheye
    tt_360Panorama, // tt:360Panorama
    tt_180Panorama, // tt:180Panorama
    tt_Quad, // tt:Quad
    tt_Original, // tt:Original
    tt_LeftHalf, // tt:LeftHalf
    tt_RightHalf, // tt:RightHalf
    tt_Dewarp // tt:Dewarp
};

// 字符串转换函数
inline std::string to_string(tt_ViewModes value) {
    switch (value) {
        case tt_ViewModes::tt_Fisheye: return "tt:Fisheye";
        case tt_ViewModes::tt_360Panorama: return "tt:360Panorama";
        case tt_ViewModes::tt_180Panorama: return "tt:180Panorama";
        case tt_ViewModes::tt_Quad: return "tt:Quad";
        case tt_ViewModes::tt_Original: return "tt:Original";
        case tt_ViewModes::tt_LeftHalf: return "tt:LeftHalf";
        case tt_ViewModes::tt_RightHalf: return "tt:RightHalf";
        case tt_ViewModes::tt_Dewarp: return "tt:Dewarp";
        default: return "";
    }
}

inline bool from_string(tt_ViewModes& value, const std::string& str) {
    if (str == "tt:Fisheye") { value = tt_ViewModes::tt_Fisheye; return true; }
    if (str == "tt:360Panorama") { value = tt_ViewModes::tt_360Panorama; return true; }
    if (str == "tt:180Panorama") { value = tt_ViewModes::tt_180Panorama; return true; }
    if (str == "tt:Quad") { value = tt_ViewModes::tt_Quad; return true; }
    if (str == "tt:Original") { value = tt_ViewModes::tt_Original; return true; }
    if (str == "tt:LeftHalf") { value = tt_ViewModes::tt_LeftHalf; return true; }
    if (str == "tt:RightHalf") { value = tt_ViewModes::tt_RightHalf; return true; }
    if (str == "tt:Dewarp") { value = tt_ViewModes::tt_Dewarp; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ViewModes
template<>
struct xml_convert::XmlValueAdapter<tt_ViewModes> {
    static bool from_xml_val(tt_ViewModes& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ViewModes& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ViewModes
template<>
struct xml_convert::XmlAttributeAdapter<tt_ViewModes> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ViewModes& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ViewModes& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// JpegOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_JpegOptions {
    // List of supported image sizes.
    std::vector<tt_VideoResolution> ResolutionsAvailable;
    // Supported frame rate in fps (frames per second).
    tt_IntRange FrameRateRange;
    // Supported encoding interval range. The encoding interval corresponds to the number of frames devided by the encoded frames. An encoding interval value of "1" means that all frames are encoded.
    tt_IntRange EncodingIntervalRange;
};


// XmlTraits for tt_JpegOptions
template<>
struct xml_convert::XmlTraits<tt_JpegOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ResolutionsAvailable", &tt_JpegOptions::ResolutionsAvailable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FrameRateRange", &tt_JpegOptions::FrameRateRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EncodingIntervalRange", &tt_JpegOptions::EncodingIntervalRange, "tt", xml_convert::serialize_type::full)
    );
};


// Mpeg4Options 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Mpeg4Options {
    // List of supported image sizes.
    std::vector<tt_VideoResolution> ResolutionsAvailable;
    // Supported group of Video frames length. This value typically corresponds to the I-Frame distance.
    tt_IntRange GovLengthRange;
    // Supported frame rate in fps (frames per second).
    tt_IntRange FrameRateRange;
    // Supported encoding interval range. The encoding interval corresponds to the number of frames devided by the encoded frames. An encoding interval value of "1" means that all frames are encoded.
    tt_IntRange EncodingIntervalRange;
    // List of supported MPEG-4 profiles.
    std::vector<tt_Mpeg4Profile> Mpeg4ProfilesSupported;
};


// XmlTraits for tt_Mpeg4Options
template<>
struct xml_convert::XmlTraits<tt_Mpeg4Options> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ResolutionsAvailable", &tt_Mpeg4Options::ResolutionsAvailable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("GovLengthRange", &tt_Mpeg4Options::GovLengthRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FrameRateRange", &tt_Mpeg4Options::FrameRateRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EncodingIntervalRange", &tt_Mpeg4Options::EncodingIntervalRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mpeg4ProfilesSupported", &tt_Mpeg4Options::Mpeg4ProfilesSupported, "tt", xml_convert::serialize_type::full)
    );
};


// H264Options 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_H264Options {
    // List of supported image sizes.
    std::vector<tt_VideoResolution> ResolutionsAvailable;
    // Supported group of Video frames length. This value typically corresponds to the I-Frame distance.
    tt_IntRange GovLengthRange;
    // Supported frame rate in fps (frames per second).
    tt_IntRange FrameRateRange;
    // Supported encoding interval range. The encoding interval corresponds to the number of frames devided by the encoded frames. An encoding interval value of "1" means that all frames are encoded.
    tt_IntRange EncodingIntervalRange;
    // List of supported H.264 profiles.
    std::vector<tt_H264Profile> H264ProfilesSupported;
};


// XmlTraits for tt_H264Options
template<>
struct xml_convert::XmlTraits<tt_H264Options> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ResolutionsAvailable", &tt_H264Options::ResolutionsAvailable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("GovLengthRange", &tt_H264Options::GovLengthRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FrameRateRange", &tt_H264Options::FrameRateRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EncodingIntervalRange", &tt_H264Options::EncodingIntervalRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("H264ProfilesSupported", &tt_H264Options::H264ProfilesSupported, "tt", xml_convert::serialize_type::full)
    );
};


// JpegOptions2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_JpegOptions2 : public tt_JpegOptions {
    // Supported range of encoded bitrate in kbps.
    tt_IntRange BitrateRange;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_JpegOptions2
template<>
struct xml_convert::XmlTraits<tt_JpegOptions2> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_JpegOptions>::fields, std::make_tuple(
        xml_convert::make_field_desc("BitrateRange", &tt_JpegOptions2::BitrateRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_JpegOptions2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_JpegOptions2::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// Mpeg4Options2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Mpeg4Options2 : public tt_Mpeg4Options {
    // Supported range of encoded bitrate in kbps.
    tt_IntRange BitrateRange;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Mpeg4Options2
template<>
struct xml_convert::XmlTraits<tt_Mpeg4Options2> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_Mpeg4Options>::fields, std::make_tuple(
        xml_convert::make_field_desc("BitrateRange", &tt_Mpeg4Options2::BitrateRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Mpeg4Options2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Mpeg4Options2::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// H264Options2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_H264Options2 : public tt_H264Options {
    // Supported range of encoded bitrate in kbps.
    tt_IntRange BitrateRange;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_H264Options2
template<>
struct xml_convert::XmlTraits<tt_H264Options2> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_H264Options>::fields, std::make_tuple(
        xml_convert::make_field_desc("BitrateRange", &tt_H264Options2::BitrateRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_H264Options2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_H264Options2::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// VideoEncoderOptionsExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoEncoderOptionsExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_VideoEncoderOptionsExtension2
template<>
struct xml_convert::XmlTraits<tt_VideoEncoderOptionsExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_VideoEncoderOptionsExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// VideoEncoderOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoEncoderOptionsExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Optional JPEG encoder settings ranges.
    std::optional<tt_JpegOptions2> JPEG;
    // Optional MPEG-4 encoder settings ranges.
    std::optional<tt_Mpeg4Options2> MPEG4;
    // Optional H.264 encoder settings ranges.
    std::optional<tt_H264Options2> H264;
    std::optional<tt_VideoEncoderOptionsExtension2> Extension;
};


// XmlTraits for tt_VideoEncoderOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_VideoEncoderOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_VideoEncoderOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("JPEG", &tt_VideoEncoderOptionsExtension::JPEG, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MPEG4", &tt_VideoEncoderOptionsExtension::MPEG4, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("H264", &tt_VideoEncoderOptionsExtension::H264, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_VideoEncoderOptionsExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// VideoEncoderConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoEncoderConfigurationOptions {
    // Range of the quality values. A high value means higher quality.
    tt_IntRange QualityRange;
    // Optional JPEG encoder settings ranges (See also Extension element).
    std::optional<tt_JpegOptions> JPEG;
    // Optional MPEG-4 encoder settings ranges (See also Extension element).
    std::optional<tt_Mpeg4Options> MPEG4;
    // Optional H.264 encoder settings ranges (See also Extension element).
    std::optional<tt_H264Options> H264;
    std::optional<tt_VideoEncoderOptionsExtension> Extension;
    // Indicates the support for the GuaranteedFrameRate attribute on the VideoEncoderConfiguration element.
    std::optional<bool> GuaranteedFrameRateSupported;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoEncoderConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_VideoEncoderConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("QualityRange", &tt_VideoEncoderConfigurationOptions::QualityRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("JPEG", &tt_VideoEncoderConfigurationOptions::JPEG, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MPEG4", &tt_VideoEncoderConfigurationOptions::MPEG4, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("H264", &tt_VideoEncoderConfigurationOptions::H264, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_VideoEncoderConfigurationOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("GuaranteedFrameRateSupported", &tt_VideoEncoderConfigurationOptions::GuaranteedFrameRateSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_VideoEncoderConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoEncodingMimeNames 枚举类型
// 基础类型: std::string
enum class  tt_VideoEncodingMimeNames {
    JPEG,
    MPV4_ES, // MPV4-ES
    H264,
    H265
};

// 字符串转换函数
inline std::string to_string(tt_VideoEncodingMimeNames value) {
    switch (value) {
        case tt_VideoEncodingMimeNames::JPEG: return "JPEG";
        case tt_VideoEncodingMimeNames::MPV4_ES: return "MPV4-ES";
        case tt_VideoEncodingMimeNames::H264: return "H264";
        case tt_VideoEncodingMimeNames::H265: return "H265";
        default: return "";
    }
}

inline bool from_string(tt_VideoEncodingMimeNames& value, const std::string& str) {
    if (str == "JPEG") { value = tt_VideoEncodingMimeNames::JPEG; return true; }
    if (str == "MPV4-ES") { value = tt_VideoEncodingMimeNames::MPV4_ES; return true; }
    if (str == "H264") { value = tt_VideoEncodingMimeNames::H264; return true; }
    if (str == "H265") { value = tt_VideoEncodingMimeNames::H265; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_VideoEncodingMimeNames
template<>
struct xml_convert::XmlValueAdapter<tt_VideoEncodingMimeNames> {
    static bool from_xml_val(tt_VideoEncodingMimeNames& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_VideoEncodingMimeNames& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_VideoEncodingMimeNames
template<>
struct xml_convert::XmlAttributeAdapter<tt_VideoEncodingMimeNames> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_VideoEncodingMimeNames& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_VideoEncodingMimeNames& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// VideoEncodingProfiles 枚举类型
// 基础类型: std::string
enum class  tt_VideoEncodingProfiles {
    Simple,
    AdvancedSimple,
    Baseline,
    Main,
    Main10,
    Extended,
    High
};

// 字符串转换函数
inline std::string to_string(tt_VideoEncodingProfiles value) {
    switch (value) {
        case tt_VideoEncodingProfiles::Simple: return "Simple";
        case tt_VideoEncodingProfiles::AdvancedSimple: return "AdvancedSimple";
        case tt_VideoEncodingProfiles::Baseline: return "Baseline";
        case tt_VideoEncodingProfiles::Main: return "Main";
        case tt_VideoEncodingProfiles::Main10: return "Main10";
        case tt_VideoEncodingProfiles::Extended: return "Extended";
        case tt_VideoEncodingProfiles::High: return "High";
        default: return "";
    }
}

inline bool from_string(tt_VideoEncodingProfiles& value, const std::string& str) {
    if (str == "Simple") { value = tt_VideoEncodingProfiles::Simple; return true; }
    if (str == "AdvancedSimple") { value = tt_VideoEncodingProfiles::AdvancedSimple; return true; }
    if (str == "Baseline") { value = tt_VideoEncodingProfiles::Baseline; return true; }
    if (str == "Main") { value = tt_VideoEncodingProfiles::Main; return true; }
    if (str == "Main10") { value = tt_VideoEncodingProfiles::Main10; return true; }
    if (str == "Extended") { value = tt_VideoEncodingProfiles::Extended; return true; }
    if (str == "High") { value = tt_VideoEncodingProfiles::High; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_VideoEncodingProfiles
template<>
struct xml_convert::XmlValueAdapter<tt_VideoEncodingProfiles> {
    static bool from_xml_val(tt_VideoEncodingProfiles& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_VideoEncodingProfiles& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_VideoEncodingProfiles
template<>
struct xml_convert::XmlAttributeAdapter<tt_VideoEncodingProfiles> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_VideoEncodingProfiles& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_VideoEncodingProfiles& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// VideoResolution2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoResolution2 {
    // Number of the columns of the Video image. If there is a 90-degree rotation, this represents the number of lines of the Video image.
    int32_t Width {};
    // Number of the lines of the Video image. If there is a 90-degree rotation, this represents the number of columns of the Video image.
    int32_t Height {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoResolution2
template<>
struct xml_convert::XmlTraits<tt_VideoResolution2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Width", &tt_VideoResolution2::Width, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Height", &tt_VideoResolution2::Height, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoResolution2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_VideoResolution2::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoRateControl2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoRateControl2 {
    // Desired frame rate in fps. The actual rate may be lower due to e.g. performance limitations.
    float FrameRateLimit {};
    // the maximum output bitrate in kbps
    int32_t BitrateLimit {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Enforce constant bitrate.
    std::optional<bool> ConstantBitRate;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoRateControl2
template<>
struct xml_convert::XmlTraits<tt_VideoRateControl2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FrameRateLimit", &tt_VideoRateControl2::FrameRateLimit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BitrateLimit", &tt_VideoRateControl2::BitrateLimit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoRateControl2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("ConstantBitRate", &tt_VideoRateControl2::ConstantBitRate, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_VideoRateControl2::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoEncoder2Configuration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoEncoder2Configuration : public tt_ConfigurationEntity {
    // Video Media Subtype for the video format. For definitions see tt:VideoEncodingMimeNames and  IANA Media Types.
    std::string Encoding;
    // Configured video resolution
    tt_VideoResolution2 Resolution;
    // Optional element to configure rate control related parameters.
    std::optional<tt_VideoRateControl2> RateControl;
    // Defines the multicast settings that could be used for video streaming.
    std::optional<tt_MulticastConfiguration> Multicast;
    // Relative value for the video quantizers and the quality of the video. A high value within supported quality range means higher quality
    float Quality {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Group of Video frames length. Determines typically the interval in which the I-Frames will be coded. An entry of 1 indicates I-Frames are continuously generated. An entry of 2 indicates that every 2nd image is an I-Frame, and 3 only every 3rd frame, etc. The frames in between are coded as P or B Frames.
    std::optional<int32_t> GovLength;
    // Distance between anchor frames of type I-Frame and P-Frame. '1' indicates no B-Frames, '2' indicates that every 2nd frame is encoded as B-Frame, '3' indicates a structure like IBBPBBP..., etc.
    std::optional<int32_t> AnchorFrameDistance;
    // The encoder profile as defined in tt:VideoEncodingProfiles.
    std::optional<std::string> Profile;
    /*
     * A value of true indicates that frame rate is a fixed value rather than an upper limit,
     * and that the video encoder shall prioritize frame rate over all other adaptable
     * configuration values such as bitrate.  Default is false.
     */
    std::optional<bool> GuaranteedFrameRate;
    // Indicates if this stream will be signed according to the Media Signing Specification.
    std::optional<bool> Signed;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoEncoder2Configuration
template<>
struct xml_convert::XmlTraits<tt_VideoEncoder2Configuration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Encoding", &tt_VideoEncoder2Configuration::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Resolution", &tt_VideoEncoder2Configuration::Resolution, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RateControl", &tt_VideoEncoder2Configuration::RateControl, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Multicast", &tt_VideoEncoder2Configuration::Multicast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Quality", &tt_VideoEncoder2Configuration::Quality, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoEncoder2Configuration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("GovLength", &tt_VideoEncoder2Configuration::GovLength, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AnchorFrameDistance", &tt_VideoEncoder2Configuration::AnchorFrameDistance, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Profile", &tt_VideoEncoder2Configuration::Profile, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("GuaranteedFrameRate", &tt_VideoEncoder2Configuration::GuaranteedFrameRate, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Signed", &tt_VideoEncoder2Configuration::Signed, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_VideoEncoder2Configuration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// VideoEncoder2ConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoEncoder2ConfigurationOptions {
    // Video Media Subtype for the video format. For definitions see tt:VideoEncodingMimeNames and  IANA Media Types.
    std::string Encoding;
    // Range of the quality values. A high value means higher quality.
    tt_FloatRange QualityRange;
    // List of supported image sizes.
    std::vector<tt_VideoResolution2> ResolutionsAvailable;
    // Supported range of encoded bitrate in kbps.
    tt_IntRange BitrateRange;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Exactly two values, which define the Lower and Upper bounds for the supported group of Video frames length. These values typically correspond to the I-Frame distance.
    std::optional<tt_IntList> GovLengthRange;
    // Signals support for B-Frames. Upper bound for the supported anchor frame distance (must be larger than one).
    std::optional<int32_t> MaxAnchorFrameDistance;
    // List of supported target frame rates in fps (frames per second). The list shall be sorted with highest values first.
    std::optional<tt_FloatList> FrameRatesSupported;
    // List of supported encoder profiles as defined in tt::VideoEncodingProfiles.
    std::optional<tt_StringAttrList> ProfilesSupported;
    // Signal whether enforcing constant bitrate is supported.
    std::optional<bool> ConstantBitRateSupported;
    // Indicates the support for the GuaranteedFrameRate attribute on the VideoEncoder2Configuration element.
    std::optional<bool> GuaranteedFrameRateSupported;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoEncoder2ConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_VideoEncoder2ConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Encoding", &tt_VideoEncoder2ConfigurationOptions::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("QualityRange", &tt_VideoEncoder2ConfigurationOptions::QualityRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ResolutionsAvailable", &tt_VideoEncoder2ConfigurationOptions::ResolutionsAvailable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BitrateRange", &tt_VideoEncoder2ConfigurationOptions::BitrateRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoEncoder2ConfigurationOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("GovLengthRange", &tt_VideoEncoder2ConfigurationOptions::GovLengthRange, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxAnchorFrameDistance", &tt_VideoEncoder2ConfigurationOptions::MaxAnchorFrameDistance, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("FrameRatesSupported", &tt_VideoEncoder2ConfigurationOptions::FrameRatesSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("ProfilesSupported", &tt_VideoEncoder2ConfigurationOptions::ProfilesSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("ConstantBitRateSupported", &tt_VideoEncoder2ConfigurationOptions::ConstantBitRateSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("GuaranteedFrameRateSupported", &tt_VideoEncoder2ConfigurationOptions::GuaranteedFrameRateSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_VideoEncoder2ConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioSourceOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioSourceOptionsExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_AudioSourceOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_AudioSourceOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AudioSourceOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// AudioSourceConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioSourceConfigurationOptions {
    // Tokens of the audio source the configuration can be used for.
    std::vector<tt_ReferenceToken> InputTokensAvailable;
    std::optional<tt_AudioSourceOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioSourceConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_AudioSourceConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("InputTokensAvailable", &tt_AudioSourceConfigurationOptions::InputTokensAvailable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_AudioSourceConfigurationOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_AudioSourceConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioEncoderConfigurationOption 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioEncoderConfigurationOption {
    // The enoding used for audio data (either G.711, G.726 or AAC)
    tt_AudioEncoding Encoding;
    // List of supported bitrates in kbps for the specified Encoding
    tt_IntItems BitrateList;
    // List of supported Sample Rates in kHz for the specified Encoding
    tt_IntItems SampleRateList;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioEncoderConfigurationOption
template<>
struct xml_convert::XmlTraits<tt_AudioEncoderConfigurationOption> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Encoding", &tt_AudioEncoderConfigurationOption::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BitrateList", &tt_AudioEncoderConfigurationOption::BitrateList, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SampleRateList", &tt_AudioEncoderConfigurationOption::SampleRateList, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioEncoderConfigurationOption::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioEncoderConfigurationOption::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioEncoderConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioEncoderConfigurationOptions {
    // list of supported AudioEncoderConfigurations
    std::vector<tt_AudioEncoderConfigurationOption> Options;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioEncoderConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_AudioEncoderConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tt_AudioEncoderConfigurationOptions::Options, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_AudioEncoderConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioEncodingMimeNames 枚举类型
// 基础类型: std::string
enum class  tt_AudioEncodingMimeNames {
    PCMU,
    G726,
    MP4A_LATM, // MP4A-LATM
    mpeg4_generic // mpeg4-generic
};

// 字符串转换函数
inline std::string to_string(tt_AudioEncodingMimeNames value) {
    switch (value) {
        case tt_AudioEncodingMimeNames::PCMU: return "PCMU";
        case tt_AudioEncodingMimeNames::G726: return "G726";
        case tt_AudioEncodingMimeNames::MP4A_LATM: return "MP4A-LATM";
        case tt_AudioEncodingMimeNames::mpeg4_generic: return "mpeg4-generic";
        default: return "";
    }
}

inline bool from_string(tt_AudioEncodingMimeNames& value, const std::string& str) {
    if (str == "PCMU") { value = tt_AudioEncodingMimeNames::PCMU; return true; }
    if (str == "G726") { value = tt_AudioEncodingMimeNames::G726; return true; }
    if (str == "MP4A-LATM") { value = tt_AudioEncodingMimeNames::MP4A_LATM; return true; }
    if (str == "mpeg4-generic") { value = tt_AudioEncodingMimeNames::mpeg4_generic; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_AudioEncodingMimeNames
template<>
struct xml_convert::XmlValueAdapter<tt_AudioEncodingMimeNames> {
    static bool from_xml_val(tt_AudioEncodingMimeNames& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_AudioEncodingMimeNames& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_AudioEncodingMimeNames
template<>
struct xml_convert::XmlAttributeAdapter<tt_AudioEncodingMimeNames> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_AudioEncodingMimeNames& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_AudioEncodingMimeNames& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// AudioEncoder2Configuration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioEncoder2Configuration : public tt_ConfigurationEntity {
    // Audio Media Subtype for the audio format. For definitions see tt:AudioEncodingMimeNames and  IANA Media Types.
    std::string Encoding;
    // Optional multicast configuration of the audio stream.
    std::optional<tt_MulticastConfiguration> Multicast;
    // The output bitrate in kbps.
    int32_t Bitrate {};
    // The output sample rate in kHz.
    int32_t SampleRate {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioEncoder2Configuration
template<>
struct xml_convert::XmlTraits<tt_AudioEncoder2Configuration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Encoding", &tt_AudioEncoder2Configuration::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Multicast", &tt_AudioEncoder2Configuration::Multicast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Bitrate", &tt_AudioEncoder2Configuration::Bitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SampleRate", &tt_AudioEncoder2Configuration::SampleRate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioEncoder2Configuration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioEncoder2Configuration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// AudioEncoder2ConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioEncoder2ConfigurationOptions {
    // Audio Media Subtype for the audio format. For definitions see tt:AudioEncodingMimeNames and  IANA Media Types.
    std::string Encoding;
    // List of supported bitrates in kbps for the specified Encoding
    tt_IntItems BitrateList;
    // List of supported Sample Rates in kHz for the specified Encoding
    tt_IntItems SampleRateList;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioEncoder2ConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_AudioEncoder2ConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Encoding", &tt_AudioEncoder2ConfigurationOptions::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BitrateList", &tt_AudioEncoder2ConfigurationOptions::BitrateList, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SampleRateList", &tt_AudioEncoder2ConfigurationOptions::SampleRateList, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioEncoder2ConfigurationOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioEncoder2ConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZStatusFilterOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZStatusFilterOptionsExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZStatusFilterOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_PTZStatusFilterOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZStatusFilterOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZStatusFilterOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZStatusFilterOptions {
    // True if the device is able to stream pan or tilt status information.
    bool PanTiltStatusSupported {};
    // True if the device is able to stream zoom status inforamtion.
    bool ZoomStatusSupported {};
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // True if the device is able to stream the pan or tilt position.
    std::optional<bool> PanTiltPositionSupported;
    // True if the device is able to stream zoom position information.
    std::optional<bool> ZoomPositionSupported;
    std::optional<tt_PTZStatusFilterOptionsExtension> Extension;
    // True if the device is able to stream the field-of-view information.
    std::optional<bool> FieldOfViewSupported;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZStatusFilterOptions
template<>
struct xml_convert::XmlTraits<tt_PTZStatusFilterOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PanTiltStatusSupported", &tt_PTZStatusFilterOptions::PanTiltStatusSupported, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ZoomStatusSupported", &tt_PTZStatusFilterOptions::ZoomStatusSupported, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PTZStatusFilterOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("PanTiltPositionSupported", &tt_PTZStatusFilterOptions::PanTiltPositionSupported, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ZoomPositionSupported", &tt_PTZStatusFilterOptions::ZoomPositionSupported, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZStatusFilterOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FieldOfViewSupported", &tt_PTZStatusFilterOptions::FieldOfViewSupported, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PTZStatusFilterOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MetadataConfigurationOptionsExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MetadataConfigurationOptionsExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_MetadataConfigurationOptionsExtension2
template<>
struct xml_convert::XmlTraits<tt_MetadataConfigurationOptionsExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_MetadataConfigurationOptionsExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// MetadataConfigurationOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MetadataConfigurationOptionsExtension {
    // List of supported metadata compression type. Its options shall be chosen from tt:MetadataCompressionType.
    std::vector<std::string> CompressionType;
    std::optional<tt_MetadataConfigurationOptionsExtension2> Extension;
};


// XmlTraits for tt_MetadataConfigurationOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_MetadataConfigurationOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CompressionType", &tt_MetadataConfigurationOptionsExtension::CompressionType, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_MetadataConfigurationOptionsExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// MetadataConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MetadataConfigurationOptions {
    tt_PTZStatusFilterOptions PTZStatusFilterOptions;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<tt_MetadataConfigurationOptionsExtension> Extension;
    // True if the device is able to stream the Geo Located positions of each target.
    std::optional<bool> GeoLocation;
    // A device signalling support for content filtering shall support expressions with the provided expression size.
    std::optional<int32_t> MaxContentFilterSize;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MetadataConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_MetadataConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PTZStatusFilterOptions", &tt_MetadataConfigurationOptions::PTZStatusFilterOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MetadataConfigurationOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Extension", &tt_MetadataConfigurationOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("GeoLocation", &tt_MetadataConfigurationOptions::GeoLocation, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxContentFilterSize", &tt_MetadataConfigurationOptions::MaxContentFilterSize, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_MetadataConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MetadataCompressionType 枚举类型
// 基础类型: std::string
enum class  tt_MetadataCompressionType {
    None,
    GZIP,
    EXI
};

// 字符串转换函数
inline std::string to_string(tt_MetadataCompressionType value) {
    switch (value) {
        case tt_MetadataCompressionType::None: return "None";
        case tt_MetadataCompressionType::GZIP: return "GZIP";
        case tt_MetadataCompressionType::EXI: return "EXI";
        default: return "";
    }
}

inline bool from_string(tt_MetadataCompressionType& value, const std::string& str) {
    if (str == "None") { value = tt_MetadataCompressionType::None; return true; }
    if (str == "GZIP") { value = tt_MetadataCompressionType::GZIP; return true; }
    if (str == "EXI") { value = tt_MetadataCompressionType::EXI; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_MetadataCompressionType
template<>
struct xml_convert::XmlValueAdapter<tt_MetadataCompressionType> {
    static bool from_xml_val(tt_MetadataCompressionType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_MetadataCompressionType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_MetadataCompressionType
template<>
struct xml_convert::XmlAttributeAdapter<tt_MetadataCompressionType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_MetadataCompressionType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_MetadataCompressionType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// PaneLayout 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PaneLayout {
    // Reference to the configuration of the streaming and coding parameters.
    tt_ReferenceToken Pane;
    // Describes the location and size of the area on the monitor. The area coordinate values are espressed in normalized units [-1.0, 1.0].
    tt_Rectangle Area;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PaneLayout
template<>
struct xml_convert::XmlTraits<tt_PaneLayout> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Pane", &tt_PaneLayout::Pane, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Area", &tt_PaneLayout::Area, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PaneLayout::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_PaneLayout::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// LayoutExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_LayoutExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_LayoutExtension
template<>
struct xml_convert::XmlTraits<tt_LayoutExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_LayoutExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Layout 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Layout {
    // List of panes assembling the display layout.
    std::vector<tt_PaneLayout> PaneLayout;
    std::optional<tt_LayoutExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Layout
template<>
struct xml_convert::XmlTraits<tt_Layout> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PaneLayout", &tt_Layout::PaneLayout, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Layout::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_Layout::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoOutputExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoOutputExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_VideoOutputExtension
template<>
struct xml_convert::XmlTraits<tt_VideoOutputExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_VideoOutputExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// VideoOutput 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoOutput : public tt_DeviceEntity {
    tt_Layout Layout;
    // Resolution of the display in Pixel.
    std::optional<tt_VideoResolution> Resolution;
    // Refresh rate of the display in Hertz.
    std::optional<float> RefreshRate;
    // Aspect ratio of the display as physical extent of width divided by height.
    std::optional<float> AspectRatio;
    std::optional<tt_VideoOutputExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoOutput
template<>
struct xml_convert::XmlTraits<tt_VideoOutput> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_DeviceEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Layout", &tt_VideoOutput::Layout, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Resolution", &tt_VideoOutput::Resolution, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RefreshRate", &tt_VideoOutput::RefreshRate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AspectRatio", &tt_VideoOutput::AspectRatio, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_VideoOutput::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_VideoOutput::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// VideoOutputConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoOutputConfiguration : public tt_ConfigurationEntity {
    // Token of the Video Output the configuration applies to
    tt_ReferenceToken OutputToken;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoOutputConfiguration
template<>
struct xml_convert::XmlTraits<tt_VideoOutputConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("OutputToken", &tt_VideoOutputConfiguration::OutputToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoOutputConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_VideoOutputConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// VideoOutputConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoOutputConfigurationOptions {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoOutputConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_VideoOutputConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_VideoOutputConfigurationOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_VideoOutputConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// JpegDecOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_JpegDecOptions {
    // List of supported Jpeg Video Resolutions
    std::vector<tt_VideoResolution> ResolutionsAvailable;
    // Supported Jpeg bitrate range in kbps
    tt_IntRange SupportedInputBitrate;
    // Supported Jpeg framerate range in fps
    tt_IntRange SupportedFrameRate;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_JpegDecOptions
template<>
struct xml_convert::XmlTraits<tt_JpegDecOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ResolutionsAvailable", &tt_JpegDecOptions::ResolutionsAvailable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedInputBitrate", &tt_JpegDecOptions::SupportedInputBitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedFrameRate", &tt_JpegDecOptions::SupportedFrameRate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_JpegDecOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_JpegDecOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// H264DecOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_H264DecOptions {
    // List of supported H.264 Video Resolutions
    std::vector<tt_VideoResolution> ResolutionsAvailable;
    // List of supported H264 Profiles (either baseline, main, extended or high)
    std::vector<tt_H264Profile> SupportedH264Profiles;
    // Supported H.264 bitrate range in kbps
    tt_IntRange SupportedInputBitrate;
    // Supported H.264 framerate range in fps
    tt_IntRange SupportedFrameRate;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_H264DecOptions
template<>
struct xml_convert::XmlTraits<tt_H264DecOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ResolutionsAvailable", &tt_H264DecOptions::ResolutionsAvailable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedH264Profiles", &tt_H264DecOptions::SupportedH264Profiles, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedInputBitrate", &tt_H264DecOptions::SupportedInputBitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedFrameRate", &tt_H264DecOptions::SupportedFrameRate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_H264DecOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_H264DecOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Mpeg4DecOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Mpeg4DecOptions {
    // List of supported Mpeg4 Video Resolutions
    std::vector<tt_VideoResolution> ResolutionsAvailable;
    // List of supported Mpeg4 Profiles (either SP or ASP)
    std::vector<tt_Mpeg4Profile> SupportedMpeg4Profiles;
    // Supported Mpeg4 bitrate range in kbps
    tt_IntRange SupportedInputBitrate;
    // Supported Mpeg4 framerate range in fps
    tt_IntRange SupportedFrameRate;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Mpeg4DecOptions
template<>
struct xml_convert::XmlTraits<tt_Mpeg4DecOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ResolutionsAvailable", &tt_Mpeg4DecOptions::ResolutionsAvailable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedMpeg4Profiles", &tt_Mpeg4DecOptions::SupportedMpeg4Profiles, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedInputBitrate", &tt_Mpeg4DecOptions::SupportedInputBitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedFrameRate", &tt_Mpeg4DecOptions::SupportedFrameRate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Mpeg4DecOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Mpeg4DecOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoDecoderConfigurationOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoDecoderConfigurationOptionsExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_VideoDecoderConfigurationOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_VideoDecoderConfigurationOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_VideoDecoderConfigurationOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// VideoDecoderConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoDecoderConfigurationOptions {
    // If the device is able to decode Jpeg streams this element describes the supported codecs and configurations
    std::optional<tt_JpegDecOptions> JpegDecOptions;
    // If the device is able to decode H.264 streams this element describes the supported codecs and configurations
    std::optional<tt_H264DecOptions> H264DecOptions;
    // If the device is able to decode Mpeg4 streams this element describes the supported codecs and configurations
    std::optional<tt_Mpeg4DecOptions> Mpeg4DecOptions;
    std::optional<tt_VideoDecoderConfigurationOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoDecoderConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_VideoDecoderConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JpegDecOptions", &tt_VideoDecoderConfigurationOptions::JpegDecOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("H264DecOptions", &tt_VideoDecoderConfigurationOptions::H264DecOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mpeg4DecOptions", &tt_VideoDecoderConfigurationOptions::Mpeg4DecOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_VideoDecoderConfigurationOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_VideoDecoderConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioOutput 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioOutput : public tt_DeviceEntity {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioOutput
template<>
struct xml_convert::XmlTraits<tt_AudioOutput> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_DeviceEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AudioOutput::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioOutput::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// FrequencyDecibelPair 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FrequencyDecibelPair {
    // The center frequency of the band in hertz (Readonly). For example, value of 1000 refers to 1kHz and 2000 refers to 2kHz.
    int32_t CenterFrequency {};
    // Decibel value associated with the center frequency.
    float Decibel {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_FrequencyDecibelPair
template<>
struct xml_convert::XmlTraits<tt_FrequencyDecibelPair> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CenterFrequency", &tt_FrequencyDecibelPair::CenterFrequency, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Decibel", &tt_FrequencyDecibelPair::Decibel, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_FrequencyDecibelPair::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// EQPreset 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_EQPreset {
    // Unique identifier for the preset.
    tt_ReferenceToken Token;
    // Preset name. (Readonly)
    std::string Name;
    // This indicates whether the EQ preset is designated as the default. When the scheduler is inactive, this preset will be applied. Only one preset can be set as the default among the EQ presets linked to an audio output. If all presets have isDefault set to false, the device may automatically select one preset as the default.
    bool isDefault {};
    // Optional schedule token (if supported).
    std::optional<std::string> ScheduleToken;
    // Indicates whether the device allows changing the decibel level for frequencies. (Readonly)
    bool isFrequencyDecibelEditable {};
    // List of frequency decibel pairs, each defined by a center frequency and its corresponding decibel value.
    std::vector<tt_FrequencyDecibelPair> FrequencyDecibelPair;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_EQPreset
template<>
struct xml_convert::XmlTraits<tt_EQPreset> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tt_EQPreset::Token, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Name", &tt_EQPreset::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("isDefault", &tt_EQPreset::isDefault, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ScheduleToken", &tt_EQPreset::ScheduleToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("isFrequencyDecibelEditable", &tt_EQPreset::isFrequencyDecibelEditable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FrequencyDecibelPair", &tt_EQPreset::FrequencyDecibelPair, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_EQPreset::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// AudioOutputConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioOutputConfigurationOptions {
    // Tokens of the physical Audio outputs (typically one).
    std::vector<tt_ReferenceToken> OutputTokensAvailable;
    /*
     * An audio channel MAY support different types of audio transmission. While for full duplex
     * operation no special handling is required, in half duplex operation the transmission direction
     * needs to be switched.
     * The optional SendPrimacy parameter inside the AudioOutputConfiguration indicates which
     * direction is currently active. An NVC can switch between different modes by setting the
     * AudioOutputConfiguration.
     * The following modes for the Send-Primacy are defined:
     * www.onvif.org/ver20/HalfDuplex/Server
     * The server is allowed to send audio data to the client. The client shall not send
     * audio data via the backchannel to the NVT in this mode.
     * www.onvif.org/ver20/HalfDuplex/Client
     * The client is allowed to send audio data via the backchannel to the server. The
     * NVT shall not send audio data to the client in this mode.
     * www.onvif.org/ver20/HalfDuplex/Auto
     * It is up to the device how to deal with sending and receiving audio data.
     *
     * Acoustic echo cancellation is out of ONVIF scope.
     */
    std::vector<std::string> SendPrimacyOptions;
    // Minimum and maximum level range supported for this Output.
    tt_IntRange OutputLevelRange;
    // Indicates whether EQPreset scheduling is supported.
    std::optional<bool> EQPresetScheduleSupport;
    // List of supported EQPresets.
    std::vector<tt_EQPreset> EQPresets;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioOutputConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_AudioOutputConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("OutputTokensAvailable", &tt_AudioOutputConfigurationOptions::OutputTokensAvailable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SendPrimacyOptions", &tt_AudioOutputConfigurationOptions::SendPrimacyOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("OutputLevelRange", &tt_AudioOutputConfigurationOptions::OutputLevelRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EQPresetScheduleSupport", &tt_AudioOutputConfigurationOptions::EQPresetScheduleSupport, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EQPresets", &tt_AudioOutputConfigurationOptions::EQPresets, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioOutputConfigurationOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioOutputConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AACDecOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AACDecOptions {
    // List of supported bitrates in kbps
    tt_IntItems Bitrate;
    // List of supported sample rates in kHz
    tt_IntItems SampleRateRange;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AACDecOptions
template<>
struct xml_convert::XmlTraits<tt_AACDecOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Bitrate", &tt_AACDecOptions::Bitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SampleRateRange", &tt_AACDecOptions::SampleRateRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AACDecOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AACDecOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// G711DecOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_G711DecOptions {
    // List of supported bitrates in kbps
    tt_IntItems Bitrate;
    // List of supported sample rates in kHz
    tt_IntItems SampleRateRange;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_G711DecOptions
template<>
struct xml_convert::XmlTraits<tt_G711DecOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Bitrate", &tt_G711DecOptions::Bitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SampleRateRange", &tt_G711DecOptions::SampleRateRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_G711DecOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_G711DecOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// G726DecOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_G726DecOptions {
    // List of supported bitrates in kbps
    tt_IntItems Bitrate;
    // List of supported sample rates in kHz
    tt_IntItems SampleRateRange;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_G726DecOptions
template<>
struct xml_convert::XmlTraits<tt_G726DecOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Bitrate", &tt_G726DecOptions::Bitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SampleRateRange", &tt_G726DecOptions::SampleRateRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_G726DecOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_G726DecOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioDecoderConfigurationOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioDecoderConfigurationOptionsExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_AudioDecoderConfigurationOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_AudioDecoderConfigurationOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AudioDecoderConfigurationOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// AudioDecoderConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioDecoderConfigurationOptions {
    // If the device is able to decode AAC encoded audio this section describes the supported configurations
    std::optional<tt_AACDecOptions> AACDecOptions;
    // If the device is able to decode G711 encoded audio this section describes the supported configurations
    std::optional<tt_G711DecOptions> G711DecOptions;
    // If the device is able to decode G726 encoded audio this section describes the supported configurations
    std::optional<tt_G726DecOptions> G726DecOptions;
    std::optional<tt_AudioDecoderConfigurationOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioDecoderConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_AudioDecoderConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AACDecOptions", &tt_AudioDecoderConfigurationOptions::AACDecOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("G711DecOptions", &tt_AudioDecoderConfigurationOptions::G711DecOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("G726DecOptions", &tt_AudioDecoderConfigurationOptions::G726DecOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_AudioDecoderConfigurationOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_AudioDecoderConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MulticastReceiverConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MulticastReceiverConfiguration {
    // The multicast address (if this address is set to 0 no multicast streaming is enabled)
    tt_IPAddress Address;
    // The RTP multicast destination port. A device may support RTCP. In this case the port value shall be even to allow the corresponding RTCP stream to be mapped to the next higher (odd) destination port number as defined in the RTSP specification.
    int32_t Port {};
    // In case of IPv6 the TTL value is assumed as the hop limit. Note that for IPV6 and administratively scoped IPv4 multicast the primary use for hop limit / TTL is to prevent packets from (endlessly) circulating and not limiting scope. In these cases the address contains the scope.
    int32_t TTL {};
    // Unique identifier of the network interface on the device. If not specified, all available interfaces will be used for listening.
    std::vector<tt_ReferenceToken> InterfaceToken;
    // When a source-specific multicast address is configured, the device will process multicast data only from the specified source, in accordance with SSM principles defined in RFC 4607.
    std::optional<tt_IPAddress> SourceSpecificMulticast;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MulticastReceiverConfiguration
template<>
struct xml_convert::XmlTraits<tt_MulticastReceiverConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Address", &tt_MulticastReceiverConfiguration::Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Port", &tt_MulticastReceiverConfiguration::Port, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TTL", &tt_MulticastReceiverConfiguration::TTL, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("InterfaceToken", &tt_MulticastReceiverConfiguration::InterfaceToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SourceSpecificMulticast", &tt_MulticastReceiverConfiguration::SourceSpecificMulticast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MulticastReceiverConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_MulticastReceiverConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SRTPPreShared 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SRTPPreShared {
    /*
     * An optional SRTP Pre-Shared Key (PSK) represented as a hexadecimal string.
     * This includes both the SRTP master key, followed by the master salt.
     * The sizes of the key and salt depend on the specified SRTPCryptoPolicy.
     * When this element is specified, RTP packets shall be encrypted.
     * The SRTPPSK shall never be returned on a get method.
     */
    std::string SRTPPSK;
    /*
     * Specifies the cryptographic algorithm when using SRTP,
     * selecting from predefined values provided in the GetMulticastAudioDecoderConfigurationOptions response.
     */
    std::string SecureStreamingProtocolAlgorithm;
    /*
     * The RTP header extension ID (ExtMapID) used to identify the ROC extension, as defined in RFC 8285.
     * Valid values are 1 to 14 for one-byte header extensions.
     */
    int32_t ROCExtMapID {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SRTPPreShared
template<>
struct xml_convert::XmlTraits<tt_SRTPPreShared> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SRTPPSK", &tt_SRTPPreShared::SRTPPSK, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SecureStreamingProtocolAlgorithm", &tt_SRTPPreShared::SecureStreamingProtocolAlgorithm, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ROCExtMapID", &tt_SRTPPreShared::ROCExtMapID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_SRTPPreShared::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_SRTPPreShared::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MulticastAudioDecoderConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MulticastAudioDecoderConfiguration : public tt_ConfigurationEntity {
    // Indicates whether the Multicast Audio Decoder is enabled or disabled.
    bool Enable {};
    // Token of the physical Audio output. This element is optional and can occur multiple times.
    std::vector<tt_ReferenceToken> AudioOutputToken;
    // Specifies the encoding type according to IANA media types.
    std::string Encoding;
    // The bitrate of the audio stream in bits per second.
    int32_t Bitrate {};
    // The sampling rate of the audio stream in kHz.
    int32_t SamplingRate {};
    // Contains configuration details for multicast settings.
    tt_MulticastReceiverConfiguration Multicast;
    /*
     * Defines the RTP payload type used for the audio stream.
     * To ensure compatibility, it is recommended to use dynamic payload types (96 and above), as specified in RFC 3551.
     * Standard payload types (0-95) should only be used for predefined audio formats matching the audio encoding as defined in
     * IANA RTP Payload Types,
     * as using them for non-standard media may lead to unexpected errors or interoperability issues.
     */
    int32_t RTPPayloadType {};
    /*
     * Indicates the priority level when multiple configurations are active.
     * A higher value signifies a higher priority. If several configurations have the same priority value the order between those configurations is undefined.
     */
    int32_t Priority {};
    /*
     * Optional media format parameters as specified in SDP, such as:
     * a=fmtp:101 stereo=1; sprop-stereo=1.
     */
    std::optional<std::string> MediaFormatParameters;
    // Optional configuration parameters for SRTP pre-shared key usage, applicable when SRTP is supported. When this configuration is present, RTP packets shall be encrypted.
    std::optional<tt_SRTPPreShared> SRTPPreSharedParameters;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MulticastAudioDecoderConfiguration
template<>
struct xml_convert::XmlTraits<tt_MulticastAudioDecoderConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Enable", &tt_MulticastAudioDecoderConfiguration::Enable, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioOutputToken", &tt_MulticastAudioDecoderConfiguration::AudioOutputToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Encoding", &tt_MulticastAudioDecoderConfiguration::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Bitrate", &tt_MulticastAudioDecoderConfiguration::Bitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SamplingRate", &tt_MulticastAudioDecoderConfiguration::SamplingRate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Multicast", &tt_MulticastAudioDecoderConfiguration::Multicast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RTPPayloadType", &tt_MulticastAudioDecoderConfiguration::RTPPayloadType, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Priority", &tt_MulticastAudioDecoderConfiguration::Priority, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MediaFormatParameters", &tt_MulticastAudioDecoderConfiguration::MediaFormatParameters, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SRTPPreSharedParameters", &tt_MulticastAudioDecoderConfiguration::SRTPPreSharedParameters, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MulticastAudioDecoderConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_MulticastAudioDecoderConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// AudioDecoder2Options 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioDecoder2Options {
    // Audio Media Subtype for the audio format. For definitions see tt:AudioEncodingMimeNames and  IANA Media Types.
    std::string Encoding;
    // List of supported bitrates in kbps for the specified Encoding
    tt_IntItems BitrateList;
    // List of supported Sample Rates in kHz for the specified Encoding
    tt_IntItems SampleRateList;
    /*
     * Optional element for specifying the RTP payload type,
     * particularly when it is fixed for a specific audio encoding as defined in IANA RTP Payload Types.
     */
    std::optional<int32_t> RTPPayloadType;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioDecoder2Options
template<>
struct xml_convert::XmlTraits<tt_AudioDecoder2Options> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Encoding", &tt_AudioDecoder2Options::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BitrateList", &tt_AudioDecoder2Options::BitrateList, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SampleRateList", &tt_AudioDecoder2Options::SampleRateList, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RTPPayloadType", &tt_AudioDecoder2Options::RTPPayloadType, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioDecoder2Options::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioDecoder2Options::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MulticastAudioDecoderConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MulticastAudioDecoderConfigurationOptions {
    // Supported encoding options for the multicast audio decoder.
    tt_AudioDecoder2Options EncodingOptions;
    // Specifies the priority range as an integer. This indicates the priority level for audio configuration.
    tt_IntRange PriorityRange;
    /*
     * An optional parameter specifies the list of supported cryptographic algorithms when SRTP support is signaled as 'true' in the GetServiceCapabilitiesResponse.
     * Refer to tt:SrtpSecurityAlgorithms for the acceptable values.
     */
    std::optional<tt_StringList> SecureStreamingProtocolAlgorithms;
    // Optional list of physical Audio output tokens. This element is used when only certain audio outputs can be configured for this token.
    std::optional<tt_StringList> AudioOutputTokens;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MulticastAudioDecoderConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_MulticastAudioDecoderConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("EncodingOptions", &tt_MulticastAudioDecoderConfigurationOptions::EncodingOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PriorityRange", &tt_MulticastAudioDecoderConfigurationOptions::PriorityRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SecureStreamingProtocolAlgorithms", &tt_MulticastAudioDecoderConfigurationOptions::SecureStreamingProtocolAlgorithms, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioOutputTokens", &tt_MulticastAudioDecoderConfigurationOptions::AudioOutputTokens, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MulticastAudioDecoderConfigurationOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_MulticastAudioDecoderConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// StreamType 枚举类型
// 基础类型: std::string
enum class  tt_StreamType {
    RTP_Unicast, // RTP-Unicast
    RTP_Multicast // RTP-Multicast
};

// 字符串转换函数
inline std::string to_string(tt_StreamType value) {
    switch (value) {
        case tt_StreamType::RTP_Unicast: return "RTP-Unicast";
        case tt_StreamType::RTP_Multicast: return "RTP-Multicast";
        default: return "";
    }
}

inline bool from_string(tt_StreamType& value, const std::string& str) {
    if (str == "RTP-Unicast") { value = tt_StreamType::RTP_Unicast; return true; }
    if (str == "RTP-Multicast") { value = tt_StreamType::RTP_Multicast; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_StreamType
template<>
struct xml_convert::XmlValueAdapter<tt_StreamType> {
    static bool from_xml_val(tt_StreamType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_StreamType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_StreamType
template<>
struct xml_convert::XmlAttributeAdapter<tt_StreamType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_StreamType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_StreamType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// TransportProtocol 枚举类型
// 基础类型: std::string
enum class  tt_TransportProtocol {
    UDP,
    TCP,
    RTSP,
    HTTP
};

// 字符串转换函数
inline std::string to_string(tt_TransportProtocol value) {
    switch (value) {
        case tt_TransportProtocol::UDP: return "UDP";
        case tt_TransportProtocol::TCP: return "TCP";
        case tt_TransportProtocol::RTSP: return "RTSP";
        case tt_TransportProtocol::HTTP: return "HTTP";
        default: return "";
    }
}

inline bool from_string(tt_TransportProtocol& value, const std::string& str) {
    if (str == "UDP") { value = tt_TransportProtocol::UDP; return true; }
    if (str == "TCP") { value = tt_TransportProtocol::TCP; return true; }
    if (str == "RTSP") { value = tt_TransportProtocol::RTSP; return true; }
    if (str == "HTTP") { value = tt_TransportProtocol::HTTP; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_TransportProtocol
template<>
struct xml_convert::XmlValueAdapter<tt_TransportProtocol> {
    static bool from_xml_val(tt_TransportProtocol& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_TransportProtocol& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_TransportProtocol
template<>
struct xml_convert::XmlAttributeAdapter<tt_TransportProtocol> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_TransportProtocol& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_TransportProtocol& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Transport 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Transport {
    // Defines the network protocol for streaming, either UDP=RTP/UDP, RTSP=RTP/RTSP/TCP or HTTP=RTP/RTSP/HTTP/TCP
    tt_TransportProtocol Protocol;
    // Optional element to describe further tunnel options. This element is normally not needed
    std::unique_ptr<tt_Transport> Tunnel;
};


// XmlTraits for tt_Transport
template<>
struct xml_convert::XmlTraits<tt_Transport> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Protocol", &tt_Transport::Protocol, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Tunnel", &tt_Transport::Tunnel, "tt", xml_convert::serialize_type::full)
    );
};


// StreamSetup 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_StreamSetup {
    // Defines if a multicast or unicast stream is requested
    tt_StreamType Stream;
    tt_Transport Transport;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_StreamSetup
template<>
struct xml_convert::XmlTraits<tt_StreamSetup> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Stream", &tt_StreamSetup::Stream, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Transport", &tt_StreamSetup::Transport, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_StreamSetup::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_StreamSetup::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MediaUri 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MediaUri {
    // Stable Uri to be used for requesting the media stream
    std::string Uri;
    // Indicates if the Uri is only valid until the connection is established. The value shall be set to "false".
    bool InvalidAfterConnect {};
    // Indicates if the Uri is invalid after a reboot of the device. The value shall be set to "false".
    bool InvalidAfterReboot {};
    // Duration how long the Uri is valid. This parameter shall be set to PT0S to indicate that this stream URI is indefinitely valid even if the profile changes
    my_Duration Timeout;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MediaUri
template<>
struct xml_convert::XmlTraits<tt_MediaUri> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Uri", &tt_MediaUri::Uri, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("InvalidAfterConnect", &tt_MediaUri::InvalidAfterConnect, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("InvalidAfterReboot", &tt_MediaUri::InvalidAfterReboot, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Timeout", &tt_MediaUri::Timeout, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MediaUri::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_MediaUri::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ScopeDefinition 枚举类型
// 基础类型: std::string
enum class  tt_ScopeDefinition {
    Fixed,
    Configurable
};

// 字符串转换函数
inline std::string to_string(tt_ScopeDefinition value) {
    switch (value) {
        case tt_ScopeDefinition::Fixed: return "Fixed";
        case tt_ScopeDefinition::Configurable: return "Configurable";
        default: return "";
    }
}

inline bool from_string(tt_ScopeDefinition& value, const std::string& str) {
    if (str == "Fixed") { value = tt_ScopeDefinition::Fixed; return true; }
    if (str == "Configurable") { value = tt_ScopeDefinition::Configurable; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ScopeDefinition
template<>
struct xml_convert::XmlValueAdapter<tt_ScopeDefinition> {
    static bool from_xml_val(tt_ScopeDefinition& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ScopeDefinition& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ScopeDefinition
template<>
struct xml_convert::XmlAttributeAdapter<tt_ScopeDefinition> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ScopeDefinition& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ScopeDefinition& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Scope 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Scope {
    // Indicates if the scope is fixed or configurable.
    tt_ScopeDefinition ScopeDef;
    // Scope item URI.
    std::string ScopeItem;
};


// XmlTraits for tt_Scope
template<>
struct xml_convert::XmlTraits<tt_Scope> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ScopeDef", &tt_Scope::ScopeDef, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ScopeItem", &tt_Scope::ScopeItem, "tt", xml_convert::serialize_type::full)
    );
};


// DiscoveryMode 枚举类型
// 基础类型: std::string
enum class  tt_DiscoveryMode {
    Discoverable,
    NonDiscoverable
};

// 字符串转换函数
inline std::string to_string(tt_DiscoveryMode value) {
    switch (value) {
        case tt_DiscoveryMode::Discoverable: return "Discoverable";
        case tt_DiscoveryMode::NonDiscoverable: return "NonDiscoverable";
        default: return "";
    }
}

inline bool from_string(tt_DiscoveryMode& value, const std::string& str) {
    if (str == "Discoverable") { value = tt_DiscoveryMode::Discoverable; return true; }
    if (str == "NonDiscoverable") { value = tt_DiscoveryMode::NonDiscoverable; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_DiscoveryMode
template<>
struct xml_convert::XmlValueAdapter<tt_DiscoveryMode> {
    static bool from_xml_val(tt_DiscoveryMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_DiscoveryMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_DiscoveryMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_DiscoveryMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_DiscoveryMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_DiscoveryMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// HwAddress 类型别名
// 基础类型: std::string
using tt_HwAddress = std::string;


// NetworkInterfaceInfo 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkInterfaceInfo {
    // Network interface name, for example eth0.
    std::optional<std::string> Name;
    // Network interface MAC address.
    tt_HwAddress HwAddress;
    // Maximum transmission unit.
    std::optional<int32_t> MTU;
};


// XmlTraits for tt_NetworkInterfaceInfo
template<>
struct xml_convert::XmlTraits<tt_NetworkInterfaceInfo> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_NetworkInterfaceInfo::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("HwAddress", &tt_NetworkInterfaceInfo::HwAddress, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MTU", &tt_NetworkInterfaceInfo::MTU, "tt", xml_convert::serialize_type::full)
    );
};


// Duplex 枚举类型
// 基础类型: std::string
enum class  tt_Duplex {
    Full,
    Half
};

// 字符串转换函数
inline std::string to_string(tt_Duplex value) {
    switch (value) {
        case tt_Duplex::Full: return "Full";
        case tt_Duplex::Half: return "Half";
        default: return "";
    }
}

inline bool from_string(tt_Duplex& value, const std::string& str) {
    if (str == "Full") { value = tt_Duplex::Full; return true; }
    if (str == "Half") { value = tt_Duplex::Half; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_Duplex
template<>
struct xml_convert::XmlValueAdapter<tt_Duplex> {
    static bool from_xml_val(tt_Duplex& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_Duplex& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_Duplex
template<>
struct xml_convert::XmlAttributeAdapter<tt_Duplex> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_Duplex& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_Duplex& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// NetworkInterfaceConnectionSetting 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkInterfaceConnectionSetting {
    // Auto negotiation on/off.
    bool AutoNegotiation {};
    // Speed.
    int32_t Speed {};
    // Duplex type, Half or Full.
    tt_Duplex Duplex;
};


// XmlTraits for tt_NetworkInterfaceConnectionSetting
template<>
struct xml_convert::XmlTraits<tt_NetworkInterfaceConnectionSetting> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AutoNegotiation", &tt_NetworkInterfaceConnectionSetting::AutoNegotiation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tt_NetworkInterfaceConnectionSetting::Speed, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Duplex", &tt_NetworkInterfaceConnectionSetting::Duplex, "tt", xml_convert::serialize_type::full)
    );
};


// IANA-IfTypes 类型别名
// 基础类型: int32_t
using tt_IANA_IfTypes = int32_t;


// NetworkInterfaceLink 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkInterfaceLink {
    // Configured link settings.
    tt_NetworkInterfaceConnectionSetting AdminSettings;
    // Current active link settings.
    tt_NetworkInterfaceConnectionSetting OperSettings;
    // Integer indicating interface type, for example: 6 is ethernet.
    tt_IANA_IfTypes InterfaceType;
};


// XmlTraits for tt_NetworkInterfaceLink
template<>
struct xml_convert::XmlTraits<tt_NetworkInterfaceLink> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AdminSettings", &tt_NetworkInterfaceLink::AdminSettings, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("OperSettings", &tt_NetworkInterfaceLink::OperSettings, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("InterfaceType", &tt_NetworkInterfaceLink::InterfaceType, "tt", xml_convert::serialize_type::full)
    );
};


// PrefixedIPv4Address 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PrefixedIPv4Address {
    // IPv4 address
    tt_IPv4Address Address;
    // Prefix/submask length
    int32_t PrefixLength {};
};


// XmlTraits for tt_PrefixedIPv4Address
template<>
struct xml_convert::XmlTraits<tt_PrefixedIPv4Address> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Address", &tt_PrefixedIPv4Address::Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PrefixLength", &tt_PrefixedIPv4Address::PrefixLength, "tt", xml_convert::serialize_type::full)
    );
};


// IPv4Configuration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IPv4Configuration {
    // List of manually added IPv4 addresses.
    std::vector<tt_PrefixedIPv4Address> Manual;
    // Link local address.
    std::optional<tt_PrefixedIPv4Address> LinkLocal;
    // IPv4 address configured by using DHCP.
    std::optional<tt_PrefixedIPv4Address> FromDHCP;
    // Indicates whether or not DHCP is used.
    bool DHCP {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_IPv4Configuration
template<>
struct xml_convert::XmlTraits<tt_IPv4Configuration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Manual", &tt_IPv4Configuration::Manual, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("LinkLocal", &tt_IPv4Configuration::LinkLocal, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FromDHCP", &tt_IPv4Configuration::FromDHCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DHCP", &tt_IPv4Configuration::DHCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_IPv4Configuration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_IPv4Configuration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// IPv4NetworkInterface 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IPv4NetworkInterface {
    // Indicates whether or not IPv4 is enabled.
    bool Enabled {};
    // IPv4 configuration.
    tt_IPv4Configuration Config;
};


// XmlTraits for tt_IPv4NetworkInterface
template<>
struct xml_convert::XmlTraits<tt_IPv4NetworkInterface> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tt_IPv4NetworkInterface::Enabled, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Config", &tt_IPv4NetworkInterface::Config, "tt", xml_convert::serialize_type::full)
    );
};


// IPv6DHCPConfiguration 枚举类型
// 基础类型: std::string
enum class  tt_IPv6DHCPConfiguration {
    Auto,
    Stateful,
    Stateless,
    Off
};

// 字符串转换函数
inline std::string to_string(tt_IPv6DHCPConfiguration value) {
    switch (value) {
        case tt_IPv6DHCPConfiguration::Auto: return "Auto";
        case tt_IPv6DHCPConfiguration::Stateful: return "Stateful";
        case tt_IPv6DHCPConfiguration::Stateless: return "Stateless";
        case tt_IPv6DHCPConfiguration::Off: return "Off";
        default: return "";
    }
}

inline bool from_string(tt_IPv6DHCPConfiguration& value, const std::string& str) {
    if (str == "Auto") { value = tt_IPv6DHCPConfiguration::Auto; return true; }
    if (str == "Stateful") { value = tt_IPv6DHCPConfiguration::Stateful; return true; }
    if (str == "Stateless") { value = tt_IPv6DHCPConfiguration::Stateless; return true; }
    if (str == "Off") { value = tt_IPv6DHCPConfiguration::Off; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_IPv6DHCPConfiguration
template<>
struct xml_convert::XmlValueAdapter<tt_IPv6DHCPConfiguration> {
    static bool from_xml_val(tt_IPv6DHCPConfiguration& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_IPv6DHCPConfiguration& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_IPv6DHCPConfiguration
template<>
struct xml_convert::XmlAttributeAdapter<tt_IPv6DHCPConfiguration> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_IPv6DHCPConfiguration& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_IPv6DHCPConfiguration& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// PrefixedIPv6Address 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PrefixedIPv6Address {
    // IPv6 address
    tt_IPv6Address Address;
    // Prefix/submask length
    int32_t PrefixLength {};
};


// XmlTraits for tt_PrefixedIPv6Address
template<>
struct xml_convert::XmlTraits<tt_PrefixedIPv6Address> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Address", &tt_PrefixedIPv6Address::Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PrefixLength", &tt_PrefixedIPv6Address::PrefixLength, "tt", xml_convert::serialize_type::full)
    );
};


// IPv6ConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IPv6ConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_IPv6ConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_IPv6ConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_IPv6ConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// IPv6Configuration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IPv6Configuration {
    // Indicates whether router advertisment is used.
    std::optional<bool> AcceptRouterAdvert;
    // DHCP configuration.
    tt_IPv6DHCPConfiguration DHCP;
    // List of manually entered IPv6 addresses.
    std::vector<tt_PrefixedIPv6Address> Manual;
    // List of link local IPv6 addresses.
    std::vector<tt_PrefixedIPv6Address> LinkLocal;
    // List of IPv6 addresses configured by using DHCP.
    std::vector<tt_PrefixedIPv6Address> FromDHCP;
    // List of IPv6 addresses configured by using router advertisment.
    std::vector<tt_PrefixedIPv6Address> FromRA;
    std::optional<tt_IPv6ConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_IPv6Configuration
template<>
struct xml_convert::XmlTraits<tt_IPv6Configuration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AcceptRouterAdvert", &tt_IPv6Configuration::AcceptRouterAdvert, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DHCP", &tt_IPv6Configuration::DHCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Manual", &tt_IPv6Configuration::Manual, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("LinkLocal", &tt_IPv6Configuration::LinkLocal, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FromDHCP", &tt_IPv6Configuration::FromDHCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FromRA", &tt_IPv6Configuration::FromRA, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_IPv6Configuration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_IPv6Configuration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// IPv6NetworkInterface 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IPv6NetworkInterface {
    // Indicates whether or not IPv6 is enabled.
    bool Enabled {};
    // IPv6 configuration.
    std::optional<tt_IPv6Configuration> Config;
};


// XmlTraits for tt_IPv6NetworkInterface
template<>
struct xml_convert::XmlTraits<tt_IPv6NetworkInterface> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tt_IPv6NetworkInterface::Enabled, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Config", &tt_IPv6NetworkInterface::Config, "tt", xml_convert::serialize_type::full)
    );
};


// Dot3Configuration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot3Configuration {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Dot3Configuration
template<>
struct xml_convert::XmlTraits<tt_Dot3Configuration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_Dot3Configuration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Dot3Configuration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Dot11SSIDType 类型别名
// 基础类型: std::string
using tt_Dot11SSIDType = std::string;


// Dot11StationMode 枚举类型
// 基础类型: std::string
enum class  tt_Dot11StationMode {
    Ad_hoc, // Ad-hoc
    Infrastructure,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_Dot11StationMode value) {
    switch (value) {
        case tt_Dot11StationMode::Ad_hoc: return "Ad-hoc";
        case tt_Dot11StationMode::Infrastructure: return "Infrastructure";
        case tt_Dot11StationMode::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_Dot11StationMode& value, const std::string& str) {
    if (str == "Ad-hoc") { value = tt_Dot11StationMode::Ad_hoc; return true; }
    if (str == "Infrastructure") { value = tt_Dot11StationMode::Infrastructure; return true; }
    if (str == "Extended") { value = tt_Dot11StationMode::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_Dot11StationMode
template<>
struct xml_convert::XmlValueAdapter<tt_Dot11StationMode> {
    static bool from_xml_val(tt_Dot11StationMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_Dot11StationMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_Dot11StationMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_Dot11StationMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_Dot11StationMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_Dot11StationMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// NetworkInterfaceConfigPriority 类型别名
// 基础类型: int64_t
using tt_NetworkInterfaceConfigPriority = int64_t;


// Dot11SecurityMode 枚举类型
// 基础类型: std::string
enum class  tt_Dot11SecurityMode {
    None,
    WEP,
    PSK,
    Dot1X,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_Dot11SecurityMode value) {
    switch (value) {
        case tt_Dot11SecurityMode::None: return "None";
        case tt_Dot11SecurityMode::WEP: return "WEP";
        case tt_Dot11SecurityMode::PSK: return "PSK";
        case tt_Dot11SecurityMode::Dot1X: return "Dot1X";
        case tt_Dot11SecurityMode::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_Dot11SecurityMode& value, const std::string& str) {
    if (str == "None") { value = tt_Dot11SecurityMode::None; return true; }
    if (str == "WEP") { value = tt_Dot11SecurityMode::WEP; return true; }
    if (str == "PSK") { value = tt_Dot11SecurityMode::PSK; return true; }
    if (str == "Dot1X") { value = tt_Dot11SecurityMode::Dot1X; return true; }
    if (str == "Extended") { value = tt_Dot11SecurityMode::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_Dot11SecurityMode
template<>
struct xml_convert::XmlValueAdapter<tt_Dot11SecurityMode> {
    static bool from_xml_val(tt_Dot11SecurityMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_Dot11SecurityMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_Dot11SecurityMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_Dot11SecurityMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_Dot11SecurityMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_Dot11SecurityMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Dot11Cipher 枚举类型
// 基础类型: std::string
enum class  tt_Dot11Cipher {
    CCMP,
    TKIP,
    Any,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_Dot11Cipher value) {
    switch (value) {
        case tt_Dot11Cipher::CCMP: return "CCMP";
        case tt_Dot11Cipher::TKIP: return "TKIP";
        case tt_Dot11Cipher::Any: return "Any";
        case tt_Dot11Cipher::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_Dot11Cipher& value, const std::string& str) {
    if (str == "CCMP") { value = tt_Dot11Cipher::CCMP; return true; }
    if (str == "TKIP") { value = tt_Dot11Cipher::TKIP; return true; }
    if (str == "Any") { value = tt_Dot11Cipher::Any; return true; }
    if (str == "Extended") { value = tt_Dot11Cipher::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_Dot11Cipher
template<>
struct xml_convert::XmlValueAdapter<tt_Dot11Cipher> {
    static bool from_xml_val(tt_Dot11Cipher& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_Dot11Cipher& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_Dot11Cipher
template<>
struct xml_convert::XmlAttributeAdapter<tt_Dot11Cipher> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_Dot11Cipher& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_Dot11Cipher& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Dot11PSK 类型别名
// 基础类型: std::string
using tt_Dot11PSK = std::string;


// Dot11PSKPassphrase 类型别名
// 基础类型: std::string
using tt_Dot11PSKPassphrase = std::string;


// Dot11PSKSetExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot11PSKSetExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_Dot11PSKSetExtension
template<>
struct xml_convert::XmlTraits<tt_Dot11PSKSetExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_Dot11PSKSetExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Dot11PSKSet 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot11PSKSet {
    /*
     * According to IEEE802.11-2007 H.4.1 the RSNA PSK consists of 256 bits, or 64 octets when represented in hex
     * Either Key or Passphrase shall be given, if both are supplied Key shall be used by the device and Passphrase ignored.
     */
    std::optional<tt_Dot11PSK> Key;
    /*
     * According to IEEE802.11-2007 H.4.1 a pass-phrase is a sequence of between 8 and 63 ASCII-encoded characters and
     * each character in the pass-phrase must have an encoding in the range of 32 to 126 (decimal),inclusive.
     * If only Passpharse is supplied the Key shall be derived using the algorithm described in IEEE802.11-2007 section H.4
     */
    std::optional<tt_Dot11PSKPassphrase> Passphrase;
    std::optional<tt_Dot11PSKSetExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Dot11PSKSet
template<>
struct xml_convert::XmlTraits<tt_Dot11PSKSet> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Key", &tt_Dot11PSKSet::Key, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Passphrase", &tt_Dot11PSKSet::Passphrase, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Dot11PSKSet::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_Dot11PSKSet::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Dot11SecurityConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot11SecurityConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Dot11SecurityConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_Dot11SecurityConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_Dot11SecurityConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Dot11SecurityConfigurationExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Dot11SecurityConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot11SecurityConfiguration {
    tt_Dot11SecurityMode Mode;
    std::optional<tt_Dot11Cipher> Algorithm;
    std::optional<tt_Dot11PSKSet> PSK;
    std::optional<tt_ReferenceToken> Dot1X;
    std::optional<tt_Dot11SecurityConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Dot11SecurityConfiguration
template<>
struct xml_convert::XmlTraits<tt_Dot11SecurityConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_Dot11SecurityConfiguration::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Algorithm", &tt_Dot11SecurityConfiguration::Algorithm, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PSK", &tt_Dot11SecurityConfiguration::PSK, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Dot1X", &tt_Dot11SecurityConfiguration::Dot1X, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Dot11SecurityConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_Dot11SecurityConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Dot11Configuration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot11Configuration {
    tt_Dot11SSIDType SSID;
    tt_Dot11StationMode Mode;
    tt_Name Alias;
    tt_NetworkInterfaceConfigPriority Priority;
    tt_Dot11SecurityConfiguration Security;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Dot11Configuration
template<>
struct xml_convert::XmlTraits<tt_Dot11Configuration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SSID", &tt_Dot11Configuration::SSID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mode", &tt_Dot11Configuration::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Alias", &tt_Dot11Configuration::Alias, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Priority", &tt_Dot11Configuration::Priority, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Security", &tt_Dot11Configuration::Security, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Dot11Configuration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Dot11Configuration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// NetworkInterfaceExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkInterfaceExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_NetworkInterfaceExtension2
template<>
struct xml_convert::XmlTraits<tt_NetworkInterfaceExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NetworkInterfaceExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// NetworkInterfaceExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkInterfaceExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    tt_IANA_IfTypes InterfaceType;
    // Extension point prepared for future 802.3 configuration.
    std::vector<tt_Dot3Configuration> Dot3;
    std::vector<tt_Dot11Configuration> Dot11;
    std::optional<tt_NetworkInterfaceExtension2> Extension;
};


// XmlTraits for tt_NetworkInterfaceExtension
template<>
struct xml_convert::XmlTraits<tt_NetworkInterfaceExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NetworkInterfaceExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("InterfaceType", &tt_NetworkInterfaceExtension::InterfaceType, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Dot3", &tt_NetworkInterfaceExtension::Dot3, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Dot11", &tt_NetworkInterfaceExtension::Dot11, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NetworkInterfaceExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// NetworkInterface 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkInterface : public tt_DeviceEntity {
    // Indicates whether or not an interface is enabled.
    bool Enabled {};
    // Network interface information
    std::optional<tt_NetworkInterfaceInfo> Info;
    // Link configuration.
    std::optional<tt_NetworkInterfaceLink> Link;
    // IPv4 network interface configuration.
    std::optional<tt_IPv4NetworkInterface> IPv4;
    // IPv6 network interface configuration.
    std::optional<tt_IPv6NetworkInterface> IPv6;
    std::optional<tt_NetworkInterfaceExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_NetworkInterface
template<>
struct xml_convert::XmlTraits<tt_NetworkInterface> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_DeviceEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tt_NetworkInterface::Enabled, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Info", &tt_NetworkInterface::Info, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Link", &tt_NetworkInterface::Link, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv4", &tt_NetworkInterface::IPv4, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv6", &tt_NetworkInterface::IPv6, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NetworkInterface::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_NetworkInterface::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// NetworkProtocolType 枚举类型
// 基础类型: std::string
enum class  tt_NetworkProtocolType {
    HTTP,
    HTTPS,
    RTSP
};

// 字符串转换函数
inline std::string to_string(tt_NetworkProtocolType value) {
    switch (value) {
        case tt_NetworkProtocolType::HTTP: return "HTTP";
        case tt_NetworkProtocolType::HTTPS: return "HTTPS";
        case tt_NetworkProtocolType::RTSP: return "RTSP";
        default: return "";
    }
}

inline bool from_string(tt_NetworkProtocolType& value, const std::string& str) {
    if (str == "HTTP") { value = tt_NetworkProtocolType::HTTP; return true; }
    if (str == "HTTPS") { value = tt_NetworkProtocolType::HTTPS; return true; }
    if (str == "RTSP") { value = tt_NetworkProtocolType::RTSP; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_NetworkProtocolType
template<>
struct xml_convert::XmlValueAdapter<tt_NetworkProtocolType> {
    static bool from_xml_val(tt_NetworkProtocolType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_NetworkProtocolType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_NetworkProtocolType
template<>
struct xml_convert::XmlAttributeAdapter<tt_NetworkProtocolType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_NetworkProtocolType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_NetworkProtocolType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// NetworkProtocolExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkProtocolExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_NetworkProtocolExtension
template<>
struct xml_convert::XmlTraits<tt_NetworkProtocolExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NetworkProtocolExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// NetworkProtocol 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkProtocol {
    // Network protocol type string.
    tt_NetworkProtocolType Name;
    // Indicates if the protocol is enabled or not.
    bool Enabled {};
    // The port that is used by the protocol.
    std::vector<int32_t> Port;
    std::optional<tt_NetworkProtocolExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_NetworkProtocol
template<>
struct xml_convert::XmlTraits<tt_NetworkProtocol> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_NetworkProtocol::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Enabled", &tt_NetworkProtocol::Enabled, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Port", &tt_NetworkProtocol::Port, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NetworkProtocol::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_NetworkProtocol::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// NetworkHostType 枚举类型
// 基础类型: std::string
enum class  tt_NetworkHostType {
    IPv4,
    IPv6,
    DNS
};

// 字符串转换函数
inline std::string to_string(tt_NetworkHostType value) {
    switch (value) {
        case tt_NetworkHostType::IPv4: return "IPv4";
        case tt_NetworkHostType::IPv6: return "IPv6";
        case tt_NetworkHostType::DNS: return "DNS";
        default: return "";
    }
}

inline bool from_string(tt_NetworkHostType& value, const std::string& str) {
    if (str == "IPv4") { value = tt_NetworkHostType::IPv4; return true; }
    if (str == "IPv6") { value = tt_NetworkHostType::IPv6; return true; }
    if (str == "DNS") { value = tt_NetworkHostType::DNS; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_NetworkHostType
template<>
struct xml_convert::XmlValueAdapter<tt_NetworkHostType> {
    static bool from_xml_val(tt_NetworkHostType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_NetworkHostType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_NetworkHostType
template<>
struct xml_convert::XmlAttributeAdapter<tt_NetworkHostType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_NetworkHostType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_NetworkHostType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// DNSName 类型别名
// 基础类型: std::string
using tt_DNSName = std::string;


// NetworkHostExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkHostExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_NetworkHostExtension
template<>
struct xml_convert::XmlTraits<tt_NetworkHostExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NetworkHostExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// NetworkHost 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkHost {
    // Network host type: IPv4, IPv6 or DNS.
    tt_NetworkHostType Type;
    // IPv4 address.
    std::optional<tt_IPv4Address> IPv4Address;
    // IPv6 address.
    std::optional<tt_IPv6Address> IPv6Address;
    // DNS name.
    std::optional<tt_DNSName> DNSname;
    std::optional<tt_NetworkHostExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_NetworkHost
template<>
struct xml_convert::XmlTraits<tt_NetworkHost> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_NetworkHost::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv4Address", &tt_NetworkHost::IPv4Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv6Address", &tt_NetworkHost::IPv6Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DNSname", &tt_NetworkHost::DNSname, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NetworkHost::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_NetworkHost::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// HostnameInformationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_HostnameInformationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_HostnameInformationExtension
template<>
struct xml_convert::XmlTraits<tt_HostnameInformationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_HostnameInformationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// HostnameInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_HostnameInformation {
    // Indicates whether the hostname has been obtained from DHCP or not.
    bool FromDHCP {};
    // Indicates the device hostname or an empty string if no hostname has been assigned.
    std::optional<std::string> Name;
    std::optional<tt_HostnameInformationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_HostnameInformation
template<>
struct xml_convert::XmlTraits<tt_HostnameInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FromDHCP", &tt_HostnameInformation::FromDHCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Name", &tt_HostnameInformation::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_HostnameInformation::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_HostnameInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// DNSInformationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DNSInformationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_DNSInformationExtension
template<>
struct xml_convert::XmlTraits<tt_DNSInformationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_DNSInformationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// DNSInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DNSInformation {
    // Indicates whether or not DNS information is retrieved from DHCP.
    bool FromDHCP {};
    // Search domain.
    std::vector<std::string> SearchDomain;
    // List of DNS addresses received from DHCP.
    std::vector<tt_IPAddress> DNSFromDHCP;
    // List of manually entered DNS addresses.
    std::vector<tt_IPAddress> DNSManual;
    std::optional<tt_DNSInformationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_DNSInformation
template<>
struct xml_convert::XmlTraits<tt_DNSInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FromDHCP", &tt_DNSInformation::FromDHCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SearchDomain", &tt_DNSInformation::SearchDomain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DNSFromDHCP", &tt_DNSInformation::DNSFromDHCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DNSManual", &tt_DNSInformation::DNSManual, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_DNSInformation::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_DNSInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// NTPInformationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NTPInformationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_NTPInformationExtension
template<>
struct xml_convert::XmlTraits<tt_NTPInformationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NTPInformationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// NTPInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NTPInformation {
    // Indicates if NTP information is to be retrieved by using DHCP.
    bool FromDHCP {};
    // List of NTP addresses retrieved by using DHCP.
    std::vector<tt_NetworkHost> NTPFromDHCP;
    // List of manually entered NTP addresses.
    std::vector<tt_NetworkHost> NTPManual;
    std::optional<tt_NTPInformationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_NTPInformation
template<>
struct xml_convert::XmlTraits<tt_NTPInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FromDHCP", &tt_NTPInformation::FromDHCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NTPFromDHCP", &tt_NTPInformation::NTPFromDHCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NTPManual", &tt_NTPInformation::NTPManual, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NTPInformation::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_NTPInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Domain 类型别名
// 基础类型: std::string
using tt_Domain = std::string;


// IPAddressFilterType 枚举类型
// 基础类型: std::string
enum class  tt_IPAddressFilterType {
    Allow,
    Deny
};

// 字符串转换函数
inline std::string to_string(tt_IPAddressFilterType value) {
    switch (value) {
        case tt_IPAddressFilterType::Allow: return "Allow";
        case tt_IPAddressFilterType::Deny: return "Deny";
        default: return "";
    }
}

inline bool from_string(tt_IPAddressFilterType& value, const std::string& str) {
    if (str == "Allow") { value = tt_IPAddressFilterType::Allow; return true; }
    if (str == "Deny") { value = tt_IPAddressFilterType::Deny; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_IPAddressFilterType
template<>
struct xml_convert::XmlValueAdapter<tt_IPAddressFilterType> {
    static bool from_xml_val(tt_IPAddressFilterType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_IPAddressFilterType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_IPAddressFilterType
template<>
struct xml_convert::XmlAttributeAdapter<tt_IPAddressFilterType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_IPAddressFilterType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_IPAddressFilterType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// DynamicDNSType 枚举类型
// 基础类型: std::string
enum class  tt_DynamicDNSType {
    NoUpdate,
    ClientUpdates,
    ServerUpdates
};

// 字符串转换函数
inline std::string to_string(tt_DynamicDNSType value) {
    switch (value) {
        case tt_DynamicDNSType::NoUpdate: return "NoUpdate";
        case tt_DynamicDNSType::ClientUpdates: return "ClientUpdates";
        case tt_DynamicDNSType::ServerUpdates: return "ServerUpdates";
        default: return "";
    }
}

inline bool from_string(tt_DynamicDNSType& value, const std::string& str) {
    if (str == "NoUpdate") { value = tt_DynamicDNSType::NoUpdate; return true; }
    if (str == "ClientUpdates") { value = tt_DynamicDNSType::ClientUpdates; return true; }
    if (str == "ServerUpdates") { value = tt_DynamicDNSType::ServerUpdates; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_DynamicDNSType
template<>
struct xml_convert::XmlValueAdapter<tt_DynamicDNSType> {
    static bool from_xml_val(tt_DynamicDNSType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_DynamicDNSType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_DynamicDNSType
template<>
struct xml_convert::XmlAttributeAdapter<tt_DynamicDNSType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_DynamicDNSType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_DynamicDNSType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// DynamicDNSInformationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DynamicDNSInformationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_DynamicDNSInformationExtension
template<>
struct xml_convert::XmlTraits<tt_DynamicDNSInformationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_DynamicDNSInformationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// DynamicDNSInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DynamicDNSInformation {
    // Dynamic DNS type.
    tt_DynamicDNSType Type;
    // DNS name.
    std::optional<tt_DNSName> Name;
    // Time to live.
    std::optional<my_Duration> TTL;
    std::optional<tt_DynamicDNSInformationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_DynamicDNSInformation
template<>
struct xml_convert::XmlTraits<tt_DynamicDNSInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_DynamicDNSInformation::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Name", &tt_DynamicDNSInformation::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TTL", &tt_DynamicDNSInformation::TTL, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_DynamicDNSInformation::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_DynamicDNSInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// IPv4NetworkInterfaceSetConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IPv4NetworkInterfaceSetConfiguration {
    // Indicates whether or not IPv4 is enabled.
    std::optional<bool> Enabled;
    // List of manually added IPv4 addresses.
    std::vector<tt_PrefixedIPv4Address> Manual;
    // Indicates whether or not DHCP is used.
    std::optional<bool> DHCP;
};


// XmlTraits for tt_IPv4NetworkInterfaceSetConfiguration
template<>
struct xml_convert::XmlTraits<tt_IPv4NetworkInterfaceSetConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tt_IPv4NetworkInterfaceSetConfiguration::Enabled, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Manual", &tt_IPv4NetworkInterfaceSetConfiguration::Manual, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DHCP", &tt_IPv4NetworkInterfaceSetConfiguration::DHCP, "tt", xml_convert::serialize_type::full)
    );
};


// IPv6NetworkInterfaceSetConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IPv6NetworkInterfaceSetConfiguration {
    // Indicates whether or not IPv6 is enabled.
    std::optional<bool> Enabled;
    // Indicates whether router advertisment is used.
    std::optional<bool> AcceptRouterAdvert;
    // List of manually added IPv6 addresses.
    std::vector<tt_PrefixedIPv6Address> Manual;
    // DHCP configuration.
    std::optional<tt_IPv6DHCPConfiguration> DHCP;
};


// XmlTraits for tt_IPv6NetworkInterfaceSetConfiguration
template<>
struct xml_convert::XmlTraits<tt_IPv6NetworkInterfaceSetConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tt_IPv6NetworkInterfaceSetConfiguration::Enabled, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AcceptRouterAdvert", &tt_IPv6NetworkInterfaceSetConfiguration::AcceptRouterAdvert, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Manual", &tt_IPv6NetworkInterfaceSetConfiguration::Manual, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DHCP", &tt_IPv6NetworkInterfaceSetConfiguration::DHCP, "tt", xml_convert::serialize_type::full)
    );
};


// NetworkInterfaceSetConfigurationExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkInterfaceSetConfigurationExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_NetworkInterfaceSetConfigurationExtension2
template<>
struct xml_convert::XmlTraits<tt_NetworkInterfaceSetConfigurationExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NetworkInterfaceSetConfigurationExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// NetworkInterfaceSetConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkInterfaceSetConfigurationExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::vector<tt_Dot3Configuration> Dot3;
    std::vector<tt_Dot11Configuration> Dot11;
    std::optional<tt_NetworkInterfaceSetConfigurationExtension2> Extension;
};


// XmlTraits for tt_NetworkInterfaceSetConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_NetworkInterfaceSetConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NetworkInterfaceSetConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Dot3", &tt_NetworkInterfaceSetConfigurationExtension::Dot3, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Dot11", &tt_NetworkInterfaceSetConfigurationExtension::Dot11, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NetworkInterfaceSetConfigurationExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// NetworkInterfaceSetConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkInterfaceSetConfiguration {
    // Indicates whether or not an interface is enabled.
    std::optional<bool> Enabled;
    // Link configuration.
    std::optional<tt_NetworkInterfaceConnectionSetting> Link;
    // Maximum transmission unit.
    std::optional<int32_t> MTU;
    // IPv4 network interface configuration.
    std::optional<tt_IPv4NetworkInterfaceSetConfiguration> IPv4;
    // IPv6 network interface configuration.
    std::optional<tt_IPv6NetworkInterfaceSetConfiguration> IPv6;
    std::optional<tt_NetworkInterfaceSetConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_NetworkInterfaceSetConfiguration
template<>
struct xml_convert::XmlTraits<tt_NetworkInterfaceSetConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tt_NetworkInterfaceSetConfiguration::Enabled, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Link", &tt_NetworkInterfaceSetConfiguration::Link, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MTU", &tt_NetworkInterfaceSetConfiguration::MTU, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv4", &tt_NetworkInterfaceSetConfiguration::IPv4, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv6", &tt_NetworkInterfaceSetConfiguration::IPv6, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NetworkInterfaceSetConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_NetworkInterfaceSetConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// NetworkGateway 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkGateway {
    // IPv4 address string.
    std::vector<tt_IPv4Address> IPv4Address;
    // IPv6 address string.
    std::vector<tt_IPv6Address> IPv6Address;
};


// XmlTraits for tt_NetworkGateway
template<>
struct xml_convert::XmlTraits<tt_NetworkGateway> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IPv4Address", &tt_NetworkGateway::IPv4Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv6Address", &tt_NetworkGateway::IPv6Address, "tt", xml_convert::serialize_type::full)
    );
};


// NetworkZeroConfigurationExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkZeroConfigurationExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_NetworkZeroConfigurationExtension2
template<>
struct xml_convert::XmlTraits<tt_NetworkZeroConfigurationExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NetworkZeroConfigurationExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// NetworkZeroConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkZeroConfigurationExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Optional array holding the configuration for the second and possibly further interfaces.
    std::vector<tt_NetworkZeroConfiguration> Additional;
    std::optional<tt_NetworkZeroConfigurationExtension2> Extension;
};


// XmlTraits for tt_NetworkZeroConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_NetworkZeroConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NetworkZeroConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Additional", &tt_NetworkZeroConfigurationExtension::Additional, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NetworkZeroConfigurationExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// NetworkZeroConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkZeroConfiguration {
    // Unique identifier of network interface.
    tt_ReferenceToken InterfaceToken;
    // Indicates whether the zero-configuration is enabled or not.
    bool Enabled {};
    // The zero-configuration IPv4 address(es)
    std::vector<tt_IPv4Address> Addresses;
    std::optional<tt_NetworkZeroConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_NetworkZeroConfiguration
template<>
struct xml_convert::XmlTraits<tt_NetworkZeroConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("InterfaceToken", &tt_NetworkZeroConfiguration::InterfaceToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Enabled", &tt_NetworkZeroConfiguration::Enabled, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Addresses", &tt_NetworkZeroConfiguration::Addresses, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NetworkZeroConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_NetworkZeroConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// IPAddressFilterExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IPAddressFilterExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_IPAddressFilterExtension
template<>
struct xml_convert::XmlTraits<tt_IPAddressFilterExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_IPAddressFilterExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// IPAddressFilter 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IPAddressFilter {
    tt_IPAddressFilterType Type;
    std::vector<tt_PrefixedIPv4Address> IPv4Address;
    std::vector<tt_PrefixedIPv6Address> IPv6Address;
    std::optional<tt_IPAddressFilterExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_IPAddressFilter
template<>
struct xml_convert::XmlTraits<tt_IPAddressFilter> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_IPAddressFilter::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv4Address", &tt_IPAddressFilter::IPv4Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv6Address", &tt_IPAddressFilter::IPv6Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_IPAddressFilter::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_IPAddressFilter::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Dot11Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot11Capabilities {
    bool TKIP {};
    bool ScanAvailableNetworks {};
    bool MultipleConfiguration {};
    bool AdHocStationMode {};
    bool WEP {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Dot11Capabilities
template<>
struct xml_convert::XmlTraits<tt_Dot11Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TKIP", &tt_Dot11Capabilities::TKIP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ScanAvailableNetworks", &tt_Dot11Capabilities::ScanAvailableNetworks, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MultipleConfiguration", &tt_Dot11Capabilities::MultipleConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AdHocStationMode", &tt_Dot11Capabilities::AdHocStationMode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WEP", &tt_Dot11Capabilities::WEP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Dot11Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Dot11Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Dot11SignalStrength 枚举类型
// 基础类型: std::string
enum class  tt_Dot11SignalStrength {
    None,
    Very_Bad, // Very Bad
    Bad,
    Good,
    Very_Good, // Very Good
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_Dot11SignalStrength value) {
    switch (value) {
        case tt_Dot11SignalStrength::None: return "None";
        case tt_Dot11SignalStrength::Very_Bad: return "Very Bad";
        case tt_Dot11SignalStrength::Bad: return "Bad";
        case tt_Dot11SignalStrength::Good: return "Good";
        case tt_Dot11SignalStrength::Very_Good: return "Very Good";
        case tt_Dot11SignalStrength::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_Dot11SignalStrength& value, const std::string& str) {
    if (str == "None") { value = tt_Dot11SignalStrength::None; return true; }
    if (str == "Very Bad") { value = tt_Dot11SignalStrength::Very_Bad; return true; }
    if (str == "Bad") { value = tt_Dot11SignalStrength::Bad; return true; }
    if (str == "Good") { value = tt_Dot11SignalStrength::Good; return true; }
    if (str == "Very Good") { value = tt_Dot11SignalStrength::Very_Good; return true; }
    if (str == "Extended") { value = tt_Dot11SignalStrength::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_Dot11SignalStrength
template<>
struct xml_convert::XmlValueAdapter<tt_Dot11SignalStrength> {
    static bool from_xml_val(tt_Dot11SignalStrength& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_Dot11SignalStrength& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_Dot11SignalStrength
template<>
struct xml_convert::XmlAttributeAdapter<tt_Dot11SignalStrength> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_Dot11SignalStrength& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_Dot11SignalStrength& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Dot11Status 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot11Status {
    tt_Dot11SSIDType SSID;
    std::optional<std::string> BSSID;
    std::optional<tt_Dot11Cipher> PairCipher;
    std::optional<tt_Dot11Cipher> GroupCipher;
    std::optional<tt_Dot11SignalStrength> SignalStrength;
    tt_ReferenceToken ActiveConfigAlias;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Dot11Status
template<>
struct xml_convert::XmlTraits<tt_Dot11Status> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SSID", &tt_Dot11Status::SSID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BSSID", &tt_Dot11Status::BSSID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PairCipher", &tt_Dot11Status::PairCipher, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("GroupCipher", &tt_Dot11Status::GroupCipher, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SignalStrength", &tt_Dot11Status::SignalStrength, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ActiveConfigAlias", &tt_Dot11Status::ActiveConfigAlias, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Dot11Status::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Dot11Status::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Dot11AuthAndMangementSuite 枚举类型
// 基础类型: std::string
enum class  tt_Dot11AuthAndMangementSuite {
    None,
    Dot1X,
    PSK,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_Dot11AuthAndMangementSuite value) {
    switch (value) {
        case tt_Dot11AuthAndMangementSuite::None: return "None";
        case tt_Dot11AuthAndMangementSuite::Dot1X: return "Dot1X";
        case tt_Dot11AuthAndMangementSuite::PSK: return "PSK";
        case tt_Dot11AuthAndMangementSuite::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_Dot11AuthAndMangementSuite& value, const std::string& str) {
    if (str == "None") { value = tt_Dot11AuthAndMangementSuite::None; return true; }
    if (str == "Dot1X") { value = tt_Dot11AuthAndMangementSuite::Dot1X; return true; }
    if (str == "PSK") { value = tt_Dot11AuthAndMangementSuite::PSK; return true; }
    if (str == "Extended") { value = tt_Dot11AuthAndMangementSuite::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_Dot11AuthAndMangementSuite
template<>
struct xml_convert::XmlValueAdapter<tt_Dot11AuthAndMangementSuite> {
    static bool from_xml_val(tt_Dot11AuthAndMangementSuite& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_Dot11AuthAndMangementSuite& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_Dot11AuthAndMangementSuite
template<>
struct xml_convert::XmlAttributeAdapter<tt_Dot11AuthAndMangementSuite> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_Dot11AuthAndMangementSuite& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_Dot11AuthAndMangementSuite& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Dot11AvailableNetworksExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot11AvailableNetworksExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_Dot11AvailableNetworksExtension
template<>
struct xml_convert::XmlTraits<tt_Dot11AvailableNetworksExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_Dot11AvailableNetworksExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Dot11AvailableNetworks 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot11AvailableNetworks {
    tt_Dot11SSIDType SSID;
    std::optional<std::string> BSSID;
    // See IEEE802.11 7.3.2.25.2 for details.
    std::vector<tt_Dot11AuthAndMangementSuite> AuthAndMangementSuite;
    std::vector<tt_Dot11Cipher> PairCipher;
    std::vector<tt_Dot11Cipher> GroupCipher;
    std::optional<tt_Dot11SignalStrength> SignalStrength;
    std::optional<tt_Dot11AvailableNetworksExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Dot11AvailableNetworks
template<>
struct xml_convert::XmlTraits<tt_Dot11AvailableNetworks> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SSID", &tt_Dot11AvailableNetworks::SSID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BSSID", &tt_Dot11AvailableNetworks::BSSID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AuthAndMangementSuite", &tt_Dot11AvailableNetworks::AuthAndMangementSuite, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PairCipher", &tt_Dot11AvailableNetworks::PairCipher, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("GroupCipher", &tt_Dot11AvailableNetworks::GroupCipher, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SignalStrength", &tt_Dot11AvailableNetworks::SignalStrength, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Dot11AvailableNetworks::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_Dot11AvailableNetworks::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CapabilityCategory 枚举类型
// 基础类型: std::string
enum class  tt_CapabilityCategory {
    All,
    Analytics,
    Device,
    Events,
    Imaging,
    Media,
    PTZ
};

// 字符串转换函数
inline std::string to_string(tt_CapabilityCategory value) {
    switch (value) {
        case tt_CapabilityCategory::All: return "All";
        case tt_CapabilityCategory::Analytics: return "Analytics";
        case tt_CapabilityCategory::Device: return "Device";
        case tt_CapabilityCategory::Events: return "Events";
        case tt_CapabilityCategory::Imaging: return "Imaging";
        case tt_CapabilityCategory::Media: return "Media";
        case tt_CapabilityCategory::PTZ: return "PTZ";
        default: return "";
    }
}

inline bool from_string(tt_CapabilityCategory& value, const std::string& str) {
    if (str == "All") { value = tt_CapabilityCategory::All; return true; }
    if (str == "Analytics") { value = tt_CapabilityCategory::Analytics; return true; }
    if (str == "Device") { value = tt_CapabilityCategory::Device; return true; }
    if (str == "Events") { value = tt_CapabilityCategory::Events; return true; }
    if (str == "Imaging") { value = tt_CapabilityCategory::Imaging; return true; }
    if (str == "Media") { value = tt_CapabilityCategory::Media; return true; }
    if (str == "PTZ") { value = tt_CapabilityCategory::PTZ; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_CapabilityCategory
template<>
struct xml_convert::XmlValueAdapter<tt_CapabilityCategory> {
    static bool from_xml_val(tt_CapabilityCategory& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_CapabilityCategory& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_CapabilityCategory
template<>
struct xml_convert::XmlAttributeAdapter<tt_CapabilityCategory> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_CapabilityCategory& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_CapabilityCategory& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// AnalyticsCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsCapabilities {
    // Analytics service URI.
    std::string XAddr;
    // Indicates whether or not rules are supported.
    bool RuleSupport {};
    // Indicates whether or not modules are supported.
    bool AnalyticsModuleSupport {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnalyticsCapabilities
template<>
struct xml_convert::XmlTraits<tt_AnalyticsCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_AnalyticsCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RuleSupport", &tt_AnalyticsCapabilities::RuleSupport, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AnalyticsModuleSupport", &tt_AnalyticsCapabilities::AnalyticsModuleSupport, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AnalyticsCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AnalyticsCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// NetworkCapabilitiesExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkCapabilitiesExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_NetworkCapabilitiesExtension2
template<>
struct xml_convert::XmlTraits<tt_NetworkCapabilitiesExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NetworkCapabilitiesExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// NetworkCapabilitiesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkCapabilitiesExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<bool> Dot11Configuration;
    std::optional<tt_NetworkCapabilitiesExtension2> Extension;
};


// XmlTraits for tt_NetworkCapabilitiesExtension
template<>
struct xml_convert::XmlTraits<tt_NetworkCapabilitiesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_NetworkCapabilitiesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Dot11Configuration", &tt_NetworkCapabilitiesExtension::Dot11Configuration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NetworkCapabilitiesExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// NetworkCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NetworkCapabilities {
    // Indicates whether or not IP filtering is supported.
    std::optional<bool> IPFilter;
    // Indicates whether or not zeroconf is supported.
    std::optional<bool> ZeroConfiguration;
    // Indicates whether or not IPv6 is supported.
    std::optional<bool> IPVersion6;
    // Indicates whether or not  is supported.
    std::optional<bool> DynDNS;
    std::optional<tt_NetworkCapabilitiesExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_NetworkCapabilities
template<>
struct xml_convert::XmlTraits<tt_NetworkCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IPFilter", &tt_NetworkCapabilities::IPFilter, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ZeroConfiguration", &tt_NetworkCapabilities::ZeroConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPVersion6", &tt_NetworkCapabilities::IPVersion6, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DynDNS", &tt_NetworkCapabilities::DynDNS, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_NetworkCapabilities::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_NetworkCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OnvifVersion 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OnvifVersion {
    // Major version number.
    int32_t Major {};
    /*
     * Two digit minor version number.
     * If major version number is less than "16", X.0.1 maps to "01" and X.2.1 maps to "21" where X stands for Major version number.
     * Otherwise, minor number is month of release, such as "06" for June.
     */
    int32_t Minor {};
};


// XmlTraits for tt_OnvifVersion
template<>
struct xml_convert::XmlTraits<tt_OnvifVersion> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Major", &tt_OnvifVersion::Major, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Minor", &tt_OnvifVersion::Minor, "tt", xml_convert::serialize_type::full)
    );
};


// SystemCapabilitiesExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SystemCapabilitiesExtension2 {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_SystemCapabilitiesExtension2
template<>
struct xml_convert::XmlTraits<tt_SystemCapabilitiesExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_SystemCapabilitiesExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SystemCapabilitiesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SystemCapabilitiesExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<bool> HttpFirmwareUpgrade;
    std::optional<bool> HttpSystemBackup;
    std::optional<bool> HttpSystemLogging;
    std::optional<bool> HttpSupportInformation;
    std::optional<tt_SystemCapabilitiesExtension2> Extension;
};


// XmlTraits for tt_SystemCapabilitiesExtension
template<>
struct xml_convert::XmlTraits<tt_SystemCapabilitiesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_SystemCapabilitiesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("HttpFirmwareUpgrade", &tt_SystemCapabilitiesExtension::HttpFirmwareUpgrade, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("HttpSystemBackup", &tt_SystemCapabilitiesExtension::HttpSystemBackup, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("HttpSystemLogging", &tt_SystemCapabilitiesExtension::HttpSystemLogging, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("HttpSupportInformation", &tt_SystemCapabilitiesExtension::HttpSupportInformation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_SystemCapabilitiesExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// SystemCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SystemCapabilities {
    // Indicates whether or not WS Discovery resolve requests are supported.
    bool DiscoveryResolve {};
    // Indicates whether or not WS-Discovery Bye is supported.
    bool DiscoveryBye {};
    // Indicates whether or not remote discovery is supported.
    bool RemoteDiscovery {};
    // Indicates whether or not system backup is supported.
    bool SystemBackup {};
    // Indicates whether or not system logging is supported.
    bool SystemLogging {};
    // Indicates whether or not firmware upgrade is supported.
    bool FirmwareUpgrade {};
    // Indicates supported ONVIF version(s).
    std::vector<tt_OnvifVersion> SupportedVersions;
    std::optional<tt_SystemCapabilitiesExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SystemCapabilities
template<>
struct xml_convert::XmlTraits<tt_SystemCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DiscoveryResolve", &tt_SystemCapabilities::DiscoveryResolve, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DiscoveryBye", &tt_SystemCapabilities::DiscoveryBye, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RemoteDiscovery", &tt_SystemCapabilities::RemoteDiscovery, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SystemBackup", &tt_SystemCapabilities::SystemBackup, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SystemLogging", &tt_SystemCapabilities::SystemLogging, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FirmwareUpgrade", &tt_SystemCapabilities::FirmwareUpgrade, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedVersions", &tt_SystemCapabilities::SupportedVersions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_SystemCapabilities::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_SystemCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AuxiliaryData 类型别名
// 基础类型: std::string
using tt_AuxiliaryData = std::string;


// IOCapabilitiesExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IOCapabilitiesExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_IOCapabilitiesExtension2
template<>
struct xml_convert::XmlTraits<tt_IOCapabilitiesExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_IOCapabilitiesExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// IOCapabilitiesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IOCapabilitiesExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<bool> Auxiliary;
    std::vector<tt_AuxiliaryData> AuxiliaryCommands;
    tt_IOCapabilitiesExtension2 Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_IOCapabilitiesExtension
template<>
struct xml_convert::XmlTraits<tt_IOCapabilitiesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_IOCapabilitiesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Auxiliary", &tt_IOCapabilitiesExtension::Auxiliary, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AuxiliaryCommands", &tt_IOCapabilitiesExtension::AuxiliaryCommands, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_IOCapabilitiesExtension::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_IOCapabilitiesExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// IOCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IOCapabilities {
    // Number of input connectors.
    std::optional<int32_t> InputConnectors;
    // Number of relay outputs.
    std::optional<int32_t> RelayOutputs;
    std::optional<tt_IOCapabilitiesExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_IOCapabilities
template<>
struct xml_convert::XmlTraits<tt_IOCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("InputConnectors", &tt_IOCapabilities::InputConnectors, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RelayOutputs", &tt_IOCapabilities::RelayOutputs, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_IOCapabilities::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_IOCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SecurityCapabilitiesExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SecurityCapabilitiesExtension2 {
    bool Dot1X {};
    // EAP Methods supported by the device. The int values refer to the IANA EAP Registry.
    std::vector<int32_t> SupportedEAPMethod;
    bool RemoteUserHandling {};
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_SecurityCapabilitiesExtension2
template<>
struct xml_convert::XmlTraits<tt_SecurityCapabilitiesExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Dot1X", &tt_SecurityCapabilitiesExtension2::Dot1X, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedEAPMethod", &tt_SecurityCapabilitiesExtension2::SupportedEAPMethod, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RemoteUserHandling", &tt_SecurityCapabilitiesExtension2::RemoteUserHandling, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_SecurityCapabilitiesExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SecurityCapabilitiesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SecurityCapabilitiesExtension {
    bool TLS1_0 {};
    std::optional<tt_SecurityCapabilitiesExtension2> Extension;
};


// XmlTraits for tt_SecurityCapabilitiesExtension
template<>
struct xml_convert::XmlTraits<tt_SecurityCapabilitiesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TLS1.0", &tt_SecurityCapabilitiesExtension::TLS1_0, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_SecurityCapabilitiesExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// SecurityCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SecurityCapabilities {
    // Indicates whether or not TLS 1.1 is supported.
    bool TLS1_1 {};
    // Indicates whether or not TLS 1.2 is supported.
    bool TLS1_2 {};
    // Indicates whether or not onboard key generation is supported.
    bool OnboardKeyGeneration {};
    // Indicates whether or not access policy configuration is supported.
    bool AccessPolicyConfig {};
    // Indicates whether or not WS-Security X.509 token is supported.
    bool X_509Token {};
    // Indicates whether or not WS-Security SAML token is supported.
    bool SAMLToken {};
    // Indicates whether or not WS-Security Kerberos token is supported.
    bool KerberosToken {};
    // Indicates whether or not WS-Security REL token is supported.
    bool RELToken {};
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<tt_SecurityCapabilitiesExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SecurityCapabilities
template<>
struct xml_convert::XmlTraits<tt_SecurityCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TLS1.1", &tt_SecurityCapabilities::TLS1_1, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TLS1.2", &tt_SecurityCapabilities::TLS1_2, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("OnboardKeyGeneration", &tt_SecurityCapabilities::OnboardKeyGeneration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AccessPolicyConfig", &tt_SecurityCapabilities::AccessPolicyConfig, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("X.509Token", &tt_SecurityCapabilities::X_509Token, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SAMLToken", &tt_SecurityCapabilities::SAMLToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("KerberosToken", &tt_SecurityCapabilities::KerberosToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RELToken", &tt_SecurityCapabilities::RELToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_SecurityCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Extension", &tt_SecurityCapabilities::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_SecurityCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// DeviceCapabilitiesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DeviceCapabilitiesExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_DeviceCapabilitiesExtension
template<>
struct xml_convert::XmlTraits<tt_DeviceCapabilitiesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_DeviceCapabilitiesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// DeviceCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DeviceCapabilities {
    // Device service URI.
    std::string XAddr;
    // Network capabilities.
    std::optional<tt_NetworkCapabilities> Network;
    // System capabilities.
    std::optional<tt_SystemCapabilities> System;
    // I/O capabilities.
    std::optional<tt_IOCapabilities> IO;
    // Security capabilities.
    std::optional<tt_SecurityCapabilities> Security;
    std::optional<tt_DeviceCapabilitiesExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_DeviceCapabilities
template<>
struct xml_convert::XmlTraits<tt_DeviceCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_DeviceCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Network", &tt_DeviceCapabilities::Network, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("System", &tt_DeviceCapabilities::System, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IO", &tt_DeviceCapabilities::IO, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Security", &tt_DeviceCapabilities::Security, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_DeviceCapabilities::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_DeviceCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// EventCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_EventCapabilities {
    // Event service URI.
    std::string XAddr;
    // Indicates whether or not WS Subscription policy is supported.
    bool WSSubscriptionPolicySupport {};
    // Indicates whether or not WS Pull Point is supported.
    bool WSPullPointSupport {};
    // Indicates whether or not WS Pausable Subscription Manager Interface is supported.
    bool WSPausableSubscriptionManagerInterfaceSupport {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_EventCapabilities
template<>
struct xml_convert::XmlTraits<tt_EventCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_EventCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WSSubscriptionPolicySupport", &tt_EventCapabilities::WSSubscriptionPolicySupport, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WSPullPointSupport", &tt_EventCapabilities::WSPullPointSupport, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WSPausableSubscriptionManagerInterfaceSupport", &tt_EventCapabilities::WSPausableSubscriptionManagerInterfaceSupport, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_EventCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_EventCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ImagingCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingCapabilities {
    // Imaging service URI.
    std::string XAddr;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ImagingCapabilities
template<>
struct xml_convert::XmlTraits<tt_ImagingCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_ImagingCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ImagingCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RealTimeStreamingCapabilitiesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RealTimeStreamingCapabilitiesExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_RealTimeStreamingCapabilitiesExtension
template<>
struct xml_convert::XmlTraits<tt_RealTimeStreamingCapabilitiesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_RealTimeStreamingCapabilitiesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// RealTimeStreamingCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RealTimeStreamingCapabilities {
    // Indicates whether or not RTP multicast is supported.
    std::optional<bool> RTPMulticast;
    // Indicates whether or not RTP over TCP is supported.
    std::optional<bool> RTP_TCP;
    // Indicates whether or not RTP/RTSP/TCP is supported.
    std::optional<bool> RTP_RTSP_TCP;
    std::optional<tt_RealTimeStreamingCapabilitiesExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RealTimeStreamingCapabilities
template<>
struct xml_convert::XmlTraits<tt_RealTimeStreamingCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RTPMulticast", &tt_RealTimeStreamingCapabilities::RTPMulticast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RTP_TCP", &tt_RealTimeStreamingCapabilities::RTP_TCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RTP_RTSP_TCP", &tt_RealTimeStreamingCapabilities::RTP_RTSP_TCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_RealTimeStreamingCapabilities::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_RealTimeStreamingCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ProfileCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ProfileCapabilities {
    // Maximum number of profiles.
    int32_t MaximumNumberOfProfiles {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ProfileCapabilities
template<>
struct xml_convert::XmlTraits<tt_ProfileCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MaximumNumberOfProfiles", &tt_ProfileCapabilities::MaximumNumberOfProfiles, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ProfileCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ProfileCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MediaCapabilitiesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MediaCapabilitiesExtension {
    tt_ProfileCapabilities ProfileCapabilities;
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MediaCapabilitiesExtension
template<>
struct xml_convert::XmlTraits<tt_MediaCapabilitiesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ProfileCapabilities", &tt_MediaCapabilitiesExtension::ProfileCapabilities, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MediaCapabilitiesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_MediaCapabilitiesExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MediaCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MediaCapabilities {
    // Media service URI.
    std::string XAddr;
    // Streaming capabilities.
    tt_RealTimeStreamingCapabilities StreamingCapabilities;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<tt_MediaCapabilitiesExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MediaCapabilities
template<>
struct xml_convert::XmlTraits<tt_MediaCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_MediaCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StreamingCapabilities", &tt_MediaCapabilities::StreamingCapabilities, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MediaCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Extension", &tt_MediaCapabilities::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_MediaCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZCapabilities {
    // PTZ service URI.
    std::string XAddr;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZCapabilities
template<>
struct xml_convert::XmlTraits<tt_PTZCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_PTZCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PTZCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_PTZCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// DeviceIOCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DeviceIOCapabilities {
    std::string XAddr;
    int32_t VideoSources {};
    int32_t VideoOutputs {};
    int32_t AudioSources {};
    int32_t AudioOutputs {};
    int32_t RelayOutputs {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_DeviceIOCapabilities
template<>
struct xml_convert::XmlTraits<tt_DeviceIOCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_DeviceIOCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoSources", &tt_DeviceIOCapabilities::VideoSources, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoOutputs", &tt_DeviceIOCapabilities::VideoOutputs, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioSources", &tt_DeviceIOCapabilities::AudioSources, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioOutputs", &tt_DeviceIOCapabilities::AudioOutputs, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RelayOutputs", &tt_DeviceIOCapabilities::RelayOutputs, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_DeviceIOCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_DeviceIOCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// DisplayCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DisplayCapabilities {
    std::string XAddr;
    // Indication that the SetLayout command supports only predefined layouts.
    bool FixedLayout {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_DisplayCapabilities
template<>
struct xml_convert::XmlTraits<tt_DisplayCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_DisplayCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FixedLayout", &tt_DisplayCapabilities::FixedLayout, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_DisplayCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_DisplayCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingCapabilities {
    std::string XAddr;
    bool ReceiverSource {};
    bool MediaProfileSource {};
    bool DynamicRecordings {};
    bool DynamicTracks {};
    int32_t MaxStringLength {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingCapabilities
template<>
struct xml_convert::XmlTraits<tt_RecordingCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_RecordingCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ReceiverSource", &tt_RecordingCapabilities::ReceiverSource, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MediaProfileSource", &tt_RecordingCapabilities::MediaProfileSource, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DynamicRecordings", &tt_RecordingCapabilities::DynamicRecordings, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DynamicTracks", &tt_RecordingCapabilities::DynamicTracks, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxStringLength", &tt_RecordingCapabilities::MaxStringLength, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SearchCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SearchCapabilities {
    std::string XAddr;
    bool MetadataSearch {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SearchCapabilities
template<>
struct xml_convert::XmlTraits<tt_SearchCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_SearchCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MetadataSearch", &tt_SearchCapabilities::MetadataSearch, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_SearchCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_SearchCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ReplayCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ReplayCapabilities {
    // The address of the replay service.
    std::string XAddr;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ReplayCapabilities
template<>
struct xml_convert::XmlTraits<tt_ReplayCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_ReplayCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ReplayCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ReplayCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ReceiverCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ReceiverCapabilities {
    // The address of the receiver service.
    std::string XAddr;
    // Indicates whether the device can receive RTP multicast streams.
    bool RTP_Multicast {};
    // Indicates whether the device can receive RTP/TCP streams
    bool RTP_TCP {};
    // Indicates whether the device can receive RTP/RTSP/TCP streams.
    bool RTP_RTSP_TCP {};
    // The maximum number of receivers supported by the device.
    int32_t SupportedReceivers {};
    // The maximum allowed length for RTSP URIs.
    int32_t MaximumRTSPURILength {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ReceiverCapabilities
template<>
struct xml_convert::XmlTraits<tt_ReceiverCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_ReceiverCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RTP_Multicast", &tt_ReceiverCapabilities::RTP_Multicast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RTP_TCP", &tt_ReceiverCapabilities::RTP_TCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RTP_RTSP_TCP", &tt_ReceiverCapabilities::RTP_RTSP_TCP, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedReceivers", &tt_ReceiverCapabilities::SupportedReceivers, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaximumRTSPURILength", &tt_ReceiverCapabilities::MaximumRTSPURILength, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ReceiverCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ReceiverCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AnalyticsDeviceExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsDeviceExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_AnalyticsDeviceExtension
template<>
struct xml_convert::XmlTraits<tt_AnalyticsDeviceExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AnalyticsDeviceExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// AnalyticsDeviceCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsDeviceCapabilities {
    std::string XAddr;
    // Obsolete property.
    std::optional<bool> RuleSupport;
    std::optional<tt_AnalyticsDeviceExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnalyticsDeviceCapabilities
template<>
struct xml_convert::XmlTraits<tt_AnalyticsDeviceCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XAddr", &tt_AnalyticsDeviceCapabilities::XAddr, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RuleSupport", &tt_AnalyticsDeviceCapabilities::RuleSupport, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_AnalyticsDeviceCapabilities::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_AnalyticsDeviceCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CapabilitiesExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CapabilitiesExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_CapabilitiesExtension2
template<>
struct xml_convert::XmlTraits<tt_CapabilitiesExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_CapabilitiesExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// CapabilitiesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CapabilitiesExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<tt_DeviceIOCapabilities> DeviceIO;
    std::optional<tt_DisplayCapabilities> Display;
    std::optional<tt_RecordingCapabilities> Recording;
    std::optional<tt_SearchCapabilities> Search;
    std::optional<tt_ReplayCapabilities> Replay;
    std::optional<tt_ReceiverCapabilities> Receiver;
    std::optional<tt_AnalyticsDeviceCapabilities> AnalyticsDevice;
    std::optional<tt_CapabilitiesExtension2> Extensions;
};


// XmlTraits for tt_CapabilitiesExtension
template<>
struct xml_convert::XmlTraits<tt_CapabilitiesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_CapabilitiesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("DeviceIO", &tt_CapabilitiesExtension::DeviceIO, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Display", &tt_CapabilitiesExtension::Display, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Recording", &tt_CapabilitiesExtension::Recording, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Search", &tt_CapabilitiesExtension::Search, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Replay", &tt_CapabilitiesExtension::Replay, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Receiver", &tt_CapabilitiesExtension::Receiver, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AnalyticsDevice", &tt_CapabilitiesExtension::AnalyticsDevice, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extensions", &tt_CapabilitiesExtension::Extensions, "tt", xml_convert::serialize_type::full)
    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Capabilities {
    // Analytics capabilities
    std::optional<tt_AnalyticsCapabilities> Analytics;
    // Device capabilities
    std::optional<tt_DeviceCapabilities> Device;
    // Event capabilities
    std::optional<tt_EventCapabilities> Events;
    // Imaging capabilities
    std::optional<tt_ImagingCapabilities> Imaging;
    // Media capabilities
    std::optional<tt_MediaCapabilities> Media;
    // PTZ capabilities
    std::optional<tt_PTZCapabilities> PTZ;
    std::optional<tt_CapabilitiesExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Capabilities
template<>
struct xml_convert::XmlTraits<tt_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Analytics", &tt_Capabilities::Analytics, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Device", &tt_Capabilities::Device, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Events", &tt_Capabilities::Events, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Imaging", &tt_Capabilities::Imaging, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Media", &tt_Capabilities::Media, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PTZ", &tt_Capabilities::PTZ, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Capabilities::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SystemLogType 枚举类型
// 基础类型: std::string
enum class  tt_SystemLogType {
    System,
    Access
};

// 字符串转换函数
inline std::string to_string(tt_SystemLogType value) {
    switch (value) {
        case tt_SystemLogType::System: return "System";
        case tt_SystemLogType::Access: return "Access";
        default: return "";
    }
}

inline bool from_string(tt_SystemLogType& value, const std::string& str) {
    if (str == "System") { value = tt_SystemLogType::System; return true; }
    if (str == "Access") { value = tt_SystemLogType::Access; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_SystemLogType
template<>
struct xml_convert::XmlValueAdapter<tt_SystemLogType> {
    static bool from_xml_val(tt_SystemLogType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_SystemLogType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_SystemLogType
template<>
struct xml_convert::XmlAttributeAdapter<tt_SystemLogType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_SystemLogType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_SystemLogType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// AttachmentData 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AttachmentData {
    xop_Include Include;
    std::optional<std::string> contentType;
};


// XmlTraits for tt_AttachmentData
template<>
struct xml_convert::XmlTraits<tt_AttachmentData> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Include", &tt_AttachmentData::Include, "xop", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("contentType", &tt_AttachmentData::contentType, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SystemLog 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SystemLog {
    // The log information as attachment data.
    std::optional<tt_AttachmentData> Binary;
    // The log information as character data.
    std::optional<std::string> String;
};


// XmlTraits for tt_SystemLog
template<>
struct xml_convert::XmlTraits<tt_SystemLog> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Binary", &tt_SystemLog::Binary, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("String", &tt_SystemLog::String, "tt", xml_convert::serialize_type::full)
    );
};


// SupportInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SupportInformation {
    // The support information as attachment data.
    std::optional<tt_AttachmentData> Binary;
    // The support information as character data.
    std::optional<std::string> String;
};


// XmlTraits for tt_SupportInformation
template<>
struct xml_convert::XmlTraits<tt_SupportInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Binary", &tt_SupportInformation::Binary, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("String", &tt_SupportInformation::String, "tt", xml_convert::serialize_type::full)
    );
};


// BinaryData 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_BinaryData {
    // base64 encoded binary data.
    std::string Data;
    std::optional<std::string> contentType;
};


// XmlTraits for tt_BinaryData
template<>
struct xml_convert::XmlTraits<tt_BinaryData> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Data", &tt_BinaryData::Data, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("contentType", &tt_BinaryData::contentType, nullptr, xml_convert::serialize_type::attribute)
    );
};


// BackupFile 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_BackupFile {
    std::string Name;
    tt_AttachmentData Data;
};


// XmlTraits for tt_BackupFile
template<>
struct xml_convert::XmlTraits<tt_BackupFile> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_BackupFile::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Data", &tt_BackupFile::Data, "tt", xml_convert::serialize_type::full)
    );
};


// SystemLogUri 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SystemLogUri {
    tt_SystemLogType Type;
    std::string Uri;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SystemLogUri
template<>
struct xml_convert::XmlTraits<tt_SystemLogUri> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_SystemLogUri::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Uri", &tt_SystemLogUri::Uri, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_SystemLogUri::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_SystemLogUri::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SystemLogUriList 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SystemLogUriList {
    std::vector<tt_SystemLogUri> SystemLog;
};


// XmlTraits for tt_SystemLogUriList
template<>
struct xml_convert::XmlTraits<tt_SystemLogUriList> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SystemLog", &tt_SystemLogUriList::SystemLog, "tt", xml_convert::serialize_type::full)
    );
};


// FactoryDefaultType 枚举类型
// 基础类型: std::string
enum class  tt_FactoryDefaultType {
    Hard,
    Soft
};

// 字符串转换函数
inline std::string to_string(tt_FactoryDefaultType value) {
    switch (value) {
        case tt_FactoryDefaultType::Hard: return "Hard";
        case tt_FactoryDefaultType::Soft: return "Soft";
        default: return "";
    }
}

inline bool from_string(tt_FactoryDefaultType& value, const std::string& str) {
    if (str == "Hard") { value = tt_FactoryDefaultType::Hard; return true; }
    if (str == "Soft") { value = tt_FactoryDefaultType::Soft; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_FactoryDefaultType
template<>
struct xml_convert::XmlValueAdapter<tt_FactoryDefaultType> {
    static bool from_xml_val(tt_FactoryDefaultType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_FactoryDefaultType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_FactoryDefaultType
template<>
struct xml_convert::XmlAttributeAdapter<tt_FactoryDefaultType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_FactoryDefaultType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_FactoryDefaultType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// SetDateTimeType 枚举类型
// 基础类型: std::string
enum class  tt_SetDateTimeType {
    Manual,
    NTP
};

// 字符串转换函数
inline std::string to_string(tt_SetDateTimeType value) {
    switch (value) {
        case tt_SetDateTimeType::Manual: return "Manual";
        case tt_SetDateTimeType::NTP: return "NTP";
        default: return "";
    }
}

inline bool from_string(tt_SetDateTimeType& value, const std::string& str) {
    if (str == "Manual") { value = tt_SetDateTimeType::Manual; return true; }
    if (str == "NTP") { value = tt_SetDateTimeType::NTP; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_SetDateTimeType
template<>
struct xml_convert::XmlValueAdapter<tt_SetDateTimeType> {
    static bool from_xml_val(tt_SetDateTimeType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_SetDateTimeType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_SetDateTimeType
template<>
struct xml_convert::XmlAttributeAdapter<tt_SetDateTimeType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_SetDateTimeType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_SetDateTimeType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// TimeZone 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_TimeZone {
    // Posix timezone string.
    std::string TZ;
};


// XmlTraits for tt_TimeZone
template<>
struct xml_convert::XmlTraits<tt_TimeZone> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TZ", &tt_TimeZone::TZ, "tt", xml_convert::serialize_type::full)
    );
};


// Time 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Time {
    // Range is 0 to 23.
    int32_t Hour {};
    // Range is 0 to 59.
    int32_t Minute {};
    // Range is 0 to 61 (typically 59).
    int32_t Second {};
};


// XmlTraits for tt_Time
template<>
struct xml_convert::XmlTraits<tt_Time> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Hour", &tt_Time::Hour, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Minute", &tt_Time::Minute, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Second", &tt_Time::Second, "tt", xml_convert::serialize_type::full)
    );
};


// Date 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Date {
    int32_t Year {};
    // Range is 1 to 12.
    int32_t Month {};
    // Range is 1 to 31.
    int32_t Day {};
};


// XmlTraits for tt_Date
template<>
struct xml_convert::XmlTraits<tt_Date> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Year", &tt_Date::Year, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Month", &tt_Date::Month, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Day", &tt_Date::Day, "tt", xml_convert::serialize_type::full)
    );
};


// DateTime 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DateTime {
    tt_Time Time;
    tt_Date Date;
};


// XmlTraits for tt_DateTime
template<>
struct xml_convert::XmlTraits<tt_DateTime> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Time", &tt_DateTime::Time, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Date", &tt_DateTime::Date, "tt", xml_convert::serialize_type::full)
    );
};


// SystemDateTimeExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SystemDateTimeExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_SystemDateTimeExtension
template<>
struct xml_convert::XmlTraits<tt_SystemDateTimeExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_SystemDateTimeExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SystemDateTime 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SystemDateTime {
    // Indicates if the time is set manully or through NTP.
    tt_SetDateTimeType DateTimeType;
    // Informative indicator whether daylight savings is currently on/off.
    bool DaylightSavings {};
    // Timezone information in Posix format.
    std::optional<tt_TimeZone> TimeZone;
    // Current system date and time in UTC format. This field is mandatory since version 2.0.
    std::optional<tt_DateTime> UTCDateTime;
    // Date and time in local format.
    std::optional<tt_DateTime> LocalDateTime;
    std::optional<tt_SystemDateTimeExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SystemDateTime
template<>
struct xml_convert::XmlTraits<tt_SystemDateTime> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DateTimeType", &tt_SystemDateTime::DateTimeType, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DaylightSavings", &tt_SystemDateTime::DaylightSavings, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TimeZone", &tt_SystemDateTime::TimeZone, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UTCDateTime", &tt_SystemDateTime::UTCDateTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("LocalDateTime", &tt_SystemDateTime::LocalDateTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_SystemDateTime::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_SystemDateTime::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RemoteUser 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RemoteUser {
    std::string Username;
    std::optional<std::string> Password;
    bool UseDerivedPassword {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RemoteUser
template<>
struct xml_convert::XmlTraits<tt_RemoteUser> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Username", &tt_RemoteUser::Username, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Password", &tt_RemoteUser::Password, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UseDerivedPassword", &tt_RemoteUser::UseDerivedPassword, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RemoteUser::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RemoteUser::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// UserLevel 枚举类型
// 基础类型: std::string
enum class  tt_UserLevel {
    Administrator,
    Operator,
    User,
    Anonymous,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_UserLevel value) {
    switch (value) {
        case tt_UserLevel::Administrator: return "Administrator";
        case tt_UserLevel::Operator: return "Operator";
        case tt_UserLevel::User: return "User";
        case tt_UserLevel::Anonymous: return "Anonymous";
        case tt_UserLevel::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_UserLevel& value, const std::string& str) {
    if (str == "Administrator") { value = tt_UserLevel::Administrator; return true; }
    if (str == "Operator") { value = tt_UserLevel::Operator; return true; }
    if (str == "User") { value = tt_UserLevel::User; return true; }
    if (str == "Anonymous") { value = tt_UserLevel::Anonymous; return true; }
    if (str == "Extended") { value = tt_UserLevel::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_UserLevel
template<>
struct xml_convert::XmlValueAdapter<tt_UserLevel> {
    static bool from_xml_val(tt_UserLevel& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_UserLevel& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_UserLevel
template<>
struct xml_convert::XmlAttributeAdapter<tt_UserLevel> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_UserLevel& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_UserLevel& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// UserRole 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_UserRole {
    // Name of the editable user level.
    std::string Name;
    // Names of the permitted function for the editable user level. The names must be prepended by the namespace prefix and colon.
    tt_StringList Functions;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_UserRole
template<>
struct xml_convert::XmlTraits<tt_UserRole> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_UserRole::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Functions", &tt_UserRole::Functions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_UserRole::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// UserExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_UserExtension {
    // The names of the roles assigned to the user.
    tt_StringList Roles;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_UserExtension
template<>
struct xml_convert::XmlTraits<tt_UserExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Roles", &tt_UserExtension::Roles, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_UserExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// User 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_User {
    // Username string.
    std::string Username;
    // Password string.
    std::optional<std::string> Password;
    // User level string.
    tt_UserLevel UserLevel;
    std::optional<tt_UserExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_User
template<>
struct xml_convert::XmlTraits<tt_User> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Username", &tt_User::Username, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Password", &tt_User::Password, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UserLevel", &tt_User::UserLevel, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_User::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_User::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CertificateGenerationParametersExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CertificateGenerationParametersExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_CertificateGenerationParametersExtension
template<>
struct xml_convert::XmlTraits<tt_CertificateGenerationParametersExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_CertificateGenerationParametersExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// CertificateGenerationParameters 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CertificateGenerationParameters {
    std::optional<std::string> CertificateID;
    std::optional<std::string> Subject;
    std::optional<std::string> ValidNotBefore;
    std::optional<std::string> ValidNotAfter;
    std::optional<tt_CertificateGenerationParametersExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_CertificateGenerationParameters
template<>
struct xml_convert::XmlTraits<tt_CertificateGenerationParameters> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tt_CertificateGenerationParameters::CertificateID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Subject", &tt_CertificateGenerationParameters::Subject, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ValidNotBefore", &tt_CertificateGenerationParameters::ValidNotBefore, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ValidNotAfter", &tt_CertificateGenerationParameters::ValidNotAfter, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_CertificateGenerationParameters::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_CertificateGenerationParameters::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Certificate 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Certificate {
    // Certificate id.
    std::string CertificateID;
    // base64 encoded DER representation of certificate.
    tt_BinaryData Certificate;
};


// XmlTraits for tt_Certificate
template<>
struct xml_convert::XmlTraits<tt_Certificate> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tt_Certificate::CertificateID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Certificate", &tt_Certificate::Certificate, "tt", xml_convert::serialize_type::full)
    );
};


// CertificateStatus 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CertificateStatus {
    // Certificate id.
    std::string CertificateID;
    // Indicates whether or not a certificate is used in an HTTPS configuration.
    bool Status {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_CertificateStatus
template<>
struct xml_convert::XmlTraits<tt_CertificateStatus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tt_CertificateStatus::CertificateID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Status", &tt_CertificateStatus::Status, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_CertificateStatus::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_CertificateStatus::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CertificateWithPrivateKey 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CertificateWithPrivateKey {
    std::optional<std::string> CertificateID;
    tt_BinaryData Certificate;
    tt_BinaryData PrivateKey;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_CertificateWithPrivateKey
template<>
struct xml_convert::XmlTraits<tt_CertificateWithPrivateKey> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tt_CertificateWithPrivateKey::CertificateID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Certificate", &tt_CertificateWithPrivateKey::Certificate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PrivateKey", &tt_CertificateWithPrivateKey::PrivateKey, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_CertificateWithPrivateKey::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_CertificateWithPrivateKey::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CertificateUsage 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CertificateUsage {
    // Value content based on xs:string
    std::string value;
    bool Critical {};
};


// XmlTraits for tt_CertificateUsage
template<>
struct xml_convert::XmlTraits<tt_CertificateUsage> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &tt_CertificateUsage::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Critical", &tt_CertificateUsage::Critical, nullptr, xml_convert::serialize_type::attribute)
    );
};


// DateTimeRange 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DateTimeRange {
    std::string From;
    std::string Until;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_DateTimeRange
template<>
struct xml_convert::XmlTraits<tt_DateTimeRange> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("From", &tt_DateTimeRange::From, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Until", &tt_DateTimeRange::Until, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_DateTimeRange::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_DateTimeRange::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CertificateInformationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CertificateInformationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_CertificateInformationExtension
template<>
struct xml_convert::XmlTraits<tt_CertificateInformationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_CertificateInformationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// CertificateInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CertificateInformation {
    std::string CertificateID;
    std::optional<std::string> IssuerDN;
    std::optional<std::string> SubjectDN;
    std::optional<tt_CertificateUsage> KeyUsage;
    std::optional<tt_CertificateUsage> ExtendedKeyUsage;
    std::optional<int32_t> KeyLength;
    std::optional<std::string> Version;
    std::optional<std::string> SerialNum;
    // Validity Range is from "NotBefore" to "NotAfter"; the corresponding DateTimeRange is from "From" to "Until"
    std::optional<std::string> SignatureAlgorithm;
    std::optional<tt_DateTimeRange> Validity;
    std::optional<tt_CertificateInformationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_CertificateInformation
template<>
struct xml_convert::XmlTraits<tt_CertificateInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tt_CertificateInformation::CertificateID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IssuerDN", &tt_CertificateInformation::IssuerDN, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SubjectDN", &tt_CertificateInformation::SubjectDN, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("KeyUsage", &tt_CertificateInformation::KeyUsage, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ExtendedKeyUsage", &tt_CertificateInformation::ExtendedKeyUsage, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("KeyLength", &tt_CertificateInformation::KeyLength, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Version", &tt_CertificateInformation::Version, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SerialNum", &tt_CertificateInformation::SerialNum, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SignatureAlgorithm", &tt_CertificateInformation::SignatureAlgorithm, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Validity", &tt_CertificateInformation::Validity, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_CertificateInformation::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_CertificateInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// TLSConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_TLSConfiguration {
    std::string CertificateID;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_TLSConfiguration
template<>
struct xml_convert::XmlTraits<tt_TLSConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tt_TLSConfiguration::CertificateID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_TLSConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_TLSConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// EapMethodExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_EapMethodExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_EapMethodExtension
template<>
struct xml_convert::XmlTraits<tt_EapMethodExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_EapMethodExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// EAPMethodConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_EAPMethodConfiguration {
    // Confgiuration information for TLS Method.
    std::optional<tt_TLSConfiguration> TLSConfiguration;
    // Password for those EAP Methods that require a password. The password shall never be returned on a get method.
    std::optional<std::string> Password;
    std::optional<tt_EapMethodExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_EAPMethodConfiguration
template<>
struct xml_convert::XmlTraits<tt_EAPMethodConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TLSConfiguration", &tt_EAPMethodConfiguration::TLSConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Password", &tt_EAPMethodConfiguration::Password, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_EAPMethodConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_EAPMethodConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Dot1XConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot1XConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_Dot1XConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_Dot1XConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_Dot1XConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Dot1XConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Dot1XConfiguration {
    tt_ReferenceToken Dot1XConfigurationToken;
    std::string Identity;
    std::optional<std::string> AnonymousID;
    // EAP Method type as defined in IANA EAP Registry.
    int32_t EAPMethod {};
    std::vector<std::string> CACertificateID;
    std::optional<tt_EAPMethodConfiguration> EAPMethodConfiguration;
    std::optional<tt_Dot1XConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Dot1XConfiguration
template<>
struct xml_convert::XmlTraits<tt_Dot1XConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Dot1XConfigurationToken", &tt_Dot1XConfiguration::Dot1XConfigurationToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Identity", &tt_Dot1XConfiguration::Identity, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AnonymousID", &tt_Dot1XConfiguration::AnonymousID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EAPMethod", &tt_Dot1XConfiguration::EAPMethod, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CACertificateID", &tt_Dot1XConfiguration::CACertificateID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EAPMethodConfiguration", &tt_Dot1XConfiguration::EAPMethodConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Dot1XConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_Dot1XConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GenericEapPwdConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_GenericEapPwdConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_GenericEapPwdConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_GenericEapPwdConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_GenericEapPwdConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// RelayLogicalState 枚举类型
// 基础类型: std::string
enum class  tt_RelayLogicalState {
    active,
    inactive
};

// 字符串转换函数
inline std::string to_string(tt_RelayLogicalState value) {
    switch (value) {
        case tt_RelayLogicalState::active: return "active";
        case tt_RelayLogicalState::inactive: return "inactive";
        default: return "";
    }
}

inline bool from_string(tt_RelayLogicalState& value, const std::string& str) {
    if (str == "active") { value = tt_RelayLogicalState::active; return true; }
    if (str == "inactive") { value = tt_RelayLogicalState::inactive; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_RelayLogicalState
template<>
struct xml_convert::XmlValueAdapter<tt_RelayLogicalState> {
    static bool from_xml_val(tt_RelayLogicalState& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_RelayLogicalState& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_RelayLogicalState
template<>
struct xml_convert::XmlAttributeAdapter<tt_RelayLogicalState> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_RelayLogicalState& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_RelayLogicalState& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// RelayIdleState 枚举类型
// 基础类型: std::string
enum class  tt_RelayIdleState {
    closed,
    open
};

// 字符串转换函数
inline std::string to_string(tt_RelayIdleState value) {
    switch (value) {
        case tt_RelayIdleState::closed: return "closed";
        case tt_RelayIdleState::open: return "open";
        default: return "";
    }
}

inline bool from_string(tt_RelayIdleState& value, const std::string& str) {
    if (str == "closed") { value = tt_RelayIdleState::closed; return true; }
    if (str == "open") { value = tt_RelayIdleState::open; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_RelayIdleState
template<>
struct xml_convert::XmlValueAdapter<tt_RelayIdleState> {
    static bool from_xml_val(tt_RelayIdleState& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_RelayIdleState& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_RelayIdleState
template<>
struct xml_convert::XmlAttributeAdapter<tt_RelayIdleState> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_RelayIdleState& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_RelayIdleState& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// RelayMode 枚举类型
// 基础类型: std::string
enum class  tt_RelayMode {
    Monostable,
    Bistable
};

// 字符串转换函数
inline std::string to_string(tt_RelayMode value) {
    switch (value) {
        case tt_RelayMode::Monostable: return "Monostable";
        case tt_RelayMode::Bistable: return "Bistable";
        default: return "";
    }
}

inline bool from_string(tt_RelayMode& value, const std::string& str) {
    if (str == "Monostable") { value = tt_RelayMode::Monostable; return true; }
    if (str == "Bistable") { value = tt_RelayMode::Bistable; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_RelayMode
template<>
struct xml_convert::XmlValueAdapter<tt_RelayMode> {
    static bool from_xml_val(tt_RelayMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_RelayMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_RelayMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_RelayMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_RelayMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_RelayMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// RelayOutputSettings 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RelayOutputSettings {
    /*
     * 'Bistable' or 'Monostable'
     *
     * Bistable – After setting the state, the relay remains in this state.
     * Monostable – After setting the state, the relay returns to its idle state after the specified time.
     */
    tt_RelayMode Mode;
    // Time after which the relay returns to its idle state if it is in monostable mode. If the Mode field is set to bistable mode the value of the parameter can be ignored.
    my_Duration DelayTime;
    /*
     * 'open' or 'closed'
     *
     * 'open' means that the relay is open when the relay state is set to 'inactive' through the trigger command and closed when the state is set to 'active' through the same command.
     * 'closed' means that the relay is closed when the relay state is set to 'inactive' through the trigger command and open when the state is set to 'active' through the same command.
     */
    tt_RelayIdleState IdleState;
};


// XmlTraits for tt_RelayOutputSettings
template<>
struct xml_convert::XmlTraits<tt_RelayOutputSettings> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_RelayOutputSettings::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DelayTime", &tt_RelayOutputSettings::DelayTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IdleState", &tt_RelayOutputSettings::IdleState, "tt", xml_convert::serialize_type::full)
    );
};


// RelayOutput 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RelayOutput : public tt_DeviceEntity {
    tt_RelayOutputSettings Properties;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RelayOutput
template<>
struct xml_convert::XmlTraits<tt_RelayOutput> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_DeviceEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Properties", &tt_RelayOutput::Properties, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RelayOutput::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RelayOutput::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// DigitalIdleState 枚举类型
// 基础类型: std::string
enum class  tt_DigitalIdleState {
    closed,
    open
};

// 字符串转换函数
inline std::string to_string(tt_DigitalIdleState value) {
    switch (value) {
        case tt_DigitalIdleState::closed: return "closed";
        case tt_DigitalIdleState::open: return "open";
        default: return "";
    }
}

inline bool from_string(tt_DigitalIdleState& value, const std::string& str) {
    if (str == "closed") { value = tt_DigitalIdleState::closed; return true; }
    if (str == "open") { value = tt_DigitalIdleState::open; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_DigitalIdleState
template<>
struct xml_convert::XmlValueAdapter<tt_DigitalIdleState> {
    static bool from_xml_val(tt_DigitalIdleState& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_DigitalIdleState& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_DigitalIdleState
template<>
struct xml_convert::XmlAttributeAdapter<tt_DigitalIdleState> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_DigitalIdleState& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_DigitalIdleState& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// DigitalInput 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DigitalInput : public tt_DeviceEntity {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indicate the Digital IdleState status.
    std::optional<tt_DigitalIdleState> IdleState;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_DigitalInput
template<>
struct xml_convert::XmlTraits<tt_DigitalInput> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_DeviceEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_DigitalInput::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("IdleState", &tt_DigitalInput::IdleState, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_DigitalInput::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// PTZSpacesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZSpacesExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZSpacesExtension
template<>
struct xml_convert::XmlTraits<tt_PTZSpacesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZSpacesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZSpaces 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZSpaces {
    /*
     * The Generic Pan/Tilt Position space is provided by every PTZ node that supports absolute Pan/Tilt, since it does not relate to a specific physical range.
     * Instead, the range should be defined as the full range of the PTZ unit normalized to the range -1 to 1 resulting in the following space description.
     */
    std::vector<tt_Space2DDescription> AbsolutePanTiltPositionSpace;
    /*
     * The Generic Zoom Position Space is provided by every PTZ node that supports absolute Zoom, since it does not relate to a specific physical range.
     * Instead, the range should be defined as the full range of the Zoom normalized to the range 0 (wide) to 1 (tele).
     * There is no assumption about how the generic zoom range is mapped to magnification, FOV or other physical zoom dimension.
     */
    std::vector<tt_Space1DDescription> AbsoluteZoomPositionSpace;
    /*
     * The Generic Pan/Tilt translation space is provided by every PTZ node that supports relative Pan/Tilt, since it does not relate to a specific physical range.
     * Instead, the range should be defined as the full positive and negative translation range of the PTZ unit normalized to the range -1 to 1,
     * where positive translation would mean clockwise rotation or movement in right/up direction resulting in the following space description.
     */
    std::vector<tt_Space2DDescription> RelativePanTiltTranslationSpace;
    /*
     * The Generic Zoom Translation Space is provided by every PTZ node that supports relative Zoom, since it does not relate to a specific physical range.
     * Instead, the corresponding absolute range should be defined as the full positive and negative translation range of the Zoom normalized to the range -1 to1,
     * where a positive translation maps to a movement in TELE direction. The translation is signed to indicate direction (negative is to wide, positive is to tele).
     * There is no assumption about how the generic zoom range is mapped to magnification, FOV or other physical zoom dimension. This results in the following space description.
     */
    std::vector<tt_Space1DDescription> RelativeZoomTranslationSpace;
    /*
     * The generic Pan/Tilt velocity space shall be provided by every PTZ node, since it does not relate to a specific physical range.
     * Instead, the range should be defined as a range of the PTZ unit’s speed normalized to the range -1 to 1, where a positive velocity would map to clockwise
     * rotation or movement in the right/up direction. A signed speed can be independently specified for the pan and tilt component resulting in the following space description.
     */
    std::vector<tt_Space2DDescription> ContinuousPanTiltVelocitySpace;
    /*
     * The generic zoom velocity space specifies a zoom factor velocity without knowing the underlying physical model. The range should be normalized from -1 to 1,
     * where a positive velocity would map to TELE direction. A generic zoom velocity space description resembles the following.
     */
    std::vector<tt_Space1DDescription> ContinuousZoomVelocitySpace;
    /*
     * The speed space specifies the speed for a Pan/Tilt movement when moving to an absolute position or to a relative translation.
     * In contrast to the velocity spaces, speed spaces do not contain any directional information. The speed of a combined Pan/Tilt
     * movement is represented by a single non-negative scalar value.
     */
    std::vector<tt_Space1DDescription> PanTiltSpeedSpace;
    /*
     * The speed space specifies the speed for a Zoom movement when moving to an absolute position or to a relative translation.
     * In contrast to the velocity spaces, speed spaces do not contain any directional information.
     */
    std::vector<tt_Space1DDescription> ZoomSpeedSpace;
    std::optional<tt_PTZSpacesExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZSpaces
template<>
struct xml_convert::XmlTraits<tt_PTZSpaces> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AbsolutePanTiltPositionSpace", &tt_PTZSpaces::AbsolutePanTiltPositionSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AbsoluteZoomPositionSpace", &tt_PTZSpaces::AbsoluteZoomPositionSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RelativePanTiltTranslationSpace", &tt_PTZSpaces::RelativePanTiltTranslationSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RelativeZoomTranslationSpace", &tt_PTZSpaces::RelativeZoomTranslationSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ContinuousPanTiltVelocitySpace", &tt_PTZSpaces::ContinuousPanTiltVelocitySpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ContinuousZoomVelocitySpace", &tt_PTZSpaces::ContinuousZoomVelocitySpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PanTiltSpeedSpace", &tt_PTZSpaces::PanTiltSpeedSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ZoomSpeedSpace", &tt_PTZSpaces::ZoomSpeedSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZSpaces::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PTZSpaces::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPresetTourOperation 枚举类型
// 基础类型: std::string
enum class  tt_PTZPresetTourOperation {
    Start,
    Stop,
    Pause,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_PTZPresetTourOperation value) {
    switch (value) {
        case tt_PTZPresetTourOperation::Start: return "Start";
        case tt_PTZPresetTourOperation::Stop: return "Stop";
        case tt_PTZPresetTourOperation::Pause: return "Pause";
        case tt_PTZPresetTourOperation::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_PTZPresetTourOperation& value, const std::string& str) {
    if (str == "Start") { value = tt_PTZPresetTourOperation::Start; return true; }
    if (str == "Stop") { value = tt_PTZPresetTourOperation::Stop; return true; }
    if (str == "Pause") { value = tt_PTZPresetTourOperation::Pause; return true; }
    if (str == "Extended") { value = tt_PTZPresetTourOperation::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_PTZPresetTourOperation
template<>
struct xml_convert::XmlValueAdapter<tt_PTZPresetTourOperation> {
    static bool from_xml_val(tt_PTZPresetTourOperation& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_PTZPresetTourOperation& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_PTZPresetTourOperation
template<>
struct xml_convert::XmlAttributeAdapter<tt_PTZPresetTourOperation> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_PTZPresetTourOperation& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_PTZPresetTourOperation& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// PTZPresetTourSupportedExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourSupportedExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZPresetTourSupportedExtension
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourSupportedExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourSupportedExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZPresetTourSupported 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourSupported {
    // Indicates number of preset tours that can be created. Required preset tour operations shall be available for this PTZ Node if one or more preset tour is supported.
    int32_t MaximumNumberOfPresetTours {};
    // Indicates which preset tour operations are available for this PTZ Node.
    std::vector<tt_PTZPresetTourOperation> PTZPresetTourOperation;
    std::optional<tt_PTZPresetTourSupportedExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPresetTourSupported
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourSupported> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MaximumNumberOfPresetTours", &tt_PTZPresetTourSupported::MaximumNumberOfPresetTours, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PTZPresetTourOperation", &tt_PTZPresetTourSupported::PTZPresetTourOperation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZPresetTourSupported::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPresetTourSupported::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZNodeExtension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZNodeExtension2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZNodeExtension2
template<>
struct xml_convert::XmlTraits<tt_PTZNodeExtension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZNodeExtension2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZNodeExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZNodeExtension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Detail of supported Preset Tour feature.
    std::optional<tt_PTZPresetTourSupported> SupportedPresetTour;
    std::optional<tt_PTZNodeExtension2> Extension;
};


// XmlTraits for tt_PTZNodeExtension
template<>
struct xml_convert::XmlTraits<tt_PTZNodeExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZNodeExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("SupportedPresetTour", &tt_PTZNodeExtension::SupportedPresetTour, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZNodeExtension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// PTZNode 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZNode : public tt_DeviceEntity {
    // A unique identifier that is used to reference PTZ Nodes.
    std::optional<tt_Name> Name;
    // A list of Coordinate Systems available for the PTZ Node. For each Coordinate System, the PTZ Node MUST specify its allowed range.
    tt_PTZSpaces SupportedPTZSpaces;
    // All preset operations MUST be available for this PTZ Node if one preset is supported.
    int32_t MaximumNumberOfPresets {};
    // A boolean operator specifying the availability of a home position. If set to true, the Home Position Operations MUST be available for this PTZ Node.
    bool HomeSupported {};
    // A list of supported Auxiliary commands. If the list is not empty, the Auxiliary Operations MUST be available for this PTZ Node.
    std::vector<tt_AuxiliaryData> AuxiliaryCommands;
    std::optional<tt_PTZNodeExtension> Extension;
    // Indication whether the HomePosition of a Node is fixed or it can be changed via the SetHomePosition command.
    std::optional<bool> FixedHomePosition;
    // Indication whether the Node supports the geo-referenced move command.
    std::optional<bool> GeoMove;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZNode
template<>
struct xml_convert::XmlTraits<tt_PTZNode> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_DeviceEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_PTZNode::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportedPTZSpaces", &tt_PTZNode::SupportedPTZSpaces, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaximumNumberOfPresets", &tt_PTZNode::MaximumNumberOfPresets, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("HomeSupported", &tt_PTZNode::HomeSupported, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AuxiliaryCommands", &tt_PTZNode::AuxiliaryCommands, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZNode::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FixedHomePosition", &tt_PTZNode::FixedHomePosition, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("GeoMove", &tt_PTZNode::GeoMove, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_PTZNode::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// EFlipOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_EFlipOptionsExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_EFlipOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_EFlipOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_EFlipOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// EFlipOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_EFlipOptions {
    // Options of EFlip mode parameter.
    std::vector<tt_EFlipMode> Mode;
    std::optional<tt_EFlipOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_EFlipOptions
template<>
struct xml_convert::XmlTraits<tt_EFlipOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_EFlipOptions::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_EFlipOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_EFlipOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ReverseOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ReverseOptionsExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ReverseOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_ReverseOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ReverseOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ReverseOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ReverseOptions {
    // Options of Reverse mode parameter.
    std::vector<tt_ReverseMode> Mode;
    std::optional<tt_ReverseOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ReverseOptions
template<>
struct xml_convert::XmlTraits<tt_ReverseOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_ReverseOptions::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ReverseOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ReverseOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTControlDirectionOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTControlDirectionOptionsExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTControlDirectionOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_PTControlDirectionOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTControlDirectionOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTControlDirectionOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTControlDirectionOptions {
    // Supported options for EFlip feature.
    std::optional<tt_EFlipOptions> EFlip;
    // Supported options for Reverse feature.
    std::optional<tt_ReverseOptions> Reverse;
    std::optional<tt_PTControlDirectionOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTControlDirectionOptions
template<>
struct xml_convert::XmlTraits<tt_PTControlDirectionOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("EFlip", &tt_PTControlDirectionOptions::EFlip, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Reverse", &tt_PTControlDirectionOptions::Reverse, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTControlDirectionOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PTControlDirectionOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZConfigurationOptions2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZConfigurationOptions2 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZConfigurationOptions2
template<>
struct xml_convert::XmlTraits<tt_PTZConfigurationOptions2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZConfigurationOptions2::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZConfigurationOptions {
    // A list of supported coordinate systems including their range limitations.
    tt_PTZSpaces Spaces;
    // A timeout Range within which Timeouts are accepted by the PTZ Node.
    tt_DurationRange PTZTimeout;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Supported options for PT Direction Control.
    std::optional<tt_PTControlDirectionOptions> PTControlDirection;
    std::optional<tt_PTZConfigurationOptions2> Extension;
    /*
     * The list of acceleration ramps supported by the device. The
     * smallest acceleration value corresponds to the minimal index, the
     * highest acceleration corresponds to the maximum index.
     */
    std::optional<tt_IntList> PTZRamps;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_PTZConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Spaces", &tt_PTZConfigurationOptions::Spaces, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PTZTimeout", &tt_PTZConfigurationOptions::PTZTimeout, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PTZConfigurationOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("PTControlDirection", &tt_PTZConfigurationOptions::PTControlDirection, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZConfigurationOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PTZRamps", &tt_PTZConfigurationOptions::PTZRamps, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_PTZConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPreset 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPreset {
    // A list of preset position name.
    std::optional<tt_Name> Name;
    // A list of preset position.
    std::optional<tt_PTZVector> PTZPosition;
    std::optional<tt_ReferenceToken> token;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPreset
template<>
struct xml_convert::XmlTraits<tt_PTZPreset> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_PTZPreset::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PTZPosition", &tt_PTZPreset::PTZPosition, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("token", &tt_PTZPreset::token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPreset::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPresetTourState 枚举类型
// 基础类型: std::string
enum class  tt_PTZPresetTourState {
    Idle,
    Touring,
    Paused,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_PTZPresetTourState value) {
    switch (value) {
        case tt_PTZPresetTourState::Idle: return "Idle";
        case tt_PTZPresetTourState::Touring: return "Touring";
        case tt_PTZPresetTourState::Paused: return "Paused";
        case tt_PTZPresetTourState::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_PTZPresetTourState& value, const std::string& str) {
    if (str == "Idle") { value = tt_PTZPresetTourState::Idle; return true; }
    if (str == "Touring") { value = tt_PTZPresetTourState::Touring; return true; }
    if (str == "Paused") { value = tt_PTZPresetTourState::Paused; return true; }
    if (str == "Extended") { value = tt_PTZPresetTourState::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_PTZPresetTourState
template<>
struct xml_convert::XmlValueAdapter<tt_PTZPresetTourState> {
    static bool from_xml_val(tt_PTZPresetTourState& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_PTZPresetTourState& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_PTZPresetTourState
template<>
struct xml_convert::XmlAttributeAdapter<tt_PTZPresetTourState> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_PTZPresetTourState& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_PTZPresetTourState& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// PTZPresetTourDirection 枚举类型
// 基础类型: std::string
enum class  tt_PTZPresetTourDirection {
    Forward,
    Backward,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_PTZPresetTourDirection value) {
    switch (value) {
        case tt_PTZPresetTourDirection::Forward: return "Forward";
        case tt_PTZPresetTourDirection::Backward: return "Backward";
        case tt_PTZPresetTourDirection::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_PTZPresetTourDirection& value, const std::string& str) {
    if (str == "Forward") { value = tt_PTZPresetTourDirection::Forward; return true; }
    if (str == "Backward") { value = tt_PTZPresetTourDirection::Backward; return true; }
    if (str == "Extended") { value = tt_PTZPresetTourDirection::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_PTZPresetTourDirection
template<>
struct xml_convert::XmlValueAdapter<tt_PTZPresetTourDirection> {
    static bool from_xml_val(tt_PTZPresetTourDirection& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_PTZPresetTourDirection& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_PTZPresetTourDirection
template<>
struct xml_convert::XmlAttributeAdapter<tt_PTZPresetTourDirection> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_PTZPresetTourDirection& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_PTZPresetTourDirection& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// PTZPresetTourTypeExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourTypeExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZPresetTourTypeExtension
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourTypeExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourTypeExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZPresetTourPresetDetail 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourPresetDetail {
    // xs:choice group 1 (mutually exclusive)
    // Option to specify the preset position with Preset Token defined in advance.
    std::optional<tt_ReferenceToken> PresetToken;
    // xs:choice group 1 (mutually exclusive)
    // Option to specify the preset position with the home position of this PTZ Node. "False" to this parameter shall be treated as an invalid argument.
    std::optional<bool> Home;
    // xs:choice group 1 (mutually exclusive)
    // Option to specify the preset position with vector of PTZ node directly.
    std::optional<tt_PTZVector> PTZPosition;
    // xs:choice group 1 (mutually exclusive)
    std::optional<tt_PTZPresetTourTypeExtension> TypeExtension;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPresetTourPresetDetail
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourPresetDetail> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PresetToken", &tt_PTZPresetTourPresetDetail::PresetToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Home", &tt_PTZPresetTourPresetDetail::Home, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PTZPosition", &tt_PTZPresetTourPresetDetail::PTZPosition, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TypeExtension", &tt_PTZPresetTourPresetDetail::TypeExtension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourPresetDetail::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPresetTourPresetDetail::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPresetTourSpotExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourSpotExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZPresetTourSpotExtension
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourSpotExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourSpotExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZPresetTourSpot 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourSpot {
    // Detail definition of preset position of the tour spot.
    tt_PTZPresetTourPresetDetail PresetDetail;
    // Optional parameter to specify Pan/Tilt and Zoom speed on moving toward this tour spot.
    std::optional<tt_PTZSpeed> Speed;
    // Optional parameter to specify time duration of staying on this tour sport.
    std::optional<my_Duration> StayTime;
    std::optional<tt_PTZPresetTourSpotExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPresetTourSpot
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourSpot> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PresetDetail", &tt_PTZPresetTourSpot::PresetDetail, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tt_PTZPresetTourSpot::Speed, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StayTime", &tt_PTZPresetTourSpot::StayTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZPresetTourSpot::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPresetTourSpot::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPresetTourStatusExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourStatusExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZPresetTourStatusExtension
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourStatusExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourStatusExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZPresetTourStatus 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourStatus {
    // Indicates state of this preset tour by Idle/Touring/Paused.
    tt_PTZPresetTourState State;
    // Indicates a tour spot currently staying.
    std::optional<tt_PTZPresetTourSpot> CurrentTourSpot;
    std::optional<tt_PTZPresetTourStatusExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPresetTourStatus
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourStatus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("State", &tt_PTZPresetTourStatus::State, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CurrentTourSpot", &tt_PTZPresetTourStatus::CurrentTourSpot, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZPresetTourStatus::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPresetTourStatus::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPresetTourStartingConditionExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourStartingConditionExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZPresetTourStartingConditionExtension
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourStartingConditionExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourStartingConditionExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZPresetTourStartingCondition 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourStartingCondition {
    // Optional parameter to specify how many times the preset tour is recurred.
    std::optional<int32_t> RecurringTime;
    // Optional parameter to specify how long time duration the preset tour is recurred.
    std::optional<my_Duration> RecurringDuration;
    // Optional parameter to choose which direction the preset tour goes. Forward shall be chosen in case it is omitted.
    std::optional<tt_PTZPresetTourDirection> Direction;
    std::optional<tt_PTZPresetTourStartingConditionExtension> Extension;
    // Execute presets in random order. If set to true and Direction is also present, Direction will be ignored and presets of the Tour will be recalled randomly.
    std::optional<bool> RandomPresetOrder;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPresetTourStartingCondition
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourStartingCondition> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecurringTime", &tt_PTZPresetTourStartingCondition::RecurringTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RecurringDuration", &tt_PTZPresetTourStartingCondition::RecurringDuration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Direction", &tt_PTZPresetTourStartingCondition::Direction, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZPresetTourStartingCondition::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RandomPresetOrder", &tt_PTZPresetTourStartingCondition::RandomPresetOrder, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPresetTourStartingCondition::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPresetTourExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZPresetTourExtension
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PresetTour 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PresetTour {
    // Readable name of the preset tour.
    std::optional<tt_Name> Name;
    // Read only parameters to indicate the status of the preset tour.
    tt_PTZPresetTourStatus Status;
    // Auto Start flag of the preset tour. True allows the preset tour to be activated always.
    bool AutoStart {};
    // Parameters to specify the detail behavior of the preset tour.
    tt_PTZPresetTourStartingCondition StartingCondition;
    // A list of detail of touring spots including preset positions.
    std::vector<tt_PTZPresetTourSpot> TourSpot;
    std::optional<tt_PTZPresetTourExtension> Extension;
    // Unique identifier of this preset tour.
    std::optional<tt_ReferenceToken> token;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PresetTour
template<>
struct xml_convert::XmlTraits<tt_PresetTour> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_PresetTour::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Status", &tt_PresetTour::Status, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AutoStart", &tt_PresetTour::AutoStart, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StartingCondition", &tt_PresetTour::StartingCondition, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TourSpot", &tt_PresetTour::TourSpot, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PresetTour::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("token", &tt_PresetTour::token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_PresetTour::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPresetTourStartingConditionOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourStartingConditionOptionsExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZPresetTourStartingConditionOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourStartingConditionOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourStartingConditionOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZPresetTourStartingConditionOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourStartingConditionOptions {
    // Supported range of Recurring Time.
    std::optional<tt_IntRange> RecurringTime;
    // Supported range of Recurring Duration.
    std::optional<tt_DurationRange> RecurringDuration;
    // Supported options for Direction of Preset Tour.
    std::vector<tt_PTZPresetTourDirection> Direction;
    std::optional<tt_PTZPresetTourStartingConditionOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPresetTourStartingConditionOptions
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourStartingConditionOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecurringTime", &tt_PTZPresetTourStartingConditionOptions::RecurringTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RecurringDuration", &tt_PTZPresetTourStartingConditionOptions::RecurringDuration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Direction", &tt_PTZPresetTourStartingConditionOptions::Direction, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZPresetTourStartingConditionOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPresetTourStartingConditionOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPresetTourPresetDetailOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourPresetDetailOptionsExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PTZPresetTourPresetDetailOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourPresetDetailOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourPresetDetailOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PTZPresetTourPresetDetailOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourPresetDetailOptions {
    // A list of available Preset Tokens for tour spots.
    std::vector<tt_ReferenceToken> PresetToken;
    // An option to indicate Home postion for tour spots.
    std::optional<bool> Home;
    // Supported range of Pan and Tilt for tour spots.
    std::optional<tt_Space2DDescription> PanTiltPositionSpace;
    // Supported range of Zoom for a tour spot.
    std::optional<tt_Space1DDescription> ZoomPositionSpace;
    std::optional<tt_PTZPresetTourPresetDetailOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPresetTourPresetDetailOptions
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourPresetDetailOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PresetToken", &tt_PTZPresetTourPresetDetailOptions::PresetToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Home", &tt_PTZPresetTourPresetDetailOptions::Home, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PanTiltPositionSpace", &tt_PTZPresetTourPresetDetailOptions::PanTiltPositionSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ZoomPositionSpace", &tt_PTZPresetTourPresetDetailOptions::ZoomPositionSpace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PTZPresetTourPresetDetailOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPresetTourPresetDetailOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPresetTourSpotOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourSpotOptions {
    // Supported options for detail definition of preset position of the tour spot.
    tt_PTZPresetTourPresetDetailOptions PresetDetail;
    // Supported range of stay time for a tour spot.
    tt_DurationRange StayTime;
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPresetTourSpotOptions
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourSpotOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PresetDetail", &tt_PTZPresetTourSpotOptions::PresetDetail, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StayTime", &tt_PTZPresetTourSpotOptions::StayTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourSpotOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPresetTourSpotOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZPresetTourOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPresetTourOptions {
    // Indicates whether or not the AutoStart is supported.
    bool AutoStart {};
    // Supported options for Preset Tour Starting Condition.
    tt_PTZPresetTourStartingConditionOptions StartingCondition;
    // Supported options for Preset Tour Spot.
    tt_PTZPresetTourSpotOptions TourSpot;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPresetTourOptions
template<>
struct xml_convert::XmlTraits<tt_PTZPresetTourOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AutoStart", &tt_PTZPresetTourOptions::AutoStart, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StartingCondition", &tt_PTZPresetTourOptions::StartingCondition, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TourSpot", &tt_PTZPresetTourOptions::TourSpot, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PTZPresetTourOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPresetTourOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MoveAndTrackMethod 枚举类型
// 基础类型: std::string
enum class  tt_MoveAndTrackMethod {
    PresetToken,
    GeoLocation,
    PTZVector,
    ObjectID
};

// 字符串转换函数
inline std::string to_string(tt_MoveAndTrackMethod value) {
    switch (value) {
        case tt_MoveAndTrackMethod::PresetToken: return "PresetToken";
        case tt_MoveAndTrackMethod::GeoLocation: return "GeoLocation";
        case tt_MoveAndTrackMethod::PTZVector: return "PTZVector";
        case tt_MoveAndTrackMethod::ObjectID: return "ObjectID";
        default: return "";
    }
}

inline bool from_string(tt_MoveAndTrackMethod& value, const std::string& str) {
    if (str == "PresetToken") { value = tt_MoveAndTrackMethod::PresetToken; return true; }
    if (str == "GeoLocation") { value = tt_MoveAndTrackMethod::GeoLocation; return true; }
    if (str == "PTZVector") { value = tt_MoveAndTrackMethod::PTZVector; return true; }
    if (str == "ObjectID") { value = tt_MoveAndTrackMethod::ObjectID; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_MoveAndTrackMethod
template<>
struct xml_convert::XmlValueAdapter<tt_MoveAndTrackMethod> {
    static bool from_xml_val(tt_MoveAndTrackMethod& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_MoveAndTrackMethod& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_MoveAndTrackMethod
template<>
struct xml_convert::XmlAttributeAdapter<tt_MoveAndTrackMethod> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_MoveAndTrackMethod& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_MoveAndTrackMethod& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// FocusStatus 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FocusStatus {
    // Status of focus position.
    float Position {};
    // Status of focus MoveStatus.
    tt_MoveStatus MoveStatus;
    // Error status of focus.
    std::string Error;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_FocusStatus
template<>
struct xml_convert::XmlTraits<tt_FocusStatus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Position", &tt_FocusStatus::Position, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MoveStatus", &tt_FocusStatus::MoveStatus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Error", &tt_FocusStatus::Error, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_FocusStatus::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_FocusStatus::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ImagingStatus 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingStatus {
    tt_FocusStatus FocusStatus;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ImagingStatus
template<>
struct xml_convert::XmlTraits<tt_ImagingStatus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FocusStatus", &tt_ImagingStatus::FocusStatus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ImagingStatus::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ImagingStatus::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AFModes 枚举类型
// 基础类型: std::string
enum class  tt_AFModes {
    OnceAfterMove
};

// 字符串转换函数
inline std::string to_string(tt_AFModes value) {
    switch (value) {
        case tt_AFModes::OnceAfterMove: return "OnceAfterMove";
        default: return "";
    }
}

inline bool from_string(tt_AFModes& value, const std::string& str) {
    if (str == "OnceAfterMove") { value = tt_AFModes::OnceAfterMove; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_AFModes
template<>
struct xml_convert::XmlValueAdapter<tt_AFModes> {
    static bool from_xml_val(tt_AFModes& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_AFModes& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_AFModes
template<>
struct xml_convert::XmlAttributeAdapter<tt_AFModes> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_AFModes& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_AFModes& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// BacklightCompensationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_BacklightCompensationOptions {
    std::vector<tt_WideDynamicMode> Mode;
    tt_FloatRange Level;
};


// XmlTraits for tt_BacklightCompensationOptions
template<>
struct xml_convert::XmlTraits<tt_BacklightCompensationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_BacklightCompensationOptions::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_BacklightCompensationOptions::Level, "tt", xml_convert::serialize_type::full)
    );
};


// ExposureOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ExposureOptions {
    std::vector<tt_ExposureMode> Mode;
    std::vector<tt_ExposurePriority> Priority;
    tt_FloatRange MinExposureTime;
    tt_FloatRange MaxExposureTime;
    tt_FloatRange MinGain;
    tt_FloatRange MaxGain;
    tt_FloatRange MinIris;
    tt_FloatRange MaxIris;
    tt_FloatRange ExposureTime;
    tt_FloatRange Gain;
    tt_FloatRange Iris;
};


// XmlTraits for tt_ExposureOptions
template<>
struct xml_convert::XmlTraits<tt_ExposureOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_ExposureOptions::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Priority", &tt_ExposureOptions::Priority, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinExposureTime", &tt_ExposureOptions::MinExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxExposureTime", &tt_ExposureOptions::MaxExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinGain", &tt_ExposureOptions::MinGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxGain", &tt_ExposureOptions::MaxGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinIris", &tt_ExposureOptions::MinIris, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxIris", &tt_ExposureOptions::MaxIris, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ExposureTime", &tt_ExposureOptions::ExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Gain", &tt_ExposureOptions::Gain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Iris", &tt_ExposureOptions::Iris, "tt", xml_convert::serialize_type::full)
    );
};


// FocusOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FocusOptions {
    std::vector<tt_AutoFocusMode> AutoFocusModes;
    tt_FloatRange DefaultSpeed;
    tt_FloatRange NearLimit;
    tt_FloatRange FarLimit;
};


// XmlTraits for tt_FocusOptions
template<>
struct xml_convert::XmlTraits<tt_FocusOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AutoFocusModes", &tt_FocusOptions::AutoFocusModes, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultSpeed", &tt_FocusOptions::DefaultSpeed, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NearLimit", &tt_FocusOptions::NearLimit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FarLimit", &tt_FocusOptions::FarLimit, "tt", xml_convert::serialize_type::full)
    );
};


// WideDynamicRangeOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_WideDynamicRangeOptions {
    std::vector<tt_WideDynamicMode> Mode;
    tt_FloatRange Level;
};


// XmlTraits for tt_WideDynamicRangeOptions
template<>
struct xml_convert::XmlTraits<tt_WideDynamicRangeOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_WideDynamicRangeOptions::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_WideDynamicRangeOptions::Level, "tt", xml_convert::serialize_type::full)
    );
};


// WhiteBalanceOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_WhiteBalanceOptions {
    std::vector<tt_WhiteBalanceMode> Mode;
    tt_FloatRange YrGain;
    tt_FloatRange YbGain;
};


// XmlTraits for tt_WhiteBalanceOptions
template<>
struct xml_convert::XmlTraits<tt_WhiteBalanceOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_WhiteBalanceOptions::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("YrGain", &tt_WhiteBalanceOptions::YrGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("YbGain", &tt_WhiteBalanceOptions::YbGain, "tt", xml_convert::serialize_type::full)
    );
};


// ImagingOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingOptions {
    tt_BacklightCompensationOptions BacklightCompensation;
    tt_FloatRange Brightness;
    tt_FloatRange ColorSaturation;
    tt_FloatRange Contrast;
    tt_ExposureOptions Exposure;
    tt_FocusOptions Focus;
    std::vector<tt_IrCutFilterMode> IrCutFilterModes;
    tt_FloatRange Sharpness;
    tt_WideDynamicRangeOptions WideDynamicRange;
    tt_WhiteBalanceOptions WhiteBalance;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ImagingOptions
template<>
struct xml_convert::XmlTraits<tt_ImagingOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BacklightCompensation", &tt_ImagingOptions::BacklightCompensation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Brightness", &tt_ImagingOptions::Brightness, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ColorSaturation", &tt_ImagingOptions::ColorSaturation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Contrast", &tt_ImagingOptions::Contrast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Exposure", &tt_ImagingOptions::Exposure, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Focus", &tt_ImagingOptions::Focus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IrCutFilterModes", &tt_ImagingOptions::IrCutFilterModes, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Sharpness", &tt_ImagingOptions::Sharpness, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WideDynamicRange", &tt_ImagingOptions::WideDynamicRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WhiteBalance", &tt_ImagingOptions::WhiteBalance, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ImagingOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ImagingOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AbsoluteFocus 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AbsoluteFocus {
    // Position parameter for the absolute focus control.
    float Position {};
    // Speed parameter for the absolute focus control.
    std::optional<float> Speed;
};


// XmlTraits for tt_AbsoluteFocus
template<>
struct xml_convert::XmlTraits<tt_AbsoluteFocus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Position", &tt_AbsoluteFocus::Position, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tt_AbsoluteFocus::Speed, "tt", xml_convert::serialize_type::full)
    );
};


// RelativeFocus 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RelativeFocus {
    // Distance parameter for the relative focus control.
    float Distance {};
    // Speed parameter for the relative focus control.
    std::optional<float> Speed;
};


// XmlTraits for tt_RelativeFocus
template<>
struct xml_convert::XmlTraits<tt_RelativeFocus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Distance", &tt_RelativeFocus::Distance, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tt_RelativeFocus::Speed, "tt", xml_convert::serialize_type::full)
    );
};


// ContinuousFocus 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ContinuousFocus {
    // Speed parameter for the Continuous focus control.
    float Speed {};
};


// XmlTraits for tt_ContinuousFocus
template<>
struct xml_convert::XmlTraits<tt_ContinuousFocus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Speed", &tt_ContinuousFocus::Speed, "tt", xml_convert::serialize_type::full)
    );
};


// FocusMove 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FocusMove {
    // Parameters for the absolute focus control.
    std::optional<tt_AbsoluteFocus> Absolute;
    // Parameters for the relative focus control.
    std::optional<tt_RelativeFocus> Relative;
    // Parameter for the continuous focus control.
    std::optional<tt_ContinuousFocus> Continuous;
};


// XmlTraits for tt_FocusMove
template<>
struct xml_convert::XmlTraits<tt_FocusMove> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Absolute", &tt_FocusMove::Absolute, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Relative", &tt_FocusMove::Relative, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Continuous", &tt_FocusMove::Continuous, "tt", xml_convert::serialize_type::full)
    );
};


// AbsoluteFocusOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AbsoluteFocusOptions {
    // Valid ranges of the position.
    tt_FloatRange Position;
    // Valid ranges of the speed.
    std::optional<tt_FloatRange> Speed;
};


// XmlTraits for tt_AbsoluteFocusOptions
template<>
struct xml_convert::XmlTraits<tt_AbsoluteFocusOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Position", &tt_AbsoluteFocusOptions::Position, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tt_AbsoluteFocusOptions::Speed, "tt", xml_convert::serialize_type::full)
    );
};


// RelativeFocusOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RelativeFocusOptions {
    // Valid ranges of the distance.
    tt_FloatRange Distance;
    // Valid ranges of the speed.
    tt_FloatRange Speed;
};


// XmlTraits for tt_RelativeFocusOptions
template<>
struct xml_convert::XmlTraits<tt_RelativeFocusOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Distance", &tt_RelativeFocusOptions::Distance, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tt_RelativeFocusOptions::Speed, "tt", xml_convert::serialize_type::full)
    );
};


// ContinuousFocusOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ContinuousFocusOptions {
    // Valid ranges of the speed.
    tt_FloatRange Speed;
};


// XmlTraits for tt_ContinuousFocusOptions
template<>
struct xml_convert::XmlTraits<tt_ContinuousFocusOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Speed", &tt_ContinuousFocusOptions::Speed, "tt", xml_convert::serialize_type::full)
    );
};


// MoveOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MoveOptions {
    std::optional<tt_AbsoluteFocusOptions> Absolute;
    std::optional<tt_RelativeFocusOptions> Relative;
    std::optional<tt_ContinuousFocusOptions> Continuous;
};


// XmlTraits for tt_MoveOptions
template<>
struct xml_convert::XmlTraits<tt_MoveOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Absolute", &tt_MoveOptions::Absolute, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Relative", &tt_MoveOptions::Relative, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Continuous", &tt_MoveOptions::Continuous, "tt", xml_convert::serialize_type::full)
    );
};


// Enabled 枚举类型
// 基础类型: std::string
enum class  tt_Enabled {
    ENABLED,
    DISABLED
};

// 字符串转换函数
inline std::string to_string(tt_Enabled value) {
    switch (value) {
        case tt_Enabled::ENABLED: return "ENABLED";
        case tt_Enabled::DISABLED: return "DISABLED";
        default: return "";
    }
}

inline bool from_string(tt_Enabled& value, const std::string& str) {
    if (str == "ENABLED") { value = tt_Enabled::ENABLED; return true; }
    if (str == "DISABLED") { value = tt_Enabled::DISABLED; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_Enabled
template<>
struct xml_convert::XmlValueAdapter<tt_Enabled> {
    static bool from_xml_val(tt_Enabled& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_Enabled& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_Enabled
template<>
struct xml_convert::XmlAttributeAdapter<tt_Enabled> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_Enabled& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_Enabled& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// FocusStatus20Extension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FocusStatus20Extension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_FocusStatus20Extension
template<>
struct xml_convert::XmlTraits<tt_FocusStatus20Extension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_FocusStatus20Extension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// FocusStatus20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FocusStatus20 {
    // Status of focus position.
    float Position {};
    // Status of focus MoveStatus.
    tt_MoveStatus MoveStatus;
    // Error status of focus.
    std::optional<std::string> Error;
    std::optional<tt_FocusStatus20Extension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_FocusStatus20
template<>
struct xml_convert::XmlTraits<tt_FocusStatus20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Position", &tt_FocusStatus20::Position, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MoveStatus", &tt_FocusStatus20::MoveStatus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Error", &tt_FocusStatus20::Error, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_FocusStatus20::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_FocusStatus20::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ImagingStatus20Extension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingStatus20Extension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ImagingStatus20Extension
template<>
struct xml_convert::XmlTraits<tt_ImagingStatus20Extension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ImagingStatus20Extension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ImagingStatus20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingStatus20 {
    // Status of focus.
    std::optional<tt_FocusStatus20> FocusStatus20;
    std::optional<tt_ImagingStatus20Extension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ImagingStatus20
template<>
struct xml_convert::XmlTraits<tt_ImagingStatus20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FocusStatus20", &tt_ImagingStatus20::FocusStatus20, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImagingStatus20::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ImagingStatus20::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// IrCutFilterAutoBoundaryType 枚举类型
// 基础类型: std::string
enum class  tt_IrCutFilterAutoBoundaryType {
    Common,
    ToOn,
    ToOff,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_IrCutFilterAutoBoundaryType value) {
    switch (value) {
        case tt_IrCutFilterAutoBoundaryType::Common: return "Common";
        case tt_IrCutFilterAutoBoundaryType::ToOn: return "ToOn";
        case tt_IrCutFilterAutoBoundaryType::ToOff: return "ToOff";
        case tt_IrCutFilterAutoBoundaryType::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_IrCutFilterAutoBoundaryType& value, const std::string& str) {
    if (str == "Common") { value = tt_IrCutFilterAutoBoundaryType::Common; return true; }
    if (str == "ToOn") { value = tt_IrCutFilterAutoBoundaryType::ToOn; return true; }
    if (str == "ToOff") { value = tt_IrCutFilterAutoBoundaryType::ToOff; return true; }
    if (str == "Extended") { value = tt_IrCutFilterAutoBoundaryType::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_IrCutFilterAutoBoundaryType
template<>
struct xml_convert::XmlValueAdapter<tt_IrCutFilterAutoBoundaryType> {
    static bool from_xml_val(tt_IrCutFilterAutoBoundaryType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_IrCutFilterAutoBoundaryType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_IrCutFilterAutoBoundaryType
template<>
struct xml_convert::XmlAttributeAdapter<tt_IrCutFilterAutoBoundaryType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_IrCutFilterAutoBoundaryType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_IrCutFilterAutoBoundaryType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ToneCompensationMode 枚举类型
// 基础类型: std::string
enum class  tt_ToneCompensationMode {
    OFF,
    ON,
    AUTO
};

// 字符串转换函数
inline std::string to_string(tt_ToneCompensationMode value) {
    switch (value) {
        case tt_ToneCompensationMode::OFF: return "OFF";
        case tt_ToneCompensationMode::ON: return "ON";
        case tt_ToneCompensationMode::AUTO: return "AUTO";
        default: return "";
    }
}

inline bool from_string(tt_ToneCompensationMode& value, const std::string& str) {
    if (str == "OFF") { value = tt_ToneCompensationMode::OFF; return true; }
    if (str == "ON") { value = tt_ToneCompensationMode::ON; return true; }
    if (str == "AUTO") { value = tt_ToneCompensationMode::AUTO; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ToneCompensationMode
template<>
struct xml_convert::XmlValueAdapter<tt_ToneCompensationMode> {
    static bool from_xml_val(tt_ToneCompensationMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ToneCompensationMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ToneCompensationMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_ToneCompensationMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ToneCompensationMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ToneCompensationMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// DefoggingMode 枚举类型
// 基础类型: std::string
enum class  tt_DefoggingMode {
    OFF,
    ON,
    AUTO
};

// 字符串转换函数
inline std::string to_string(tt_DefoggingMode value) {
    switch (value) {
        case tt_DefoggingMode::OFF: return "OFF";
        case tt_DefoggingMode::ON: return "ON";
        case tt_DefoggingMode::AUTO: return "AUTO";
        default: return "";
    }
}

inline bool from_string(tt_DefoggingMode& value, const std::string& str) {
    if (str == "OFF") { value = tt_DefoggingMode::OFF; return true; }
    if (str == "ON") { value = tt_DefoggingMode::ON; return true; }
    if (str == "AUTO") { value = tt_DefoggingMode::AUTO; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_DefoggingMode
template<>
struct xml_convert::XmlValueAdapter<tt_DefoggingMode> {
    static bool from_xml_val(tt_DefoggingMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_DefoggingMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_DefoggingMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_DefoggingMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_DefoggingMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_DefoggingMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// BacklightCompensationOptions20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_BacklightCompensationOptions20 {
    // 'ON' or 'OFF'
    std::vector<tt_BacklightCompensationMode> Mode;
    // Level range of BacklightCompensation.
    std::optional<tt_FloatRange> Level;
};


// XmlTraits for tt_BacklightCompensationOptions20
template<>
struct xml_convert::XmlTraits<tt_BacklightCompensationOptions20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_BacklightCompensationOptions20::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_BacklightCompensationOptions20::Level, "tt", xml_convert::serialize_type::full)
    );
};


// ExposureOptions20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ExposureOptions20 {
    /*
     * Exposure Mode
     *
     * Auto – Enabled the exposure algorithm on the device.
     * Manual – Disabled exposure algorithm on the device.
     */
    std::vector<tt_ExposureMode> Mode;
    // The exposure priority mode (low noise/framerate).
    std::vector<tt_ExposurePriority> Priority;
    // Valid range of the Minimum ExposureTime.
    std::optional<tt_FloatRange> MinExposureTime;
    // Valid range of the Maximum ExposureTime.
    std::optional<tt_FloatRange> MaxExposureTime;
    // Valid range of the Minimum Gain.
    std::optional<tt_FloatRange> MinGain;
    // Valid range of the Maximum Gain.
    std::optional<tt_FloatRange> MaxGain;
    // Valid range of the Minimum Iris.
    std::optional<tt_FloatRange> MinIris;
    // Valid range of the Maximum Iris.
    std::optional<tt_FloatRange> MaxIris;
    // Valid range of the ExposureTime.
    std::optional<tt_FloatRange> ExposureTime;
    // Valid range of the Gain.
    std::optional<tt_FloatRange> Gain;
    // Valid range of the Iris.
    std::optional<tt_FloatRange> Iris;
};


// XmlTraits for tt_ExposureOptions20
template<>
struct xml_convert::XmlTraits<tt_ExposureOptions20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_ExposureOptions20::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Priority", &tt_ExposureOptions20::Priority, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinExposureTime", &tt_ExposureOptions20::MinExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxExposureTime", &tt_ExposureOptions20::MaxExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinGain", &tt_ExposureOptions20::MinGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxGain", &tt_ExposureOptions20::MaxGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MinIris", &tt_ExposureOptions20::MinIris, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxIris", &tt_ExposureOptions20::MaxIris, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ExposureTime", &tt_ExposureOptions20::ExposureTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Gain", &tt_ExposureOptions20::Gain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Iris", &tt_ExposureOptions20::Iris, "tt", xml_convert::serialize_type::full)
    );
};


// FocusOptions20Extension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FocusOptions20Extension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Supported options for auto focus. Options shall be chosen from tt:AFModes.
    std::optional<tt_StringAttrList> AFModes;
};


// XmlTraits for tt_FocusOptions20Extension
template<>
struct xml_convert::XmlTraits<tt_FocusOptions20Extension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_FocusOptions20Extension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("AFModes", &tt_FocusOptions20Extension::AFModes, "tt", xml_convert::serialize_type::full)
    );
};


// FocusOptions20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FocusOptions20 {
    /*
     * Supported modes for auto focus.
     *
     * AUTO - The device supports automatic focus adjustment.
     * MANUAL - The device supports manual focus adjustment.
     */
    std::vector<tt_AutoFocusMode> AutoFocusModes;
    // Valid range of DefaultSpeed.
    std::optional<tt_FloatRange> DefaultSpeed;
    // Valid range of NearLimit.
    std::optional<tt_FloatRange> NearLimit;
    // Valid range of FarLimit.
    std::optional<tt_FloatRange> FarLimit;
    std::optional<tt_FocusOptions20Extension> Extension;
};


// XmlTraits for tt_FocusOptions20
template<>
struct xml_convert::XmlTraits<tt_FocusOptions20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AutoFocusModes", &tt_FocusOptions20::AutoFocusModes, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefaultSpeed", &tt_FocusOptions20::DefaultSpeed, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NearLimit", &tt_FocusOptions20::NearLimit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FarLimit", &tt_FocusOptions20::FarLimit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_FocusOptions20::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// WideDynamicRangeOptions20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_WideDynamicRangeOptions20 {
    std::vector<tt_WideDynamicMode> Mode;
    std::optional<tt_FloatRange> Level;
};


// XmlTraits for tt_WideDynamicRangeOptions20
template<>
struct xml_convert::XmlTraits<tt_WideDynamicRangeOptions20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_WideDynamicRangeOptions20::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_WideDynamicRangeOptions20::Level, "tt", xml_convert::serialize_type::full)
    );
};


// WhiteBalanceOptions20Extension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_WhiteBalanceOptions20Extension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_WhiteBalanceOptions20Extension
template<>
struct xml_convert::XmlTraits<tt_WhiteBalanceOptions20Extension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_WhiteBalanceOptions20Extension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// WhiteBalanceOptions20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_WhiteBalanceOptions20 {
    /*
     * Mode of WhiteBalance.
     *
     * AUTO
     * MANUAL
     */
    std::vector<tt_WhiteBalanceMode> Mode;
    std::optional<tt_FloatRange> YrGain;
    std::optional<tt_FloatRange> YbGain;
    std::optional<tt_WhiteBalanceOptions20Extension> Extension;
};


// XmlTraits for tt_WhiteBalanceOptions20
template<>
struct xml_convert::XmlTraits<tt_WhiteBalanceOptions20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_WhiteBalanceOptions20::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("YrGain", &tt_WhiteBalanceOptions20::YrGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("YbGain", &tt_WhiteBalanceOptions20::YbGain, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_WhiteBalanceOptions20::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// ImageStabilizationOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImageStabilizationOptionsExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ImageStabilizationOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_ImageStabilizationOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ImageStabilizationOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ImageStabilizationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImageStabilizationOptions {
    // Supported options of Image Stabilization mode parameter.
    std::vector<tt_ImageStabilizationMode> Mode;
    // Valid range of the Image Stabilization.
    std::optional<tt_FloatRange> Level;
    std::optional<tt_ImageStabilizationOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ImageStabilizationOptions
template<>
struct xml_convert::XmlTraits<tt_ImageStabilizationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_ImageStabilizationOptions::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_ImageStabilizationOptions::Level, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImageStabilizationOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ImageStabilizationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// IrCutFilterAutoAdjustmentOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IrCutFilterAutoAdjustmentOptionsExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_IrCutFilterAutoAdjustmentOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_IrCutFilterAutoAdjustmentOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_IrCutFilterAutoAdjustmentOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// IrCutFilterAutoAdjustmentOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_IrCutFilterAutoAdjustmentOptions {
    // Supported options of boundary types for adjustment of Ir cut filter auto mode. The opptions shall be chosen from tt:IrCutFilterAutoBoundaryType.
    std::vector<std::string> BoundaryType;
    // Indicates whether or not boundary offset for toggling Ir cut filter is supported.
    std::optional<bool> BoundaryOffset;
    // Supported range of delay time for toggling Ir cut filter.
    std::optional<tt_DurationRange> ResponseTimeRange;
    std::optional<tt_IrCutFilterAutoAdjustmentOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_IrCutFilterAutoAdjustmentOptions
template<>
struct xml_convert::XmlTraits<tt_IrCutFilterAutoAdjustmentOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BoundaryType", &tt_IrCutFilterAutoAdjustmentOptions::BoundaryType, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BoundaryOffset", &tt_IrCutFilterAutoAdjustmentOptions::BoundaryOffset, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ResponseTimeRange", &tt_IrCutFilterAutoAdjustmentOptions::ResponseTimeRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_IrCutFilterAutoAdjustmentOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_IrCutFilterAutoAdjustmentOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ToneCompensationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ToneCompensationOptions {
    // Supported options for Tone Compensation mode. Its options shall be chosen from tt:ToneCompensationMode Type.
    std::vector<std::string> Mode;
    // Indicates whether or not support Level parameter for Tone Compensation.
    bool Level {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ToneCompensationOptions
template<>
struct xml_convert::XmlTraits<tt_ToneCompensationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_ToneCompensationOptions::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_ToneCompensationOptions::Level, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ToneCompensationOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ToneCompensationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// DefoggingOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_DefoggingOptions {
    // Supported options for Defogging mode. Its options shall be chosen from tt:DefoggingMode Type.
    std::vector<std::string> Mode;
    // Indicates whether or not support Level parameter for Defogging.
    bool Level {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_DefoggingOptions
template<>
struct xml_convert::XmlTraits<tt_DefoggingOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_DefoggingOptions::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Level", &tt_DefoggingOptions::Level, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_DefoggingOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_DefoggingOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// NoiseReductionOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_NoiseReductionOptions {
    // Indicates whether or not support Level parameter for NoiseReduction.
    bool Level {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_NoiseReductionOptions
template<>
struct xml_convert::XmlTraits<tt_NoiseReductionOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Level", &tt_NoiseReductionOptions::Level, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_NoiseReductionOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_NoiseReductionOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ImagingOptions20Extension4 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingOptions20Extension4 {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ImagingOptions20Extension4
template<>
struct xml_convert::XmlTraits<tt_ImagingOptions20Extension4> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ImagingOptions20Extension4::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ImagingOptions20Extension3 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingOptions20Extension3 {
    // Options of parameters for Tone Compensation feature.
    std::optional<tt_ToneCompensationOptions> ToneCompensationOptions;
    // Options of parameters for Defogging feature.
    std::optional<tt_DefoggingOptions> DefoggingOptions;
    // Options of parameter for Noise Reduction feature.
    std::optional<tt_NoiseReductionOptions> NoiseReductionOptions;
    std::optional<tt_ImagingOptions20Extension4> Extension;
};


// XmlTraits for tt_ImagingOptions20Extension3
template<>
struct xml_convert::XmlTraits<tt_ImagingOptions20Extension3> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ToneCompensationOptions", &tt_ImagingOptions20Extension3::ToneCompensationOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DefoggingOptions", &tt_ImagingOptions20Extension3::DefoggingOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NoiseReductionOptions", &tt_ImagingOptions20Extension3::NoiseReductionOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImagingOptions20Extension3::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// ImagingOptions20Extension2 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingOptions20Extension2 {
    // Options of parameters for adjustment of Ir cut filter auto mode.
    std::optional<tt_IrCutFilterAutoAdjustmentOptions> IrCutFilterAutoAdjustment;
    std::optional<tt_ImagingOptions20Extension3> Extension;
};


// XmlTraits for tt_ImagingOptions20Extension2
template<>
struct xml_convert::XmlTraits<tt_ImagingOptions20Extension2> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IrCutFilterAutoAdjustment", &tt_ImagingOptions20Extension2::IrCutFilterAutoAdjustment, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImagingOptions20Extension2::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// ImagingOptions20Extension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingOptions20Extension {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    // Options of parameters for Image Stabilization feature.
    std::optional<tt_ImageStabilizationOptions> ImageStabilization;
    std::optional<tt_ImagingOptions20Extension2> Extension;
};


// XmlTraits for tt_ImagingOptions20Extension
template<>
struct xml_convert::XmlTraits<tt_ImagingOptions20Extension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ImagingOptions20Extension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("ImageStabilization", &tt_ImagingOptions20Extension::ImageStabilization, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImagingOptions20Extension::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// ImagingOptions20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ImagingOptions20 {
    // Valid range of Backlight Compensation.
    std::optional<tt_BacklightCompensationOptions20> BacklightCompensation;
    // Valid range of Brightness.
    std::optional<tt_FloatRange> Brightness;
    // Valid range of Color Saturation.
    std::optional<tt_FloatRange> ColorSaturation;
    // Valid range of Contrast.
    std::optional<tt_FloatRange> Contrast;
    // Valid range of Exposure.
    std::optional<tt_ExposureOptions20> Exposure;
    // Valid range of Focus.
    std::optional<tt_FocusOptions20> Focus;
    // Valid range of IrCutFilterModes.
    std::vector<tt_IrCutFilterMode> IrCutFilterModes;
    // Valid range of Sharpness.
    std::optional<tt_FloatRange> Sharpness;
    // Valid range of WideDynamicRange.
    std::optional<tt_WideDynamicRangeOptions20> WideDynamicRange;
    // Valid range of WhiteBalance.
    std::optional<tt_WhiteBalanceOptions20> WhiteBalance;
    std::optional<tt_ImagingOptions20Extension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ImagingOptions20
template<>
struct xml_convert::XmlTraits<tt_ImagingOptions20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BacklightCompensation", &tt_ImagingOptions20::BacklightCompensation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Brightness", &tt_ImagingOptions20::Brightness, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ColorSaturation", &tt_ImagingOptions20::ColorSaturation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Contrast", &tt_ImagingOptions20::Contrast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Exposure", &tt_ImagingOptions20::Exposure, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Focus", &tt_ImagingOptions20::Focus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IrCutFilterModes", &tt_ImagingOptions20::IrCutFilterModes, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Sharpness", &tt_ImagingOptions20::Sharpness, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WideDynamicRange", &tt_ImagingOptions20::WideDynamicRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("WhiteBalance", &tt_ImagingOptions20::WhiteBalance, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ImagingOptions20::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ImagingOptions20::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RelativeFocusOptions20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RelativeFocusOptions20 {
    // Valid ranges of the distance.
    tt_FloatRange Distance;
    // Valid ranges of the speed.
    std::optional<tt_FloatRange> Speed;
};


// XmlTraits for tt_RelativeFocusOptions20
template<>
struct xml_convert::XmlTraits<tt_RelativeFocusOptions20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Distance", &tt_RelativeFocusOptions20::Distance, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Speed", &tt_RelativeFocusOptions20::Speed, "tt", xml_convert::serialize_type::full)
    );
};


// MoveOptions20 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MoveOptions20 {
    // Valid ranges for the absolute control.
    std::optional<tt_AbsoluteFocusOptions> Absolute;
    // Valid ranges for the relative control.
    std::optional<tt_RelativeFocusOptions20> Relative;
    // Valid ranges for the continuous control.
    std::optional<tt_ContinuousFocusOptions> Continuous;
};


// XmlTraits for tt_MoveOptions20
template<>
struct xml_convert::XmlTraits<tt_MoveOptions20> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Absolute", &tt_MoveOptions20::Absolute, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Relative", &tt_MoveOptions20::Relative, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Continuous", &tt_MoveOptions20::Continuous, "tt", xml_convert::serialize_type::full)
    );
};


// ImageSendingType 枚举类型
// 基础类型: std::string
enum class  tt_ImageSendingType {
    Embedded,
    LocalStorage,
    RemoteStorage
};

// 字符串转换函数
inline std::string to_string(tt_ImageSendingType value) {
    switch (value) {
        case tt_ImageSendingType::Embedded: return "Embedded";
        case tt_ImageSendingType::LocalStorage: return "LocalStorage";
        case tt_ImageSendingType::RemoteStorage: return "RemoteStorage";
        default: return "";
    }
}

inline bool from_string(tt_ImageSendingType& value, const std::string& str) {
    if (str == "Embedded") { value = tt_ImageSendingType::Embedded; return true; }
    if (str == "LocalStorage") { value = tt_ImageSendingType::LocalStorage; return true; }
    if (str == "RemoteStorage") { value = tt_ImageSendingType::RemoteStorage; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ImageSendingType
template<>
struct xml_convert::XmlValueAdapter<tt_ImageSendingType> {
    static bool from_xml_val(tt_ImageSendingType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ImageSendingType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ImageSendingType
template<>
struct xml_convert::XmlAttributeAdapter<tt_ImageSendingType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ImageSendingType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ImageSendingType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// PropertyOperation 枚举类型
// 基础类型: std::string
enum class  tt_PropertyOperation {
    Initialized,
    Deleted,
    Changed
};

// 字符串转换函数
inline std::string to_string(tt_PropertyOperation value) {
    switch (value) {
        case tt_PropertyOperation::Initialized: return "Initialized";
        case tt_PropertyOperation::Deleted: return "Deleted";
        case tt_PropertyOperation::Changed: return "Changed";
        default: return "";
    }
}

inline bool from_string(tt_PropertyOperation& value, const std::string& str) {
    if (str == "Initialized") { value = tt_PropertyOperation::Initialized; return true; }
    if (str == "Deleted") { value = tt_PropertyOperation::Deleted; return true; }
    if (str == "Changed") { value = tt_PropertyOperation::Changed; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_PropertyOperation
template<>
struct xml_convert::XmlValueAdapter<tt_PropertyOperation> {
    static bool from_xml_val(tt_PropertyOperation& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_PropertyOperation& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_PropertyOperation
template<>
struct xml_convert::XmlAttributeAdapter<tt_PropertyOperation> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_PropertyOperation& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_PropertyOperation& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// MessageExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MessageExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_MessageExtension
template<>
struct xml_convert::XmlTraits<tt_MessageExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_MessageExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Message 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Message {
    // Token value pairs that triggered this message. Typically only one item is present.
    std::optional<tt_ItemList> Source;
    std::optional<tt_ItemList> Key;
    std::optional<tt_ItemList> Data;
    std::optional<tt_MessageExtension> Extension;
    std::string UtcTime;
    std::optional<tt_PropertyOperation> PropertyOperation;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Message
template<>
struct xml_convert::XmlTraits<tt_Message> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Source", &tt_Message::Source, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Key", &tt_Message::Key, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Data", &tt_Message::Data, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Message::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UtcTime", &tt_Message::UtcTime, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("PropertyOperation", &tt_Message::PropertyOperation, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_Message::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SimpleItemDescription 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SimpleItemDescription {
    // Item name. Must be unique within a list.
    std::string Name;
    std::string Type;
};


// XmlTraits for tt_SimpleItemDescription
template<>
struct xml_convert::XmlTraits<tt_SimpleItemDescription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_SimpleItemDescription::Name, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Type", &tt_SimpleItemDescription::Type, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ElementItemDescription 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ElementItemDescription {
    // Item name. Must be unique within a list.
    std::string Name;
    // The type of the item. The Type must reference a defined type.
    std::string Type;
};


// XmlTraits for tt_ElementItemDescription
template<>
struct xml_convert::XmlTraits<tt_ElementItemDescription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_ElementItemDescription::Name, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Type", &tt_ElementItemDescription::Type, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ItemListDescriptionExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ItemListDescriptionExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ItemListDescriptionExtension
template<>
struct xml_convert::XmlTraits<tt_ItemListDescriptionExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ItemListDescriptionExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ItemListDescription 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ItemListDescription {
    // Description of a simple item. The type must be of cathegory simpleType (xs:string, xs:integer, xs:float, ...).
    std::vector<tt_SimpleItemDescription> SimpleItemDescription;
    // Description of a complex type. The Type must reference a defined type.
    std::vector<tt_ElementItemDescription> ElementItemDescription;
    std::optional<tt_ItemListDescriptionExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ItemListDescription
template<>
struct xml_convert::XmlTraits<tt_ItemListDescription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SimpleItemDescription", &tt_ItemListDescription::SimpleItemDescription, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ElementItemDescription", &tt_ItemListDescription::ElementItemDescription, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ItemListDescription::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ItemListDescription::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MessageDescriptionExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MessageDescriptionExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_MessageDescriptionExtension
template<>
struct xml_convert::XmlTraits<tt_MessageDescriptionExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_MessageDescriptionExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// MessageDescription 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MessageDescription {
    /*
     * Set of tokens producing this message. The list may only contain SimpleItemDescription items.
     * The set of tokens identify the component within the WS-Endpoint, which is responsible for the producing the message.
     * For analytics events the token set shall include the VideoSourceConfigurationToken, the VideoAnalyticsConfigurationToken
     * and the name of the analytics module or rule.
     */
    std::optional<tt_ItemListDescription> Source;
    // Describes optional message payload parameters that may be used as key. E.g. object IDs of tracked objects are conveyed as key.
    std::optional<tt_ItemListDescription> Key;
    // Describes the payload of the message.
    std::optional<tt_ItemListDescription> Data;
    std::optional<tt_MessageDescriptionExtension> Extension;
    // Must be set to true when the described Message relates to a property. An alternative term of "property" is a "state" in contrast to a pure event, which contains relevant information for only a single point in time.Default is false.
    std::optional<bool> IsProperty;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MessageDescription
template<>
struct xml_convert::XmlTraits<tt_MessageDescription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Source", &tt_MessageDescription::Source, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Key", &tt_MessageDescription::Key, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Data", &tt_MessageDescription::Data, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_MessageDescription::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IsProperty", &tt_MessageDescription::IsProperty, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_MessageDescription::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Polyline 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Polyline {
    std::vector<tt_Vector> Point;
};


// XmlTraits for tt_Polyline
template<>
struct xml_convert::XmlTraits<tt_Polyline> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Point", &tt_Polyline::Point, "tt", xml_convert::serialize_type::full)
    );
};


// Direction 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Direction {
};


// XmlTraits for tt_Direction
template<>
struct xml_convert::XmlTraits<tt_Direction> {
    static constexpr auto fields = std::make_tuple(

    );
};


// ExtendedDirection 枚举类型
// 基础类型: std::string
enum class  tt_ExtendedDirection {
    Left,
    Right,
    Any,
    Entering,
    Exiting,
    Approaching,
    Departing
};

// 字符串转换函数
inline std::string to_string(tt_ExtendedDirection value) {
    switch (value) {
        case tt_ExtendedDirection::Left: return "Left";
        case tt_ExtendedDirection::Right: return "Right";
        case tt_ExtendedDirection::Any: return "Any";
        case tt_ExtendedDirection::Entering: return "Entering";
        case tt_ExtendedDirection::Exiting: return "Exiting";
        case tt_ExtendedDirection::Approaching: return "Approaching";
        case tt_ExtendedDirection::Departing: return "Departing";
        default: return "";
    }
}

inline bool from_string(tt_ExtendedDirection& value, const std::string& str) {
    if (str == "Left") { value = tt_ExtendedDirection::Left; return true; }
    if (str == "Right") { value = tt_ExtendedDirection::Right; return true; }
    if (str == "Any") { value = tt_ExtendedDirection::Any; return true; }
    if (str == "Entering") { value = tt_ExtendedDirection::Entering; return true; }
    if (str == "Exiting") { value = tt_ExtendedDirection::Exiting; return true; }
    if (str == "Approaching") { value = tt_ExtendedDirection::Approaching; return true; }
    if (str == "Departing") { value = tt_ExtendedDirection::Departing; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ExtendedDirection
template<>
struct xml_convert::XmlValueAdapter<tt_ExtendedDirection> {
    static bool from_xml_val(tt_ExtendedDirection& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ExtendedDirection& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ExtendedDirection
template<>
struct xml_convert::XmlAttributeAdapter<tt_ExtendedDirection> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ExtendedDirection& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ExtendedDirection& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// Messages 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Messages : public tt_MessageDescription {
    // The topic of the message. For historical reason the element is named ParentTopic, but the full topic is expected.
    std::string ParentTopic;
};


// XmlTraits for tt_Messages
template<>
struct xml_convert::XmlTraits<tt_Messages> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_MessageDescription>::fields, std::make_tuple(
        xml_convert::make_field_desc("ParentTopic", &tt_Messages::ParentTopic, "tt", xml_convert::serialize_type::full))
    );
};


// ConfigDescriptionExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ConfigDescriptionExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_ConfigDescriptionExtension
template<>
struct xml_convert::XmlTraits<tt_ConfigDescriptionExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ConfigDescriptionExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ConfigDescription 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ConfigDescription {
    /*
     * List describing the configuration parameters. The names of the parameters must be unique. If possible SimpleItems
     * should be used to transport the information to ease parsing of dynamically defined messages by a client
     * application.
     */
    tt_ItemListDescription Parameters;
    /*
     * The analytics modules and rule engine produce Events, which must be listed within the Analytics Module Description. In order to do so
     * the structure of the Message is defined and consists of three groups: Source, Key, and Data. It is recommended to use SimpleItemDescriptions wherever applicable.
     * The name of all Items must be unique within all Items contained in any group of this Message.
     * Depending on the component multiple parameters or none may be needed to identify the component uniquely.
     */
    std::vector<tt_Messages> Messages;
    std::optional<tt_ConfigDescriptionExtension> Extension;
    // The Name attribute (e.g. "tt::LineDetector") uniquely identifies the type of rule, not a type definition in a schema.
    std::string Name;
    // The fixed attribute signals that it is not allowed to add or remove this type of configuration.
    std::optional<bool> fixed;
    // The maxInstances attribute signals the maximum number of instances per configuration.
    std::optional<int64_t> maxInstances;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ConfigDescription
template<>
struct xml_convert::XmlTraits<tt_ConfigDescription> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Parameters", &tt_ConfigDescription::Parameters, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Messages", &tt_ConfigDescription::Messages, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ConfigDescription::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Name", &tt_ConfigDescription::Name, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("fixed", &tt_ConfigDescription::fixed, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("maxInstances", &tt_ConfigDescription::maxInstances, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_ConfigDescription::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SupportedRulesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SupportedRulesExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_SupportedRulesExtension
template<>
struct xml_convert::XmlTraits<tt_SupportedRulesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_SupportedRulesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SupportedRules 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SupportedRules {
    // Lists the location of all schemas that are referenced in the rules.
    std::vector<std::string> RuleContentSchemaLocation;
    // List of rules supported by the Video Analytics configuration..
    std::vector<tt_ConfigDescription> RuleDescription;
    std::optional<tt_SupportedRulesExtension> Extension;
    // Maximum number of concurrent instances.
    std::optional<int32_t> Limit;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SupportedRules
template<>
struct xml_convert::XmlTraits<tt_SupportedRules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RuleContentSchemaLocation", &tt_SupportedRules::RuleContentSchemaLocation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RuleDescription", &tt_SupportedRules::RuleDescription, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_SupportedRules::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Limit", &tt_SupportedRules::Limit, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_SupportedRules::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SupportedAnalyticsModulesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SupportedAnalyticsModulesExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_SupportedAnalyticsModulesExtension
template<>
struct xml_convert::XmlTraits<tt_SupportedAnalyticsModulesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_SupportedAnalyticsModulesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SupportedAnalyticsModules 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SupportedAnalyticsModules {
    /*
     * It optionally contains a list of URLs that provide the location of schema files.
     * These schema files describe the types and elements used in the analytics module descriptions.
     * Analytics module descriptions that reference types or elements imported from any ONVIF defined schema files
     * need not explicitly list those schema files.
     */
    std::vector<std::string> AnalyticsModuleContentSchemaLocation;
    std::vector<tt_ConfigDescription> AnalyticsModuleDescription;
    std::optional<tt_SupportedAnalyticsModulesExtension> Extension;
    // Maximum number of concurrent instances.
    std::optional<int32_t> Limit;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SupportedAnalyticsModules
template<>
struct xml_convert::XmlTraits<tt_SupportedAnalyticsModules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AnalyticsModuleContentSchemaLocation", &tt_SupportedAnalyticsModules::AnalyticsModuleContentSchemaLocation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AnalyticsModuleDescription", &tt_SupportedAnalyticsModules::AnalyticsModuleDescription, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_SupportedAnalyticsModules::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Limit", &tt_SupportedAnalyticsModules::Limit, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_SupportedAnalyticsModules::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MotionExpression 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MotionExpression {
    // Motion Expression data structure contains motion expression which is based on Scene Descriptor schema with XPATH syntax. The Type argument could allow introduction of different dialects
    std::string Expression;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<std::string> Type;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MotionExpression
template<>
struct xml_convert::XmlTraits<tt_MotionExpression> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Expression", &tt_MotionExpression::Expression, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MotionExpression::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Type", &tt_MotionExpression::Type, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_MotionExpression::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MotionExpressionConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MotionExpressionConfiguration {
    // Contains Rule MotionExpression configuration
    tt_MotionExpression MotionExpression;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MotionExpressionConfiguration
template<>
struct xml_convert::XmlTraits<tt_MotionExpressionConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MotionExpression", &tt_MotionExpressionConfiguration::MotionExpression, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MotionExpressionConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_MotionExpressionConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CellLayout 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CellLayout {
    // Mapping of the cell grid to the Video frame. The cell grid is starting from the upper left corner and x dimension is going from left to right and the y dimension from up to down.
    tt_Transformation Transformation;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Number of columns of the cell grid (x dimension)
    int64_t Columns {};
    // Number of rows of the cell grid (y dimension)
    int64_t Rows {};
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_CellLayout
template<>
struct xml_convert::XmlTraits<tt_CellLayout> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Transformation", &tt_CellLayout::Transformation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_CellLayout::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Columns", &tt_CellLayout::Columns, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Rows", &tt_CellLayout::Rows, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_CellLayout::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PaneConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PaneConfiguration {
    // Optional name of the pane configuration.
    std::optional<std::string> PaneName;
    /*
     * If the device has audio outputs, this element contains a pointer to the audio output that is associated with the pane. A client
     * can retrieve the available audio outputs of a device using the GetAudioOutputs command of the DeviceIO service.
     */
    std::optional<tt_ReferenceToken> AudioOutputToken;
    /*
     * If the device has audio sources, this element contains a pointer to the audio source that is associated with this pane.
     * The audio connection from a decoder device to the NVT is established using the backchannel mechanism. A client can retrieve the available audio sources of a device using the GetAudioSources command of the
     * DeviceIO service.
     */
    std::optional<tt_ReferenceToken> AudioSourceToken;
    /*
     * The configuration of the audio encoder including codec, bitrate
     * and sample rate.
     */
    std::optional<tt_AudioEncoderConfiguration> AudioEncoderConfiguration;
    /*
     * A pointer to a Receiver that has the necessary information to receive
     * data from a Transmitter. This Receiver can be connected and the network video decoder displays the received data on the specified outputs. A client can retrieve the available Receivers using the
     * GetReceivers command of the Receiver Service.
     */
    std::optional<tt_ReferenceToken> ReceiverToken;
    // A unique identifier in the display device.
    tt_ReferenceToken Token;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PaneConfiguration
template<>
struct xml_convert::XmlTraits<tt_PaneConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PaneName", &tt_PaneConfiguration::PaneName, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioOutputToken", &tt_PaneConfiguration::AudioOutputToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioSourceToken", &tt_PaneConfiguration::AudioSourceToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioEncoderConfiguration", &tt_PaneConfiguration::AudioEncoderConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ReceiverToken", &tt_PaneConfiguration::ReceiverToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Token", &tt_PaneConfiguration::Token, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PaneConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_PaneConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// CodingCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_CodingCapabilities {
    // If the device supports audio encoding this section describes the supported codecs and their configuration.
    std::optional<tt_AudioEncoderConfigurationOptions> AudioEncodingCapabilities;
    // If the device supports audio decoding this section describes the supported codecs and their settings.
    std::optional<tt_AudioDecoderConfigurationOptions> AudioDecodingCapabilities;
    // This section describes the supported video codesc and their configuration.
    tt_VideoDecoderConfigurationOptions VideoDecodingCapabilities;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_CodingCapabilities
template<>
struct xml_convert::XmlTraits<tt_CodingCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AudioEncodingCapabilities", &tt_CodingCapabilities::AudioEncodingCapabilities, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioDecodingCapabilities", &tt_CodingCapabilities::AudioDecodingCapabilities, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoDecodingCapabilities", &tt_CodingCapabilities::VideoDecodingCapabilities, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_CodingCapabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_CodingCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PaneOptionExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PaneOptionExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_PaneOptionExtension
template<>
struct xml_convert::XmlTraits<tt_PaneOptionExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_PaneOptionExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// PaneLayoutOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PaneLayoutOptions {
    // List of areas assembling a layout. Coordinate values are in the range [-1.0, 1.0].
    std::vector<tt_Rectangle> Area;
    std::optional<tt_PaneOptionExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PaneLayoutOptions
template<>
struct xml_convert::XmlTraits<tt_PaneLayoutOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Area", &tt_PaneLayoutOptions::Area, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_PaneLayoutOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_PaneLayoutOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// LayoutOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_LayoutOptionsExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_LayoutOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_LayoutOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_LayoutOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// LayoutOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_LayoutOptions {
    // Lists the possible Pane Layouts of the Video Output
    std::vector<tt_PaneLayoutOptions> PaneLayoutOptions;
    std::optional<tt_LayoutOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_LayoutOptions
template<>
struct xml_convert::XmlTraits<tt_LayoutOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PaneLayoutOptions", &tt_LayoutOptions::PaneLayoutOptions, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_LayoutOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_LayoutOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ReceiverMode 枚举类型
// 基础类型: std::string
enum class  tt_ReceiverMode {
    AutoConnect,
    AlwaysConnect,
    NeverConnect,
    Unknown
};

// 字符串转换函数
inline std::string to_string(tt_ReceiverMode value) {
    switch (value) {
        case tt_ReceiverMode::AutoConnect: return "AutoConnect";
        case tt_ReceiverMode::AlwaysConnect: return "AlwaysConnect";
        case tt_ReceiverMode::NeverConnect: return "NeverConnect";
        case tt_ReceiverMode::Unknown: return "Unknown";
        default: return "";
    }
}

inline bool from_string(tt_ReceiverMode& value, const std::string& str) {
    if (str == "AutoConnect") { value = tt_ReceiverMode::AutoConnect; return true; }
    if (str == "AlwaysConnect") { value = tt_ReceiverMode::AlwaysConnect; return true; }
    if (str == "NeverConnect") { value = tt_ReceiverMode::NeverConnect; return true; }
    if (str == "Unknown") { value = tt_ReceiverMode::Unknown; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ReceiverMode
template<>
struct xml_convert::XmlValueAdapter<tt_ReceiverMode> {
    static bool from_xml_val(tt_ReceiverMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ReceiverMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ReceiverMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_ReceiverMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ReceiverMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ReceiverMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ReceiverConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ReceiverConfiguration {
    // The following connection modes are defined:
    tt_ReceiverMode Mode;
    // Details of the URI to which the receiver should connect.
    std::string MediaUri;
    // Stream connection parameters.
    tt_StreamSetup StreamSetup;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ReceiverConfiguration
template<>
struct xml_convert::XmlTraits<tt_ReceiverConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Mode", &tt_ReceiverConfiguration::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MediaUri", &tt_ReceiverConfiguration::MediaUri, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StreamSetup", &tt_ReceiverConfiguration::StreamSetup, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ReceiverConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ReceiverConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Receiver 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Receiver {
    // Unique identifier of the receiver.
    tt_ReferenceToken Token;
    // Describes the configuration of the receiver.
    tt_ReceiverConfiguration Configuration;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Receiver
template<>
struct xml_convert::XmlTraits<tt_Receiver> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tt_Receiver::Token, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configuration", &tt_Receiver::Configuration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Receiver::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Receiver::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ReceiverState 枚举类型
// 基础类型: std::string
enum class  tt_ReceiverState {
    NotConnected,
    Connecting,
    Connected,
    Unknown
};

// 字符串转换函数
inline std::string to_string(tt_ReceiverState value) {
    switch (value) {
        case tt_ReceiverState::NotConnected: return "NotConnected";
        case tt_ReceiverState::Connecting: return "Connecting";
        case tt_ReceiverState::Connected: return "Connected";
        case tt_ReceiverState::Unknown: return "Unknown";
        default: return "";
    }
}

inline bool from_string(tt_ReceiverState& value, const std::string& str) {
    if (str == "NotConnected") { value = tt_ReceiverState::NotConnected; return true; }
    if (str == "Connecting") { value = tt_ReceiverState::Connecting; return true; }
    if (str == "Connected") { value = tt_ReceiverState::Connected; return true; }
    if (str == "Unknown") { value = tt_ReceiverState::Unknown; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ReceiverState
template<>
struct xml_convert::XmlValueAdapter<tt_ReceiverState> {
    static bool from_xml_val(tt_ReceiverState& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ReceiverState& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ReceiverState
template<>
struct xml_convert::XmlAttributeAdapter<tt_ReceiverState> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ReceiverState& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ReceiverState& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ReceiverStateInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ReceiverStateInformation {
    // The connection state of the receiver may have one of the following states:
    tt_ReceiverState State;
    // Indicates whether or not the receiver was created automatically.
    bool AutoCreated {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ReceiverStateInformation
template<>
struct xml_convert::XmlTraits<tt_ReceiverStateInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("State", &tt_ReceiverStateInformation::State, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AutoCreated", &tt_ReceiverStateInformation::AutoCreated, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ReceiverStateInformation::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ReceiverStateInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ReceiverReference 类型别名
// 基础类型: tt_ReferenceToken
using tt_ReceiverReference = tt_ReferenceToken;


// RecordingReference 类型别名
// 基础类型: tt_ReferenceToken
using tt_RecordingReference = tt_ReferenceToken;


// SourceReference 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SourceReference {
    tt_ReferenceToken Token;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<std::string> Type;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SourceReference
template<>
struct xml_convert::XmlTraits<tt_SourceReference> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tt_SourceReference::Token, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_SourceReference::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Type", &tt_SourceReference::Type, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_SourceReference::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// TrackReference 类型别名
// 基础类型: tt_ReferenceToken
using tt_TrackReference = tt_ReferenceToken;


// Description 类型别名
// 基础类型: std::string
using tt_Description = std::string;


// RecordingSummary 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingSummary {
    // The earliest point in time where there is recorded data on the device.
    std::string DataFrom;
    // The most recent point in time where there is recorded data on the device.
    std::string DataUntil;
    // The device contains this many recordings.
    int32_t NumberRecordings {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingSummary
template<>
struct xml_convert::XmlTraits<tt_RecordingSummary> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DataFrom", &tt_RecordingSummary::DataFrom, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DataUntil", &tt_RecordingSummary::DataUntil, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NumberRecordings", &tt_RecordingSummary::NumberRecordings, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingSummary::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingSummary::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// XPathExpression 类型别名
// 基础类型: std::string
using tt_XPathExpression = std::string;


// SearchScopeExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SearchScopeExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_SearchScopeExtension
template<>
struct xml_convert::XmlTraits<tt_SearchScopeExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_SearchScopeExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SearchScope 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SearchScope {
    // A list of sources that are included in the scope. If this list is included, only data from one of these sources shall be searched.
    std::vector<tt_SourceReference> IncludedSources;
    // A list of recordings that are included in the scope. If this list is included, only data from one of these recordings shall be searched.
    std::vector<tt_RecordingReference> IncludedRecordings;
    // An xpath expression used to specify what recordings to search. Only those recordings with an RecordingInformation structure that matches the filter shall be searched.
    std::optional<tt_XPathExpression> RecordingInformationFilter;
    // Extension point
    std::optional<tt_SearchScopeExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SearchScope
template<>
struct xml_convert::XmlTraits<tt_SearchScope> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IncludedSources", &tt_SearchScope::IncludedSources, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IncludedRecordings", &tt_SearchScope::IncludedRecordings, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RecordingInformationFilter", &tt_SearchScope::RecordingInformationFilter, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_SearchScope::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_SearchScope::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// EventFilter 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_EventFilter : public wsnt_FilterType {
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_EventFilter
template<>
struct xml_convert::XmlTraits<tt_EventFilter> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsnt_FilterType>::fields, std::make_tuple(
        xml_convert::make_field_desc("_attrs_", &tt_EventFilter::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// PTZPositionFilter 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PTZPositionFilter {
    // The lower boundary of the PTZ volume to look for.
    tt_PTZVector MinPosition;
    // The upper boundary of the PTZ volume to look for.
    tt_PTZVector MaxPosition;
    // If true, search for when entering the specified PTZ volume.
    bool EnterOrExit {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZPositionFilter
template<>
struct xml_convert::XmlTraits<tt_PTZPositionFilter> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MinPosition", &tt_PTZPositionFilter::MinPosition, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxPosition", &tt_PTZPositionFilter::MaxPosition, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EnterOrExit", &tt_PTZPositionFilter::EnterOrExit, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PTZPositionFilter::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_PTZPositionFilter::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MetadataFilter 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MetadataFilter {
    tt_XPathExpression MetadataStreamFilter;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MetadataFilter
template<>
struct xml_convert::XmlTraits<tt_MetadataFilter> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MetadataStreamFilter", &tt_MetadataFilter::MetadataStreamFilter, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MetadataFilter::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_MetadataFilter::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SearchState 枚举类型
// 基础类型: std::string
enum class  tt_SearchState {
    Queued,
    Searching,
    Completed,
    Unknown
};

// 字符串转换函数
inline std::string to_string(tt_SearchState value) {
    switch (value) {
        case tt_SearchState::Queued: return "Queued";
        case tt_SearchState::Searching: return "Searching";
        case tt_SearchState::Completed: return "Completed";
        case tt_SearchState::Unknown: return "Unknown";
        default: return "";
    }
}

inline bool from_string(tt_SearchState& value, const std::string& str) {
    if (str == "Queued") { value = tt_SearchState::Queued; return true; }
    if (str == "Searching") { value = tt_SearchState::Searching; return true; }
    if (str == "Completed") { value = tt_SearchState::Completed; return true; }
    if (str == "Unknown") { value = tt_SearchState::Unknown; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_SearchState
template<>
struct xml_convert::XmlValueAdapter<tt_SearchState> {
    static bool from_xml_val(tt_SearchState& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_SearchState& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_SearchState
template<>
struct xml_convert::XmlAttributeAdapter<tt_SearchState> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_SearchState& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_SearchState& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// RecordingSourceInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingSourceInformation {
    /*
     * Identifier for the source chosen by the client that creates the structure.
     * This identifier is opaque to the device. Clients may use any type of URI for this field. A device shall support at least 128 characters.
     */
    std::string SourceId;
    // Informative user readable name of the source, e.g. "Camera23". A device shall support at least 20 characters.
    tt_Name Name;
    // Informative description of the physical location of the source, e.g. the coordinates on a map.
    tt_Description Location;
    // Informative description of the source.
    tt_Description Description;
    // URI provided by the service supplying data to be recorded. A device shall support at least 128 characters.
    std::string Address;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingSourceInformation
template<>
struct xml_convert::XmlTraits<tt_RecordingSourceInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SourceId", &tt_RecordingSourceInformation::SourceId, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Name", &tt_RecordingSourceInformation::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Location", &tt_RecordingSourceInformation::Location, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Description", &tt_RecordingSourceInformation::Description, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Address", &tt_RecordingSourceInformation::Address, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingSourceInformation::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingSourceInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// TrackType 枚举类型
// 基础类型: std::string
enum class  tt_TrackType {
    Video,
    Audio,
    Metadata,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_TrackType value) {
    switch (value) {
        case tt_TrackType::Video: return "Video";
        case tt_TrackType::Audio: return "Audio";
        case tt_TrackType::Metadata: return "Metadata";
        case tt_TrackType::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_TrackType& value, const std::string& str) {
    if (str == "Video") { value = tt_TrackType::Video; return true; }
    if (str == "Audio") { value = tt_TrackType::Audio; return true; }
    if (str == "Metadata") { value = tt_TrackType::Metadata; return true; }
    if (str == "Extended") { value = tt_TrackType::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_TrackType
template<>
struct xml_convert::XmlValueAdapter<tt_TrackType> {
    static bool from_xml_val(tt_TrackType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_TrackType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_TrackType
template<>
struct xml_convert::XmlAttributeAdapter<tt_TrackType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_TrackType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_TrackType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// TrackInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_TrackInformation {
    tt_TrackReference TrackToken;
    /*
     * Type of the track: "Video", "Audio" or "Metadata".
     * The track shall only be able to hold data of that type.
     */
    tt_TrackType TrackType;
    // Informative description of the contents of the track.
    tt_Description Description;
    // The start date and time of the oldest recorded data in the track.
    std::string DataFrom;
    // The stop date and time of the newest recorded data in the track.
    std::string DataTo;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_TrackInformation
template<>
struct xml_convert::XmlTraits<tt_TrackInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TrackToken", &tt_TrackInformation::TrackToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TrackType", &tt_TrackInformation::TrackType, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Description", &tt_TrackInformation::Description, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DataFrom", &tt_TrackInformation::DataFrom, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DataTo", &tt_TrackInformation::DataTo, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_TrackInformation::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_TrackInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingStatus 枚举类型
// 基础类型: std::string
enum class  tt_RecordingStatus {
    Initiated,
    Recording,
    Stopped,
    Removing,
    Removed,
    Unknown
};

// 字符串转换函数
inline std::string to_string(tt_RecordingStatus value) {
    switch (value) {
        case tt_RecordingStatus::Initiated: return "Initiated";
        case tt_RecordingStatus::Recording: return "Recording";
        case tt_RecordingStatus::Stopped: return "Stopped";
        case tt_RecordingStatus::Removing: return "Removing";
        case tt_RecordingStatus::Removed: return "Removed";
        case tt_RecordingStatus::Unknown: return "Unknown";
        default: return "";
    }
}

inline bool from_string(tt_RecordingStatus& value, const std::string& str) {
    if (str == "Initiated") { value = tt_RecordingStatus::Initiated; return true; }
    if (str == "Recording") { value = tt_RecordingStatus::Recording; return true; }
    if (str == "Stopped") { value = tt_RecordingStatus::Stopped; return true; }
    if (str == "Removing") { value = tt_RecordingStatus::Removing; return true; }
    if (str == "Removed") { value = tt_RecordingStatus::Removed; return true; }
    if (str == "Unknown") { value = tt_RecordingStatus::Unknown; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_RecordingStatus
template<>
struct xml_convert::XmlValueAdapter<tt_RecordingStatus> {
    static bool from_xml_val(tt_RecordingStatus& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_RecordingStatus& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_RecordingStatus
template<>
struct xml_convert::XmlAttributeAdapter<tt_RecordingStatus> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_RecordingStatus& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_RecordingStatus& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// RecordingInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingInformation {
    tt_RecordingReference RecordingToken;
    /*
     * Information about the source of the recording. This gives a description of where the data in the recording comes from. Since a single
     * recording is intended to record related material, there is just one source. It is indicates the physical location or the
     * major data source for the recording. Currently the recordingconfiguration cannot describe each individual data source.
     */
    tt_RecordingSourceInformation Source;
    std::optional<std::string> EarliestRecording;
    std::optional<std::string> LatestRecording;
    tt_Description Content;
    // Basic information about the track. Note that a track may represent a single contiguous time span or consist of multiple slices.
    std::vector<tt_TrackInformation> Track;
    tt_RecordingStatus RecordingStatus;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingInformation
template<>
struct xml_convert::XmlTraits<tt_RecordingInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &tt_RecordingInformation::RecordingToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Source", &tt_RecordingInformation::Source, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EarliestRecording", &tt_RecordingInformation::EarliestRecording, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("LatestRecording", &tt_RecordingInformation::LatestRecording, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Content", &tt_RecordingInformation::Content, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Track", &tt_RecordingInformation::Track, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RecordingStatus", &tt_RecordingInformation::RecordingStatus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingInformation::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// FindRecordingResultList 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FindRecordingResultList {
    // The state of the search when the result is returned. Indicates if there can be more results, or if the search is completed.
    tt_SearchState SearchState;
    // A RecordingInformation structure for each found recording matching the search.
    std::vector<tt_RecordingInformation> RecordingInformation;
};


// XmlTraits for tt_FindRecordingResultList
template<>
struct xml_convert::XmlTraits<tt_FindRecordingResultList> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchState", &tt_FindRecordingResultList::SearchState, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RecordingInformation", &tt_FindRecordingResultList::RecordingInformation, "tt", xml_convert::serialize_type::full)
    );
};


// FindEventResult 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FindEventResult {
    // The recording where this event was found. Empty string if no recording is associated with this event.
    tt_RecordingReference RecordingToken;
    // A reference to the track where this event was found. Empty string if no track is associated with this event.
    tt_TrackReference TrackToken;
    // The time when the event occured.
    std::string Time;
    // The description of the event.
    wsnt_NotificationMessageHolderType Event;
    // If true, indicates that the event is a virtual event generated for this particular search session to give the state of a property at the start time of the search.
    bool StartStateEvent {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_FindEventResult
template<>
struct xml_convert::XmlTraits<tt_FindEventResult> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &tt_FindEventResult::RecordingToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TrackToken", &tt_FindEventResult::TrackToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Time", &tt_FindEventResult::Time, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Event", &tt_FindEventResult::Event, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StartStateEvent", &tt_FindEventResult::StartStateEvent, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_FindEventResult::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_FindEventResult::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// FindEventResultList 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FindEventResultList {
    // The state of the search when the result is returned. Indicates if there can be more results, or if the search is completed.
    tt_SearchState SearchState;
    // A FindEventResult structure for each found event matching the search.
    std::vector<tt_FindEventResult> Result;
};


// XmlTraits for tt_FindEventResultList
template<>
struct xml_convert::XmlTraits<tt_FindEventResultList> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchState", &tt_FindEventResultList::SearchState, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Result", &tt_FindEventResultList::Result, "tt", xml_convert::serialize_type::full)
    );
};


// FindPTZPositionResult 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FindPTZPositionResult {
    // A reference to the recording containing the PTZ position.
    tt_RecordingReference RecordingToken;
    // A reference to the metadata track containing the PTZ position.
    tt_TrackReference TrackToken;
    // The time when the PTZ position was valid.
    std::string Time;
    // The PTZ position.
    tt_PTZVector Position;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_FindPTZPositionResult
template<>
struct xml_convert::XmlTraits<tt_FindPTZPositionResult> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &tt_FindPTZPositionResult::RecordingToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TrackToken", &tt_FindPTZPositionResult::TrackToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Time", &tt_FindPTZPositionResult::Time, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Position", &tt_FindPTZPositionResult::Position, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_FindPTZPositionResult::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_FindPTZPositionResult::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// FindPTZPositionResultList 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FindPTZPositionResultList {
    // The state of the search when the result is returned. Indicates if there can be more results, or if the search is completed.
    tt_SearchState SearchState;
    // A FindPTZPositionResult structure for each found PTZ position matching the search.
    std::vector<tt_FindPTZPositionResult> Result;
};


// XmlTraits for tt_FindPTZPositionResultList
template<>
struct xml_convert::XmlTraits<tt_FindPTZPositionResultList> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchState", &tt_FindPTZPositionResultList::SearchState, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Result", &tt_FindPTZPositionResultList::Result, "tt", xml_convert::serialize_type::full)
    );
};


// FindMetadataResult 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FindMetadataResult {
    // A reference to the recording containing the metadata.
    tt_RecordingReference RecordingToken;
    // A reference to the metadata track containing the matching metadata.
    tt_TrackReference TrackToken;
    // The point in time when the matching metadata occurs in the metadata track.
    std::string Time;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_FindMetadataResult
template<>
struct xml_convert::XmlTraits<tt_FindMetadataResult> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &tt_FindMetadataResult::RecordingToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TrackToken", &tt_FindMetadataResult::TrackToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Time", &tt_FindMetadataResult::Time, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_FindMetadataResult::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_FindMetadataResult::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// FindMetadataResultList 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FindMetadataResultList {
    // The state of the search when the result is returned. Indicates if there can be more results, or if the search is completed.
    tt_SearchState SearchState;
    // A FindMetadataResult structure for each found set of Metadata matching the search.
    std::vector<tt_FindMetadataResult> Result;
};


// XmlTraits for tt_FindMetadataResultList
template<>
struct xml_convert::XmlTraits<tt_FindMetadataResultList> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SearchState", &tt_FindMetadataResultList::SearchState, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Result", &tt_FindMetadataResultList::Result, "tt", xml_convert::serialize_type::full)
    );
};


// JobToken 类型别名
// 基础类型: tt_ReferenceToken
using tt_JobToken = tt_ReferenceToken;


// TargetFormat 枚举类型
// 基础类型: std::string
enum class  tt_TargetFormat {
    MP4,
    CMAF
};

// 字符串转换函数
inline std::string to_string(tt_TargetFormat value) {
    switch (value) {
        case tt_TargetFormat::MP4: return "MP4";
        case tt_TargetFormat::CMAF: return "CMAF";
        default: return "";
    }
}

inline bool from_string(tt_TargetFormat& value, const std::string& str) {
    if (str == "MP4") { value = tt_TargetFormat::MP4; return true; }
    if (str == "CMAF") { value = tt_TargetFormat::CMAF; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_TargetFormat
template<>
struct xml_convert::XmlValueAdapter<tt_TargetFormat> {
    static bool from_xml_val(tt_TargetFormat& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_TargetFormat& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_TargetFormat
template<>
struct xml_convert::XmlAttributeAdapter<tt_TargetFormat> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_TargetFormat& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_TargetFormat& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// EncryptionMode 枚举类型
// 基础类型: std::string
enum class  tt_EncryptionMode {
    CENC,
    CBCS
};

// 字符串转换函数
inline std::string to_string(tt_EncryptionMode value) {
    switch (value) {
        case tt_EncryptionMode::CENC: return "CENC";
        case tt_EncryptionMode::CBCS: return "CBCS";
        default: return "";
    }
}

inline bool from_string(tt_EncryptionMode& value, const std::string& str) {
    if (str == "CENC") { value = tt_EncryptionMode::CENC; return true; }
    if (str == "CBCS") { value = tt_EncryptionMode::CBCS; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_EncryptionMode
template<>
struct xml_convert::XmlValueAdapter<tt_EncryptionMode> {
    static bool from_xml_val(tt_EncryptionMode& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_EncryptionMode& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_EncryptionMode
template<>
struct xml_convert::XmlAttributeAdapter<tt_EncryptionMode> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_EncryptionMode& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_EncryptionMode& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// AsymmetricEncryption 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AsymmetricEncryption {
    // List of certificates used to encrypt the symmetric key for the PSSH box.
    std::vector<std::string> CertificateID;
    /*
     * Frequency at which the device shall generate a new key to encrypt a new segment.
     * If not specified, key rotation is disabled.
     * KeyRotationDuration must be a positive duration value.
     */
    std::optional<my_Duration> KeyRotationDuration;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_AsymmetricEncryption
template<>
struct xml_convert::XmlTraits<tt_AsymmetricEncryption> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tt_AsymmetricEncryption::CertificateID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("KeyRotationDuration", &tt_AsymmetricEncryption::KeyRotationDuration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AsymmetricEncryption::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// RecordingEncryption 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingEncryption {
    // Key ID of the associated key for encryption. This parameter is ignored when AsymmetricEncryption is configured.
    std::optional<std::string> KID;
    /*
     * Key for encrypting content. This parameter is ignored when AsymmetricEncryption is configured.
     * The device shall not include this parameter when reading.
     */
    std::optional<std::string> Key;
    /*
     * Optional list of track tokens to be encrypted.
     * If no track tokens are specified, all tracks are encrypted and no other encryption configurations shall exist for the recording.
     * Each track shall only be contained in one encryption configuration.
     */
    std::vector<std::string> Track;
    std::optional<tt_AsymmetricEncryption> AsymmetricEncryption;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    /*
     * Mode of encryption.
     * See tt:EncryptionMode for a list of definitions and capability trc:SupportedEncryptionModes for the supported encryption modes.
     */
    std::string Mode;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingEncryption
template<>
struct xml_convert::XmlTraits<tt_RecordingEncryption> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("KID", &tt_RecordingEncryption::KID, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Key", &tt_RecordingEncryption::Key, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Track", &tt_RecordingEncryption::Track, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AsymmetricEncryption", &tt_RecordingEncryption::AsymmetricEncryption, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingEncryption::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Mode", &tt_RecordingEncryption::Mode, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingEncryption::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SegmentDurationOverride 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SegmentDurationOverride {
    // Current value of the segment duration.
    my_Duration Duration;
    // Time remaining until the override expires.
    my_Duration Expiration;
};


// XmlTraits for tt_SegmentDurationOverride
template<>
struct xml_convert::XmlTraits<tt_SegmentDurationOverride> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Duration", &tt_SegmentDurationOverride::Duration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Expiration", &tt_SegmentDurationOverride::Expiration, "tt", xml_convert::serialize_type::full)
    );
};


// RecordingTargetConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingTargetConfiguration {
    // Token of a storage configuration.
    tt_ReferenceToken Storage;
    /*
     * Format of the recording.
     * See tt:TargetFormat for a list of definitions and capability trc:SupportedTargetFormats for the supported formats.
     */
    std::string Format;
    // Path prefix to be inserted in the object key.
    std::optional<std::string> Prefix;
    // Path postfix to be inserted in the object key.
    std::optional<std::string> Postfix;
    // Maximum duration of a span.
    std::optional<my_Duration> SpanDuration;
    // Maximum duration of a segment.
    my_Duration SegmentDuration;
    /*
     * Optional encryption configuration.
     * See capability trc:EncryptionEntryLimit for the number of supported entries.
     * By specifying multiple encryption entries per recording, different tracks can be encrypted with different configurations.
     * Each track shall only be contained in one encryption configuration.
     */
    std::vector<tt_RecordingEncryption> Encryption;
    // Value of the active OverrideSegmentDuration parameters if one exists. (readonly)
    std::optional<tt_SegmentDurationOverride> SegmentDurationOverride;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingTargetConfiguration
template<>
struct xml_convert::XmlTraits<tt_RecordingTargetConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Storage", &tt_RecordingTargetConfiguration::Storage, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Format", &tt_RecordingTargetConfiguration::Format, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Prefix", &tt_RecordingTargetConfiguration::Prefix, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Postfix", &tt_RecordingTargetConfiguration::Postfix, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SpanDuration", &tt_RecordingTargetConfiguration::SpanDuration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SegmentDuration", &tt_RecordingTargetConfiguration::SegmentDuration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Encryption", &tt_RecordingTargetConfiguration::Encryption, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SegmentDurationOverride", &tt_RecordingTargetConfiguration::SegmentDurationOverride, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingTargetConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingTargetConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// VideoAttributes 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_VideoAttributes {
    // Average bitrate in kbps.
    std::optional<int32_t> Bitrate;
    // The width of the video in pixels.
    int32_t Width {};
    // The height of the video in pixels.
    int32_t Height {};
    // Video encoding of the track.  Use value from tt:VideoEncoding for MPEG4. Otherwise use values from tt:VideoEncodingMimeNames and  IANA Media Types.
    std::string Encoding;
    // Average framerate in frames per second.
    float Framerate {};
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_VideoAttributes
template<>
struct xml_convert::XmlTraits<tt_VideoAttributes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Bitrate", &tt_VideoAttributes::Bitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Width", &tt_VideoAttributes::Width, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Height", &tt_VideoAttributes::Height, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Encoding", &tt_VideoAttributes::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Framerate", &tt_VideoAttributes::Framerate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_VideoAttributes::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_VideoAttributes::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioAttributes 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioAttributes {
    // The bitrate in kbps.
    std::optional<int32_t> Bitrate;
    // Audio encoding of the track.  Use values from tt:AudioEncoding for G711 and AAC. Otherwise use values from tt:AudioEncodingMimeNames and  IANA Media Types.
    std::string Encoding;
    // The sample rate in kHz.
    int32_t Samplerate {};
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioAttributes
template<>
struct xml_convert::XmlTraits<tt_AudioAttributes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Bitrate", &tt_AudioAttributes::Bitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Encoding", &tt_AudioAttributes::Encoding, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Samplerate", &tt_AudioAttributes::Samplerate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioAttributes::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioAttributes::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MetadataAttributes 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MetadataAttributes {
    // Indicates that there can be PTZ data in the metadata track in the specified time interval.
    bool CanContainPTZ {};
    // Indicates that there can be analytics data in the metadata track in the specified time interval.
    bool CanContainAnalytics {};
    // Indicates that there can be notifications in the metadata track in the specified time interval.
    bool CanContainNotifications {};
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // List of all PTZ spaces active for recording. Note that events are only recorded on position changes and the actual point of recording may not necessarily contain an event of the specified type.
    std::optional<tt_StringAttrList> PtzSpaces;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MetadataAttributes
template<>
struct xml_convert::XmlTraits<tt_MetadataAttributes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CanContainPTZ", &tt_MetadataAttributes::CanContainPTZ, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CanContainAnalytics", &tt_MetadataAttributes::CanContainAnalytics, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CanContainNotifications", &tt_MetadataAttributes::CanContainNotifications, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MetadataAttributes::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("PtzSpaces", &tt_MetadataAttributes::PtzSpaces, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_MetadataAttributes::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// TrackAttributesExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_TrackAttributesExtension {
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_TrackAttributesExtension
template<>
struct xml_convert::XmlTraits<tt_TrackAttributesExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_TrackAttributesExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// TrackAttributes 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_TrackAttributes {
    // The basic information about the track. Note that a track may represent a single contiguous time span or consist of multiple slices.
    tt_TrackInformation TrackInformation;
    // If the track is a video track, exactly one of this structure shall be present and contain the video attributes.
    std::optional<tt_VideoAttributes> VideoAttributes;
    // If the track is an audio track, exactly one of this structure shall be present and contain the audio attributes.
    std::optional<tt_AudioAttributes> AudioAttributes;
    // If the track is an metadata track, exactly one of this structure shall be present and contain the metadata attributes.
    std::optional<tt_MetadataAttributes> MetadataAttributes;
    std::optional<tt_TrackAttributesExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_TrackAttributes
template<>
struct xml_convert::XmlTraits<tt_TrackAttributes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TrackInformation", &tt_TrackAttributes::TrackInformation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoAttributes", &tt_TrackAttributes::VideoAttributes, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AudioAttributes", &tt_TrackAttributes::AudioAttributes, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MetadataAttributes", &tt_TrackAttributes::MetadataAttributes, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_TrackAttributes::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_TrackAttributes::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MediaAttributes 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MediaAttributes {
    // A reference to the recording that has these attributes.
    tt_RecordingReference RecordingToken;
    // A set of attributes for each track.
    std::vector<tt_TrackAttributes> TrackAttributes;
    // The attributes are valid from this point in time in the recording.
    std::string From;
    // The attributes are valid until this point in time in the recording. Can be equal to 'From' to indicate that the attributes are only known to be valid for this particular point in time.
    std::string Until;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MediaAttributes
template<>
struct xml_convert::XmlTraits<tt_MediaAttributes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &tt_MediaAttributes::RecordingToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TrackAttributes", &tt_MediaAttributes::TrackAttributes, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("From", &tt_MediaAttributes::From, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Until", &tt_MediaAttributes::Until, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_MediaAttributes::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_MediaAttributes::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingJobReference 类型别名
// 基础类型: tt_ReferenceToken
using tt_RecordingJobReference = tt_ReferenceToken;


// RecordingConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingConfiguration {
    // Information about the source of the recording.
    tt_RecordingSourceInformation Source;
    // Informative description of the source.
    tt_Description Content;
    /*
     * Sspecifies the maximum time that data in any track within the
     * recording shall be stored. The device shall delete any data older than the maximum retention
     * time. Such data shall not be accessible anymore. If the MaximumRetentionPeriod is set to 0,
     * the device shall not limit the retention time of stored data, except by resource constraints.
     * Whatever the value of MaximumRetentionTime, the device may automatically delete
     * recordings to free up storage space for new recordings.
     */
    my_Duration MaximumRetentionTime;
    // Optional external storage target configuration.
    std::optional<tt_RecordingTargetConfiguration> Target;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingConfiguration
template<>
struct xml_convert::XmlTraits<tt_RecordingConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Source", &tt_RecordingConfiguration::Source, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Content", &tt_RecordingConfiguration::Content, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaximumRetentionTime", &tt_RecordingConfiguration::MaximumRetentionTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Target", &tt_RecordingConfiguration::Target, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// TrackConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_TrackConfiguration {
    /*
     * Type of the track. It shall be equal to the strings “Video”,
     * “Audio” or “Metadata”. The track shall only be able to hold data of that type.
     */
    tt_TrackType TrackType;
    // Informative description of the track.
    tt_Description Description;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_TrackConfiguration
template<>
struct xml_convert::XmlTraits<tt_TrackConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TrackType", &tt_TrackConfiguration::TrackType, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Description", &tt_TrackConfiguration::Description, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_TrackConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_TrackConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetTracksResponseItem 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_GetTracksResponseItem {
    // Token of the track.
    tt_TrackReference TrackToken;
    // Configuration of the track.
    tt_TrackConfiguration Configuration;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_GetTracksResponseItem
template<>
struct xml_convert::XmlTraits<tt_GetTracksResponseItem> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TrackToken", &tt_GetTracksResponseItem::TrackToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configuration", &tt_GetTracksResponseItem::Configuration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_GetTracksResponseItem::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_GetTracksResponseItem::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetTracksResponseList 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_GetTracksResponseList {
    // Configuration of a track.
    std::vector<tt_GetTracksResponseItem> Track;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_GetTracksResponseList
template<>
struct xml_convert::XmlTraits<tt_GetTracksResponseList> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Track", &tt_GetTracksResponseList::Track, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_GetTracksResponseList::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetRecordingsResponseItem 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_GetRecordingsResponseItem {
    // Token of the recording.
    tt_RecordingReference RecordingToken;
    // Configuration of the recording.
    tt_RecordingConfiguration Configuration;
    // List of tracks.
    tt_GetTracksResponseList Tracks;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_GetRecordingsResponseItem
template<>
struct xml_convert::XmlTraits<tt_GetRecordingsResponseItem> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &tt_GetRecordingsResponseItem::RecordingToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Configuration", &tt_GetRecordingsResponseItem::Configuration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Tracks", &tt_GetRecordingsResponseItem::Tracks, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_GetRecordingsResponseItem::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_GetRecordingsResponseItem::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingJobMode 类型别名
// 基础类型: std::string
using tt_RecordingJobMode = std::string;


// RecordingJobTrack 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingJobTrack {
    /*
     * If the received RTSP stream contains multiple tracks of the same type, the
     * SourceTag differentiates between those Tracks. This field can be ignored in case of recording a local source.
     */
    std::string SourceTag;
    /*
     * The destination is the tracktoken of the track to which the device shall store the
     * received data.
     */
    tt_TrackReference Destination;
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingJobTrack
template<>
struct xml_convert::XmlTraits<tt_RecordingJobTrack> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SourceTag", &tt_RecordingJobTrack::SourceTag, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Destination", &tt_RecordingJobTrack::Destination, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingJobTrack::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingJobTrack::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingJobSourceExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingJobSourceExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_RecordingJobSourceExtension
template<>
struct xml_convert::XmlTraits<tt_RecordingJobSourceExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_RecordingJobSourceExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// RecordingJobSource 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingJobSource {
    /*
     * This field shall be a reference to the source of the data. The type of the source
     * is determined by the attribute Type in the SourceToken structure. If Type is
     * http://www.onvif.org/ver10/schema/Receiver, the token is a ReceiverReference. In this case
     * the device shall receive the data over the network. If Type is
     * http://www.onvif.org/ver10/schema/Profile, the token identifies a media profile, instructing the
     * device to obtain data from a profile that exists on the local device.
     */
    std::optional<tt_SourceReference> SourceToken;
    /*
     * If this field is TRUE, and if the SourceToken is omitted, the device
     * shall create a receiver object (through the receiver service) and assign the
     * ReceiverReference to the SourceToken field. When retrieving the RecordingJobConfiguration
     * from the device, the AutoCreateReceiver field shall never be present.
     */
    std::optional<bool> AutoCreateReceiver;
    // List of tracks associated with the recording.
    std::vector<tt_RecordingJobTrack> Tracks;
    std::optional<tt_RecordingJobSourceExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingJobSource
template<>
struct xml_convert::XmlTraits<tt_RecordingJobSource> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SourceToken", &tt_RecordingJobSource::SourceToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AutoCreateReceiver", &tt_RecordingJobSource::AutoCreateReceiver, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Tracks", &tt_RecordingJobSource::Tracks, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_RecordingJobSource::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingJobSource::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingJobConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingJobConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_RecordingJobConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_RecordingJobConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_RecordingJobConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Filter 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_Filter {
    // Topic filter as defined in section 9.6.3 of the ONVIF Core Specification.
    std::string Topic;
    // Optional message source content filter as defined in section 9.4.4 of the ONVIF Core Specification.
    std::optional<std::string> Source;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Filter
template<>
struct xml_convert::XmlTraits<tt_Filter> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Topic", &tt_Filter::Topic, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Source", &tt_Filter::Source, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_Filter::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_Filter::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingEventFilter 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingEventFilter {
    std::vector<tt_Filter> Filter;
    // Optional timespan to record before the actual event condition became active.
    std::optional<my_Duration> Before;
    // Optional timespan to record after the actual event condition becomes inactive.
    std::optional<my_Duration> After;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingEventFilter
template<>
struct xml_convert::XmlTraits<tt_RecordingEventFilter> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Filter", &tt_RecordingEventFilter::Filter, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Before", &tt_RecordingEventFilter::Before, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("After", &tt_RecordingEventFilter::After, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingEventFilter::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingEventFilter::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingJobConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingJobConfiguration {
    // Identifies the recording to which this job shall store the received data.
    tt_RecordingReference RecordingToken;
    /*
     * The mode of the job. If it is idle, nothing shall happen. If it is active, the device shall try
     * to obtain data from the receivers. A client shall use GetRecordingJobState to determine if data transfer is really taking place.
     * The only valid values for Mode shall be “Idle” and “Active”.
     */
    tt_RecordingJobMode Mode;
    /*
     * This shall be a non-negative number. If there are multiple recording jobs that store data to
     * the same track, the device will only store the data for the recording job with the highest
     * priority. The priority is specified per recording job, but the device shall determine the priority
     * of each track individually. If there are two recording jobs with the same priority, the device
     * shall record the data corresponding to the recording job that was activated the latest.
     */
    int32_t Priority {};
    // Source of the recording.
    std::vector<tt_RecordingJobSource> Source;
    std::optional<tt_RecordingJobConfigurationExtension> Extension;
    // Optional filter defining on which event condition a recording job gets active.
    std::optional<tt_RecordingEventFilter> EventFilter;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    /*
     * This attribute adds an additional requirement for activating the recording job.
     * If this optional field is provided the job shall only record if the schedule exists and is active.
     */
    std::optional<std::string> ScheduleToken;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingJobConfiguration
template<>
struct xml_convert::XmlTraits<tt_RecordingJobConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &tt_RecordingJobConfiguration::RecordingToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mode", &tt_RecordingJobConfiguration::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Priority", &tt_RecordingJobConfiguration::Priority, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Source", &tt_RecordingJobConfiguration::Source, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_RecordingJobConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EventFilter", &tt_RecordingJobConfiguration::EventFilter, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingJobConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("ScheduleToken", &tt_RecordingJobConfiguration::ScheduleToken, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingJobConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingJobState 类型别名
// 基础类型: std::string
using tt_RecordingJobState = std::string;


// RecordingJobStateTrack 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingJobStateTrack {
    // Identifies the track of the data source that provides the data.
    std::string SourceTag;
    // Indicates the destination track.
    tt_TrackReference Destination;
    /*
     * Optionally holds an implementation defined string value that describes the error.
     * The string should be in the English language.
     */
    std::optional<std::string> Error;
    /*
     * Provides the job state of the track. The valid
     * values of state shall be “Idle”, “Active” and “Error”. If state equals “Error”, the Error field may be filled in with an implementation defined value.
     */
    tt_RecordingJobState State;
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingJobStateTrack
template<>
struct xml_convert::XmlTraits<tt_RecordingJobStateTrack> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SourceTag", &tt_RecordingJobStateTrack::SourceTag, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Destination", &tt_RecordingJobStateTrack::Destination, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Error", &tt_RecordingJobStateTrack::Error, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("State", &tt_RecordingJobStateTrack::State, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingJobStateTrack::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingJobStateTrack::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingJobStateTracks 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingJobStateTracks {
    std::vector<tt_RecordingJobStateTrack> Track;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingJobStateTracks
template<>
struct xml_convert::XmlTraits<tt_RecordingJobStateTracks> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Track", &tt_RecordingJobStateTracks::Track, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingJobStateTracks::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingJobStateSource 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingJobStateSource {
    // Identifies the data source of the recording job.
    tt_SourceReference SourceToken;
    // Holds the aggregated state over all substructures of RecordingJobStateSource.
    tt_RecordingJobState State;
    // List of track items.
    tt_RecordingJobStateTracks Tracks;
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingJobStateSource
template<>
struct xml_convert::XmlTraits<tt_RecordingJobStateSource> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SourceToken", &tt_RecordingJobStateSource::SourceToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("State", &tt_RecordingJobStateSource::State, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Tracks", &tt_RecordingJobStateSource::Tracks, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_RecordingJobStateSource::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingJobStateSource::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// RecordingJobStateInformationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingJobStateInformationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_RecordingJobStateInformationExtension
template<>
struct xml_convert::XmlTraits<tt_RecordingJobStateInformationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_RecordingJobStateInformationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// RecordingJobStateInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_RecordingJobStateInformation {
    // Identification of the recording that the recording job records to.
    tt_RecordingReference RecordingToken;
    // Holds the aggregated state over the whole RecordingJobInformation structure.
    tt_RecordingJobState State;
    // Identifies the data source of the recording job.
    std::vector<tt_RecordingJobStateSource> Sources;
    std::optional<tt_RecordingJobStateInformationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_RecordingJobStateInformation
template<>
struct xml_convert::XmlTraits<tt_RecordingJobStateInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RecordingToken", &tt_RecordingJobStateInformation::RecordingToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("State", &tt_RecordingJobStateInformation::State, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Sources", &tt_RecordingJobStateInformation::Sources, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_RecordingJobStateInformation::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_RecordingJobStateInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetRecordingJobsResponseItem 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_GetRecordingJobsResponseItem {
    tt_RecordingJobReference JobToken;
    tt_RecordingJobConfiguration JobConfiguration;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_GetRecordingJobsResponseItem
template<>
struct xml_convert::XmlTraits<tt_GetRecordingJobsResponseItem> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("JobToken", &tt_GetRecordingJobsResponseItem::JobToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("JobConfiguration", &tt_GetRecordingJobsResponseItem::JobConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_GetRecordingJobsResponseItem::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_GetRecordingJobsResponseItem::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ReplayConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ReplayConfiguration {
    // The RTSP session timeout.
    my_Duration SessionTimeout;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ReplayConfiguration
template<>
struct xml_convert::XmlTraits<tt_ReplayConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SessionTimeout", &tt_ReplayConfiguration::SessionTimeout, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ReplayConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ReplayConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AnalyticsEngineInputInfoExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsEngineInputInfoExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_AnalyticsEngineInputInfoExtension
template<>
struct xml_convert::XmlTraits<tt_AnalyticsEngineInputInfoExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AnalyticsEngineInputInfoExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// AnalyticsEngineInputInfo 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsEngineInputInfo {
    std::optional<tt_Config> InputInfo;
    std::optional<tt_AnalyticsEngineInputInfoExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnalyticsEngineInputInfo
template<>
struct xml_convert::XmlTraits<tt_AnalyticsEngineInputInfo> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("InputInfo", &tt_AnalyticsEngineInputInfo::InputInfo, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_AnalyticsEngineInputInfo::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_AnalyticsEngineInputInfo::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// EngineConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_EngineConfiguration {
    tt_VideoAnalyticsConfiguration VideoAnalyticsConfiguration;
    tt_AnalyticsEngineInputInfo AnalyticsEngineInputInfo;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_EngineConfiguration
template<>
struct xml_convert::XmlTraits<tt_EngineConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("VideoAnalyticsConfiguration", &tt_EngineConfiguration::VideoAnalyticsConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AnalyticsEngineInputInfo", &tt_EngineConfiguration::AnalyticsEngineInputInfo, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_EngineConfiguration::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_EngineConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AnalyticsDeviceEngineConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsDeviceEngineConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_AnalyticsDeviceEngineConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_AnalyticsDeviceEngineConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AnalyticsDeviceEngineConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// AnalyticsDeviceEngineConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsDeviceEngineConfiguration {
    std::vector<tt_EngineConfiguration> EngineConfiguration;
    std::optional<tt_AnalyticsDeviceEngineConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnalyticsDeviceEngineConfiguration
template<>
struct xml_convert::XmlTraits<tt_AnalyticsDeviceEngineConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("EngineConfiguration", &tt_AnalyticsDeviceEngineConfiguration::EngineConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_AnalyticsDeviceEngineConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_AnalyticsDeviceEngineConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AnalyticsEngine 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsEngine : public tt_ConfigurationEntity {
    tt_AnalyticsDeviceEngineConfiguration AnalyticsEngineConfiguration;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnalyticsEngine
template<>
struct xml_convert::XmlTraits<tt_AnalyticsEngine> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("AnalyticsEngineConfiguration", &tt_AnalyticsEngine::AnalyticsEngineConfiguration, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AnalyticsEngine::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AnalyticsEngine::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// SourceIdentificationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SourceIdentificationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_SourceIdentificationExtension
template<>
struct xml_convert::XmlTraits<tt_SourceIdentificationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_SourceIdentificationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// SourceIdentification 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_SourceIdentification {
    std::string Name;
    std::vector<tt_ReferenceToken> Token;
    std::optional<tt_SourceIdentificationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_SourceIdentification
template<>
struct xml_convert::XmlTraits<tt_SourceIdentification> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tt_SourceIdentification::Name, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Token", &tt_SourceIdentification::Token, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_SourceIdentification::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_SourceIdentification::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MetadataInputExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MetadataInputExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_MetadataInputExtension
template<>
struct xml_convert::XmlTraits<tt_MetadataInputExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_MetadataInputExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// MetadataInput 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MetadataInput {
    std::vector<tt_Config> MetadataConfig;
    std::optional<tt_MetadataInputExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MetadataInput
template<>
struct xml_convert::XmlTraits<tt_MetadataInput> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MetadataConfig", &tt_MetadataInput::MetadataConfig, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_MetadataInput::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_MetadataInput::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AnalyticsEngineInput 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsEngineInput : public tt_ConfigurationEntity {
    tt_SourceIdentification SourceIdentification;
    tt_VideoEncoderConfiguration VideoInput;
    tt_MetadataInput MetadataInput;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnalyticsEngineInput
template<>
struct xml_convert::XmlTraits<tt_AnalyticsEngineInput> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("SourceIdentification", &tt_AnalyticsEngineInput::SourceIdentification, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VideoInput", &tt_AnalyticsEngineInput::VideoInput, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MetadataInput", &tt_AnalyticsEngineInput::MetadataInput, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AnalyticsEngineInput::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AnalyticsEngineInput::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// ModeOfOperation 枚举类型
// 基础类型: std::string
enum class  tt_ModeOfOperation {
    Idle,
    Active,
    Unknown
};

// 字符串转换函数
inline std::string to_string(tt_ModeOfOperation value) {
    switch (value) {
        case tt_ModeOfOperation::Idle: return "Idle";
        case tt_ModeOfOperation::Active: return "Active";
        case tt_ModeOfOperation::Unknown: return "Unknown";
        default: return "";
    }
}

inline bool from_string(tt_ModeOfOperation& value, const std::string& str) {
    if (str == "Idle") { value = tt_ModeOfOperation::Idle; return true; }
    if (str == "Active") { value = tt_ModeOfOperation::Active; return true; }
    if (str == "Unknown") { value = tt_ModeOfOperation::Unknown; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_ModeOfOperation
template<>
struct xml_convert::XmlValueAdapter<tt_ModeOfOperation> {
    static bool from_xml_val(tt_ModeOfOperation& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_ModeOfOperation& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_ModeOfOperation
template<>
struct xml_convert::XmlAttributeAdapter<tt_ModeOfOperation> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_ModeOfOperation& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_ModeOfOperation& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// AnalyticsEngineControl 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsEngineControl : public tt_ConfigurationEntity {
    // Token of the analytics engine (AnalyticsEngine) being controlled.
    tt_ReferenceToken EngineToken;
    // Token of the analytics engine configuration (VideoAnalyticsConfiguration) in effect.
    tt_ReferenceToken EngineConfigToken;
    // Tokens of the input (AnalyticsEngineInput) configuration applied.
    std::vector<tt_ReferenceToken> InputToken;
    // Tokens of the receiver providing media input data. The order of ReceiverToken shall exactly match the order of InputToken.
    std::vector<tt_ReferenceToken> ReceiverToken;
    std::optional<tt_MulticastConfiguration> Multicast;
    tt_Config Subscription;
    tt_ModeOfOperation Mode;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnalyticsEngineControl
template<>
struct xml_convert::XmlTraits<tt_AnalyticsEngineControl> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_ConfigurationEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("EngineToken", &tt_AnalyticsEngineControl::EngineToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("EngineConfigToken", &tt_AnalyticsEngineControl::EngineConfigToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("InputToken", &tt_AnalyticsEngineControl::InputToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ReceiverToken", &tt_AnalyticsEngineControl::ReceiverToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Multicast", &tt_AnalyticsEngineControl::Multicast, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Subscription", &tt_AnalyticsEngineControl::Subscription, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Mode", &tt_AnalyticsEngineControl::Mode, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AnalyticsEngineControl::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AnalyticsEngineControl::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// AnalyticsState 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsState {
    std::optional<std::string> Error;
    std::string State;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnalyticsState
template<>
struct xml_convert::XmlTraits<tt_AnalyticsState> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Error", &tt_AnalyticsState::Error, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("State", &tt_AnalyticsState::State, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AnalyticsState::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AnalyticsState::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AnalyticsStateInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AnalyticsStateInformation {
    // Token of the control object whose status is requested.
    tt_ReferenceToken AnalyticsEngineControlToken;
    tt_AnalyticsState State;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AnalyticsStateInformation
template<>
struct xml_convert::XmlTraits<tt_AnalyticsStateInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AnalyticsEngineControlToken", &tt_AnalyticsStateInformation::AnalyticsEngineControlToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("State", &tt_AnalyticsStateInformation::State, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AnalyticsStateInformation::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AnalyticsStateInformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ActionEngineEventPayloadExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ActionEngineEventPayloadExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ActionEngineEventPayloadExtension
template<>
struct xml_convert::XmlTraits<tt_ActionEngineEventPayloadExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ActionEngineEventPayloadExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ActionEngineEventPayloadExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ActionEngineEventPayload 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ActionEngineEventPayload {
    // Request Message
    std::optional<soap_Envelope> RequestInfo;
    // Response Message
    std::optional<soap_Envelope> ResponseInfo;
    // Fault Message
    std::optional<soap_Fault> Fault;
    std::optional<tt_ActionEngineEventPayloadExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ActionEngineEventPayload
template<>
struct xml_convert::XmlTraits<tt_ActionEngineEventPayload> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RequestInfo", &tt_ActionEngineEventPayload::RequestInfo, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ResponseInfo", &tt_ActionEngineEventPayload::ResponseInfo, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Fault", &tt_ActionEngineEventPayload::Fault, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ActionEngineEventPayload::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ActionEngineEventPayload::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioClassType 枚举类型
// 基础类型: std::string
enum class  tt_AudioClassType {
    gun_shot,
    scream,
    glass_breaking,
    tire_screech
};

// 字符串转换函数
inline std::string to_string(tt_AudioClassType value) {
    switch (value) {
        case tt_AudioClassType::gun_shot: return "gun_shot";
        case tt_AudioClassType::scream: return "scream";
        case tt_AudioClassType::glass_breaking: return "glass_breaking";
        case tt_AudioClassType::tire_screech: return "tire_screech";
        default: return "";
    }
}

inline bool from_string(tt_AudioClassType& value, const std::string& str) {
    if (str == "gun_shot") { value = tt_AudioClassType::gun_shot; return true; }
    if (str == "scream") { value = tt_AudioClassType::scream; return true; }
    if (str == "glass_breaking") { value = tt_AudioClassType::glass_breaking; return true; }
    if (str == "tire_screech") { value = tt_AudioClassType::tire_screech; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_AudioClassType
template<>
struct xml_convert::XmlValueAdapter<tt_AudioClassType> {
    static bool from_xml_val(tt_AudioClassType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_AudioClassType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_AudioClassType
template<>
struct xml_convert::XmlAttributeAdapter<tt_AudioClassType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_AudioClassType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_AudioClassType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// AudioClassification 枚举类型
// 基础类型: std::string
enum class  tt_AudioClassification {
    GunShot,
    Scream,
    GlassBreaking,
    TireScreech,
    Alarm
};

// 字符串转换函数
inline std::string to_string(tt_AudioClassification value) {
    switch (value) {
        case tt_AudioClassification::GunShot: return "GunShot";
        case tt_AudioClassification::Scream: return "Scream";
        case tt_AudioClassification::GlassBreaking: return "GlassBreaking";
        case tt_AudioClassification::TireScreech: return "TireScreech";
        case tt_AudioClassification::Alarm: return "Alarm";
        default: return "";
    }
}

inline bool from_string(tt_AudioClassification& value, const std::string& str) {
    if (str == "GunShot") { value = tt_AudioClassification::GunShot; return true; }
    if (str == "Scream") { value = tt_AudioClassification::Scream; return true; }
    if (str == "GlassBreaking") { value = tt_AudioClassification::GlassBreaking; return true; }
    if (str == "TireScreech") { value = tt_AudioClassification::TireScreech; return true; }
    if (str == "Alarm") { value = tt_AudioClassification::Alarm; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_AudioClassification
template<>
struct xml_convert::XmlValueAdapter<tt_AudioClassification> {
    static bool from_xml_val(tt_AudioClassification& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_AudioClassification& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_AudioClassification
template<>
struct xml_convert::XmlAttributeAdapter<tt_AudioClassification> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_AudioClassification& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_AudioClassification& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// AudioClassCandidate 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioClassCandidate {
    // Indicates audio class label
    tt_AudioClassType Type;
    // A likelihood/probability that the corresponding audio event belongs to this class. The sum of the likelihoods shall NOT exceed 1
    float Likelihood {};
    // Collection of any elements from namespace: ##targetNamespace (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioClassCandidate
template<>
struct xml_convert::XmlTraits<tt_AudioClassCandidate> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_AudioClassCandidate::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Likelihood", &tt_AudioClassCandidate::Likelihood, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_AudioClassCandidate::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioClassCandidate::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioClassDescriptorExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioClassDescriptorExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioClassDescriptorExtension
template<>
struct xml_convert::XmlTraits<tt_AudioClassDescriptorExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_AudioClassDescriptorExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_AudioClassDescriptorExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// AudioClassDescriptor 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_AudioClassDescriptor {
    // Array of audio class label and class probability
    std::vector<tt_AudioClassCandidate> ClassCandidate;
    std::optional<tt_AudioClassDescriptorExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_AudioClassDescriptor
template<>
struct xml_convert::XmlTraits<tt_AudioClassDescriptor> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ClassCandidate", &tt_AudioClassDescriptor::ClassCandidate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_AudioClassDescriptor::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_AudioClassDescriptor::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ActiveConnection 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ActiveConnection {
    float CurrentBitrate {};
    float CurrentFps {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ActiveConnection
template<>
struct xml_convert::XmlTraits<tt_ActiveConnection> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CurrentBitrate", &tt_ActiveConnection::CurrentBitrate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CurrentFps", &tt_ActiveConnection::CurrentFps, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ActiveConnection::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ActiveConnection::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ProfileStatusExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ProfileStatusExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ProfileStatusExtension
template<>
struct xml_convert::XmlTraits<tt_ProfileStatusExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ProfileStatusExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ProfileStatusExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ProfileStatus 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ProfileStatus {
    std::vector<tt_ActiveConnection> ActiveConnections;
    std::optional<tt_ProfileStatusExtension> Extension;
};


// XmlTraits for tt_ProfileStatus
template<>
struct xml_convert::XmlTraits<tt_ProfileStatus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ActiveConnections", &tt_ProfileStatus::ActiveConnections, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ProfileStatus::Extension, "tt", xml_convert::serialize_type::full)
    );
};


// OSDReference 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDReference {
    // Value content based on tt:ReferenceToken
    tt_ReferenceToken value;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDReference
template<>
struct xml_convert::XmlTraits<tt_OSDReference> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &tt_OSDReference::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_OSDReference::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDType 枚举类型
// 基础类型: std::string
enum class  tt_OSDType {
    Text,
    Image,
    Extended
};

// 字符串转换函数
inline std::string to_string(tt_OSDType value) {
    switch (value) {
        case tt_OSDType::Text: return "Text";
        case tt_OSDType::Image: return "Image";
        case tt_OSDType::Extended: return "Extended";
        default: return "";
    }
}

inline bool from_string(tt_OSDType& value, const std::string& str) {
    if (str == "Text") { value = tt_OSDType::Text; return true; }
    if (str == "Image") { value = tt_OSDType::Image; return true; }
    if (str == "Extended") { value = tt_OSDType::Extended; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_OSDType
template<>
struct xml_convert::XmlValueAdapter<tt_OSDType> {
    static bool from_xml_val(tt_OSDType& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_OSDType& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_OSDType
template<>
struct xml_convert::XmlAttributeAdapter<tt_OSDType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_OSDType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_OSDType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// OSDPosConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDPosConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDPosConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_OSDPosConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_OSDPosConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_OSDPosConfigurationExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDPosConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDPosConfiguration {
    /*
     * For OSD position type, following are the pre-defined: UpperLeft
     * UpperRight
     * LowerLeft
     * LowerRight
     * Custom
     */
    std::string Type;
    std::optional<tt_Vector> Pos;
    std::optional<tt_OSDPosConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDPosConfiguration
template<>
struct xml_convert::XmlTraits<tt_OSDPosConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_OSDPosConfiguration::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Pos", &tt_OSDPosConfiguration::Pos, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_OSDPosConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_OSDPosConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDColor 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDColor {
    tt_Color Color;
    std::optional<int32_t> Transparent;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDColor
template<>
struct xml_convert::XmlTraits<tt_OSDColor> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Color", &tt_OSDColor::Color, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Transparent", &tt_OSDColor::Transparent, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_OSDColor::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDTextConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDTextConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDTextConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_OSDTextConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_OSDTextConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_OSDTextConfigurationExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDTextConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDTextConfiguration {
    /*
     * The following OSD Text Type are defined:
     * Plain - The Plain type means the OSD is shown as a text string which defined in the "PlainText" item.
     * Date - The Date type means the OSD is shown as a date, format of which should be present in the "DateFormat" item.
     * Time - The Time type means the OSD is shown as a time, format of which should be present in the "TimeFormat" item.
     * DateAndTime - The DateAndTime type means the OSD is shown as date and time, format of which should be present in the "DateFormat" and the "TimeFormat" item.
     */
    std::string Type;
    /*
     * List of supported OSD date formats. This element shall be present when the value of Type field has Date or DateAndTime. The following DateFormat are defined:
     * M/d/yyyy - e.g. 3/6/2013
     * MM/dd/yyyy - e.g. 03/06/2013
     * dd/MM/yyyy - e.g. 06/03/2013
     * yyyy/MM/dd - e.g. 2013/03/06
     * yyyy-MM-dd - e.g. 2013-06-03
     * dddd, MMMM dd, yyyy - e.g. Wednesday, March 06, 2013
     * MMMM dd, yyyy - e.g. March 06, 2013
     * dd MMMM, yyyy - e.g. 06 March, 2013
     */
    std::optional<std::string> DateFormat;
    /*
     * List of supported OSD time formats. This element shall be present when the value of Type field has Time or DateAndTime. The following TimeFormat are defined:
     * h:mm:ss tt - e.g. 2:14:21 PM
     * hh:mm:ss tt - e.g. 02:14:21 PM
     * H:mm:ss - e.g. 14:14:21
     * HH:mm:ss - e.g. 14:14:21
     */
    std::optional<std::string> TimeFormat;
    // Font size of the text in pt.
    std::optional<int32_t> FontSize;
    // Font color of the text.
    std::optional<tt_OSDColor> FontColor;
    // Background color of the text.
    std::optional<tt_OSDColor> BackgroundColor;
    // The content of text to be displayed.
    std::optional<std::string> PlainText;
    std::optional<tt_OSDTextConfigurationExtension> Extension;
    // This flag is applicable for Type Plain and defaults to true. When set to false the PlainText content will not be persistent across device reboots.
    std::optional<bool> IsPersistentText;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDTextConfiguration
template<>
struct xml_convert::XmlTraits<tt_OSDTextConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_OSDTextConfiguration::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DateFormat", &tt_OSDTextConfiguration::DateFormat, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TimeFormat", &tt_OSDTextConfiguration::TimeFormat, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FontSize", &tt_OSDTextConfiguration::FontSize, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FontColor", &tt_OSDTextConfiguration::FontColor, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BackgroundColor", &tt_OSDTextConfiguration::BackgroundColor, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PlainText", &tt_OSDTextConfiguration::PlainText, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_OSDTextConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IsPersistentText", &tt_OSDTextConfiguration::IsPersistentText, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_OSDTextConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDImgConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDImgConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDImgConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_OSDImgConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_OSDImgConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_OSDImgConfigurationExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDImgConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDImgConfiguration {
    // The URI of the image which to be displayed.
    std::string ImgPath;
    std::optional<tt_OSDImgConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDImgConfiguration
template<>
struct xml_convert::XmlTraits<tt_OSDImgConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ImgPath", &tt_OSDImgConfiguration::ImgPath, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_OSDImgConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_OSDImgConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ColorspaceRange 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ColorspaceRange {
    tt_FloatRange X;
    tt_FloatRange Y;
    tt_FloatRange Z;
    // Acceptable values are the same as in tt:Color.
    std::string Colorspace;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ColorspaceRange
template<>
struct xml_convert::XmlTraits<tt_ColorspaceRange> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("X", &tt_ColorspaceRange::X, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Y", &tt_ColorspaceRange::Y, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Z", &tt_ColorspaceRange::Z, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Colorspace", &tt_ColorspaceRange::Colorspace, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ColorspaceRange::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ColorOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ColorOptions {
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ColorOptions
template<>
struct xml_convert::XmlTraits<tt_ColorOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_attrs_", &tt_ColorOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDColorOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDColorOptionsExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDColorOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_OSDColorOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_OSDColorOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_OSDColorOptionsExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDColorOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDColorOptions {
    // Optional list of supported colors.
    std::optional<tt_ColorOptions> Color;
    // Range of the transparent level. Larger means more tranparent.
    std::optional<tt_IntRange> Transparent;
    std::optional<tt_OSDColorOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDColorOptions
template<>
struct xml_convert::XmlTraits<tt_OSDColorOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Color", &tt_OSDColorOptions::Color, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Transparent", &tt_OSDColorOptions::Transparent, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_OSDColorOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_OSDColorOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDTextOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDTextOptionsExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDTextOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_OSDTextOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_OSDTextOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_OSDTextOptionsExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDTextOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDTextOptions {
    // List of supported OSD text type. When a device indicates the supported number relating to Text type in MaximumNumberOfOSDs, the type shall be presented.
    std::vector<std::string> Type;
    // Range of the font size value.
    std::optional<tt_IntRange> FontSizeRange;
    // List of supported date format.
    std::vector<std::string> DateFormat;
    // List of supported time format.
    std::vector<std::string> TimeFormat;
    // List of supported font color.
    std::optional<tt_OSDColorOptions> FontColor;
    // List of supported background color.
    std::optional<tt_OSDColorOptions> BackgroundColor;
    std::optional<tt_OSDTextOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDTextOptions
template<>
struct xml_convert::XmlTraits<tt_OSDTextOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tt_OSDTextOptions::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FontSizeRange", &tt_OSDTextOptions::FontSizeRange, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DateFormat", &tt_OSDTextOptions::DateFormat, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TimeFormat", &tt_OSDTextOptions::TimeFormat, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FontColor", &tt_OSDTextOptions::FontColor, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BackgroundColor", &tt_OSDTextOptions::BackgroundColor, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_OSDTextOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_OSDTextOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDImgOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDImgOptionsExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDImgOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_OSDImgOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_OSDImgOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_OSDImgOptionsExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDImgOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDImgOptions {
    // List of available image URIs.
    std::vector<std::string> ImagePath;
    std::optional<tt_OSDImgOptionsExtension> Extension;
    // List of supported image MIME types, such as "image/png".
    std::optional<tt_StringAttrList> FormatsSupported;
    // The maximum size (in bytes) of the image that can be uploaded.
    std::optional<int32_t> MaxSize;
    // The maximum width (in pixels) of the image that can be uploaded.
    std::optional<int32_t> MaxWidth;
    // The maximum height (in pixels) of the image that can be uploaded.
    std::optional<int32_t> MaxHeight;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDImgOptions
template<>
struct xml_convert::XmlTraits<tt_OSDImgOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ImagePath", &tt_OSDImgOptions::ImagePath, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_OSDImgOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FormatsSupported", &tt_OSDImgOptions::FormatsSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxSize", &tt_OSDImgOptions::MaxSize, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxWidth", &tt_OSDImgOptions::MaxWidth, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxHeight", &tt_OSDImgOptions::MaxHeight, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_OSDImgOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDConfigurationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDConfigurationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDConfigurationExtension
template<>
struct xml_convert::XmlTraits<tt_OSDConfigurationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_OSDConfigurationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_OSDConfigurationExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDConfiguration : public tt_DeviceEntity {
    // Reference to the video source configuration.
    tt_OSDReference VideoSourceConfigurationToken;
    // Type of OSD.
    tt_OSDType Type;
    // Position configuration of OSD.
    tt_OSDPosConfiguration Position;
    // Text configuration of OSD. It shall be present when the value of Type field is Text.
    std::optional<tt_OSDTextConfiguration> TextString;
    // Image configuration of OSD. It shall be present when the value of Type field is Image
    std::optional<tt_OSDImgConfiguration> Image;
    std::optional<tt_OSDConfigurationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDConfiguration
template<>
struct xml_convert::XmlTraits<tt_OSDConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_DeviceEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("VideoSourceConfigurationToken", &tt_OSDConfiguration::VideoSourceConfigurationToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Type", &tt_OSDConfiguration::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Position", &tt_OSDConfiguration::Position, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TextString", &tt_OSDConfiguration::TextString, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Image", &tt_OSDConfiguration::Image, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_OSDConfiguration::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_OSDConfiguration::_attrs_, nullptr, xml_convert::serialize_type::attribute))
    );
};


// MaximumNumberOfOSDs 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_MaximumNumberOfOSDs {
    int32_t Total {};
    std::optional<int32_t> Image;
    std::optional<int32_t> PlainText;
    std::optional<int32_t> Date;
    std::optional<int32_t> Time;
    std::optional<int32_t> DateAndTime;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_MaximumNumberOfOSDs
template<>
struct xml_convert::XmlTraits<tt_MaximumNumberOfOSDs> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Total", &tt_MaximumNumberOfOSDs::Total, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Image", &tt_MaximumNumberOfOSDs::Image, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("PlainText", &tt_MaximumNumberOfOSDs::PlainText, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Date", &tt_MaximumNumberOfOSDs::Date, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Time", &tt_MaximumNumberOfOSDs::Time, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("DateAndTime", &tt_MaximumNumberOfOSDs::DateAndTime, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_MaximumNumberOfOSDs::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDConfigurationOptionsExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDConfigurationOptionsExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDConfigurationOptionsExtension
template<>
struct xml_convert::XmlTraits<tt_OSDConfigurationOptionsExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_OSDConfigurationOptionsExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_OSDConfigurationOptionsExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// OSDConfigurationOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_OSDConfigurationOptions {
    // The maximum number of OSD configurations supported for the specified video source configuration. If the configuration does not support OSDs, this value shall be zero and the Type and PositionOption elements are ignored. If a device limits the number of instances by OSDType, it shall indicate the supported number for each type via the related attribute.
    tt_MaximumNumberOfOSDs MaximumNumberOfOSDs;
    // List supported type of OSD configuration. When a device indicates the supported number for each types in MaximumNumberOfOSDs, related type shall be presented. A device shall return Option element relating to listed type.
    std::vector<tt_OSDType> Type;
    /*
     * List available OSD position type. Following are the pre-defined:UpperLeft
     * UpperRight
     * LowerLeft
     * LowerRight
     * Custom
     */
    std::vector<std::string> PositionOption;
    // Option of the OSD text configuration. This element shall be returned if the device is signaling the support for Text.
    std::optional<tt_OSDTextOptions> TextOption;
    // Option of the OSD image configuration. This element shall be returned if the device is signaling the support for Image.
    std::optional<tt_OSDImgOptions> ImageOption;
    std::optional<tt_OSDConfigurationOptionsExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_OSDConfigurationOptions
template<>
struct xml_convert::XmlTraits<tt_OSDConfigurationOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MaximumNumberOfOSDs", &tt_OSDConfigurationOptions::MaximumNumberOfOSDs, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Type", &tt_OSDConfigurationOptions::Type, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PositionOption", &tt_OSDConfigurationOptions::PositionOption, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TextOption", &tt_OSDConfigurationOptions::TextOption, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ImageOption", &tt_OSDConfigurationOptions::ImageOption, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_OSDConfigurationOptions::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_OSDConfigurationOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// FileProgress 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_FileProgress {
    // Exported file name
    std::string FileName;
    // Normalized percentage completion for uploading the exported file
    float Progress {};
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_FileProgress
template<>
struct xml_convert::XmlTraits<tt_FileProgress> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FileName", &tt_FileProgress::FileName, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Progress", &tt_FileProgress::Progress, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_FileProgress::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_FileProgress::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ArrayOfFileProgressExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ArrayOfFileProgressExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ArrayOfFileProgressExtension
template<>
struct xml_convert::XmlTraits<tt_ArrayOfFileProgressExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_ArrayOfFileProgressExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ArrayOfFileProgressExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ArrayOfFileProgress 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_ArrayOfFileProgress {
    // Exported file name and export progress information
    std::vector<tt_FileProgress> FileProgress;
    std::optional<tt_ArrayOfFileProgressExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ArrayOfFileProgress
template<>
struct xml_convert::XmlTraits<tt_ArrayOfFileProgress> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FileProgress", &tt_ArrayOfFileProgress::FileProgress, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ArrayOfFileProgress::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_ArrayOfFileProgress::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// StorageReferencePathExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_StorageReferencePathExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_StorageReferencePathExtension
template<>
struct xml_convert::XmlTraits<tt_StorageReferencePathExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_StorageReferencePathExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_StorageReferencePathExtension::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// StorageReferencePath 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_StorageReferencePath {
    // identifier of an existing Storage Configuration.
    tt_ReferenceToken StorageToken;
    // gives the relative directory path on the storage
    std::optional<std::string> RelativePath;
    std::optional<tt_StorageReferencePathExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_StorageReferencePath
template<>
struct xml_convert::XmlTraits<tt_StorageReferencePath> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StorageToken", &tt_StorageReferencePath::StorageToken, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RelativePath", &tt_StorageReferencePath::RelativePath, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_StorageReferencePath::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_StorageReferencePath::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PolygonOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: onvif_v10.xsd
struct tt_PolygonOptions {
    /*
     * True if the device supports defining a region only using Rectangle.
     * The rectangle points are still passed using a Polygon element if the device does not support polygon regions. In this case, the points provided in the Polygon element shall represent a rectangle.
     */
    std::optional<bool> RectangleOnly;
    /*
     * Provides the minimum and maximum number of points that can be defined in the Polygon.
     * If RectangleOnly is not set to true, this parameter is required.
     */
    std::optional<tt_IntRange> VertexLimits;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PolygonOptions
template<>
struct xml_convert::XmlTraits<tt_PolygonOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RectangleOnly", &tt_PolygonOptions::RectangleOnly, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("VertexLimits", &tt_PolygonOptions::VertexLimits, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PolygonOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_PolygonOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


} // namespace libonvif_client
