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
#include "FermiLexer.hpp"

#undef yylex 
#define yylex lexer.nextToken
}
// --- Begin list of tokens --- 
%token INTEGER_LITERAL 
%token FLOAT_LITERAL
%token COMPLEX_LITERAL
%token CHARACTER_LITERAL
%%
start: %empty;