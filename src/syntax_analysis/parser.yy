%require "3.7"
%skeleton "lalr1.cc"
%locations 

%define api.location.file "./location.hpp"
%define api.namespace {fermi}
%define api.parser.class {parser}
%define api.token.constructor 
%define api.token.raw
%define api.value.type variant 

%define parse.assert 
%define parse.error detailed 
%define parse.lac full 
%define parse.trace

%code requires {
    #include <string_view>

    #include "syntax_node.hpp"

    namespace fermi {
        class lexer;
    }
}

%code {
    #include "lexer.hpp"
}

%parse-param {fermi::lexer& lexer_}
%parse-param {std::vector<syntax_nodes::syntax_node>& syntax_tree_}

%code {
    #define yylex lexer_.next_token

    using namespace fermi::syntax_nodes;
}
 
// Literals
%token <std::string_view> INTEGER  <std::string_view> FLOAT <std::string_view> COMPLEX <std::string_view> CHARACTER <std::string_view> STRING ;
// Identifiers 
%token <std::string_view> IDENTIFIER <std::string_view> TYPE_NAME;
// Keywords
%token AS "as" AMPERSAND "&" AND "and";
%token BOOL "bool" ; 
%token COMPEVAL "compeval" ; 
%token DEFINE "define" ; 
%token ELSE "else" ELSIF "elsif" EXPORT "export" ;
%token FALSE "false" FOR "for" ;
%token IF "if" IMPORT "import" IN "in" INT "int";
%token LET "let" ;
%token MATCH "match" MODULE "module" MOVE "move" MUTABLE "mutable" ;
%token NEW "new" NOT "not";
%token OPERATOR "operator" OR "or" OUT "out" ;
%token PUBLIC "public" PURE "pure" ;
%token RANGE "range" REQUIRES "requires" RETURN "return" ;
%token STATIC "static" STRUCT "struct" ;
%token THIS "this" TRUE "true" TYPE "type" TYPEOF "typeof" TYPESET "typeset"
%token WHERE "where" WHILE "while" WITH "with" ;
// Punctuators
%token COLON ":" COLON_COLON "::" ; 
%token LEFT_BRACE "{" LEFT_BRACKET "[" LEFT_PARENTHESIS "(" ;
%token RIGHT_BRACE "}" RIGHT_BRACKET "]" RIGHT_PARENTHESIS ")" ;
%token SEMICOLON ";" ;
// Operators
%token ASSIGN "=" ;
%token BANG "!" BANG_EQUAL "!=" ;
%token CARET "^" CARET_EQUAL "^=" COMMA ",";
%token DOT "." ;
%token EQUAL_EQUAL "==";
%token GREATER ">" GREATER_EQUAL ">=" ;
%token LEFT_ARROW "<-" LESS "<" LESS_EQUAL "<="; 
%token RIGHT_ARROW "->" ;
%token MINUS "-" MINUS_EQUAL "-=" MINUS_MINUS "--";
%token PERCENT "%" PERCENT_EQUAL "%=" PIPE "|" PLUS "+" PLUS_EQUAL "+=" PLUS_PLUS "++";
%token SLASH "/" SLASH_EQUAL "/=" SLASH_SLASH "//" SLASH_SLASH_EQUAL "//=" SPACESHIP "<=>" STAR "*" STAR_EQUAL "*=";

%left "or"
%left "and"
%left "==" "!="
%left "<" "<=" ">" ">="
%left "<=>"
%left "+" "-"
%left "*" "%" "/" "//"
%right "^"
%right "++" "--" "not"
%left "." "!"

// Expressions
%nterm <std::size_t> expression ;
%nterm <std::size_t> primary-exression ;
%nterm <std::size_t> binary-expression ; 
%nterm <std::size_t> unary-expression ; 
%nterm <std::size_t> function-call-expression ;
%nterm <std::size_t> absolute-value-expression ;
%nterm <std::size_t> array-index-expression ;
%nterm <std::size_t> literal ;
%nterm <std::vector<std::size_t>> expression-list ;
%nterm <std::vector<std::size_t>> expression-list-opt ;

// Statements
%nterm <std::size_t> statement ;
%nterm <std::size_t> assignment-statement ;
%nterm <std::size_t> compound-statement ;
%nterm <std::vector<std::size_t>> statements ;

// Declarations 
%nterm <std::size_t> variable-declaration ;
%nterm <std::size_t> type ;
%nterm <std::size_t> simple-type ;
%nterm <std::size_t> function-parameter ;
%nterm <syntax_nodes::function_parameter_attributes::attribute> mode ;
%nterm <std::vector<std::size_t>> function-parameter-list ;
%nterm <std::vector<std::size_t>> function-parameter-list-opt ;
%nterm <std::size_t> return-type-opt ; 
%nterm <std::size_t> return-type ;
%nterm <std::size_t> function-declaration ;
%nterm <std::size_t> declaration ;
%%
start: declarations ;
// Declarations
declarations: 
      declarations declaration
    | %empty 
    ; 
