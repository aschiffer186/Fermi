/** @file ASTGenerator.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Syntax-Tree/StatementNode.hpp"
#include <memory>

namespace Fermi::SyntaxAnalysis
{
    class BinaryExpressionNode;
    class ExpressionStatementNode;
    class FermiNode;
    class LiteralNode;
}

namespace Fermi::SemanticAnalysis
{
    class ExpressionASTNode;
    class FermiASTNode;
    class StatementASTNode;
    
    std::unique_ptr<ExpressionASTNode> transform(const SyntaxAnalysis::LiteralNode& node);
    std::unique_ptr<ExpressionASTNode> transform(const SyntaxAnalysis::BinaryExpressionNode& node);
    
    std::unique_ptr<StatementASTNode> transform(const SyntaxAnalysis::ExpressionStatementNode& node);

    std::unique_ptr<FermiASTNode> transform(const SyntaxAnalysis::FermiNode& node);
}