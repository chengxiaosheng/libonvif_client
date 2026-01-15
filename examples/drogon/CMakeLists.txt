# ========================================================================
# Drogon HTTP 客户端示例
# ========================================================================

# 查找 drogon（可能是系统安装或用户指定的）
find_package(drogon QUIET)

# 只有找到 drogon 时才构建示例
if(drogon_FOUND OR TARGET drogon)
    add_executable(onvif_client_demo
            demo.cpp
            drogon_http_client.cpp
    )

    # 包含目录
    target_include_directories(onvif_client_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

    # 链接库
    target_link_libraries(onvif_client_demo PRIVATE
            onvif_client
            drogon
    )

    # header-only 模板库优化
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        # 链接时优化（对模板库特别有效）
        target_compile_options(onvif_client_demo PRIVATE
            -flto
        )
        target_link_options(onvif_client_demo PRIVATE
            -flto
        )
        # 更积极的内联
        target_compile_options(onvif_client_demo PRIVATE
            $<$<COMPILE_LANGUAGE:CXX>:-finline-functions>
        )
    endif()

    # 安装（可选）
    install(TARGETS onvif_client_demo
        RUNTIME DESTINATION bin
    )

    message(STATUS "Drogon example: enabled")
else()
    message(STATUS "Drogon example: disabled - drogon not found")
endif()