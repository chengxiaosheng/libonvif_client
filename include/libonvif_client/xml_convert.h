/**
 * @file xml_convert.h
 * @brief 基于 libxml2 的 XML 序列化/反序列化框架，专为 ONVIF 设计
 * @note 完全基于 utils/xml_convert.h 重写，适配 libxml2 API
 */

#pragma once

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <map>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

namespace libonvif_client {


// ==================== AnyElement 类型系统 ====================

/**
 * @brief 表示任意XML元素的结构，专门用于处理 xs:any 类型
 *
 * 此类型完全支持XML命名空间、属性、文本内容和嵌套子元素。
 * 设计用于处理ONVIF扩展点和任意命名空间的XML内容。
 */
struct AnyElement {
    std::string local_name;                           ///< 元素的本地名称（不含命名空间前缀）
    std::string namespace_uri;                        ///< 完整的命名空间URI
    std::string ns_prefix;                            ///< 命名空间前缀（用于XML生成）
    std::map<std::string, std::string> attributes;    ///< 元素属性（属性名 -> 属性值）
    std::string text_content;                         ///< 文本内容（如果有）
    std::vector<AnyElement> children;                 ///< 子元素集合

    // 构造函数
    AnyElement() = default;

    /**
     * @brief 构造一个简单的AnyElement
     * @param name 元素名称
     * @param content 文本内容（可选）
     * @param ns_uri 命名空间URI（可选）
     * @param prefix 命名空间前缀（可选）
     */
    explicit AnyElement(const std::string& name, const std::string& content = "",
              const std::string& ns_uri = "", const std::string& prefix = "")
        : local_name(name), namespace_uri(ns_uri), ns_prefix(prefix), text_content(content) {}

    // 便利方法

    /**
     * @brief 添加子元素
     */
    void add_child(const AnyElement& child) {
        children.push_back(child);
    }

    /**
     * @brief 添加属性
     */
    void set_attribute(const std::string& name, const std::string& value) {
        attributes[name] = value;
    }

    /**
     * @brief 根据命名空间URI查找子元素
     */
    [[nodiscard]] std::vector<AnyElement> get_children_by_namespace(const std::string& ns_uri) const {
        std::vector<AnyElement> result;
        for (const auto& child : children) {
            if (child.namespace_uri == ns_uri) {
                result.push_back(child);
            }
        }
        return result;
    }

    /**
     * @brief 根据元素名称查找子元素
     */
    [[nodiscard]] std::vector<AnyElement> get_children_by_name(const std::string& name) const {
        std::vector<AnyElement> result;
        for (const auto& child : children) {
            if (child.local_name == name) {
                result.push_back(child);
            }
        }
        return result;
    }

    /**
     * @brief 查找第一个匹配名称的子元素
     */
    [[nodiscard]] std::optional<AnyElement> find_child(const std::string& name) const {
        for (const auto& child : children) {
            if (child.local_name == name) {
                return child;
            }
        }
        return std::nullopt;
    }

    /**
     * @brief 检查是否为空元素（无内容、无属性、无子元素）
     */
    bool empty() const {
        return local_name.empty() && text_content.empty() &&
               attributes.empty() && children.empty();
    }

