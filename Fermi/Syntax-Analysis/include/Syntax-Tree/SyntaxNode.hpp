#ifndef SYNTAX_NODE_HPP
#define SYNTAX_NODE_HPP

#include <vector>

namespace Fermi::SyntaxAnalysis
{
    enum class SyntaxNodeType 
    {
        BinaryExpression,
        Literal,
        VariableDeclarationNode, 
        PrintNode, 
        AssignmentStatementNode
    };

    /**
     * @brief Base class of syntax tree node hierarchy.
     * 
     * The SyntaxNode class is a pure virtual base-class that serves as the 
     * base class of all nodes in the syntax node hierarchy. It defines the 
     * functions common to all syntax nodes.
     */
    class SyntaxNode 
    {
    public:

        virtual SyntaxNodeType getNodeType() const = 0;

        virtual std::vector<const SyntaxNode*> getChildren() const = 0;

        virtual ~SyntaxNode() = default;
    };
}

#endif