#ifndef DAG_NODE_HPP
#define DAG_NODE_HPP

#include <vector>

namespace Fermi::SemanticAnalysis
{
    class Visitor;

    enum class DAGNodeType 
    {
       BinaryExpresionNode,
       TypeConversionNode
    };

    class DAGNode
    {
    public:
        virtual DAGNodeType getType() const = 0;

        virtual std::vector<const DAGNode*> getChildren() const = 0;

        virtual void accept(Visitor* visitor) const = 0;

        virtual ~DAGNode() = default;
    };
}

#endif