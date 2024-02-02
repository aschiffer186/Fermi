#ifndef SYNTAX_NODES_HPP
#define SYNTAX_NODES_HPP

#include <variant>

#include "ExpressionSyntaxNodes.hpp"

namespace Fermi::SyntaxAnalysis
{
    using SyntaxNode = std::variant<BinaryExpressionNode, 
                                    UnaryExpressionNode, 
                                    LiteralExpressionNode>;
}

#endif