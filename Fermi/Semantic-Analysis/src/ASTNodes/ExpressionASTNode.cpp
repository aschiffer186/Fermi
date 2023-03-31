/**
 * @file ExpressionASTNode.cpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ASTNodes/ExpressionASTNode.hpp"
#include "Type.hpp"

namespace Fermi::SemanticAnalysis
{
    TypeConversionASTNode::TypeConversionASTNode(std::unique_ptr<ExpressionASTNode> child, const FermiType& outputType)
    : child_{std::move(child)}, outputType_{outputType}
    {

    }

    ASTNodeType TypeConversionASTNode::getNodeType() const 
    {
        return ASTNodeType::TypeConversion;
    }

    std::vector<const ASTNode*> TypeConversionASTNode::getChildren() const 
    {
        return {child_.get()};
    }

    FermiType TypeConversionASTNode::getType() const 
    {
        return outputType_;
    }

    BinaryExpressionASTNode::BinaryExpressionASTNode(std::unique_ptr<ExpressionASTNode> lhs, BinaryOperatorType op, std::unique_ptr<ExpressionASTNode> rhs)
    : lhs_{std::move(lhs)}, op_{op}, rhs_{std::move(rhs)}
    {

    }

    ASTNodeType BinaryExpressionASTNode::getNodeType() const 
    {
        return ASTNodeType::BinaryExpression;
    }

    std::vector<const ASTNode*> BinaryExpressionASTNode::getChildren() const 
    {
        return {lhs_.get(), rhs_.get()};
    }

    FermiType BinaryExpressionASTNode::getType() const 
    {
        return commonType(lhs_->getType(), rhs_->getType());
    }

    BinaryOperatorType BinaryExpressionASTNode::getOperator() const 
    {
        return op_;
    }

    LiteralExpressionASTNode::LiteralExpressionASTNode(std::string_view value, const FermiType& type)
    : value_{value}, type_{type}
    {

    }

    ASTNodeType LiteralExpressionASTNode::getNodeType() const 
    {
        return ASTNodeType::LiteralExpression;
    }

    std::vector<const ASTNode*> LiteralExpressionASTNode::getChildren() const 
    {
        return {};
    }

    FermiType LiteralExpressionASTNode::getType() const 
    {
        return type_;
    }

    std::string_view LiteralExpressionASTNode::getValue() const 
    {
        return value_;
    }
}
