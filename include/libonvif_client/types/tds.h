/**
 * @file tds.h
 * @brief 从 devicemgmt_v10.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver10/device/wsdl
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 * @comment ONVIF服务WSDL - 每个文件单独生成
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/common.h>
#include <libonvif_client/types/tt.h>

// 标准库头文件
#include <string>
#include <vector>
#include <optional>
#include <memory>
#include <map>
#include <cstdint>
#include <sstream>

// libonvif_client框架头文件
#include <libonvif_client/xml_convert.h>
#include "libonvif_client/base_types.h"

namespace libonvif_client {

// GetServices 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetServices {
    // Indicates if the service capabilities (untyped) should be included in the response.
    bool IncludeCapability {};
};


// XmlTraits for tds_GetServices
template<>
struct xml_convert::XmlTraits<tds_GetServices> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IncludeCapability", &tds_GetServices::IncludeCapability, "tds", xml_convert::serialize_type::full)
    );
};


// NetworkCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_NetworkCapabilities {
    // Indicates support for IP filtering.
    std::optional<bool> IPFilter;
    // Indicates support for zeroconf.
    std::optional<bool> ZeroConfiguration;
    // Indicates support for IPv6.
    std::optional<bool> IPVersion6;
    // Indicates support for dynamic DNS configuration.
    std::optional<bool> DynDNS;
    // Indicates support for IEEE 802.11 configuration.
    std::optional<bool> Dot11Configuration;
    // Indicates the maximum number of Dot1X configurations supported by the device
    std::optional<int32_t> Dot1XConfigurations;
    // Indicates support for retrieval of hostname from DHCP.
    std::optional<bool> HostnameFromDHCP;
    // Maximum number of NTP servers supported by the devices SetNTP command.
    std::optional<int32_t> NTP;
    // Indicates support for Stateful IPv6 DHCP.
    std::optional<bool> DHCPv6;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tds_NetworkCapabilities
template<>
struct xml_convert::XmlTraits<tds_NetworkCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IPFilter", &tds_NetworkCapabilities::IPFilter, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("ZeroConfiguration", &tds_NetworkCapabilities::ZeroConfiguration, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("IPVersion6", &tds_NetworkCapabilities::IPVersion6, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("DynDNS", &tds_NetworkCapabilities::DynDNS, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Dot11Configuration", &tds_NetworkCapabilities::Dot11Configuration, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Dot1XConfigurations", &tds_NetworkCapabilities::Dot1XConfigurations, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("HostnameFromDHCP", &tds_NetworkCapabilities::HostnameFromDHCP, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("NTP", &tds_NetworkCapabilities::NTP, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("DHCPv6", &tds_NetworkCapabilities::DHCPv6, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tds_NetworkCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SecurityCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SecurityCapabilities {
    // Indicates support for TLS 1.0.
    std::optional<bool> TLS1_0;
    // Indicates support for TLS 1.1.
    std::optional<bool> TLS1_1;
    // Indicates support for TLS 1.2.
    std::optional<bool> TLS1_2;
    // Indicates support for onboard key generation.
    std::optional<bool> OnboardKeyGeneration;
    // Indicates support for access policy configuration.
    std::optional<bool> AccessPolicyConfig;
    // Indicates support for the ONVIF default access policy.
    std::optional<bool> DefaultAccessPolicy;
    // Indicates support for IEEE 802.1X configuration.
    std::optional<bool> Dot1X;
    // Indicates support for remote user configuration. Used when accessing another device.
    std::optional<bool> RemoteUserHandling;
    // Indicates support for WS-Security X.509 token.
    std::optional<bool> X_509Token;
    // Indicates support for WS-Security SAML token.
    std::optional<bool> SAMLToken;
    // Indicates support for WS-Security Kerberos token.
    std::optional<bool> KerberosToken;
    // Indicates support for WS-Security Username token.
    std::optional<bool> UsernameToken;
    // Indicates support for WS over HTTP digest authenticated communication layer.
    std::optional<bool> HttpDigest;
    // Indicates support for WS-Security REL token.
    std::optional<bool> RELToken;
    // Indicates support for JWT-based authentication with WS-Security Binary Security token.
    std::optional<bool> JsonWebToken;
    // EAP Methods supported by the device. The int values refer to the IANA EAP Registry.
    std::optional<tt_IntList> SupportedEAPMethods;
    // The maximum number of users that the device supports.
    std::optional<int32_t> MaxUsers;
    // Maximum number of characters supported for the username by CreateUsers.
    std::optional<int32_t> MaxUserNameLength;
    // Maximum number of characters supported for the password by CreateUsers and SetUser.
    std::optional<int32_t> MaxPasswordLength;
    // Indicates which security policies are supported. Options are: ModifyPassword, PasswordComplexity, AuthFailureWarnings
    std::optional<tt_StringList> SecurityPolicies;
    // Maximum number of passwords that the device can remember for each user
    std::optional<int32_t> MaxPasswordHistory;
    // Supported hashing algorithms as part of HTTP and RTSP Digest authentication.Example: MD5,SHA-256
    std::optional<tt_StringList> HashingAlgorithms;
    // Whenever set to an integer greater than zero, it signals that the device supports editable user roles. It indicates the maximum number of editable user roles.
    std::optional<int32_t> MaxUserRoles;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tds_SecurityCapabilities
template<>
struct xml_convert::XmlTraits<tds_SecurityCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("TLS1.0", &tds_SecurityCapabilities::TLS1_0, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("TLS1.1", &tds_SecurityCapabilities::TLS1_1, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("TLS1.2", &tds_SecurityCapabilities::TLS1_2, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("OnboardKeyGeneration", &tds_SecurityCapabilities::OnboardKeyGeneration, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AccessPolicyConfig", &tds_SecurityCapabilities::AccessPolicyConfig, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("DefaultAccessPolicy", &tds_SecurityCapabilities::DefaultAccessPolicy, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Dot1X", &tds_SecurityCapabilities::Dot1X, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RemoteUserHandling", &tds_SecurityCapabilities::RemoteUserHandling, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("X.509Token", &tds_SecurityCapabilities::X_509Token, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SAMLToken", &tds_SecurityCapabilities::SAMLToken, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("KerberosToken", &tds_SecurityCapabilities::KerberosToken, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("UsernameToken", &tds_SecurityCapabilities::UsernameToken, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("HttpDigest", &tds_SecurityCapabilities::HttpDigest, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RELToken", &tds_SecurityCapabilities::RELToken, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("JsonWebToken", &tds_SecurityCapabilities::JsonWebToken, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SupportedEAPMethods", &tds_SecurityCapabilities::SupportedEAPMethods, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxUsers", &tds_SecurityCapabilities::MaxUsers, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxUserNameLength", &tds_SecurityCapabilities::MaxUserNameLength, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxPasswordLength", &tds_SecurityCapabilities::MaxPasswordLength, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SecurityPolicies", &tds_SecurityCapabilities::SecurityPolicies, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxPasswordHistory", &tds_SecurityCapabilities::MaxPasswordHistory, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("HashingAlgorithms", &tds_SecurityCapabilities::HashingAlgorithms, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxUserRoles", &tds_SecurityCapabilities::MaxUserRoles, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tds_SecurityCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// SystemCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SystemCapabilities {
    // Indicates support for WS Discovery resolve requests.
    std::optional<bool> DiscoveryResolve;
    // Indicates support for WS-Discovery Bye.
    std::optional<bool> DiscoveryBye;
    // Indicates support for remote discovery.
    std::optional<bool> RemoteDiscovery;
    // Indicates support for system backup through MTOM.
    std::optional<bool> SystemBackup;
    // Indicates support for retrieval of system logging through MTOM.
    std::optional<bool> SystemLogging;
    // Indicates support for firmware upgrade through MTOM.
    std::optional<bool> FirmwareUpgrade;
    // Indicates support for firmware upgrade through the cloud.
    std::optional<bool> CloudFirmwareUpgrade;
    // Indicates support for firmware upgrade through HTTP.
    std::optional<bool> HttpFirmwareUpgrade;
    // Indicates support for system backup through HTTP.
    std::optional<bool> HttpSystemBackup;
    // Indicates support for retrieval of system logging through HTTP.
    std::optional<bool> HttpSystemLogging;
    // Indicates support for retrieving support information through HTTP.
    std::optional<bool> HttpSupportInformation;
    // Indicates support for storage configuration interfaces.
    std::optional<bool> StorageConfiguration;
    // Indicates maximum number of storage configurations supported.
    std::optional<int32_t> MaxStorageConfigurations;
    // Indicates support for renewal of storage configuration.
    std::optional<bool> StorageConfigurationRenewal;
    // If present signals support for geo location. The value signals the supported number of entries.
    std::optional<int32_t> GeoLocationEntries;
    // List of supported automatic GeoLocation adjustment supported by the device. Valid items are defined by tds:AutoGeoMode.
    std::optional<tt_StringAttrList> AutoGeo;
    // Enumerates the supported StorageTypes, see tds:StorageType.
    std::optional<tt_StringAttrList> StorageTypesSupported;
    // Indicates no support for network discovery.
    std::optional<bool> DiscoveryNotSupported;
    // Indicates no support for network configuration.
    std::optional<bool> NetworkConfigNotSupported;
    // Indicates no support for user configuration.
    std::optional<bool> UserConfigNotSupported;
    // List of supported Addons by the device.
    std::optional<tt_StringAttrList> Addons;
    // Indicates what type of device this is. See tt:HardwareTypes for available options.
    std::optional<std::string> HardwareType;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tds_SystemCapabilities
template<>
struct xml_convert::XmlTraits<tds_SystemCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DiscoveryResolve", &tds_SystemCapabilities::DiscoveryResolve, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("DiscoveryBye", &tds_SystemCapabilities::DiscoveryBye, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RemoteDiscovery", &tds_SystemCapabilities::RemoteDiscovery, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SystemBackup", &tds_SystemCapabilities::SystemBackup, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SystemLogging", &tds_SystemCapabilities::SystemLogging, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("FirmwareUpgrade", &tds_SystemCapabilities::FirmwareUpgrade, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("CloudFirmwareUpgrade", &tds_SystemCapabilities::CloudFirmwareUpgrade, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("HttpFirmwareUpgrade", &tds_SystemCapabilities::HttpFirmwareUpgrade, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("HttpSystemBackup", &tds_SystemCapabilities::HttpSystemBackup, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("HttpSystemLogging", &tds_SystemCapabilities::HttpSystemLogging, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("HttpSupportInformation", &tds_SystemCapabilities::HttpSupportInformation, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("StorageConfiguration", &tds_SystemCapabilities::StorageConfiguration, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("MaxStorageConfigurations", &tds_SystemCapabilities::MaxStorageConfigurations, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("StorageConfigurationRenewal", &tds_SystemCapabilities::StorageConfigurationRenewal, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("GeoLocationEntries", &tds_SystemCapabilities::GeoLocationEntries, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AutoGeo", &tds_SystemCapabilities::AutoGeo, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("StorageTypesSupported", &tds_SystemCapabilities::StorageTypesSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("DiscoveryNotSupported", &tds_SystemCapabilities::DiscoveryNotSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("NetworkConfigNotSupported", &tds_SystemCapabilities::NetworkConfigNotSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("UserConfigNotSupported", &tds_SystemCapabilities::UserConfigNotSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Addons", &tds_SystemCapabilities::Addons, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("HardwareType", &tds_SystemCapabilities::HardwareType, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tds_SystemCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// MiscCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_MiscCapabilities {
    // Lists of commands supported by SendAuxiliaryCommand.
    std::optional<tt_StringAttrList> AuxiliaryCommands;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tds_MiscCapabilities
template<>
struct xml_convert::XmlTraits<tds_MiscCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AuxiliaryCommands", &tds_MiscCapabilities::AuxiliaryCommands, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tds_MiscCapabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// DeviceServiceCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeviceServiceCapabilities {
    // Network capabilities.
    tds_NetworkCapabilities Network;
    // Security capabilities.
    tds_SecurityCapabilities Security;
    // System capabilities.
    tds_SystemCapabilities System;
    // Capabilities that do not fit in any of the other categories.
    std::optional<tds_MiscCapabilities> Misc;
};


// XmlTraits for tds_DeviceServiceCapabilities
template<>
struct xml_convert::XmlTraits<tds_DeviceServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Network", &tds_DeviceServiceCapabilities::Network, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Security", &tds_DeviceServiceCapabilities::Security, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("System", &tds_DeviceServiceCapabilities::System, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Misc", &tds_DeviceServiceCapabilities::Misc, "tds", xml_convert::serialize_type::full)
    );
};


// Capabilities 类型别名
// 基础类型: tds_DeviceServiceCapabilities
using tds_Capabilities = tds_DeviceServiceCapabilities;


// Service 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_Service {
    // Namespace of the service being described. This parameter allows to match the service capabilities to the service. Note that only one set of capabilities is supported per namespace.
    std::string Namespace;
    // The transport addresses where the service can be reached. The scheme and IP part shall match the one used in the request (i.e. the GetServices request).
    std::string XAddr;
    std::optional<tds_Capabilities> Capabilities;
    // The version of the service (not the ONVIF core spec version).
    tt_OnvifVersion Version;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tds_Service
template<>
struct xml_convert::XmlTraits<tds_Service> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Namespace", &tds_Service::Namespace, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("XAddr", &tds_Service::XAddr, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Capabilities", &tds_Service::Capabilities, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Version", &tds_Service::Version, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tds_Service::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("_attrs_", &tds_Service::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServicesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetServicesResponse {
    // Each Service element contains information about one service.
    std::vector<tds_Service> Service;
};


// XmlTraits for tds_GetServicesResponse
template<>
struct xml_convert::XmlTraits<tds_GetServicesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Service", &tds_GetServicesResponse::Service, "tds", xml_convert::serialize_type::full)
    );
};


// GetServiceCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetServiceCapabilities {
};


// XmlTraits for tds_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<tds_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetServiceCapabilitiesResponse {
    // The capabilities for the device service is returned in the Capabilities element.
    tds_DeviceServiceCapabilities Capabilities;
};


// XmlTraits for tds_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<tds_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &tds_GetServiceCapabilitiesResponse::Capabilities, "tds", xml_convert::serialize_type::full)
    );
};


// AutoGeoModes 枚举类型
// 基础类型: std::string
enum class  tds_AutoGeoModes {
    Location,
    Heading,
    Leveling
};

// 字符串转换函数
inline std::string to_string(tds_AutoGeoModes value) {
    switch (value) {
        case tds_AutoGeoModes::Location: return "Location";
        case tds_AutoGeoModes::Heading: return "Heading";
        case tds_AutoGeoModes::Leveling: return "Leveling";
        default: return "";
    }
}

inline bool from_string(tds_AutoGeoModes& value, const std::string& str) {
    if (str == "Location") { value = tds_AutoGeoModes::Location; return true; }
    if (str == "Heading") { value = tds_AutoGeoModes::Heading; return true; }
    if (str == "Leveling") { value = tds_AutoGeoModes::Leveling; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tds_AutoGeoModes
template<>
struct xml_convert::XmlValueAdapter<tds_AutoGeoModes> {
    static bool from_xml_val(tds_AutoGeoModes& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        xmlNodePtr targetElement = name ? 
            xmlGetChildElementByName(element, name) : element;
        if (!targetElement) return false;
        xmlChar* content = xmlNodeGetContent(targetElement);
        if (!content) return false;
        std::string str_val(reinterpret_cast<char*>(content));
        xmlFree(content);
        return from_string(val, str_val);
    }
    
    static bool to_xml_val(const tds_AutoGeoModes& val, xmlNodePtr parent, const char* name,
                           const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;
        xmlNodePtr element = create_element_with_ns(parent, name, ns_prefix, namespaces);
        if (!element) return false;
        xmlNodeSetContent(element, BAD_CAST to_string(val).c_str());
        return true;
    }
    
private:
    static xmlNodePtr create_element_with_ns(xmlNodePtr parent, const char* name, 
                                            const char* ns_prefix, const std::map<std::string_view, std::string_view>& namespaces) {
        xmlNodePtr element = xmlNewChild(parent, nullptr, BAD_CAST name, nullptr);
        if (element && ns_prefix) {
            auto it = namespaces.find(ns_prefix);
            if (it != namespaces.end()) {
                xmlNsPtr ns = xmlNewNs(element, BAD_CAST it->second.data(), BAD_CAST ns_prefix);
                xmlSetNs(element, ns);
            }
        }
        return element;
    }
    
    static xmlNodePtr xmlGetChildElementByName(xmlNodePtr parent, const char* name) {
        if (!parent || !name) return nullptr;
        for (xmlNodePtr child = parent->children; child; child = child->next) {
            if (child->type == XML_ELEMENT_NODE && 
                xmlStrcmp(child->name, BAD_CAST name) == 0) {
                return child;
            }
        }
        return nullptr;
    }
};

// XmlAttributeAdapter specialization for enum tds_AutoGeoModes
template<>
struct xml_convert::XmlAttributeAdapter<tds_AutoGeoModes> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tds_AutoGeoModes& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tds_AutoGeoModes& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// HardwareTypes 枚举类型
// 基础类型: std::string
enum class  tds_HardwareTypes {
    Camera,
    MultiSensorCamera,
    Encoder,
    Intercom,
    AccessControl,
    Speaker,
    Recorder,
    Microphone,
    Display,
    IO_Device // IO-Device
};

// 字符串转换函数
inline std::string to_string(tds_HardwareTypes value) {
    switch (value) {
        case tds_HardwareTypes::Camera: return "Camera";
        case tds_HardwareTypes::MultiSensorCamera: return "MultiSensorCamera";
        case tds_HardwareTypes::Encoder: return "Encoder";
        case tds_HardwareTypes::Intercom: return "Intercom";
        case tds_HardwareTypes::AccessControl: return "AccessControl";
        case tds_HardwareTypes::Speaker: return "Speaker";
        case tds_HardwareTypes::Recorder: return "Recorder";
        case tds_HardwareTypes::Microphone: return "Microphone";
        case tds_HardwareTypes::Display: return "Display";
        case tds_HardwareTypes::IO_Device: return "IO-Device";
        default: return "";
    }
}

inline bool from_string(tds_HardwareTypes& value, const std::string& str) {
    if (str == "Camera") { value = tds_HardwareTypes::Camera; return true; }
    if (str == "MultiSensorCamera") { value = tds_HardwareTypes::MultiSensorCamera; return true; }
    if (str == "Encoder") { value = tds_HardwareTypes::Encoder; return true; }
    if (str == "Intercom") { value = tds_HardwareTypes::Intercom; return true; }
    if (str == "AccessControl") { value = tds_HardwareTypes::AccessControl; return true; }
    if (str == "Speaker") { value = tds_HardwareTypes::Speaker; return true; }
    if (str == "Recorder") { value = tds_HardwareTypes::Recorder; return true; }
    if (str == "Microphone") { value = tds_HardwareTypes::Microphone; return true; }
    if (str == "Display") { value = tds_HardwareTypes::Display; return true; }
    if (str == "IO-Device") { value = tds_HardwareTypes::IO_Device; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tds_HardwareTypes
template<>
struct xml_convert::XmlValueAdapter<tds_HardwareTypes> {
    static bool from_xml_val(tds_HardwareTypes& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        xmlNodePtr targetElement = name ? 
            xmlGetChildElementByName(element, name) : element;
        if (!targetElement) return false;
        xmlChar* content = xmlNodeGetContent(targetElement);
        if (!content) return false;
        std::string str_val(reinterpret_cast<char*>(content));
        xmlFree(content);
        return from_string(val, str_val);
    }
    
    static bool to_xml_val(const tds_HardwareTypes& val, xmlNodePtr parent, const char* name,
                           const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;
        xmlNodePtr element = create_element_with_ns(parent, name, ns_prefix, namespaces);
        if (!element) return false;
        xmlNodeSetContent(element, BAD_CAST to_string(val).c_str());
        return true;
    }
    
private:
    static xmlNodePtr create_element_with_ns(xmlNodePtr parent, const char* name, 
                                            const char* ns_prefix, const std::map<std::string_view, std::string_view>& namespaces) {
        xmlNodePtr element = xmlNewChild(parent, nullptr, BAD_CAST name, nullptr);
        if (element && ns_prefix) {
            auto it = namespaces.find(ns_prefix);
            if (it != namespaces.end()) {
                xmlNsPtr ns = xmlNewNs(element, BAD_CAST it->second.data(), BAD_CAST ns_prefix);
                xmlSetNs(element, ns);
            }
        }
        return element;
    }
    
    static xmlNodePtr xmlGetChildElementByName(xmlNodePtr parent, const char* name) {
        if (!parent || !name) return nullptr;
        for (xmlNodePtr child = parent->children; child; child = child->next) {
            if (child->type == XML_ELEMENT_NODE && 
                xmlStrcmp(child->name, BAD_CAST name) == 0) {
                return child;
            }
        }
        return nullptr;
    }
};

// XmlAttributeAdapter specialization for enum tds_HardwareTypes
template<>
struct xml_convert::XmlAttributeAdapter<tds_HardwareTypes> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tds_HardwareTypes& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tds_HardwareTypes& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// GetDeviceInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDeviceInformation {
};


// XmlTraits for tds_GetDeviceInformation
template<>
struct xml_convert::XmlTraits<tds_GetDeviceInformation> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetDeviceInformationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDeviceInformationResponse {
    // The manufactor of the device.
    std::string Manufacturer;
    // The device model.
    std::string Model;
    // The firmware version in the device.
    std::string FirmwareVersion;
    // The serial number of the device.
    std::string SerialNumber;
    // The hardware ID of the device.
    std::string HardwareId;
};


// XmlTraits for tds_GetDeviceInformationResponse
template<>
struct xml_convert::XmlTraits<tds_GetDeviceInformationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Manufacturer", &tds_GetDeviceInformationResponse::Manufacturer, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Model", &tds_GetDeviceInformationResponse::Model, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("FirmwareVersion", &tds_GetDeviceInformationResponse::FirmwareVersion, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SerialNumber", &tds_GetDeviceInformationResponse::SerialNumber, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("HardwareId", &tds_GetDeviceInformationResponse::HardwareId, "tds", xml_convert::serialize_type::full)
    );
};


// SetSystemDateAndTime 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetSystemDateAndTime {
    // Defines if the date and time is set via NTP or manually.
    tt_SetDateTimeType DateTimeType;
    // Automatically adjust Daylight savings if defined in TimeZone.
    bool DaylightSavings {};
    // The time zone in POSIX 1003.1 format
    std::optional<tt_TimeZone> TimeZone;
    // Date and time in UTC. If time is obtained via NTP, UTCDateTime has no meaning
    std::optional<tt_DateTime> UTCDateTime;
};


// XmlTraits for tds_SetSystemDateAndTime
template<>
struct xml_convert::XmlTraits<tds_SetSystemDateAndTime> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DateTimeType", &tds_SetSystemDateAndTime::DateTimeType, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DaylightSavings", &tds_SetSystemDateAndTime::DaylightSavings, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TimeZone", &tds_SetSystemDateAndTime::TimeZone, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UTCDateTime", &tds_SetSystemDateAndTime::UTCDateTime, "tds", xml_convert::serialize_type::full)
    );
};


// SetSystemDateAndTimeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetSystemDateAndTimeResponse {
};


// XmlTraits for tds_SetSystemDateAndTimeResponse
template<>
struct xml_convert::XmlTraits<tds_SetSystemDateAndTimeResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetSystemDateAndTime 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetSystemDateAndTime {
};


// XmlTraits for tds_GetSystemDateAndTime
template<>
struct xml_convert::XmlTraits<tds_GetSystemDateAndTime> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetSystemDateAndTimeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetSystemDateAndTimeResponse {
    // Contains information whether system date and time are set manually or by NTP, daylight savings is on or off, time zone in POSIX 1003.1 format and system date and time in UTC and also local system date and time.
    tt_SystemDateTime SystemDateAndTime;
};


// XmlTraits for tds_GetSystemDateAndTimeResponse
template<>
struct xml_convert::XmlTraits<tds_GetSystemDateAndTimeResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SystemDateAndTime", &tds_GetSystemDateAndTimeResponse::SystemDateAndTime, "tds", xml_convert::serialize_type::full)
    );
};


// SetSystemFactoryDefault 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetSystemFactoryDefault {
    // Specifies the factory default action type.
    tt_FactoryDefaultType FactoryDefault;
};


// XmlTraits for tds_SetSystemFactoryDefault
template<>
struct xml_convert::XmlTraits<tds_SetSystemFactoryDefault> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FactoryDefault", &tds_SetSystemFactoryDefault::FactoryDefault, "tds", xml_convert::serialize_type::full)
    );
};


// SetSystemFactoryDefaultResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetSystemFactoryDefaultResponse {
};


// XmlTraits for tds_SetSystemFactoryDefaultResponse
template<>
struct xml_convert::XmlTraits<tds_SetSystemFactoryDefaultResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// UpgradeSystemFirmware 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_UpgradeSystemFirmware {
    tt_AttachmentData Firmware;
};


// XmlTraits for tds_UpgradeSystemFirmware
template<>
struct xml_convert::XmlTraits<tds_UpgradeSystemFirmware> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Firmware", &tds_UpgradeSystemFirmware::Firmware, "tds", xml_convert::serialize_type::full)
    );
};


// UpgradeSystemFirmwareResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_UpgradeSystemFirmwareResponse {
    std::optional<std::string> Message;
};


// XmlTraits for tds_UpgradeSystemFirmwareResponse
template<>
struct xml_convert::XmlTraits<tds_UpgradeSystemFirmwareResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Message", &tds_UpgradeSystemFirmwareResponse::Message, "tds", xml_convert::serialize_type::full)
    );
};


// SystemReboot 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SystemReboot {
};


// XmlTraits for tds_SystemReboot
template<>
struct xml_convert::XmlTraits<tds_SystemReboot> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SystemRebootResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SystemRebootResponse {
    // Contains the reboot message sent by the device.
    std::string Message;
};


// XmlTraits for tds_SystemRebootResponse
template<>
struct xml_convert::XmlTraits<tds_SystemRebootResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Message", &tds_SystemRebootResponse::Message, "tds", xml_convert::serialize_type::full)
    );
};


// RestoreSystem 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_RestoreSystem {
    std::vector<tt_BackupFile> BackupFiles;
};


// XmlTraits for tds_RestoreSystem
template<>
struct xml_convert::XmlTraits<tds_RestoreSystem> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BackupFiles", &tds_RestoreSystem::BackupFiles, "tds", xml_convert::serialize_type::full)
    );
};


// RestoreSystemResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_RestoreSystemResponse {
};


// XmlTraits for tds_RestoreSystemResponse
template<>
struct xml_convert::XmlTraits<tds_RestoreSystemResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetSystemBackup 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetSystemBackup {
};


// XmlTraits for tds_GetSystemBackup
template<>
struct xml_convert::XmlTraits<tds_GetSystemBackup> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetSystemBackupResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetSystemBackupResponse {
    std::vector<tt_BackupFile> BackupFiles;
};


// XmlTraits for tds_GetSystemBackupResponse
template<>
struct xml_convert::XmlTraits<tds_GetSystemBackupResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("BackupFiles", &tds_GetSystemBackupResponse::BackupFiles, "tds", xml_convert::serialize_type::full)
    );
};


// GetSystemSupportInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetSystemSupportInformation {
};


// XmlTraits for tds_GetSystemSupportInformation
template<>
struct xml_convert::XmlTraits<tds_GetSystemSupportInformation> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetSystemSupportInformationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetSystemSupportInformationResponse {
    // Contains the arbitary device diagnostics information.
    tt_SupportInformation SupportInformation;
};


// XmlTraits for tds_GetSystemSupportInformationResponse
template<>
struct xml_convert::XmlTraits<tds_GetSystemSupportInformationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SupportInformation", &tds_GetSystemSupportInformationResponse::SupportInformation, "tds", xml_convert::serialize_type::full)
    );
};


// GetSystemLog 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetSystemLog {
    // Specifies the type of system log to get.
    tt_SystemLogType LogType;
};


// XmlTraits for tds_GetSystemLog
template<>
struct xml_convert::XmlTraits<tds_GetSystemLog> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("LogType", &tds_GetSystemLog::LogType, "tds", xml_convert::serialize_type::full)
    );
};


// GetSystemLogResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetSystemLogResponse {
    // Contains the system log information.
    tt_SystemLog SystemLog;
};


// XmlTraits for tds_GetSystemLogResponse
template<>
struct xml_convert::XmlTraits<tds_GetSystemLogResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SystemLog", &tds_GetSystemLogResponse::SystemLog, "tds", xml_convert::serialize_type::full)
    );
};


// GetScopes 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetScopes {
};


// XmlTraits for tds_GetScopes
template<>
struct xml_convert::XmlTraits<tds_GetScopes> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetScopesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetScopesResponse {
    // Contains a list of URI definining the device scopes. Scope parameters can be of two types: fixed and configurable. Fixed parameters can not be altered.
    std::vector<tt_Scope> Scopes;
};


// XmlTraits for tds_GetScopesResponse
template<>
struct xml_convert::XmlTraits<tds_GetScopesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Scopes", &tds_GetScopesResponse::Scopes, "tds", xml_convert::serialize_type::full)
    );
};


// SetScopes 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetScopes {
    // Contains a list of scope parameters that will replace all existing configurable scope parameters.
    std::vector<std::string> Scopes;
};


// XmlTraits for tds_SetScopes
template<>
struct xml_convert::XmlTraits<tds_SetScopes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Scopes", &tds_SetScopes::Scopes, "tds", xml_convert::serialize_type::full)
    );
};


// SetScopesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetScopesResponse {
};


// XmlTraits for tds_SetScopesResponse
template<>
struct xml_convert::XmlTraits<tds_SetScopesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AddScopes 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_AddScopes {
    // Contains a list of new configurable scope parameters that will be added to the existing configurable scope.
    std::vector<std::string> ScopeItem;
};


// XmlTraits for tds_AddScopes
template<>
struct xml_convert::XmlTraits<tds_AddScopes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ScopeItem", &tds_AddScopes::ScopeItem, "tds", xml_convert::serialize_type::full)
    );
};


// AddScopesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_AddScopesResponse {
};


// XmlTraits for tds_AddScopesResponse
template<>
struct xml_convert::XmlTraits<tds_AddScopesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveScopes 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_RemoveScopes {
    /*
     * Contains a list of URIs that should be removed from the device scope.
     * Note that the response message always will match the request or an error will be returned. The use of the response is for that reason deprecated.
     */
    std::vector<std::string> ScopeItem;
};