    /**
     * @brief 获取完整的元素名（包含前缀）
     */
    [[nodiscard]] std::string full_name() const {
        if (ns_prefix.empty()) {
            return local_name;
        }
        return ns_prefix + ":" + local_name;
    }
};

namespace xml_convert {

// ==================== 内部辅助函数命名空间 ====================
namespace detail {

/**
 * @brief 根据名称查找子元素（宽松命名空间处理）
 * @note 只匹配元素名，忽略命名空间 - 适用于宽松的ONVIF场景
 */
inline xmlNodePtr xmlGetChildElementByName(xmlNodePtr parent, const char* name) {
    if (!parent || !name) return nullptr;

    for (xmlNodePtr child = parent->children; child; child = child->next) {
        if (child->type == XML_ELEMENT_NODE &&
            xmlStrcmp(child->name, BAD_CAST name) == 0) {
            return child;
        }
    }
    return nullptr;
}

/**
 * @brief 获取下一个同名兄弟节点（宽松命名空间处理）
 */
inline xmlNodePtr xmlGetNextSiblingByName(xmlNodePtr node, const char* name) {
    if (!node || !name) return nullptr;

    for (xmlNodePtr sibling = node->next; sibling; sibling = sibling->next) {
        if (sibling->type == XML_ELEMENT_NODE &&
            xmlStrcmp(sibling->name, BAD_CAST name) == 0) {
            return sibling;
        }
    }
    return nullptr;
}

/**
 * @brief 创建带命名空间的元素（优化：复用已存在的命名空间声明）
 */
inline xmlNodePtr create_element_with_ns(xmlNodePtr parent, const char* name,
                                         const char* ns_prefix,
                                         const std::map<std::string_view, std::string_view>& namespaces) {
    xmlNodePtr element = xmlNewChild(parent, nullptr, BAD_CAST name, nullptr);
    if (!element || !ns_prefix) return element;

    auto it = namespaces.find(ns_prefix);
    if (it != namespaces.end()) {
        // 优先查找已存在的命名空间声明（避免重复）
        xmlNsPtr ns = xmlSearchNs(element->doc, element, BAD_CAST ns_prefix);
        if (!ns) {
            // 不存在则创建新的命名空间声明
            ns = xmlNewNs(xmlDocGetRootElement(element->doc), BAD_CAST it->second.data(), BAD_CAST ns_prefix);
        }
        if (ns) {
            xmlSetNs(element, ns);
        }
    }
    return element;
}

} // namespace detail

enum class serialize_type {
    serialize = 1 << 0,      // 从结构体到XML
    deserialize = 1 << 1,    // 从XML到结构体
    full = ((1 << 0) | (1 << 1)),  // 双向支持
    attribute = 1 << 2,      // 作为XML属性而非子元素
    any_element = 1 << 3     // xs:any 扩展字段（收集/输出未知元素）
};

constexpr serialize_type operator|(serialize_type a, serialize_type b) {
    return static_cast<serialize_type>(static_cast<int>(a) | static_cast<int>(b));
}

constexpr serialize_type operator&(serialize_type a, serialize_type b) {
    return static_cast<serialize_type>(static_cast<int>(a) & static_cast<int>(b));
}

// 字段描述符
template<typename Struct, typename FieldType>
struct FieldDesc {
    static_assert(std::is_class_v<Struct>, "Struct must be a class type");
    using parent_type = Struct;
    using field_type = FieldType;
    const char* name{nullptr};   // 字段名称，nullptr表示取父元素内容
    const char* ns_prefix{nullptr}; // 命名空间前缀
    FieldType Struct::*ptr{nullptr}; // 成员指针
    serialize_type type = serialize_type::full; // 序列化类型
};

// 类型特征标记
template<typename T>
struct XmlTraits; // 用户必须特化此模板

template <typename T, typename = void>
struct has_xml_traits : std::false_type {};

template<typename T>
struct has_xml_traits<T, std::void_t<decltype(XmlTraits<T>::fields)>> : std::true_type {};

// 创建字段描述符
template<typename Struct, typename FieldType>
constexpr auto make_field_desc(const char* name, FieldType Struct::*ptr,
                              const char* ns_prefix = nullptr,
                              serialize_type type = serialize_type::full) {
    return FieldDesc<Struct, FieldType>{name, ns_prefix, ptr, type};
}

// 宏定义简化使用
#define XML_FIELD(struct_type, member) libonvif_client::xml_convert::make_field_desc(#member, &struct_type::member)
#define XML_FIELD_NS(struct_type, member, ns_prefix) libonvif_client::xml_convert::make_field_desc(#member, &struct_type::member, ns_prefix)
#define XML_ATTR(struct_type, member) libonvif_client::xml_convert::make_field_desc(#member, &struct_type::member, nullptr, libonvif_client::xml_convert::serialize_type::full | libonvif_client::xml_convert::serialize_type::attribute)
#define XML_ATTR_NS(struct_type, member, ns_prefix) libonvif_client::xml_convert::make_field_desc(#member, &struct_type::member, ns_prefix, libonvif_client::xml_convert::serialize_type::full | libonvif_client::xml_convert::serialize_type::attribute)
#define XML_CONTENT_VALUE(struct_type, member) libonvif_client::xml_convert::make_field_desc(nullptr, &struct_type::member)

// remove_cvref的实现（C++17兼容）
template<typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

// 判断类型是否可XML序列化
template<typename T, typename = void>
struct is_xml_serializable_impl : std::false_type {};

template<typename T>
struct is_xml_serializable_impl<T, std::void_t<decltype(XmlTraits<T>::fields)>> : std::true_type {};

template<typename T>
constexpr bool IsXmlSerializable = is_xml_serializable_impl<T>::value;

template<typename T>
struct dependent_false {
    static constexpr bool value = false;
};

// 前置声明
template<typename T>
bool from_xml_val(T& val, xmlNodePtr element, const char* name = nullptr,
                 const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {});

template<typename T>
bool to_xml_val(const T& val, xmlNodePtr parent, const char* name, 
               const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {});

namespace traits {
    template<typename>
    struct is_optional : std::false_type {};

    template<typename T>
    struct is_optional<std::optional<T>> : std::true_type {};

    template<typename>
    struct is_vector : std::false_type {};

    template<typename T>
    struct is_vector<std::vector<T>> : std::true_type {};

    template<typename>
    struct is_unique_ptr : std::false_type {};

    template<typename T>
    struct is_unique_ptr<std::unique_ptr<T>> : std::true_type {};
} // namespace traits

// XML属性适配器 - 专门处理XML属性的序列化和反序列化
template<typename T>
struct XmlAttributeAdapter {
    // 序列化属性：将值写入XML属性
    static bool to_attribute(xmlNodePtr element, const char* name, const T& value) {
        if (!element || !name) return false;

        if constexpr (traits::is_optional<T>::value) {
            if (!value.has_value()) return true; // optional为空时不设置属性
            using ValueType = typename T::value_type;
            return XmlAttributeAdapter<ValueType>::to_attribute(element, name, value.value());
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            xmlSetProp(element, BAD_CAST name, BAD_CAST value.c_str());
            return true;
        }
        else if constexpr (std::is_same_v<T, bool>) {
            xmlSetProp(element, BAD_CAST name, BAD_CAST (value ? "true" : "false"));
            return true;
        }
        else if constexpr (std::is_arithmetic_v<T>) {
            if constexpr (std::is_unsigned_v<T>) {
                std::string str_val = std::to_string(static_cast<uint64_t>(value));
                xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
            } else if constexpr (std::is_floating_point_v<T>) {
                std::string str_val = std::to_string(static_cast<double>(value));
                xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
            } else {
                std::string str_val = std::to_string(static_cast<int64_t>(value));
                xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
            }
            return true;
        }
        else {
            // 对于复杂类型，尝试转换为字符串
            // static_assert(dependent_false<T>::value, "Unsupported attribute type - consider specializing XmlAttributeAdapter");
            return false;
        }
    }
    
