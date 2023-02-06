%option c++ noyywrap nodefault debug 
%option yyclass = "Fermi::SyntaxAnalysis::Lexer"

%{
    #include <istream>

    #include "FermiLexer.hpp"

    #ifdef YY_DECL
    #undef YY_DECL
    #endif 

    using Parser = Fermi::SyntaxAnalysis::FermiParser;
    using Lexer = Fermi::SyntaxAnalysis::FermiLexer;

    #define YY_DECL Parser::symbol_type Lexer::nextToken()
    #define YY_USER_ACTION loc_.columns(yyleng);

    #ifdef YY_NULL
    #undef YY_NULL
    #endif 
    #define YY_NULL Parser::make_YYEOF(loc_)
%}

digit [0-9]
identifier_start [a-zA-Z]
identifier_cont [a-zA-Z0-9]

integer_literal {digit}+
float_literal {digit}*\.{digit}+([eE][+-]?{digit}+)?

identifier {identifier_start}{identifier_cont}*

space [ \t\r]
%%
%{
    loc_.step();
%}
\n+ loc_.lines(yyleng); loc_.step();
{space}+ loc_.step();

{integer_literal} {return Parser::make_INTEGER_LITERAL(yytext, loc_);}
{float_literal} {return Parser::make_FLOAT_LITERAL(yytext, loc_);}

"+" {return Parser::make_PLUS(loc_);}
"-" {return Parser::make_MINUS(loc_);}
"*" {return Parser::make_STAR(loc_);}
"/" {return Parser::make_SLASH(loc_);}
"//" {return Parser::make_SLASH_SLASH(loc_);}
"^" {return Parser::make_CARET(loc_);}
"%" {return Parser::make_PERCENT(loc_);}
"=" {return Parser::make_ASSIGN(loc_);}

":" {return Parser::make_COLON(loc_);}
";" {return Parser::make_SEMI_COLON(loc_);}
"(" {return Parser::make_LEFT_PARENTHESIS(loc_);}
")" {return Parser::make_RIGHT_PARENTHESIS(loc_);}
"," {return Parser::make_COMMA(loc_);}

"float32_t" {return Parser::make_FLOAT32_T(loc_);}
"float64_t" {return Parser::make_FLOAT64_T(loc_);}
"int8_t" {return Parser::make_INT8_T(loc_);}
"int16_t" {return Parser::make_INT16_T(loc_);}
"int32_t" {return Parser::make_INT32_T(loc_);}
"int64_t" {return Parser::make_INT64_T(loc_);}
"let" {return Parser::make_LET(loc_);}
"print" {return Parser::make_PRINT(loc_);}

{identifier} {return Parser::make_IDENTIFIER(yytext, loc_);}

<<EOF>> {return Parser::make_YYEOF(loc_);}
. {return Parser::make_YYerror(loc_);}

%%
namespace Fermi::SyntaxAnalysis
{
    FermiLexer::FermiLexer(std::istream& in)
    : yyFlexLexer{&in}, loc_{}
    {

    }
}