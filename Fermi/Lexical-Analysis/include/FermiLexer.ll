%option c++ noyywrap nodefault debug 
%option yyclass = "Fermi::LexicaAnalysis::FermiLexer"

%{
    #include <istream>
    
    #include "FermiLexer.hpp"

    using Lexer = Fermi::LexicalAnalysis::FermiLexer;
    using Token = Fermi::LexicalAnalysis::FermiToken;
    using TokenKind = Fermi::LexicalAnalysis::FermiTokenKind;

    #undef YY_DECL 
    #define YY_DECL Token Lexer::nextToken()

    #undef YY_NULL
    #define YY_NULL Token{}
%}

digit [0-9]
integer {digit}+([+][eE]{digit}+)?
float {digit}*\.{digit}+([+-]?[eE]{digit}+)?
complex ({integer}|{float})i

identifier [_a-zA-Z][_a-zA-Z0-9]*

%%
%{
    _currLoc.column++;
%}

{complex} {return makeToken(TokenKind::ComplexLiteral, yytext);}
{float}   {return makeToken(TokenKind::FloatLiteral, yytext);}
{integer} {return makeToken(TokenKind::IntegerLiteral, yytext);}

"&" {return makeToken(TokenKind::Amp, yytext);}
":" {return makeToken(TokenKind::Colon, yytext);}
"," {return makeToken(TokenKind::Comma, yytext);}
"{" {return makeToken(TokenKind::LeftBrace, yytext);}
"[" {return makeToken(TokenKind::LeftBracket, yytext);}
"(" {return makeToken(TokenKind::LeftParenthesis, yytext);}
"}" {return makeToken(TokenKind::RightBrace, yytext);}
"]" {return makeToken(TokenKind::RightBracket, yytext);}
")" {return makeToken(TokenKind::RightParenthesis, yytext);}
";" {return makeToken(TokenKind::SemiColon, yytext);}

"+"   {return makeToken(TokenKind::Plus, yytext);}
"-"   {return makeToken(TokenKind::Minus, yytext);}
"*"   {return makeToken(TokenKind::Star, yytext);}
"/"   {return makeToken(TokenKind::Slash, yytext);}
"//"  {return makeToken(TokenKind::SlashSlash, yytext);}
"^"   {return makeToken(TokenKind::Caret, yytext);}
"%"   {return makeToken(TokenKind::Percent, yytext);}
"||"  {return makeToken(TokenKind::PipePipe, yytext);}
"!"   {return makeToken(TokenKind::Bang, yytext);}
"=="  {return makeToken(TokenKind::Equal, yytext);}
"!="  {return makeToken(TokenKind::NotEqual, yytext);}
">"   {return makeToken(TokenKind::Greater, yytext);}
"<"   {return makeToken(TokenKind::Less, yytext);}
">="  {return makeToken(TokenKind::GreaterEqual, yytext);}
"<="  {return makeToken(TokenKind::LessEqual, yytext);}
"<=>" {return makeToken(TokenKind::Spaceship, yytext);}
"."   {return makeToken(TokenKind::Dot, yytext);}
"="   {return makeToken(TokenKind::Assign, yytext);}

"as" {return makeToken(TokenKind::As, yytext);}
"define" {return makeToken(TokenKind::Define, yytext);}
"export" {return makeToken(TokenKind::Export, yytext);}
"let" {return makeToken(TokenKind::Let, yytext);}
"module" {return makeToken(TokenKind::Module, yytext);}
"nothrow" {return makeToken(TokenKind::Nothrow, yytext);}
"operator" {return makeToken(TokenKind::Operator, yytext);}
"public" {return makeToken(TokenKind::Public, yytext);}
"pure" {return makeToken(TokenKind::Pure, yytext);}
"struct" {return makeToken(TokenKind::Struct, yytext);}
"template" {return makeToken(TokenKind::Template, yytext);}
"typeset" {return makeToken(TokenKind::Typeset, yytext);}

{identifier} {return makeToken(TokenKind::Identifier, yytext);}

. {return makeToken(TokenKind::FermiEOF, yytext);}

<<EOF>> {return makeToken(TokenKind::FermiEOF, "$");}

%%

namespace Fermi::LexicalAnalysis
{
    FermiLexer::FermiLexer(std::istream& is)
    : yyFlexLexer(&is)
    {

    }

    std::vector<FermiToken> FermiLexer::lex()
    {
        std::vector<FermiToken> tokens;
        FermiToken tok;
        while(true)
        {
            tok = nextToken();
            if (tok.kind == FermiTokenKind::FermiEOF)
                break;
            tokens.push_back(std::move(tok));
        }
        tokens.push_back(std::move(tok));
        return tokens;
    }

    FermiToken FermiLexer::makeToken(FermiTokenKind kind, std::string value) const
    {
        return FermiToken{.start = _currLoc, .end = _currLoc, .kind = kind, .value = std::move(value)};
    }
}
