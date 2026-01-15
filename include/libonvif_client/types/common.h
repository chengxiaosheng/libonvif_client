/**
 * @file common.h
 * @brief 从 common_v10.xsd 生成的类型定义
 * @namespace http://www.onvif.org/ver10/schema
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 * @comment ONVIF核心Schema - 分离生成以避免循环依赖
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

// ReferenceToken 类型别名
// 基础类型: std::string
using tt_ReferenceToken = std::string;


// IntRange 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_IntRange {
    int32_t Min {};
    int32_t Max {};
};


// XmlTraits for tt_IntRange
template<>
struct xml_convert::XmlTraits<tt_IntRange> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Min", &tt_IntRange::Min, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Max", &tt_IntRange::Max, "tt", xml_convert::serialize_type::full)
    );
};


// Vector2D 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_Vector2D {
    float x {};
    float y {};
    /*
     * Pan/tilt coordinate space selector. The following options are defined:
     * http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace
     * http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace
     * http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace
     * http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace
     */
    std::optional<std::string> space;
};


// XmlTraits for tt_Vector2D
template<>
struct xml_convert::XmlTraits<tt_Vector2D> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("x", &tt_Vector2D::x, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("y", &tt_Vector2D::y, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("space", &tt_Vector2D::space, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Vector1D 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_Vector1D {
    float x {};
    /*
     * Zoom coordinate space selector. The following options are defined:
     * http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace
     * http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace
     * http://www.onvif.org/ver10/tptz/ZoomSpaces/VelocityGenericSpace
     * http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace
     */
    std::optional<std::string> space;
};


// XmlTraits for tt_Vector1D
template<>
struct xml_convert::XmlTraits<tt_Vector1D> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("x", &tt_Vector1D::x, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("space", &tt_Vector1D::space, nullptr, xml_convert::serialize_type::attribute)
    );
};


// PTZVector 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_PTZVector {
    // Pan and tilt position. The x component corresponds to pan and the y component to tilt.
    std::optional<tt_Vector2D> PanTilt;
    // A zoom position.
    std::optional<tt_Vector1D> Zoom;
};


// XmlTraits for tt_PTZVector
template<>
struct xml_convert::XmlTraits<tt_PTZVector> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PanTilt", &tt_PTZVector::PanTilt, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Zoom", &tt_PTZVector::Zoom, "tt", xml_convert::serialize_type::full)
    );
};


// FieldOfView 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_FieldOfView {
    // Horizontal field-of-view in degrees.
    float hfov {};
    // Vertical field-of-view in degrees.
    float vfov {};
};


