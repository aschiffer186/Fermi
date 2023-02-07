#include <algorithm>

#include "ExpressionNode.hpp"
#include "StatementNode.hpp"

namespace Fermi::SyntaxAnalysis
{
    VariableDeclarationNode::VariableDeclarationNode(Type type, std::string_view identifier, std::unique_ptr<ExpressionNode> initializer)
    : type_{type}, identifier_{identifier}, initializer_{std::move(initializer)}
    {

    }

    SyntaxNodeType VariableDeclarationNode::getNodeType() const 
    {
        return SyntaxNodeType::VariableDeclarationNode;
    }

    std::vector<const SyntaxNode*> VariableDeclarationNode::getChildren() const 
    {
        return {initializer_.get()};
    }

    Type VariableDeclarationNode::getType() const 
    {
        return type_;
    }

    const std::string& VariableDeclarationNode::getIdentifier() const 
    {
        return identifier_;
    }

    PrintNode::PrintNode(std::vector<std::unique_ptr<ExpressionNode>>&& vec)
    : expressions_{std::move(vec)}
    {
        
    }
    
    SyntaxNodeType PrintNode::getNodeType() const 
    {
        return SyntaxNodeType::PrintNode;
    }

    std::vector<const SyntaxNode*> PrintNode::getChildren() const 
    {
        std::vector<const SyntaxNode*> children;
        std::transform(expressions_.begin(), expressions_.end(), std::back_inserter(children), [](const auto& exp) {return exp.get();});
        return children;
    }

    void PrintNode::addPrintingExpression(std::unique_ptr<ExpressionNode> expression)
    {
        expressions_.push_back(std::move(expression));
    }

    AssignmentStatementNode::AssignmentStatementNode(std::string_view lhs, std::unique_ptr<ExpressionNode> rhs)
    : lhs_{lhs}, rhs_{std::move(rhs)}
    {

    }


    SyntaxNodeType AssignmentStatementNode::getNodeType() const 
    {
        return SyntaxNodeType::AssignmentStatementNode;
    }

    std::vector<const SyntaxNode*> AssignmentStatementNode::getChildren() const 
    {
        return {rhs_.get()};
    }

    const std::string& AssignmentStatementNode::getAssignee() const 
    {
        return lhs_;
    }
}