#ifndef STATEMENT_SYNTAX_NODES_HPP
#define STATEMENT_SYNTAX_NODES_HPP

#include "FermiLexerTypes.hpp"
namespace Fermi::SyntaxAnalysis
{
    struct ExpressionStatemetNode 
    {
        LexicalAnalysis::Location start;
        LexicalAnalysis::Location end; 
        std::size_t expression;

        friend bool operator==(const ExpressionStatemetNode&, const ExpressionStatemetNode&) = default;
    };
}

#endif