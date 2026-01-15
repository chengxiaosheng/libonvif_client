/**
 * @file xop.h
 * @brief 从 include.xml 生成的类型定义
 * @namespace http://www.w3.org/2004/08/xop/include
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

// Include 类型定义
// 命名空间: http://www.w3.org/2004/08/xop/include
// 源文件: include.xml
struct xop_Include {
    // Collection of any elements from namespace: ##other (processContents: strict)
    std::vector<AnyElement> _any_;
    std::string href;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for xop_Include
template<>
struct xml_convert::XmlTraits<xop_Include> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &xop_Include::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("href", &xop_Include::href, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &xop_Include::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


} // namespace libonvif_client
