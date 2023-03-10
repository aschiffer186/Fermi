#ifndef EXPRESSION_NODES_HPP
#define EXPRESSION_NODES_HPP

#include <memory>

#include "ASTNode.hpp"
#include "Type.hpp"

namespace Fermi::SemanticAnalysis
{
    class ExpressionNode : public ASTNode
    {
    public:
        virtual Type getOutputEntityType() const = 0;
        virtual ~ExpressionNode() = default;
    };

    class TypeConversionNode : public ExpressionNode
    {
    public:
        TypeConversionNode(std::unique_ptr<ExpressionNode> child, const Type& outputType);

        ASTNodeType getType() const override;

        std::vector<const ASTNode*> getChildren() const override;

        void accept(Visitor* visitor) const override;

        Type getOutputEntityType() const override;
    private:
        Type outputType_;
        std::unique_ptr<ExpressionNode> child_;
    };

    enum class BinaryExpressionOperator
    {
        Addition
    }; 

    class BinaryExpressionNode : public ExpressionNode
    {
    public: 
        BinaryExpressionNode(std::unique_ptr<ExpressionNode> lhs, BinaryExpressionOperator op, std::unique_ptr<ExpressionNode> rhs);

        ASTNodeType getType() const override;

        std::vector<const ASTNode*> getChildren() const override;

        void accept(Visitor* visitor) const override;

        Type getOutputEntityType() const override;

    private:
        BinaryExpressionOperator op_;
        Type outputType_;
        std::unique_ptr<ExpressionNode> lhs_;
        std::unique_ptr<ExpressionNode> rhs_;
    };

    class LiteralNode : public ExpressionNode
    {
    public:
        LiteralNode(Type type, std::string_view value);

        ASTNodeType getType() const override;

        std::vector<const ASTNode*> getChildren() const override;

        void accept(Visitor* visitor) const override; 

        Type getOutputEntityType() const override;

        const std::string& getValue() const;
    private:
        Type type_;
        std::string value_;
    };

    class IdentifierNode : public ExpressionNode 
    {
    public:
        IdentifierNode(std::string_view identifier, const Type& type);
    
        ASTNodeType getType() const override;

        std::vector<const ASTNode*> getChildren() const override;

        void accept(Visitor* visitor) const override;

        Type getOutputEntityType() const override; 

        const std::string& getIdentifier() const;
    private:
        std::string identifier_;
        Type type_;
    };
}

#endif