/**
 * @file onvif_callback.h
 * @brief ONVIF回调接口定义
 * @note 统一的异步回调接口，用于所有ONVIF操作
 */

#pragma once

#include <libonvif_client/core/onvif_result.h>
#include <functional>

namespace libonvif_client {

/**
 * @brief ONVIF异步操作回调函数模板
 *
 * 用于所有ONVIF异步操作的统一回调接口。
 * 回调函数接收 OnvifResult 对象（通过 move 语义传递）。
 *
 * @tparam T 响应数据类型
 * @param result ONVIF操作结果（包含成功数据或错误信息）
 *
 * @note 回调函数可能在任何线程中被调用，实现者需要确保线程安全
 * @note result 通过 move 语义传递，避免拷贝开销
 * @note 使用 result.is_success() 判断成功，result.is_error() 判断失败
 *
 * @example
 * @code
 * client->GetDeviceInformation(request,
 *     [](OnvifResult<GetDeviceInformationResponse>&& result) {
 *         if (result.is_success()) {
 *             auto& info = *result.data;
 *             std::cout << "Manufacturer: " << info.manufacturer << "\n";
 *         } else {
 *             std::cout << "Error: " << result.get_error_message() << "\n";
 *         }
 *     });
 * @endcode
 */
template<typename T>
using OnvifCallback = std::function<void(OnvifResult<T>&&)>;
using OnvifSimpleCallback = std::function<void(OnvifResult<void> &&)>;

} // namespace libonvif_client