    // 反序列化属性：从XML属性读取值
    static bool from_attribute(T& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;

        if constexpr (traits::is_optional<T>::value) {
            using ValueType = typename T::value_type;
            ValueType temp{};
            // 直接调用内层类型的特化版本，以支持复杂类型（如 map）
            if (XmlAttributeAdapter<ValueType>::from_attribute(temp, element, name)) {
                value = std::move(temp);
                return true;
            }
            value.reset();
            return false;
        }
        else {
            xmlChar* attr = xmlGetProp(element, BAD_CAST name);
            if (!attr) {
                return false; // 必需属性不存在
            }

            std::string str_val(reinterpret_cast<char*>(attr));
            xmlFree(attr);

            return parse_attribute_value(value, str_val);
        }
    }
    
private:
    // 解析属性值的通用函数
    template<typename U>
    static bool parse_attribute_value(U& val, const std::string& str_val) {
        if constexpr (std::is_same_v<U, std::string>) {
            val = str_val;
            return true;
        }
        else if constexpr (std::is_same_v<U, bool>) {
            val = (str_val == "true" || str_val == "True" || str_val == "1" || str_val == "yes" || str_val == "Yes");
            return true;
        }
        else if constexpr (std::is_arithmetic_v<U>) {
            try {
                if constexpr (std::is_unsigned_v<U>) {
                    uint64_t temp_val = std::stoull(str_val);
                    val = static_cast<U>(temp_val);
                } else if constexpr (std::is_floating_point_v<U>) {
                    double temp_val = std::stod(str_val);
                    val = static_cast<U>(temp_val);
                } else {
                    int64_t temp_val = std::stoll(str_val);
                    val = static_cast<U>(temp_val);
                }
                return true;
            } catch (...) {
                return false;
            }
        }
        else {
            // 对于复杂类型，可以特化此模板
            // static_assert(dependent_false<U>::value, "Unsupported attribute value type - consider specializing parse_attribute_value");
            return false;
        }
    }
};

// XmlAttributeAdapter 特化：std::map<std::string, std::string> - 用于 xs:anyAttribute
template<>
struct XmlAttributeAdapter<std::map<std::string, std::string>> {
    // 序列化：将 map 中的所有键值对作为 XML 属性添加到元素上
    static bool to_attribute(xmlNodePtr element, const char* name, const std::map<std::string, std::string>& value) {
        if (!element) return false;

        // 对于 anyAttribute，忽略 name 参数，直接将所有键值对添加为属性
        for (const auto& [attr_name, attr_value] : value) {
            xmlSetProp(element, BAD_CAST attr_name.c_str(), BAD_CAST attr_value.c_str());
        }
        return true;
    }

    // 反序列化：读取元素的所有属性到 map 中
    // 注意：这会读取所有属性，包括已知的命名属性
    // 调用者需要在更高层过滤掉已知属性
    static bool from_attribute(std::map<std::string, std::string>& value, xmlNodePtr element, const char* name) {
        if (!element) return false;

        value.clear();

        // 遍历元素的所有属性
        for (xmlAttrPtr attr = element->properties; attr; attr = attr->next) {
            if (attr->name && attr->children && attr->children->content) {
                std::string attr_name(reinterpret_cast<const char*>(attr->name));
                std::string attr_value(reinterpret_cast<const char*>(attr->children->content));
                value[attr_name] = attr_value;
            }
        }
        return true;
    }
};

// XmlAttributeAdapter 特化示例 - 用于复杂的ONVIF类型
/*
// 示例：为枚举类型特化
template<>
struct XmlAttributeAdapter<MyEnumType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const MyEnumType& value) {
        std::string enum_str = enum_to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST enum_str.c_str());
        return true;
    }
    
    static bool from_attribute(MyEnumType& value, xmlNodePtr element, const char* name) {
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        
        return string_to_enum(str_val, value);
    }
};

// 示例：为日期时间类型特化
template<>
struct XmlAttributeAdapter<std::chrono::system_clock::time_point> {
    static bool to_attribute(xmlNodePtr element, const char* name, const std::chrono::system_clock::time_point& value) {
        std::string iso_time = to_iso_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST iso_time.c_str());
        return true;
    }
    
    static bool from_attribute(std::chrono::system_clock::time_point& value, xmlNodePtr element, const char* name) {
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        
        return from_iso_string(str_val, value);
    }
};
*/

// 基础类型适配器 - 完全基于原版设计
template<typename T>
struct XmlValueAdapter {
    static bool to_xml_val(const T& val, xmlNodePtr parent, const char* name, 
                          const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;
        
        if constexpr (traits::is_optional<T>::value) {
            if (!val) return true; // 可选类型为空时不添加元素
            return xml_convert::to_xml_val(val.value(), parent, name, ns_prefix, namespaces);
        }
        else if constexpr (traits::is_unique_ptr<T>::value) {
            if (!val) return true; // nullptr 时不添加元素
            return xml_convert::to_xml_val(*val, parent, name, ns_prefix, namespaces);
        }
        else if constexpr (traits::is_vector<T>::value) {
            for (const auto& item : val) {
                xml_convert::to_xml_val(item, parent, name, ns_prefix, namespaces);
            }
            return true;
        }
        else if constexpr (std::is_arithmetic_v<T>) {
            xmlNodePtr element = detail::create_element_with_ns(parent, name, ns_prefix, namespaces);
            if (!element) return false;

            if constexpr (std::is_same_v<T, bool>) {
                xmlNodeSetContent(element, BAD_CAST (val ? "true" : "false"));
            }
            else if constexpr (std::is_floating_point_v<T>) {
                std::string str_val = std::to_string(static_cast<double>(val));
                xmlNodeSetContent(element, BAD_CAST str_val.c_str());
            }
            else if constexpr (std::is_unsigned_v<T>) {
                std::string str_val = std::to_string(static_cast<uint64_t>(val));
                xmlNodeSetContent(element, BAD_CAST str_val.c_str());
            }
            else {
                std::string str_val = std::to_string(static_cast<int64_t>(val));
                xmlNodeSetContent(element, BAD_CAST str_val.c_str());
            }
            return true;
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            xmlNodePtr element = detail::create_element_with_ns(parent, name, ns_prefix, namespaces);
            if (!element) return false;
            xmlNodeSetContent(element, BAD_CAST val.c_str());
            return true;
        } 
        else {
            static_assert(dependent_false<T>::value, "必须特化此模板或定义XmlTraits");
            return false;
        }
        return false;
    }

