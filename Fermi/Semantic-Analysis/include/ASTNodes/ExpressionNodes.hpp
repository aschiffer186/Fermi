#ifndef EXPRESSION_NODES_HPP
#define EXPRESSION_NODES_HPP

#include <memory>

#include "ASTNode.hpp"
#include "Type.hpp"

namespace Fermi::SemanticAnalysis
{
    class ExpressionASTNode : public ASTNode
    {
    public:
        virtual Type getOutputEntityType() const = 0;
        virtual ~ExpressionASTNode() = default;
    };

    class TypeConversionNode : public ExpressionASTNode
    {
    public:
        TypeConversionNode(std::unique_ptr<ExpressionASTNode> child, const Type& outputType);

        ASTNodeType getType() const override;

        std::vector<const ASTNode*> getChildren() const override;

        void accept(Visitor* visitor) const override;

        Type getOutputEntityType() const override;
    private:
        Type outputType_;
        std::unique_ptr<ExpressionASTNode> child_;
    };

    enum class BinaryExpressionOperator
    {
        Addition,
        Subtraction,
        Multiplication,
        Division,
        IntegerDivision, 
        Exponentiation,
        Modulo
    }; 

    class BinaryExpressionASTNode : public ExpressionASTNode
    {
    public: 
        BinaryExpressionASTNode(std::unique_ptr<ExpressionASTNode> lhs, BinaryExpressionOperator op, std::unique_ptr<ExpressionASTNode> rhs);

        ASTNodeType getType() const override;

        std::vector<const ASTNode*> getChildren() const override;

        void accept(Visitor* visitor) const override;

        Type getOutputEntityType() const override;

    private:
        BinaryExpressionOperator op_;
        Type outputType_;
        std::unique_ptr<ExpressionASTNode> lhs_;
        std::unique_ptr<ExpressionASTNode> rhs_;
    };

    class LiteralASTNode : public ExpressionASTNode
    {
    public:
        LiteralASTNode(Type type, std::string_view value);

        ASTNodeType getType() const override;

        std::vector<const ASTNode*> getChildren() const override;

        void accept(Visitor* visitor) const override; 

        Type getOutputEntityType() const override;

        const std::string& getValue() const;
    private:
        Type type_;
        std::string value_;
    };

    class IdentifierASTNode : public ExpressionASTNode 
    {
    public:
        IdentifierASTNode(std::string_view identifier, const Type& type);
    
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