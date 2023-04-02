#ifndef EXPRESSION_NODES
#define EXPRESSION_NODES

#include "SyntaxTreeBase.hpp"

#include <string>

namespace Fermi::SyntaxAnalysis
{
    enum class BinaryOperator 
    {
        Addition, 
        Subtraction, 
        Multiplication,
        Division,
        IntegerDivision, 
        Exponentiation, 
        Modulo
    };
    
    template<SyntaxNode Child1, SyntaxNode Child2>
    class BinaryExpressionNode
    {
    public:
        BinaryExpressionNode(const Child1& lhs, BinaryOperator op, const Child2& rhs)
        : lhs_{lhs}, op_{op}, rhs_{rhs}
        {

        }

        BinaryOperator getOperator() const 
        {
            return op_;
        }

        const Child1& getLHS() const
        {
            return lhs_;
        }

        const Child2& getRHS() const 
        {
            return rhs_;
        }
    private:
        Child1 lhs_;
        BinaryOperator op_;
        Child2 rhs_;
    };

    enum class LiteralNodeType 
    {
        Float, 
        Identifier, 
        Integer
    };

    class LiteralNode 
    {
    private:
        LiteralNodeType type_;
        std::string value_;
    };

}

#endif