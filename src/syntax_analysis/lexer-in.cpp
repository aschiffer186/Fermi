#include "lexer.hpp"
#include "location.hpp"
#include "parser.hpp"

#include <cassert>
#include <cctype>
#include <string_view>

fermi::lexer::lexer(std::string_view source)
    : source_(source), curr_(source.cbegin()) {}

void fermi::lexer::reset() {
  loc_ = parser::location_type{};
  curr_ = source_.cbegin();
}

fermi::parser::symbol_type fermi::lexer::next_token() {
  skip_to_token();
  loc_.step();
  std::string_view::const_iterator first = curr_;
  std::string_view::const_iterator marker = curr_;
  if (curr_ == source_.cend()) {
    loc_.columns(curr_ - first);
    return parser::make_YYEOF(loc_);
  }
  /*!re2c
    re2c:define:YYCTYPE = char;
    re2c:define:YYCURSOR = curr_;
    re2c:define:YYMARKER = marker;
    re2c:yyfill:enable = 0;

    [0-9]+([eE][+]?[0-9]+)? {
      loc_.columns(curr_ - first);
      return parser::make_INTEGER(std::string_view{first, curr_}, loc_);
    }

    [0-9]+([eE][-][0-9]+) {
      loc_.columns(curr_ - first);
      return parser::make_FLOAT(std::string_view{first, curr_}, loc_);
    }

    [0-9]*"."[0-9]+([eE][+-]?[0-9]+)? {
      loc_.columns(curr_ - first);
      return parser::make_FLOAT(std::string_view{first, curr_}, loc_);
    }

    "\"" [^"]* "\"" {
      loc_.columns(curr_ - first);
      return parser::make_STRING(std::string_view{first, curr_}, loc_);
    }

    "'"[^']"'" {
      loc_.columns(curr_ - first);
      return parser::make_CHARACTER(std::string_view{first, curr_}, loc_);
    }

    "and" {
      loc_.columns(curr_ - first);
      return parser::make_AND(loc_);
    }
    "as" {
      loc_.columns(curr_ - first);
      return parser::make_AS(loc_);
    }
    "bool" {
      loc_.columns(curr_ - first);
      return parser::make_BOOL(loc_);
    }
    "compeval" {
      loc_.columns(curr_ - first);
      return parser::make_COMPEVAL(loc_);
    }
    "define" {
      loc_.columns(curr_ - first);
      return parser::make_DEFINE(loc_);
    }
    "else" {
      loc_.columns(curr_ - first);
      return parser::make_ELSE(loc_);
    }
    "elsif" {
      loc_.columns(curr_ - first);
      return parser::make_ELSIF(loc_);
    }
    "export" {
      loc_.columns(curr_ - first);
      return parser::make_EXPORT(loc_);
    }
    "false" {
      loc_.columns(curr_ - first);
      return parser::make_FALSE(loc_);
    }
    "in" {
      loc_.columns(curr_ - first);
      return parser::make_IN(loc_);
    }
    "let" {
      loc_.columns(curr_ - first);
      return parser::make_LET(loc_);
    }
    "move" {
      loc_.columns(curr_ - first);
      return parser::make_MOVE(loc_);
    }
    "mutable" {
      loc_.columns(curr_ - first);
      return parser::make_MUTABLE(loc_);
    }
    "not" {
      loc_.columns(curr_ - first);
      return parser::make_NOT(loc_);
    }
    "out" {
      loc_.columns(curr_ - first);
      return parser::make_OUT(loc_);
    }
    "or" {
      loc_.columns(curr_ - first);
      return parser::make_OR(loc_);
    }
    "this" {
      loc_.columns(curr_ - first);
      return parser::make_THIS(loc_);
    }
    "true" {
      loc_.columns(curr_ - first);
      return parser::make_TRUE(loc_);
    }

    [a-zA-Z_][a-zA-Z0-9]* {
      loc_.columns(curr_ - first);
      if (!lex_as_typename_) {
        return parser::make_IDENTIFIER(std::string_view{first, curr_}, loc_);
      } else {
        lex_as_typename_ = false;
        return parser::make_TYPE_NAME(std::string_view{first, curr_}, loc_);
      }
    }

    "&" {
      loc_.columns(curr_ - first);
      return parser::make_AMPERSAND(loc_);
    }
    "*" {
      loc_.columns(curr_ - first);
      return parser::make_STAR(loc_);
    }
    "[" {
      loc_.columns(curr_ - first);
      return parser::make_LEFT_BRACKET(loc_);
     }
    "]" {
      loc_.columns(curr_ - first);
      return parser::make_RIGHT_BRACKET(loc_);
    }
    ")" {
      loc_.columns(curr_ - first);
      return parser::make_RIGHT_PARENTHESIS(loc_);
    }
    "(" {
      loc_.columns(curr_ - first);
      return parser::make_LEFT_PARENTHESIS(loc_);
    }
    "=" {
      loc_.columns(curr_ - first);
      return parser::make_ASSIGN(loc_);
    }
    "," {
      loc_.columns(curr_ - first);
      return parser::make_COMMA(loc_);
    }
    ":" {
      loc_.columns(curr_ - first);
      return parser::make_COLON(loc_);
    }
    "->" {
      loc_.columns(curr_ - first);
      return parser::make_RIGHT_ARROW(loc_);
    }
    ";" {
      loc_.columns(curr_ - first);
      return parser::make_SEMICOLON(loc_);
    }
    "<-" {
      loc_.columns(curr_ - first);
      return parser::make_LEFT_ARROW(loc_);
    }
    "+=" {
      loc_.columns(curr_ - first);
      return parser::make_PLUS_EQUAL(loc_);
    }
    "-=" {
      loc_.columns(curr_ - first);
      return parser::make_MINUS_EQUAL(loc_);
    }
    "*=" {
      loc_.columns(curr_ - first);
      return parser::make_STAR_EQUAL(loc_);
    }
    "/=" {
      loc_.columns(curr_ - first);
      return parser::make_SLASH_EQUAL(loc_);
    }
    "//=" {
      loc_.columns(curr_ - first);
      return parser::make_SLASH_SLASH_EQUAL(loc_);
    }
    "%=" {
      loc_.columns(curr_ - first);
      return parser::make_PERCENT_EQUAL(loc_);
    }
    "^=" {
      loc_.columns(curr_ - first);
      return parser::make_CARET_EQUAL(loc_);
    }
    "{" {
      loc_.columns(curr_ - first);
      return parser::make_LEFT_BRACE(loc_);
    }
    "}" {
      loc_.columns(curr_ - first);
      return parser::make_RIGHT_BRACE(loc_);
    }
    "==" {
      loc_.columns(curr_ - first);
      return parser::make_EQUAL_EQUAL(loc_);
    }
    "!=" {
      loc_.columns(curr_ - first);
      return parser::make_BANG_EQUAL(loc_);
    }
    "<" {
      loc_.columns(curr_ - first);
      return parser::make_LESS(loc_);
    }
    "<=" {
      loc_.columns(curr_ - first);
      return parser::make_LESS_EQUAL(loc_);
    }
    ">" {
      loc_.columns(curr_ - first);
      return parser::make_GREATER(loc_);
    }
    ">=" {
      loc_.columns(curr_ - first);
      return parser::make_GREATER_EQUAL(loc_);
    }
    "<=>" {
      loc_.columns(curr_ - first);
      return parser::make_SPACESHIP(loc_);
    }
    "+" {
      loc_.columns(curr_ - first);
      return parser::make_PLUS(loc_);
    }
    "-" {
      loc_.columns(curr_ - first);
      return parser::make_MINUS(loc_);
    }
    "/" {
      loc_.columns(curr_ - first);
      return parser::make_SLASH(loc_);
    }
    "//" {
      loc_.columns(curr_ - first);
      return parser::make_SLASH_SLASH(loc_);
    }
    "%" {
      loc_.columns(curr_ - first);
      return parser::make_PERCENT(loc_);
    }
    "^" {
      loc_.columns(curr_ - first);
      return parser::make_CARET(loc_);
    }
    "." {
      loc_.columns(curr_ - first);
      return parser::make_DOT(loc_);
    }
    "!" {
      loc_.columns(curr_ - first);
      return parser::make_BANG(loc_);
    }
    "|" {
      loc_.columns(curr_ - first);
      return parser::make_PIPE(loc_);
    }

    * {
      loc_.columns(curr_ - first);
      return parser::make_YYerror(loc_);
    }
  */
}

