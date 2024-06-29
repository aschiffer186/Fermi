%{
    #include "FermiLexer.hpp"

    #include <istream>

    #undef YY_DECL 
    #define YY_DECL auto Fermi::SyntaxAnalysis::FermiLexer::nextToken() -> FermiParser::semantic_type

    using FermiParser = Fermi::SyntaxAnalysis::FermiParser;
%}

%option c++

digit [0-9]
based_digit {digit}|[a-zA-Z]

decimal_integer_literal {digit}+([eE][+]?{digit}+)?
based_integer_literal {digit}{1,2}#{based_digit}+#([+]?{based_digit}+)? 
integer_literal {decimal_integer_literal}|{based_integer_literal}

decimal_float_literal {digit}*\.{digit}+([eE][+-]?{digit}+)?
based_float_literal {digit}{1,2}#{based_digit}*\.{based_digit}+#([+-]?{based_digit}+)?
float_literal {decimal_float_literal}|{based_float_literal}
simple_character [^[:cntrl:]\'\\]
%%
{integer_literal} { return FermiParser::make_INTEGER_LITERAL(loc_); }
{float_literal} { return FermiParser::make_FLOAT_LITERAL(loc_); }
({integer_literal}|{float_literal})i { return FermiParser::make_COMPLEX_LITERAL(loc_); }
'{simple_character}' { return FermiParser::make_CHARACTER_LITERAL (loc_); }
%%
namespace Fermi::SyntaxAnalysis 
{
    FermiLexer::FermiLexer(std::istream& in)
    : yyFlexLexer{&in}
    {

    }
}