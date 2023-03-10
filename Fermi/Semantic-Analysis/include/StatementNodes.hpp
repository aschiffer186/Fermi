#ifndef ASSIGN_NODE_HPP
#define ASSIGN_NODE_HPP

#include "ASTNode.hpp"
#include "ExpressionNodes.hpp"

namespace Fermi::SemanticAnalysis
{
    class AssignNode : public ASTNode
    {
    private:
        IdentifierNode lhs_;
        std::unique_ptr<ExpressionNode> rhs_;
    };

    class FermiNode : public ASTNode 
    {
    public:
        ASTNodeType getType() const override;

        std::vector<const ASTNode*> getChildren() const override;

        void accept(Visitor* visitor) const override;

        void addChild(std::unique_ptr<ASTNode> child);
    private:
        std::vector<std::unique_ptr<ASTNode>> children_;
    };
}

#endif