// XmlTraits for tds_RemoveScopes
template<>
struct xml_convert::XmlTraits<tds_RemoveScopes> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ScopeItem", &tds_RemoveScopes::ScopeItem, "tds", xml_convert::serialize_type::full)
    );
};


// RemoveScopesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_RemoveScopesResponse {
    // Contains a list of URIs that has been removed from the device scope
    std::vector<std::string> ScopeItem;
};


// XmlTraits for tds_RemoveScopesResponse
template<>
struct xml_convert::XmlTraits<tds_RemoveScopesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ScopeItem", &tds_RemoveScopesResponse::ScopeItem, "tds", xml_convert::serialize_type::full)
    );
};


// GetDiscoveryMode 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDiscoveryMode {
};


// XmlTraits for tds_GetDiscoveryMode
template<>
struct xml_convert::XmlTraits<tds_GetDiscoveryMode> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetDiscoveryModeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDiscoveryModeResponse {
    // Indicator of discovery mode: Discoverable, NonDiscoverable.
    tt_DiscoveryMode DiscoveryMode;
};


// XmlTraits for tds_GetDiscoveryModeResponse
template<>
struct xml_convert::XmlTraits<tds_GetDiscoveryModeResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DiscoveryMode", &tds_GetDiscoveryModeResponse::DiscoveryMode, "tds", xml_convert::serialize_type::full)
    );
};


