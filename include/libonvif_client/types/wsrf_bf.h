/**
 * @file wsrf_bf.h
 * @brief 从 bf-2.xsd 生成的类型定义
 * @namespace http://docs.oasis-open.org/wsrf/bf-2
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 * @comment WS-* 规范相关
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/wsa.h>
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

// ErrorCode 类型定义
// 命名空间: http://docs.oasis-open.org/wsrf/bf-2
// 源文件: bf-2.xsd
struct wsrf_bf_ErrorCode {
    // Mixed content any element
    std::optional<AnyElement> _any_;
    std::string dialect;
};


// XmlTraits for wsrf_bf_ErrorCode
template<>
struct xml_convert::XmlTraits<wsrf_bf_ErrorCode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsrf_bf_ErrorCode::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("dialect", &wsrf_bf_ErrorCode::dialect, nullptr, xml_convert::serialize_type::attribute)
    );
};


// Description 类型定义
// 命名空间: http://docs.oasis-open.org/wsrf/bf-2
// 源文件: bf-2.xsd
struct wsrf_bf_Description {
    // Value content based on xsd:string
    std::string value;
    std::optional<std::string> lang;
};


// XmlTraits for wsrf_bf_Description
template<>
struct xml_convert::XmlTraits<wsrf_bf_Description> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &wsrf_bf_Description::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("lang", &wsrf_bf_Description::lang, nullptr, xml_convert::serialize_type::attribute)
    );
};


// FaultCause 类型定义
// 命名空间: http://docs.oasis-open.org/wsrf/bf-2
// 源文件: bf-2.xsd
struct wsrf_bf_FaultCause {
    // Any element from namespace: ##other (processContents: lax)
    AnyElement _any_;
};


// XmlTraits for wsrf_bf_FaultCause
template<>
struct xml_convert::XmlTraits<wsrf_bf_FaultCause> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsrf_bf_FaultCause::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// BaseFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsrf/bf-2
// 源文件: bf-2.xsd
struct wsrf_bf_BaseFaultType {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::string Timestamp;
    std::optional<wsa_EndpointReferenceType> Originator;
    std::optional<wsrf_bf_ErrorCode> ErrorCode;
    std::vector<wsrf_bf_Description> Description;
    std::optional<wsrf_bf_FaultCause> FaultCause;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wsrf_bf_BaseFaultType
template<>
struct xml_convert::XmlTraits<wsrf_bf_BaseFaultType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wsrf_bf_BaseFaultType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Timestamp", &wsrf_bf_BaseFaultType::Timestamp, "wsrf_bf", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Originator", &wsrf_bf_BaseFaultType::Originator, "wsrf_bf", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ErrorCode", &wsrf_bf_BaseFaultType::ErrorCode, "wsrf_bf", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Description", &wsrf_bf_BaseFaultType::Description, "wsrf_bf", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FaultCause", &wsrf_bf_BaseFaultType::FaultCause, "wsrf_bf", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &wsrf_bf_BaseFaultType::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// BaseFault 类型别名
// 基础类型: wsrf_bf_BaseFaultType
using wsrf_bf_BaseFault = wsrf_bf_BaseFaultType;


} // namespace libonvif_client
