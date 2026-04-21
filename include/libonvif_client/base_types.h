/**
 * @file base_types.h
 * @brief ONVIF 基础类型定义
 * @note 此文件定义了 ONVIF/XML Schema 基础类型到 C++ 类型的映射
 */

#pragma once

#include <chrono>
#include <cstdint>
#include <iomanip>
#include <map>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>

#include "utils/date_time.h"
#include "utils/logger.h"
#include "xml_convert.h"

namespace libonvif_client {

// XSD 二进制类型
struct my_Base64Binary {
    // todo: 可以考虑使用 std::vector<uint8_t> 来存储二进制数据, 暂时简化处理为 std::string
    std::string value;
};
template<>
struct xml_convert::XmlValueAdapter<my_Base64Binary> {
    static bool to_xml_val(const my_Base64Binary& val, xmlNodePtr parent, const char* name,
                          const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        return xml_convert::to_xml_val(val.value, parent, name, ns_prefix, namespaces);
    }
    static bool from_xml_val(my_Base64Binary& val, xmlNodePtr element, const char* name = nullptr, const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        return xml_convert::from_xml_val(val.value, element, name);
    }
};

struct my_HexBinary {
    // todo: 可以考虑使用 std::vector<uint8_t> 来存储二进制数据, 暂时简化处理为 std::string
    std::string value;

    friend std::ostream& operator<<(std::ostream& os, const my_HexBinary& hex) {
        os << hex.value;
        return os;
    }
};
template<>
struct xml_convert::XmlValueAdapter<my_HexBinary> {
    static bool to_xml_val(const my_HexBinary& val, xmlNodePtr parent, const char* name,
                          const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        return xml_convert::to_xml_val(val.value, parent, name, ns_prefix, namespaces);
    }
    static bool from_xml_val(my_HexBinary& val, xmlNodePtr element, const char* name = nullptr, const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        return xml_convert::from_xml_val(val.value, element, name);
    }
};

// ==================== DateTime 类型 ====================

/**
 * @brief 时间间隔类型，单位为秒
 */
class my_Duration {
public:
    my_Duration() = default;
    explicit my_Duration(std::chrono::seconds seconds) : seconds_(seconds) {}

    static my_Duration form_string(const std::string& durationStr) {
        size_t pos = 0;
        bool negative = false;
        if (durationStr.empty()) {
            // throw std::invalid_argument("Empty duration");
            return my_Duration(std::chrono::seconds(0));
        }

        // 处理负号
        if (durationStr[0] == '-') {
            negative = true;
            pos = 1;
        }

        // 验证P前缀
        if (pos >= durationStr.size() || durationStr[pos] != 'P') {
            throw std::invalid_argument("Missing 'P' in duration");
            return my_Duration(std::chrono::seconds(0));
        }


        pos++;
        std::chrono::seconds total(0);

        // 解析日期部分
        pos = parseComponent(durationStr, pos, 'Y', total, 31536000); // 年→秒(365天)
        pos = parseComponent(durationStr, pos, 'M', total, 2592000);  // 月→秒(30天)
        pos = parseComponent(durationStr, pos, 'D', total, 86400);    // 天→秒

        // 解析时间部分
        if (pos < durationStr.size() && durationStr[pos] == 'T') {
            pos++;
            pos = parseComponent(durationStr, pos, 'H', total, 3600);   // 小时
            pos = parseComponent(durationStr, pos, 'M', total, 60);     // 分钟
            pos = parseComponent(durationStr, pos, 'S', total, 1);      // 秒
        }
        // 忽略
        // if (pos != durationStr.size())
        //     throw std::invalid_argument("Invalid duration format");

        return my_Duration(negative ? -total : total);
    }

    [[nodiscard]] std::string to_string() const {
        std::string result;
        auto sec = seconds_.count();
        bool negative = sec < 0;
        if (negative) sec = -sec;

        result += 'P';

        // 处理年/月/日
        auto years = sec / 31536000;
        sec %= 31536000;
        if (years > 0) result += std::to_string(years) + 'Y';

        auto months = sec / 2592000;
        sec %= 2592000;
        if (months > 0) result += std::to_string(months) + 'M';

        auto days = sec / 86400;
        sec %= 86400;
        if (days > 0) result += std::to_string(days) + 'D';

        // 处理时间部分
        if (sec > 0) {
            result += 'T';
            auto hours = sec / 3600;
            sec %= 3600;
            if (hours > 0) result += std::to_string(hours) + 'H';

            auto minutes = sec / 60;
            sec %= 60;
            if (minutes > 0) result += std::to_string(minutes) + 'M';

            if (sec > 0) result += std::to_string(sec) + 'S';
        } else if (result.size() == 1) { // 只有P的情况
            result += "T0S";
        }

        if (negative) result.insert(0, 1, '-');
        return result;
    }