    static bool from_xml_val(T& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        // 预留ns_prefix和namespaces参数，目前未使用，后续可扩展
        xmlNodePtr targetElement = name ?
            detail::xmlGetChildElementByName(element, name) : element;
        if (!targetElement) return false;

        if constexpr (traits::is_vector<T>::value) {
            using ValueType = typename T::value_type;
            val.clear();

            // 查找所有同名子节点
            for (xmlNodePtr child = targetElement; child; child = detail::xmlGetNextSiblingByName(child, name)) {
                ValueType temp{};
                if (xml_convert::from_xml_val(temp, child, nullptr, ns_prefix, namespaces)) {
                    val.push_back(std::move(temp));
                }
            }
            return true;
        }
        else if constexpr (traits::is_optional<T>::value) {
            using ValueType = typename T::value_type;
            ValueType temp{};
            if (xml_convert::from_xml_val(temp, targetElement, nullptr, ns_prefix, namespaces)) {
                val = std::move(temp);
                return true;
            }
            return false;
        }
        else if constexpr (traits::is_unique_ptr<T>::value) {
            using ValueType = typename T::element_type;
            val = std::make_unique<ValueType>();
            if (xml_convert::from_xml_val(*val, targetElement, nullptr, ns_prefix, namespaces)) {
                return true;
            }
            val.reset();
            return false;
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            if (xmlChar *content = xmlNodeGetContent(targetElement)) {
                val = reinterpret_cast<char*>(content);
                xmlFree(content);
                return true;
            }
            return false;
        } 
        else if constexpr (std::is_arithmetic_v<T>) {
            xmlChar* content = xmlNodeGetContent(targetElement);
            if (!content) return false;
            
            std::string str_val(reinterpret_cast<char*>(content));
            xmlFree(content);
            
            try {
                if constexpr (std::is_same_v<T, bool>) {
                    val = (str_val == "true" || str_val == "True" || str_val == "1");
                } else if constexpr (std::is_floating_point_v<T>) {
                    val = static_cast<T>(std::stod(str_val));
                } else if constexpr (std::is_unsigned_v<T>) {
                    val = static_cast<T>(std::stoull(str_val));
                } else if constexpr (std::is_integral_v<T>) {
                    val = static_cast<T>(std::stoll(str_val));
                }
                return true;
            } catch (...) {
                return false;
            }
        } 
        else {
            static_assert(dependent_false<T>::value, "必须特化此模板或定义XmlTraits");
        }
        return false;
    }
};

// XmlValueAdapter 特化：std::map<std::string, std::string>
// 用于将 map 序列化为多个子元素，每个元素包含 key 和 value 子元素
template<>
struct XmlValueAdapter<std::map<std::string, std::string>> {
    static bool to_xml_val(const std::map<std::string, std::string>& val, xmlNodePtr parent, const char* name,
                          const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;

        // 为每个键值对创建一个子元素
        for (const auto& [key, value] : val) {
            xmlNodePtr element = xmlNewChild(parent, nullptr, BAD_CAST name, nullptr);
            if (!element) return false;

            // 创建 key 子元素
            xmlNodePtr keyNode = xmlNewChild(element, nullptr, BAD_CAST "key", BAD_CAST key.c_str());
            if (!keyNode) return false;

            // 创建 value 子元素
            xmlNodePtr valueNode = xmlNewChild(element, nullptr, BAD_CAST "value", BAD_CAST value.c_str());
            if (!valueNode) return false;
        }

        return true;
    }

    static bool from_xml_val(std::map<std::string, std::string>& val, xmlNodePtr element, const char* name = nullptr,
                            const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!element) return false;

        val.clear();

        // 查找所有同名子节点
        xmlNodePtr targetElement = name ? detail::xmlGetChildElementByName(element, name) : element;

        for (xmlNodePtr child = targetElement; child; child = name ? detail::xmlGetNextSiblingByName(child, name) : child->next) {
            if (name && child->type != XML_ELEMENT_NODE) continue;

            // 读取 key 子元素
            xmlNodePtr keyNode = detail::xmlGetChildElementByName(child, "key");
            if (!keyNode) {
                if (!name) break; // 如果没有指定 name，只处理第一个元素
                continue;
            }

            xmlChar* keyContent = xmlNodeGetContent(keyNode);
            if (!keyContent) {
                if (!name) break;
                continue;
            }
            std::string key(reinterpret_cast<char*>(keyContent));
            xmlFree(keyContent);

            // 读取 value 子元素
            xmlNodePtr valueNode = detail::xmlGetChildElementByName(child, "value");
            if (!valueNode) {
                if (!name) break;
                continue;
            }

            xmlChar* valueContent = xmlNodeGetContent(valueNode);
            if (!valueContent) {
                if (!name) break;
                continue;
            }
            std::string value(reinterpret_cast<char*>(valueContent));
            xmlFree(valueContent);

            val[key] = value;

            if (!name) break; // 如果没有指定 name，只处理第一个元素
        }

        return true;
    }
};

template<>
struct XmlValueAdapter<AnyElement> {
    static bool from_xml_val(AnyElement& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        xmlNodePtr target_element = name ? xmlGetChildElementByName(element, name) : element;
        if (!target_element) return false;

        return parse_element_recursive(val, target_element, namespaces);
    }

    static bool to_xml_val(const AnyElement& val, xmlNodePtr parent, const char* name,
                           const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent) return false;