// XmlTraits for tt_FieldOfView
template<>
struct xml_convert::XmlTraits<tt_FieldOfView> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("hfov", &tt_FieldOfView::hfov, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("vfov", &tt_FieldOfView::vfov, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MoveStatus 枚举类型
// 基础类型: std::string
enum class  tt_MoveStatus {
    IDLE,
    MOVING,
    UNKNOWN
};

// 字符串转换函数
inline std::string to_string(tt_MoveStatus value) {
    switch (value) {
        case tt_MoveStatus::IDLE: return "IDLE";
        case tt_MoveStatus::MOVING: return "MOVING";
        case tt_MoveStatus::UNKNOWN: return "UNKNOWN";
        default: return "";
    }
}

inline bool from_string(tt_MoveStatus& value, const std::string& str) {
    if (str == "IDLE") { value = tt_MoveStatus::IDLE; return true; }
    if (str == "MOVING") { value = tt_MoveStatus::MOVING; return true; }
    if (str == "UNKNOWN") { value = tt_MoveStatus::UNKNOWN; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_MoveStatus
template<>
struct xml_convert::XmlValueAdapter<tt_MoveStatus> {
    static bool from_xml_val(tt_MoveStatus& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_MoveStatus& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_MoveStatus
template<>
struct xml_convert::XmlAttributeAdapter<tt_MoveStatus> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_MoveStatus& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_MoveStatus& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// PTZMoveStatus 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_PTZMoveStatus {
    std::optional<tt_MoveStatus> PanTilt;
    std::optional<tt_MoveStatus> Zoom;
};


// XmlTraits for tt_PTZMoveStatus
template<>
struct xml_convert::XmlTraits<tt_PTZMoveStatus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PanTilt", &tt_PTZMoveStatus::PanTilt, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Zoom", &tt_PTZMoveStatus::Zoom, "tt", xml_convert::serialize_type::full)
    );
};


// PTZStatus 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_PTZStatus {
    // Specifies the absolute position of the PTZ unit together with the Space references. The default absolute spaces of the corresponding PTZ configuration MUST be referenced within the Position element.
    std::optional<tt_PTZVector> Position;
    // Indicates if the Pan/Tilt/Zoom device unit is currently moving, idle or in an unknown state.
    std::optional<tt_PTZMoveStatus> MoveStatus;
    // States a current PTZ error.
    std::optional<std::string> Error;
    // Specifies the UTC time when this status was generated.
    std::string UtcTime;
    // States the current field of view of the video stream.
    std::optional<tt_FieldOfView> FieldOfView;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_PTZStatus
template<>
struct xml_convert::XmlTraits<tt_PTZStatus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Position", &tt_PTZStatus::Position, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MoveStatus", &tt_PTZStatus::MoveStatus, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Error", &tt_PTZStatus::Error, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UtcTime", &tt_PTZStatus::UtcTime, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FieldOfView", &tt_PTZStatus::FieldOfView, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_PTZStatus::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_PTZStatus::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Vector 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_Vector {
    float x {};
    float y {};
};


// XmlTraits for tt_Vector
template<>
struct xml_convert::XmlTraits<tt_Vector> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("x", &tt_Vector::x, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("y", &tt_Vector::y, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Rectangle 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_Rectangle {
    float bottom {};
    float top {};
    float right {};
    float left {};
};


// XmlTraits for tt_Rectangle
template<>
struct xml_convert::XmlTraits<tt_Rectangle> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("bottom", &tt_Rectangle::bottom, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("top", &tt_Rectangle::top, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("right", &tt_Rectangle::right, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("left", &tt_Rectangle::left, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Polygon 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_Polygon {
    std::vector<tt_Vector> Point;
};


// XmlTraits for tt_Polygon
template<>
struct xml_convert::XmlTraits<tt_Polygon> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Point", &tt_Polygon::Point, "tt", xml_convert::serialize_type::full)
    );
};


// Color 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_Color {
    float X {};
    float Y {};
    float Z {};
    /*
     * Acceptable values:
     *
     * http://www.onvif.org/ver10/colorspace/YCbCr - YCbCr
     * X attribute = Y value
     * Y attribute = Cb value
     * Z attribute = Cr value
     *
     * http://www.onvif.org/ver10/colorspace/RGB - RGB
     * X attribute = R value
     * Y attribute = G value
     * Z attribute = B value
     *
     *
     * If the Colorspace attribute is absent and not defined on higher level, YCbCr is implied.
     *
     * Deprecated values:
     *
     * http://www.onvif.org/ver10/colorspace/CIELUV - CIE LUV
     * http://www.onvif.org/ver10/colorspace/CIELAB - CIE 1976 (L*a*b*)
     * http://www.onvif.org/ver10/colorspace/HSV - HSV
     */
    std::optional<std::string> Colorspace;
    // Likelihood that the color is correct.
    std::optional<float> Likelihood;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Color
template<>
struct xml_convert::XmlTraits<tt_Color> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("X", &tt_Color::X, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Y", &tt_Color::Y, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Z", &tt_Color::Z, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Colorspace", &tt_Color::Colorspace, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Likelihood", &tt_Color::Likelihood, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_Color::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ColorCovariance 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_ColorCovariance {
    float XX {};
    float YY {};
    float ZZ {};
    std::optional<float> XY;
    std::optional<float> XZ;
    std::optional<float> YZ;
    // Acceptable values are the same as in tt:Color.
    std::optional<std::string> Colorspace;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ColorCovariance
template<>
struct xml_convert::XmlTraits<tt_ColorCovariance> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("XX", &tt_ColorCovariance::XX, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("YY", &tt_ColorCovariance::YY, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("ZZ", &tt_ColorCovariance::ZZ, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("XY", &tt_ColorCovariance::XY, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("XZ", &tt_ColorCovariance::XZ, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("YZ", &tt_ColorCovariance::YZ, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Colorspace", &tt_ColorCovariance::Colorspace, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_ColorCovariance::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ColorCluster 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_ColorCluster {
    tt_Color Color;
    std::optional<float> Weight;
    std::optional<tt_ColorCovariance> Covariance;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ColorCluster
template<>
struct xml_convert::XmlTraits<tt_ColorCluster> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Color", &tt_ColorCluster::Color, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Weight", &tt_ColorCluster::Weight, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Covariance", &tt_ColorCluster::Covariance, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ColorCluster::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ColorCluster::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// ColorDescriptor 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_ColorDescriptor {
    std::vector<tt_ColorCluster> ColorCluster;
    std::optional<std::string> Extension;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_ColorDescriptor
template<>
struct xml_convert::XmlTraits<tt_ColorDescriptor> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ColorCluster", &tt_ColorDescriptor::ColorCluster, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_ColorDescriptor::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tt_ColorDescriptor::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tt_ColorDescriptor::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// TransformationExtension 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_TransformationExtension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tt_TransformationExtension
template<>
struct xml_convert::XmlTraits<tt_TransformationExtension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_TransformationExtension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// Transformation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_Transformation {
    std::optional<tt_Vector> Translate;
    std::optional<tt_Vector> Scale;
    std::optional<tt_TransformationExtension> Extension;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_Transformation
template<>
struct xml_convert::XmlTraits<tt_Transformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Translate", &tt_Transformation::Translate, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Scale", &tt_Transformation::Scale, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tt_Transformation::Extension, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &tt_Transformation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GeoLocation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_GeoLocation {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // East west location as angle.
    std::optional<double> lon;
    // North south location as angle.
    std::optional<double> lat;
    // Hight in meters above sea level.
    std::optional<float> elevation;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_GeoLocation
template<>
struct xml_convert::XmlTraits<tt_GeoLocation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_GeoLocation::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("lon", &tt_GeoLocation::lon, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("lat", &tt_GeoLocation::lat, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("elevation", &tt_GeoLocation::elevation, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_GeoLocation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GeoOrientation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_GeoOrientation {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Rotation around the x axis.
    std::optional<float> roll;
    // Rotation around the y axis.
    std::optional<float> pitch;
    // Rotation around the z axis.
    std::optional<float> yaw;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_GeoOrientation
template<>
struct xml_convert::XmlTraits<tt_GeoOrientation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_GeoOrientation::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("roll", &tt_GeoOrientation::roll, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("pitch", &tt_GeoOrientation::pitch, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("yaw", &tt_GeoOrientation::yaw, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_GeoOrientation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// LocalLocation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_LocalLocation {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // East west location as angle.
    std::optional<float> x;
    // North south location as angle.
    std::optional<float> y;
    // Offset in meters from the sea level.
    std::optional<float> z;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_LocalLocation
template<>
struct xml_convert::XmlTraits<tt_LocalLocation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_LocalLocation::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("x", &tt_LocalLocation::x, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("y", &tt_LocalLocation::y, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("z", &tt_LocalLocation::z, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_LocalLocation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// LocalOrientation 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_LocalOrientation {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Rotation around the y axis.
    std::optional<float> pan;
    // Rotation around the z axis.
    std::optional<float> tilt;
    // Rotation around the x axis.
    std::optional<float> roll;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tt_LocalOrientation
template<>
struct xml_convert::XmlTraits<tt_LocalOrientation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_LocalOrientation::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("pan", &tt_LocalOrientation::pan, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("tilt", &tt_LocalOrientation::tilt, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("roll", &tt_LocalOrientation::roll, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tt_LocalOrientation::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SphericalCoordinate 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_SphericalCoordinate {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Distance in meters to the object.
    std::optional<float> Distance;
    // Elevation angle in the range -90 to 90 degrees, where 0 is in level with the x-y plane.
    std::optional<float> ElevationAngle;
    // Azimuth angle in the range -180 to 180 degrees counter clockwise, where 0 is rightwards.
    std::optional<float> AzimuthAngle;
};


// XmlTraits for tt_SphericalCoordinate
template<>
struct xml_convert::XmlTraits<tt_SphericalCoordinate> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tt_SphericalCoordinate::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Distance", &tt_SphericalCoordinate::Distance, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("ElevationAngle", &tt_SphericalCoordinate::ElevationAngle, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AzimuthAngle", &tt_SphericalCoordinate::AzimuthAngle, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Entity 枚举类型
// 基础类型: std::string
enum class  tt_Entity {
    Device,
    VideoSource,
    AudioSource
};

// 字符串转换函数
inline std::string to_string(tt_Entity value) {
    switch (value) {
        case tt_Entity::Device: return "Device";
        case tt_Entity::VideoSource: return "VideoSource";
        case tt_Entity::AudioSource: return "AudioSource";
        default: return "";
    }
}

inline bool from_string(tt_Entity& value, const std::string& str) {
    if (str == "Device") { value = tt_Entity::Device; return true; }
    if (str == "VideoSource") { value = tt_Entity::VideoSource; return true; }
    if (str == "AudioSource") { value = tt_Entity::AudioSource; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tt_Entity
template<>
struct xml_convert::XmlValueAdapter<tt_Entity> {
    static bool from_xml_val(tt_Entity& val, xmlNodePtr element, const char* name = nullptr,
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
    
    static bool to_xml_val(const tt_Entity& val, xmlNodePtr parent, const char* name,
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

// XmlAttributeAdapter specialization for enum tt_Entity
template<>
struct xml_convert::XmlAttributeAdapter<tt_Entity> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tt_Entity& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tt_Entity& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// LocationEntity 类型定义
// 命名空间: http://www.onvif.org/ver10/schema
// 源文件: common_v10.xsd
struct tt_LocationEntity {
    // Location on earth.
    std::optional<tt_GeoLocation> GeoLocation;
    // Orientation relative to earth.
    std::optional<tt_GeoOrientation> GeoOrientation;
    // Indoor location offset.
    std::optional<tt_LocalLocation> LocalLocation;
    // Indoor orientation offset.
    std::optional<tt_LocalOrientation> LocalOrientation;
    // Entity type the entry refers to, use a value from the tt:Entity enumeration.
    std::optional<std::string> Entity;
    // Optional entity token.
    std::optional<tt_ReferenceToken> Token;
    // If this value is true the entity cannot be deleted.
    std::optional<bool> Fixed;
    // Optional reference to the XAddr of another devices DeviceManagement service.
    std::optional<std::string> GeoSource;
    // If set the geo location is obtained internally.
    std::optional<bool> AutoGeo;
};


// XmlTraits for tt_LocationEntity
template<>
struct xml_convert::XmlTraits<tt_LocationEntity> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("GeoLocation", &tt_LocationEntity::GeoLocation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("GeoOrientation", &tt_LocationEntity::GeoOrientation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("LocalLocation", &tt_LocationEntity::LocalLocation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("LocalOrientation", &tt_LocationEntity::LocalOrientation, "tt", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Entity", &tt_LocationEntity::Entity, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Token", &tt_LocationEntity::Token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Fixed", &tt_LocationEntity::Fixed, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("GeoSource", &tt_LocationEntity::GeoSource, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AutoGeo", &tt_LocationEntity::AutoGeo, nullptr, xml_convert::serialize_type::attribute)
    );
};


} // namespace libonvif_client