declaration: 
      variable-declaration { $$ = $1;}
    | function-declaration { $$ = $1; }
    ;
variable-declaration: 
    "let" IDENTIFIER ";" {
        syntax_tree_.push_back(variable_declaration_node{.name = $2, .type = missing_expression, .initializer = missing_expression});
        $$ = syntax_tree_.size() - 1;
    }
    | "let" IDENTIFIER ":" type ";" {
        variable_declaration_node node {
            .name = $2, 
            .type = $4,
            .initializer = missing_expression
        };
        syntax_tree_.push_back(node);
        $$ = syntax_tree_.size() - 1;
    }
    | "let" IDENTIFIER "=" expression ";" {
        variable_declaration_node node {
            .name = $2, 
            .type = missing_expression,
            .initializer = $4
        };
        syntax_tree_.push_back(node);
        $$ = syntax_tree_.size() - 1;
    }
    | "let" IDENTIFIER ":" type "=" expression ";" {
         variable_declaration_node node {
            .name = $2, 
            .type = $4,
            .initializer = $6
        };
        syntax_tree_.push_back(node);
        $$ = syntax_tree_.size() - 1;
    }
    ;
type: 
      simple-type {$$ = $1;}
    | type "&" /* Reference */ {
        type_node type {
            .inner_type = $1, 
            .attribute = type_attributes::reference
        };
        syntax_tree_.push_back(type);
        $$ = syntax_tree_.size() - 1;
    }
    | type "*" /* Pointer */ {
        type_node type {
            .inner_type = $1, 
            .attribute = type_attributes::pointer
        };
        syntax_tree_.push_back(type);
        $$ = syntax_tree_.size() - 1;
    }
    | type "[" "]" /* Array */ {
        type_node type {
            .inner_type = $1, 
            .attribute = type_attributes::array
        };
        syntax_tree_.push_back(type);
        $$ = syntax_tree_.size() - 1;
    }
    | type "*" "mutable" /* Mutable pointer */ {
        type_node type {
            .inner_type = $1, 
            .attribute = (type_attributes::pointer | type_attributes::mutable_type)
        };
        syntax_tree_.push_back(type);
        $$ = syntax_tree_.size() - 1;
    }
    | type "[" "]" "mutable" /* Mutable array */ {
        type_node type {
            .inner_type = $1, 
            .attribute = (type_attributes::array | type_attributes::mutable_type)
        };
        syntax_tree_.push_back(type);
        $$ = syntax_tree_.size() - 1;
    }
    ;
simple-type: 
      TYPE_NAME {
        literal_expression_node inner_type{
            .type = literal_type::identifier, 
            .literal = $1
        };
        syntax_tree_.push_back(inner_type);
        type_node type{
            .inner_type = syntax_tree_.size() - 1
        };
        syntax_tree_.push_back(type);
        $$ = syntax_tree_.size() - 1;
    }
    | TYPE_NAME "mutable" {
        literal_expression_node inner_type{
            .type = literal_type::identifier, 
            .literal = $1
        };
        syntax_tree_.push_back(inner_type);
        type_node type{
            .inner_type = syntax_tree_.size() - 1,
            .attribute = type_attributes::mutable_type
        };
        syntax_tree_.push_back(type);
        $$ = syntax_tree_.size() - 1;
    }
    | "typeof" "(" expression ")" {
        unary_expression_node inner_type {
            .op = unary_operator::typeof_operator, 
            .child = $3
        };
        syntax_tree_.push_back(inner_type);
        type_node type{
            .inner_type = syntax_tree_.size() - 1
        };
        syntax_tree_.push_back(type);
        $$ = syntax_tree_.size() - 1;
    }
    | "typeof" "(" expression ")" "mutable"  {
        unary_expression_node inner_type {
            .op = unary_operator::typeof_operator, 
            .child = $3
        };
         syntax_tree_.push_back(inner_type);
        type_node type{
            .inner_type = syntax_tree_.size() - 1,
            .attribute = type_attributes::mutable_type
        };
        syntax_tree_.push_back(type);
        $$ = syntax_tree_.size() - 1;
    }
    ;
function-declaration:
    "let" IDENTIFIER "(" function-parameter-list-opt ")" return-type-opt "=" compound-statement {
        function_declaration_node node {
            .name = $2, 
            .parameters = std::move($4), 
            .return_type = $6, 
            .definition = $8
        };
        syntax_tree_.push_back(std::move(node));
        $$ = syntax_tree_.size() - 1;
    } 
    ;
