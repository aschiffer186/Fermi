%option c++ noyywrap nodefault debug 
%option yyclass = "Fermi::SyntaxAnalysis::Lexer"

%{
    #include <istream>
    #include <ostream>

    #include "FermiLexer.hpp"

    #ifdef YY_DECL
    #undef YY_DECL
    #endif 

    using Lexer = Fermi::SyntaxAnalysis::FermiLexer;
    using Token = Fermi::SyntaxAnalysis::FermiToken;

    #define YY_DECL Token Lexer::nextToken()
    #define YY_USER_ACTION _col += yyleng;

    #ifdef YY_NULL
    #undef YY_NULL
    #endif 
    #define YY_NULL makeEOF();
%}

digit [0-9]
identifier_start [a-zA-Z]
identifier_cont [a-zA-Z0-9]

integer_literal {digit}+
float_literal {digit}*\.{digit}+([eE][+-]?{digit}+)?

identifier {identifier_start}{identifier_cont}*

space [ \t\r]

%%

\n+ _line += yyleng; _col = 1;
{space}+ ++_col;

{integer_literal} {return makeToken(FermiTokenType::IntegerLiteral);}
{float_literal} {return makeToken(FermiTokenType::FloatLiteral);}

"+" {return makeToken(FermiTokenType::Plus);}
"-" {return makeToken(FermiTokenType::Minus);}
"*" {return makeToken(FermiTokenType::Star);}
"/" {return makeToken(FermiTokenType::Slash);}
"//" {return makeToken(FermiTokenType::DoubleSlash);}
"^" {return makeToken(FermiTokenType::Caret);}
"%" {return makeToken(FermiTokenType::Percent);}
"=" {return makeToken(FermiTokenType::Equal);}

";" {return makeToken(FermiTokenType::SemiColon);}
":" {return makeToken(FermiTokenType::Colon);}
"(" {return makeToken(FermiTokenType::LeftParenthesis);}
")" {return makeToken(FermiTokenType::RightParenthesis);}
"," {return makeToken(FermiTokenType::Comma);}

"let" {return makeToken(FermiTokenType::Let);}
"print" {return makeToken(FermiTokenType::Print);}

{identifier} {return makeToken(FermiTokenType::Identifier);}

<<EOF>> {return makeEOF();}
. {return makeToken(FermiTokenType::Error);}

%%

namespace Fermi::SyntaxAnalysis
{
    FermiLexer::FermiLexer(std::istream& in)
    : yyFlexLexer{&in}, _line{1}, _col{1}
    {

    }

    FermiToken FermiLexer::makeToken(FermiTokenType type)
    {
        std::string value{yytext};
        std::size_t startCol = _col - value.length();
        return FermiToken{.location={.line = _line, .startCol = startCol, .endCol = _col - 1},
                          .type = type,
                          .value = value};
    }

    FermiToken FermiLexer::makeEOF()
    {
        return FermiToken{.location={.line = _line, .startCol = _col, .endCol = _col},
                          .type = FermiTokenType::FermiEOF,
                          .value = "$"};
    }

    std::ostream& operator<<(std::ostream& os, FermiTokenType type)
    {
        os << typeNames[static_cast<short>(type)];
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const FermiToken& token)
    {
        os << "{Line: " << token.location.line << ", Start Col: " << token.location.startCol; 
        os << ", End Col: " << token.location.endCol;
        os << ", Type: " << token.type << ", Value: " << token.value << "}";
        return os;
    }
}
