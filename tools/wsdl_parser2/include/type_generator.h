/**
 * @file type_generator.h
 * @brief 类型定义代码生成器
 */

#pragma once

#include "file_info.h"
#include "config.h"
#include "type_utils.h"
#include <string>
#include <vector>
#include <map>
#include <set>

namespace wsdl_parser2 {

/**
 * @brief 代码生成选项
 */
struct GeneratorOptions {
    std::string indent = "    ";            // 缩进字符串
    bool generate_xml_traits = true;       // 生成XmlTraits
    bool generate_comments = true;          // 生成注释
    bool use_smart_pointers = false;       // 使用智能指针
};

/**
 * @brief 拓扑排序结果，包含排序后的类型和循环依赖信息
 */
struct TopologicalSortResult {
    std::vector<WsdlType> sorted_types;           // 排序后的类型列表
    std::set<std::string> circular_types;         // 涉及循环依赖的类型名称
};

/**
 * @brief 类型定义代码生成器
 */
class TypeGenerator {
public:
    /**
     * @brief 构造函数
     * @param config 解析器配置
     * @param options 代码生成选项
     */
    TypeGenerator(const ParserConfig& config, const GeneratorOptions& options);
    
    /**
     * @brief 为单个文件生成类型定义
     * @param file_info 文件信息
     * @param all_files 所有文件信息（用于依赖分析）
     * @return 生成的代码
     */
    std::string generate_types_for_file(
        const std::shared_ptr<FileInfo>& file_info,
        const std::vector<std::shared_ptr<FileInfo>>& all_files) const;
    
    
    /**
     * @brief 生成所有类型文件
     * @param files 所有文件信息
     * @param output_dir 输出目录
     * @return 生成的文件数量
     */
    int generate_all_type_files(
        const std::vector<std::shared_ptr<FileInfo>>& files) const;

    /**
     * @brief 生成全局命名空间映射文件（.cpp 实现）
     * @param files 所有文件信息
     * @return 生成的命名空间映射代码
     */
    std::string generate_namespace_mappings(
        const std::vector<std::shared_ptr<FileInfo>>& files) const;

    /**
     * @brief 生成全局命名空间映射头文件（header-only）
     * @param files 所有文件信息
     * @return 生成的命名空间映射头文件代码
     */
    std::string generate_namespace_mappings_header(
        const std::vector<std::shared_ptr<FileInfo>>& files) const;
        
    /**
     * @brief 根据配置分离生成Schema类型文件
     * @param files 所有文件信息
     * @return 生成的文件数量
     */
    int generate_separate_schema_files(
        const std::vector<std::shared_ptr<FileInfo>>& files) const;
        
    /**
     * @brief 为分离的Schema配置生成类型定义
     * @param target_files 目标文件列表
     * @param schema_config Schema配置
     * @param all_files 所有文件信息
     * @return 生成的代码
     */
    std::string generate_separate_schema_types(
        const std::vector<std::shared_ptr<FileInfo>>& target_files,
        const SchemaConfig& schema_config,
        const std::vector<std::shared_ptr<FileInfo>>& all_files) const;
        
    /**
     * @brief 自动分析类型依赖关系
     * @param types 当前文件的类型列表
     * @param all_files 所有文件信息
     * @return 依赖的类型文件名集合
     */
    std::set<std::string> analyze_type_dependencies(
        const std::vector<WsdlType>& types,
        const std::vector<std::shared_ptr<FileInfo>>& all_files) const;
        
    /**
     * @brief 分析单个类型的依赖关系
     * @param type 要分析的类型
     * @param current_types 当前文件中定义的类型集合
     * @param all_files 所有文件信息
     * @param dependencies 输出的依赖集合
     */
    void analyze_single_type_dependencies(
        const WsdlType& type,
        const std::set<std::string>& current_types,
        const std::vector<std::shared_ptr<FileInfo>>& all_files,
        std::set<std::string>& dependencies) const;

    std::string infer_dependency_from_type_prefix(const std::string& clean_type) const;
    
    /**
     * @brief 查找指定类型的依赖头文件
     * @param clean_type 清理后的类型名
     * @param all_files 所有文件信息
     * @param dependencies 输出的依赖集合
     */
    void find_type_dependency(
        const std::string& clean_type,
        const std::vector<std::shared_ptr<FileInfo>>& all_files,
        std::set<std::string>& dependencies) const;
        
    
    /**
     * @brief 为文件生成对应的头文件名
     * @param file_info 文件信息
     * @return 头文件名
     */
    std::string generate_header_name(const std::shared_ptr<FileInfo>& file_info) const;
    
    /**
     * @brief 根据命名空间生成头文件名
     * @param target_namespace 目标命名空间
     * @param source_file_path 源文件路径（用作后备）
     * @return 头文件名
     */
    std::string generate_header_name_for_namespace(const std::string& target_namespace, 
                                                   const std::string& source_file_path = "") const;
    
