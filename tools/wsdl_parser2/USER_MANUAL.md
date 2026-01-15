# WSDL Parser 2.0 使用手册

## 快速参考

### 基本命令

```bash
# 解析单个文件
./wsdl_parser2 file.wsdl

# 解析多个文件
./wsdl_parser2 file1.wsdl file2.wsdl file3.wsdl

# 使用配置文件
./wsdl_parser2 -c config.json file.wsdl

# 详细输出模式
./wsdl_parser2 -v file.wsdl
```

### 常用选项

| 选项 | 说明 | 示例 |
|------|------|------|
| `-h, --help` | 显示帮助 | `./wsdl_parser2 --help` |
| `-v, --verbose` | 详细输出 | `./wsdl_parser2 -v file.wsdl` |
| `-c, --config <file>` | 指定配置文件 | `./wsdl_parser2 -c my.json file.wsdl` |
| `--cache-dir <dir>` | 设置缓存目录 | `./wsdl_parser2 --cache-dir ./cache file.wsdl` |
| `--types-only` | 仅生成类型 | `./wsdl_parser2 --types-only file.xsd` |
| `--clients-only` | 仅生成客户端 | `./wsdl_parser2 --clients-only file.wsdl` |
| `--ignore-missing-deps` | 忽略缺失依赖 | `./wsdl_parser2 --ignore-missing-deps file.wsdl` |

## 配置文件模板

### 最小配置

```json
{
  "output_types_header_dir": "./include/types",
  "output_client_header_dir": "./include/client",
  "output_client_source_dir": "./src/client",
  "schema_configs": [
    {
      "ns_url": "http://www.onvif.org/ver10/device/wsdl",
      "ns_prefix": "tds",
      "output_name": "device"
    }
  ]
}
```

### 完整配置

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
      "comment": "配置说明（可选）",
      "ns_url": "命名空间URL（必需）",
      "ns_prefix": "命名空间前缀（必需）",
      "output_name": "输出文件名（必需）",
      "source_files": ["源文件列表（可选）"],
      "priority": 10,
      "dependencies": ["依赖列表（可选）"]
    }
  ]
}
```

## 典型使用场景

### 场景 1: 首次生成 ONVIF 代码

```bash
# 1. 准备工作目录
mkdir -p onvif_gen/{include,src,cache}
cd onvif_gen

