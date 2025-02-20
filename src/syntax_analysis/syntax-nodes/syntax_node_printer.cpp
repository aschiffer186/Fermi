#include "syntax_node_printer.hpp"

#include <array>
#include <cassert>
#include <string_view>
#include <type_traits>
#include <variant>

#include "expression_nodes.hpp"

namespace fermi::syntax_nodes {
namespace {
constexpr std::string_view tee = "├──";
constexpr std::string_view corner = "└──";
constexpr std::string_view pipe = "|";
const std::string space = "  ";

std::string to_string(const syntax_node& node,
                      const std::vector<syntax_node>& syntax_tree,
                      std::string indent, bool is_last) {
  return std::visit(
      [&syntax_tree, &indent, is_last](const auto& arg) {
        return to_string(arg, syntax_tree, indent, is_last);
      },
      node);
}

std::string to_string(const binary_expression_node& node,
                      const std::vector<syntax_node>& syntax_tree,
                      std::string indent, bool is_last) {
  assert(node.op != binary_operator::last &&
         "Impossible binary operator type in to_string");

  constexpr std::array binary_operator_names{
      "add",        "or",      "and",           "divide",     "equals",
      "exponent",   "greater", "greater_equal", "int_divide", "less",
      "less_equal", "member",  "multiply",      "modulo",     "not_equals",
      "spaceship",  "subtract"};
  static_assert(binary_operator_names.size() ==
                static_cast<std::size_t>(binary_operator::last));

  const std::string_view token_marker = (is_last) ? corner : tee;
  std::string rep;
  rep.append(indent).append(token_marker);
  rep.append("Binary Expression");
  (is_last) ? indent.append(space) : indent.append(pipe).append(space);
  rep.append("\n");

  const std::size_t left_child = node.left_child;
  rep.append(to_string(syntax_tree[left_child], syntax_tree, indent, false));
  rep.append("\n");

  rep.append(tee)
      .append("Operator: ")
      .append(binary_operator_names[static_cast<int>(node.op)]);
  rep.append("\n");

  const std::size_t right_child = node.right_child;
  rep.append(to_string(syntax_tree[right_child], syntax_tree, indent, true));

  return rep;
}

std::string to_string(const unary_expression_node& node,
                      const std::vector<syntax_node>& syntax_tree,
                      std::string indent, bool is_last) {
  assert(node.op != unary_operator::last &&
         "Impossible binary operator type in to_string");

  constexpr std::array unary_operator_names{
      "absolute_value", "factorial", "negate", "unary_not", "typeof_operator"};
  static_assert(unary_operator_names.size() ==
                static_cast<std::size_t>(unary_operator::last));

  const std::string_view token_marker = (is_last) ? corner : tee;
  std::string rep;
  rep.append(indent).append(token_marker);
  rep.append("Unary Expression");
  (is_last) ? indent.append(space) : indent.append(pipe).append(space);
  rep.append("\n");

  rep.append(tee)
      .append("Operator: ")
      .append(unary_operator_names[static_cast<int>(node.op)]);
  rep.append("\n");

  const std::size_t child = node.child;
  rep.append(to_string(syntax_tree[child], syntax_tree, indent, true));

  return rep;
}

std::string to_string(const literal_expression_node& node,
                      const std::vector<syntax_node>& /*syntax_tree*/,
                      std::string indent, bool is_last) {

  assert(node.type != literal_type::last &&
         "Impossible literal type in to_string");
  static constexpr std::array literal_type_names{
      "boolean",    "character", "complex", "floating_point",
      "identifier", "integer",   "string",  "this"};
  static_assert(literal_type_names.size() ==
                static_cast<std::size_t>(literal_type::last));

  const std::string_view token_marker = (is_last) ? corner : tee;
  std::string rep = indent;
  rep.append(token_marker);
  rep.append("Literal Expression");
  (is_last) ? indent.append(space) : indent.append(pipe).append(space);
  rep.append("\n");
  rep.append(tee).append("value: ").append(node.literal);
  rep.append("\n");
  rep.append(corner);
  rep.append(literal_type_names[static_cast<int>(node.type)]);

  return rep;
}
} // namespace
} // namespace fermi::syntax_nodes
std::string
fermi::syntax_nodes::to_string(const std::vector<syntax_node>& syntax_tree) {
  if (syntax_tree.empty()) {
    return "";
  }

  return to_string(syntax_tree.back(), syntax_tree, "", true);
}