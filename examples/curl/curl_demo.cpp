/**
 * @file curl_demo.cpp
 * @brief ONVIF客户端库使用示例 - 使用libcurl HTTP客户端
 *
 * 本示例展示如何使用 libonvif_client 库配合 libcurl HTTP客户端:
 * - 连接到ONVIF设备
 * - 获取设备信息
 * - 获取设备时间
 * - 获取设备能力和主机名
 * - 获取所有媒体配置文件(Profiles)
 * - 获取流URI和快照URI
 * - 获取OSD配置
 *
 * 编译:
 *   g++ -std=c++17 curl_demo.cpp curl_http_client.cpp \
 *       -I../include -lcurl -lxml2 -o curl_demo
 *
 * 运行:
 *   ./curl_demo http://192.168.1.100/onvif/device_service admin admin123
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
#include <libonvif_client/client/SearchPortClient.h>
#include <libonvif_client/client/RecordingPortClient.h>

// 使用 curl HTTP 客户端实现
#include "curl_http_client.h"


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
                if (resp.MediaUri.Timeout.duration().count()) {
                    std::cout << "超时: " << resp.MediaUri.Timeout.duration().count() << " 秒\n";
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

/**
 * @brief 打印轨道信息
 */
void print_track_information(const tt_TrackInformation& track, int index) {
    std::cout << "  Track #" << index << ":\n";
    std::cout << "    Token: " << track.TrackToken << "\n";

    std::string type_str;
    switch (track.TrackType) {
        case tt_TrackType::Video: type_str = "Video"; break;
        case tt_TrackType::Audio: type_str = "Audio"; break;
        case tt_TrackType::Metadata: type_str = "Metadata"; break;
        case tt_TrackType::Extended: type_str = "Extended"; break;
    }
    std::cout << "    类型 (Type): " << type_str << "\n";
    std::cout << "    描述 (Description): " << track.Description << "\n";
    std::cout << "    数据起始 (Data From): " << track.DataFrom.to_string() << "\n";
    std::cout << "    数据数据截止 (Data To): " << track.DataTo.to_string() << "\n";
}

/**
 * @brief 打印录像信息
 */
void print_recording_information(const tt_RecordingInformation& rec, int index) {
    std::cout << "\n录像 #" << index << ":\n";
    std::cout << "  RecordingToken: " << rec.RecordingToken << "\n";
    std::cout << "  状态 (Status): " << to_string(rec.RecordingStatus) << "\n";

    if (rec.EarliestRecording) {
        std::cout << "    最早录像 (Earliest): " << rec.EarliestRecording->to_string() << "\n";

    }
    if (rec.LatestRecording) {
        std::cout << "    最晚录像 (Latest): " << rec.LatestRecording->to_string() << "\n";
    }

    std::cout << "  内容描述 (Content): " << rec.Content << "\n";
    std::cout << "  轨道数量 (Tracks): " << rec.Track.size() << "\n";

    for (size_t ti = 0; ti < rec.Track.size(); ++ti) {
        print_track_information(rec.Track[ti], ti + 1);
    }

    std::cout << "  来源信息 (Source):\n";
    std::cout << "    SourceId: " << rec.Source.SourceId << "\n";
    std::cout << "    Name: " << rec.Source.Name << "\n";
    std::cout << "    Location: " << rec.Source.Location << "\n";
    std::cout << "    Description: " << rec.Source.Description << "\n";
    std::cout << "    Address: " << rec.Source.Address << "\n";
}

/**
 * @brief 演示获取录像概览
 */
void demo_get_recording_summary(std::shared_ptr<SearchPortClient> search_client) {
    print_separator("录像概览 (Recording Summary)");

    tse_GetRecordingSummary request;

    search_client->GetRecordingSummary(request,
        [](OnvifResult<tse_GetRecordingSummaryResponse>&& result) {
            if (result.is_error()) {
                std::cout << "错误: " << result.get_error_message() << "\n";
            } else {
                auto& summary = result.data->Summary;
                std::cout << "录像总数 (Number of Recordings): " << summary.NumberRecordings << "\n";
                std::cout << "最早录像 (Data From): " << summary.DataFrom.to_string() << "\n";
                std::cout << "最晚录像 (Data Until): " << summary.DataUntil.to_string() << "\n";
            }
            signal_operation_completed();
        });

    wait_for_operation();
}

/**
 * @brief 演示搜索详细录像列表
 *
 * 使用 FindRecordings 启动异步搜索, 然后通过 GetRecordingSearchResults 轮询结果,
 * 直到 SearchState 为 Completed。
 */
