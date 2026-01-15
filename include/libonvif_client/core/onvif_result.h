/**
 * @file onvif_result.h
 * @brief ONVIF操作结果统一封装
 * @note 零拷贝设计 + 保留XML上下文 + 统一错误处理
 */

#pragma once

#include <libxml/tree.h>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace libonvif_client {


/**
 * @brief SOAP Fault 零拷贝结构
 *
 * 设计原则：
 * - 使用 string_view 零拷贝引用 XML 节点内容
 * - XML 文档生命周期由 shared_ptr<xmlDoc> 管理
 * - 对于非 XML 错误（HTTP/客户端错误），使用 owned_strings 拥有所有权
 * - 延迟构建完整错误消息（仅在需要时格式化）
 */
struct SoapFault {
    std::string_view code;      ///< Fault Code（零拷贝，指向XML节点或owned_strings）
    std::string_view subcode;   ///< Fault Subcode（零拷贝）
    std::string_view reason;    ///< Fault Reason（零拷贝）
    xmlNodePtr detail_node;     ///< Fault Detail节点（供自定义解析，可为nullptr）

    /**
     * @brief 拥有所有权的字符串存储（用于非XML错误）
     * @note 仅在 HTTP 错误、超时、客户端错误时使用
     */
    std::vector<std::string> owned_strings;

    /**
     * @brief 默认构造函数
     */
    SoapFault() : detail_node(nullptr) {}

    /**
     * @brief 设置拥有所有权的错误信息（用于非XML错误）
     * @param code_str 错误代码
     * @param reason_str 错误原因
     * @param subcode_str 子代码（可选）
     */
    void set_owned_error(std::string code_str,
                        std::string reason_str,
                        std::string subcode_str = "") {
        owned_strings.clear();
        owned_strings.reserve(3);

        owned_strings.push_back(std::move(code_str));
        owned_strings.push_back(std::move(reason_str));

        code = owned_strings[0];
        reason = owned_strings[1];

        if (!subcode_str.empty()) {
            owned_strings.push_back(std::move(subcode_str));
            subcode = owned_strings[2];
        } else {
            subcode = "";
        }

        detail_node = nullptr;
    }

    /**
     * @brief 设置零拷贝错误信息（用于XML错误）
     * @param code_view 错误代码（string_view，指向XML节点）
     * @param reason_view 错误原因（string_view，指向XML节点）
     * @param subcode_view 子代码（可选）
     * @param detail_node_ptr Detail节点指针（可选）
     */
    void set_xml_error(std::string_view code_view,
                      std::string_view reason_view,
                      std::string_view subcode_view = "",
                      xmlNodePtr detail_node_ptr = nullptr) {
        code = code_view;
        reason = reason_view;
        subcode = subcode_view;
        detail_node = detail_node_ptr;
        owned_strings.clear();
    }

    /**
     * @brief 获取格式化的错误消息（延迟构建）
     * @return 完整的错误描述字符串
     */
    [[nodiscard]] std::string to_string() const {
        // 预分配空间：2方括号 + 空格 + code + subcode分隔符 + reason
        size_t reserve_size = 3 + code.size() + reason.size();
        if (!subcode.empty()) {
            reserve_size += 1 + subcode.size();  // "/" + subcode
        }
        std::string msg;
        msg.reserve(reserve_size);

        msg += '[';
        msg += code;
        if (!subcode.empty()) {
            msg += '/';
            msg += subcode;
        }
        msg += "] ";
        msg += reason;

        return msg;
    }
};

/**
 * @brief OnvifResult 基类（包含公共成员和方法）
 *
 * @tparam Derived 派生类类型（用于CRTP）
 *
 * 设计原则：
 * - 提取 OnvifResult<T> 和 OnvifResult<void> 的公共代码
 * - 使用 CRTP 避免虚函数开销
 */
template<typename Derived>
class OnvifResultBase {
public:
    // === 错误信息（统一为 SoapFault）===
    std::unique_ptr<SoapFault> soap_fault;      ///< 错误信息（失败时非空）

    // === XML 上下文（始终保留）===
    std::shared_ptr<xmlDoc> xml_doc;            ///< 原始XML文档（保持生命周期）
    xmlNodePtr response_node;                   ///< 响应/错误节点指针（可为nullptr）

    /**
     * @brief 默认构造函数
     */
    OnvifResultBase() : response_node(nullptr) {}

    /**
     * @brief 禁止拷贝
     */
    OnvifResultBase(const OnvifResultBase&) = delete;
    OnvifResultBase& operator=(const OnvifResultBase&) = delete;

