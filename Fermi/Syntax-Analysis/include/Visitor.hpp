#ifndef VISITOR_HPP
#define VISITOR_HPP

namespace Fermi::SyntaxAnalysis
{
    class AssignmentStatementNode;
    class BinaryExpressionNode;
    class ExpressionStatementNode;
    class FermiNode;
    class LiteralNode;
    class PrintNode;
    class VariableDeclarationNode;

    class Visitor
    {
    public:
        virtual void visit(const AssignmentStatementNode*) = 0;
        virtual void visit(const BinaryExpressionNode*) = 0;
        virtual void visit(const ExpressionStatementNode*) = 0;
        virtual void visit(const FermiNode*) = 0;
        virtual void visit(const LiteralNode*) = 0;
        virtual void visit(const PrintNode*) = 0;
        virtual void visit(const VariableDeclarationNode*) = 0;
        virtual ~Visitor() = default;
    };
} // namespace Fermi::SyntaxAnalysis


#endif