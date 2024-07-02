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
#include "SyntaxNodes.hpp"

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
  expression ";" {
    const std::size_t idx = srcFile.syntaxTreeSize() - 1; 
    srcFile.emplaceNode<ExpressionStatementNode>(idx);
  }
  | "let" IDENTIFIER "=" expression ";" { 
      const std::size_t idx = srcFile.syntaxTreeSize() - 1;
      srcFile.emplaceNode<DeclarationStatementNode>($2, idx); 
    }

expression: 
      expression "+" expression { 
        const std::size_t idx = srcFile.syntaxTreeSize() - 2;
        const std::size_t idx2 = srcFile.syntaxTreeSize() - 1; 
        srcFile.emplaceNode<BinaryExpressionNode>(idx, BinaryOperation::Addition, idx2);
      } 
    | expression "-" expression { 
        const std::size_t idx = srcFile.syntaxTreeSize() - 2;
        const std::size_t idx2 = srcFile.syntaxTreeSize() - 1; 
        srcFile.emplaceNode<BinaryExpressionNode>(idx, BinaryOperation::Subtraction, idx2);
      } 
    | expression "*" expression { 
        const std::size_t idx = srcFile.syntaxTreeSize() - 2;
        const std::size_t idx2 = srcFile.syntaxTreeSize() - 1; 
        srcFile.emplaceNode<BinaryExpressionNode>(idx, BinaryOperation::Multiplication, idx2);
      } 
    | expression "/" expression { 
        const std::size_t idx = srcFile.syntaxTreeSize() - 2;
        const std::size_t idx2 = srcFile.syntaxTreeSize() - 1; 
        srcFile.emplaceNode<BinaryExpressionNode>(idx, BinaryOperation::Division, idx2);
      } 
    | expression "%" expression { 
        const std::size_t idx = srcFile.syntaxTreeSize() - 2;
        const std::size_t idx2 = srcFile.syntaxTreeSize() - 1; 
        srcFile.emplaceNode<BinaryExpressionNode>(idx, BinaryOperation::Modulo, idx2);
      } 
    | expression "^" expression { 
        const std::size_t idx = srcFile.syntaxTreeSize() - 2;
        const std::size_t idx2 = srcFile.syntaxTreeSize() - 1; 
        srcFile.emplaceNode<BinaryExpressionNode>(idx, BinaryOperation::Exponentiation, idx2);
      } 
    | "(" expression ")" { srcFile.emplaceNode<ParenthesizedExpressionNode>(srcFile.syntaxTreeSize()); }
    | INTEGER_LITERAL { srcFile.emplaceNode<LiteralExpressionNode>($1, LiteralExpressionType::Integer); }
    | FLOAT_LITERAL { srcFile.emplaceNode<LiteralExpressionNode>($1, LiteralExpressionType::Float); }
    | COMPLEX_LITERAL { srcFile.emplaceNode<LiteralExpressionNode>($1, LiteralExpressionType::Complex); }
    | IDENTIFIER { srcFile.emplaceNode<IdentifierExpressionNode>($1); }
    ;
%%
void Fermi::SyntaxAnalysis::FermiParser::error (const location_type& l, const std::string& m)
{
  std::cerr << "Error at " << l << ": " << m << '\n';
}