    /**
     * @brief 允许移动
     */
    OnvifResultBase(OnvifResultBase&&) noexcept = default;
    OnvifResultBase& operator=(OnvifResultBase&&) noexcept = default;

    /**
     * @brief 获取错误消息（仅在失败时调用）
     * @return 格式化的错误描述，成功时返回空字符串
     */
    [[nodiscard]] std::string get_error_message() const {
        if (soap_fault) {
            return soap_fault->to_string();
        }
        return "";
    }

    /**
     * @brief 获取原始XML字符串（调试用）
     * @return XML 文档的字符串表示，无 XML 文档时返回空字符串
     * @note 此方法会分配内存，仅在调试时使用
     */
    [[nodiscard]] std::string get_raw_xml() const {
        if (!xml_doc) return "";

        xmlChar* xml_buf = nullptr;
        int buf_size = 0;
        xmlDocDumpMemory(xml_doc.get(), &xml_buf, &buf_size);

        if (!xml_buf) return "";

        std::string result(reinterpret_cast<char*>(xml_buf), buf_size);
        xmlFree(xml_buf);
        return result;
    }

protected:
    ~OnvifResultBase() = default;
};

/**
 * @brief ONVIF操作结果（统一成功/失败封装）
 *
 * @tparam T 响应数据类型
 *
 * 设计哲学：
 * 1. 成功时：data 非空，soap_fault 为空
 * 2. 失败时：data 为空，soap_fault 非空（包含所有错误类型）
 * 3. XML文档始终保留（调试/自定义解析）
 * 4. 使用 move 语义传递，避免拷贝
 */
template<typename T>
struct OnvifResult : public OnvifResultBase<OnvifResult<T>> {
    using Base = OnvifResultBase<OnvifResult<T>>;

    // === 成功数据 ===
    std::unique_ptr<T> data;                    ///< 解析后的响应数据（成功时非空）

    // 继承基类成员
    using Base::soap_fault;
    using Base::xml_doc;
    using Base::response_node;
    using Base::get_error_message;
    using Base::get_raw_xml;

    /**
     * @brief 默认构造函数
     */
    OnvifResult() = default;

    /**
     * @brief 禁止拷贝
     */
    OnvifResult(const OnvifResult&) = delete;
    OnvifResult& operator=(const OnvifResult&) = delete;

    /**
     * @brief 允许移动
     */
    OnvifResult(OnvifResult&&) noexcept = default;
    OnvifResult& operator=(OnvifResult&&) noexcept = default;

    // === 状态判断 ===

    /**
     * @brief 检查操作是否成功
     * @return true 表示成功，data 非空
     */
    [[nodiscard]] bool is_success() const {
        return data != nullptr;
    }
    /**
     * @brief 检查操作是否成功
     */
    [[nodiscard]] operator bool() const {
        return is_success();
    }

    /**
     * @brief 检查操作是否失败
     * @return true 表示失败，soap_fault 非空
     */
    [[nodiscard]] bool is_error() const {
        return soap_fault != nullptr;
    }
};

/**
 * @brief OnvifResult 的 void 特化（用于无返回数据的操作）
 *
 * 用于只需要知道操作成功或失败的 ONVIF 操作（如 Notify）。
 */
template<>
struct OnvifResult<void> : public OnvifResultBase<OnvifResult<void>> {
    using Base = OnvifResultBase<OnvifResult<void>>;

    // 继承基类成员
    using Base::soap_fault;
    using Base::xml_doc;
    using Base::response_node;
    using Base::get_error_message;
    using Base::get_raw_xml;

    /**
     * @brief 默认构造函数
     */
    OnvifResult() = default;

    /**
     * @brief 禁止拷贝
     */
    OnvifResult(const OnvifResult&) = delete;
    OnvifResult& operator=(const OnvifResult&) = delete;

    /**
     * @brief 允许移动
     */
    OnvifResult(OnvifResult&&) noexcept = default;
    OnvifResult& operator=(OnvifResult&&) noexcept = default;

    // === 状态判断 ===

    /**
     * @brief 检查操作是否成功
     * @return true 表示成功（无错误）
     */
    [[nodiscard]] bool is_success() const {
        return soap_fault == nullptr;
    }

    /**
     * @brief 检查操作是否成功
     */
    [[nodiscard]] operator bool() const {
        return is_success();
    }

    /**
     * @brief 检查操作是否失败
     * @return true 表示失败，soap_fault 非空
     */
    [[nodiscard]] bool is_error() const {
        return soap_fault != nullptr;
    }
};

} // namespace libonvif_client
