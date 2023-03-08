#ifndef ASSIGN_NODE_HPP
#define ASSIGN_NODE_HPP

#include "DAGNode.hpp"
#include "ExpressionNodes.hpp"

namespace Fermi::SemanticAnalysis
{
    class AssignNode : DAGNode
    {
    private:
        IdentifierNode lhs_;
        std::unique_ptr<ExpressionNode> rhs_;
    };
}

#endif