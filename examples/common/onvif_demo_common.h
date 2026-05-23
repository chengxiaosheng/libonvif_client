#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>

#include <libonvif_client/core/onvif_client.h>
#include <libonvif_client/client/DeviceClient.h>
#include <libonvif_client/client/MediaClient.h>
#include <libonvif_client/client/Media2Client.h>
#include <libonvif_client/client/RecordingPortClient.h>
#include <libonvif_client/client/SearchPortClient.h>
#include <libonvif_client/client/ReceiverPortClient.h>

#include "onvif_demo_printers.h"
#include "onvif_demo_custom_types.h"

namespace onvif_demo {

struct RecordFiles {
    libonvif_client::my_DateTime start_time;
    libonvif_client::my_DateTime end_time;
};

struct ProfileInfo {
    std::string stream_uri;
    std::string video_source_token;
    std::string recording_token;  // from GetRecordingJobs
    std::string recording_job_token;
    std::string receiver_token; //

    libonvif_client::my_DateTime start_recording_time;
    libonvif_client::my_DateTime end_recording_time;
    std::vector<RecordFiles> record_files;
};




using DoneCallback = std::function<void()>;

class OnvifDemoRunner {
public:
    explicit OnvifDemoRunner(std::shared_ptr<libonvif_client::OnvifClient> client);

    void start(DoneCallback done);

private:
    std::shared_ptr<libonvif_client::OnvifClient> onvif_client_;
    std::map<std::string, ProfileInfo> profile_infos_;

    void step_initialize(DoneCallback done);
    void step_get_device_info(DoneCallback done);
    void step_get_system_datetime(DoneCallback done);
    void step_get_capabilities(DoneCallback done);
    void step_get_hostname(DoneCallback done);
    void step_get_profiles(DoneCallback done);
    void step_query_recording_job(DoneCallback done);
    void step_query_receiver(DoneCallback done);
    void step_qeury_recordings(DoneCallback done);
    void step_query_recording_events(DoneCallback done);
    void step_print_services(DoneCallback done);
};

} // namespace onvif_demo
