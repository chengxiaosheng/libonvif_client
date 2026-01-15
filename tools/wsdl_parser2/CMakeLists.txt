cmake_minimum_required(VERSION 3.16)
project(wsdl_parser2 VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找依赖库
find_package(LibXml2 REQUIRED)

# 查找 jsoncpp，如果找不到则使用 FetchContent 下载
find_package(jsoncpp QUIET)
if(NOT jsoncpp_FOUND)
    message(STATUS "jsoncpp 未找到，使用 FetchContent 下载...")
    include(FetchContent)

    FetchContent_Declare(
        jsoncpp
        GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
        GIT_TAG 1.9.6  # 稳定版本
        GIT_SHALLOW TRUE
    )

    # 设置 jsoncpp 选项
    set(JSONCPP_WITH_TESTS OFF CACHE BOOL "" FORCE)
    set(JSONCPP_WITH_POST_BUILD_UNITTEST OFF CACHE BOOL "" FORCE)
    set(JSONCPP_WITH_WARNING_AS_ERROR OFF CACHE BOOL "" FORCE)
    set(JSONCPP_WITH_PKGCONFIG_SUPPORT OFF CACHE BOOL "" FORCE)
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
    set(JSONCPP_WITH_CMAKE_PACKAGE OFF CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(jsoncpp)

    message(STATUS "jsoncpp 已下载: ${jsoncpp_SOURCE_DIR}")
endif()


# 源文件
set(WSDL_PARSER2_SOURCES
    src/config.cpp
    src/file_info.cpp
    src/downloader.cpp
    src/type_utils.cpp
    src/wsdl_parser.cpp
    src/type_generator.cpp
    src/client_generator.cpp
    src/main.cpp
)

# 创建可执行文件
add_executable(wsdl_parser2 ${WSDL_PARSER2_SOURCES})

# 包含目录
target_include_directories(wsdl_parser2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
# 链接库（处理系统安装和 FetchContent 两种情况）
if(TARGET JsonCpp::JsonCpp)
    target_link_libraries(wsdl_parser2 PRIVATE LibXml2::LibXml2 JsonCpp::JsonCpp)
elseif(TARGET jsoncpp_lib)
    target_link_libraries(wsdl_parser2 PRIVATE LibXml2::LibXml2 jsoncpp_lib)
else()
    message(FATAL_ERROR "无法找到 jsoncpp 目标")
endif()

if (UNIX)
    target_compile_options(wsdl_parser2 PRIVATE
            "-fPIC"
            "-Wall"
            "-Wextra"
            "-Wno-unused-function"
            "-Wno-unused-parameter"
            "-Wno-unused-variable"
            "-Wno-error=extra"
            "-Wno-error=missing-field-initializers"
            "-Wno-error=type-limits"
    )
elseif (WIN32)
    target_compile_options(wsdl_parser2 INTERFACE "/utf-8")
    target_compile_options(wsdl_parser2 INTERFACE "/wd4251" "/wd4275")
    if(MSVC)
        target_compile_options(wsdl_parser2 INTERFACE "$<$<C_COMPILER_ID:MSVC>:/utf-8>")
        target_compile_options(wsdl_parser2 INTERFACE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
        target_compile_options(wsdl_parser2 INTERFACE "/EHsc")
        add_compile_options("/EHsc")
        if (MSVC_VERSION GREATER_EQUAL 1914)
            # Tells Visual Studio 2017 (15.7+) and newer to correctly set the value of the standard __cplusplus macro,
            # instead of leaving it to 199711L and settings the effective c++ version in _MSVC_LANG
            # Dropping support for older versions of VS would allow to only rely on __cplusplus
            target_compile_options(wsdl_parser2 INTERFACE "/Zc:__cplusplus")
        endif()
    elseif (CMAKE_GENERATOR MATCHES "Ninja")
        set(CMAKE_GENERATOR_PLATFORM "x64" CACHE STRING "Force x64 for Ninja" FORCE)
    endif ()
    set(CMAKE_MSVC_RUNTIME_LIBRARY_DEBUG "MultiThreadedDebugDLL")    # Debug: /MDd
    set(CMAKE_MSVC_RUNTIME_LIBRARY_RELEASE "MultiThreaded")       # Release: /MD
endif ()


# 编译选项
target_compile_options(wsdl_parser2 PRIVATE ${LIBXML2_CFLAGS_OTHER})

# 创建测试（可选）
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

# 打印配置信息
message(STATUS "wsdl_parser2 配置:")
message(STATUS "  - C++标准: ${CMAKE_CXX_STANDARD}")
message(STATUS "  - libxml2版本: ${LIBXML2_VERSION}")
if(jsoncpp_FOUND)
    message(STATUS "  - jsoncpp: 系统安装")
elseif(TARGET jsoncpp_lib)
    message(STATUS "  - jsoncpp: FetchContent (自动下载)")
endif()
message(STATUS "  - 构建测试: ${BUILD_TESTS}")