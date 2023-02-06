#include "ExpressionNode.hpp"

namespace Fermi::SyntaxAnalysis
{
    BinaryExpressionNode::BinaryExpressionNode(std::unique_ptr<ExpressionNode> lhs, 
                                               BinaryExpressionTypes operatorIn, 
                                               std::unique_ptr<ExpressionNode> rhs)
        : lhs_{std::move(lhs)}, operator_{operatorIn}, rhs_{std::move(rhs)}
        {

        }

    SyntaxNodeType BinaryExpressionNode::getNodeType() const 
    {
        return SyntaxNodeType::BinaryExpression;
    }

    std::vector<const SyntaxNode*> BinaryExpressionNode::getChildren() const 
    {
        return {lhs_.get(), rhs_.get()};
    }

    BinaryExpressionTypes BinaryExpressionNode::getOperator() const 
    {
        return operator_;
    }

    LiteralNode::LiteralNode(std::string_view value, LiteralType type)
    : type_{type}, value_{value}
    {

    }

    SyntaxNodeType LiteralNode::getNodeType() const 
    {
        return SyntaxNodeType::Literal;
    }

    std::vector<const SyntaxNode*> LiteralNode::getChildren() const 
    {
        return {};
    }

    const std::string& LiteralNode::getValue() const 
    {
        return value_;
    }

    LiteralType LiteralNode::getType() const 
    {
        return type_;
    }
}