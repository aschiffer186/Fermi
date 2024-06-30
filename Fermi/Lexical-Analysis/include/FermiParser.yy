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
    }   
}

%parse-param {FermiLexer& lexer}

%code {
#include <iostream>

#include "FermiLexer.hpp"

#undef yylex 
#define yylex lexer.nextToken
}
// --- Begin list of tokens --- 
%token <std::uint64_t> INTEGER_LITERAL 
%token <double> FLOAT_LITERAL
%token <double> COMPLEX_LITERAL
%token CHARACTER_LITERAL

// --- Arithmetic Tokens ---
%token PLUS "+" MINUS "-" STAR "*" SLASH "/" PERCENT "%" CARET "^"

%left "+" "-"
%left "*" "/" "%"
%right "^"
%%
start: expressions ;

expressions:
      expressions expression 
    | %empty 
    ;

expression: 
      expression "+" expression 
    | expression "-" expression 
    | expression "*" expression 
    | expression "/" expression 
    | expression "^" expression 
    | INTEGER_LITERAL 
    | FLOAT_LITERAL 
    | COMPLEX_LITERAL
    ;
%%
void Fermi::SyntaxAnalysis::FermiParser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}