#ifndef EXPRESSION_NODES
#define EXPRESSION_NODES

#include <cstddef>
#include <cstdint>
#include <string_view>
#include <vector>

namespace fermi::syntax_nodes {
enum class binary_operator : std::uint8_t {
  add,
  binary_or,
  binary_and,
  divide,
  equals,
  exponent,
  greater,
  greater_equal,
  int_divide,
  less,
  less_equal,
  member,
  multiply,
  modulo,
  not_equals,
  spaceship,
  subtract,
  last,
};

struct binary_expression_node {
  std::size_t left_child;
  binary_operator op;
  std::size_t right_child;
};

enum class unary_operator : std::uint8_t {
  absolute_value,
  factorial,
  negate,
  unary_not,
  typeof_operator,
  last,
};

struct unary_expression_node {
  unary_operator op;
  std::size_t child;
};

enum class literal_type : std::uint8_t {
  boolean,
  character,
  complex,
  floating_point,
  identifier,
  integer,
  string,
  this_literal,
  last,
};

struct literal_expression_node {
  literal_type type;
  std::string_view literal;
};

struct function_call_expression_node {
  std::size_t function_expression;
  std::vector<std::size_t> parameter_keys;
};

struct array_index_expression_node {
  std::size_t array_expression;
  std::size_t index_expression;
};
} // namespace fermi::syntax_nodes

#endif