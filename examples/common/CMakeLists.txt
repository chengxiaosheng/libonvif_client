# onvif_demo_common — shared business logic for ONVIF demo programs

add_library(onvif_demo_common STATIC
    onvif_demo_printers.cpp
    onvif_demo_custom_types.cpp
    onvif_demo_common.cpp
)

target_include_directories(onvif_demo_common PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(onvif_demo_common PUBLIC
    onvif_client
)