// SetDiscoveryMode 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetDiscoveryMode {
    // Indicator of discovery mode: Discoverable, NonDiscoverable.
    tt_DiscoveryMode DiscoveryMode;
};


// XmlTraits for tds_SetDiscoveryMode
template<>
struct xml_convert::XmlTraits<tds_SetDiscoveryMode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DiscoveryMode", &tds_SetDiscoveryMode::DiscoveryMode, "tds", xml_convert::serialize_type::full)
    );
};


// SetDiscoveryModeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetDiscoveryModeResponse {
};


// XmlTraits for tds_SetDiscoveryModeResponse
template<>
struct xml_convert::XmlTraits<tds_SetDiscoveryModeResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRemoteDiscoveryMode 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetRemoteDiscoveryMode {
};


// XmlTraits for tds_GetRemoteDiscoveryMode
template<>
struct xml_convert::XmlTraits<tds_GetRemoteDiscoveryMode> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRemoteDiscoveryModeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetRemoteDiscoveryModeResponse {
    // Indicator of discovery mode: Discoverable, NonDiscoverable.
    tt_DiscoveryMode RemoteDiscoveryMode;
};


// XmlTraits for tds_GetRemoteDiscoveryModeResponse
template<>
struct xml_convert::XmlTraits<tds_GetRemoteDiscoveryModeResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RemoteDiscoveryMode", &tds_GetRemoteDiscoveryModeResponse::RemoteDiscoveryMode, "tds", xml_convert::serialize_type::full)
    );
};


// SetRemoteDiscoveryMode 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetRemoteDiscoveryMode {
    // Indicator of discovery mode: Discoverable, NonDiscoverable.
    tt_DiscoveryMode RemoteDiscoveryMode;
};


// XmlTraits for tds_SetRemoteDiscoveryMode
template<>
struct xml_convert::XmlTraits<tds_SetRemoteDiscoveryMode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RemoteDiscoveryMode", &tds_SetRemoteDiscoveryMode::RemoteDiscoveryMode, "tds", xml_convert::serialize_type::full)
    );
};


// SetRemoteDiscoveryModeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetRemoteDiscoveryModeResponse {
};


// XmlTraits for tds_SetRemoteDiscoveryModeResponse
template<>
struct xml_convert::XmlTraits<tds_SetRemoteDiscoveryModeResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetDPAddresses 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDPAddresses {
};


// XmlTraits for tds_GetDPAddresses
template<>
struct xml_convert::XmlTraits<tds_GetDPAddresses> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetDPAddressesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDPAddressesResponse {
    std::vector<tt_NetworkHost> DPAddress;
};


// XmlTraits for tds_GetDPAddressesResponse
template<>
struct xml_convert::XmlTraits<tds_GetDPAddressesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DPAddress", &tds_GetDPAddressesResponse::DPAddress, "tds", xml_convert::serialize_type::full)
    );
};


// SetDPAddresses 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetDPAddresses {
    std::vector<tt_NetworkHost> DPAddress;
};


// XmlTraits for tds_SetDPAddresses
template<>
struct xml_convert::XmlTraits<tds_SetDPAddresses> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DPAddress", &tds_SetDPAddresses::DPAddress, "tds", xml_convert::serialize_type::full)
    );
};


// SetDPAddressesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetDPAddressesResponse {
};


// XmlTraits for tds_SetDPAddressesResponse
template<>
struct xml_convert::XmlTraits<tds_SetDPAddressesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetEndpointReference 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetEndpointReference {
};


// XmlTraits for tds_GetEndpointReference
template<>
struct xml_convert::XmlTraits<tds_GetEndpointReference> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetEndpointReferenceResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetEndpointReferenceResponse {
    std::string GUID;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tds_GetEndpointReferenceResponse
template<>
struct xml_convert::XmlTraits<tds_GetEndpointReferenceResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("GUID", &tds_GetEndpointReferenceResponse::GUID, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tds_GetEndpointReferenceResponse::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// GetRemoteUser 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetRemoteUser {
};


// XmlTraits for tds_GetRemoteUser
template<>
struct xml_convert::XmlTraits<tds_GetRemoteUser> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRemoteUserResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetRemoteUserResponse {
    std::optional<tt_RemoteUser> RemoteUser;
};


// XmlTraits for tds_GetRemoteUserResponse
template<>
struct xml_convert::XmlTraits<tds_GetRemoteUserResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RemoteUser", &tds_GetRemoteUserResponse::RemoteUser, "tds", xml_convert::serialize_type::full)
    );
};


// SetRemoteUser 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetRemoteUser {
    std::optional<tt_RemoteUser> RemoteUser;
};


// XmlTraits for tds_SetRemoteUser
template<>
struct xml_convert::XmlTraits<tds_SetRemoteUser> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RemoteUser", &tds_SetRemoteUser::RemoteUser, "tds", xml_convert::serialize_type::full)
    );
};


// SetRemoteUserResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetRemoteUserResponse {
};


// XmlTraits for tds_SetRemoteUserResponse
template<>
struct xml_convert::XmlTraits<tds_SetRemoteUserResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetUsers 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetUsers {
};


// XmlTraits for tds_GetUsers
template<>
struct xml_convert::XmlTraits<tds_GetUsers> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetUsersResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetUsersResponse {
    // Contains a list of the onvif users and following information is included in each entry: username and user level.
    std::vector<tt_User> User;
};


// XmlTraits for tds_GetUsersResponse
template<>
struct xml_convert::XmlTraits<tds_GetUsersResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("User", &tds_GetUsersResponse::User, "tds", xml_convert::serialize_type::full)
    );
};


// CreateUsers 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_CreateUsers {
    // Creates new device users and corresponding credentials. Each user entry includes: username, password and user level. Either all users are created successfully or a fault message MUST be returned without creating any user. If trying to create several users with exactly the same username the request is rejected and no users are created. If password is missing, then fault message Too weak password is returned.
    std::vector<tt_User> User;
};


