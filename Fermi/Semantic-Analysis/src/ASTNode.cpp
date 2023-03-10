#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <charconv>
#include <cmath>
#include <limits>
#include <unordered_map>

#include "ASTNode.hpp"
#include "ExpressionNode.hpp"
#include "StatementNodes.hpp"
#include "Type.hpp"

namespace Fermi::SemanticAnalysis
{
    std::unordered_map<std::string, Type> symbolTable;

    std::unique_ptr<ASTNode> makeLiteralNode(const SyntaxAnalysis::LiteralNode* node)
    {
        auto type = node->getType();
        switch(type)
        {
            case SyntaxAnalysis::LiteralType::Integer:
            {
                std::string_view value = node->getValue();
                int64_t val;
                auto [ptr, ec] = std::from_chars(value.data(), value.data() + value.size(), val);

                if (ec == std::errc::result_out_of_range)
                {
                    // Compiler-erro
                }

                if (std::abs(val) <= std::numeric_limits<int8_t>::max())
                {
                    return std::make_unique<LiteralNode>(Type{1, "int8_t"}, value);
                }
                else if (std::abs(val) <= std::numeric_limits<int16_t>::max())
                {
                    return std::make_unique<LiteralNode>(Type{2, "int16_t"}, value);
                }
                else if (std::abs(val) <= std::numeric_limits<int32_t>::max())
                {
                    return std::make_unique<LiteralNode>(Type{4, "int32_t"}, value);
                }
                else
                {
                    return std::make_unique<LiteralNode>(Type{8, "int64_t"}, value);
                }
            }
            case SyntaxAnalysis::LiteralType::Float:
            {
                std::string_view value = node->getValue();
                double val;
                auto [ptr, ec] = std::from_chars(value.data(), value.data() + value.size(), val);

                if (ec == std::errc::result_out_of_range)
                {
                    return std::make_unique<LiteralNode>(Type{8, "float64_t"}, "inf");
                }

                if (std::abs(val) <= std::numeric_limits<float>::max())
                {
                    return std::make_unique<LiteralNode>(Type{4, "float32_t"}, value);
                }
                else 
                {
                    return std::make_unique<LiteralNode>(Type{8, "float64_t"}, value);
                }
            }
            case SyntaxAnalysis::LiteralType::Identifier:
            {
                const std::string& identifier = node->getValue();
                if (auto it = symbolTable.find(identifier); it != symbolTable.end())
                {
                    auto type = it->second;
                    return std::make_unique<IdentifierNode>(identifier, type);
                }
                else 
                {
                    // Handle error
                    break;
                }
            }
        }
        return nullptr;
    }

    std::unique_ptr<ASTNode> makeAST(std::shared_ptr<SyntaxAnalysis::FermiNode> syntaxTree)
    {
        auto root = std::make_unique<FermiNode>();

        for(const auto* child : syntaxTree->getChildren())
        {

        }   
    }
}

#endif