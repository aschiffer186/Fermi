#ifndef EXPRESSION_NODES_HPP
#define EXPRESSION_NODES_HPP

#include <string>
#include <variant>

namespace Fermi::SyntaxAnalysis::SyntaxTree 
{
    enum class LiteralNodeType 
    {
        FloatLiteral,
        IntegerLiteral
    };

    struct LiteralExpressionNode 
    {
        LiteralNodeType type;
        std::string value;  

        friend bool operator==(const LiteralExpressionNode& lhs, const LiteralExpressionNode& rhs) noexcept = default;
    };

    enum class BinaryOperatorType 
    {
        Plus,
        Minus, 
        Start,
        Slash,
        DoubleSlash,
        Caret,
        Modulo
    };

    template<typename ChildNode1, typename ChildNode2> 
    struct BinaryExpressionNode
    {
        ChildNode1 lhs;
        BinaryOperatorType op;
        ChildNode2 rhs;
    };

    template<typename T1, typename T2>
    BinaryExpressionNode(T1, BinaryOperatorType, T2) -> BinaryExpressionNode<T1, T2>;

    template<typename C1, typename C2, typename C3, typename C4>
    bool operator==(const BinaryExpressionNode<C1, C2>& lhs, const BinaryExpressionNode<C3, C4>& rhs) noexcept
    {
        if (!std::same_as<C1, C3> || !std::same_as<C2, C4>)
            return false;
        return lhs.lhs == rhs.lhs && lhs.op == rhs.op && lhs.rhs == rhs.lhs;
    }

    template<typename... ExpressionNodes>
    using ExpressionNodeType = std::variant<ExpressionNodes...>;
};

#endif