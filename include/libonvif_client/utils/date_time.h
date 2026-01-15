/**
 * @file date_time.h
 * @brief 日期时间处理 - 独立实现，不依赖第三方库
 * @note 支持 ISO 8601 格式的日期时间解析和序列化
 */

#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

namespace libonvif_client {

/**
 * @brief 日期时间类
 * @note 支持 ISO 8601 格式：YYYY-MM-DDTHH:MM:SS[.sss][Z|(+|-)HH:MM]
 */
class DateTime {
public:
    /**
     * @brief 默认构造函数 - 当前时间
     */
    DateTime() : micros_since_epoch_(
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count()) {}

    /**
     * @brief 从微秒时间戳构造
     * @param micros_since_epoch 自 Unix Epoch 以来的微秒数
     */
    explicit DateTime(int64_t micros_since_epoch)
        : micros_since_epoch_(micros_since_epoch) {}

    /**
     * @brief 从字符串解析日期时间
     * @param date_time_str ISO 8601 格式的日期时间字符串
     * @return DateTime 对象
     * @throw std::invalid_argument 如果格式不正确
     */
    static DateTime fromString(const std::string& date_time_str) {
        // 支持格式：
        // YYYY-MM-DDTHH:MM:SS
        // YYYY-MM-DDTHH:MM:SS.sss
        // YYYY-MM-DDTHH:MM:SSZ
        // YYYY-MM-DDTHH:MM:SS+HH:MM
        // YYYY/MM/DD HH:MM:SS (宽松格式)

        std::string str = date_time_str;

        // 替换 'T' 为空格以便解析
        size_t t_pos = str.find('T');
        if (t_pos != std::string::npos) {
            str[t_pos] = ' ';
        }

        // 解析时区偏移
        int tz_offset_minutes = 0;
        size_t z_pos = str.find('Z');
        if (z_pos != std::string::npos) {
            str = str.substr(0, z_pos); // 移除 'Z'
        } else {
            // 查找 +/- 时区偏移
            size_t plus_pos = str.find('+', 10); // 从第10个字符开始查找（跳过日期部分）
            size_t minus_pos = str.find('-', 10);
            size_t tz_pos = (plus_pos != std::string::npos) ? plus_pos : minus_pos;

            if (tz_pos != std::string::npos) {
                std::string tz_str = str.substr(tz_pos);
                str = str.substr(0, tz_pos);

                // 解析时区偏移 (+|-)HH:MM
                int tz_hours = 0, tz_mins = 0;
                char sign = tz_str[0];
                if (sscanf(tz_str.c_str() + 1, "%d:%d", &tz_hours, &tz_mins) >= 1) {
                    tz_offset_minutes = tz_hours * 60 + tz_mins;
                    if (sign == '-') {
                        tz_offset_minutes = -tz_offset_minutes;
                    }
                }
            }
        }

        // 解析日期和时间
        std::tm tm = {};
        int microseconds = 0;

        // 尝试解析微秒
        size_t dot_pos = str.find('.');
        if (dot_pos != std::string::npos) {
            std::string micros_str = str.substr(dot_pos + 1);
            str = str.substr(0, dot_pos);

            // 补齐或截断到6位
            while (micros_str.length() < 6) micros_str += "0";
            if (micros_str.length() > 6) micros_str = micros_str.substr(0, 6);

            microseconds = std::stoi(micros_str);
        }

        // 解析日期时间 (YYYY-MM-DD HH:MM:SS 或 YYYY/MM/DD HH:MM:SS)
        if (sscanf(str.c_str(), "%d-%d-%d %d:%d:%d",
                   &tm.tm_year, &tm.tm_mon, &tm.tm_mday,
                   &tm.tm_hour, &tm.tm_min, &tm.tm_sec) == 6 ||
            sscanf(str.c_str(), "%d/%d/%d %d:%d:%d",
                   &tm.tm_year, &tm.tm_mon, &tm.tm_mday,
                   &tm.tm_hour, &tm.tm_min, &tm.tm_sec) == 6) {

            tm.tm_year -= 1900; // tm_year 是从 1900 年开始
            tm.tm_mon -= 1;     // tm_mon 是 0-11
            tm.tm_isdst = -1;   // 让系统决定是否是夏令时

            // 转换为 time_t (本地时间)
            std::time_t time = std::mktime(&tm);

            // 转换为 UTC 时间（考虑时区偏移）
            time -= tz_offset_minutes * 60;

            // 转换为微秒
            int64_t micros = static_cast<int64_t>(time) * 1000000LL + microseconds;

            return DateTime(micros);
        }

        throw std::invalid_argument("Invalid date-time format: " + date_time_str);
    }

    /**
     * @brief 转换为 ISO 8601 字符串 (UTC)
     * @return ISO 8601 格式的字符串
     */
    std::string toISOString() const {
        return toIOS8601String();
    }

    /**
     * @brief 转换为 ISO 8601 字符串 (UTC)
     * @return ISO 8601 格式的字符串
     */
    std::string toIOS8601String() const {
        std::time_t seconds = micros_since_epoch_ / 1000000;
        int64_t micros = micros_since_epoch_ % 1000000;

        std::tm tm;
#ifdef _WIN32
        gmtime_s(&tm, &seconds);
#else
        gmtime_r(&seconds, &tm);
#endif

        std::ostringstream oss;
        oss << std::setfill('0')
            << std::setw(4) << (tm.tm_year + 1900) << "-"
            << std::setw(2) << (tm.tm_mon + 1) << "-"
            << std::setw(2) << tm.tm_mday << "T"
            << std::setw(2) << tm.tm_hour << ":"
            << std::setw(2) << tm.tm_min << ":"
            << std::setw(2) << tm.tm_sec;

        if (micros > 0) {
            oss << "." << std::setw(6) << micros;
        }

        oss << "Z"; // UTC 时区

        return oss.str();
    }

    /**
     * @brief 获取自 Unix Epoch 以来的微秒数
     * @return 微秒时间戳
     */
    int64_t microSecondsSinceEpoch() const {
        return micros_since_epoch_;
    }

    /**
     * @brief 获取自 Unix Epoch 以来的秒数
     * @return 秒时间戳
     */
    int64_t secondsSinceEpoch() const {
        return micros_since_epoch_ / 1000000;
    }

private:
    int64_t micros_since_epoch_; ///< 自 Unix Epoch 以来的微秒数
};

} // namespace libonvif_client
