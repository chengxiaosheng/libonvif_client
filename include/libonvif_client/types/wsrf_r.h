/**
 * @file wsrf_r.h
 * @brief 从 r-2.xsd 生成的类型定义
 * @namespace http://docs.oasis-open.org/wsrf/r-2
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 * @comment Auto-generated from wsdl:import
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/wsrf_bf.h>

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

// ResourceUnknownFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsrf/r-2
// 源文件: r-2.xsd
struct wsrf_r_ResourceUnknownFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsrf_r_ResourceUnknownFaultType
template<>
struct xml_convert::XmlTraits<wsrf_r_ResourceUnknownFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// ResourceUnknownFault 类型别名
// 基础类型: wsrf_r_ResourceUnknownFaultType
using wsrf_r_ResourceUnknownFault = wsrf_r_ResourceUnknownFaultType;


// ResourceUnavailableFaultType 类型定义
// 命名空间: http://docs.oasis-open.org/wsrf/r-2
// 源文件: r-2.xsd
struct wsrf_r_ResourceUnavailableFaultType : public wsrf_bf_BaseFaultType {
};


// XmlTraits for wsrf_r_ResourceUnavailableFaultType
template<>
struct xml_convert::XmlTraits<wsrf_r_ResourceUnavailableFaultType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wsrf_bf_BaseFaultType>::fields, std::make_tuple(
)
    );
};


// ResourceUnavailableFault 类型别名
// 基础类型: wsrf_r_ResourceUnavailableFaultType
using wsrf_r_ResourceUnavailableFault = wsrf_r_ResourceUnavailableFaultType;


} // namespace libonvif_client