        // 如果指定了name参数，使用它；否则使用AnyElement的local_name
        const std::string element_name = name ? name : val.local_name;
        if (element_name.empty()) return false;

        return create_element_recursive(val, parent, element_name, namespaces);
    }

private:
    /**
     * @brief 递归解析XML元素到AnyElement
     */
    static bool parse_element_recursive(AnyElement& element, xmlNodePtr xml_node,
                                       const std::map<std::string_view, std::string_view>& namespaces) {
        if (!xml_node) return false;

        // 设置元素名称
        element.local_name = reinterpret_cast<const char*>(xml_node->name);

        // 处理命名空间
        if (xml_node->ns) {
            if (xml_node->ns->href) {
                element.namespace_uri = reinterpret_cast<const char*>(xml_node->ns->href);
            }
            if (xml_node->ns->prefix) {
                element.ns_prefix = reinterpret_cast<const char*>(xml_node->ns->prefix);
            }
        }

        // 解析属性
        for (xmlAttrPtr attr = xml_node->properties; attr; attr = attr->next) {
            if (attr->children && attr->children->content) {
                std::string attr_name = reinterpret_cast<const char*>(attr->name);
                std::string attr_value = reinterpret_cast<const char*>(attr->children->content);
                element.attributes[attr_name] = attr_value;
            }
        }

        // 处理内容和子元素
        bool has_element_children = false;
        std::string text_content;

        for (xmlNodePtr child = xml_node->children; child; child = child->next) {
            if (child->type == XML_ELEMENT_NODE) {
                has_element_children = true;
                AnyElement child_element;
                if (parse_element_recursive(child_element, child, namespaces)) {
                    element.children.push_back(std::move(child_element));
                }
            } else if (child->type == XML_TEXT_NODE || child->type == XML_CDATA_SECTION_NODE) {
                if (child->content) {
                    text_content += reinterpret_cast<const char*>(child->content);
                }
            }
        }

        // 如果没有子元素，保存文本内容
        if (!has_element_children) {
            // 清理空白字符
            text_content.erase(0, text_content.find_first_not_of(" \t\n\r"));
            text_content.erase(text_content.find_last_not_of(" \t\n\r") + 1);
            element.text_content = text_content;
        }

        return true;
    }

    /**
     * @brief 递归创建XML元素从AnyElement
     */
    static bool create_element_recursive(const AnyElement& element, xmlNodePtr parent,
                                        const std::string& element_name,
                                        const std::map<std::string_view, std::string_view>& namespaces) {
        // 创建XML元素
        xmlNodePtr xml_element = xmlNewChild(parent, nullptr, BAD_CAST element_name.c_str(), nullptr);
        if (!xml_element) return false;

        // 设置命名空间
        if (!element.ns_prefix.empty() && !element.namespace_uri.empty()) {
            xmlNsPtr ns = xmlNewNs(xml_element, BAD_CAST element.namespace_uri.c_str(),
                                  BAD_CAST element.ns_prefix.c_str());
            if (ns) {
                xmlSetNs(xml_element, ns);
            }
        } else if (!element.ns_prefix.empty()) {
            // 尝试从命名空间映射中查找URI
            auto it = namespaces.find(element.ns_prefix);
            if (it != namespaces.end()) {
                xmlNsPtr ns = xmlNewNs(xml_element, BAD_CAST it->second.data(),
                                      BAD_CAST element.ns_prefix.c_str());
                if (ns) {
                    xmlSetNs(xml_element, ns);
                }
            }
        }

        // 设置属性
        for (const auto& [attr_name, attr_value] : element.attributes) {
            xmlSetProp(xml_element, BAD_CAST attr_name.c_str(), BAD_CAST attr_value.c_str());
        }

        // 处理内容
        if (!element.children.empty()) {
            // 有子元素，递归创建子元素
            for (const auto& child : element.children) {
                if (!create_element_recursive(child, xml_element, child.local_name, namespaces)) {
                    return false;
                }
            }
        } else if (!element.text_content.empty()) {
            // 没有子元素，设置文本内容
            xmlNodeSetContent(xml_element, BAD_CAST element.text_content.c_str());
        }

        return true;
    }

    /**
     * @brief 根据名称查找子元素
     */
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


// 结构体转换器
template<typename T>
class XmlConverter {
public:
    static bool to_xml_val(const T& obj, xmlNodePtr parent, const char* name = nullptr,
                         const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;

        xmlNodePtr element = detail::create_element_with_ns(parent, name, ns_prefix, namespaces);
        if (!element) return false;

        bool success = true;
        std::apply([&](const auto&... fields) {
            ((SerializeField(element, obj, fields, namespaces) || [&]{ success = false; return false; }()), ...);
        }, XmlTraits<T>::fields);

        return success;
    }

    static bool from_xml_val(T& obj, xmlNodePtr element, const char* name = nullptr,
                           const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!element) return false;
        // 预留ns_prefix参数，目前未使用，后续可扩展
        xmlNodePtr obj_element = (name == nullptr || *name == '\0') ?
            element : detail::xmlGetChildElementByName(element, name);
        if (!obj_element) return false;

        try {
            // 两阶段反序列化，确保 xs:any 字段只收集未被处理的元素

            // 第一阶段：收集所有已定义字段的元素名称和属性名称，并检查是否存在 _any 字段
            std::set<std::string> processed_names;       // 已处理的元素名
            std::set<std::string> processed_attributes;  // 已处理的属性名
            bool has_any_field = false;
            std::apply([&](auto&&... fields) {
                ((collect_field_names(fields, processed_names, processed_attributes, has_any_field)), ...);
            }, XmlTraits<T>::fields);

            // 第二阶段：反序列化所有字段
            // 只有存在 _any 字段时，才会收集未处理的元素
            std::apply([&](auto&&... fields) {
                ((DeserializeFieldWithContext(obj_element, obj, fields, namespaces,
                                             processed_names, processed_attributes, has_any_field)), ...);
            }, XmlTraits<T>::fields);

            return true;
        } catch (...) {
            return false;
        }
    }

