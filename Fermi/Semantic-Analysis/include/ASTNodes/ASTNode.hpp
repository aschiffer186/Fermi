#ifndef DAG_NODE_HPP
#define DAG_NODE_HPP

#include <memory>
#include <vector>

#include "StatementNode.hpp"

namespace Fermi::SemanticAnalysis
{
    class Visitor;

    enum class ASTNodeType 
    {
        AssignmentNode,
        BinaryExpresionNode,
        FermiNode,
        IdentifierNode,
        LiteralNode,
        TypeConversionNode
    };

    class ASTNode
    {
    public:
        virtual ASTNodeType getType() const = 0;

        virtual std::vector<const ASTNode*> getChildren() const = 0;

        virtual void accept(Visitor* visitor) const = 0;

        virtual ~ASTNode() = default;
    };

    std::unique_ptr<ASTNode> makeAST(std::shared_ptr<SyntaxAnalysis::FermiNode> syntaxTree);
}

#endif