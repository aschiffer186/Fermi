#ifndef FERMI_LEXER_HPP
#define FERMI_LEXER_HPP

#include <iosfwd>

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include "FermiParser.hpp"
#include "location.hh"

namespace Fermi::SyntaxAnalysis
{
    class FermiLexer : public yyFlexLexer
    {
      public:
        explicit FermiLexer(std::istream& in);

        using FlexLexer::yylex;

        auto nextToken() -> FermiParser::semantic_type;

      private:
        location loc_{};
    };
} // namespace Fermi::SyntaxAnalysis

#endif