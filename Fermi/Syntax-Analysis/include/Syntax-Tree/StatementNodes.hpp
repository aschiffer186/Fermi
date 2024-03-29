/**
 * @file SyntaxNode.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef STATEMENT_NODE_HPP
#define STATEMENT_NODE_HPP

#include <memory>
#include <string>

#include "SyntaxNode.hpp"

namespace Fermi::SyntaxAnalysis
{
    class StatementNode : public SyntaxNode 
    {
    public:
        virtual ~StatementNode() = default;
    };

    class FermiStatementNode : public SyntaxNode 
    {
    public:
        explicit FermiStatementNode(const std::vector<std::shared_ptr<StatementNode>>& statements);

        SyntaxNodeType getNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override; 

        std::ostream& print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    private:
        std::vector<std::shared_ptr<StatementNode>> statements_;
    };

    enum class Type 
    {
        int8_t, 
        int16_t, 
        int32_t, 
        int64_t, 
        float32_t, 
        float64_t, 
        deduced
    };

    class ExpressionNode;

    class ExpressionStatementNode : public StatementNode 
    {
    public: 
        explicit ExpressionStatementNode(std::shared_ptr<ExpressionNode> expression);
    
        SyntaxNodeType getNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override; 

        std::ostream& print(std::ostream& os, std::string ident, bool isLast) const override;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    private:
        std::shared_ptr<ExpressionNode> expression_;
    };

    class VariableDeclarationStatementNode : public StatementNode 
    {
    public:
        VariableDeclarationStatementNode(Type type, std::string_view identifier, std::shared_ptr<ExpressionNode> initializer = nullptr);

        SyntaxNodeType getNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override; 

        Type getType() const;

        const std::string& getIdentifier() const;

        std::ostream& print(std::ostream& os, std::string ident, bool isLast) const override;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    private:
        Type type_;
        std::string identifier_;
        std::shared_ptr<ExpressionNode> initializer_;
    };

    class PrintStatementNode : public StatementNode 
    {
    public:
        PrintStatementNode(const std::vector<std::shared_ptr<ExpressionNode>>& vec);

        SyntaxNodeType getNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override; 

        void addPrintingExpression(std::shared_ptr<ExpressionNode> expression);

        std::ostream& print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    private:
        std::vector<std::shared_ptr<ExpressionNode>> expressions_;
    };

    class AssignmentStatementNode : public StatementNode 
    {
    public:
        AssignmentStatementNode(std::string_view lhs, std::shared_ptr<ExpressionNode> rhs);

        SyntaxNodeType getNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override; 

        const std::string& getAssignee() const; 
        
        std::ostream& print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    private:
        std::string lhs_;
        std::shared_ptr<ExpressionNode> rhs_;
    };
} // namespace JOLT


#endif