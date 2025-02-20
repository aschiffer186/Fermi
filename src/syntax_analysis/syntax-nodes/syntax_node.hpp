#include <variant>

#include "declaration_nodes.hpp"
#include "expression_nodes.hpp"
#include "statement_nodes.hpp"

namespace fermi::syntax_nodes {
using syntax_node =
    std::variant<array_index_expression_node, assignment_statement_node,
                 binary_expression_node, compound_statement_node,
                 variable_declaration_node, function_call_expression_node,
                 function_declaration_node, function_parameter_node,
                 literal_expression_node, type_node, unary_expression_node>;
}