    [[nodiscard]] std::chrono::seconds duration() const { return seconds_; }
private:
    static size_t parseComponent(const std::string& str, size_t pos, char unit,
                               std::chrono::seconds& total, int multiplier) {
        const size_t start = pos;
        while (pos < str.size() && isdigit(str[pos])) pos++;

        if (start != pos && pos < str.size() && str[pos] == unit) {
            int value = std::stoi(str.substr(start, pos - start));
            total += std::chrono::seconds(value * multiplier);
            return pos + 1;
        }
        // Digits don't belong to this unit — leave them for the next component
        return start;
    }
    std::chrono::seconds seconds_{0};
};
template<>
struct libonvif_client::xml_convert::XmlValueAdapter<my_Duration> {
    static bool from_xml_val(my_Duration& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        std::string str_val;
        if (!xml_convert::from_xml_val(str_val, element, name, ns_prefix, namespaces)) {
            return false;
        }
        try {
            val = my_Duration::form_string(str_val);
            return true;
        } catch (const std::exception& e) {
            ONVIF_LOG_ERROR << "Failed to parse my_Duration from XML: " << e.what();
        }
        return false;
    }
    static bool to_xml_val(const my_Duration& val, xmlNodePtr parent, const char* name,
                          const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        return xml_convert::to_xml_val(val.to_string(), parent, name, ns_prefix, namespaces);
    }
};

class my_TimePart {
public:
    my_TimePart() = default;
    explicit my_TimePart(std::chrono::microseconds micro_sec) : micro_sec_(micro_sec) {}
    static my_TimePart from_string(const std::string& timeStr) {
        // 解析时间字符串 HH:MM:SS[.sss]
        int hours = 0, minutes = 0, seconds = 0, microseconds = 0;

        // 查找小数点
        size_t dot_pos = timeStr.find('.');
        std::string time_part = (dot_pos != std::string::npos) ? timeStr.substr(0, dot_pos) : timeStr;
        std::string micros_part = (dot_pos != std::string::npos) ? timeStr.substr(dot_pos + 1) : "";

        // 解析时分秒
        if (sscanf(time_part.c_str(), "%d:%d:%d", &hours, &minutes, &seconds) < 2) {
            // throw std::invalid_argument("Invalid time format: " + timeStr);
            return my_TimePart(std::chrono::microseconds(0));
        }

        // 解析微秒
        if (!micros_part.empty()) {
            // 补齐或截断到6位
            while (micros_part.length() < 6) micros_part += "0";
            if (micros_part.length() > 6) micros_part = micros_part.substr(0, 6);
            microseconds = std::stoi(micros_part);
        }

        // 转换为总微秒数
        int64_t total_micros = static_cast<int64_t>(hours) * 3600 * 1000000
                             + static_cast<int64_t>(minutes) * 60 * 1000000
                             + static_cast<int64_t>(seconds) * 1000000
                             + microseconds;

        return my_TimePart(std::chrono::microseconds(total_micros));
    }
    [[nodiscard]] std::string to_string() const {
        auto total_sec = std::chrono::duration_cast<std::chrono::seconds>(micro_sec_);
        auto remaining_micro = micro_sec_ - total_sec;

        std::stringstream ss;
        ss << std::setfill('0')
           << std::setw(2) << (total_sec.count() / 3600) % 24 << ":"
           << std::setw(2) << (total_sec.count() / 60) % 60 << ":"
           << std::setw(2) << total_sec.count() % 60;

        if (remaining_micro.count() > 0) {
            ss << "." << std::setw(3) << std::setfill('0') << remaining_micro.count() / 1000;
        }
        return ss.str();
    }
    [[nodiscard]] std::chrono::microseconds microSeconds() const { return micro_sec_; }

private:
    std::chrono::microseconds micro_sec_{};
};

template<>
struct libonvif_client::xml_convert::XmlValueAdapter<my_TimePart> {
    static bool from_xml_val(my_TimePart& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        std::string str_val;
        if (!xml_convert::from_xml_val(str_val, element, name, ns_prefix, namespaces)) {
            return false;
        }
        try {
            val = my_TimePart::from_string(str_val);
            return true;
        } catch (const std::exception& e) {
            ONVIF_LOG_ERROR << "Failed to parse my_TimePart from XML: " << e.what();
        }
        return false;
    }
    static bool to_xml_val(const my_TimePart& val, xmlNodePtr parent, const char* name,
                          const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        return xml_convert::to_xml_val(val.to_string(), parent, name, ns_prefix, namespaces);
    }
};

// DateTime 已在 date_time.h 中定义，这里直接使用
// 无需重新定义

template<>
struct libonvif_client::xml_convert::XmlValueAdapter<DateTime> {
    static bool from_xml_val(DateTime& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        std::string str_val;
        if (!xml_convert::from_xml_val(str_val, element, name, ns_prefix, namespaces)) {
            return false;
        }
        try {
            val = DateTime(DateTime::fromString(str_val).microSecondsSinceEpoch());
            return true;
        } catch (const std::exception& e) {
            ONVIF_LOG_ERROR << "Failed to parse DateTime from XML: " << e.what();
        }
        return false;
    }
    static bool to_xml_val(const DateTime& val, xmlNodePtr parent, const char* name,
                          const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        return xml_convert::to_xml_val(val.toIOS8601String(), parent, name, ns_prefix, namespaces);
    }
};

// AnyElement 的 XML 适配器特化

} // namespace libonvif_client