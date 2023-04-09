#ifndef STATEMENT_NODES_HPP
#define STATEMENT_NODES_HPP

#include <optional>
#include <vector>

#include "Static-Syntax-Tree/ExpressionNodes.hpp"

namespace Fermi::SyntaxAnalysis
{
    template<typename Expression>
    struct AssignmentStatementNode 
    {
        std::string lhs;
        Expression rhs;
    };

    template<typename Expression>
    AssignmentStatementNode(std::string_view, Expression) -> AssignmentStatementNode<Expression>;

    template<typename Expression>
    bool operator==(const Expression& lhs, const Expression& rhs) noexcept 
    {
        return lhs.lhs == rhs.lhs && lhs.rhs == rhs.rhs;
    }

    template<typename Expression>
    struct ExpressionStatementNode 
    {
        Expression child;
    };

    template<typename Expression>
    bool operator==(const ExpressionStatementNode<Expression>& lhs, const ExpressionStatementNode<Expression>& rhs) noexcept 
    {
        return lhs.child == rhs.child;
    }

    template<typename Expression>
    ExpressionStatementNode(Expression) -> ExpressionStatementNode<Expression>;

    template<typename... NodeTypes>
    struct PrintStatementNode
    {
        std::vector<ExpressionNode<NodeTypes...>> expressions;
    };

    template<typename... NodeTypes>
    PrintStatementNode(std::vector<ExpressionNode<NodeTypes...>>) -> PrintStatementNode<NodeTypes...>;

    template<typename Expression>
    struct VariableInitializationStatementNode 
    {
        std::string identifier;
        std::string type;
        Expression initializer;
    };

    template<typename Expression>
    VariableInitializationStatementNode(std::string_view, std::string_view, std::optional<Expression>) -> VariableInitializationStatementNode<Expression>;

    struct VariableDeclarationStatementNode
    {
        std::string identifier;
        std::string type;
    };

    template<typename... NodeTypes>
    using StatementNode = std::variant<NodeTypes...>;

    template<typename... NodeTypes>
    struct FermiNode
    {
        std::vector<StatementNode<NodeTypes...>> children;
    };
};

#endif