%require "3.7"
%skeleton "lalr1.cc"
%locations 

%define api.location.file "../include/Location.hpp"
%define api.namespace {Fermi::SyntaxAnalysis}
%define api.parser.class {FermiParser}
%define api.token.constructor 
%define api.token.raw
%define api.value.type variant 

%define parse.assert 
%define parse.error detailed 
%define parse.lac full 
%define parse.trace


%code requires {
    #include <string>

    namespace Fermi::SyntaxAnalysis { class FermiLexer; }
}

%parse-param {Fermi::SyntaxAnalysis::FermiLexer& lexer}

%code {
    #include "FermiLexer.hpp"

    #define yylex lexer.nextToken
}

// Literals
%token <std::string> INTEGER_LITERAL <std::string> FLOAT_LITERAL ;
%token <std::string> IDENTIFIER 
// Operators
%token PLUS "+" MINUS "-" STAR "*" SLASH "/" SLASH_SLASH "//" CARET "^" PERCENT "%" ;
%token ASSIGN "=" ;

%token SEMI_COLON ";" LEFT_PARENTHESIS "(" RIGHT_PARENTHESIS ")" COMMA "," COLON ":" ;

// Keywords
%token LET "let" PRINT "print" ;
%token INT8_T "int8_t" INT16_T "int16_t" INT32_T "int32_t" INT64_T "int64_t" ;
%token FLOAT32_T "float32_t" FLOAT64_T "float64_t" ;

%right "="
%left "+" "-"
%left "*" "/" "//" "%"
%right "^"
%%
start: statements
statements: statements statement 
    | %empty 
    ;
statement: 
    variable-declaration
    | print_statement
    | assignment-statement
    ;
variable-declaration: 
    "let" IDENTIFIER "=" expression ;
    | "let" IDENTIFIER ":" type "=" expression ";"
type:
    "int8_t"
    | "int16_t"
    | "int32_t"
    | "int64_t"
    | "float32_t"
    | "float64_t"
    ;
print_statement: "print" "(" expression-list ")" ";" ;
expression-list: expression-list "," expression 
    | expression 
    ;
assignment-statement: IDENTIFIER "=" expression ";" ;
expression:
    identity_expression 
    | creation_expression 
    ;
creation_expression:
    expression "+" expression
    | expression "-" expression 
    | expression "*" expression 
    | expression "/" expression 
    | expression "//" expression 
    | expression "^" expression 
    | expression "%" expression 
    ;
identity_expression:
    literal
    | IDENTIFIER
    | "(" expression ")"
    ;
literal: 
    INTEGER_LITERAL 
    | FLOAT_LITERAL
    ;
%%