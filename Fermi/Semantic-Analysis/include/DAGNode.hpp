#ifndef DAG_NODE_HPP
#define DAG_NODE_HPP

#include <vector>

namespace Fermi::SyntaxAnalysis
{
    enum class DAGNodeType 
    {
        Float32Add,
        Float64Add,
        Int8Add,
        Int16Add, 
        Int32Add,
        Int64Add,
        Float32Sub,
        Float64Sub, 
        Int8Sub, 
        Int16Sub,
        Int32Sub,
        Int64Sub,
        Float32Mul, 
        Float64Mul, 
        Int8Mul,
        Int16Mul, 
        Int32Mul, 
        Int64Mul, 
        FloatDivision, 
        IntegerDivision,
        FloatExponentiation,
        IntExponentiation, 
        Modulo,
        FTOLF,
        ITOLI, 
        ITOF,
        Assign, 
        Print
    };

    class DAGNode
    {
    public:
        virtual DAGNodeType getTye() const = 0;

        virtual std::vector<const DAGNode*> getChildren() const = 0;

        virtual ~DAGNode() = default;
    };
}

#endif