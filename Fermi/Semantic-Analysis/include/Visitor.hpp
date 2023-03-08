#ifndef VISITOR_HPP
#define VISITOR_HPP


namespace Fermi::SemanticAnalysis
{
    class AssignNode;
    class BinaryExpressionNode;
    class LiteralNode;
    class TypeConversionNode;

    class Visitor
    {
    public:
        virtual void visit(const AssignNode* node) = 0;
        virtual void visit(const BinaryExpressionNode* node) = 0;
        virtual void visit(const TypeConversionNode* node) = 0;
        virtual void visit(const LiteralNode* node) = 0;
        virtual ~Visitor() = default;
    };
} // namespace Fermi::SemanticAnalysis


#endif