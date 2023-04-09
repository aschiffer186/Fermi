#ifndef FERMI_PARSER_NEW_HPP
#define FERMI_PARSER_NEW_HPP

#include "FermiLexer.hpp"
#include "StatementNodes.hpp"

namespace Fermi::SyntaxAnalysis
{
    class FermiParserNew
    {
    public:
        explicit FermiParserNew(FermiLexer& lexer);

        FermiNode parse()
        {
            auto tok = lexer_.nextToken();
        }
    private:
        auto parseStatement();
    private:
        FermiLexer& lexer_;
    };
}

#endif