// XmlTraits for tds_CreateUsers
template<>
struct xml_convert::XmlTraits<tds_CreateUsers> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("User", &tds_CreateUsers::User, "tds", xml_convert::serialize_type::full)
    );
};


// CreateUsersResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_CreateUsersResponse {
};


// XmlTraits for tds_CreateUsersResponse
template<>
struct xml_convert::XmlTraits<tds_CreateUsersResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteUsers 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteUsers {
    // Deletes users on an device and there may exist users that cannot be deleted to ensure access to the unit. Either all users are deleted successfully or a fault message MUST be returned and no users be deleted. If a username exists multiple times in the request, then a fault message is returned.
    std::vector<std::string> Username;
};


// XmlTraits for tds_DeleteUsers
template<>
struct xml_convert::XmlTraits<tds_DeleteUsers> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Username", &tds_DeleteUsers::Username, "tds", xml_convert::serialize_type::full)
    );
};


// DeleteUsersResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteUsersResponse {
};


// XmlTraits for tds_DeleteUsersResponse
template<>
struct xml_convert::XmlTraits<tds_DeleteUsersResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetUser 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetUser {
    // Updates the credentials for one or several users on an device. Either all change requests are processed successfully or a fault message MUST be returned. If the request contains the same username multiple times, a fault message is returned.
    std::vector<tt_User> User;
};


// XmlTraits for tds_SetUser
template<>
struct xml_convert::XmlTraits<tds_SetUser> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("User", &tds_SetUser::User, "tds", xml_convert::serialize_type::full)
    );
};


// SetUserResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetUserResponse {
};


// XmlTraits for tds_SetUserResponse
template<>
struct xml_convert::XmlTraits<tds_SetUserResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetUserRoles 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetUserRoles {
    std::optional<std::string> UserRole;
};


// XmlTraits for tds_GetUserRoles
template<>
struct xml_convert::XmlTraits<tds_GetUserRoles> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("UserRole", &tds_GetUserRoles::UserRole, "tds", xml_convert::serialize_type::full)
    );
};


// GetUserRolesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetUserRolesResponse {
    std::vector<tt_UserRole> UserRole;
};


// XmlTraits for tds_GetUserRolesResponse
template<>
struct xml_convert::XmlTraits<tds_GetUserRolesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("UserRole", &tds_GetUserRolesResponse::UserRole, "tds", xml_convert::serialize_type::full)
    );
};


// SetUserRole 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetUserRole {
    tt_UserRole UserRole;
};


// XmlTraits for tds_SetUserRole
template<>
struct xml_convert::XmlTraits<tds_SetUserRole> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("UserRole", &tds_SetUserRole::UserRole, "tds", xml_convert::serialize_type::full)
    );
};


// SetUserRoleResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetUserRoleResponse {
};


// XmlTraits for tds_SetUserRoleResponse
template<>
struct xml_convert::XmlTraits<tds_SetUserRoleResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteUserRole 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteUserRole {
    std::string UserRole;
};


// XmlTraits for tds_DeleteUserRole
template<>
struct xml_convert::XmlTraits<tds_DeleteUserRole> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("UserRole", &tds_DeleteUserRole::UserRole, "tds", xml_convert::serialize_type::full)
    );
};


// DeleteUserRoleResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteUserRoleResponse {
};


// XmlTraits for tds_DeleteUserRoleResponse
template<>
struct xml_convert::XmlTraits<tds_DeleteUserRoleResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetWsdlUrl 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetWsdlUrl {
};


// XmlTraits for tds_GetWsdlUrl
template<>
struct xml_convert::XmlTraits<tds_GetWsdlUrl> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetWsdlUrlResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetWsdlUrlResponse {
    std::string WsdlUrl;
};


// XmlTraits for tds_GetWsdlUrlResponse
template<>
struct xml_convert::XmlTraits<tds_GetWsdlUrlResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("WsdlUrl", &tds_GetWsdlUrlResponse::WsdlUrl, "tds", xml_convert::serialize_type::full)
    );
};


// GetPasswordComplexityOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetPasswordComplexityOptions {
};


// XmlTraits for tds_GetPasswordComplexityOptions
template<>
struct xml_convert::XmlTraits<tds_GetPasswordComplexityOptions> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetPasswordComplexityOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetPasswordComplexityOptionsResponse {
    std::optional<tt_IntRange> MinLenRange;
    std::optional<tt_IntRange> UppercaseRange;
    std::optional<tt_IntRange> NumberRange;
    std::optional<tt_IntRange> SpecialCharsRange;
    std::optional<bool> BlockUsernameOccurrenceSupported;
    std::optional<bool> PolicyConfigurationLockSupported;
};


// XmlTraits for tds_GetPasswordComplexityOptionsResponse
template<>
struct xml_convert::XmlTraits<tds_GetPasswordComplexityOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MinLenRange", &tds_GetPasswordComplexityOptionsResponse::MinLenRange, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UppercaseRange", &tds_GetPasswordComplexityOptionsResponse::UppercaseRange, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NumberRange", &tds_GetPasswordComplexityOptionsResponse::NumberRange, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SpecialCharsRange", &tds_GetPasswordComplexityOptionsResponse::SpecialCharsRange, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BlockUsernameOccurrenceSupported", &tds_GetPasswordComplexityOptionsResponse::BlockUsernameOccurrenceSupported, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PolicyConfigurationLockSupported", &tds_GetPasswordComplexityOptionsResponse::PolicyConfigurationLockSupported, "tds", xml_convert::serialize_type::full)
    );
};


// GetPasswordComplexityConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetPasswordComplexityConfiguration {
};


// XmlTraits for tds_GetPasswordComplexityConfiguration
template<>
struct xml_convert::XmlTraits<tds_GetPasswordComplexityConfiguration> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetPasswordComplexityConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetPasswordComplexityConfigurationResponse {
    std::optional<int32_t> MinLen;
    std::optional<int32_t> Uppercase;
    std::optional<int32_t> Number;
    std::optional<int32_t> SpecialChars;
    std::optional<bool> BlockUsernameOccurrence;
    std::optional<bool> PolicyConfigurationLocked;
};


// XmlTraits for tds_GetPasswordComplexityConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_GetPasswordComplexityConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MinLen", &tds_GetPasswordComplexityConfigurationResponse::MinLen, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Uppercase", &tds_GetPasswordComplexityConfigurationResponse::Uppercase, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Number", &tds_GetPasswordComplexityConfigurationResponse::Number, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SpecialChars", &tds_GetPasswordComplexityConfigurationResponse::SpecialChars, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BlockUsernameOccurrence", &tds_GetPasswordComplexityConfigurationResponse::BlockUsernameOccurrence, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PolicyConfigurationLocked", &tds_GetPasswordComplexityConfigurationResponse::PolicyConfigurationLocked, "tds", xml_convert::serialize_type::full)
    );
};


// SetPasswordComplexityConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetPasswordComplexityConfiguration {
    std::optional<int32_t> MinLen;
    std::optional<int32_t> Uppercase;
    std::optional<int32_t> Number;
    std::optional<int32_t> SpecialChars;
    std::optional<bool> BlockUsernameOccurrence;
    std::optional<bool> PolicyConfigurationLocked;
};


// XmlTraits for tds_SetPasswordComplexityConfiguration
template<>
struct xml_convert::XmlTraits<tds_SetPasswordComplexityConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MinLen", &tds_SetPasswordComplexityConfiguration::MinLen, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Uppercase", &tds_SetPasswordComplexityConfiguration::Uppercase, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Number", &tds_SetPasswordComplexityConfiguration::Number, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SpecialChars", &tds_SetPasswordComplexityConfiguration::SpecialChars, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("BlockUsernameOccurrence", &tds_SetPasswordComplexityConfiguration::BlockUsernameOccurrence, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("PolicyConfigurationLocked", &tds_SetPasswordComplexityConfiguration::PolicyConfigurationLocked, "tds", xml_convert::serialize_type::full)
    );
};


// SetPasswordComplexityConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetPasswordComplexityConfigurationResponse {
};


// XmlTraits for tds_SetPasswordComplexityConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_SetPasswordComplexityConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetPasswordHistoryConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetPasswordHistoryConfiguration {
};


// XmlTraits for tds_GetPasswordHistoryConfiguration
template<>
struct xml_convert::XmlTraits<tds_GetPasswordHistoryConfiguration> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetPasswordHistoryConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetPasswordHistoryConfigurationResponse {
    bool Enabled {};
    int32_t Length {};
};


// XmlTraits for tds_GetPasswordHistoryConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_GetPasswordHistoryConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tds_GetPasswordHistoryConfigurationResponse::Enabled, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Length", &tds_GetPasswordHistoryConfigurationResponse::Length, "tds", xml_convert::serialize_type::full)
    );
};


// SetPasswordHistoryConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetPasswordHistoryConfiguration {
    bool Enabled {};
    int32_t Length {};
};


// XmlTraits for tds_SetPasswordHistoryConfiguration
template<>
struct xml_convert::XmlTraits<tds_SetPasswordHistoryConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tds_SetPasswordHistoryConfiguration::Enabled, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Length", &tds_SetPasswordHistoryConfiguration::Length, "tds", xml_convert::serialize_type::full)
    );
};


// SetPasswordHistoryConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetPasswordHistoryConfigurationResponse {
};


// XmlTraits for tds_SetPasswordHistoryConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_SetPasswordHistoryConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAuthFailureWarningOptions 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetAuthFailureWarningOptions {
};


// XmlTraits for tds_GetAuthFailureWarningOptions
template<>
struct xml_convert::XmlTraits<tds_GetAuthFailureWarningOptions> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAuthFailureWarningOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetAuthFailureWarningOptionsResponse {
    tt_IntRange MonitorPeriodRange;
    tt_IntRange AuthFailureRange;
};


// XmlTraits for tds_GetAuthFailureWarningOptionsResponse
template<>
struct xml_convert::XmlTraits<tds_GetAuthFailureWarningOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("MonitorPeriodRange", &tds_GetAuthFailureWarningOptionsResponse::MonitorPeriodRange, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AuthFailureRange", &tds_GetAuthFailureWarningOptionsResponse::AuthFailureRange, "tds", xml_convert::serialize_type::full)
    );
};


// GetAuthFailureWarningConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetAuthFailureWarningConfiguration {
};


// XmlTraits for tds_GetAuthFailureWarningConfiguration
template<>
struct xml_convert::XmlTraits<tds_GetAuthFailureWarningConfiguration> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAuthFailureWarningConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetAuthFailureWarningConfigurationResponse {
    bool Enabled {};
    int32_t MonitorPeriod {};
    int32_t MaxAuthFailures {};
};


// XmlTraits for tds_GetAuthFailureWarningConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_GetAuthFailureWarningConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tds_GetAuthFailureWarningConfigurationResponse::Enabled, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MonitorPeriod", &tds_GetAuthFailureWarningConfigurationResponse::MonitorPeriod, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxAuthFailures", &tds_GetAuthFailureWarningConfigurationResponse::MaxAuthFailures, "tds", xml_convert::serialize_type::full)
    );
};


// SetAuthFailureWarningConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetAuthFailureWarningConfiguration {
    bool Enabled {};
    int32_t MonitorPeriod {};
    int32_t MaxAuthFailures {};
};


// XmlTraits for tds_SetAuthFailureWarningConfiguration
template<>
struct xml_convert::XmlTraits<tds_SetAuthFailureWarningConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tds_SetAuthFailureWarningConfiguration::Enabled, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MonitorPeriod", &tds_SetAuthFailureWarningConfiguration::MonitorPeriod, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("MaxAuthFailures", &tds_SetAuthFailureWarningConfiguration::MaxAuthFailures, "tds", xml_convert::serialize_type::full)
    );
};


// SetAuthFailureWarningConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetAuthFailureWarningConfigurationResponse {
};


// XmlTraits for tds_SetAuthFailureWarningConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_SetAuthFailureWarningConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetCapabilities {
    // List of categories to retrieve capability information on.
    std::vector<tt_CapabilityCategory> Category;
};


// XmlTraits for tds_GetCapabilities
template<>
struct xml_convert::XmlTraits<tds_GetCapabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Category", &tds_GetCapabilities::Category, "tds", xml_convert::serialize_type::full)
    );
};


// GetCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetCapabilitiesResponse {
    // Capability information.
    tt_Capabilities Capabilities;
};


// XmlTraits for tds_GetCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<tds_GetCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &tds_GetCapabilitiesResponse::Capabilities, "tds", xml_convert::serialize_type::full)
    );
};


// GetHostname 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetHostname {
};


