%skeleton "lalr1.cc"
%require "3.2"
%defines 
%locations

%define api.namespace {Fermi::SyntaxAnalysis}
%define api.parser.class {FermiParser}
%define api.value.type variant
%define parse.assert

%code requires {
    #include <cstdint>
}

// --- Begin list of tokens --- 
%token INTEGER_LITERAL 
%token FLOAT_LITERAL
%token COMPLEX_LITERAL
%token CHARACTER_LITERAL
%%
start: %empty;