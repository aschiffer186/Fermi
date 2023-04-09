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

    #include "ExpressionNode.hpp"
    #include "StatementNode.hpp"

    #include "Static-Syntax-Tree/ExpressionNodes.hpp"
    #include "Static-Syntax-Tree/StatementNodes.hpp"

    namespace Fermi::SyntaxAnalysis 
    { 
        class FermiSourceFile; 
        class FermiLexer;
    }
}

%parse-param {Fermi::SyntaxAnalysis::FermiSourceFile& sourceFile}
%parse-param {Fermi::SyntaxAnalysis::FermiLexer& lexer}

%code {
    #include "FermiSourceFile.hpp"
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

%nterm <std::shared_ptr<FermiNode>> start
%nterm <std::vector<std::shared_ptr<StatementNode>>> statements
%nterm <std::shared_ptr<StatementNode>> statement 
%nterm <std::shared_ptr<ExpressionStatementNode>> expression-statement
%nterm <std::shared_ptr<StatementNode>> variable-declaration
%nterm <std::shared_ptr<StatementNode>> print_statement
%nterm <std::shared_ptr<StatementNode>> assignment-statement
%nterm <Type> type
%nterm <std::vector<std::shared_ptr<ExpressionNode>>> expression-list
%nterm <std::shared_ptr<ExpressionNode>> expression
%nterm <std::shared_ptr<ExpressionNode>> creation_expression
%nterm <std::shared_ptr<ExpressionNode>> identity_expression
%nterm <LiteralExpressionNode> literal
%%
start: statements {sourceFile.setSyntaxTree(std::make_unique<FermiNode>($1));}
statements: statements statement {$1.push_back($2); $$ = $1;}
    | %empty {$$ = std::vector<std::shared_ptr<StatementNode>>{};}
    ;
statement: 
    expression-statement {$$ = $1;}
    | variable-declaration {$$ = $1;}
    | print_statement {$$ = $1;}
    | assignment-statement {$$ = $1;}
    ;
expression-statement: expression ";" {$$ = std::make_shared<ExpressionStatementNode>($1);}
variable-declaration: 
    "let" IDENTIFIER "=" expression ";" {$$ = std::make_shared<VariableDeclarationNode>(Type::deduced, $2, $4);}
    | "let" IDENTIFIER ":" type "=" expression ";" {$$ = std::make_shared<VariableDeclarationNode>($4, $2, $6);}
    | "let" IDENTIFIER ":" type ";" {$$ = std::make_shared<VariableDeclarationNode>($4, $2);}
    ;
type:
    "int8_t" {$$ = Type::int8_t;}
    | "int16_t" {$$ = Type::int16_t;}
    | "int32_t" {$$ = Type::int32_t;}
    | "int64_t" {$$ = Type::int64_t;}
    | "float32_t" {$$ = Type::float32_t;}
    | "float64_t" {$$ = Type::float64_t;}
    ;
print_statement: "print" "(" expression-list ")" ";" {$$ = std::make_shared<PrintNode>($3);};
expression-list: expression-list "," expression {$1.push_back($3); $$ = $1;}
    | expression {std::vector<std::shared_ptr<ExpressionNode>> v; v.push_back($1); $$ = v;}
    ;
assignment-statement: IDENTIFIER "=" expression ";" {$$ = std::make_shared<AssignmentStatementNode>($1, $3);}
    | IDENTIFIER "=" expression error {sourceFile.addDiagnostic("Expected \";\" on line: ");}
    ;
expression:
    identity_expression {$$ = $1;}
    | creation_expression {$$ = $1;}
    ;
creation_expression:
    expression "+" expression {$$ = BinaryExpressionNode{$1, BinaryOperator::Addition, $3};}
    | expression "-" expression {$$ = BinaryExpressionNode{$1, BinaryOperator::Subtraction, $3};}
    | expression "*" expression {$$ = BinaryExpressionNode{$1, BinaryOperator::Multiplication, $3};}
    | expression "/" expression {$$ = BinaryExpressionNode{$1, BinaryOperator::Division, $3};}
    | expression "//" expression {$$ = BinaryExpressionNode{$1, BinaryOperator::IntegerDivision, $3};}
    | expression "^" expression {$$ = BinaryExpressionNode{$1, BinaryOperator::Exponentiation, $3};}
    | expression "%" expression {$$ = BinaryExpressionNode{$1, BinaryOperator::Modulo, $3};}
    ;
identity_expression:
    literal {$$ = $1;}
    | IDENTIFIER {$$ = LitealExpressionNode{$1, LiteralNodeType::Identifier};}
    | "(" expression ")" {$$ = $2;}
    ;
literal: 
    INTEGER_LITERAL {$$ = LiteralExpressionNode{$1, LiteralNodeType::Integer};}
    | FLOAT_LITERAL {$$ = LiteralExpressionNode{$1, LiteralType::Float};}
    ;
%%
namespace Fermi::SyntaxAnalysis
{
    void FermiParser::error(const location& loc, const std::string& msg)
    {
        std::string errorMsg = "Error: " + msg; 
        errorMsg.append(" on line: ").append(std::to_string(loc.begin.line));
        errorMsg.append(", col: ").append(std::to_string(loc.end.line));
        sourceFile.addDiagnostic(errorMsg);
    }
}