void fermi::lexer::skip_to_token() {
  while (curr_ != source_.cend() && std::isspace(*curr_)) {
    loc_.step();
    if (*curr_ == '\n') {
      loc_.lines(1);
    }
    ++curr_;
  }

  if (curr_ == source_.cend()) {
    return;
  }

  if (*curr_ == '#') {
    while (curr_ != source_.cend() && *curr_ != '\n') {
      loc_.step();
      ++curr_;
    }
    if (curr_ != source_.cend()) {
      loc_.step();
      loc_.lines(1);
      ++curr_;
    }
    skip_to_token();
  }
}

std::ostream& fermi::operator<<(std::ostream& os,
                                const parser::symbol_type& symbol) {
  os << "{Type: " << symbol.name() << ", value: ";
  const auto& value = symbol.value;
  const auto token_type = symbol.kind();

  if (token_type == parser::symbol_kind_type::S_CHARACTER ||
      token_type == parser::symbol_kind_type::S_COMPLEX ||
      token_type == parser::symbol_kind_type::S_FLOAT ||
      token_type == parser::symbol_kind_type::S_IDENTIFIER ||
      token_type == parser::symbol_kind_type::S_INTEGER ||
      token_type == parser::symbol_kind_type::S_STRING ||
      token_type == parser::symbol_kind_type::S_TYPE_NAME) {
    os << value.as<std::string_view>() << ", ";
  } else {
    os << symbol.name() << ", ";
  }
  os << "Start Column: " << symbol.location.begin.column << ", ";
  os << "End Column: " << symbol.location.end.column << ", ";
  os << "Line: " << symbol.location.begin.line << "}";
  return os;
}