# 2. 创建配置文件
cat > config.json << 'EOF'
{
  "output_types_header_dir": "./include/types",
  "output_client_header_dir": "./include/client",
  "output_client_source_dir": "./src/client",
  "cache_dir": "./cache",
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

# 3. 运行解析器
wsdl_parser2 -c config.json -v \
    https://www.onvif.org/ver10/device/wsdl/devicemgmt.wsdl
    
# 4. 查看生成的文件
tree include src

# 5. libonvif_client 
./wsdl_parser2 \
  https://www.onvif.org/ver10/device/wsdl/devicemgmt.wsdl \
  http://www.onvif.org/onvif/ver10/analyticsdevice.wsdl \
  http://www.onvif.org/onvif/ver10/replay.wsdl \
  http://www.onvif.org/onvif/ver10/search.wsdl \
  http://www.onvif.org/onvif/ver10/recording.wsdl \
  http://www.onvif.org/onvif/ver20/ptz/wsdl/ptz.wsdl \
  http://www.onvif.org/onvif/ver10/media/wsdl/media.wsdl \
  http://www.onvif.org/onvif/ver20/media/wsdl/media.wsdl \
  http://www.onvif.org/onvif/ver20/imaging/wsdl/imaging.wsdl \
  http://www.onvif.org/onvif/ver20/analytics/wsdl/analytics.wsdl \
  https://www.onvif.org/onvif/ver10/events/wsdl/event.wsdl
```

### 场景 2: 增量添加服务

```bash
# 已有 Device 服务，现在添加 Media 服务

# 1. 更新配置文件，添加 Media 配置
# 2. 运行解析器
wsdl_parser2 -c config.json \
    https://www.onvif.org/ver10/media/wsdl/media.wsdl

# 工具会自动跳过已生成的类型，仅生成新的 MediaClient
```

### 场景 3: 调试解析问题

```bash
# 使用详细模式查看详细信息
wsdl_parser2 -v -c config.json file.wsdl 2>&1 | tee parse.log

# 查看警告和错误
grep -E "警告|错误|Warning|Error" parse.log

# 检查生成的文件数量
find include src -type f | wc -l
```

### 场景 4: 批量生成所有 ONVIF 服务

```bash
#!/bin/bash
# generate_all_onvif.sh

BASE_URL="https://www.onvif.org"

wsdl_parser2 -c config.json -v \
    ${BASE_URL}/ver10/device/wsdl/devicemgmt.wsdl \
    ${BASE_URL}/ver10/media/wsdl/media.wsdl \
    ${BASE_URL}/ver20/ptz/wsdl/ptz.wsdl \
    ${BASE_URL}/ver20/imaging/wsdl/imaging.wsdl \
    ${BASE_URL}/ver20/analytics/wsdl/analytics.wsdl \
    ${BASE_URL}/ver10/recording/wsdl/recording.wsdl \
    ${BASE_URL}/ver10/replay/wsdl/replay.wsdl \
    ${BASE_URL}/ver10/search/wsdl/search.wsdl
```

## ONVIF 命名空间映射表

### 常用服务

| 服务名称 | 命名空间前缀 | 命名空间 URL | 文件前缀 |
|---------|------------|-------------|---------|
| 通用类型 | `tt` | `http://www.onvif.org/ver10/schema` | `common_`, `tt_` |
| 设备管理 | `tds` | `http://www.onvif.org/ver10/device/wsdl` | `tds_` |
| 媒体服务 v1.0 | `trt` | `http://www.onvif.org/ver10/media/wsdl` | `trt_` |
| 媒体服务 v2.0 | `tr2` | `http://www.onvif.org/ver20/media/wsdl` | `tr2_` |
| PTZ 控制 | `tptz` | `http://www.onvif.org/ver20/ptz/wsdl` | `tptz_` |
| 图像设置 | `timg` | `http://www.onvif.org/ver20/imaging/wsdl` | `timg_` |
| 事件服务 | `tev` | `http://www.onvif.org/ver10/events/wsdl` | `tev_` |
| 分析服务 | `tan` | `http://www.onvif.org/ver20/analytics/wsdl` | `tan_` |
| 分析设备 | `tad` | `http://www.onvif.org/ver10/analyticsdevice/wsdl` | `tad_` |
| 录像服务 | `trc` | `http://www.onvif.org/ver10/recording/wsdl` | `trc_` |
| 回放服务 | `trp` | `http://www.onvif.org/ver10/replay/wsdl` | `trp_` |
| 搜索服务 | `tse` | `http://www.onvif.org/ver10/search/wsdl` | `tse_` |

### 辅助命名空间

| 用途 | 前缀 | 命名空间 URL |
|------|-----|-------------|
| SOAP 封装 | `soapenv` | `http://www.w3.org/2003/05/soap-envelope` |
| WS-Addressing | `wsa` | `http://www.w3.org/2005/08/addressing` |
| WS-Notification | `wsnt` | `http://docs.oasis-open.org/wsn/b-2` |
| XML MIME | `xmime` | `http://www.w3.org/2005/05/xmlmime` |
| XOP Include | `xop` | `http://www.w3.org/2004/08/xop/include` |

## 生成代码结构

### 类型定义文件

```
include/types/
├── common.h          # tt_ 前缀的通用类型
├── device.h          # tds_ 前缀的设备类型
├── media.h           # trt_ 前缀的媒体类型
├── ptz.h             # tptz_ 前缀的 PTZ 类型
└── ...
```

### 客户端文件

```
include/client/
├── DeviceClient.h      # 设备管理客户端
├── MediaClient.h       # 媒体服务客户端
├── PTZClient.h         # PTZ 控制客户端
└── ...

src/client/
├── DeviceClient.cpp    # 设备管理客户端实现
├── MediaClient.cpp     # 媒体服务客户端实现
├── PTZClient.cpp       # PTZ 控制客户端实现
└── ...
```

## 代码使用示例

### 包含头文件

```cpp
// 包含类型定义
#include "types/common.h"
#include "types/device.h"
#include "types/media.h"

// 包含客户端
#include "client/DeviceClient.h"
#include "client/MediaClient.h"

// 包含框架
#include <libonvif_client/core/onvif_client.h>
#include <libonvif_client/transport/drogon_http_client.h>
```

### 使用生成的类型

```cpp
// 创建请求
tds_GetDeviceInformation request;

// 创建复杂类型
tt_VideoSource source;
source.token = "VideoSource_1";
source.Framerate = 25.0;

// 使用枚举
tt_VideoEncoding encoding = tt_VideoEncoding::H264;
```

### 使用生成的客户端

```cpp
// 方式 1: 直接使用客户端
auto http_client = std::make_unique<DrogonHttpClient>();
DeviceClient device_client(
    "http://192.168.1.100/onvif/device_service",
    *http_client,
    "admin",
    "password"
);

device_client.GetDeviceInformation(request,
    [](const tds_GetDeviceInformationResponse* response,
       const OnvifError* error) {
        if (error) {
            std::cerr << "Error: " << error->message << std::endl;
            return;
        }
        std::cout << "Model: " << response->Model << std::endl;
    });

// 方式 2: 通过 OnvifClient 自动管理
auto onvif_client = std::make_unique<OnvifClient>(
    std::move(http_client));

OnvifClient::Config config;
config.device_url = "http://192.168.1.100/onvif/device_service";
config.username = "admin";
config.password = "password";

onvif_client->connect(config,
    [&](bool success, const OnvifError* error) {
        if (!success) {
            std::cerr << "Connect failed: " << error->message << std::endl;
            return;
        }

        // 自动发现的服务可直接使用
        auto device = onvif_client->device();
        auto media = onvif_client->get_service_client<MediaClient>("trt");
    });
```

## CMake 集成

### 添加到项目

```cmake
# 包含生成的代码
target_include_directories(your_target PRIVATE
    ${CMAKE_SOURCE_DIR}/generated/include
)

# 添加源文件
file(GLOB GENERATED_SOURCES
    ${CMAKE_SOURCE_DIR}/generated/src/client/*.cpp
)
target_sources(your_target PRIVATE ${GENERATED_SOURCES})

# 链接库
target_link_libraries(your_target PRIVATE
    onvif_client
    LibXml2::LibXml2
)
```

## 常见问题速查

### Q1: 如何添加新的 ONVIF 服务？

1. 在 `config.json` 中添加服务配置
2. 运行 `wsdl_parser2 -c config.json new_service.wsdl`
3. 将生成的文件添加到项目中

### Q2: 生成的代码在哪里？

- 类型定义: `output_types_header_dir` 指定的目录
- 客户端头文件: `output_client_header_dir` 指定的目录
- 客户端源文件: `output_client_source_dir` 指定的目录

### Q3: 如何处理命名冲突？

- 修改 `ns_prefix` 使用不同的前缀
- 修改 `output_name` 生成不同的文件名

### Q4: 生成的代码需要哪些依赖？

- `libonvif_client` 框架库
- `LibXml2` XML 解析库
- C++17 编译器

### Q5: 如何更新已生成的代码？

- 删除旧的生成文件
- 重新运行 wsdl_parser2
- 或者使用 `--force` 选项（如果支持）

### Q6: 支持哪些 WSDL/XSD 版本？

- WSDL 1.1
- XSD 1.0/1.1
- ONVIF 标准所有版本

## 性能优化建议

### 1. 使用缓存

```bash
# 指定缓存目录，避免重复下载
wsdl_parser2 --cache-dir ~/.wsdl_cache file.wsdl
```

### 2. 分批生成

```bash
# 先生成基础类型
wsdl_parser2 --types-only common.xsd

# 再生成客户端
wsdl_parser2 --clients-only devicemgmt.wsdl
```

### 3. 并行处理

```bash
# 对于大量文件，可以并行处理
for file in *.wsdl; do
    wsdl_parser2 "$file" &
done
wait
```

## 调试技巧

### 启用详细日志

```bash
wsdl_parser2 -v file.wsdl 2>&1 | tee debug.log
```

### 检查配置

```bash
# 验证 JSON 格式
cat config.json | jq .

# 查看特定配置
cat config.json | jq '.schema_configs'
```

### 测试单个文件

```bash
# 先测试最小示例
wsdl_parser2 --types-only simple.xsd

# 确认无误后处理复杂文件
wsdl_parser2 -v complex.wsdl
```

## 资源链接

- **ONVIF 官网**: https://www.onvif.org/
- **WSDL 规范**: https://www.w3.org/TR/wsdl
- **XSD 规范**: https://www.w3.org/TR/xmlschema-1/
- **libxml2 文档**: http://xmlsoft.org/

---

**提示**: 建议将此手册添加到项目文档中，方便团队成员查阅。