    // 序列化 any_element 字段的辅助方法
    template<typename FieldType>
    static bool serialize_any_element(const FieldType& value, xmlNodePtr element,
                                      const std::map<std::string_view, std::string_view>& namespaces) {
        using ::libonvif_client::AnyElement;

        if constexpr (std::is_same_v<FieldType, AnyElement>) {
            // 单个 AnyElement：使用其 local_name 直接序列化
            if (value.local_name.empty()) return true; // 空元素不序列化
            return XmlValueAdapter<AnyElement>::to_xml_val(value, element, nullptr, nullptr, namespaces);
        }
        else if constexpr (std::is_same_v<FieldType, std::optional<AnyElement>>) {
            // optional<AnyElement>：如果有值则序列化
            if (!value.has_value() || value->local_name.empty()) return true;
            return XmlValueAdapter<AnyElement>::to_xml_val(*value, element, nullptr, nullptr, namespaces);
        }
        else if constexpr (std::is_same_v<FieldType, std::vector<AnyElement>>) {
            // vector<AnyElement>：序列化所有元素
            for (const auto& elem : value) {
                if (elem.local_name.empty()) continue; // 跳过空元素
                if (!XmlValueAdapter<AnyElement>::to_xml_val(elem, element, nullptr, nullptr, namespaces)) {
                    return false;
                }
            }
            return true;
        }
        else {
            // 不支持的类型，忽略
            return true;
        }
    }

    // 字段级序列化（改为 public 以便外部使用）
    // 注意：FieldStruct 可以是 Struct 的基类（用于继承场景）
    template<typename Struct, typename FieldStruct, typename FieldType>
    static bool SerializeField(xmlNodePtr element, const Struct& obj,
                              const FieldDesc<FieldStruct, FieldType>& desc,
                              const std::map<std::string_view, std::string_view>& namespaces) {
        // 属性和 any_element 字段隐含支持序列化
        bool is_attribute = (desc.type & serialize_type::attribute) == serialize_type::attribute;
        bool is_any_element = (desc.type & serialize_type::any_element) == serialize_type::any_element;
        bool can_serialize = ((desc.type & serialize_type::serialize) == serialize_type::serialize) ||
                            is_attribute || is_any_element;

        if (!can_serialize)
            return true;

        const auto& value = obj.*(desc.ptr);

        // 属性处理 - 使用专门的属性适配器
        if (is_attribute) {
            return XmlAttributeAdapter<FieldType>::to_attribute(element, desc.name, value);
        }

        // xs:any 元素处理：对于 _any 字段，需要特殊处理
        if (is_any_element) {
            if (desc.name && std::string(desc.name) == "_any_") {
                // 对于 _any 字段，直接序列化 AnyElement 的内容，不使用字段名
                return serialize_any_element(value, element, namespaces);
            }
            // 非标准的 xs:any 字段被忽略
            return true;
        }

        // 子元素处理
        return xml_convert::to_xml_val(value, element, desc.name, desc.ns_prefix, namespaces);
    }

    // 字段级反序列化（改为 public 以便外部使用）
    // 注意：FieldStruct 可以是 Struct 的基类（用于继承场景）
    template<typename Struct, typename FieldStruct, typename FieldType>
    static void DeserializeField(xmlNodePtr element, Struct& obj,
                                const FieldDesc<FieldStruct, FieldType>& desc, const std::map<std::string_view, std::string_view>& namespaces) {
        if ((desc.type & serialize_type::deserialize) != serialize_type::deserialize)
            return;

        auto& value = obj.*(desc.ptr);

        // 属性处理 - 使用专门的属性适配器
        if ((desc.type & serialize_type::attribute) == serialize_type::attribute) {
            XmlAttributeAdapter<FieldType>::from_attribute(value, element, desc.name);
            return;
        }
        xml_convert::from_xml_val(value, element, desc.name, desc.ns_prefix, namespaces);
    }

