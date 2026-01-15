/**
 * @file tan.h
 * @brief 从 analytics_v20.wsdl 生成的类型定义
 * @namespace http://www.onvif.org/ver20/analytics/wsdl
 * @note 此文件由 wsdl_parser2 自动生成，请勿手动修改
 */

#pragma once

// 依赖的类型定义
#include <libonvif_client/types/common.h>
#include <libonvif_client/types/metadata.h>
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

// GetServiceCapabilities 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetServiceCapabilities {
};


// XmlTraits for tan_GetServiceCapabilities
template<>
struct xml_convert::XmlTraits<tan_GetServiceCapabilities> {
    static constexpr auto fields = std::make_tuple(

    );
};


// Capabilities 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_Capabilities {
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Indication that the device supports the rules interface and the rules syntax.
    std::optional<bool> RuleSupport;
    // Indication that the device supports the scene analytics module interface.
    std::optional<bool> AnalyticsModuleSupport;
    // Indication that the device produces the cell based scene description
    std::optional<bool> CellBasedSceneDescriptionSupported;
    // Indication that the device supports the GetRuleOptions operation on the rules interface
    std::optional<bool> RuleOptionsSupported;
    // Indication that the device supports the GetAnalyticsModuleOptions operation on the analytics interface
    std::optional<bool> AnalyticsModuleOptionsSupported;
    // Indication that the device supports the GetSupportedMetadata operation.
    std::optional<bool> SupportedMetadata;
    // Indication what kinds of method that the device support for sending image, acceptable values are defined in tt:ImageSendingType.
    std::optional<tt_StringList> ImageSendingType;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tan_Capabilities
template<>
struct xml_convert::XmlTraits<tan_Capabilities> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tan_Capabilities::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("RuleSupport", &tan_Capabilities::RuleSupport, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AnalyticsModuleSupport", &tan_Capabilities::AnalyticsModuleSupport, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("CellBasedSceneDescriptionSupported", &tan_Capabilities::CellBasedSceneDescriptionSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("RuleOptionsSupported", &tan_Capabilities::RuleOptionsSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AnalyticsModuleOptionsSupported", &tan_Capabilities::AnalyticsModuleOptionsSupported, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("SupportedMetadata", &tan_Capabilities::SupportedMetadata, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("ImageSendingType", &tan_Capabilities::ImageSendingType, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tan_Capabilities::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetServiceCapabilitiesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetServiceCapabilitiesResponse {
    // The capabilities for the analytics service is returned in the Capabilities element.
    tan_Capabilities Capabilities;
};


// XmlTraits for tan_GetServiceCapabilitiesResponse
template<>
struct xml_convert::XmlTraits<tan_GetServiceCapabilitiesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Capabilities", &tan_GetServiceCapabilitiesResponse::Capabilities, "tan", xml_convert::serialize_type::full)
    );
};


// GetSupportedRules 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetSupportedRules {
    /*
     * References an existing Video Analytics configuration. The list of available tokens can be obtained
     * via the Media service GetVideoAnalyticsConfigurations method.
     */
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tan_GetSupportedRules
template<>
struct xml_convert::XmlTraits<tan_GetSupportedRules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tan_GetSupportedRules::ConfigurationToken, "tan", xml_convert::serialize_type::full)
    );
};


// GetSupportedRulesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetSupportedRulesResponse {
    tt_SupportedRules SupportedRules;
};


// XmlTraits for tan_GetSupportedRulesResponse
template<>
struct xml_convert::XmlTraits<tan_GetSupportedRulesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SupportedRules", &tan_GetSupportedRulesResponse::SupportedRules, "tan", xml_convert::serialize_type::full)
    );
};


// CreateRules 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_CreateRules {
    // Reference to an existing VideoAnalyticsConfiguration.
    tt_ReferenceToken ConfigurationToken;
    std::vector<tt_Config> Rule;
};


// XmlTraits for tan_CreateRules
template<>
struct xml_convert::XmlTraits<tan_CreateRules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tan_CreateRules::ConfigurationToken, "tan", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Rule", &tan_CreateRules::Rule, "tan", xml_convert::serialize_type::full)
    );
};


// CreateRulesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_CreateRulesResponse {
};