    /**
     * @brief 验证类型用法与适配器匹配
     * @param files 所有文件信息
     */
    void validate_type_adapters(const std::vector<std::shared_ptr<FileInfo>>& files) const;

private:
    /**
     * @brief 生成文件头部
     * @param file_info 文件信息
     * @param dependencies 依赖的头文件
     * @return 头部代码
     */
    std::string generate_file_header(
        const std::shared_ptr<FileInfo>& file_info,
        const std::set<std::string>& dependencies) const;
    
    
    /**
     * @brief 收集文件依赖
     * @param file_info 文件信息
     * @param all_files 所有文件信息
     * @return 依赖的头文件名集合
     */
    std::set<std::string> collect_dependencies(
        const std::shared_ptr<FileInfo>& file_info,
        const std::vector<std::shared_ptr<FileInfo>>& all_files) const;
    
    /**
     * @brief 对类型进行拓扑排序并检测循环依赖
     * @param types 类型列表
     * @return 拓扑排序结果，包含排序后的类型和循环依赖信息
     */
    TopologicalSortResult topological_sort_types(const std::vector<WsdlType>& types) const;
    
    /**
     * @brief 生成结构体定义
     * @param type 类型定义
     * @param current_file 当前文件信息
     * @param all_files 所有文件信息
     * @return 结构体代码
     */
    std::string generate_struct(
        const WsdlType& type,
        const std::shared_ptr<FileInfo>& current_file,
        const std::vector<std::shared_ptr<FileInfo>>& all_files) const;
    
    /**
     * @brief 生成枚举定义
     * @param type 类型定义
     * @return 枚举代码
     */
    std::string generate_enum(const WsdlType& type) const;
    
    /**
     * @brief 生成列表类型定义
     * @param type 类型定义
     * @return 列表类型代码
     */
    std::string generate_list_type(const WsdlType& type) const;
    
    /**
     * @brief 生成简单类型重命名
     * @param type 类型定义
     * @param current_file 当前文件信息
     * @return 类型重命名代码
     */
    std::string generate_simple_type_rename(const WsdlType& type,
                                            const std::shared_ptr<FileInfo>& current_file) const;
    
    /**
     * @brief 生成XmlTraits特化
     * @param type 类型定义
     * @return XmlTraits代码
     */
    std::string generate_xml_traits(const WsdlType& type) const;
    
    /**
     * @brief 生成枚举的XmlTraits
     * @param type 类型定义
     * @return XmlTraits代码
     */
    std::string generate_enum_xml_traits(const WsdlType& type) const;
    
    /**
     * @brief 生成列表类型的XmlTraits
     * @param type 类型定义
     * @return XmlTraits代码
     */
    std::string generate_list_xml_traits(const WsdlType& type) const;
    
    /**
     * @brief 获取C++类型名
     * @param type_name XSD类型名
     * @param current_file 当前文件
     * @param all_files 所有文件
     * @return C++类型名
     */
    std::string get_cpp_type_name(
        const std::string& type_name,
        const std::shared_ptr<FileInfo>& current_file,
        const std::vector<std::shared_ptr<FileInfo>>& all_files) const;
    
    /**
     * @brief 获取带前缀的类型名
     * @param type 类型定义
     * @return 带前缀的类型名
     */
    std::string get_prefixed_type_name(const WsdlType& type) const;
    
    /**
     * @brief 清理枚举值（移除非法字符）
     * @param value 枚举值
     * @return 清理后的枚举值
     */
    std::string sanitize_enum_value(const std::string& value) const;
    
    /**
     * @brief 转换字段名为C++风格
     * @param name 字段名
     * @return C++风格字段名
     */
    std::string to_cpp_field_name(const std::string& name) const;
    
    /**
     * @brief 生成文档注释
     * @param text 文档文本
     * @param indent_level 缩进级别
     * @return 注释代码
     */
    std::string generate_doc_comment(const std::string& text, int indent_level = 0) const;
    
    
    /**
     * @brief 标准化文件名，确保有效的C++标识符
     * @param filename 原始文件名
     * @return 标准化的文件名
     */
    std::string normalize_filename(const std::string& filename) const;
    
    /**
     * @brief 检测并解决循环依赖问题
     * @param file_groups 文件分组
     * @param all_files 所有文件信息
     */
    void resolve_circular_dependencies(
        std::map<std::string, std::vector<std::shared_ptr<FileInfo>>>& file_groups,
        const std::vector<std::shared_ptr<FileInfo>>& all_files) const;
    
    /**
     * @brief 为文件生成唯一的文件名（避免循环依赖）
     * @param file_info 文件信息
     * @return 唯一的文件名
     */
    std::string generate_unique_filename(const std::shared_ptr<FileInfo>& file_info) const;
    
private:
    ParserConfig config_;                   // 解析器配置
    GeneratorOptions options_;              // 代码生成选项
};

} // namespace wsdl_parser2