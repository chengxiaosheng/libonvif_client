/**
 * @file demo.cpp
 * @brief ONVIF客户端库使用示例
 *
 * 本示例展示如何使用 libonvif_client 库:
 * - 连接到ONVIF设备
 * - 获取设备信息
 * - 获取设备时间
 * - 获取所有媒体配置文件(Profiles)
 * - 获取流URI和快照URI
 * - 获取OSD配置
 * - 一些常用操作
 */

#include <iostream>
#include <iomanip>
#include <memory>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>

// ONVIF 客户端核心头文件
#include <libonvif_client/core/onvif_client.h>
#include <libonvif_client/client/DeviceClient.h>
#include <libonvif_client/client/MediaClient.h>

// HTTP 客户端实现 (示例实现，位于 examples/http_clients)
#include "drogon_http_client.h"


using namespace libonvif_client;

// 全局同步变量 - 用于演示目的
std::mutex g_mutex;
std::condition_variable g_cv;
bool g_operation_completed = false;
std::shared_ptr<DeviceClient> device_client;
std::shared_ptr<MediaClient> media_client;
/**
 * @brief 等待异步操作完成的辅助函数
 */
void wait_for_operation(int timeout_seconds = 10) {
    std::unique_lock<std::mutex> lock(g_mutex);
    g_cv.wait_for(lock, std::chrono::seconds(timeout_seconds), [] { return g_operation_completed; });
    g_operation_completed = false;
}

/**
 * @brief 标记操作完成的辅助函数
 */
void signal_operation_completed() {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        g_operation_completed = true;
    }
    g_cv.notify_one();
}

/**
 * @brief 打印分隔线
 */
void print_separator(const std::string& title = "") {
    std::cout << "\n" << std::string(80, '=') << "\n";
    if (!title.empty()) {
        std::cout << "  " << title << "\n";
        std::cout << std::string(80, '=') << "\n";
    }
}

/**
 * @brief 打印设备信息
 */
void print_device_info(const tds_GetDeviceInformationResponse& info) {
    print_separator("设备信息 (Device Information)");
    std::cout << "制造商 (Manufacturer):  " << info.Manufacturer << "\n";
    std::cout << "型号 (Model):          " << info.Model << "\n";
    std::cout << "固件版本 (Firmware):    " << info.FirmwareVersion << "\n";
    std::cout << "序列号 (Serial):       " << info.SerialNumber << "\n";
    std::cout << "硬件ID (Hardware ID):  " << info.HardwareId << "\n";
}

/**
 * @brief 打印日期时间
 */
void print_datetime(const tt_DateTime& dt, const std::string& label) {
    std::cout << label << ": "
              << std::setfill('0') << std::setw(4) << dt.Date.Year << "-"
              << std::setw(2) << dt.Date.Month << "-"
              << std::setw(2) << dt.Date.Day << " "
              << std::setw(2) << dt.Time.Hour << ":"
              << std::setw(2) << dt.Time.Minute << ":"
              << std::setw(2) << dt.Time.Second << "\n";
}

/**
 * @brief 打印系统日期时间信息
 */
void print_system_datetime(const tds_GetSystemDateAndTimeResponse& response) {
    print_separator("系统时间 (System Date & Time)");

    const auto& sdt = response.SystemDateAndTime;

    std::cout << "时间类型 (Type): "
              << (sdt.DateTimeType == tt_SetDateTimeType::NTP ? "NTP" : "Manual") << "\n";
    std::cout << "夏令时 (DST):   " << (sdt.DaylightSavings ? "启用" : "禁用") << "\n";

    if (sdt.TimeZone) {
        std::cout << "时区 (Timezone): " << sdt.TimeZone->TZ << "\n";
    }

    if (sdt.UTCDateTime) {
        print_datetime(*sdt.UTCDateTime, "UTC时间");
    }

    if (sdt.LocalDateTime) {
        print_datetime(*sdt.LocalDateTime, "本地时间");
    }
}

/**
 * @brief 打印视频编码器配置
 */
void print_video_encoder_config(const tt_VideoEncoderConfiguration& config) {
    std::cout << "    视频编码器:\n";
    std::cout << "      名称: " << config.Name << "\n";
    std::cout << "      Token: " << config.token << "\n";

    std::string encoding;
    switch (config.Encoding) {
        case tt_VideoEncoding::JPEG: encoding = "JPEG"; break;
        case tt_VideoEncoding::MPEG4: encoding = "MPEG4"; break;
        case tt_VideoEncoding::H264: encoding = "H264"; break;
        default: encoding = "Unknown"; break;
    }
    std::cout << "      编码: " << encoding << "\n";

    std::cout << "      分辨率: " << config.Resolution.Width << "x"
              << config.Resolution.Height << "\n";
}

