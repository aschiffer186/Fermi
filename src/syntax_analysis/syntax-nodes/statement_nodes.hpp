#ifndef STATEMENT_NODES_HPP
#define STATEMENT_NODES_HPP

#include <cstddef>
#include <vector>
namespace fermi::syntax_nodes {
enum class assignment_type {
  copy,
  move,
  add,
  subtract,
  multiply,
  divide,
  int_divide,
  modulo,
  exponent
};

struct assignment_statement_node {
  std::size_t lhs;
  assignment_type type;
  std::size_t rhs;
};

struct compound_statement_node {
  std::vector<std::size_t> statements;
};
} // namespace fermi::syntax_nodes

#endif