    // 带上下文的字段级反序列化（用于处理 xs:any 和 xs:anyAttribute 的排他性）
    // 注意：FieldStruct 可以是 Struct 的基类（用于继承场景）
    template<typename Struct, typename FieldStruct, typename FieldType>
    static bool DeserializeFieldWithContext(xmlNodePtr element, Struct& obj,
                                           const FieldDesc<FieldStruct, FieldType>& desc,
                                           const std::map<std::string_view, std::string_view>& namespaces,
                                           const std::set<std::string>& processed_names,
                                           const std::set<std::string>& processed_attributes,
                                           bool has_any_field) {
        // 属性和 any_element 字段隐含支持反序列化
        bool is_attribute = (desc.type & serialize_type::attribute) == serialize_type::attribute;
        bool is_any_element = (desc.type & serialize_type::any_element) == serialize_type::any_element;
        bool can_deserialize = ((desc.type & serialize_type::deserialize) == serialize_type::deserialize) ||
                              is_attribute || is_any_element;

        if (!can_deserialize)
            return false;

        auto& value = obj.*(desc.ptr);

        // 属性处理
        if ((desc.type & serialize_type::attribute) == serialize_type::attribute) {
            // 检查是否为 anyAttribute（类型为 map<string, string> 或 optional<map<string, string>>）
            if constexpr (std::is_same_v<FieldType, std::map<std::string, std::string>>) {
                // anyAttribute：读取所有属性，然后过滤掉已知属性
                std::map<std::string, std::string> all_attrs;
                if (XmlAttributeAdapter<FieldType>::from_attribute(all_attrs, element, desc.name)) {
                    // 过滤掉已知属性
                    for (const auto& known_attr : processed_attributes) {
                        all_attrs.erase(known_attr);
                    }
                    value = std::move(all_attrs);
                }
                return true;
            } else if constexpr (std::is_same_v<FieldType, std::optional<std::map<std::string, std::string>>>) {
                // anyAttribute（可选）：读取所有属性，然后过滤掉已知属性
                std::map<std::string, std::string> all_attrs;
                if (XmlAttributeAdapter<std::map<std::string, std::string>>::from_attribute(all_attrs, element, desc.name)) {
                    // 过滤掉已知属性
                    for (const auto& known_attr : processed_attributes) {
                        all_attrs.erase(known_attr);
                    }
                    if (!all_attrs.empty()) {
                        value = std::move(all_attrs);
                    }
                }
                return true;
            } else {
                // 普通属性：使用 SFINAE 避免为不支持的类型实例化 XmlAttributeAdapter
                return deserialize_as_attribute(value, element, desc.name);
            }
        }

        // xs:any 元素处理：只有当字段名为 "_any_" 且结构体确实有 _any 字段时才收集未处理元素
        if ((desc.type & serialize_type::any_element) == serialize_type::any_element) {
            if (has_any_field && desc.name && std::string(desc.name) == "_any_") {
                collect_unprocessed_elements(value, element, processed_names, namespaces);
            }
            // 非标准的 xs:any 字段（不是 _any）被忽略
            return true;
        }

        // 普通元素处理
       return xml_convert::from_xml_val(value, element, desc.name, desc.ns_prefix, namespaces);
    }

    // SFINAE 辅助函数：只为支持的类型实例化属性反序列化
    template<typename TYPE>
    static auto deserialize_as_attribute(TYPE & value, xmlNodePtr element, const char* name)
        -> decltype(XmlAttributeAdapter<TYPE>::from_attribute(value, element, name), bool()) {
        return XmlAttributeAdapter<TYPE>::from_attribute(value, element, name);
    }

    // 对于不支持的类型，提供空实现（永远不会被调用，因为运行时检查会跳过）
    static bool deserialize_as_attribute(...) {
        // 不应该到达这里
        return false;
    }

    // 收集字段对应的元素名称和属性名称（用于第一阶段）
    // 注意：FieldStruct 可以是任意类型（用于继承场景）
    template<typename FieldStruct, typename FieldType>
    static void collect_field_names(const FieldDesc<FieldStruct, FieldType>& desc,
                                    std::set<std::string>& processed_names,
                                    std::set<std::string>& processed_attributes,
                                    bool& has_any_field) {
        // 处理属性字段
        if ((desc.type & serialize_type::attribute) == serialize_type::attribute) {
            // 跳过 anyAttribute（map<string, string> 或 optional<map<string, string>> 类型）
            if constexpr (!std::is_same_v<FieldType, std::map<std::string, std::string>> &&
                         !std::is_same_v<FieldType, std::optional<std::map<std::string, std::string>>>) {
                // 普通属性：记录属性名
                if (desc.name && desc.name[0] != '\0') {
                    processed_attributes.insert(desc.name);
                }
            }
            return;
        }

        // 检查是否为标准的 xs:any 字段（名为 "_any_"）
        if ((desc.type & serialize_type::any_element) == serialize_type::any_element) {
            if (desc.name && std::string(desc.name) == "_any_") {
                has_any_field = true;
            }
            // xs:any 字段不加入 processed_names（无论是否为 _any）
            return;
        }

        // 记录普通元素名称
        if (desc.name && desc.name[0] != '\0') {
            processed_names.insert(desc.name);
        }
    }

    // 收集未被处理的元素到 AnyElement
    template<typename FieldType>
    static void collect_unprocessed_elements(FieldType& value, xmlNodePtr element,
                                            const std::set<std::string>& processed_names,
                                            const std::map<std::string_view, std::string_view>& namespaces) {
        // 根据字段类型分别处理
        using ::libonvif_client::AnyElement;
        if constexpr (std::is_same_v<FieldType, AnyElement> ||
                      std::is_same_v<FieldType, std::optional<AnyElement>>) {
            // 单个 AnyElement：读取第一个未处理的子元素
            collect_single_any_element(value, element, processed_names, namespaces);
        } else if constexpr (std::is_same_v<FieldType, std::vector<AnyElement>>) {
            // AnyElement 集合：读取所有未处理的子元素
            collect_any_element_vector(value, element, processed_names, namespaces);
        }
    }

    // 收集单个未处理元素
    template<typename FieldType>
    static void collect_single_any_element(FieldType& value, xmlNodePtr element,
                                          const std::set<std::string>& processed_names,
                                          const std::map<std::string_view, std::string_view>& namespaces) {
        using ::libonvif_client::AnyElement;
        for (xmlNodePtr child = element->children; child; child = child->next) {
            if (child->type != XML_ELEMENT_NODE) continue;

            std::string child_name = reinterpret_cast<const char*>(child->name);
            if (processed_names.find(child_name) == processed_names.end()) {
                // 找到第一个未处理的元素
                AnyElement any_elem;
                if (XmlValueAdapter<AnyElement>::from_xml_val(
                        any_elem, child, nullptr, nullptr, namespaces)) {
                    if constexpr (std::is_same_v<FieldType, std::optional<AnyElement>>) {
                        value = std::move(any_elem);
                    } else {
                        value = std::move(any_elem);
                    }
                }
                return; // 只读取第一个
            }
        }
    }