function-parameter-list-opt: 
      function-parameter-list {$$ = std::move($1); }
    | %empty { $$ = {}; }
    ;
function-parameter-list: 
      function-parameter {$$ = std::vector{$1}; }
    | function-parameter-list "," function-parameter { $$.push_back($3); }
    ;
function-parameter: 
      IDENTIFIER {
        function_parameter_node node {
            .name = $1, 
            .type = missing_expression, 
            .mode = function_parameter_attributes::in
        };
        syntax_tree_.push_back(node);
        $$ = syntax_tree_.size() - 1;
      }
    | IDENTIFIER ":" mode {
         function_parameter_node node {
            .name = $1, 
            .type = missing_expression, 
            .mode = $3
        };
        syntax_tree_.push_back(node);
        $$ = syntax_tree_.size() - 1;
    }
    | IDENTIFIER ":" type {
         function_parameter_node node {
            .name = $1, 
            .type = $3,
            .mode = function_parameter_attributes::in
        };
        syntax_tree_.push_back(node);
        $$ = syntax_tree_.size() - 1;
    }
    | IDENTIFIER ":" mode type {
         function_parameter_node node {
            .name = $1, 
            .type = $4,
            .mode = $3
        };
        syntax_tree_.push_back(node);
        $$ = syntax_tree_.size() - 1;
    }
    ;
mode: 
      "in" {$$ = function_parameter_attributes::in;}
    | "out"  {$$ = function_parameter_attributes::out;}
    | "in" "out" { $$ = function_parameter_attributes::in | function_parameter_attributes::out; }
    | "move" {$$ = function_parameter_attributes::move; }
    ;
return-type-opt:
      return-type { $$ = $1; }
    | %empty { $$ = missing_expression; }
    ;
return-type: "->" type  {
    $$ = $2;
};
// Statements
statements: 
      statements statement { $$.push_back($2); }
    | %empty {$$ = {}; }
    ;
statement: 
      expression ";" { $$ = $1; }
    | assignment-statement { $$ = $1; }
    | compound-statement { $$ = $1; }
    | declaration { $$ = $1 ; }
    ;
