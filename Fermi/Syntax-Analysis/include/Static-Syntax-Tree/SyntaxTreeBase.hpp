#ifndef SYNTAX_TREE_BASE_HPP
#define SYNTAX_TREE_BASE_HPP

#include <concepts>
#include <iosfwd>
#include <variant>
#include <vector>

namespace Fermi::SyntaxAnalysis
{
    class BinaryExpressionNode;
    class LiteralNode;

    using NodeView = std::variant<BinaryExpressionNode, LiteralNode>;

    template<typename NodeType>
    concept SyntaxNode = std::equality_comparable<NodeType> && 
        requires(NodeType node, std::ostream& os)
        {
            {node.getChildren()} -> std::same_as<std::vector<NodeView>>;
            os << node;
        };
    
} // namespace Fermi::Synta


#endif