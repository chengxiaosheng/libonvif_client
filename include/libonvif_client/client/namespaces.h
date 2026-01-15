/**
 * @file namespaces.h
 * @brief ONVIF 全局命名空间映射（header-only）
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

#include <string_view>
#include <array>

namespace libonvif_client {

/**
 * @brief 命名空间对
 */
struct namespace_pair {
    constexpr namespace_pair(const char* p, const char* u)
        : prefix(p), uri(u) {}
    const char* prefix;   // 命名空间前缀
    const char* uri;      // 命名空间 URI
};

/**
 * @brief 所有命名空间映射
 */
inline constexpr std::array<namespace_pair, 25> g_namespace_mappings = {{
    namespace_pair{"bd", "http://www.onvif.org/ver20/analytics/humanbody"},
    namespace_pair{"fc", "http://www.onvif.org/ver20/analytics/humanface"},
    namespace_pair{"soap", "http://www.w3.org/2003/05/soap-envelope"},
    namespace_pair{"tad", "http://www.onvif.org/ver10/analyticsdevice/wsdl"},
    namespace_pair{"tan", "http://www.onvif.org/ver20/analytics/wsdl"},
    namespace_pair{"tds", "http://www.onvif.org/ver10/device/wsdl"},
    namespace_pair{"tev", "http://www.onvif.org/ver10/events/wsdl"},
    namespace_pair{"timg", "http://www.onvif.org/ver20/imaging/wsdl"},
    namespace_pair{"tptz", "http://www.onvif.org/ver20/ptz/wsdl"},
    namespace_pair{"tr2", "http://www.onvif.org/ver20/media/wsdl"},
    namespace_pair{"trc", "http://www.onvif.org/ver10/recording/wsdl"},
    namespace_pair{"trp", "http://www.onvif.org/ver10/replay/wsdl"},
    namespace_pair{"trt", "http://www.onvif.org/ver10/media/wsdl"},
    namespace_pair{"tse", "http://www.onvif.org/ver10/search/wsdl"},
    namespace_pair{"tt", "http://www.onvif.org/ver10/schema"},
    namespace_pair{"wsa", "http://www.w3.org/2005/08/addressing"},
    namespace_pair{"wsnt", "http://docs.oasis-open.org/wsn/b-2"},
    namespace_pair{"wsntw", "http://docs.oasis-open.org/wsn/bw-2"},
    namespace_pair{"wsrf-r", "http://docs.oasis-open.org/wsrf/r-2"},
    namespace_pair{"wsrf-rw", "http://docs.oasis-open.org/wsrf/rw-2"},
    namespace_pair{"wsrf_bf", "http://docs.oasis-open.org/wsrf/bf-2"},
    namespace_pair{"wstop", "http://docs.oasis-open.org/wsn/t-1"},
    namespace_pair{"xmime", "http://www.w3.org/2005/05/xmlmime"},
    namespace_pair{"xop", "http://www.w3.org/2004/08/xop/include"},
    namespace_pair{"xs", "http://www.w3.org/XML/1998/namespace"},
}};

/**
 * @brief 根据 URI 查找命名空间前缀
 * @param uri 命名空间 URI
 * @return 命名空间前缀，未找到返回 nullptr
 */
[[nodiscard]]
constexpr const char* find_namespace_prefix(const std::string_view& uri) noexcept {
    for (const auto& [prefix, u] : g_namespace_mappings) {
        if (uri == u) return prefix;
    }
    return nullptr;
}

/**
 * @brief 根据前缀查找命名空间 URI
 * @param prefix 命名空间前缀
 * @return 命名空间 URI，未找到返回 nullptr
 */
[[nodiscard]]
constexpr const char* find_namespace_uri(const std::string_view& prefix) noexcept {
    for (const auto& [p, uri] : g_namespace_mappings) {
        if (prefix == p) return uri;
    }
    return nullptr;
}

} // namespace libonvif_client
