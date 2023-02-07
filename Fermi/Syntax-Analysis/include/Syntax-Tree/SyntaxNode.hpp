#ifndef SYNTAX_NODE_HPP
#define SYNTAX_NODE_HPP

#include <ostream>
#include <typeinfo>
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

        /**
         * @brief Return the node type
         * 
         * Returns an enum indicating which concrete syntax tree node is represented 
         * by *this. This enum can be used to down-cast from general syntax node types 
         * to specific syntax node types
         * 
         * @return an enum indicating the concrete syntax tree node 
         */
        virtual SyntaxNodeType getNodeType() const = 0;

        /**
         * @brief Returns the children of the current node
         * 
         * Returns a std::vector containing pointers to the children of *this. 
         * If *this has no children (is a leaf node), then the returned vector 
         * will be empty.
         * 
         * @return a std::vector contain pointers to the children of *this.
         */
        virtual std::vector<const SyntaxNode*> getChildren() const = 0;

        virtual ~SyntaxNode() = default;
    private:
        // @pre typeid(other) == typeid(*this)
        virtual bool equals(const SyntaxNode& other) const noexcept = 0; 
        virtual std::ostream& print(std::ostream& os) const = 0;

        friend bool operator==(const SyntaxNode& lhs, const SyntaxNode& rhs) noexcept;
        friend std::ostream& operator<<(std::ostream& os, const SyntaxNode& node);
    };

    inline bool operator==(const SyntaxNode& lhs, const SyntaxNode& rhs) noexcept
    {
        return typeid(lhs) == typeid(rhs) && lhs.equals(rhs);
    }

    inline std::ostream& operator<<(std::ostream& os, const SyntaxNode& node)
    {
        node.print(os);
        return os;
    }
}

#endif