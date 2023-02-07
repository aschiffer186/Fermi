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

    bool VariableDeclarationNode::equals(const SyntaxNode& other) const noexcept
    {
        const auto& node = dynamic_cast<const VariableDeclarationNode&>(other);
        if(type_ != node.type_)
            return false;
        if (identifier_ != node.identifier_)
            return false;
        if (!initializer_)
            return !node.initializer_;
        return *initializer_ == *node.initializer_;
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

    bool PrintNode::equals(const SyntaxNode& other) const noexcept
    {
        const auto& node = dynamic_cast<const PrintNode&>(other);
        return std::equal(expressions_.begin(), expressions_.end(), node.expressions_.begin(), [](const auto& lhs, const auto& rhs){
            return *lhs == *rhs;
        });
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

    bool AssignmentStatementNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = dynamic_cast<const AssignmentStatementNode&>(other);
        return lhs_ == node.lhs_ && *rhs_ == *node.rhs_;
    }
}