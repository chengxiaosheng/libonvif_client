# ONVIF 客户端库示例程序

本目录包含 libonvif_client 库的使用示例。

## 示例列表

### demo.cpp - ONVIF 客户端完整演示 (Drogon HTTP 客户端)

这是一个全面的示例程序，展示了如何使用 libonvif_client 库与 ONVIF 设备交互，使用 Drogon HTTP 客户端。

**功能演示：**
- 连接到 ONVIF 设备
- 获取设备信息（制造商、型号、固件版本等）
- 获取系统时间
- 获取设备能力（支持的服务）
- 获取网络接口信息
- 获取所有媒体配置文件 (Profiles)
- 获取流 URI (RTSP/RTP)
- 获取快照 URI
- 列出所有可用服务

### curl_demo.cpp - ONVIF 客户端演示 (libcurl HTTP 客户端)

与 demo.cpp 功能相同，但使用 libcurl 作为 HTTP 客户端实现。

**优点：**
- 不依赖 Drogon 框架
- 更轻量级
- 易于集成到现有项目

## 构建示例

### 1. 配置 CMake 并启用示例

在项目根目录或 libonvif_client 目录下运行：

```bash
mkdir build && cd build
cmake .. -DBUILD_EXAMPLES=ON
cmake --build .
```

### 2. 运行示例

编译完成后，可执行文件位于构建目录中：

```bash
# 使用 Drogon HTTP 客户端
./examples/onvif_client_demo <设备URL> <用户名> <密码>

# 使用 libcurl HTTP 客户端
./examples/onvif_client_curl_demo <设备URL> <用户名> <密码>
```

**参数说明：**
- `<设备URL>`: ONVIF 设备的服务端点 URL，例如：
  - `http://192.168.1.100/onvif/device_service`
  - `http://192.168.1.100:80/onvif/device_service`
  - `https://192.168.1.100:443/onvif/device_service`
- `<用户名>`: ONVIF 设备的用户名（通常是 `admin`）
- `<密码>`: ONVIF 设备的密码

### 3. 示例输出

运行成功后，程序将输出类似以下内容：

```
================================================================================
  ONVIF 客户端演示程序
================================================================================
设备URL: http://192.168.1.100/onvif/device_service
用户名: admin

================================================================================
  连接到ONVIF设备
================================================================================
正在连接...
✓ 连接成功!

================================================================================
  设备信息 (Device Information)
================================================================================
制造商 (Manufacturer):  HIKVision
型号 (Model):          DS-2CD2145FWD-I
固件版本 (Firmware):    V5.5.82
序列号 (Serial):       DS-2CD2145FWD-I20190101AAWRD
硬件ID (Hardware ID):  88

================================================================================
  系统时间 (System Date & Time)
================================================================================
时间类型 (Type): NTP
夏令时 (DST):   禁用
时区 (Timezone): CST-8
UTC时间: 2025-10-23 12:30:45
本地时间: 2025-10-23 20:30:45

================================================================================
  媒体配置文件 (Media Profiles)
================================================================================
共有 2 个配置文件

配置文件 #1:
  名称: MainStream
  Token: Profile_1
  固定: 是
    视频编码器:
      名称: VideoEncoderConfig_1
      Token: VideoEncoderConfig_1
      编码: H264
      分辨率: 2560x1440

配置文件 #2:
  名称: SubStream
  Token: Profile_2
  固定: 否
    视频编码器:
      名称: VideoEncoderConfig_2
      Token: VideoEncoderConfig_2
      编码: H264
      分辨率: 704x576

================================================================================
  获取流URI (Stream URI)
================================================================================
配置文件 Token: Profile_1
流URI: rtsp://192.168.1.100:554/Streaming/Channels/101

================================================================================
  获取快照URI (Snapshot URI)
================================================================================
配置文件 Token: Profile_1
快照URI: http://192.168.1.100/ISAPI/Streaming/channels/101/picture

================================================================================
  演示完成
================================================================================
所有操作已完成!
```

