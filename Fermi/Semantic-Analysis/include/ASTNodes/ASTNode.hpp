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
        virtual ~ASTNode() = default;

        virtual std::vector<const ASTNode*> getChildren() const = 0;

        virtual ASTNodeType getNodeType() const = 0;
    };
}

#endif