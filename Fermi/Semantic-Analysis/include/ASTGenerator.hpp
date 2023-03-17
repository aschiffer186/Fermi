#ifndef AST_GENERATOR_HPP
#define AST_GENERATOR_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "Type.hpp"
#include "Visitor.hpp"

namespace Fermi::SemanticAnalysis
{
    class ASTNode;
    class FermiASTNode;

    class ASTGenerator : public SyntaxAnalysis::Visitor
    {
    public:
        ASTGenerator(const SyntaxAnalysis::FermiNode& syntaxTree, std::unordered_map<std::string, Type>& symbolTable);

        void visit(const SyntaxAnalysis::AssignmentStatementNode*) override;
        void visit(const SyntaxAnalysis::BinaryExpressionNode*) override;
        void visit(const SyntaxAnalysis::ExpressionStatementNode*) override;
        void visit(const SyntaxAnalysis::FermiNode*) override;
        void visit(const SyntaxAnalysis::LiteralNode*) override;
        void visit(const SyntaxAnalysis::PrintNode*) override;
        void visit(const SyntaxAnalysis::VariableDeclarationNode*) override;

        /**
         * @brief Obtain syntax tree produced 
         * 
         * @return FermiASTNode* 
         */
        std::unique_ptr<FermiASTNode> getTree();
    private:
        std::unique_ptr<FermiASTNode> tree_;
        std::unordered_map<std::string, Type>& symbolTable_;
    };
} // namespace Fermi::SemanticAnalysis


#endif