/**
 * @brief 打印媒体配置文件
 */
void print_profile(const tt_Profile& profile, int index) {
    std::cout << "\n配置文件 #" << index << ":\n";
    std::cout << "  名称: " << profile.Name << "\n";
    std::cout << "  Token: " << profile.token << "\n";

    if (profile.fixed) {
        std::cout << "  固定: " << (*profile.fixed ? "是" : "否") << "\n";
    }

    if (profile.VideoEncoderConfiguration) {
        print_video_encoder_config(*profile.VideoEncoderConfiguration);
    }

    if (profile.PTZConfiguration) {
        std::cout << "    云台 (PTZ): 支持\n";
        std::cout << "      名称: " << profile.PTZConfiguration->Name << "\n";
    }
}

/**
 * @brief 打印所有配置文件
 */
void print_profiles(const trt_GetProfilesResponse& response) {
    print_separator("媒体配置文件 (Media Profiles)");
    std::cout << "共有 " << response.Profiles.size() << " 个配置文件\n";

    int index = 1;
    for (const auto& profile : response.Profiles) {
        print_profile(profile, index++);
    }
}

/**
 * @brief 演示获取流URI
 */
void demo_get_stream_uri(std::shared_ptr<MediaClient> media_client, const std::string& profile_token) {
    print_separator("获取流URI (Stream URI)");
    std::cout << "配置文件 Token: " << profile_token << "\n";

    trt_GetStreamUri request;
    request.ProfileToken = profile_token;
    request.StreamSetup.Stream = tt_StreamType::RTP_Unicast;
    request.StreamSetup.Transport.Protocol = tt_TransportProtocol::RTSP;

    media_client->GetStreamUri(request,
        [media_client](OnvifResult<trt_GetStreamUriResponse>&& result) {
            if (result.is_error()) {
                std::cout << "错误: " << result.get_error_message() << "\n";
            } else {
                auto& resp = *result.data;
                std::cout << "流URI: " << resp.MediaUri.Uri << "\n";
                if (resp.MediaUri.InvalidAfterConnect) {
                    std::cout << "注意: 此URI在连接后会失效\n";
                }
                if (resp.MediaUri.InvalidAfterReboot) {
                    std::cout << "注意: 此URI在设备重启后会失效\n";
                }
                if (!resp.MediaUri.Timeout.empty()) {
                    std::cout << "超时: " << resp.MediaUri.Timeout << " 秒\n";
                }
            }
            signal_operation_completed();
        });

    wait_for_operation();
}

/**
 * @brief 演示获取快照URI
 */
void demo_get_snapshot_uri(std::shared_ptr<MediaClient> media_client, const std::string& profile_token) {
    print_separator("获取快照URI (Snapshot URI)");
    std::cout << "配置文件 Token: " << profile_token << "\n";

    trt_GetSnapshotUri request;
    request.ProfileToken = profile_token;

    media_client->GetSnapshotUri(request,
        [media_client](OnvifResult<trt_GetSnapshotUriResponse>&& result) {
            if (result.is_error()) {
                std::cout << "错误: " << result.get_error_message() << "\n";
            } else {
                std::cout << "快照URI: " << result.data->MediaUri.Uri << "\n";
            }
            signal_operation_completed();
        });

    wait_for_operation();
}

/**
 * @brief 打印OSD类型
 */
std::string osd_type_to_string(tt_OSDType type) {
    switch (type) {
        case tt_OSDType::Text: return "文本 (Text)";
        case tt_OSDType::Image: return "图像 (Image)";
        case tt_OSDType::Extended: return "扩展 (Extended)";
        default: return "未知";
    }
}

/**
 * @brief 打印OSD配置信息
 */
