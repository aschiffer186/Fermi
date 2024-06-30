%skeleton "lalr1.cc"
%require "3.2"
%defines 
%locations

%define api.namespace {Fermi::SyntaxAnalysis}
%define api.parser.class {FermiParser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert

// --- Set up code dependencies --- 

%code requires {
    #include <cstdint>

    namespace Fermi::SyntaxAnalysis
    {
        class FermiLexer;
        class FermiSourceFile;
    }   
}

%parse-param {FermiSourceFile& srcFile}

%code {
#include <iostream>

#include "FermiLexer.hpp"
#include "FermiSourceFile.hpp"

#undef yylex 
#define yylex srcFile.getLexer().nextToken
}
// --- Begin list of tokens --- 
%token <std::uint64_t> INTEGER_LITERAL 
%token <double> FLOAT_LITERAL
%token <double> COMPLEX_LITERAL
%token CHARACTER_LITERAL
%token <std::string> IDENTIFIER 

// --- Arithmetic Tokens ---
%token PLUS "+" MINUS "-" STAR "*" SLASH "/" PERCENT "%" CARET "^" ASSIGN "="

// --- Separator Tokens ---
%token LPAREN "(" RPAREN ")" SEMICOLON ";" 

// --- Keyword Tokens ---
%token LET "let"

%left "+" "-"
%left "*" "/" "%"
%right "^"
%%
start: statements ;

statements: 
  statements statement 
  | %empty 
  ;

statement: 
  expression ";" 
  | "let" IDENTIFIER "=" expression ";"

expression: 
      expression "+" expression 
    | expression "-" expression 
    | expression "*" expression 
    | expression "/" expression 
    | expression "%" expression 
    | expression "^" expression 
    | "(" expression ")"
    | INTEGER_LITERAL 
    | FLOAT_LITERAL 
    | COMPLEX_LITERAL
    | IDENTIFIER 
    ;
%%
void Fermi::SyntaxAnalysis::FermiParser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}