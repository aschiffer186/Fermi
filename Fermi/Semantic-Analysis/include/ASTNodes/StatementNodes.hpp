#ifndef ASSIGN_NODE_HPP
#define ASSIGN_NODE_HPP

#include "ASTNode.hpp"
#include "ExpressionNodes.hpp"

namespace Fermi::SemanticAnalysis
{
    class AssignNode : public ASTNode
    {
    private:
        IdentifierASTNode lhs_;
        std::unique_ptr<ExpressionASTNode> rhs_;
    };

    class FermiASTNode : public ASTNode 
    {
    public:
        FermiASTNode();

        ASTNodeType getType() const override;

        std::vector<const ASTNode*> getChildren() const override;

        void accept(Visitor* visitor) const override;

        void addChild(std::unique_ptr<ASTNode> child);
    private:
        std::vector<std::unique_ptr<ASTNode>> children_;
    };
}

#endif