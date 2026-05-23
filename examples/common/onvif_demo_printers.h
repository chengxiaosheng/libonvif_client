#pragma once

#include <string>

#include <libonvif_client/types/tds.h>
#include <libonvif_client/types/tt.h>
#include <libonvif_client/types/trt.h>

namespace onvif_demo {

void print_separator(const std::string& title = "");

void print_device_info(const libonvif_client::tds_GetDeviceInformationResponse& info);

void print_datetime(const libonvif_client::tt_DateTime& dt, const std::string& label);

void print_system_datetime(const libonvif_client::tds_GetSystemDateAndTimeResponse& response);

void print_video_encoder_config(const libonvif_client::tt_VideoEncoderConfiguration& config);

void print_profile(const libonvif_client::tt_Profile& profile, int index);

void print_profiles(const libonvif_client::trt_GetProfilesResponse& response);

std::string osd_type_to_string(libonvif_client::tt_OSDType type);

void print_osd_config(const libonvif_client::tt_OSDConfiguration& osd, int index);

} // namespace onvif_demo