/**
 * @file wstop.h
 * @brief 从 t-1.xsd 生成的类型定义
 * @namespace http://docs.oasis-open.org/wsn/t-1
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

// 前置声明（循环依赖的类型）
struct wstop_TopicType;

// Documentation 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/t-1
// 源文件: t-1.xsd
struct wstop_Documentation {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wstop_Documentation
template<>
struct xml_convert::XmlTraits<wstop_Documentation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wstop_Documentation::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// ExtensibleDocumented 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/t-1
// 源文件: t-1.xsd
struct wstop_ExtensibleDocumented {
    std::optional<wstop_Documentation> documentation;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for wstop_ExtensibleDocumented
template<>
struct xml_convert::XmlTraits<wstop_ExtensibleDocumented> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("documentation", &wstop_ExtensibleDocumented::documentation, "wstop", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_attrs_", &wstop_ExtensibleDocumented::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// QueryExpressionType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/t-1
// 源文件: t-1.xsd
struct wstop_QueryExpressionType {
    // Any element from namespace: ##any (processContents: lax)
    std::optional<AnyElement> _any_;
    std::string Dialect;
};


// XmlTraits for wstop_QueryExpressionType
template<>
struct xml_convert::XmlTraits<wstop_QueryExpressionType> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &wstop_QueryExpressionType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Dialect", &wstop_QueryExpressionType::Dialect, nullptr, xml_convert::serialize_type::attribute)
    );
};


// TopicType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/t-1
// 源文件: t-1.xsd
struct wstop_TopicType : public wstop_ExtensibleDocumented {
    std::optional<wstop_QueryExpressionType> MessagePattern;
    std::vector<wstop_TopicType> Topic;
    // Collection of any elements from namespace: ##other (processContents: strict)
    std::vector<AnyElement> _any_;
    std::string name;
    std::optional<std::string> messageTypes;
    std::optional<bool> final;
};


// XmlTraits for wstop_TopicType
template<>
struct xml_convert::XmlTraits<wstop_TopicType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wstop_ExtensibleDocumented>::fields, std::make_tuple(
        xml_convert::make_field_desc("MessagePattern", &wstop_TopicType::MessagePattern, "wstop", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Topic", &wstop_TopicType::Topic, "wstop", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wstop_TopicType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("name", &wstop_TopicType::name, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("messageTypes", &wstop_TopicType::messageTypes, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("final", &wstop_TopicType::final, nullptr, xml_convert::serialize_type::attribute))
    );
};


// ConcreteTopicExpression 类型别名
// 基础类型: std::string
using wstop_ConcreteTopicExpression = std::string;


// Topic 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/t-1
// 源文件: t-1.xsd
struct wstop_Topic : public wstop_TopicType {
    std::optional<wstop_ConcreteTopicExpression> parent;
};


// XmlTraits for wstop_Topic
template<>
struct xml_convert::XmlTraits<wstop_Topic> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wstop_TopicType>::fields, std::make_tuple(
        xml_convert::make_field_desc("parent", &wstop_Topic::parent, nullptr, xml_convert::serialize_type::attribute))
    );
};


// TopicNamespaceType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/t-1
// 源文件: t-1.xsd
struct wstop_TopicNamespaceType : public wstop_ExtensibleDocumented {
    std::vector<wstop_Topic> Topic;
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
    std::optional<std::string> name;
    std::string targetNamespace;
    std::optional<bool> final;
};


// XmlTraits for wstop_TopicNamespaceType
template<>
struct xml_convert::XmlTraits<wstop_TopicNamespaceType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wstop_ExtensibleDocumented>::fields, std::make_tuple(
        xml_convert::make_field_desc("Topic", &wstop_TopicNamespaceType::Topic, "wstop", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &wstop_TopicNamespaceType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("name", &wstop_TopicNamespaceType::name, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("targetNamespace", &wstop_TopicNamespaceType::targetNamespace, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("final", &wstop_TopicNamespaceType::final, nullptr, xml_convert::serialize_type::attribute))
    );
};


// TopicNamespace 类型别名
// 基础类型: wstop_TopicNamespaceType
using wstop_TopicNamespace = wstop_TopicNamespaceType;


// TopicSetType 类型定义
// 命名空间: http://docs.oasis-open.org/wsn/t-1
// 源文件: t-1.xsd
struct wstop_TopicSetType : public wstop_ExtensibleDocumented {
    // Collection of any elements from namespace: ##other (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for wstop_TopicSetType
template<>
struct xml_convert::XmlTraits<wstop_TopicSetType> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<wstop_ExtensibleDocumented>::fields, std::make_tuple(
        xml_convert::make_field_desc("_any_", &wstop_TopicSetType::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element))
    );
};


// TopicSet 类型别名
// 基础类型: wstop_TopicSetType
using wstop_TopicSet = wstop_TopicSetType;


// FullTopicExpression 类型别名
// 基础类型: std::string
using wstop_FullTopicExpression = std::string;


// SimpleTopicExpression 类型别名
// 基础类型: std::string
using wstop_SimpleTopicExpression = std::string;


} // namespace libonvif_client
