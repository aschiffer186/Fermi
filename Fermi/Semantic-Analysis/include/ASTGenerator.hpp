/** @file ASTGenerator.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <memory>

#include "Syntax-Tree/StatementNodes.hpp"

namespace Fermi::SyntaxAnalysis
{
    class AssignmentStatementNode;
    class BinaryExpressionNode;
    class ExpressionStatementNode;
    class FermiStatementNode;
    class LiteralExpressionNode;
    class VariableDeclarationNode;
}

namespace Fermi::SemanticAnalysis
{
    class ExpressionASTNode;
    class FermiASTNode;
    class StatementASTNode;
    
    std::unique_ptr<ExpressionASTNode> transform(const SyntaxAnalysis::LiteralExpressionNode& node);
    std::unique_ptr<ExpressionASTNode> transform(const SyntaxAnalysis::BinaryExpressionNode& node);
    
    std::unique_ptr<StatementASTNode> transform(const SyntaxAnalysis::AssignmentStatementNode& node);
    std::unique_ptr<StatementASTNode> transform(const SyntaxAnalysis::ExpressionStatementNode& node);
    std::unique_ptr<StatementASTNode> transform(const SyntaxAnalysis::VariableDeclarationStatementNode& node);

    std::unique_ptr<FermiASTNode> transform(const SyntaxAnalysis::FermiStatementNode& node);
}