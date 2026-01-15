cmake_minimum_required(VERSION 3.16)
project(onvif_client VERSION 1.0.0)

option(BUILD_TOOLS "Build code generation tools (wsdl_parser2)" OFF)
option(BUILD_EXAMPLES "Build example programs" ON)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找依赖 - 只依赖 LibXml2
find_package(LibXml2 REQUIRED)

add_library(${PROJECT_NAME} INTERFACE)

# 传递依赖给使用者
target_link_libraries(${PROJECT_NAME} INTERFACE LibXml2::LibXml2)

# 导出头文件路径
target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 头文件安装
install(DIRECTORY include/ DESTINATION include)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/onvif_client.pc
    DESTINATION lib/pkgconfig
)

# 可选：代码生成工具（仅开发时需要）
if(BUILD_TOOLS)
    add_subdirectory(tools/wsdl_parser2)
endif()

# 可选：示例程序
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()