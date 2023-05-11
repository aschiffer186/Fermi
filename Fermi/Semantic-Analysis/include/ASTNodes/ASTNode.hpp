/**
 * @file ASTNode.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <iosfwd>
#include <string>
#include <vector>

namespace Fermi::SemanticAnalysis
{
    enum class ASTNodeType
    {
        BinaryExpression, 
        FermiStatement,
        LiteralExpression,
        TypeConversion
    };

    class ASTNode 
    {
    public:
        ASTNode(const ASTNode&) = delete;
        ASTNode(ASTNode&&) = delete;
        ASTNode& operator=(const ASTNode&) = delete;
        ASTNode& operator=(ASTNode&&) = delete;

        virtual ~ASTNode() = default;

        virtual std::vector<const ASTNode*> getChildren() const = 0;

        virtual ASTNodeType getNodeType() const = 0;
    
    private: 
        virtual bool equals(const ASTNode& lhs) const noexcept = 0;

        virtual void print(std::ostream& os, std::string indent, bool isLast) const = 0;
    };

    bool operator==(const ASTNode& lhs, const ASTNode& rhs) noexcept;

    std::ostream& operator<<(std::ostream& os, const ASTNode& lhs);
}

#endif