void demo_find_recordings(std::shared_ptr<SearchPortClient> search_client) {
    print_separator("搜索录像列表 (Find Recordings)");

    // Step 1: 启动搜索
    std::string search_token;
    {
        tse_FindRecordings request;
        request.KeepAliveTime = my_Duration(std::chrono::seconds(30));
        request.MaxMatches = 100;

        search_client->FindRecordings(request,
            [&search_token](OnvifResult<tse_FindRecordingsResponse>&& result) {
                if (result.is_error()) {
                    std::cout << "启动搜索失败: " << result.get_error_message() << "\n";
                } else {
                    search_token = result.data->SearchToken;
                    std::cout << "搜索已启动, SearchToken: " << search_token << "\n";
                }
                signal_operation_completed();
            });
        wait_for_operation();
    }

    if (search_token.empty()) {
        std::cout << "未能获取 SearchToken, 搜索终止\n";
        return;
    }

    // Step 2: 轮询结果
    bool search_complete = false;
    int total_recordings = 0;

    while (!search_complete) {
        tse_GetRecordingSearchResults request;
        request.SearchToken = search_token;
        request.MaxResults = 30;
        request.WaitTime = std::chrono::seconds(5);

        search_client->GetRecordingSearchResults(request,
            [&search_complete, &total_recordings](OnvifResult<tse_GetRecordingSearchResultsResponse>&& result) {
                if (result.is_error()) {
                    std::cout << "获取搜索结果失败: " << result.get_error_message() << "\n";
                    search_complete = true;
                } else {
                    auto& result_list = result.data->ResultList;
                    auto state_str = to_string(result_list.SearchState);
                    std::cout << "\n搜索状态: " << state_str
                              << ", 本次返回: " << result_list.RecordingInformation.size() << " 条\n";

                    for (const auto& rec_info : result_list.RecordingInformation) {
                        print_recording_information(rec_info, total_recordings + 1);
                        total_recordings++;
                    }

                    if (result_list.SearchState == tt_SearchState::Completed) {
                        search_complete = true;
                    }
                }
                signal_operation_completed();
            });
        wait_for_operation();
    }

    std::cout << "\n搜索完成, 共找到 " << total_recordings << " 条录像\n";
}

/**
 * @brief 演示获取录像任务列表 (含 Profile 映射)
 *
 * GetRecordingJobs 返回每个录像任务的 RecordingToken 和 SourceToken,
 * SourceToken 的 Value 就是对应的 ProfileToken。
 */
void demo_get_recording_jobs(std::shared_ptr<RecordingPortClient> recording_client) {
    print_separator("录像任务列表 (Recording Jobs)");

    trc_GetRecordingJobs request;

    recording_client->GetRecordingJobs(request,
        [](OnvifResult<trc_GetRecordingJobsResponse>&& result) {
            if (result.is_error()) {
                std::cout << "错误: " << result.get_error_message() << "\n";
            } else {
                auto& jobs = result.data->JobItem;
                std::cout << "共有 " << jobs.size() << " 个录像任务\n";

                int idx = 1;
                for (const auto& job : jobs) {
                    std::cout << "\n任务 #" << idx++ << ":\n";
                    std::cout << "  JobToken: " << job.JobToken << "\n";
                    std::cout << "  RecordingToken: " << job.JobConfiguration.RecordingToken << "\n";
                    std::cout << "  Mode: " << job.JobConfiguration.Mode << "\n";
                    std::cout << "  Priority: " << job.JobConfiguration.Priority << "\n";

                    for (size_t si = 0; si < job.JobConfiguration.Source.size(); ++si) {
                        const auto& src = job.JobConfiguration.Source[si];
                        if (src.SourceToken) {
                            std::cout << "  Source[" << si << "].SourceToken: "
                                      << src.SourceToken->Token << "\n";
                        }
                    }
                }
            }
            signal_operation_completed();
        });

    wait_for_operation();
}

std::shared_ptr<OnvifClient> onvif_client;

/**
 * @brief 从事件数据的 AnyElement 树中查找指定名称的 SimpleItem 的值
 */
std::string find_simple_item_value(const AnyElement& data_elem, const std::string& name) {
    for (const auto& child : data_elem.children) {
        if (child.local_name == "SimpleItem") {
            auto name_it = child.attributes.find("Name");
            if (name_it != child.attributes.end() && name_it->second == name) {
                auto value_it = child.attributes.find("Value");
                if (value_it != child.attributes.end()) {
                    return value_it->second;
                }
            }
        }
    }
    return "";
}

