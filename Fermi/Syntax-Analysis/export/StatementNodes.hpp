#ifndef STATEMENT_NODES_HPP
#define STATEMENT_NODES_HPP

#include <cstddef>
#include <string>
namespace Fermi::SyntaxAnalysis
{
    struct ExpressionStatementNode
    {
        std::size_t expression;

        friend bool operator==(
            const ExpressionStatementNode&,
            const ExpressionStatementNode&) = default;
    };

    struct DeclarationStatementNode
    {
        std::string identifier;
        std::size_t expression;

        friend bool operator==(
            const DeclarationStatementNode&,
            const DeclarationStatementNode&) = default;
    };

} // namespace Fermi::SyntaxAnalysis

#endif