## 常见问题

### Q: 提示 "连接失败" 怎么办？

**A:** 检查以下几点：
1. 设备 IP 地址和端口是否正确
2. 设备是否支持 ONVIF 协议
3. 用户名和密码是否正确
4. 网络是否可达（可以先用 `ping` 测试）
5. 防火墙是否阻止了连接

### Q: SSL/TLS 证书验证失败？

**A:** ONVIF 设备通常使用自签名证书。示例程序已经通过以下代码禁用了证书验证：

```cpp
http_client_ptr->set_ssl_verify(false);
```

### Q: 如何找到设备的 URL？

**A:** 通常有以下几种方法：
1. 查看设备说明书或 Web 管理界面
2. 使用 ONVIF 设备发现工具（如 ONVIF Device Manager）
3. 常见的 URL 格式：
   - `http://<IP>/onvif/device_service`
   - `http://<IP>:<PORT>/onvif/device_service`
   - 端口通常是 80、8080 或 10080

### Q: 某些功能不可用？

**A:** 不是所有 ONVIF 设备都支持完整的 ONVIF 规范。某些设备可能不支持：
- PTZ 云台控制（需要硬件支持）
- 某些高级服务（Analytics、Events 等）
- 某些配置选项

## 扩展示例

基于此示例，你可以：

1. **添加 PTZ 控制**：使用 `PTZClient` 控制云台
2. **事件订阅**：使用事件服务接收设备事件通知
3. **录像回放**：使用录像服务访问历史录像
4. **图像调整**：使用图像服务调整亮度、对比度等
5. **设备配置**：修改设备设置（需要管理员权限）

## 代码结构说明

示例代码的主要流程：

```cpp
1. 创建 HTTP 客户端 (DrogonHttpClient 或 CurlHttpClient)
2. 创建 ONVIF 客户端 (OnvifClient)
3. 配置连接参数 (Config)
4. 连接到设备 (connect)
5. 获取服务客户端 (device(), get_service_client<MediaClient>)
6. 调用 ONVIF 操作（GetDeviceInformation, GetProfiles 等）
7. 处理异步回调结果
```

## HTTP 客户端选择

libonvif_client 支持多种 HTTP 客户端实现：

| HTTP 客户端 | 头文件 | 依赖 | 优点 | 适用场景 |
|------------|--------|------|------|---------|
| DrogonHttpClient | `http_clients/drogon_http_client.h` | Drogon | 高性能、协程支持 | 已使用 Drogon 框架的项目 |
| CurlHttpClient | `http_clients/curl_http_client.h` | libcurl | 轻量、广泛使用 | 独立程序、嵌入式应用 |

### 使用 DrogonHttpClient

```cpp
#include "http_clients/drogon_http_client.h"

auto http_client = std::make_shared<DrogonHttpClient>(true);
http_client->set_ssl_verify(false);
```

### 使用 CurlHttpClient

```cpp
#include "http_clients/curl_http_client.h"

auto http_client = std::make_shared<CurlHttpClient>(true, 4);
http_client->set_ssl_verify(false);
http_client->set_connect_timeout(10);
```

## 注意事项

1. **异步操作**：所有 ONVIF 操作都是异步的，需要提供回调函数
2. **线程安全**：示例使用互斥锁和条件变量来同步异步操作（仅用于演示）
3. **生产环境**：在实际应用中，应该使用事件循环而不是阻塞等待
4. **错误处理**：始终检查回调中的 `error` 参数
5. **资源管理**：使用智能指针管理资源生命周期

## 参考资料

- [ONVIF 官方网站](https://www.onvif.org/)
- [ONVIF Core Specification](https://www.onvif.org/specs/core/ONVIF-Core-Specification.pdf)
- [ONVIF Application Programmer's Guide](https://www.onvif.org/specs/DocMap-2.4.2.html)
- [libonvif_client 文档](../README.md)

## 许可证

与主项目相同。
