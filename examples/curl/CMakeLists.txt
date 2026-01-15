# ========================================================================
# libcurl HTTP 客户端示例
# ========================================================================

find_package(CURL QUIET)

# 只有找到 libcurl 时才构建示例
if(CURL_FOUND OR TARGET CURL::libcurl)
    add_executable(onvif_client_curl_demo
            curl_demo.cpp
            curl_http_client.cpp
    )

    # 包含目录
    target_include_directories(onvif_client_curl_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

    # 链接库
    target_link_libraries(onvif_client_curl_demo PRIVATE
            onvif_client
            CURL::libcurl
    )

    # header-only 模板库优化
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        # 链接时优化（对模板库特别有效）
        target_compile_options(onvif_client_curl_demo PRIVATE
            -flto
        )
        target_link_options(onvif_client_curl_demo PRIVATE
            -flto
        )
        # 更积极的内联
        target_compile_options(onvif_client_curl_demo PRIVATE
            $<$<COMPILE_LANGUAGE:CXX>:-finline-functions>
        )
    endif()

    # 安装（可选）
    install(TARGETS onvif_client_curl_demo
        RUNTIME DESTINATION bin
    )

    message(STATUS "Curl example: enabled")
else()
    message(STATUS "Curl example: disabled - libcurl not found")
endif()
