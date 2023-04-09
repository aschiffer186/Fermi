#ifndef STATEMENT_NODES_HPP
#define STATEMENT_NODES_HPP

#include <concepts>
#include <string>
#include <variant>
#include <vector>

namespace Fermi::SyntaxAnalysis::SemanticAnalysis
{
    template<typename ExpressionNode>
    struct ExpressionStatementNode 
    {
        ExpressionNode expression;
    };

    template<typename T>
    ExpressionStatementNode(T) -> ExpressionStatementNode<T>;

    template<typename E1, typename E2>
    bool operator==(ExpressionStatementNode<E1>& lhs, ExpressionStatementNode<E2>& rhs) noexcept 
    {
        if (!std::same_as<E1, E2>)
            return false;
        return lhs.expression == rhs.expression;
    }
    
    enum class Type 
    {
        int8_t, 
        int16_t, 
        int32_t, 
        int64_t, 
        float32_t, 
        float64_t, 
        deduced
    };

    struct VariableDeclarationNode 
    {
        std::string identifier;
        Type type;

        friend bool operator==(const VariableDeclarationNode& lhs, const VariableDeclarationNode& rhs) noexcept = default;
    };

    template<typename ExpressionNode> 
    struct VariableInitializationNode 
    {
        std::string identifier;
        Type type;
        ExpressionNode initializer;
    };

    template<typename E>
    VariableInitializationNode(std::string, Type, E) -> VariableInitializationNode<E>;

    template<typename E>
    VariableInitializationNode(std::string_view, Type, E) -> VariableInitializationNode<E>;

    template<typename E1, typename E2>
    bool operator==(const VariableInitializationNode<E1>& lhs, const VariableInitializationNode<E2>& rhs) noexcept 
    {
        if (!std::same_as<E1, E2>)
            return false; 
        return lhs.identifier == rhs.identifier && lhs.type == rhs.type && lhs.initializer && rhs.initializer;
    } 


    template<typename... NodeTypes> 
    struct FermiNode 
    {
        std::vector<std::variant<NodeTypes...>> children;  
    };
};

#endif