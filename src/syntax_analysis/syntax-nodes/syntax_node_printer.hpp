#ifndef SYNTAX_NODE_PRINTER_HPP
#define SYNTAX_NODE_PRINTER_HPP

#include <string>
#include <vector>

#include "syntax_node.hpp"
namespace fermi::syntax_nodes {
std::string to_string(const std::vector<syntax_node>& syntax_tree);
} // namespace fermi::syntax_nodes

#endif