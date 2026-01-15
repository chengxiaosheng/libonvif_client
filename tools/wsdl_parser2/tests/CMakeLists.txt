cmake_minimum_required(VERSION 3.16)

# 测试源文件（排除main.cpp）
set(TEST_SOURCES
    ../src/config.cpp
    ../src/file_info.cpp
    ../src/downloader.cpp
    ../src/wsdl_parser.cpp
    ../src/type_generator.cpp
    ../src/client_generator.cpp
)

# 创建测试可执行文件
add_executable(test_basic 
    test_basic.cpp
    ${TEST_SOURCES}
)

# 包含目录
target_include_directories(test_basic PRIVATE 
    ../include
    ${LIBXML2_INCLUDE_DIRS}
)

# 链接库
target_link_libraries(test_basic 
    ${LIBXML2_LIBRARIES}
)

# 编译选项
target_compile_options(test_basic PRIVATE ${LIBXML2_CFLAGS_OTHER})

# 设置输出目录
set_target_properties(test_basic PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

# 添加测试
enable_testing()
add_test(NAME BasicFunctionality COMMAND test_basic)

message(STATUS "测试配置完成")