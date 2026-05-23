/**
 * @file drogon_demo.cpp
 * @brief ONVIF client demo using Drogon HTTP transport
 *
 * Usage: ./drogon_demo <device_url> <username> <password>
 */

#include <iostream>
#include <memory>

#include <libonvif_client/core/onvif_client.h>
#include <drogon/drogon.h>
#include "drogon_http_client.h"
#include "common/onvif_demo_common.h"

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Usage: " << argv[0] << " <device_url> <username> <password>\n";
        return 1;
    }

    auto http_client = std::make_shared<libonvif_client::DrogonHttpClient>(false);

    auto onvif_client = std::make_shared<libonvif_client::OnvifClient>(
        argv[1], argv[2], argv[3], http_client);

    auto runner = std::make_shared<onvif_demo::OnvifDemoRunner>(onvif_client);

    drogon::app().registerBeginningAdvice([runner]() {
        runner->start([]() {
            drogon::app().quit();
        });
    });
    drogon::app().run();
    return 0;
}