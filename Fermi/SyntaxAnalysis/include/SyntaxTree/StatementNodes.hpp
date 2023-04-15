/**
 * @file StatementNodes.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief Declaration of statement syntax nodes
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once 

#include <memory> 
#include <optional>

#include "FermiLexer.hpp"
#include "SyntaxNode.hpp"
#include "SyntaxTree/ExpressionNodes.hpp"

namespace Fermi::SyntaxAnalysis
{
    class ExpressionNode;
    class IdentifierExpressionNode;

    class StatementNode : public SyntaxNode 
    {
    public:
        virtual ~StatementNode() = default;
    };

    class AssignmentStatementNode : public StatementNode
    {
    public:
        AssignmentStatementNode(std::unique_ptr<IdentifierExpressionNode> lhs, 
                                std::unique_ptr<ExpressionNode> rhs, 
                                const FermiSourceLocation& location);

        SyntaxNodeType getSyntaxNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override;

        const FermiSourceLocation& getSourceLocation() const override;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    public:
        void print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        std::unique_ptr<IdentifierExpressionNode> _lhs;
        std::unique_ptr<ExpressionNode> _rhs;
        FermiSourceLocation _location;
    };

    class ExpressionStatementNode : public StatementNode 
    {
    public: 
        ExpressionStatementNode(std::unique_ptr<ExpressionNode> child, const FermiSourceLocation& loc);
    };

    class FermiStatementNode : public StatementNode 
    {
    public:
        SyntaxNodeType getSyntaxNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override;

        const FermiSourceLocation& getSourceLocation() const override;

        void addChild(std::unique_ptr<StatementNode> child);
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    public:
        void print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        std::vector<std::unique_ptr<StatementNode>> _children;
        FermiSourceLocation _location;
    };

    class PrintStatementNode : public StatementNode 
    {
    public:
        PrintStatementNode(std::vector<std::unique_ptr<ExpressionNode>> vec, const FermiSourceLocation& loc);

        SyntaxNodeType getSyntaxNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override;

        const FermiSourceLocation& getSourceLocation() const override;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    public:
        void print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        std::vector<std::unique_ptr<ExpressionNode>> _children;
        FermiSourceLocation _location;
    };

    struct TypeNode 
    {
        std::string name;
        FermiSourceLocation loc;

        friend bool operator==(const TypeNode& lhs, const TypeNode& rhs) noexcept = default;
    };

    class VariableDeclarationStatementNode : public StatementNode 
    {
    public:
        VariableDeclarationStatementNode(std::string_view identifier, 
                                         std::optional<TypeNode> type,
                                         std::unique_ptr<ExpressionNode> initializer, 
                                         const FermiSourceLocation& loc);

        SyntaxNodeType getSyntaxNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override;

        const FermiSourceLocation& getSourceLocation() const override;

        const std::string& getIdentifier() const;

        std::optional<TypeNode> getType() const;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    public:
        void print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        std::string _identifier;
        std::optional<TypeNode> _type;
        std::unique_ptr<ExpressionNode> _initializer;
        FermiSourceLocation _location;
    };
}