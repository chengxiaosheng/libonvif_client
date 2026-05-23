#include "onvif_demo_common.h"

#include <iostream>
#include <algorithm>
#include <atomic>
#include "libonvif_client/client/ReceiverPortClient.h"
#include "onvif_demo_custom_types.h"

namespace onvif_demo {

namespace lc = libonvif_client;

// shared_ptr<void> with a custom deleter that runs a callback.
// Captured by async callbacks to: (1) keep service clients alive via the
// deleter's lambda captures, (2) trigger the next step when all callbacks
// finish (refcount drops to zero).
static std::shared_ptr<void> make_guard(std::function<void()> on_done) {
    return std::shared_ptr<void>(nullptr, [on_done = std::move(on_done)](void*) {
        on_done();
    });
}

OnvifDemoRunner::OnvifDemoRunner(std::shared_ptr<lc::OnvifClient> client)
    : onvif_client_(std::move(client)) {}

void OnvifDemoRunner::start(DoneCallback done) {
    step_initialize(std::move(done));
}

// ============================================================================
void OnvifDemoRunner::step_initialize(DoneCallback done) {
    std::cout << "\n" << std::string(80, '=') << "\n"
              << "  Initializing ONVIF Client\n"
              << std::string(80, '=') << "\n"
              << "Discovering services...\n";

    onvif_client_->initialize(
        [this, done](lc::OnvifResult<lc::tds_GetServicesResponse>&& result) {
            if (result.is_error()) {
                std::cout << "Initialization failed: " << result.get_error_message() << "\n";
                done();
                return;
            }
            std::cout << "Initialization successful!\n";
            if (!onvif_client_->create_device_client()) {
                std::cout << "Failed to create device client\n";
                done();
                return;
            }
            step_get_device_info(std::move(done));
        });
}

// ============================================================================
void OnvifDemoRunner::step_get_device_info(DoneCallback done) {
    auto device = onvif_client_->create_device_client();
    auto guard = make_guard([this, done, device]() {
        step_get_system_datetime(std::move(done));
    });

    lc::tds_GetDeviceInformation request;
    device->GetDeviceInformation(request,
        [this, guard](lc::OnvifResult<lc::tds_GetDeviceInformationResponse>&& result) {
            if (result.is_success()) print_device_info(*result.data);
            else std::cout << "GetDeviceInformation failed: " << result.get_error_message() << "\n";
        });
}

// ============================================================================
void OnvifDemoRunner::step_get_system_datetime(DoneCallback done) {
    auto device = onvif_client_->create_device_client();
    auto guard = make_guard([this, done, device]() {
        step_get_capabilities(std::move(done));
    });

    lc::tds_GetSystemDateAndTime request;
    device->GetSystemDateAndTime(request,
        [this, guard](lc::OnvifResult<lc::tds_GetSystemDateAndTimeResponse>&& result) {
            if (result.is_success()) print_system_datetime(*result.data);
            else std::cout << "GetSystemDateAndTime failed: " << result.get_error_message() << "\n";
        });
}

// ============================================================================
void OnvifDemoRunner::step_get_capabilities(DoneCallback done) {
    auto device = onvif_client_->create_device_client();
    auto guard = make_guard([this, done, device]() {
        step_get_hostname(std::move(done));
    });

    print_separator("Device Capabilities");

    lc::tds_GetCapabilities request;
    device->GetCapabilities(request,
        [this, guard](lc::OnvifResult<lc::tds_GetCapabilitiesResponse>&& result) {
            if (result.is_success()) {
                const auto& caps = result.data->Capabilities;
                if (caps.Media) std::cout << "Media: " << caps.Media->XAddr << "\n";
                if (caps.PTZ) std::cout << "PTZ: " << caps.PTZ->XAddr << "\n";
                if (caps.Imaging) std::cout << "Imaging: " << caps.Imaging->XAddr << "\n";
                if (caps.Events) std::cout << "Events: " << caps.Events->XAddr << "\n";
                if (caps.Analytics) std::cout << "Analytics: " << caps.Analytics->XAddr << "\n";
            } else {
                std::cout << "GetCapabilities failed: " << result.get_error_message() << "\n";
            }
        });
}

// ============================================================================
void OnvifDemoRunner::step_get_hostname(DoneCallback done) {
    auto device = onvif_client_->create_device_client();
    auto guard = make_guard([this, done, device]() {
        step_get_profiles(std::move(done));
    });

    print_separator("Hostname");

    lc::tds_GetHostname request;
    device->GetHostname(request,
        [this, guard](lc::OnvifResult<lc::tds_GetHostnameResponse>&& result) {
            if (result.is_success()) {
                auto& resp = *result.data;
                if (resp.HostnameInformation.Name)
                    std::cout << "Hostname: " << *resp.HostnameInformation.Name << "\n";
                std::cout << "FromDHCP: " << (resp.HostnameInformation.FromDHCP ? "Yes" : "No") << "\n";
            } else {
                std::cout << "GetHostname failed: " << result.get_error_message() << "\n";
            }
        });
}

// ============================================================================
void OnvifDemoRunner::step_get_profiles(DoneCallback done) {
    auto media2 = onvif_client_->create_service<lc::Media2Client>();
    auto media = onvif_client_->create_service<lc::MediaClient>();

    auto guard = make_guard([this, done, media, media2]() {
        for (auto &it : profile_infos_) {
            std::cout << "  Profile: " << it.first << ", VideoSourceToken:" << it.second.video_source_token << ", Uri:" << it.second.stream_uri << "\n";
        }
        step_query_receiver(std::move(done));
    });

    if (media2) {
        print_separator("Media2 Profiles");
        lc::tr2_GetProfiles req;
        media2->GetProfiles(req,
            [this, media2, guard](lc::OnvifResult<lc::tr2_GetProfilesResponse>&& result) {
                if (result.is_error()) {
                    std::cout << "Media2 GetProfiles failed: " << result.get_error_message() << "\n";
                    return;
                }

                auto& profiles = result.data->Profiles;
                std::cout << "Total profiles: " << profiles.size() << "\n";
                if (profiles.empty()) return;

                for (const auto& profile : profiles) {
                    lc::tr2_GetStreamUri uri_req;
                    uri_req.ProfileToken = profile.token;
                    uri_req.Protocol = "RTSP";

                    std::string tok = profile.token;
                    std::string vst;
                    if (profile.Configurations && profile.Configurations->VideoSource)
                        vst = profile.Configurations->VideoSource->token;

                    media2->GetStreamUri(uri_req,
                        [this, tok, vst, guard](lc::OnvifResult<lc::tr2_GetStreamUriResponse>&& uri_result) {
                            std::string uri_str;
                            if (uri_result.is_success()) {
                                ProfileInfo info;
                                info.stream_uri = uri_result.data->Uri;
                                info.video_source_token = vst;
                                profile_infos_[tok] = info;
                                uri_str = uri_result.data->Uri;
                            } else {
                                uri_str = "(failed)";
                            }
                            std::cout << "  Profile: " << tok << " StreamUri: " << uri_str << "\n";
                        });
                }
            });
    }
    else if (media) {
        print_separator("Media Profiles");

        lc::trt_GetProfiles request;
        media->GetProfiles(request,
            [this, media, guard](lc::OnvifResult<lc::trt_GetProfilesResponse>&& result) {
                if (result.is_error()) {
                    std::cout << "GetProfiles failed: " << result.get_error_message() << "\n";
                    return;
                }

                print_profiles(*result.data);

                auto& profiles = result.data->Profiles;
                if (profiles.empty()) return;

                if (profiles[0].VideoSourceConfiguration) {
                    lc::trt_GetOSDs osd_req;
                    osd_req.ConfigurationToken = profiles[0].VideoSourceConfiguration->token;
                    media->GetOSDs(osd_req,
                        [guard](lc::OnvifResult<lc::trt_GetOSDsResponse>&& osd_result) {
                            if (osd_result.is_success()) {
                                std::cout << "Total OSDs: " << osd_result.data->OSDs.size() << "\n";
                                int idx = 1;
                                for (const auto& osd : osd_result.data->OSDs)
                                    print_osd_config(osd, idx++);
                            }
                        });
                }

                for (const auto& profile : profiles) {
                    if (profile.fixed != true) continue;
                    lc::trt_GetStreamUri uri_req;
                    uri_req.ProfileToken = profile.token;
                    uri_req.StreamSetup.Stream = lc::tt_StreamType::RTP_Unicast;
                    uri_req.StreamSetup.Transport.Protocol = lc::tt_TransportProtocol::RTSP;

                    std::string tok = profile.token;
                    std::string vst;
                    if (profile.VideoSourceConfiguration)
                        vst = profile.VideoSourceConfiguration->token;

                    media->GetStreamUri(uri_req,
                        [this, tok, vst, guard](lc::OnvifResult<lc::trt_GetStreamUriResponse>&& uri_result) {
                            if (uri_result.is_success()) {
                                ProfileInfo info;
                                info.stream_uri = uri_result.data->MediaUri.Uri;
                                info.video_source_token = vst;
                                profile_infos_[tok] = info;
                            } else {
                                std::cout << "Profile [" << tok << "] GetStreamUri Failed" << uri_result.get_error_message() << "\n";
                            }
                        });
                }
            });
    } else {
        std::cout << "\nWarning: Media service not available\n";
        step_print_services(std::move(done));
    }
}

void OnvifDemoRunner::step_query_receiver(DoneCallback done) {
    auto receiver  = onvif_client_->create_service<lc::ReceiverPortClient>();
    if (receiver) {
        libonvif_client::trv_GetReceivers input;
        receiver->GetReceivers({}, [this, receiver, done](const lc::OnvifResult<lc::trv_GetReceiversResponse>& result) {
            if (result.is_error())
                std::cout << "GetRecordingJobs failed: " << result.get_error_message() << "\n";
            else {
                print_separator("Query ReceiverToken");
                for (auto &it : result.data->Receivers) {
                    std::cout << "ReceiverToken:" << it.Token << ", uri:" << it.Configuration.MediaUri << "\n";
                    auto profile = std::find_if(profile_infos_.begin(), profile_infos_.end(), [&](const std::pair<std::string, ProfileInfo>& info) {
                        if (info.second.stream_uri == it.Configuration.MediaUri) {
                            return true;
                        }
                        // Fuzzy URI match: strip query params, then compare last path segment
                        auto last_segment = [](const std::string& uri) -> std::string {
                            auto qpos = uri.find('?');
                            std::string path = (qpos != std::string::npos) ? uri.substr(0, qpos) : uri;
                            if (path.empty() || path.back() == '/') return path;
                            auto slash = path.rfind('/');
                            return (slash != std::string::npos) ? path.substr(slash + 1) : path;
                        };
                        return last_segment(info.second.stream_uri) == last_segment(it.Configuration.MediaUri);
                    });
                    if (profile != profile_infos_.end()) {
                        profile->second.receiver_token = it.Token;
                    }
                }
                step_query_recording_job(done);
            }
        });
    }
}


void OnvifDemoRunner::step_qeury_recordings(DoneCallback done) {

    auto search = onvif_client_->create_service<lc::SearchPortClient>();
    auto guard = std::shared_ptr<void>(nullptr, [this, search, done](void *) {
        step_query_recording_events(done);
    });

    for (auto &profile : profile_infos_) {
        if (profile.second.recording_token.empty()) continue;

        libonvif_client::tse_FindRecordings input;
        input.Scope.IncludedRecordings = {  profile.second.recording_token };
        input.Scope.RecordingInformationFilter = R"(boolean(//Track[TrackType = “Video”]))";
        input.KeepAliveTime = std::chrono::seconds(30);
        search->FindRecordings(input, [guard, profile = profile.first, search, rdt= profile.second.recording_token, this](lc::OnvifResult<lc::tse_FindRecordingsResponse>&& result) {
            if (result.is_error()) {
                std::cout << "FindRecordings failed: " << result.get_error_message() << "\n";
                return;
            }

            auto first = std::make_shared<bool>(true);
            auto do_got = [guard, token = result.data->SearchToken, search, rdt, profile, this, first](auto && self) -> void {
                libonvif_client::tse_GetRecordingSearchResults input;
                input.SearchToken = token;
                // input.MinResults = 100;
                input.MaxResults = 1000;
                input.WaitTime = std::chrono::seconds(30);

                search->GetRecordingSearchResults(input, [guard, this, self = std::forward<decltype(self)>(self), rdt, pt = profile,
                         first](const lc::OnvifResult<lc::tse_GetRecordingSearchResultsResponse>& result) -> void {
                    if (result.is_error() ) {
                        std::cout << "GetRecordingSearchResults failed: " << result.get_error_message() << "\n";
                        return;
                    }
                    auto & profile = profile_infos_[pt];
                    if (result.data->ResultList.RecordingInformation.size() > 1) {
                        for (auto &it : result.data->ResultList.RecordingInformation) {
                            if (it.RecordingToken != rdt) continue;
                            for (auto &track : it.Track) {
                                if (track.TrackType == libonvif_client::tt_TrackType::Video) {
                                    profile.record_files.push_back({track.DataFrom, track.DataTo});
                                }
                            }
                        }
                    }
                    if (result.data->ResultList.RecordingInformation.size() == 1 && *first) {
                        for (auto &it : result.data->ResultList.RecordingInformation) {
                            if (it.RecordingToken != rdt) continue;
                            for (auto &track : it.Track) {
                                if (track.TrackType == libonvif_client::tt_TrackType::Video) {
                                    profile.start_recording_time = track.DataFrom;
                                    profile.end_recording_time = track.DataTo;
                                }
                            }
                            break;
                        }
                    }
                    *first = false;
                    if (result.data->ResultList.SearchState != lc::tt_SearchState::Completed) {
                        self(self);
                    }
                });
            };
            do_got(do_got);
        });
    }
}
void OnvifDemoRunner::step_query_recording_events(DoneCallback done) {

    auto base_search = onvif_client_->create_service<lc::SearchPortClient>();
    auto search = std::make_shared<onvif_demo::CustomSearchClient>(base_search->get_service_url(),
        base_search->get_http_client(),
        onvif_client_->username(), onvif_client_->password());

    if (!search) {
        std::cout << "Search service not available, skipping event query\n";
        step_print_services(std::move(done));
        return;
    }

    bool has_recording = false;
    for (auto& [tok, info] : profile_infos_) {
        if (!info.recording_token.empty()) { has_recording = true; break; }
    }
    if (!has_recording) {
        step_print_services(std::move(done));
        return;
    }

    auto guard = make_guard([this, done, base_search, search]() {
        print_separator("Recording Event Results");
        for (const auto& [tok, info] : profile_infos_) {
            if (info.recording_token.empty()) continue;
            std::cout << "  Profile: " << tok << ", segments: " << info.record_files.size() << "\n";
            for (size_t i = 0; i < info.record_files.size(); ++i) {
                auto& f = info.record_files[i];
                std::cout << "    [" << i << "] " << f.start_time.to_string()
                          << " ~ " << f.end_time.to_string() << "\n";
            }
        }
        step_print_services(std::move(done));
    });

    print_separator("Recording Events");

    for (auto& [profile_token, info] : profile_infos_) {
        if (info.recording_token.empty()) continue;

        lc::tse_FindEvents req;
        req.StartPoint = info.end_recording_time.after(std::chrono::seconds(-2 * 24 * 60 * 60));
        req.EndPoint = libonvif_client::my_DateTime();
        req.IncludeStartState = true;
        req.KeepAliveTime = lc::my_Duration(std::chrono::seconds(30));
        req.Scope.IncludedRecordings = {info.recording_token};

        lc::AnyElement topic_filter;
        topic_filter.local_name = "TopicExpression";
        topic_filter.attributes.emplace("Dialect", "http://www.onvif.org/ver10/tev/topicExpression/ConcreteSet");
        topic_filter.text_content = "tns1:RecordingHistory/Track/State";
        req.SearchFilter._any_.push_back(topic_filter);

        lc::AnyElement content_filter;
        content_filter.local_name = "MessageContentFilter";
        content_filter.text_content = R"(boolean(//tt:SimpleItem[@Name="IsDataPresent"]))";
        content_filter.attributes.emplace("Dialect", "http://www.onvif.org/ver10/tev/messageContentFilter/ItemFilter");
        req.SearchFilter._any_.push_back(content_filter);

        search->FindEvents(req,
            [this, guard, search, pt = profile_token](lc::OnvifResult<lc::tse_FindEventsResponse>&& result) {
                if (result.is_error()) {
                    std::cout << "FindEvents failed for " << pt << ": " << result.get_error_message() << "\n";
                    return;
                }

                auto search_token = result.data->SearchToken;
                if (search_token.empty()) return;

                auto all_events = std::make_shared<std::vector<lc::my_DateTime>>();
                auto iteration = std::make_shared<int>(0);

                auto do_paginate = [this, guard, search, search_token, pt, all_events, iteration](auto&& self) -> void {

                    lc::tse_GetEventSearchResults input;
                    input.SearchToken = search_token;
                    input.MaxResults = 1000;
                    input.WaitTime = lc::my_Duration(std::chrono::seconds(5));

                    search->GetEventSearchResultsCustom(input,
                        [this, self = std::forward<decltype(self)>(self), pt, all_events, guard]
                        (lc::OnvifResult<onvif_demo::demo_GetEventSearchResultsResponse>&& result) -> void {
                            if (result.is_error()) {
                                std::cout << "GetEventSearchResults failed for " << pt << ": " << result.get_error_message() << "\n";
                                return;
                            }

                            for (auto& ev : result.data->ResultList.Result) {
                                if (!ev.Event.Message.Message || !ev.Event.Message.Message->Data) continue;
                                for (auto& item : ev.Event.Message.Message->Data->SimpleItem) {
                                    if (item.Name != "IsDataPresent") continue;
                                    if (item.Value == "true") {
                                        all_events->push_back(ev.Time);
                                    }
                                    break;
                                }
                            }

                            if (result.data->ResultList.SearchState == lc::tt_SearchState::Completed || result.data->ResultList.SearchState == lc::tt_SearchState::Unknown) {
                                auto& profile = profile_infos_[pt];
                                profile.record_files.clear();

                                std::sort(all_events->begin(), all_events->end(),
                                    [](const lc::my_DateTime& a, const lc::my_DateTime& b) {
                                        return a.microSecondsSinceEpoch() < b.microSecondsSinceEpoch();
                                    });
                                all_events->erase(std::unique(all_events->begin(), all_events->end(),
                                    [](const lc::my_DateTime& a, const lc::my_DateTime& b) {
                                        return a.microSecondsSinceEpoch() == b.microSecondsSinceEpoch();
                                    }), all_events->end());

                                for (size_t i = 0; i + 1 < all_events->size(); ++i) {
                                    profile.record_files.push_back({(*all_events)[i], (*all_events)[i + 1]});
                                }
                            } else {
                                self(self);
                            }
                        });
                };
                do_paginate(do_paginate);
            });
    }
}

// ============================================================================
void OnvifDemoRunner::step_query_recording_job(DoneCallback done) {
    auto recording = onvif_client_->create_service<lc::RecordingPortClient>();


    if (!recording) {
        std::cout << "Recording service not available, skipping\n";
        step_print_services(std::move(done));
        return;
    }

    auto guard = make_guard([this, done, recording]() {
        for (const auto &profile : profile_infos_) {
            if (profile.second.recording_token.empty()) continue;
            std::cout << "Profile: " << profile.first
            << ", RecordingJob: " << profile.second.recording_job_token
            << ", RecordingToken: " << profile.second.recording_token << "\n";
        }

        step_qeury_recordings(std::move(done));
    });

    print_separator("Recording Segments");

    lc::trc_GetRecordingJobs request;
    recording->GetRecordingJobs(request,
        [this, guard , recording](lc::OnvifResult<lc::trc_GetRecordingJobsResponse>&& result) {
            if (result.is_error())
                std::cout << "GetRecordingJobs failed: " << result.get_error_message() << "\n";
            else
                std::cout << "Got " << result.data->JobItem.size() << " recording jobs\n";

            for (auto &it : result.data->JobItem) {
                for (auto &source : it.JobConfiguration.Source) {
                    if (!source.SourceToken) continue;

                    auto profile = std::find_if(profile_infos_.begin(), profile_infos_.end(), [&](const std::pair<std::string, ProfileInfo> &info) {
                        if (source.SourceToken->Type == "http://www.onvif.org/ver10/schema/Receiver") {
                            return source.SourceToken->Token == info.second.receiver_token;
                        }
                        else return source.SourceToken->Token == info.first;
                    });
                    if (profile != profile_infos_.end()) {
                        profile->second.recording_token = it.JobConfiguration.RecordingToken;
                        profile->second.recording_job_token = it.JobToken;
                    }
                }
            }
        });
}


// ============================================================================
void OnvifDemoRunner::step_print_services(DoneCallback done) {
    print_separator("Available Services");
    for (const auto& [name, endpoint] : onvif_client_->get_available_services())
        std::cout << name << ": " << endpoint << "\n";

    print_separator("Print Record");

    for (auto &it : profile_infos_) {
        if (it.second.recording_token.empty()) continue;
        std::cout << "Profile: " << it.first
        << ", start_record: " << it.second.start_recording_time.to_string()
        << ", end_record: " << it.second.end_recording_time.to_string()
        << ", total_file: " <<it.second.record_files.size()
        << "\n";
    }


    print_separator("Demo Complete");


    std::cout << "All operations completed!\n\n";
    done();
}

} // namespace onvif_demo