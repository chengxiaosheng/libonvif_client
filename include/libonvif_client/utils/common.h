/**
 * @file common.h
 * @brief ONVIF客户端公共工具函数（header-only）
 * @note 提供WS-Security、时间戳、随机数等通用功能
 */

#pragma once

#include <algorithm>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include "libonvif_client/client/namespaces.h"

namespace libonvif_client {

// SOAP 命名空间常量
inline constexpr std::string_view soap_envelope_namespace = "http://www.w3.org/2003/05/soap-envelope";
inline constexpr std::string_view soap_wsa_namespace = "http://www.w3.org/2005/08/addressing";
inline constexpr std::string_view soap_wsse_namespace = "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd";
inline constexpr std::string_view soap_wsu_namespace = "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd";


inline const char* find_ns_prefix(const std::string& namespace_uri) {
    // 首先查找 ONVIF 命名空间
    if (auto data = find_namespace_prefix(namespace_uri)) {
        return data;
    }

    // 默认 SOAP 命名空间映射
    static const std::map<std::string_view, std::string_view> default_namespace = {
        {"soap", soap_envelope_namespace},
        {"wsa", soap_wsa_namespace},
        {"wsse", soap_wsse_namespace},
        {"wsu", soap_wsu_namespace},
    };

    auto it = std::find_if(default_namespace.begin(), default_namespace.end(),
        [&](const std::pair<std::string_view, std::string_view>& item) {
            return item.second == namespace_uri;
        });
    if (it != default_namespace.end()) {
        return it->first.data();
    }
    return nullptr;
}

// ============================================================================
// WS-Security 相关工具函数
// ============================================================================
    namespace crypto {
    std::string base64_encode(const std::string& input);
    std::string base64_decode(const std::string& input);
    std::string compute_ws_security_digest(const std::string& nonce_base64,
                                           const std::string& created,
                                           const std::string& password);
}

/**
 * @brief 生成WS-Security Nonce（随机数）
 */
inline std::string generate_nonce() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint8_t> dis(0, 255);

    std::string nonce_bytes;
    nonce_bytes.reserve(16);
    for (int i = 0; i < 16; ++i) {
        nonce_bytes.push_back(static_cast<char>(dis(gen)));
    }
    return crypto::base64_encode(nonce_bytes);
}

/**
 * @brief 获取当前UTC时间戳
 */
inline std::string get_current_timestamp() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    std::ostringstream oss;
    oss << std::put_time(std::gmtime(&time_t), "%Y-%m-%dT%H:%M:%S");
    oss << "." << std::setfill('0') << std::setw(3) << ms.count() << "Z";
    return oss.str();
}

/**
 * @brief 计算WS-Security密码摘要
 */
inline std::string compute_password_digest(const std::string& nonce,
                                          const std::string& created,
                                          const std::string& password) {
    return crypto::compute_ws_security_digest(nonce, created, password);
}

// ============================================================================
// 加密工具函数命名空间
// ============================================================================

namespace crypto {

/**
 * @brief SHA1哈希实现类
 */
class SHA1 {
public:
    SHA1() { reset(); }

    void reset() {
        length_low_ = 0;
        length_high_ = 0;
        message_block_index_ = 0;
        h_[0] = 0x67452301;
        h_[1] = 0xEFCDAB89;
        h_[2] = 0x98BADCFE;
        h_[3] = 0x10325476;
        h_[4] = 0xC3D2E1F0;
        computed_ = false;
    }

    void input(const uint8_t* bytes, size_t byte_count) {
        if (byte_count == 0) return;
        if (computed_) reset();

        while (byte_count-- && !computed_) {
            message_block_[message_block_index_++] = *bytes++;
            length_low_ += 8;
            if (length_low_ == 0) {
                length_high_++;
                if (length_high_ == 0) computed_ = true;
            }
            if (message_block_index_ == 64) {
                process_message_block();
            }
        }
    }

    void input(const std::string& str) {
        input(reinterpret_cast<const uint8_t*>(str.c_str()), str.length());
    }

