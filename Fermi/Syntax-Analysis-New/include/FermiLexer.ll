%option c++ noyywrap nodefault debug 
%option yyclass = "Fermi::SyntaxAnalysis::Lexer"

%{
    #include <istream>

    #include "FermiLexer.hpp"

    #ifdef YY_DECL
    #undef YY_DECL
    #endif 

    using Lexer = Fermi::SyntaxAnalysis::FermiLexer;
    using TokenType = Fermi::SyntaxAnalysis::FermiToken;

    #define YY_DECL TokenType Lexer::nextToken()
    #define YY_USER_ACTION line_ += yyleng;

    #ifdef YY_NULL
    #undef YY_NULL
    #endif 
    #define YY_NULL return makeToken(FermiTokenType::FermiEOF);
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
    ++col_;
%}
\n+ ++line_; col_ = 1;
{space}+ ++col_;

{integer_literal} {return makeToken(FermiTokenType::IntegerLiteral);}
{float_literal} {return makeToken(FermiTokenType::FloatLiteral);}

"+" {return makeToken(FermiTokenType::Plus);}
"-" {return makeToken(FermiTokenType::Minus);}
"*" {return makeToken(FermiTokenType::Star);}
"/" {return makeToken(FermiTokenType::Slash);}
"//" {return makeToken(FermiTokenType::SlashSlash);}
"^" {return makeToken(FermiTokenType::Caret);}
"%" {return makeToken(FermiTokenType::Percent);}
"=" {return makeToken(FermiTokenType::Assign);}

":" {return makeToken(FermiTokenType::Colon);}
";" {return makeToken(FermiTokenType::SemiColon);}
"(" {return makeToken(FermiTokenType::LeftParenthesis);}
")" {return makeToken(FermiTokenType::RightParenthesis);}
"," {return makeToken(FermiTokenType::Comma);}

"float32_t" {return makeToken(FermiTokenType::Float32T);}
"float64_t" {return makeToken(FermiTokenType::Float64T);}
"int8_t" {return makeToken(FermiTokenType::Int8T);}
"int16_t" {return makeToken(FermiTokenType::Int16T);}
"int32_t" {return makeToken(FermiTokenType::Int32T);}
"int64_t" {return makeToken(FermiTokenType::Int64T);}
"let" {return makeToken(FermiTokenType::Let);}
"print" {return makeToken(FermiTokenType::Print);}

{identifier} {return makeToken(FermiTokenType::Identifier);}

<<EOF>> {return makeToken(FermiTokenType::FermiEOF);}
. {
    std::cerr << "Unexpected token \"" << yytext;
    std::cerr << "\" on line: " << line_; 
    std::cerr << ", col: " << col_ << "\n";
    return makeToken(FermiTokenType::Error);
}

%%
namespace Fermi::SyntaxAnalysis
{
    FermiLexer::FermiLexer(std::istream& in)
    : yyFlexLexer{&in}, line_{1}, col_{1}
    {

    }

    FermiToken FermiLexer::makeToken(FermiTokenType type)
    {
        return FermiToken{.line=line_, .startCol = col_ - std::strlen(yytext), .endCol=col_, .value=yytext, .type=type};
    }
}