/**
 * @brief 演示通过搜索 IsDataPresent 事件获取录像片段列表 (ONVIF 官方标准路径)
 *
 * 工作流:
 * 1. 获取所有 RecordingToken
 * 2. 使用 FindEvents 搜索 IsDataPresent 事件
 * 3. 轮询 GetEventSearchResults
 * 4. 解析 Value=true(开始)/false(结束) 配对构建录像片段
 */
void demo_find_events(std::shared_ptr<SearchPortClient> search_client,
                      std::shared_ptr<RecordingPortClient> recording_client) {
    print_separator("搜索录像事件 (Find Events - IsDataPresent)");

    // Step 1: 获取所有 RecordingToken
    std::vector<std::string> recording_tokens;
    {
        trc_GetRecordings request;
        recording_client->GetRecordings(request,
            [&recording_tokens](OnvifResult<trc_GetRecordingsResponse>&& result) {
                if (result.is_error()) {
                    std::cout << "获取录像列表失败: " << result.get_error_message() << "\n";
                } else {
                    for (const auto& item : result.data->RecordingItem) {
                        recording_tokens.push_back(item.RecordingToken);
                    }
                    std::cout << "获取到 " << recording_tokens.size() << " 个录像\n";
                }
                signal_operation_completed();
            });
        wait_for_operation();
    }

    if (recording_tokens.empty()) {
        std::cout << "没有可用的录像, 跳过事件搜索\n";
        return;
    }

    // Step 2: 通过 GetRecordingSummary 获取录像时间范围
    std::optional<my_DateTime> data_from;
    std::optional<my_DateTime> data_until;
    {
        tse_GetRecordingSummary request;
        search_client->GetRecordingSummary(request,
            [&data_from, &data_until](OnvifResult<tse_GetRecordingSummaryResponse>&& result) {
                if (result.is_error()) {
                    std::cout << "获取录像摘要失败: " << result.get_error_message() << "\n";
                } else {
                    data_from = result.data->Summary.DataFrom;
                    data_until = result.data->Summary.DataUntil;
                    std::cout << "录像时间范围: " << data_from->to_string()
                              << " ~ " << data_until->to_string() << "\n";
                }
                signal_operation_completed();
            });
        wait_for_operation();
    }

    // Step 3: 启动 FindEvents
    std::string search_token;
    {
        tse_FindEvents request;
        if (data_from) request.StartPoint = *data_from;
        if (data_until) request.EndPoint = *data_until;
        request.Scope.IncludedRecordings = recording_tokens;
        request.IncludeStartState = true;
        request.MaxMatches = 200;
        AnyElement temp;
        temp.local_name = "MessageContentFilter";
        temp.text_content = R"(boolean(//tt:SimpleItem[@Name="IsDataPresent"]))";
        temp.attributes.emplace("Dialect", "http://www.onvif.org/ver10/tev/messageContentFilter/ItemFilter");
        request.SearchFilter._any_.push_back(temp);
        
        request.KeepAliveTime = my_Duration(std::chrono::seconds(30));

        search_client->FindEvents(request,
            [&search_token](OnvifResult<tse_FindEventsResponse>&& result) {
                if (result.is_error()) {
                    std::cout << "启动事件搜索失败: " << result.get_error_message() << "\n";
                } else {
                    search_token = result.data->SearchToken;
                    std::cout << "事件搜索已启动, SearchToken: " << search_token << "\n";
                }
                signal_operation_completed();
            });
        wait_for_operation();
    }

    if (search_token.empty()) {
        std::cout << "未能获取 SearchToken, 事件搜索终止\n";
        return;
    }

    // Step 4: 轮询结果
    bool search_complete = false;
    int total_events = 0;
    std::vector<std::pair<my_DateTime, my_DateTime>> recording_segments;
    std::vector<my_DateTime> pending_starts;

    while (!search_complete) {
        tse_GetEventSearchResults request;
        request.SearchToken = search_token;
        request.MaxResults = 30;
        request.WaitTime = std::chrono::seconds(5);

        search_client->GetEventSearchResults(request,
            [&search_complete, &total_events, &recording_segments, &pending_starts]
            (OnvifResult<tse_GetEventSearchResultsResponse>&& result) {
                if (result.is_error()) {
                    std::cout << "获取事件搜索结果失败: " << result.get_error_message() << "\n";
                    search_complete = true;
                } else {
                    auto& result_list = result.data->ResultList;
                    auto state_str = to_string(result_list.SearchState);
                    std::cout << "\n搜索状态: " << state_str
                              << ", 本次返回: " << result_list.Result.size() << " 个事件\n";
                    std::cout << "\n" << result.get_raw_xml() <<"\n";

                    // for (const auto& event_result : result_list.Result) {
                    //     total_events++;
                    //     auto event_time = event_result.Time;
                    //
                    //     for (const auto& msg_elem : event_result.Event.Message._any_) {
                    //         if (msg_elem.local_name == "Data") {
                    //             auto name_val = find_simple_item_value(msg_elem, "IsDataPresent");
                    //             if (!name_val.empty()) {
                    //                 bool is_present = (name_val == "true");
                    //                 auto track = find_simple_item_value(msg_elem, "Track");
                    //
                    //                 std::cout << "  [" << total_events << "] "
                    //                           << event_time.to_string()
                    //                           << " Track=" << track
                    //                           << " IsDataPresent=" << (is_present ? "true(开始)" : "false(结束)");
                    //
                    //                 if (is_present) {
                    //                     pending_starts.push_back(event_time);
                    //                     std::cout << "\n";
                    //                 } else {
                    //                     if (!pending_starts.empty()) {
                    //                         auto start_time = pending_starts.front();
                    //                         pending_starts.erase(pending_starts.begin());
                    //                         recording_segments.emplace_back(start_time, event_time);
                    //                         std::cout << " → 配对成功, 片段时长: "
                    //                                   << start_time.to_string()
                    //                                   << " ~ " << event_time.to_string() << "\n";
                    //                     } else {
                    //                         std::cout << " → 无配对开始事件\n";
                    //                     }
                    //                 }
                    //             }
                    //         }
                    //     }
                    // }

                    if (result_list.SearchState == tt_SearchState::Completed) {
                        search_complete = true;
                    }
                }
                signal_operation_completed();
            });
        wait_for_operation();
    }

    std::cout << "\n事件搜索完成:\n";
    std::cout << "  总事件数: " << total_events << "\n";
    std::cout << "  录像片段数: " << recording_segments.size() << "\n";

    if (!recording_segments.empty()) {
        std::cout << "\n录像片段列表:\n";
        int seg_idx = 1;
        for (const auto& [start, end] : recording_segments) {
            std::cout << "  片段 #" << seg_idx++ << ": "
                      << start.to_string() << " ~ " << end.to_string() << "\n";
        }
    }
}

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

    print_separator("ONVIF 客户端演示程序 (libcurl)");
    std::cout << "设备URL: " << device_url << "\n";
    std::cout << "用户名: " << username << "\n";

    try {
        // 1. 创建 libcurl HTTP 客户端
        auto http_client = std::make_shared<CurlHttpClient>(true, 4);

        // 可选：配置HTTP客户端
        http_client->set_ssl_verify(false);  // ONVIF设备常使用自签名证书
        http_client->set_connect_timeout(10);

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

        // 5. 获取设备信息
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

        // 6. 获取系统时间
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

        // 7. 获取设备能力
        demo_get_capabilities(onvif_client->create_device_client());

        // 8. 获取主机名
        demo_get_hostname(onvif_client->create_device_client());

        // 9. 获取媒体服务客户端
        media_client = onvif_client->create_service<MediaClient>();
        if (!media_client) {
            std::cout << "\n警告: 媒体服务不可用\n";
        } else {
            // 10. 获取所有配置文件
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

            // 11. 如果有配置文件，获取第一个配置文件的流URI和快照URI
            if (!profiles_response.Profiles.empty()) {
                const auto& first_profile = profiles_response.Profiles[0];
                demo_get_stream_uri(media_client, first_profile.token);
                demo_get_snapshot_uri(media_client, first_profile.token);

                // 12. 获取OSD配置
                if (first_profile.VideoSourceConfiguration) {
                    demo_get_osds(media_client, first_profile.VideoSourceConfiguration->token);
                }
            }
        }

        // 13. 录像查询功能
        {
            auto search_client = onvif_client->create_service<SearchPortClient>();
            if (search_client) {
                demo_get_recording_summary(search_client);
                demo_find_recordings(search_client);
            } else {
                std::cout << "\n警告: 搜索服务 (Search) 不可用\n";
            }

            auto recording_client = onvif_client->create_service<RecordingPortClient>();
            if (recording_client) {
                demo_get_recording_jobs(recording_client);

                if (search_client) {
                    demo_find_events(search_client, recording_client);
                }
            } else {
                std::cout << "\n警告: 录像服务 (Recording) 不可用\n";
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

    // 清理libcurl全局资源
    curl_global_cleanup();

    return 0;
}
