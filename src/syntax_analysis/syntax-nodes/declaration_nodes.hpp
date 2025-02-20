#ifndef DECLARATION_NODES_HPP
#define DECLARATION_NODES_HPP

#include <cstddef>
#include <cstdint>
#include <limits>
#include <string_view>
#include <vector>

namespace fermi::syntax_nodes {
constexpr std::size_t missing_expression{
    std::numeric_limits<std::size_t>::max()};

struct variable_declaration_node {
  std::string_view name;
  std::size_t type;
  std::size_t initializer;
};

namespace type_attributes {
enum attribute : std::uint8_t {
  none = 0,
  pointer = 1,
  reference = 1 << 1,
  array = 1 << 2,
  mutable_type = 1 << 3
};

constexpr attribute& operator&=(attribute& lhs, attribute rhs) noexcept {
  lhs = static_cast<attribute>(static_cast<int>(lhs) & static_cast<int>(rhs));
  return lhs;
}

constexpr attribute& operator|=(attribute& lhs, attribute rhs) noexcept {
  lhs = static_cast<attribute>(static_cast<int>(lhs) | static_cast<int>(rhs));
  return lhs;
}

constexpr attribute operator&(attribute lhs, attribute rhs) noexcept {
  return lhs &= rhs;
}

constexpr attribute operator|(attribute lhs, attribute rhs) noexcept {
  return lhs |= rhs;
}
} // namespace type_attributes

struct type_node {
  std::size_t inner_type;
  type_attributes::attribute attribute = type_attributes::none;
};

namespace function_parameter_attributes {
enum attribute : std::uint8_t { none = 0, in = 1, out = 1 << 1, move = 1 << 2 };

constexpr attribute& operator&=(attribute& lhs, attribute rhs) noexcept {
  lhs = static_cast<attribute>(static_cast<int>(lhs) & static_cast<int>(rhs));
  return lhs;
}

constexpr attribute& operator|=(attribute& lhs, attribute rhs) noexcept {
  lhs = static_cast<attribute>(static_cast<int>(lhs) | static_cast<int>(rhs));
  return lhs;
}

constexpr attribute operator&(attribute lhs, attribute rhs) noexcept {
  return lhs &= rhs;
}

constexpr attribute operator|(attribute lhs, attribute rhs) noexcept {
  return lhs |= rhs;
}
} // namespace function_parameter_attributes

struct function_parameter_node {
  std::string_view name;
  std::size_t type;
  function_parameter_attributes::attribute mode;
};

struct function_declaration_node {
  std::string_view name;
  std::vector<std::size_t> parameters;
  std::size_t return_type;
  std::size_t definition;
};
} // namespace fermi::syntax_nodes

#endif