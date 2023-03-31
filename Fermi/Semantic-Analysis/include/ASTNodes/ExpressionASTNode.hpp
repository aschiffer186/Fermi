/**
 * @file ExpressionASTNode.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef EXPRESSION_AST_NODE_HPP
#define EXPRESSION_AST_NODE_HPP


#include <memory>
#include <string>
#include <string_view>

#include "ASTNode.hpp"
#include "Type.hpp"

namespace Fermi::SemanticAnalysis
{
    class ExpressionASTNode : public ASTNode 
    {
    public:
        virtual ~ExpressionASTNode() = default;

        virtual FermiType getType() const = 0;
    };

    enum class BinaryOperatorType 
    {
        Addition,
        Subtraction,
        Multiplication,
        Division,
        IntegerDivision,
        Exponentiation,
        Modulo
    };

    class TypeConversionASTNode : public ExpressionASTNode 
    {
    public:
        TypeConversionASTNode(std::unique_ptr<ExpressionASTNode> child, const FermiType& outputType);

        ASTNodeType getNodeType() const override; 

        std::vector<const ASTNode*> getChildren() const override; 

        FermiType getType() const override;
    private:
        std::unique_ptr<ExpressionASTNode> child_;
        FermiType outputType_;
    };

    class BinaryExpressionASTNode : public ExpressionASTNode 
    {
    public:
        BinaryExpressionASTNode(std::unique_ptr<ExpressionASTNode> lhs, BinaryOperatorType op, std::unique_ptr<ExpressionASTNode> rhs);

        ASTNodeType getNodeType() const override; 

        std::vector<const ASTNode*> getChildren() const override; 

        FermiType getType() const override;

        BinaryOperatorType getOperator() const;
    private:
        std::unique_ptr<ExpressionASTNode> lhs_;
        BinaryOperatorType op_;
        std::unique_ptr<ExpressionASTNode> rhs_;
    };

    class LiteralExpressionASTNode : public ExpressionASTNode 
    {
    public:
        LiteralExpressionASTNode(std::string_view value, const FermiType& type);

        ASTNodeType getNodeType() const override; 

        std::vector<const ASTNode*> getChildren() const override; 

        FermiType getType() const override;

        std::string_view getValue() const;
    private:
        std::string value_;
        FermiType type_;
    };

    class IdentifierExpressionASTNode : public ExpressionASTNode
    {

    };
}

#endif