// XmlTraits for tds_GetHostname
template<>
struct xml_convert::XmlTraits<tds_GetHostname> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetHostnameResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetHostnameResponse {
    // Contains the hostname information.
    tt_HostnameInformation HostnameInformation;
};


// XmlTraits for tds_GetHostnameResponse
template<>
struct xml_convert::XmlTraits<tds_GetHostnameResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("HostnameInformation", &tds_GetHostnameResponse::HostnameInformation, "tds", xml_convert::serialize_type::full)
    );
};


// SetHostname 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetHostname {
    // The hostname to set.
    std::string Name;
};


// XmlTraits for tds_SetHostname
template<>
struct xml_convert::XmlTraits<tds_SetHostname> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Name", &tds_SetHostname::Name, "tds", xml_convert::serialize_type::full)
    );
};


// SetHostnameResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetHostnameResponse {
};


// XmlTraits for tds_SetHostnameResponse
template<>
struct xml_convert::XmlTraits<tds_SetHostnameResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetHostnameFromDHCP 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetHostnameFromDHCP {
    // True if the hostname shall be obtained via DHCP.
    bool FromDHCP {};
};


// XmlTraits for tds_SetHostnameFromDHCP
template<>
struct xml_convert::XmlTraits<tds_SetHostnameFromDHCP> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FromDHCP", &tds_SetHostnameFromDHCP::FromDHCP, "tds", xml_convert::serialize_type::full)
    );
};


// SetHostnameFromDHCPResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetHostnameFromDHCPResponse {
    // Indicates whether or not a reboot is required after configuration updates.
    bool RebootNeeded {};
};


// XmlTraits for tds_SetHostnameFromDHCPResponse
template<>
struct xml_convert::XmlTraits<tds_SetHostnameFromDHCPResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RebootNeeded", &tds_SetHostnameFromDHCPResponse::RebootNeeded, "tds", xml_convert::serialize_type::full)
    );
};


// GetDNS 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDNS {
};


// XmlTraits for tds_GetDNS
template<>
struct xml_convert::XmlTraits<tds_GetDNS> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetDNSResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDNSResponse {
    // DNS information.
    tt_DNSInformation DNSInformation;
};


// XmlTraits for tds_GetDNSResponse
template<>
struct xml_convert::XmlTraits<tds_GetDNSResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DNSInformation", &tds_GetDNSResponse::DNSInformation, "tds", xml_convert::serialize_type::full)
    );
};


// SetDNS 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetDNS {
    // Indicate if the DNS address is to be retrieved using DHCP.
    bool FromDHCP {};
    // DNS search domain.
    std::vector<std::string> SearchDomain;
    // DNS address(es) set manually.
    std::vector<tt_IPAddress> DNSManual;
};


// XmlTraits for tds_SetDNS
template<>
struct xml_convert::XmlTraits<tds_SetDNS> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FromDHCP", &tds_SetDNS::FromDHCP, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SearchDomain", &tds_SetDNS::SearchDomain, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("DNSManual", &tds_SetDNS::DNSManual, "tds", xml_convert::serialize_type::full)
    );
};


// SetDNSResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetDNSResponse {
};


// XmlTraits for tds_SetDNSResponse
template<>
struct xml_convert::XmlTraits<tds_SetDNSResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetNTP 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetNTP {
};


// XmlTraits for tds_GetNTP
template<>
struct xml_convert::XmlTraits<tds_GetNTP> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetNTPResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetNTPResponse {
    // NTP information.
    tt_NTPInformation NTPInformation;
};


// XmlTraits for tds_GetNTPResponse
template<>
struct xml_convert::XmlTraits<tds_GetNTPResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NTPInformation", &tds_GetNTPResponse::NTPInformation, "tds", xml_convert::serialize_type::full)
    );
};


// SetNTP 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetNTP {
    // Indicate if NTP address information is to be retrieved using DHCP.
    bool FromDHCP {};
    // Manual NTP settings.
    std::vector<tt_NetworkHost> NTPManual;
};


// XmlTraits for tds_SetNTP
template<>
struct xml_convert::XmlTraits<tds_SetNTP> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("FromDHCP", &tds_SetNTP::FromDHCP, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NTPManual", &tds_SetNTP::NTPManual, "tds", xml_convert::serialize_type::full)
    );
};


// SetNTPResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetNTPResponse {
};


// XmlTraits for tds_SetNTPResponse
template<>
struct xml_convert::XmlTraits<tds_SetNTPResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetDynamicDNS 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDynamicDNS {
};


// XmlTraits for tds_GetDynamicDNS
template<>
struct xml_convert::XmlTraits<tds_GetDynamicDNS> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetDynamicDNSResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDynamicDNSResponse {
    // Dynamic DNS information.
    tt_DynamicDNSInformation DynamicDNSInformation;
};


// XmlTraits for tds_GetDynamicDNSResponse
template<>
struct xml_convert::XmlTraits<tds_GetDynamicDNSResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("DynamicDNSInformation", &tds_GetDynamicDNSResponse::DynamicDNSInformation, "tds", xml_convert::serialize_type::full)
    );
};


// SetDynamicDNS 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetDynamicDNS {
    // Dynamic DNS type.
    tt_DynamicDNSType Type;
    // DNS name.
    std::optional<tt_DNSName> Name;
    // DNS record time to live.
    std::optional<my_Duration> TTL;
};


// XmlTraits for tds_SetDynamicDNS
template<>
struct xml_convert::XmlTraits<tds_SetDynamicDNS> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tds_SetDynamicDNS::Type, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Name", &tds_SetDynamicDNS::Name, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("TTL", &tds_SetDynamicDNS::TTL, "tds", xml_convert::serialize_type::full)
    );
};


// SetDynamicDNSResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetDynamicDNSResponse {
};


// XmlTraits for tds_SetDynamicDNSResponse
template<>
struct xml_convert::XmlTraits<tds_SetDynamicDNSResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetNetworkInterfaces 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetNetworkInterfaces {
};


// XmlTraits for tds_GetNetworkInterfaces
template<>
struct xml_convert::XmlTraits<tds_GetNetworkInterfaces> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetNetworkInterfacesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetNetworkInterfacesResponse {
    // List of network interfaces.
    std::vector<tt_NetworkInterface> NetworkInterfaces;
};


// XmlTraits for tds_GetNetworkInterfacesResponse
template<>
struct xml_convert::XmlTraits<tds_GetNetworkInterfacesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NetworkInterfaces", &tds_GetNetworkInterfacesResponse::NetworkInterfaces, "tds", xml_convert::serialize_type::full)
    );
};


// SetNetworkInterfaces 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetNetworkInterfaces {
    // Symbolic network interface name.
    tt_ReferenceToken InterfaceToken;
    // Network interface name.
    tt_NetworkInterfaceSetConfiguration NetworkInterface;
};


// XmlTraits for tds_SetNetworkInterfaces
template<>
struct xml_convert::XmlTraits<tds_SetNetworkInterfaces> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("InterfaceToken", &tds_SetNetworkInterfaces::InterfaceToken, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("NetworkInterface", &tds_SetNetworkInterfaces::NetworkInterface, "tds", xml_convert::serialize_type::full)
    );
};


// SetNetworkInterfacesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetNetworkInterfacesResponse {
    /*
     * Indicates whether or not a reboot is required after configuration updates.
     * If a device responds with RebootNeeded set to false, the device can be reached
     * via the new IP address without further action. A client should be aware that a device
     * may not be responsive for a short period of time until it signals availability at
     * the new address via the discovery Hello messages.
     * If a device responds with RebootNeeded set to true, it will be further available under
     * its previous IP address. The settings will only be activated when the device is
     * rebooted via the SystemReboot command.
     */
    bool RebootNeeded {};
};


// XmlTraits for tds_SetNetworkInterfacesResponse
template<>
struct xml_convert::XmlTraits<tds_SetNetworkInterfacesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RebootNeeded", &tds_SetNetworkInterfacesResponse::RebootNeeded, "tds", xml_convert::serialize_type::full)
    );
};


// GetNetworkProtocols 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetNetworkProtocols {
};


// XmlTraits for tds_GetNetworkProtocols
template<>
struct xml_convert::XmlTraits<tds_GetNetworkProtocols> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetNetworkProtocolsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetNetworkProtocolsResponse {
    // Contains an array of defined protocols supported by the device. There are three protocols defined; HTTP, HTTPS and RTSP. The following parameters can be retrieved for each protocol: port and enable/disable.
    std::vector<tt_NetworkProtocol> NetworkProtocols;
};


// XmlTraits for tds_GetNetworkProtocolsResponse
template<>
struct xml_convert::XmlTraits<tds_GetNetworkProtocolsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NetworkProtocols", &tds_GetNetworkProtocolsResponse::NetworkProtocols, "tds", xml_convert::serialize_type::full)
    );
};


// SetNetworkProtocols 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetNetworkProtocols {
    // Configures one or more defined network protocols supported by the device. There are currently three protocols defined; HTTP, HTTPS and RTSP. The following parameters can be set for each protocol: port and enable/disable.
    std::vector<tt_NetworkProtocol> NetworkProtocols;
};


// XmlTraits for tds_SetNetworkProtocols
template<>
struct xml_convert::XmlTraits<tds_SetNetworkProtocols> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NetworkProtocols", &tds_SetNetworkProtocols::NetworkProtocols, "tds", xml_convert::serialize_type::full)
    );
};


// SetNetworkProtocolsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetNetworkProtocolsResponse {
};


// XmlTraits for tds_SetNetworkProtocolsResponse
template<>
struct xml_convert::XmlTraits<tds_SetNetworkProtocolsResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetNetworkDefaultGateway 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetNetworkDefaultGateway {
};


// XmlTraits for tds_GetNetworkDefaultGateway
template<>
struct xml_convert::XmlTraits<tds_GetNetworkDefaultGateway> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetNetworkDefaultGatewayResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetNetworkDefaultGatewayResponse {
    // Gets the default IPv4 and IPv6 gateway settings from the device.
    tt_NetworkGateway NetworkGateway;
};


// XmlTraits for tds_GetNetworkDefaultGatewayResponse
template<>
struct xml_convert::XmlTraits<tds_GetNetworkDefaultGatewayResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NetworkGateway", &tds_GetNetworkDefaultGatewayResponse::NetworkGateway, "tds", xml_convert::serialize_type::full)
    );
};


// SetNetworkDefaultGateway 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetNetworkDefaultGateway {
    // Sets IPv4 gateway address used as default setting.
    std::vector<tt_IPv4Address> IPv4Address;
    // Sets IPv6 gateway address used as default setting.
    std::vector<tt_IPv6Address> IPv6Address;
};


// XmlTraits for tds_SetNetworkDefaultGateway
template<>
struct xml_convert::XmlTraits<tds_SetNetworkDefaultGateway> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IPv4Address", &tds_SetNetworkDefaultGateway::IPv4Address, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("IPv6Address", &tds_SetNetworkDefaultGateway::IPv6Address, "tds", xml_convert::serialize_type::full)
    );
};


// SetNetworkDefaultGatewayResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetNetworkDefaultGatewayResponse {
};


// XmlTraits for tds_SetNetworkDefaultGatewayResponse
template<>
struct xml_convert::XmlTraits<tds_SetNetworkDefaultGatewayResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetZeroConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetZeroConfiguration {
};


// XmlTraits for tds_GetZeroConfiguration
template<>
struct xml_convert::XmlTraits<tds_GetZeroConfiguration> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetZeroConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetZeroConfigurationResponse {
    // Contains the zero-configuration.
    tt_NetworkZeroConfiguration ZeroConfiguration;
};


// XmlTraits for tds_GetZeroConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_GetZeroConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ZeroConfiguration", &tds_GetZeroConfigurationResponse::ZeroConfiguration, "tds", xml_convert::serialize_type::full)
    );
};


// SetZeroConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetZeroConfiguration {
    // Unique identifier referencing the physical interface.
    tt_ReferenceToken InterfaceToken;
    // Specifies if the zero-configuration should be enabled or not.
    bool Enabled {};
};


// XmlTraits for tds_SetZeroConfiguration
template<>
struct xml_convert::XmlTraits<tds_SetZeroConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("InterfaceToken", &tds_SetZeroConfiguration::InterfaceToken, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Enabled", &tds_SetZeroConfiguration::Enabled, "tds", xml_convert::serialize_type::full)
    );
};


// SetZeroConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetZeroConfigurationResponse {
};


// XmlTraits for tds_SetZeroConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_SetZeroConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetIPAddressFilter 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetIPAddressFilter {
};