    std::vector<uint8_t> result() {
        if (!computed_) {
            pad_message();
            std::memset(message_block_, 0, sizeof(message_block_));
            length_low_ = 0;
            length_high_ = 0;
            computed_ = true;
        }

        std::vector<uint8_t> digest(20);
        for (int i = 0; i < 20; ++i) {
            digest[i] = h_[i >> 2] >> 8 * (3 - (i & 0x03));
        }
        return digest;
    }

private:
    void process_message_block() {
        const uint32_t K[] = {
            0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6
        };
        uint32_t W[80];

        for (int t = 0; t < 16; t++) {
            W[t] = message_block_[t * 4] << 24;
            W[t] |= message_block_[t * 4 + 1] << 16;
            W[t] |= message_block_[t * 4 + 2] << 8;
            W[t] |= message_block_[t * 4 + 3];
        }

        for (int t = 16; t < 80; t++) {
            W[t] = circular_shift(1, W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16]);
        }

        uint32_t A = h_[0], B = h_[1], C = h_[2], D = h_[3], E = h_[4];

        for (int t = 0; t < 80; t++) {
            uint32_t temp = circular_shift(5, A) +
                          ((t < 20) ? ((B & C) | ((~B) & D)) :
                           (t < 40) ? (B ^ C ^ D) :
                           (t < 60) ? ((B & C) | (B & D) | (C & D)) :
                                      (B ^ C ^ D)) +
                          E + W[t] + K[t/20];
            E = D; D = C;
            C = circular_shift(30, B);
            B = A; A = temp;
        }

        h_[0] += A; h_[1] += B; h_[2] += C; h_[3] += D; h_[4] += E;
        message_block_index_ = 0;
    }

    void pad_message() {
        if (message_block_index_ > 55) {
            message_block_[message_block_index_++] = 0x80;
            while (message_block_index_ < 64) {
                message_block_[message_block_index_++] = 0;
            }
            process_message_block();
            while (message_block_index_ < 56) {
                message_block_[message_block_index_++] = 0;
            }
        } else {
            message_block_[message_block_index_++] = 0x80;
            while (message_block_index_ < 56) {
                message_block_[message_block_index_++] = 0;
            }
        }

        message_block_[56] = length_high_ >> 24;
        message_block_[57] = length_high_ >> 16;
        message_block_[58] = length_high_ >> 8;
        message_block_[59] = length_high_;
        message_block_[60] = length_low_ >> 24;
        message_block_[61] = length_low_ >> 16;
        message_block_[62] = length_low_ >> 8;
        message_block_[63] = length_low_;

        process_message_block();
    }

    static uint32_t circular_shift(int bits, uint32_t word) {
        return (word << bits) | (word >> (32 - bits));
    }

    uint32_t h_[5];
    uint32_t length_low_;
    uint32_t length_high_;
    uint8_t message_block_[64];
    int message_block_index_;
    bool computed_;
};

inline std::vector<uint8_t> sha1(const std::string& input) {
    SHA1 sha;
    sha.input(input);
    return sha.result();
}

inline std::string sha1_hex(const std::string& input) {
    auto digest = sha1(input);
    std::ostringstream oss;
    for (uint8_t byte : digest) {
        oss << std::hex << std::setw(2) << std::setfill('0')
            << static_cast<int>(byte);
    }
    return oss.str();
}

inline std::string compute_ws_security_digest(const std::string& nonce_base64,
                                             const std::string& created,
                                             const std::string& password) {
    std::string nonce_bytes = base64_decode(nonce_base64);
    std::string combined = nonce_bytes + created + password;
    auto hash = sha1(combined);
    std::string hash_str(reinterpret_cast<const char*>(hash.data()), hash.size());
    return base64_encode(hash_str);
}

// Base64编码表
constexpr const std::string_view base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

inline std::string base64_encode(const std::string& input) {
    std::string ret;
    int i = 0, j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    const unsigned char* bytes_to_encode =
        reinterpret_cast<const unsigned char*>(input.c_str());
    int in_len = input.length();

    while (in_len--) {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for(i = 0; (i <4); i++)
                ret += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i) {
        for(j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while((i++ < 3))
            ret += '=';
    }

    return ret;
}

inline std::string base64_decode(const std::string& input) {
    auto is_base64 = [](unsigned char c) {
        return (isalnum(c) || (c == '+') || (c == '/'));
    };

    auto in_len = input.length();
    int i = 0, j = 0, in = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (in_len-- && (input[in] != '=') && is_base64(input[in])) {
        char_array_4[i++] = input[in]; in++;
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++)
            char_array_4[j] = 0;

        for (j = 0; j < 4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }

    return ret;
}

} // namespace crypto
} // namespace libonvif_client
