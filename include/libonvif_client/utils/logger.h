/**
 * @file logger.h
 * @brief 日志系统 - 基于回调的轻量级日志
 * @note 用户可以设置日志回调来处理日志输出，如果未设置则静默处理
 */

#pragma once

#include <functional>
#include <sstream>
#include <string>
#include <utility>

namespace libonvif_client {

/**
 * @brief 日志级别
 */
enum class LogLevel {
    Trace = 0,
    Debug,
    Info, Warn,
    Error
};

/**
 * @brief 日志回调函数类型
 * @param level 日志级别
 * @param file 源文件名
 * @param line 行号
 * @param function 函数名
 * @param message 日志消息
 */
using LogCallback = std::function<void(LogLevel level, const char* file, int line, const char* function, const std::string& message)>;

/**
 * @brief 日志管理器
 */
class Logger {
public:
    /**
     * @brief 设置日志回调函数
     * @param callback 日志回调，如果为空则静默处理
     */
    static void set_log_callback(LogCallback callback) {
        get_callback() = std::move(callback);
    }

    /**
     * @brief 获取日志回调函数
     * @return 日志回调函数引用
     */
    static LogCallback& get_callback() {
        static LogCallback callback = nullptr;
        return callback;
    }

    /**
     * @brief 输出日志
     * @param level 日志级别
     * @param file 源文件名
     * @param line 行号
     * @param function 函数名
     * @param message 日志消息
     */
    static void log(LogLevel level, const char* file, int line, const char* function, const std::string& message) {
        if (auto &callback = get_callback()) {
            callback(level, file, line, function, message);
        }
    }
};

/**
 * @brief 日志流辅助类
 */
class LogStream {
public:
    LogStream(LogLevel level, const char* file, int line, const char* function)
        : level_(level), file_(file), line_(line), function_(function) {}

    ~LogStream() {
        Logger::log(level_, file_, line_, function_, stream_.str());
    }

    template<typename T>
    LogStream& operator<<(const T& value) {
        stream_ << value;
        return *this;
    }

    // 支持流操作符（如 std::endl）
    LogStream& operator<<(std::ostream& (*manipulator)(std::ostream&)) {
        manipulator(stream_);
        return *this;
    }

private:
    LogLevel level_;
    const char* file_;
    int line_;
    const char* function_;
    std::ostringstream stream_;
};

} // namespace libonvif_client

// 日志宏定义
#define ONVIF_LOG_TRACE ::libonvif_client::LogStream(::libonvif_client::LogLevel::Trace, __FILE__, __LINE__, __FUNCTION__)
#define ONVIF_LOG_DEBUG ::libonvif_client::LogStream(::libonvif_client::LogLevel::Debug, __FILE__, __LINE__, __FUNCTION__)
#define ONVIF_LOG_INFO  ::libonvif_client::LogStream(::libonvif_client::LogLevel::Info, __FILE__, __LINE__, __FUNCTION__)
#define ONVIF_LOG_WARN  ::libonvif_client::LogStream(::libonvif_client::LogLevel::Warn, __FILE__, __LINE__, __FUNCTION__)
#define ONVIF_LOG_ERROR ::libonvif_client::LogStream(::libonvif_client::LogLevel::Error, __FILE__, __LINE__, __FUNCTION__)