// XmlTraits for tds_GetIPAddressFilter
template<>
struct xml_convert::XmlTraits<tds_GetIPAddressFilter> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetIPAddressFilterResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetIPAddressFilterResponse {
    tt_IPAddressFilter IPAddressFilter;
};


// XmlTraits for tds_GetIPAddressFilterResponse
template<>
struct xml_convert::XmlTraits<tds_GetIPAddressFilterResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IPAddressFilter", &tds_GetIPAddressFilterResponse::IPAddressFilter, "tds", xml_convert::serialize_type::full)
    );
};


// SetIPAddressFilter 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetIPAddressFilter {
    tt_IPAddressFilter IPAddressFilter;
};


// XmlTraits for tds_SetIPAddressFilter
template<>
struct xml_convert::XmlTraits<tds_SetIPAddressFilter> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IPAddressFilter", &tds_SetIPAddressFilter::IPAddressFilter, "tds", xml_convert::serialize_type::full)
    );
};


// SetIPAddressFilterResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetIPAddressFilterResponse {
};


// XmlTraits for tds_SetIPAddressFilterResponse
template<>
struct xml_convert::XmlTraits<tds_SetIPAddressFilterResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// AddIPAddressFilter 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_AddIPAddressFilter {
    tt_IPAddressFilter IPAddressFilter;
};


// XmlTraits for tds_AddIPAddressFilter
template<>
struct xml_convert::XmlTraits<tds_AddIPAddressFilter> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IPAddressFilter", &tds_AddIPAddressFilter::IPAddressFilter, "tds", xml_convert::serialize_type::full)
    );
};


// AddIPAddressFilterResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_AddIPAddressFilterResponse {
};


// XmlTraits for tds_AddIPAddressFilterResponse
template<>
struct xml_convert::XmlTraits<tds_AddIPAddressFilterResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// RemoveIPAddressFilter 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_RemoveIPAddressFilter {
    tt_IPAddressFilter IPAddressFilter;
};


// XmlTraits for tds_RemoveIPAddressFilter
template<>
struct xml_convert::XmlTraits<tds_RemoveIPAddressFilter> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("IPAddressFilter", &tds_RemoveIPAddressFilter::IPAddressFilter, "tds", xml_convert::serialize_type::full)
    );
};


// RemoveIPAddressFilterResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_RemoveIPAddressFilterResponse {
};


// XmlTraits for tds_RemoveIPAddressFilterResponse
template<>
struct xml_convert::XmlTraits<tds_RemoveIPAddressFilterResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAccessPolicy 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetAccessPolicy {
};


// XmlTraits for tds_GetAccessPolicy
template<>
struct xml_convert::XmlTraits<tds_GetAccessPolicy> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAccessPolicyResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetAccessPolicyResponse {
    tt_BinaryData PolicyFile;
};


// XmlTraits for tds_GetAccessPolicyResponse
template<>
struct xml_convert::XmlTraits<tds_GetAccessPolicyResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PolicyFile", &tds_GetAccessPolicyResponse::PolicyFile, "tds", xml_convert::serialize_type::full)
    );
};


// SetAccessPolicy 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetAccessPolicy {
    tt_BinaryData PolicyFile;
};


// XmlTraits for tds_SetAccessPolicy
template<>
struct xml_convert::XmlTraits<tds_SetAccessPolicy> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("PolicyFile", &tds_SetAccessPolicy::PolicyFile, "tds", xml_convert::serialize_type::full)
    );
};


// SetAccessPolicyResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetAccessPolicyResponse {
};


// XmlTraits for tds_SetAccessPolicyResponse
template<>
struct xml_convert::XmlTraits<tds_SetAccessPolicyResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// CreateCertificate 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_CreateCertificate {
    // Certificate id.
    std::optional<std::string> CertificateID;
    // Identification of the entity associated with the public-key.
    std::optional<std::string> Subject;
    // Certificate validity start date.
    std::optional<std::string> ValidNotBefore;
    // Certificate expiry start date.
    std::optional<std::string> ValidNotAfter;
};


// XmlTraits for tds_CreateCertificate
template<>
struct xml_convert::XmlTraits<tds_CreateCertificate> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tds_CreateCertificate::CertificateID, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Subject", &tds_CreateCertificate::Subject, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ValidNotBefore", &tds_CreateCertificate::ValidNotBefore, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ValidNotAfter", &tds_CreateCertificate::ValidNotAfter, "tds", xml_convert::serialize_type::full)
    );
};


// CreateCertificateResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_CreateCertificateResponse {
    // base64 encoded DER representation of certificate.
    tt_Certificate NvtCertificate;
};


// XmlTraits for tds_CreateCertificateResponse
template<>
struct xml_convert::XmlTraits<tds_CreateCertificateResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NvtCertificate", &tds_CreateCertificateResponse::NvtCertificate, "tds", xml_convert::serialize_type::full)
    );
};


// GetCertificates 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetCertificates {
};


// XmlTraits for tds_GetCertificates
template<>
struct xml_convert::XmlTraits<tds_GetCertificates> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetCertificatesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetCertificatesResponse {
    // Id and base64 encoded DER representation of all available certificates.
    std::vector<tt_Certificate> NvtCertificate;
};


// XmlTraits for tds_GetCertificatesResponse
template<>
struct xml_convert::XmlTraits<tds_GetCertificatesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NvtCertificate", &tds_GetCertificatesResponse::NvtCertificate, "tds", xml_convert::serialize_type::full)
    );
};


// GetCertificatesStatus 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetCertificatesStatus {
};


// XmlTraits for tds_GetCertificatesStatus
template<>
struct xml_convert::XmlTraits<tds_GetCertificatesStatus> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetCertificatesStatusResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetCertificatesStatusResponse {
    // Indicates if a certificate is used in an optional HTTPS configuration of the device.
    std::vector<tt_CertificateStatus> CertificateStatus;
};


// XmlTraits for tds_GetCertificatesStatusResponse
template<>
struct xml_convert::XmlTraits<tds_GetCertificatesStatusResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateStatus", &tds_GetCertificatesStatusResponse::CertificateStatus, "tds", xml_convert::serialize_type::full)
    );
};


// SetCertificatesStatus 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetCertificatesStatus {
    // Indicates if a certificate is to be used in an optional HTTPS configuration of the device.
    std::vector<tt_CertificateStatus> CertificateStatus;
};


// XmlTraits for tds_SetCertificatesStatus
template<>
struct xml_convert::XmlTraits<tds_SetCertificatesStatus> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateStatus", &tds_SetCertificatesStatus::CertificateStatus, "tds", xml_convert::serialize_type::full)
    );
};


// SetCertificatesStatusResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetCertificatesStatusResponse {
};


// XmlTraits for tds_SetCertificatesStatusResponse
template<>
struct xml_convert::XmlTraits<tds_SetCertificatesStatusResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteCertificates 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteCertificates {
    // List of ids of certificates to delete.
    std::vector<std::string> CertificateID;
};


// XmlTraits for tds_DeleteCertificates
template<>
struct xml_convert::XmlTraits<tds_DeleteCertificates> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tds_DeleteCertificates::CertificateID, "tds", xml_convert::serialize_type::full)
    );
};


// DeleteCertificatesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteCertificatesResponse {
};


// XmlTraits for tds_DeleteCertificatesResponse
template<>
struct xml_convert::XmlTraits<tds_DeleteCertificatesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetPkcs10Request 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetPkcs10Request {
    // List of ids of certificates to delete.
    std::string CertificateID;
    // Relative Dinstinguished Name(RDN) CommonName(CN).
    std::optional<std::string> Subject;
    // Optional base64 encoded DER attributes.
    std::optional<tt_BinaryData> Attributes;
};


// XmlTraits for tds_GetPkcs10Request
template<>
struct xml_convert::XmlTraits<tds_GetPkcs10Request> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tds_GetPkcs10Request::CertificateID, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Subject", &tds_GetPkcs10Request::Subject, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Attributes", &tds_GetPkcs10Request::Attributes, "tds", xml_convert::serialize_type::full)
    );
};


// GetPkcs10RequestResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetPkcs10RequestResponse {
    // base64 encoded DER representation of certificate.
    tt_BinaryData Pkcs10Request;
};


// XmlTraits for tds_GetPkcs10RequestResponse
template<>
struct xml_convert::XmlTraits<tds_GetPkcs10RequestResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Pkcs10Request", &tds_GetPkcs10RequestResponse::Pkcs10Request, "tds", xml_convert::serialize_type::full)
    );
};


// LoadCertificates 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_LoadCertificates {
    // Optional id and base64 encoded DER representation of certificate.
    std::vector<tt_Certificate> NVTCertificate;
};


// XmlTraits for tds_LoadCertificates
template<>
struct xml_convert::XmlTraits<tds_LoadCertificates> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("NVTCertificate", &tds_LoadCertificates::NVTCertificate, "tds", xml_convert::serialize_type::full)
    );
};


// LoadCertificatesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_LoadCertificatesResponse {
};


// XmlTraits for tds_LoadCertificatesResponse
template<>
struct xml_convert::XmlTraits<tds_LoadCertificatesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetClientCertificateMode 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetClientCertificateMode {
};


// XmlTraits for tds_GetClientCertificateMode
template<>
struct xml_convert::XmlTraits<tds_GetClientCertificateMode> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetClientCertificateModeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetClientCertificateModeResponse {
    // Indicates whether or not client certificates are required by device.
    bool Enabled {};
};


// XmlTraits for tds_GetClientCertificateModeResponse
template<>
struct xml_convert::XmlTraits<tds_GetClientCertificateModeResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tds_GetClientCertificateModeResponse::Enabled, "tds", xml_convert::serialize_type::full)
    );
};


// SetClientCertificateMode 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetClientCertificateMode {
    // Indicates whether or not client certificates are required by device.
    bool Enabled {};
};


// XmlTraits for tds_SetClientCertificateMode
template<>
struct xml_convert::XmlTraits<tds_SetClientCertificateMode> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Enabled", &tds_SetClientCertificateMode::Enabled, "tds", xml_convert::serialize_type::full)
    );
};


// SetClientCertificateModeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetClientCertificateModeResponse {
};


// XmlTraits for tds_SetClientCertificateModeResponse
template<>
struct xml_convert::XmlTraits<tds_SetClientCertificateModeResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetCACertificates 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetCACertificates {
};


// XmlTraits for tds_GetCACertificates
template<>
struct xml_convert::XmlTraits<tds_GetCACertificates> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetCACertificatesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetCACertificatesResponse {
    std::vector<tt_Certificate> CACertificate;
};


// XmlTraits for tds_GetCACertificatesResponse
template<>
struct xml_convert::XmlTraits<tds_GetCACertificatesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CACertificate", &tds_GetCACertificatesResponse::CACertificate, "tds", xml_convert::serialize_type::full)
    );
};


// LoadCertificateWithPrivateKey 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_LoadCertificateWithPrivateKey {
    std::vector<tt_CertificateWithPrivateKey> CertificateWithPrivateKey;
};


// XmlTraits for tds_LoadCertificateWithPrivateKey
template<>
struct xml_convert::XmlTraits<tds_LoadCertificateWithPrivateKey> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateWithPrivateKey", &tds_LoadCertificateWithPrivateKey::CertificateWithPrivateKey, "tds", xml_convert::serialize_type::full)
    );
};


// LoadCertificateWithPrivateKeyResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_LoadCertificateWithPrivateKeyResponse {
};


// XmlTraits for tds_LoadCertificateWithPrivateKeyResponse
template<>
struct xml_convert::XmlTraits<tds_LoadCertificateWithPrivateKeyResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetCertificateInformation 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetCertificateInformation {
    std::string CertificateID;
};


// XmlTraits for tds_GetCertificateInformation
template<>
struct xml_convert::XmlTraits<tds_GetCertificateInformation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateID", &tds_GetCertificateInformation::CertificateID, "tds", xml_convert::serialize_type::full)
    );
};


// GetCertificateInformationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetCertificateInformationResponse {
    tt_CertificateInformation CertificateInformation;
};


// XmlTraits for tds_GetCertificateInformationResponse
template<>
struct xml_convert::XmlTraits<tds_GetCertificateInformationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CertificateInformation", &tds_GetCertificateInformationResponse::CertificateInformation, "tds", xml_convert::serialize_type::full)
    );
};


// LoadCACertificates 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_LoadCACertificates {
    std::vector<tt_Certificate> CACertificate;
};


// XmlTraits for tds_LoadCACertificates
template<>
struct xml_convert::XmlTraits<tds_LoadCACertificates> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("CACertificate", &tds_LoadCACertificates::CACertificate, "tds", xml_convert::serialize_type::full)
    );
};


// LoadCACertificatesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_LoadCACertificatesResponse {
};