void print_osd_config(const tt_OSDConfiguration& osd, int index) {
    std::cout << "\nOSD #" << index << ":\n";
    std::cout << "  Token: " << osd.token << "\n";
    std::cout << "  类型: " << osd_type_to_string(osd.Type) << "\n";
    std::cout << "  视频源Token: " << osd.VideoSourceConfigurationToken.value << "\n";

    // 位置信息
    std::cout << "  位置:\n";
    std::cout << "    类型: " << osd.Position.Type << "\n";
    if (osd.Position.Pos) {
        std::cout << "    X: " << osd.Position.Pos->x << "\n";
        std::cout << "    Y: " << osd.Position.Pos->y << "\n";
    }

    // 文本配置
    if (osd.TextString && osd.Type == tt_OSDType::Text) {
        std::cout << "  文本配置:\n";
        std::cout << "    类型: " << osd.TextString->Type << "\n";
        if (osd.TextString->DateFormat) {
            std::cout << "    日期格式: " << *osd.TextString->DateFormat << "\n";
        }
        if (osd.TextString->TimeFormat) {
            std::cout << "    时间格式: " << *osd.TextString->TimeFormat << "\n";
        }
        if (osd.TextString->FontSize) {
            std::cout << "    字体大小: " << *osd.TextString->FontSize << "\n";
        }
        if (osd.TextString->FontColor) {
            std::cout << "    字体颜色: R=" << (int)osd.TextString->FontColor->Color.X
                      << " G=" << (int)osd.TextString->FontColor->Color.Y
                      << " B=" << (int)osd.TextString->FontColor->Color.Z << "\n";
        }
        if (osd.TextString->BackgroundColor) {
            std::cout << "    背景颜色: R=" << (int)osd.TextString->BackgroundColor->Color.X
                      << " G=" << (int)osd.TextString->BackgroundColor->Color.Y
                      << " B=" << (int)osd.TextString->BackgroundColor->Color.Z << "\n";
        }
        if (osd.TextString->PlainText) {
            std::cout << "    文本内容: " << *osd.TextString->PlainText << "\n";
        }
    }

    // 图像配置
    if (osd.Image && osd.Type == tt_OSDType::Image) {
        std::cout << "  图像配置:\n";
        std::cout << "    图像URI: " << osd.Image->ImgPath << "\n";
    }
}

/**
 * @brief 演示获取OSD配置
 */
void demo_get_osds(std::shared_ptr<MediaClient> media_client, const std::string& video_source_token) {
    print_separator("获取OSD配置 (OSD Configurations)");
    std::cout << "视频源 Token: " << video_source_token << "\n";

    trt_GetOSDs request;
    request.ConfigurationToken = video_source_token;

    media_client->GetOSDs(request,
        [media_client](OnvifResult<trt_GetOSDsResponse>&& result) {
            if (result.is_error()) {
                std::cout << "错误: " << result.get_error_message() << "\n";
            } else {
                auto& resp = *result.data;
                std::cout << "共有 " << resp.OSDs.size() << " 个OSD配置\n";

                int index = 1;
                for (const auto& osd : resp.OSDs) {
                    print_osd_config(osd, index++);
                }
            }
            signal_operation_completed();
        });

    wait_for_operation();
}

/**
 * @brief 演示获取主机名
 */
void demo_get_hostname(std::shared_ptr<DeviceClient> device_client) {
    print_separator("主机名 (Hostname)");

    tds_GetHostname request;

    device_client->GetHostname(request,
        [device_client](OnvifResult<tds_GetHostnameResponse>&& result) {
            if (result.is_error()) {
                std::cout << "错误: " << result.get_error_message() << "\n";
            } else {
                auto& resp = *result.data;
                if (resp.HostnameInformation.Name) {
                    std::cout << "主机名: " << *resp.HostnameInformation.Name << "\n";
                }
                std::cout << "来自DHCP: " << (resp.HostnameInformation.FromDHCP ? "是" : "否") << "\n";
            }
            signal_operation_completed();
        });

    wait_for_operation();
}

/**
 * @brief 演示获取服务能力
 */
void demo_get_capabilities(std::shared_ptr<DeviceClient> device_client) {
    print_separator("设备能力 (Device Capabilities)");

    tds_GetCapabilities request;

    device_client->GetCapabilities(request,
        [device_client](OnvifResult<tds_GetCapabilitiesResponse>&& result) {
            if (result.is_error()) {
                std::cout << "错误: " << result.get_error_message() << "\n";
            } else {
                const auto& caps = result.data->Capabilities;

                if (caps.Media) {
                    std::cout << "媒体服务 (Media): " << caps.Media->XAddr << "\n";
                }
                if (caps.PTZ) {
                    std::cout << "云台服务 (PTZ): " << caps.PTZ->XAddr << "\n";
                }
                if (caps.Imaging) {
                    std::cout << "图像服务 (Imaging): " << caps.Imaging->XAddr << "\n";
                }
                if (caps.Events) {
                    std::cout << "事件服务 (Events): " << caps.Events->XAddr << "\n";
                }
                if (caps.Analytics) {
                    std::cout << "分析服务 (Analytics): " << caps.Analytics->XAddr << "\n";
                }
            }
            signal_operation_completed();
        });

    wait_for_operation();
}
std::shared_ptr<OnvifClient>  onvif_client;
/**
 * @brief 主函数
 */
