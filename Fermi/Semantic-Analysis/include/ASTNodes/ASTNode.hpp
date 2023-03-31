#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <vector>

namespace Fermi::SemanticAnalysis
{
    enum class ASTNodeType
    {

    };

    class ASTNode 
    {
    public:
        virtual ~ASTNode() = default;

        virtual std::vector<const ASTNode*> getChildren() const = 0;

        virtual ASTNodeType getNodeType() const = 0;
    };
}

#endif