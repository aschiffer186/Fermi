#ifndef SYNTAX_NODE_HPP
#define SYNTAX_NODE_HPP

#include "ExpressionNodes.hpp"
#include "StatementNodes.hpp"
#include <variant>

namespace Fermi::SyntaxAnalysis
{
    using SyntaxNode = std::variant<
        BinaryExpressionNode, LiteralExpressionNode, IdentifierExpressionNode,
        ParenthesizedExpressionNode, DeclarationStatementNode,
        ExpressionStatementNode>;
}

#endif