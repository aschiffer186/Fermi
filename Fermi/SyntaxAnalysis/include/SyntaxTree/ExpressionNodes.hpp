/**
 * @file ExpressionNodes.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief Declaration of expression syntax nodes
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once 

#include <memory>

#include "SyntaxNode.hpp"

namespace Fermi::SyntaxAnalysis
{
    class ExpressionNode : public SyntaxNode 
    {
    public:
        virtual ~ExpressionNode() = default;
    };

    enum class BinaryOperatorType 
    {
        Plus,
        Minus, 
        Star, 
        Slash, 
        DoubleSlash, 
        Caret,
        Percent
    };

    class BinaryExpressionNode : public ExpressionNode 
    {
    public:
        BinaryExpressionNode(std::unique_ptr<ExpressionNode> lhs, 
                             BinaryOperatorType op, 
                             std::unique_ptr<ExpressionNode> rhs, 
                             const FermiSourceLocation& location);

        SyntaxNodeType getSyntaxNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override;

        const FermiSourceLocation& getSourceLocation() const override;

        BinaryOperatorType getOperator() const;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    public:
        void print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        std::unique_ptr<ExpressionNode> _lhs;
        BinaryOperatorType _op;
        std::unique_ptr<ExpressionNode> _rhs;
        FermiSourceLocation _location;
    };

    class IdentifierExpressionNode : public ExpressionNode 
    {
    public:
        IdentifierExpressionNode(std::string_view identifier, const FermiSourceLocation& location);

        SyntaxNodeType getSyntaxNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override;

        const FermiSourceLocation& getSourceLocation() const override;

        const std::string& getIdentifier() const;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    public:
        void print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        std::string _identifier;
        FermiSourceLocation _location;
    };

    enum class LiteralExpressionType 
    {
        FloatLiteral,
        IntegerLiteral
    };

    class LiteralExpressionNode : public ExpressionNode 
    {
    public:
        LiteralExpressionNode(LiteralExpressionType type, std::string_view value, const FermiSourceLocation& location);

        SyntaxNodeType getSyntaxNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override;

        const FermiSourceLocation& getSourceLocation() const override;

        LiteralExpressionType getLiteralExpressionType() const;

        const std::string& getValue() const;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    public:
        void print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        LiteralExpressionType _type;
        std::string _value;
        FermiSourceLocation _location;
    };
}