// XmlTraits for tan_CreateRulesResponse
template<>
struct xml_convert::XmlTraits<tan_CreateRulesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteRules 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_DeleteRules {
    // Reference to an existing VideoAnalyticsConfiguration.
    tt_ReferenceToken ConfigurationToken;
    // References the specific rule to be deleted (e.g. "MyLineDetector").
    std::vector<std::string> RuleName;
};


// XmlTraits for tan_DeleteRules
template<>
struct xml_convert::XmlTraits<tan_DeleteRules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tan_DeleteRules::ConfigurationToken, "tan", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("RuleName", &tan_DeleteRules::RuleName, "tan", xml_convert::serialize_type::full)
    );
};


// DeleteRulesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_DeleteRulesResponse {
};


// XmlTraits for tan_DeleteRulesResponse
template<>
struct xml_convert::XmlTraits<tan_DeleteRulesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// ModifyRules 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_ModifyRules {
    // Reference to an existing VideoAnalyticsConfiguration.
    tt_ReferenceToken ConfigurationToken;
    std::vector<tt_Config> Rule;
};


// XmlTraits for tan_ModifyRules
template<>
struct xml_convert::XmlTraits<tan_ModifyRules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tan_ModifyRules::ConfigurationToken, "tan", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("Rule", &tan_ModifyRules::Rule, "tan", xml_convert::serialize_type::full)
    );
};


// ModifyRulesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_ModifyRulesResponse {
};


// XmlTraits for tan_ModifyRulesResponse
template<>
struct xml_convert::XmlTraits<tan_ModifyRulesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetRules 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetRules {
    // Reference to an existing VideoAnalyticsConfiguration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tan_GetRules
template<>
struct xml_convert::XmlTraits<tan_GetRules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tan_GetRules::ConfigurationToken, "tan", xml_convert::serialize_type::full)
    );
};


// GetRulesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetRulesResponse {
    std::vector<tt_Config> Rule;
};


// XmlTraits for tan_GetRulesResponse
template<>
struct xml_convert::XmlTraits<tan_GetRulesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Rule", &tan_GetRulesResponse::Rule, "tan", xml_convert::serialize_type::full)
    );
};


// GetRuleOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetRuleOptions {
    // Reference to an SupportedRule Type returned from GetSupportedRules.
    std::optional<std::string> RuleType;
    // Reference to an existing analytics configuration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tan_GetRuleOptions
template<>
struct xml_convert::XmlTraits<tan_GetRuleOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RuleType", &tan_GetRuleOptions::RuleType, "tan", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &tan_GetRuleOptions::ConfigurationToken, "tan", xml_convert::serialize_type::full)
    );
};


// ConfigOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_ConfigOptions {
    // Any element from namespace: ##any (processContents: strict)
    AnyElement _any_;
    // The RuleType the ConfigOptions applies to if the Name attribute is ambiguous.
    std::optional<std::string> RuleType;
    /*
     * The Name of the SimpleItemDescription/ElementItemDescription
     * the ConfigOptions applies to.
     */
    std::string Name;
    /*
     * Type of the Rule Options represented by a unique QName.
     * The Type defines the element contained in this structure.
     * This attribute is deprecated since its value must be identical to the embedded element.
     */
    std::optional<std::string> Type;
    // Optional name of the analytics module this constraint applies to. This option is only necessary in cases where different constraints for elements with the same Name exist.
    std::optional<std::string> AnalyticsModule;
    // Minimal number of occurrences. Defaults to one.
    std::optional<int32_t> minOccurs;
    // Maximum number of occurrences. Defaults to one.
    std::optional<int32_t> maxOccurs;
    // Any attributes allowed (namespace: ##other, processContents: lax)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tan_ConfigOptions
template<>
struct xml_convert::XmlTraits<tan_ConfigOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("_any_", &tan_ConfigOptions::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("RuleType", &tan_ConfigOptions::RuleType, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Name", &tan_ConfigOptions::Name, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("Type", &tan_ConfigOptions::Type, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("AnalyticsModule", &tan_ConfigOptions::AnalyticsModule, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("minOccurs", &tan_ConfigOptions::minOccurs, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("maxOccurs", &tan_ConfigOptions::maxOccurs, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tan_ConfigOptions::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetRuleOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetRuleOptionsResponse {
    // A device shall provide respective ConfigOptions.RuleType for each RuleOption if the request does not specify RuleType. The response Options shall not contain any AnalyticsModule attribute.
    std::vector<tan_ConfigOptions> RuleOptions;
};


// XmlTraits for tan_GetRuleOptionsResponse
template<>
struct xml_convert::XmlTraits<tan_GetRuleOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("RuleOptions", &tan_GetRuleOptionsResponse::RuleOptions, "tan", xml_convert::serialize_type::full)
    );
};