// XmlTraits for tds_LoadCACertificatesResponse
template<>
struct xml_convert::XmlTraits<tds_LoadCACertificatesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// CreateDot1XConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_CreateDot1XConfiguration {
    tt_Dot1XConfiguration Dot1XConfiguration;
};


// XmlTraits for tds_CreateDot1XConfiguration
template<>
struct xml_convert::XmlTraits<tds_CreateDot1XConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Dot1XConfiguration", &tds_CreateDot1XConfiguration::Dot1XConfiguration, "tds", xml_convert::serialize_type::full)
    );
};


// CreateDot1XConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_CreateDot1XConfigurationResponse {
};


// XmlTraits for tds_CreateDot1XConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_CreateDot1XConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetDot1XConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetDot1XConfiguration {
    tt_Dot1XConfiguration Dot1XConfiguration;
};


// XmlTraits for tds_SetDot1XConfiguration
template<>
struct xml_convert::XmlTraits<tds_SetDot1XConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Dot1XConfiguration", &tds_SetDot1XConfiguration::Dot1XConfiguration, "tds", xml_convert::serialize_type::full)
    );
};


// SetDot1XConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetDot1XConfigurationResponse {
};


// XmlTraits for tds_SetDot1XConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_SetDot1XConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetDot1XConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDot1XConfiguration {
    tt_ReferenceToken Dot1XConfigurationToken;
};


// XmlTraits for tds_GetDot1XConfiguration
template<>
struct xml_convert::XmlTraits<tds_GetDot1XConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Dot1XConfigurationToken", &tds_GetDot1XConfiguration::Dot1XConfigurationToken, "tds", xml_convert::serialize_type::full)
    );
};


// GetDot1XConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDot1XConfigurationResponse {
    tt_Dot1XConfiguration Dot1XConfiguration;
};


// XmlTraits for tds_GetDot1XConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_GetDot1XConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Dot1XConfiguration", &tds_GetDot1XConfigurationResponse::Dot1XConfiguration, "tds", xml_convert::serialize_type::full)
    );
};


// GetDot1XConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDot1XConfigurations {
};


// XmlTraits for tds_GetDot1XConfigurations
template<>
struct xml_convert::XmlTraits<tds_GetDot1XConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetDot1XConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDot1XConfigurationsResponse {
    std::vector<tt_Dot1XConfiguration> Dot1XConfiguration;
};


// XmlTraits for tds_GetDot1XConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tds_GetDot1XConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Dot1XConfiguration", &tds_GetDot1XConfigurationsResponse::Dot1XConfiguration, "tds", xml_convert::serialize_type::full)
    );
};


// DeleteDot1XConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteDot1XConfiguration {
    std::vector<tt_ReferenceToken> Dot1XConfigurationToken;
};


// XmlTraits for tds_DeleteDot1XConfiguration
template<>
struct xml_convert::XmlTraits<tds_DeleteDot1XConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Dot1XConfigurationToken", &tds_DeleteDot1XConfiguration::Dot1XConfigurationToken, "tds", xml_convert::serialize_type::full)
    );
};


// DeleteDot1XConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteDot1XConfigurationResponse {
};


// XmlTraits for tds_DeleteDot1XConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_DeleteDot1XConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRelayOutputs 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetRelayOutputs {
};


// XmlTraits for tds_GetRelayOutputs
template<>
struct xml_convert::XmlTraits<tds_GetRelayOutputs> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRelayOutputsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetRelayOutputsResponse {
    std::vector<tt_RelayOutput> RelayOutputs;
};


// XmlTraits for tds_GetRelayOutputsResponse
template<>
struct xml_convert::XmlTraits<tds_GetRelayOutputsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RelayOutputs", &tds_GetRelayOutputsResponse::RelayOutputs, "tds", xml_convert::serialize_type::full)
    );
};


// SetRelayOutputSettings 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetRelayOutputSettings {
    tt_ReferenceToken RelayOutputToken;
    tt_RelayOutputSettings Properties;
};


// XmlTraits for tds_SetRelayOutputSettings
template<>
struct xml_convert::XmlTraits<tds_SetRelayOutputSettings> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RelayOutputToken", &tds_SetRelayOutputSettings::RelayOutputToken, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Properties", &tds_SetRelayOutputSettings::Properties, "tds", xml_convert::serialize_type::full)
    );
};


// SetRelayOutputSettingsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetRelayOutputSettingsResponse {
};


// XmlTraits for tds_SetRelayOutputSettingsResponse
template<>
struct xml_convert::XmlTraits<tds_SetRelayOutputSettingsResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SetRelayOutputState 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetRelayOutputState {
    tt_ReferenceToken RelayOutputToken;
    tt_RelayLogicalState LogicalState;
};


// XmlTraits for tds_SetRelayOutputState
template<>
struct xml_convert::XmlTraits<tds_SetRelayOutputState> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RelayOutputToken", &tds_SetRelayOutputState::RelayOutputToken, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("LogicalState", &tds_SetRelayOutputState::LogicalState, "tds", xml_convert::serialize_type::full)
    );
};


// SetRelayOutputStateResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetRelayOutputStateResponse {
};


// XmlTraits for tds_SetRelayOutputStateResponse
template<>
struct xml_convert::XmlTraits<tds_SetRelayOutputStateResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// SendAuxiliaryCommand 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SendAuxiliaryCommand {
    tt_AuxiliaryData AuxiliaryCommand;
};


// XmlTraits for tds_SendAuxiliaryCommand
template<>
struct xml_convert::XmlTraits<tds_SendAuxiliaryCommand> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AuxiliaryCommand", &tds_SendAuxiliaryCommand::AuxiliaryCommand, "tds", xml_convert::serialize_type::full)
    );
};


// SendAuxiliaryCommandResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SendAuxiliaryCommandResponse {
    std::optional<tt_AuxiliaryData> AuxiliaryCommandResponse;
};


// XmlTraits for tds_SendAuxiliaryCommandResponse
template<>
struct xml_convert::XmlTraits<tds_SendAuxiliaryCommandResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AuxiliaryCommandResponse", &tds_SendAuxiliaryCommandResponse::AuxiliaryCommandResponse, "tds", xml_convert::serialize_type::full)
    );
};


// GetDot11Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDot11Capabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tds_GetDot11Capabilities
template<>
struct xml_convert::XmlTraits<tds_GetDot11Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tds_GetDot11Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// GetDot11CapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDot11CapabilitiesResponse {
    tt_Dot11Capabilities Capabilities;
};


// XmlTraits for tds_GetDot11CapabilitiesResponse
template<>
struct xml_convert::XmlTraits<tds_GetDot11CapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &tds_GetDot11CapabilitiesResponse::Capabilities, "tds", xml_convert::serialize_type::full)
    );
};


// GetDot11Status 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDot11Status {
    tt_ReferenceToken InterfaceToken;
};


// XmlTraits for tds_GetDot11Status
template<>
struct xml_convert::XmlTraits<tds_GetDot11Status> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("InterfaceToken", &tds_GetDot11Status::InterfaceToken, "tds", xml_convert::serialize_type::full)
    );
};


// GetDot11StatusResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetDot11StatusResponse {
    tt_Dot11Status Status;
};


// XmlTraits for tds_GetDot11StatusResponse
template<>
struct xml_convert::XmlTraits<tds_GetDot11StatusResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Status", &tds_GetDot11StatusResponse::Status, "tds", xml_convert::serialize_type::full)
    );
};


// ScanAvailableDot11Networks 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_ScanAvailableDot11Networks {
    tt_ReferenceToken InterfaceToken;
};


// XmlTraits for tds_ScanAvailableDot11Networks
template<>
struct xml_convert::XmlTraits<tds_ScanAvailableDot11Networks> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("InterfaceToken", &tds_ScanAvailableDot11Networks::InterfaceToken, "tds", xml_convert::serialize_type::full)
    );
};


// ScanAvailableDot11NetworksResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_ScanAvailableDot11NetworksResponse {
    std::vector<tt_Dot11AvailableNetworks> Networks;
};


// XmlTraits for tds_ScanAvailableDot11NetworksResponse
template<>
struct xml_convert::XmlTraits<tds_ScanAvailableDot11NetworksResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Networks", &tds_ScanAvailableDot11NetworksResponse::Networks, "tds", xml_convert::serialize_type::full)
    );
};


// GetSystemUris 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetSystemUris {
};


// XmlTraits for tds_GetSystemUris
template<>
struct xml_convert::XmlTraits<tds_GetSystemUris> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Extension 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_Extension {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tds_Extension
template<>
struct xml_convert::XmlTraits<tds_Extension> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tds_Extension::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// GetSystemUrisResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetSystemUrisResponse {
    std::optional<tt_SystemLogUriList> SystemLogUris;
    std::optional<std::string> SupportInfoUri;
    std::optional<std::string> SystemBackupUri;
    std::optional<tds_Extension> Extension;
};


// XmlTraits for tds_GetSystemUrisResponse
template<>
struct xml_convert::XmlTraits<tds_GetSystemUrisResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SystemLogUris", &tds_GetSystemUrisResponse::SystemLogUris, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SupportInfoUri", &tds_GetSystemUrisResponse::SupportInfoUri, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("SystemBackupUri", &tds_GetSystemUrisResponse::SystemBackupUri, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tds_GetSystemUrisResponse::Extension, "tds", xml_convert::serialize_type::full)
    );
};


// StartFirmwareUpgrade 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_StartFirmwareUpgrade {
};


// XmlTraits for tds_StartFirmwareUpgrade
template<>
struct xml_convert::XmlTraits<tds_StartFirmwareUpgrade> {
    static constexpr auto fields = std::make_tuple(

    );
};


// StartFirmwareUpgradeResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_StartFirmwareUpgradeResponse {
    std::string UploadUri;
    my_Duration UploadDelay;
    my_Duration ExpectedDownTime;
};


// XmlTraits for tds_StartFirmwareUpgradeResponse
template<>
struct xml_convert::XmlTraits<tds_StartFirmwareUpgradeResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("UploadUri", &tds_StartFirmwareUpgradeResponse::UploadUri, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("UploadDelay", &tds_StartFirmwareUpgradeResponse::UploadDelay, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ExpectedDownTime", &tds_StartFirmwareUpgradeResponse::ExpectedDownTime, "tds", xml_convert::serialize_type::full)
    );
};


// UpgradeFirmware 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_UpgradeFirmware {
    std::string Version;
};


// XmlTraits for tds_UpgradeFirmware
template<>
struct xml_convert::XmlTraits<tds_UpgradeFirmware> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Version", &tds_UpgradeFirmware::Version, "tds", xml_convert::serialize_type::full)
    );
};


// UpgradeFirmwareResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_UpgradeFirmwareResponse {
    my_Duration ExpectedDownTime;
};


// XmlTraits for tds_UpgradeFirmwareResponse
template<>
struct xml_convert::XmlTraits<tds_UpgradeFirmwareResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ExpectedDownTime", &tds_UpgradeFirmwareResponse::ExpectedDownTime, "tds", xml_convert::serialize_type::full)
    );
};


// StartSystemRestore 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_StartSystemRestore {
};


// XmlTraits for tds_StartSystemRestore
template<>
struct xml_convert::XmlTraits<tds_StartSystemRestore> {
    static constexpr auto fields = std::make_tuple(

    );
};


// StartSystemRestoreResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_StartSystemRestoreResponse {
    std::string UploadUri;
    my_Duration ExpectedDownTime;
};


// XmlTraits for tds_StartSystemRestoreResponse
template<>
struct xml_convert::XmlTraits<tds_StartSystemRestoreResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("UploadUri", &tds_StartSystemRestoreResponse::UploadUri, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ExpectedDownTime", &tds_StartSystemRestoreResponse::ExpectedDownTime, "tds", xml_convert::serialize_type::full)
    );
};


// SetHashingAlgorithm 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetHashingAlgorithm {
    // Hashing algorithm(s) used in HTTP and RTSP Digest Authentication.
    tt_StringList Algorithm;
};


// XmlTraits for tds_SetHashingAlgorithm
template<>
struct xml_convert::XmlTraits<tds_SetHashingAlgorithm> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Algorithm", &tds_SetHashingAlgorithm::Algorithm, "tds", xml_convert::serialize_type::full)
    );
};


// SetHashingAlgorithmResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetHashingAlgorithmResponse {
};


// XmlTraits for tds_SetHashingAlgorithmResponse
template<>
struct xml_convert::XmlTraits<tds_SetHashingAlgorithmResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// UserCredential 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_UserCredential {
    // User name
    std::string UserName;
    // optional password, device shall not return the credentials (password) in the reply.
    std::optional<std::string> Password;
    std::optional<tds_Extension> Extension;
    // optional access token, device shall not return the credentials (token) in the reply.
    std::optional<std::string> Token;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
};


