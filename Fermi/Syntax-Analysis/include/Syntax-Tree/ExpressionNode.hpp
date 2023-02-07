#ifndef EXPRESSION_NODE_HPP
#define EXPRESSION_NODE_HPP

#include <memory>
#include <string>
#include <string_view>

#include "SyntaxNode.hpp"

namespace Fermi::SyntaxAnalysis
{
    class ExpressionNode : public SyntaxNode 
    {
    public:
        virtual ~ExpressionNode() = default;
    };

    enum class BinaryExpressionTypes
    {
        Addition,
        Subtraction,
        Multiplication,
        Division,
        IntegerDivision,
        Exponentiation,
        Modulo
    };

    class BinaryExpressionNode : public ExpressionNode
    {
    public:
        BinaryExpressionNode(std::unique_ptr<ExpressionNode> lhs, BinaryExpressionTypes operandIn, std::unique_ptr<ExpressionNode> rhs);

        SyntaxNodeType getNodeType() const override; 

        std::vector<const SyntaxNode*> getChildren() const override; 

        BinaryExpressionTypes getOperator() const;

    private:
        bool equals(const SyntaxNode& other) const noexcept override;
        std::ostream& print(std::ostream& os) const override;
    private:
        std::unique_ptr<ExpressionNode> lhs_;
        BinaryExpressionTypes operator_;
        std::unique_ptr<ExpressionNode> rhs_;
    };

    enum class LiteralType 
    {
        Integer, 
        Float, 
        Identifier
    };

    class LiteralNode : public ExpressionNode
    {
    public:
        explicit LiteralNode(std::string_view value, LiteralType type);

        SyntaxNodeType getNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override;

        const std::string& getValue() const;

        LiteralType getType() const;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
        std::ostream& print(std::ostream& os) const override;
    private:
        LiteralType type_;
        std::string value_;
    };

    
}

#endif