assignment-statement:
      expression "=" expression ";" {
        syntax_tree_.push_back(assignment_statement_node{.lhs=$1, .type=assignment_type::copy, .rhs=$3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "<-" expression ";" {
        syntax_tree_.push_back(assignment_statement_node{.lhs=$1, .type=assignment_type::move, .rhs=$3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "+=" expression ";" {
        syntax_tree_.push_back(assignment_statement_node{.lhs=$1, .type=assignment_type::add, .rhs=$3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "-=" expression ";" {
        syntax_tree_.push_back(assignment_statement_node{.lhs=$1, .type=assignment_type::subtract, .rhs=$3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "*=" expression ";" {
        syntax_tree_.push_back(assignment_statement_node{.lhs=$1, .type=assignment_type::multiply, .rhs=$3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "%=" expression ";" {
        syntax_tree_.push_back(assignment_statement_node{.lhs=$1, .type=assignment_type::modulo, .rhs=$3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "/=" expression ";" {
        syntax_tree_.push_back(assignment_statement_node{.lhs=$1, .type=assignment_type::divide, .rhs=$3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "//=" expression ";" {
        syntax_tree_.push_back(assignment_statement_node{.lhs=$1, .type=assignment_type::int_divide, .rhs=$3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "^=" expression ";" {
        syntax_tree_.push_back(assignment_statement_node{.lhs=$1, .type=assignment_type::exponent, .rhs=$3});
        $$ = syntax_tree_.size() - 1;
    }
    ;
compound-statement: 
    "{" statements "}" { 
        syntax_tree_.push_back(compound_statement_node{.statements = std::move($2)});
        $$ = syntax_tree_.size() - 1;
    }
    ;
// Expressions
expression: 
      primary-exression {$$ = syntax_tree_.size() - 1;}
    | binary-expression {$$ = syntax_tree_.size() - 1;}
    | unary-expression {$$ = syntax_tree_.size() - 1;}
    | absolute-value-expression {$$ = syntax_tree_.size() - 1;}
    | function-call-expression {$$ = syntax_tree_.size() - 1;}
    | array-index-expression {$$ = syntax_tree_.size() - 1;}
    ;
primary-exression: 
      literal {$$ = syntax_tree_.size() - 1;}
    | "(" expression ")" {$$ = syntax_tree_.size() - 1;}
    ;
literal: 
     CHARACTER {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::character, .literal = $1}); 
        $$ = syntax_tree_.size() - 1;
    }
   | COMPLEX {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::complex, .literal = $1}); 
        $$ = syntax_tree_.size() - 1;
    }
   | FLOAT {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::floating_point, .literal = $1}); 
        $$ = syntax_tree_.size() - 1;
    }
   | IDENTIFIER {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::identifier, .literal = $1}); 
        $$ = syntax_tree_.size() - 1;
    }
   | INTEGER {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::integer, .literal = $1}); 
        $$ = syntax_tree_.size() - 1;
    }
   | STRING  {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::string, .literal = $1}); 
        $$ = syntax_tree_.size() - 1;
    }
   | "true" {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::boolean, .literal = "true"}); 
        $$ = syntax_tree_.size() - 1;
    }
   | "false" {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::boolean, .literal = "false"}); 
        $$ = syntax_tree_.size() - 1;
    }
   | "this" {
        syntax_tree_.push_back(literal_expression_node{.type = literal_type::this_literal, .literal = "this"}); 
        $$ = syntax_tree_.size() - 1;
    }
   ;
binary-expression: 
      expression "or" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::binary_or, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "and" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::binary_and, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "==" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::equals, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "!=" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::not_equals, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "<" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::less, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "<=" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::less_equal, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression ">" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::greater, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression ">=" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::greater_equal, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "<=>" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::spaceship, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "+" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::add, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "-" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::subtract, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "*" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::multiply, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "/" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::divide, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "//" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::int_divide, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "%" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::modulo, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "^" expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::exponent, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    | expression "." expression {
        syntax_tree_.push_back(binary_expression_node{.left_child = $1, .op = binary_operator::member, .right_child = $3});
        $$ = syntax_tree_.size() - 1;
    }
    ;
unary-expression: 
      expression "!" {
        syntax_tree_.push_back(unary_expression_node{.op = unary_operator::factorial, .child = $1});
        $$ = syntax_tree_.size() - 1;
    }
    | "not" expression {
        syntax_tree_.push_back(unary_expression_node{.op = unary_operator::unary_not, .child = $2});
        $$ = syntax_tree_.size() - 1;
    }
    | "-" expression {
        syntax_tree_.push_back(unary_expression_node{.op = unary_operator::negate, .child = $2});
        $$ = syntax_tree_.size() - 1;
    }
    ;
absolute-value-expression:
    "|" expression "|" {
        syntax_tree_.push_back(unary_expression_node{.op = unary_operator::absolute_value, .child = $2});
        $$ = syntax_tree_.size() - 1;
    }
    ;
function-call-expression : 
      IDENTIFIER "(" expression-list-opt ")" {
        literal_expression_node function_expression{.type = literal_type::identifier, .literal = $1};
        syntax_tree_.push_back(function_expression);
        function_call_expression_node function_call{.function_expression = syntax_tree_.size() - 1, .parameter_keys = std::move($3)};
        syntax_tree_.push_back(std::move(function_call));
        $$ = syntax_tree_.size() - 1;
      }
    | function-call-expression "(" expression-list-opt ")" {
        function_call_expression_node function_call{.function_expression = $1, .parameter_keys = std::move($3)};
        syntax_tree_.push_back(std::move(function_call));
        $$ = syntax_tree_.size() - 1;
    }
    ;
array-index-expression: 
      IDENTIFIER "[" expression "]" {
        literal_expression_node function_expression{.type = literal_type::identifier, .literal = $1};
        syntax_tree_.push_back(function_expression);
        array_index_expression_node array_index{.array_expression = syntax_tree_.size() - 1, .index_expression = $3};
        syntax_tree_.push_back(array_index);
        $$ = syntax_tree_.size() - 1;
    }
    | function-call-expression "[" expression "]" {
        array_index_expression_node array_index{.array_expression = $1, .index_expression = $3};
        syntax_tree_.push_back(array_index);
        $$ = syntax_tree_.size() - 1;
    }
    | array-index-expression "[" expression "]" {
        array_index_expression_node array_index{.array_expression = $1, .index_expression = $3};
        syntax_tree_.push_back(array_index);
        $$ = syntax_tree_.size() - 1;
    }
    ;
// Valid ways to call functions 
// func()
// foo.func()
// foo[]()
// foo[].func()
expression-list-opt:
      expression-list { $$ = std::move($1);}
    | %empty { $$ = {}; }
    ;
expression-list: 
      expression { $$ = std::vector{$1}; }
    | expression-list "," expression { $$.push_back($3); }
    ;
%%

void fermi::parser::error(const location_type& l, const std::string& m)
{
    std::cerr << (l.begin.filename ? l.begin.filename->c_str() : "(undefined)");
    std::cerr << ':' << l.begin.line << ':' << l.begin.column << '-' << l.end.column << ": " << m << '\n';
}