// XmlTraits for tds_UserCredential
template<>
struct xml_convert::XmlTraits<tds_UserCredential> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("UserName", &tds_UserCredential::UserName, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Password", &tds_UserCredential::Password, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tds_UserCredential::Extension, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Token", &tds_UserCredential::Token, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tds_UserCredential::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element)
    );
};


// StorageType 枚举类型
// 基础类型: std::string
enum class  tds_StorageType {
    NFS,
    CIFS,
    CDMI,
    FTP,
    ObjectStorageS3,
    ObjectStorageAzure
};

// 字符串转换函数
inline std::string to_string(tds_StorageType value) {
    switch (value) {
        case tds_StorageType::NFS: return "NFS";
        case tds_StorageType::CIFS: return "CIFS";
        case tds_StorageType::CDMI: return "CDMI";
        case tds_StorageType::FTP: return "FTP";
        case tds_StorageType::ObjectStorageS3: return "ObjectStorageS3";
        case tds_StorageType::ObjectStorageAzure: return "ObjectStorageAzure";
        default: return "";
    }
}

inline bool from_string(tds_StorageType& value, const std::string& str) {
    if (str == "NFS") { value = tds_StorageType::NFS; return true; }
    if (str == "CIFS") { value = tds_StorageType::CIFS; return true; }
    if (str == "CDMI") { value = tds_StorageType::CDMI; return true; }
    if (str == "FTP") { value = tds_StorageType::FTP; return true; }
    if (str == "ObjectStorageS3") { value = tds_StorageType::ObjectStorageS3; return true; }
    if (str == "ObjectStorageAzure") { value = tds_StorageType::ObjectStorageAzure; return true; }
    return false;
}


// XmlValueAdapter specialization for enum tds_StorageType
template<>
struct xml_convert::XmlValueAdapter<tds_StorageType> {
    static bool from_xml_val(tds_StorageType& val, xmlNodePtr element, const char* name = nullptr,
                             const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        xmlNodePtr targetElement = name ? 
            xmlGetChildElementByName(element, name) : element;
        if (!targetElement) return false;
        xmlChar* content = xmlNodeGetContent(targetElement);
        if (!content) return false;
        std::string str_val(reinterpret_cast<char*>(content));
        xmlFree(content);
        return from_string(val, str_val);
    }
    
    static bool to_xml_val(const tds_StorageType& val, xmlNodePtr parent, const char* name,
                           const char* ns_prefix = nullptr, const std::map<std::string_view, std::string_view>& namespaces = {}) {
        if (!parent || !name) return false;
        xmlNodePtr element = create_element_with_ns(parent, name, ns_prefix, namespaces);
        if (!element) return false;
        xmlNodeSetContent(element, BAD_CAST to_string(val).c_str());
        return true;
    }
    
private:
    static xmlNodePtr create_element_with_ns(xmlNodePtr parent, const char* name, 
                                            const char* ns_prefix, const std::map<std::string_view, std::string_view>& namespaces) {
        xmlNodePtr element = xmlNewChild(parent, nullptr, BAD_CAST name, nullptr);
        if (element && ns_prefix) {
            auto it = namespaces.find(ns_prefix);
            if (it != namespaces.end()) {
                xmlNsPtr ns = xmlNewNs(element, BAD_CAST it->second.data(), BAD_CAST ns_prefix);
                xmlSetNs(element, ns);
            }
        }
        return element;
    }
    
    static xmlNodePtr xmlGetChildElementByName(xmlNodePtr parent, const char* name) {
        if (!parent || !name) return nullptr;
        for (xmlNodePtr child = parent->children; child; child = child->next) {
            if (child->type == XML_ELEMENT_NODE && 
                xmlStrcmp(child->name, BAD_CAST name) == 0) {
                return child;
            }
        }
        return nullptr;
    }
};

// XmlAttributeAdapter specialization for enum tds_StorageType
template<>
struct xml_convert::XmlAttributeAdapter<tds_StorageType> {
    static bool to_attribute(xmlNodePtr element, const char* name, const tds_StorageType& value) {
        if (!element || !name) return false;
        std::string str_val = to_string(value);
        xmlSetProp(element, BAD_CAST name, BAD_CAST str_val.c_str());
        return true;
    }

    static bool from_attribute(tds_StorageType& value, xmlNodePtr element, const char* name) {
        if (!element || !name) return false;
        xmlChar* attr = xmlGetProp(element, BAD_CAST name);
        if (!attr) return false;
        std::string str_val(reinterpret_cast<char*>(attr));
        xmlFree(attr);
        return from_string(value, str_val);
    }
};


// ConfigurationRenewal 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_ConfigurationRenewal {
    // Remote URL to be queried by the device to renew the storage configuration.
    std::string RenewalEndpoint;
    // AuthorizationServer token referring to the server that provides access tokens to authorize with the the renewal endpoint.
    tt_ReferenceToken AuthorizationServer;
    /*
     * CertPathValidationPolicyID used to validate the renewal endpoint server certificate.
     * If not configured, server certificate validation behavior is undefined and the device may either apply
     * a vendor specific default validation policy or skip validation at all.
     */
    std::optional<std::string> CertPathValidationPolicyID;
    // Optional user readable error information (readonly).
    std::optional<std::string> Error;
};


// XmlTraits for tds_ConfigurationRenewal
template<>
struct xml_convert::XmlTraits<tds_ConfigurationRenewal> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RenewalEndpoint", &tds_ConfigurationRenewal::RenewalEndpoint, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AuthorizationServer", &tds_ConfigurationRenewal::AuthorizationServer, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CertPathValidationPolicyID", &tds_ConfigurationRenewal::CertPathValidationPolicyID, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Error", &tds_ConfigurationRenewal::Error, "tds", xml_convert::serialize_type::full)
    );
};


// StorageConfigurationData 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_StorageConfigurationData {
    // Local path
    std::optional<std::string> LocalPath;
    // Storage server address
    std::optional<std::string> StorageUri;
    // User credential for the storage server
    std::optional<tds_UserCredential> User;
    std::optional<tds_Extension> Extension;
    // The unique identifier of the certification path validation policy to be used for validating the server certificate as declared in the security service.
    std::optional<std::string> CertPathValidationPolicyID;
    std::optional<tds_ConfigurationRenewal> ConfigurationRenewal;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // tds:StorageType lists the acceptable values for type attribute
    std::string type;
    // Optional region of the storage server
    std::optional<std::string> Region;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tds_StorageConfigurationData
template<>
struct xml_convert::XmlTraits<tds_StorageConfigurationData> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("LocalPath", &tds_StorageConfigurationData::LocalPath, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("StorageUri", &tds_StorageConfigurationData::StorageUri, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("User", &tds_StorageConfigurationData::User, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Extension", &tds_StorageConfigurationData::Extension, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("CertPathValidationPolicyID", &tds_StorageConfigurationData::CertPathValidationPolicyID, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationRenewal", &tds_StorageConfigurationData::ConfigurationRenewal, "tds", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tds_StorageConfigurationData::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("type", &tds_StorageConfigurationData::type, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Region", &tds_StorageConfigurationData::Region, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tds_StorageConfigurationData::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// StorageConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_StorageConfiguration : public tt_DeviceEntity {
    tds_StorageConfigurationData Data;
};


// XmlTraits for tds_StorageConfiguration
template<>
struct xml_convert::XmlTraits<tds_StorageConfiguration> {
    static constexpr auto fields = std::tuple_cat(xml_convert::XmlTraits<tt_DeviceEntity>::fields, std::make_tuple(
        xml_convert::make_field_desc("Data", &tds_StorageConfiguration::Data, "tds", xml_convert::serialize_type::full))
    );
};


// GetStorageConfigurations 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetStorageConfigurations {
};


// XmlTraits for tds_GetStorageConfigurations
template<>
struct xml_convert::XmlTraits<tds_GetStorageConfigurations> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetStorageConfigurationsResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetStorageConfigurationsResponse {
    std::vector<tds_StorageConfiguration> StorageConfigurations;
};


// XmlTraits for tds_GetStorageConfigurationsResponse
template<>
struct xml_convert::XmlTraits<tds_GetStorageConfigurationsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StorageConfigurations", &tds_GetStorageConfigurationsResponse::StorageConfigurations, "tds", xml_convert::serialize_type::full)
    );
};


// CreateStorageConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_CreateStorageConfiguration {
    tds_StorageConfigurationData StorageConfiguration;
};


// XmlTraits for tds_CreateStorageConfiguration
template<>
struct xml_convert::XmlTraits<tds_CreateStorageConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StorageConfiguration", &tds_CreateStorageConfiguration::StorageConfiguration, "tds", xml_convert::serialize_type::full)
    );
};


// CreateStorageConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_CreateStorageConfigurationResponse {
    tt_ReferenceToken Token;
};


// XmlTraits for tds_CreateStorageConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_CreateStorageConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tds_CreateStorageConfigurationResponse::Token, "tds", xml_convert::serialize_type::full)
    );
};


// GetStorageConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetStorageConfiguration {
    tt_ReferenceToken Token;
};


// XmlTraits for tds_GetStorageConfiguration
template<>
struct xml_convert::XmlTraits<tds_GetStorageConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tds_GetStorageConfiguration::Token, "tds", xml_convert::serialize_type::full)
    );
};


// GetStorageConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetStorageConfigurationResponse {
    tds_StorageConfiguration StorageConfiguration;
};


// XmlTraits for tds_GetStorageConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_GetStorageConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StorageConfiguration", &tds_GetStorageConfigurationResponse::StorageConfiguration, "tds", xml_convert::serialize_type::full)
    );
};


// SetStorageConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetStorageConfiguration {
    tds_StorageConfiguration StorageConfiguration;
};


// XmlTraits for tds_SetStorageConfiguration
template<>
struct xml_convert::XmlTraits<tds_SetStorageConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("StorageConfiguration", &tds_SetStorageConfiguration::StorageConfiguration, "tds", xml_convert::serialize_type::full)
    );
};


// SetStorageConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetStorageConfigurationResponse {
};


// XmlTraits for tds_SetStorageConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_SetStorageConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteStorageConfiguration 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteStorageConfiguration {
    tt_ReferenceToken Token;
};


// XmlTraits for tds_DeleteStorageConfiguration
template<>
struct xml_convert::XmlTraits<tds_DeleteStorageConfiguration> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Token", &tds_DeleteStorageConfiguration::Token, "tds", xml_convert::serialize_type::full)
    );
};


// DeleteStorageConfigurationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteStorageConfigurationResponse {
};


// XmlTraits for tds_DeleteStorageConfigurationResponse
template<>
struct xml_convert::XmlTraits<tds_DeleteStorageConfigurationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetGeoLocation 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetGeoLocation {
};


// XmlTraits for tds_GetGeoLocation
template<>
struct xml_convert::XmlTraits<tds_GetGeoLocation> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetGeoLocationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_GetGeoLocationResponse {
    std::vector<tt_LocationEntity> Location;
};


// XmlTraits for tds_GetGeoLocationResponse
template<>
struct xml_convert::XmlTraits<tds_GetGeoLocationResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Location", &tds_GetGeoLocationResponse::Location, "tds", xml_convert::serialize_type::full)
    );
};


// SetGeoLocation 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetGeoLocation {
    std::vector<tt_LocationEntity> Location;
};


// XmlTraits for tds_SetGeoLocation
template<>
struct xml_convert::XmlTraits<tds_SetGeoLocation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Location", &tds_SetGeoLocation::Location, "tds", xml_convert::serialize_type::full)
    );
};


// SetGeoLocationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_SetGeoLocationResponse {
};


// XmlTraits for tds_SetGeoLocationResponse
template<>
struct xml_convert::XmlTraits<tds_SetGeoLocationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteGeoLocation 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteGeoLocation {
    std::vector<tt_LocationEntity> Location;
};


// XmlTraits for tds_DeleteGeoLocation
template<>
struct xml_convert::XmlTraits<tds_DeleteGeoLocation> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Location", &tds_DeleteGeoLocation::Location, "tds", xml_convert::serialize_type::full)
    );
};


// DeleteGeoLocationResponse 类型定义
// 命名空间: http://www.onvif.org/ver10/device/wsdl
// 源文件: devicemgmt_v10.wsdl
struct tds_DeleteGeoLocationResponse {
};


// XmlTraits for tds_DeleteGeoLocationResponse
template<>
struct xml_convert::XmlTraits<tds_DeleteGeoLocationResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


} // namespace libonvif_client
