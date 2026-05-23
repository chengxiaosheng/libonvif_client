#include "onvif_demo_printers.h"

#include <iostream>
#include <iomanip>
#include <string>

namespace onvif_demo {
namespace {

namespace lc = libonvif_client;

} // anonymous namespace

void print_separator(const std::string& title) {
    std::cout << "\n" << std::string(80, '=') << "\n";
    if (!title.empty()) {
        std::cout << "  " << title << "\n";
        std::cout << std::string(80, '=') << "\n";
    }
}

void print_device_info(const lc::tds_GetDeviceInformationResponse& info) {
    print_separator("Device Information");
    std::cout << "Manufacturer:  " << info.Manufacturer << "\n";
    std::cout << "Model:         " << info.Model << "\n";
    std::cout << "Firmware:      " << info.FirmwareVersion << "\n";
    std::cout << "Serial:        " << info.SerialNumber << "\n";
    std::cout << "Hardware ID:   " << info.HardwareId << "\n";
}

void print_datetime(const lc::tt_DateTime& dt, const std::string& label) {
    std::cout << label << ": "
              << std::setfill('0') << std::setw(4) << dt.Date.Year << "-"
              << std::setw(2) << dt.Date.Month << "-"
              << std::setw(2) << dt.Date.Day << " "
              << std::setw(2) << dt.Time.Hour << ":"
              << std::setw(2) << dt.Time.Minute << ":"
              << std::setw(2) << dt.Time.Second << "\n";
}

void print_system_datetime(const lc::tds_GetSystemDateAndTimeResponse& response) {
    print_separator("System Date & Time");

    const auto& sdt = response.SystemDateAndTime;

    std::cout << "Type: "
              << (sdt.DateTimeType == lc::tt_SetDateTimeType::NTP ? "NTP" : "Manual") << "\n";
    std::cout << "DST:   " << (sdt.DaylightSavings ? "Yes" : "No") << "\n";

    if (sdt.TimeZone) {
        std::cout << "Timezone: " << sdt.TimeZone->TZ << "\n";
    }

    if (sdt.UTCDateTime) {
        print_datetime(*sdt.UTCDateTime, "UTC");
    }

    if (sdt.LocalDateTime) {
        print_datetime(*sdt.LocalDateTime, "Local");
    }
}

void print_video_encoder_config(const lc::tt_VideoEncoderConfiguration& config) {
    std::cout << "    VideoEncoder:\n";
    std::cout << "      Name: " << config.Name << "\n";
    std::cout << "      Token: " << config.token << "\n";

    std::string encoding;
    switch (config.Encoding) {
        case lc::tt_VideoEncoding::JPEG: encoding = "JPEG"; break;
        case lc::tt_VideoEncoding::MPEG4: encoding = "MPEG4"; break;
        case lc::tt_VideoEncoding::H264: encoding = "H264"; break;
        default: encoding = "Unknown"; break;
    }
    std::cout << "      Encoding: " << encoding << "\n";

    std::cout << "      Resolution: " << config.Resolution.Width << "x"
              << config.Resolution.Height << "\n";
}

void print_profile(const lc::tt_Profile& profile, int index) {
    std::cout << "\nProfile #" << index << ":\n";
    std::cout << "  Name: " << profile.Name << "\n";
    std::cout << "  Token: " << profile.token << "\n";

    if (profile.fixed) {
        std::cout << "  Fixed: " << (*profile.fixed ? "Yes" : "No") << "\n";
    }

    if (profile.VideoEncoderConfiguration) {
        print_video_encoder_config(*profile.VideoEncoderConfiguration);
    }

    if (profile.PTZConfiguration) {
        std::cout << "    PTZ: Supported\n";
        std::cout << "      Name: " << profile.PTZConfiguration->Name << "\n";
    }
}

void print_profiles(const lc::trt_GetProfilesResponse& response) {
    print_separator("Media Profiles");
    std::cout << "Total profiles: " << response.Profiles.size() << "\n";

    int index = 1;
    for (const auto& profile : response.Profiles) {
        print_profile(profile, index++);
    }
}

std::string osd_type_to_string(lc::tt_OSDType type) {
    switch (type) {
        case lc::tt_OSDType::Text: return "Text";
        case lc::tt_OSDType::Image: return "Image";
        case lc::tt_OSDType::Extended: return "Extended";
        default: return "Unknown";
    }
}

void print_osd_config(const lc::tt_OSDConfiguration& osd, int index) {
    std::cout << "\nOSD #" << index << ":\n";
    std::cout << "  Token: " << osd.token << "\n";
    std::cout << "  Type: " << osd_type_to_string(osd.Type) << "\n";
    std::cout << "  VideoSourceToken: " << osd.VideoSourceConfigurationToken.value << "\n";

    std::cout << "  Position:\n";
    std::cout << "    Type: " << osd.Position.Type << "\n";
    if (osd.Position.Pos) {
        std::cout << "    X: " << osd.Position.Pos->x << "\n";
        std::cout << "    Y: " << osd.Position.Pos->y << "\n";
    }

    if (osd.TextString && osd.Type == lc::tt_OSDType::Text) {
        std::cout << "  TextString:\n";
        std::cout << "    Type: " << osd.TextString->Type << "\n";
        if (osd.TextString->DateFormat) {
            std::cout << "    DateFormat: " << *osd.TextString->DateFormat << "\n";
        }
        if (osd.TextString->TimeFormat) {
            std::cout << "    TimeFormat: " << *osd.TextString->TimeFormat << "\n";
        }
        if (osd.TextString->FontSize) {
            std::cout << "    FontSize: " << *osd.TextString->FontSize << "\n";
        }
        if (osd.TextString->FontColor) {
            std::cout << "    FontColor: R=" << (int)osd.TextString->FontColor->Color.X
                      << " G=" << (int)osd.TextString->FontColor->Color.Y
                      << " B=" << (int)osd.TextString->FontColor->Color.Z << "\n";
        }
        if (osd.TextString->BackgroundColor) {
            std::cout << "    BackgroundColor: R=" << (int)osd.TextString->BackgroundColor->Color.X
                      << " G=" << (int)osd.TextString->BackgroundColor->Color.Y
                      << " B=" << (int)osd.TextString->BackgroundColor->Color.Z << "\n";
        }
        if (osd.TextString->PlainText) {
            std::cout << "    PlainText: " << *osd.TextString->PlainText << "\n";
        }
    }

    if (osd.Image && osd.Type == lc::tt_OSDType::Image) {
        std::cout << "  Image:\n";
        std::cout << "    ImgPath: " << osd.Image->ImgPath << "\n";
    }
}

} // namespace onvif_demo