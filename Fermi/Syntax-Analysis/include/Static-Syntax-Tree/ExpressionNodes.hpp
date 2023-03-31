#ifndef EXPRESSION_NODES
#define EXPRESSION_NODES

#include "SyntaxTreeBase.hpp"

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

    class LiteralNode 
    {

    };
    
    class BinaryExpressionNode
    {
    public:
        template<typename LHSNodeType, typename RHSNodeType>
        BinaryExpressionNode(LHSNodeType&& lhs, BinaryOperator op, RHSNodeType&& rhs)
        : lhs_{std::forward<LHSNodeType>(lhs)}
        {

        }
    private:
        NodeView lhs_;
        BinaryOperator op_;
        NodeView rhs_;
    };

}

#endif