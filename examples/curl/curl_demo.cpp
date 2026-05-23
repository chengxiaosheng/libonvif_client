/**
 * @file curl_demo.cpp
 * @brief ONVIF client demo using libcurl HTTP transport
 *
 * Usage: ./curl_demo <device_url> <username> <password>
 */

#include <iostream>
#include <memory>
#include <future>

#include <libonvif_client/core/onvif_client.h>
#include "curl_http_client.h"
#include "common/onvif_demo_common.h"

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Usage: " << argv[0] << " <device_url> <username> <password>\n";
        return 1;
    }

    auto http_client = std::make_shared<libonvif_client::CurlHttpClient>(true, 4);
    http_client->set_ssl_verify(false);

    auto onvif_client = std::make_shared<libonvif_client::OnvifClient>(
        argv[1], argv[2], argv[3], http_client);

    onvif_demo::OnvifDemoRunner runner(onvif_client);

    // CurlHttpClient uses detached threads — need a barrier for program exit
    std::promise<void> done_promise;
    runner.start([&done_promise] {
        done_promise.set_value();
    });

    done_promise.get_future().wait();
    curl_global_cleanup();
    return 0;
}