// GetSupportedAnalyticsModules 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetSupportedAnalyticsModules {
    // Reference to an existing VideoAnalyticsConfiguration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tan_GetSupportedAnalyticsModules
template<>
struct xml_convert::XmlTraits<tan_GetSupportedAnalyticsModules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tan_GetSupportedAnalyticsModules::ConfigurationToken, "tan", xml_convert::serialize_type::full)
    );
};


// GetSupportedAnalyticsModulesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetSupportedAnalyticsModulesResponse {
    tt_SupportedAnalyticsModules SupportedAnalyticsModules;
};


// XmlTraits for tan_GetSupportedAnalyticsModulesResponse
template<>
struct xml_convert::XmlTraits<tan_GetSupportedAnalyticsModulesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SupportedAnalyticsModules", &tan_GetSupportedAnalyticsModulesResponse::SupportedAnalyticsModules, "tan", xml_convert::serialize_type::full)
    );
};


// CreateAnalyticsModules 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_CreateAnalyticsModules {
    // Reference to an existing VideoAnalyticsConfiguration.
    tt_ReferenceToken ConfigurationToken;
    std::vector<tt_Config> AnalyticsModule;
};


// XmlTraits for tan_CreateAnalyticsModules
template<>
struct xml_convert::XmlTraits<tan_CreateAnalyticsModules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tan_CreateAnalyticsModules::ConfigurationToken, "tan", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AnalyticsModule", &tan_CreateAnalyticsModules::AnalyticsModule, "tan", xml_convert::serialize_type::full)
    );
};


// CreateAnalyticsModulesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_CreateAnalyticsModulesResponse {
};


// XmlTraits for tan_CreateAnalyticsModulesResponse
template<>
struct xml_convert::XmlTraits<tan_CreateAnalyticsModulesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// DeleteAnalyticsModules 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_DeleteAnalyticsModules {
    // Reference to an existing Video Analytics configuration.
    tt_ReferenceToken ConfigurationToken;
    // Name of the AnalyticsModule to be deleted.
    std::vector<std::string> AnalyticsModuleName;
};


// XmlTraits for tan_DeleteAnalyticsModules
template<>
struct xml_convert::XmlTraits<tan_DeleteAnalyticsModules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tan_DeleteAnalyticsModules::ConfigurationToken, "tan", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AnalyticsModuleName", &tan_DeleteAnalyticsModules::AnalyticsModuleName, "tan", xml_convert::serialize_type::full)
    );
};


// DeleteAnalyticsModulesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_DeleteAnalyticsModulesResponse {
};


// XmlTraits for tan_DeleteAnalyticsModulesResponse
template<>
struct xml_convert::XmlTraits<tan_DeleteAnalyticsModulesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// ModifyAnalyticsModules 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_ModifyAnalyticsModules {
    // Reference to an existing VideoAnalyticsConfiguration.
    tt_ReferenceToken ConfigurationToken;
    std::vector<tt_Config> AnalyticsModule;
};


// XmlTraits for tan_ModifyAnalyticsModules
template<>
struct xml_convert::XmlTraits<tan_ModifyAnalyticsModules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tan_ModifyAnalyticsModules::ConfigurationToken, "tan", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("AnalyticsModule", &tan_ModifyAnalyticsModules::AnalyticsModule, "tan", xml_convert::serialize_type::full)
    );
};


// ModifyAnalyticsModulesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_ModifyAnalyticsModulesResponse {
};


// XmlTraits for tan_ModifyAnalyticsModulesResponse
template<>
struct xml_convert::XmlTraits<tan_ModifyAnalyticsModulesResponse> {
    static constexpr auto fields = std::make_tuple(

    );
};


