#ifndef EXPRESSION_NODES_HH
#define EXPRESSION_NODES_HH

#include <cstdint>

#include "Scanner.hh"

namespace Fermi 
{
    struct IdentifierNode 
    {
        std::string identifier; 

        friend auto operator==(const IdentifierNode&, const IdentifierNode&) -> bool = default;
    };

    struct LiteralExpressionNode 
    {
        TokenType literalType;
        std::string literal;

        friend auto operator==(const LiteralExpressionNode&, const LiteralExpressionNode&) -> bool = default;
    };

    struct BinaryExpressionNode 
    {
        std::size_t left; 
        TokenType op; 
        std::size_t right;

        friend auto operator==(const BinaryExpressionNode&, const BinaryExpressionNode&) -> bool = default;
    };

    struct UnaryExpressionNode 
    {
        TokenType op; 
        std::size_t child;

        friend auto operator==(const UnaryExpressionNode&, const UnaryExpressionNode&) -> bool = default;
    };
}

#endif