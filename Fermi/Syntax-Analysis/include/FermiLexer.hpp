#ifndef FERMI_LEXER_HPP
#define FERMI_LEXER_HPP

#include <iosfwd>

#ifndef yyFlexLexer
#include <FlexLexer.h>
#endif

#include "Location.hpp"
#include "FermiParser.hpp"

namespace Fermi::SyntaxAnalysis
{
    class FermiLexer : public yyFlexLexer
    {
    public:
        explicit FermiLexer(std::istream& in);

        using FlexLexer::yylex;

        FermiParser::symbol_type nextToken();
    private:
        location loc_;
    };
} // namespace Fermi::SyntaxAnalysis


#endif