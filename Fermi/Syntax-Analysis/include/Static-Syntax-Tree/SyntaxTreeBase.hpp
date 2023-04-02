#ifndef SYNTAX_TREE_BASE_HPP
#define SYNTAX_TREE_BASE_HPP

#include <concepts>
#include <iosfwd>
#include <variant>
#include <vector>

namespace Fermi::SyntaxAnalysis
{
    template<typename NodeType>
    concept SyntaxNode = std::equality_comparable<NodeType> && 
        requires(NodeType node, std::ostream& os)
        {
            os << node;
        };
    
} // namespace Fermi::SyntaxAnalysis


#endif