#ifndef DAG_NODE_HPP
#define DAG_NODE_HPP

#include <memory>
#include <vector>

namespace Fermi::SyntaxAnalysis
{
    class SyntaxNode;
}

namespace Fermi::SemanticAnalysis
{
    enum class DAGNodeType 
    {
        Alloc, 
        Assign, 
        IAdd, 
        FAdd, 
        ISub,
        FSub,
        IToI,
        FToF, 
        IToF
    };

    class DAGNode
    {
    public:
        virtual DAGNodeType getTye() const = 0;

        virtual std::vector<const DAGNode*> getChildren() const = 0;

        virtual ~DAGNode() = default;
    };

    std::unique_ptr<DAGNode> makeDAG(std::shared_ptr<SyntaxAnalysis::SyntaxNode> syntaxTree);
}

#endif