// GetAnalyticsModules 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetAnalyticsModules {
    // Reference to an existing VideoAnalyticsConfiguration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tan_GetAnalyticsModules
template<>
struct xml_convert::XmlTraits<tan_GetAnalyticsModules> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("ConfigurationToken", &tan_GetAnalyticsModules::ConfigurationToken, "tan", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsModulesResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetAnalyticsModulesResponse {
    std::vector<tt_Config> AnalyticsModule;
};


// XmlTraits for tan_GetAnalyticsModulesResponse
template<>
struct xml_convert::XmlTraits<tan_GetAnalyticsModulesResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AnalyticsModule", &tan_GetAnalyticsModulesResponse::AnalyticsModule, "tan", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsModuleOptions 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetAnalyticsModuleOptions {
    // Reference to an SupportedAnalyticsModule Type returned from GetSupportedAnalyticsModules.
    std::optional<std::string> Type;
    // Reference to an existing AnalyticsConfiguration.
    tt_ReferenceToken ConfigurationToken;
};


// XmlTraits for tan_GetAnalyticsModuleOptions
template<>
struct xml_convert::XmlTraits<tan_GetAnalyticsModuleOptions> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tan_GetAnalyticsModuleOptions::Type, "tan", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("ConfigurationToken", &tan_GetAnalyticsModuleOptions::ConfigurationToken, "tan", xml_convert::serialize_type::full)
    );
};


// GetAnalyticsModuleOptionsResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetAnalyticsModuleOptionsResponse {
    // List of options for the specified analytics module. The response Options shall not contain any RuleType attribute.
    std::vector<tan_ConfigOptions> Options;
};


// XmlTraits for tan_GetAnalyticsModuleOptionsResponse
template<>
struct xml_convert::XmlTraits<tan_GetAnalyticsModuleOptionsResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Options", &tan_GetAnalyticsModuleOptionsResponse::Options, "tan", xml_convert::serialize_type::full)
    );
};


// GetSupportedMetadata 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetSupportedMetadata {
    // Optional reference to an AnalyticsModule Type returned from GetSupportedAnalyticsModules.
    std::optional<std::string> Type;
};


// XmlTraits for tan_GetSupportedMetadata
template<>
struct xml_convert::XmlTraits<tan_GetSupportedMetadata> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("Type", &tan_GetSupportedMetadata::Type, "tan", xml_convert::serialize_type::full)
    );
};


// MetadataInfo 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_MetadataInfo {
    // Sample frame content starting with the tt:Frame node.
    tt_Frame SampleFrame;
    // Collection of any elements from namespace: ##any (processContents: lax)
    std::vector<AnyElement> _any_;
    // Reference to an AnalyticsModule Type.
    std::string Type;
    // Any attributes allowed (namespace: ##other, processContents: strict)
    std::optional<std::map<std::string, std::string>> _attrs_;
};


// XmlTraits for tan_MetadataInfo
template<>
struct xml_convert::XmlTraits<tan_MetadataInfo> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("SampleFrame", &tan_MetadataInfo::SampleFrame, "tan", xml_convert::serialize_type::full),
        xml_convert::make_field_desc("_any_", &tan_MetadataInfo::_any_, nullptr, xml_convert::serialize_type::full | xml_convert::serialize_type::any_element),
        xml_convert::make_field_desc("Type", &tan_MetadataInfo::Type, nullptr, xml_convert::serialize_type::attribute),
        xml_convert::make_field_desc("_attrs_", &tan_MetadataInfo::_attrs_, nullptr, xml_convert::serialize_type::attribute)
    );
};


// GetSupportedMetadataResponse 类型定义
// 命名空间: http://www.onvif.org/ver20/analytics/wsdl
// 源文件: analytics_v20.wsdl
struct tan_GetSupportedMetadataResponse {
    std::vector<tan_MetadataInfo> AnalyticsModule;
};


// XmlTraits for tan_GetSupportedMetadataResponse
template<>
struct xml_convert::XmlTraits<tan_GetSupportedMetadataResponse> {
    static constexpr auto fields = std::make_tuple(
        xml_convert::make_field_desc("AnalyticsModule", &tan_GetSupportedMetadataResponse::AnalyticsModule, "tan", xml_convert::serialize_type::full)
    );
};


} // namespace libonvif_client
