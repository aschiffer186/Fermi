#ifndef EXPRESSION_NODES_HPP
#define EXPRESSION_NODES_HPP

#include <string>
#include <string_view>
#include <variant>

namespace Fermi::SyntaxAnalysis
{
    enum class BinaryOperator 
    {
        Addition, 
        Subtraction, 
        Multiplication,
        Division,
        IntegerDivision, 
        Exponentiation, 
        Modulo
    };
    
    template<typename Child1, typename Child2>
    struct BinaryExpressionNode
    {
        Child1 lhs_;
        BinaryOperator op_;
        Child2 rhs_;
    };

    template<typename T1, typename T2>
    bool operator==(const BinaryExpressionNode<T1, T2>& lhs, const BinaryExpressionNode<T1, T2>& rhs)
    {
        return lhs.lhs_ == rhs.lhs_ && lhs.op_ == rhs.op_ && lhs.rhs_ == rhs.rhs_;
    }

    enum class LiteralNodeType 
    {
        Float, 
        Identifier, 
        Integer
    };

    struct LiteralExpressionNode
    {    
        LiteralNodeType type;
        std::string value;

        friend bool operator==(const LiteralExpressionNode& lhs, const LiteralExpressionNode& rhs) noexcept = default;
    };

    template<typename... NodeTypes>
    using ExpressionNode = std::variant<NodeTypes...>;
}

#endif