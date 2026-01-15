# WSDL Parser 2.0

一个强大且高效的 ONVIF WSDL/XSD 解析工具，用于自动生成 C++ 类型定义和服务客户端代码。

## 📋 目录

- [功能特性](#功能特性)
- [系统要求](#系统要求)
- [编译安装](#编译安装)
- [快速开始](#快速开始)
- [使用方法](#使用方法)
- [配置文件](#配置文件)
- [生成的代码](#生成的代码)
- [示例](#示例)
- [故障排查](#故障排查)

## ✨ 功能特性

- **自动解析** - 支持 WSDL 和 XSD 文件的自动解析
- **依赖管理** - 自动处理文件间的依赖关系
- **网络支持** - 支持从网络 URL 下载和解析文件
- **智能缓存** - 自动缓存已下载的文件，避免重复下载
- **类型生成** - 生成完整的 C++ 类型定义（结构体、枚举、类型别名）
- **客户端生成** - 生成服务客户端代码，包含自动注册功能
- **命名空间映射** - 灵活的命名空间到 C++ 类型的映射
- **文档支持** - 保留 WSDL/XSD 中的文档注释
- **跨平台** - 支持 Linux、Windows、macOS

## 📦 系统要求

### 必需依赖

- **C++17** 或更高版本
- **CMake** 3.16+
- **libxml2** - XML 解析库
- **jsoncpp** - JSON 配置文件解析

### 可选依赖

- **curl** - 用于网络文件下载（建议安装）

## 🔧 编译安装

### Linux/macOS

```bash
# 安装依赖
# Ubuntu/Debian
sudo apt-get install libxml2-dev libjsoncpp-dev libcurl4-openssl-dev

# macOS
brew install libxml2 jsoncpp curl

# 编译
mkdir build && cd build
cmake ..
make -j$(nproc)

# 可执行文件位于 build/wsdl_parser2
```

### Windows

```powershell
# 使用 vcpkg 安装依赖
vcpkg install libxml2:x64-windows jsoncpp:x64-windows curl:x64-windows

# 编译
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake
cmake --build . --config Release

# 可执行文件位于 build\Release\wsdl_parser2.exe
```

## 🚀 快速开始

### 基本用法

```bash
# 解析单个 WSDL 文件
./wsdl_parser2 devicemgmt.wsdl

# 解析多个文件
./wsdl_parser2 devicemgmt.wsdl media.wsdl ptz.wsdl

# 从网络 URL 解析
./wsdl_parser2 https://www.onvif.org/ver10/device/wsdl/devicemgmt.wsdl
```

### 使用配置文件

```bash
# 使用自定义配置
./wsdl_parser2 -c config.json devicemgmt.wsdl

# 指定缓存目录
./wsdl_parser2 --cache-dir ./cache devicemgmt.wsdl

# 仅生成类型定义
./wsdl_parser2 --types-only common.xsd

# 仅生成客户端代码
./wsdl_parser2 --clients-only devicemgmt.wsdl

# 启用详细输出
./wsdl_parser2 -v devicemgmt.wsdl
```

## 📖 使用方法

### 命令行选项

```
用法:
    wsdl_parser2 [选项] <wsdl_file>...

参数:
    <wsdl_file>...          要解析的 WSDL/XSD 文件（支持多个）

选项:
    -h, --help              显示帮助信息
    -v, --verbose           启用详细输出
    -o, --output <dir>      输出目录 (默认: ./generated)
    -c, --config <file>     配置文件路径 (默认: ./config.json)
    --cache-dir <dir>       缓存目录 (默认: ./cache)
    --types-only            仅生成类型定义
    --clients-only          仅生成客户端代码
    --ignore-missing-deps   忽略缺失的依赖文件
```

### 典型工作流程

1. **准备配置文件** - 根据项目需求配置命名空间映射
2. **运行解析器** - 解析 WSDL/XSD 文件
3. **检查生成的代码** - 验证生成的头文件和源文件
4. **集成到项目** - 将生成的代码添加到你的项目中
5. **链接库** - 确保链接 `libonvif_client` 库

## ⚙️ 配置文件

配置文件使用 JSON 格式，用于定制解析器的行为和输出。

### 配置文件结构

```json
{
  "output_types_header_dir": "./include/types",
  "output_client_header_dir": "./include/client",
  "output_client_source_dir": "./src/client",
  "cache_dir": "./cache",
  "generate_types": true,
  "generate_clients": true,
  "verbose": false,
  "ignore_missing_deps": false,
  "detect_duplicates": true,
  "smart_merge": true,
  "client_namespace": "libonvif_client",
  "schema_configs": [
    {
      "comment": "ONVIF核心Schema",
      "ns_url": "http://www.onvif.org/ver10/schema",
      "ns_prefix": "tt",
      "output_name": "common",
      "source_files": ["common.xsd"],
      "priority": 10
    },
    {
      "comment": "ONVIF设备管理服务",
      "ns_url": "http://www.onvif.org/ver10/device/wsdl",
      "ns_prefix": "tds",
      "output_name": "device",
      "source_files": ["devicemgmt.wsdl"],
      "priority": 9
    }
  ]
}
```

### 配置选项说明

#### 基本选项

- **output_types_header_dir** - 类型定义头文件输出目录
- **output_client_header_dir** - 客户端头文件输出目录
- **output_client_source_dir** - 客户端源文件输出目录
- **cache_dir** - 网络文件缓存目录
- **generate_types** - 是否生成类型定义（默认: true）
- **generate_clients** - 是否生成客户端代码（默认: true）
- **verbose** - 是否启用详细输出（默认: false）
- **ignore_missing_deps** - 是否忽略缺失的依赖（默认: false）
- **detect_duplicates** - 是否检测重复类型（默认: true）
- **smart_merge** - 是否智能合并类型（默认: true）
- **client_namespace** - 客户端代码的命名空间

#### Schema 配置

每个 `schema_configs` 条目定义一个 WSDL/XSD 文件的处理方式：

- **comment** - 配置注释（可选）
- **ns_url** - 命名空间 URL（唯一标识）
- **ns_prefix** - 命名空间前缀（用于 C++ 类型名）
- **output_name** - 输出文件名前缀
- **source_files** - 源文件列表（可选，用于明确指定）
- **priority** - 优先级（用于排序，数值越大优先级越高）
- **dependencies** - 依赖的其他类型文件（可选）

### 命名空间映射规则

WSDL/XSD 命名空间会映射到 C++ 类型名：

| 命名空间前缀 | WSDL 命名空间 URL | C++ 类型前缀 | 示例 |
|-------------|------------------|-------------|------|
| `tt` | `http://www.onvif.org/ver10/schema` | `tt_` | `tt_VideoSource` |
| `tds` | `http://www.onvif.org/ver10/device/wsdl` | `tds_` | `tds_GetDeviceInformation` |
| `trt` | `http://www.onvif.org/ver10/media/wsdl` | `trt_` | `trt_GetProfiles` |
| `tptz` | `http://www.onvif.org/ver20/ptz/wsdl` | `tptz_` | `tptz_ContinuousMove` |

## 📝 生成的代码

### 类型定义文件

生成的类型文件包含：

```cpp
// common.h - ONVIF 核心类型
namespace libonvif_client {

// 结构体
struct tt_VideoSource {
    std::string token;
    tt_VideoResolution resolution;
    // ... 字段定义
};

// 枚举
enum class tt_VideoEncoding {
    JPEG,
    MPEG4,
    H264
};

// 类型别名
using tt_ReferenceToken = std::string;

} // namespace libonvif_client
```

### 客户端代码文件

生成的客户端包含：

```cpp
// DeviceClient.h
class DeviceClient : public OnvifServiceBase {
public:
    DeviceClient(const std::string& service_url,
                 const std::shared_ptr<IHttpClient> &http_client,
                 const std::string& username = "",
                 const std::string& password = "");

    void GetDeviceInformation(
        const tds_GetDeviceInformation& request,
        OnvifCallback<tds_GetDeviceInformationResponse> callback);

    // ... 其他操作方法
};
```

### 自动注册机制

生成的客户端会自动注册到 `ServiceClientFactory`：

```cpp
// DeviceClient.cpp
static ServiceClientRegistrar tds_service_registrar(
    "http://www.onvif.org/ver10/device/wsdl",
    "tds",
    [](const std::string& endpoint, const std::shared_ptr<IHttpClient> &http_client,
       const std::string& username, const std::string& password)
       -> std::shared_ptr<OnvifServiceBase> {
        return std::make_shared<DeviceClient>(
            endpoint, http_client, username, password);
    }
);
```

## 💡 示例

### 示例 1: 生成 ONVIF 设备管理客户端

```bash
# 1. 准备配置文件 config.json
cat > config.json << EOF
{
  "output_types_header_dir": "./include/types",
  "output_client_header_dir": "./include/client",
  "output_client_source_dir": "./src/client",
  "generate_types": true,
  "generate_clients": true,
  "schema_configs": [
    {
      "ns_url": "http://www.onvif.org/ver10/schema",
      "ns_prefix": "tt",
      "output_name": "common"
    },
    {
      "ns_url": "http://www.onvif.org/ver10/device/wsdl",
      "ns_prefix": "tds",
      "output_name": "device"
    }
  ]
}
EOF

# 2. 运行解析器
./wsdl_parser2 -c config.json devicemgmt.wsdl

# 3. 输出
# ✅ 生成了 2 个类型文件
#   - include/types/common.h
#   - include/types/device.h
# ✅ 生成了 1 个客户端
#   - include/client/DeviceClient.h
#   - src/client/DeviceClient.cpp
```

### 示例 2: 批量生成所有 ONVIF 服务

```bash
# 从 ONVIF 官网下载所有 WSDL 文件
WSDL_BASE="https://www.onvif.org/ver10"

./wsdl_parser2 -c config.json \
    ${WSDL_BASE}/device/wsdl/devicemgmt.wsdl \
    ${WSDL_BASE}/media/wsdl/media.wsdl \
    ${WSDL_BASE}/ptz/wsdl/ptz.wsdl \
    ${WSDL_BASE}/imaging/wsdl/imaging.wsdl \
    ${WSDL_BASE}/analytics/wsdl/analytics.wsdl \
    ${WSDL_BASE}/recording/wsdl/recording.wsdl
```

### 示例 3: 仅生成类型定义

```bash
# 仅解析 XSD 文件，不生成客户端
./wsdl_parser2 --types-only \
    common.xsd \
    onvif.xsd \
    metadatastream.xsd
```

### 示例 4: 使用生成的代码

```cpp
// main.cpp - 使用生成的客户端代码
#include "client/DeviceClient.h"
#include "transport/drogon_http_client.h"
#include <iostream>

using namespace libonvif_client;

int main() {
    // 1. 创建 HTTP 客户端
    auto http_client = std::make_unique<DrogonHttpClient>();

    // 2. 创建设备客户端
    DeviceClient device_client(
        "http://192.168.1.100/onvif/device_service",
        *http_client,
        "admin",
        "password"
    );

    // 3. 调用 GetDeviceInformation
    tds_GetDeviceInformation request;

    device_client.GetDeviceInformation(request,
        [](const tds_GetDeviceInformationResponse* response,
           const OnvifError* error) {
            if (error) {
                std::cerr << "Error: " << error->message << std::endl;
                return;
            }

            std::cout << "Manufacturer: " << response->Manufacturer << std::endl;
            std::cout << "Model: " << response->Model << std::endl;
            std::cout << "Serial Number: " << response->SerialNumber << std::endl;
        });

    return 0;
}
```

## 🔍 故障排查

### 常见问题

#### 1. 找不到 libxml2

**错误信息:**
```
CMake Error: Could not find LibXml2
```

**解决方法:**
```bash
# Ubuntu/Debian
sudo apt-get install libxml2-dev

# macOS
brew install libxml2

# Windows (vcpkg)
vcpkg install libxml2:x64-windows
```

#### 2. 网络文件下载失败

**错误信息:**
```
❌ 解析失败: Failed to download file from URL
```

**解决方法:**
- 检查网络连接
- 使用 `--cache-dir` 指定缓存目录
- 手动下载文件并使用本地路径
- 安装 curl 库

#### 3. 依赖文件缺失

**错误信息:**
```
⚠️ 警告信息:
  - Missing dependency: common.xsd
```

**解决方法:**
- 使用 `--ignore-missing-deps` 选项忽略警告
- 手动下载缺失的依赖文件
- 在配置文件中正确配置依赖关系

#### 4. 命名空间冲突

**错误信息:**
```
Duplicate type name detected
```

**解决方法:**
- 检查 `schema_configs` 中的 `ns_prefix` 设置
- 确保每个命名空间有唯一的前缀
- 使用 `detect_duplicates: false` 禁用重复检测（不推荐）

#### 5. 生成的代码编译错误

**可能原因:**
- 缺少必需的头文件
- 没有链接 `libonvif_client` 库
- C++ 标准版本不匹配

**解决方法:**
```cmake
# CMakeLists.txt
target_include_directories(your_target PRIVATE
    ${CMAKE_SOURCE_DIR}/generated/include)
target_link_libraries(your_target PRIVATE onvif_client)
set_target_properties(your_target PROPERTIES CXX_STANDARD 17)
```

### 调试技巧

#### 启用详细输出

```bash
./wsdl_parser2 -v devicemgmt.wsdl
```

详细输出会显示：
- 文件解析过程
- 命名空间映射
- 类型定义详情
- 依赖关系解析
- 代码生成过程

#### 检查配置

```bash
# 显示当前配置
cat config.json | jq .

# 验证 JSON 格式
jq . config.json
```

#### 单独测试

```bash
# 先只生成类型定义
./wsdl_parser2 --types-only common.xsd

# 确认无误后再生成客户端
./wsdl_parser2 --clients-only devicemgmt.wsdl
```

## 📚 进阶主题

### 自定义类型映射

在配置文件中可以添加自定义类型映射：

```json
{
  "type_mappings": {
    "xs:dateTime": "std::chrono::system_clock::time_point",
    "xs:duration": "std::chrono::seconds",
    "xs:base64Binary": "std::vector<uint8_t>"
  }
}
```

### 代码生成钩子

可以通过修改模板来定制生成的代码：

1. 编辑 `type_generator.cpp` 中的模板
2. 编辑 `client_generator.cpp` 中的模板
3. 重新编译 wsdl_parser2

### 批处理脚本

创建批处理脚本自动生成所有 ONVIF 服务：

```bash
#!/bin/bash
# generate_onvif_all.sh

WSDL_DIR="./specs/wsdl"
OUTPUT_DIR="./generated"

./wsdl_parser2 -c config.json \
    -o ${OUTPUT_DIR} \
    ${WSDL_DIR}/ver10/device/wsdl/devicemgmt.wsdl \
    ${WSDL_DIR}/ver10/media/wsdl/media.wsdl \
    ${WSDL_DIR}/ver20/ptz/wsdl/ptz.wsdl \
    # ... 添加更多 WSDL 文件
```

## 📄 许可证

本项目遵循与 OpenMediaServer 相同的许可证。

## 🤝 贡献

欢迎提交 Issue 和 Pull Request！

## 📮 联系方式

如有问题或建议，请通过以下方式联系：
- GitHub Issues
- 项目维护者

---

**注意**: 本工具专为 ONVIF 标准设计，对其他 WSDL/XSD 文件的支持可能有限。
