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

%nterm <std::vector<std::shared_ptr<StatementNode>>> start
%nterm <std::vector<std::shared_ptr<StatementNode>>> statements
%nterm <std::shared_ptr<StatementNode>> statement 
%nterm <std::shared_ptr<StatementNode>> variable-declaration
%nterm <std::shared_ptr<StatementNode>> print_statement
%nterm <std::shared_ptr<StatementNode>> assignment-statement
%nterm <Type> type
%nterm <std::vector<std::shared_ptr<ExpressionNode>>> expression-list
%nterm <std::shared_ptr<ExpressionNode>> expression
%nterm <std::shared_ptr<ExpressionNode>> creation_expression
%nterm <std::shared_ptr<ExpressionNode>> identity_expression
%nterm <std::shared_ptr<ExpressionNode>> literal
%%
start: statements {$$ = std::move($1);}
statements: statements statement {$1.push_back(std::move($2)); $$ = std::move($1);}
    | %empty {$$ = std::vector<std::shared_ptr<StatementNode>>{};}
    ;
statement: 
    variable-declaration {$$ = std::move($1);}
    | print_statement {$$ = std::move($1);}
    | assignment-statement {$$ = std::move($1);}
    ;
variable-declaration: 
    "let" IDENTIFIER "=" expression {$$ = std::make_shared<VariableDeclarationNode>(Type::deduced, $2, std::move($4));}
    | "let" IDENTIFIER ":" type "=" expression ";" {$$ = std::make_shared<VariableDeclarationNode>($4, $2, std::move($6));}
    ;
type:
    "int8_t" {$$ = Type::int8_t;}
    | "int16_t" {$$ = Type::int16_t;}
    | "int32_t" {$$ = Type::int32_t;}
    | "int64_t" {$$ = Type::int64_t;}
    | "float32_t" {$$ = Type::float32_t;}
    | "float64_t" {$$ = Type::float64_t;}
    ;
print_statement: "print" "(" expression-list ")" ";" {$$ = std::make_shared<PrintNode>(std::move($3));};
expression-list: expression-list "," expression {$1.push_back(std::move($3)); $$ = std::move($1);}
    | expression {std::vector<std::shared_ptr<ExpressionNode>> v; v.push_back(std::move($1)); $$ = std::move(v);}
    ;
assignment-statement: IDENTIFIER "=" expression ";" {$$ = std::make_shared<AssignmentStatementNode>($1, std::move($3));};
expression:
    identity_expression {$$ = std::move($1);}
    | creation_expression {$$ = std::move($1);}
    ;
creation_expression:
    expression "+" expression {$$ = std::make_shared<BinaryExpressionNode>(std::move($1), BinaryExpressionTypes::Addition, std::move($3));}
    | expression "-" expression {$$ = std::make_shared<BinaryExpressionNode>(std::move($1), BinaryExpressionTypes::Subtraction, std::move($3));}
    | expression "*" expression {$$ = std::make_shared<BinaryExpressionNode>(std::move($1), BinaryExpressionTypes::Multiplication, std::move($3));}
    | expression "/" expression {$$ = std::make_shared<BinaryExpressionNode>(std::move($1), BinaryExpressionTypes::Division, std::move($3));}
    | expression "//" expression {$$ = std::make_shared<BinaryExpressionNode>(std::move($1), BinaryExpressionTypes::IntegerDivision, std::move($3));}
    | expression "^" expression {$$ = std::make_shared<BinaryExpressionNode>(std::move($1), BinaryExpressionTypes::Exponentiation, std::move($3));}
    | expression "%" expression {$$ = std::make_shared<BinaryExpressionNode>(std::move($1), BinaryExpressionTypes::Modulo, std::move($3));}
    ;
identity_expression:
    literal {$$ = std::move($1);}
    | IDENTIFIER {$$ = std::make_shared<LiteralNode>($1, LiteralType::Identifier);}
    | "(" expression ")" {$$ = std::move($2);}
    ;
literal: 
    INTEGER_LITERAL {$$ = std::make_shared<LiteralNode>($1, LiteralType::Integer);}
    | FLOAT_LITERAL {$$ = std::make_shared<LiteralNode>($1, LiteralType::Float);}
    ;
%%
namespace Fermi::SyntaxAnalysis
{
    void FermiParser::error(const location&, const std::string&)
    {
        
    }
}