    // 收集所有未处理元素
    static void collect_any_element_vector(std::vector<::libonvif_client::AnyElement>& value, xmlNodePtr element,
                                          const std::set<std::string>& processed_names,
                                          const std::map<std::string_view, std::string_view>& namespaces) {
        using ::libonvif_client::AnyElement;
        value.clear();
        for (xmlNodePtr child = element->children; child; child = child->next) {
            if (child->type != XML_ELEMENT_NODE) continue;

            std::string child_name = reinterpret_cast<const char*>(child->name);
            if (processed_names.find(child_name) == processed_names.end()) {
                // 未处理的元素，加入集合
                AnyElement any_elem;
                if (XmlValueAdapter<AnyElement>::from_xml_val(
                        any_elem, child, nullptr, nullptr, namespaces)) {
                    value.push_back(std::move(any_elem));
                }
            }
        }
    }
};

// 统一序列化入口
template<typename T>
bool to_xml_val(const T& val, xmlNodePtr parent, const char* name,
               const char* ns_prefix,
               const std::map<std::string_view, std::string_view>& namespaces) {
    if (!parent || !name) return false;

    if constexpr (IsXmlSerializable<T>) {
        return XmlConverter<remove_cvref_t<T>>::to_xml_val(val, parent, name, ns_prefix, namespaces);
    } else {
        return XmlValueAdapter<T>::to_xml_val(val, parent, name, ns_prefix, namespaces);
    }
}

// 统一反序列化入口
template<typename T>
bool from_xml_val(T& val, xmlNodePtr element, const char* name,
                 const char* ns_prefix,
                 const std::map<std::string_view, std::string_view>& namespaces) {
    if (!element) return false;

    if constexpr (IsXmlSerializable<T>) {
        return XmlConverter<remove_cvref_t<T>>::from_xml_val(val, element, name, ns_prefix, namespaces);
    } else {
        return XmlValueAdapter<T>::from_xml_val(val, element, name, ns_prefix, namespaces);
    }
}

// 便捷的序列化/反序列化函数
template<typename T>
std::string to_xml_string(const T& obj, const char* root_name, 
                         const std::map<std::string_view, std::string_view>& namespaces = {}) {
    if (!root_name) return "";
    
    xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
    if (!doc) return "";
    
    xmlNodePtr root = xmlNewNode(nullptr, BAD_CAST root_name);
    if (!root) {
        xmlFreeDoc(doc);
        return "";
    }
    xmlDocSetRootElement(doc, root);
    
    // 设置命名空间声明
    for (const auto& [prefix, uri] : namespaces) {
        xmlNewNs(root, BAD_CAST uri.data(), BAD_CAST prefix.data());
    }

    // 直接将obj的内容写入root，而不是创建子节点
    bool success = true;
    if constexpr (IsXmlSerializable<T>) {
        // 对于有 XmlTraits 的结构体，序列化其字段到根元素
        std::apply([&](const auto&... fields) {
            ((XmlConverter<T>::SerializeField(root, obj, fields, namespaces) || [&]{ success = false; return false; }()), ...);
        }, XmlTraits<T>::fields);
    } else {
        // 对于基础类型（string, int 等），将其作为根元素的文本内容
        if constexpr (std::is_same_v<T, std::string>) {
            xmlNodeSetContent(root, BAD_CAST obj.c_str());
        } else if constexpr (std::is_arithmetic_v<T>) {
            std::string str_val;
            if constexpr (std::is_same_v<T, bool>) {
                str_val = obj ? "true" : "false";
            } else if constexpr (std::is_floating_point_v<T>) {
                str_val = std::to_string(static_cast<double>(obj));
            } else if constexpr (std::is_unsigned_v<T>) {
                str_val = std::to_string(static_cast<uint64_t>(obj));
            } else {
                str_val = std::to_string(static_cast<int64_t>(obj));
            }
            xmlNodeSetContent(root, BAD_CAST str_val.c_str());
        } else {
            // 不支持的类型
            success = false;
        }
    }
    
    std::string result;
    if (success) {
        xmlChar* xml_buff;
        int buffer_size;
        xmlDocDumpFormatMemory(doc, &xml_buff, &buffer_size, 1);
        if (xml_buff) {
            result = reinterpret_cast<char*>(xml_buff);
            xmlFree(xml_buff);
        }
    }
    
    xmlFreeDoc(doc);
    return result;
}

template<typename T>
bool from_xml_string(T& obj, const std::string& xml_str,
                    const std::map<std::string_view, std::string_view>& namespaces = {}) {
    if (xml_str.empty()) return false;
    auto doc = std::shared_ptr<xmlDoc>(xmlReadMemory(xml_str.c_str(), xml_str.size(), nullptr, nullptr, XML_PARSE_NOWARNING | XML_PARSE_NOERROR), xmlFreeDoc);
    if (!doc) return false;

    xmlNodePtr root = xmlDocGetRootElement(doc.get());
    if (root) {
        return xml_convert::from_xml_val(obj, root, nullptr, nullptr, namespaces);
    }
    return false;
}

// ============================================================================
// 便捷函数 - 与 OnvifServiceBase 兼容
// ============================================================================


/**
 * @brief 从 XML 字符串反序列化对象（便捷版本）
 *
 * @tparam T 对象类型
 * @param xml_str XML 字符串
 * @return 反序列化的对象，失败时抛出异常
 */
template<typename T>
T from_xml(const std::string& xml_str) {
    if (xml_str.empty()) {
        throw std::runtime_error("Cannot parse empty XML string");
    }

    T obj{};
    if (!from_xml_string(obj, xml_str)) {
        std::string preview = xml_str.length() > 200 ?
            xml_str.substr(0, 200) + "..." : xml_str;
        throw std::runtime_error("Failed to parse XML: " + preview);
    }

    return obj;
}

} // namespace xml_convert

// 导入便捷函数到顶层命名空间
using xml_convert::from_xml;

} // namespace libonvif_client