#ifndef SYNATX_NODES_HH
#define SYNATX_NODES_HH

#include <variant>

#include "ExpressionNodes.hh"
#include "StatementNodes.hh"

namespace Fermi 
{
    using SyntaxNode = std::variant<ExpressionStatementNode,
                                    IdentifierNode, 
                                    LiteralExpressionNode,
                                    BinaryExpressionNode, 
                                    UnaryExpressionNode>;
}

#endif