/**
 * @file xmime.h
 * @brief 从 xmlmime.xml 生成的类型定义
 * @namespace http://www.w3.org/2005/05/xmlmime
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 * @comment 基础XML相关命名空间
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

// base64Binary 类型定义
// 命名空间: http://www.w3.org/2005/05/xmlmime
// 源文件: xmlmime.xml
struct xmime_base64Binary {
    // Value content based on xs:base64Binary
    std::string value;
    std::optional<std::string> contentType;
};


// XmlTraits for xmime_base64Binary
template<>
struct xml_convert::XmlTraits<xmime_base64Binary> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &xmime_base64Binary::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("contentType", &xmime_base64Binary::contentType, nullptr, xml_convert::serialize_type::attribute)
    );
};


// hexBinary 类型定义
// 命名空间: http://www.w3.org/2005/05/xmlmime
// 源文件: xmlmime.xml
struct xmime_hexBinary {
    // Value content based on xs:hexBinary
    std::string value;
    std::optional<std::string> contentType;
};


// XmlTraits for xmime_hexBinary
template<>
struct xml_convert::XmlTraits<xmime_hexBinary> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc(nullptr, &xmime_hexBinary::value, nullptr, xml_convert::serialize_type::full),
        xml_convert::make_field_desc("contentType", &xmime_hexBinary::contentType, nullptr, xml_convert::serialize_type::attribute)
    );
};


} // namespace libonvif_client