int main(int argc, char* argv[]) {
    // 检查命令行参数
    if (argc < 4) {
        std::cout << "用法: " << argv[0] << " <设备URL> <用户名> <密码>\n";
        std::cout << "示例: " << argv[0] << " http://192.168.1.100/onvif/device_service admin admin123\n";
        return 1;
    }

    std::string device_url = argv[1];
    std::string username = argv[2];
    std::string password = argv[3];

    print_separator("ONVIF 客户端演示程序");
    std::cout << "设备URL: " << device_url << "\n";
    std::cout << "用户名: " << username << "\n";

    try {
        // 1. 创建 HTTP 客户端
        auto http_client = std::make_shared<DrogonHttpClient>(false);

        // 2. 创建 ONVIF 客户端
        onvif_client = std::make_shared<OnvifClient>(
            device_url, username, password, http_client
        );

        // 3. 初始化客户端（发现所有服务）
        print_separator("初始化ONVIF客户端");
        std::cout << "正在发现服务...\n";

        onvif_client->initialize(
            [](OnvifResult<tds_GetServicesResponse>&& result) {
                if (result.is_error()) {
                    std::cout << "✗ 初始化失败: " << result.get_error_message() << "\n";
                } else {
                    std::cout << "✓ 初始化成功!\n";
                }
                signal_operation_completed();
            });

        wait_for_operation();

        // 4. 获取设备客户端
        device_client = onvif_client->create_device_client();
        if (!device_client) {
            std::cout << "无法获取设备客户端\n";
            return 1;
        }

        // 6. 获取设备信息
        {
            tds_GetDeviceInformation request;
            device_client->GetDeviceInformation(request,
                [](OnvifResult<tds_GetDeviceInformationResponse>&& result) {
                    if (result.is_error()) {
                        std::cout << "获取设备信息失败: " << result.get_error_message() << "\n";
                    } else {
                        print_device_info(*result.data);
                    }
                    signal_operation_completed();
                });
            wait_for_operation();
        }

        // 7. 获取系统时间
        {
            tds_GetSystemDateAndTime request;
            device_client->GetSystemDateAndTime(request,
                [](OnvifResult<tds_GetSystemDateAndTimeResponse>&& result) {
                    if (result.is_error()) {
                        std::cout << "获取系统时间失败: " << result.get_error_message() << "\n";
                    } else {
                        print_system_datetime(*result.data);
                    }
                    signal_operation_completed();
                });
            wait_for_operation();
        }

        // 8. 获取设备能力
        demo_get_capabilities(device_client);

        // 9. 获取主机名
        demo_get_hostname(device_client);

        // 10. 获取媒体服务客户端
        media_client = onvif_client->create_service<MediaClient>();
        if (!media_client) {
            std::cout << "\n警告: 媒体服务不可用\n";
        } else {
            // 11. 获取所有配置文件
            trt_GetProfilesResponse profiles_response;
            {
                trt_GetProfiles request;
                media_client->GetProfiles(request,
                    [&profiles_response](OnvifResult<trt_GetProfilesResponse>&& result) {
                        if (result.is_error()) {
                            std::cout << "获取配置文件失败: " << result.get_error_message() << "\n";
                        } else {
                            profiles_response = *result.data;
                            print_profiles(*result.data);
                        }
                        signal_operation_completed();
                    });
                wait_for_operation();
            }

            // 12. 如果有配置文件，获取第一个配置文件的流URI和快照URI
            if (!profiles_response.Profiles.empty()) {
                const auto& first_profile = profiles_response.Profiles[0];
                demo_get_stream_uri(media_client, first_profile.token);
                demo_get_snapshot_uri(media_client, first_profile.token);

                // 13. 获取OSD配置
                if (first_profile.VideoSourceConfiguration) {
                    demo_get_osds(media_client, first_profile.VideoSourceConfiguration->token);
                }
            }
        }

        // 14. 显示可用服务列表
        print_separator("可用服务列表");
        auto services = onvif_client->get_available_services();
        for (const auto& [name, endpoint] : services) {
            std::cout << name << ": " << endpoint << "\n";
        }

        print_separator("演示完成");
        std::cout << "所有操作已完成!\n\n";

    } catch (const std::exception& e) {
        std::cout << "异常: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
