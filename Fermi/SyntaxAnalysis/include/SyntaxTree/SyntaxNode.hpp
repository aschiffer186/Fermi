/**
 * @file SyntaxNode.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief Declaration of syntax node base class
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <iosfwd>
#include <string>
#include <vector>

#include "FermiLexer.hpp"

namespace Fermi::SyntaxAnalysis
{
    inline constexpr const char* TEE = "├──";
    inline constexpr const char* CORNER = "└──";
    inline constexpr const char* PIPE = "|";
    inline const std::string SPACE = "   ";

    enum class SyntaxNodeType 
    {
        AssignmentStatementNode,
        BinaryExpressionNode,
        ExpressionStatementNode,
        FermiStatementNode,
        IdentifierExpressionNode,
        LiteralExpressionNode,
        PrintStatementNode,
        VariableDeclarationStatementNode
    };

    class SyntaxNode 
    {
    public:
        SyntaxNode() noexcept = default;
        SyntaxNode(const SyntaxNode&) = delete; 
        SyntaxNode(SyntaxNode&&) = delete;
        SyntaxNode& operator=(const SyntaxNode&) = delete;
        SyntaxNode& operator=(SyntaxNode&&) = delete;

        virtual SyntaxNodeType getSyntaxNodeType() const = 0;

        virtual std::vector<const SyntaxNode*> getChildren() const = 0;

        virtual const FermiSourceLocation& getSourceLocation() const = 0;

        virtual ~SyntaxNode() = default;
    private:
        virtual bool equals(const SyntaxNode& other) const noexcept = 0;

    public:
        virtual void print(std::ostream& os, std::string indent, bool isLast) const = 0;

    private:
        friend bool operator==(const SyntaxNode& lhs, const SyntaxNode& rhs) noexcept;
        friend std::ostream& operator<<(std::ostream& os, const SyntaxNode& node);
    };

    inline bool operator==(const SyntaxNode& lhs, const SyntaxNode& rhs) noexcept
    {
        if (lhs.getSyntaxNodeType() != rhs.getSyntaxNodeType())
            return false; 
        return lhs.equals(rhs);
    }

    std::ostream& operator<<(std::ostream& os, const SyntaxNode& node);
}