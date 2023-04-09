#ifndef FERMI_PARSER_HPP
#define FERMI_PARSER_HPP

#include <vector>

#include "FermiLexer.hpp"

namespace Fermi::SyntaxAnalysis
{
    class Parser 
    {
    public:
        auto parse();
    private:
        bool accept(FermiTokenType type);

        bool expect(FermiTokenType type);
    private:
        FermiToken currToken_;
        FermiLexer lexer_;
        std::vector<std::string> errors_;
    };
}

#endif