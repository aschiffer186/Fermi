#ifndef AST_HPP
#define AST_HPP

#include <memory>

#include "SyntaxNode.hpp"

namespace Fermi::SemanticAnalysis
{
    class ASTNode;

    class AST
    {
    public:
        explicit AST(std::shared_ptr<SyntaxAnalysis::SyntaxNode> syntaxTree);
    private:
        ASTNode* root_;
    };
} // namespace Fermi::SemanticAnalysis


#endif