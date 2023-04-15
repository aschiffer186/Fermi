/**
 * @file Visitor.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef VISITOR_HPP
#define VISITOR_HPP

namespace Fermi::SyntaxAnalysis
{
    class AssignmentStatementNode;
    class BinaryExpressionNode;
    class ExpressionStatementNode;
    class FermiStatementNode;
    class LiteralExpressionNode;
    class PrintStatementNode;
    class VariableDeclarationStatementNode;

    class Visitor
    {
    public:
        virtual void visit(const AssignmentStatementNode*) = 0;
        virtual void visit(const BinaryExpressionNode*) = 0;
        virtual void visit(const ExpressionStatementNode*) = 0;
        virtual void visit(const FermiStatementNode*) = 0;
        virtual void visit(const LiteralExpressionNode*) = 0;
        virtual void visit(const PrintStatementNode*) = 0;
        virtual void visit(const VariableDeclarationStatementNode*) = 0;
        virtual ~Visitor() = default;
    };
} // namespace Fermi::SyntaxAnalysis


#endif