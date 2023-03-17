#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <charconv>
#include <cmath>
#include <limits>
#include <unordered_map>

#include "ASTNode.hpp"
#include "ExpressionNode.hpp"
#include "StatementNodes.hpp"
#include "SyntaxNode.hpp"
#include "Type.hpp"

namespace Fermi::SemanticAnalysis
{
    std::unordered_map<std::string, Type> symbolTable;

    std::unique_ptr<ExpressionASTNode> makeASTNode(const SyntaxAnalysis::LiteralNode* node)
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
                    return std::make_unique<LiteralASTNode>(Type{1, "int8_t"}, value);
                }
                else if (std::abs(val) <= std::numeric_limits<int16_t>::max())
                {
                    return std::make_unique<LiteralASTNode>(Type{2, "int16_t"}, value);
                }
                else if (std::abs(val) <= std::numeric_limits<int32_t>::max())
                {
                    return std::make_unique<LiteralASTNode>(Type{4, "int32_t"}, value);
                }
                else
                {
                    return std::make_unique<LiteralASTNode>(Type{8, "int64_t"}, value);
                }
            }
            case SyntaxAnalysis::LiteralType::Float:
            {
                std::string_view value = node->getValue();
                double val;
                auto [ptr, ec] = std::from_chars(value.data(), value.data() + value.size(), val);

                if (ec == std::errc::result_out_of_range)
                {
                    return std::make_unique<LiteralASTNode>(Type{8, "float64_t"}, "inf");
                }

                if (std::abs(val) <= std::numeric_limits<float>::max())
                {
                    return std::make_unique<LiteralASTNode>(Type{4, "float32_t"}, value);
                }
                else 
                {
                    return std::make_unique<LiteralASTNode>(Type{8, "float64_t"}, value);
                }
            }
            case SyntaxAnalysis::LiteralType::Identifier:
            {
                const std::string& identifier = node->getValue();
                if (auto it = symbolTable.find(identifier); it != symbolTable.end())
                {
                    auto type = it->second;
                    return std::make_unique<IdentifierASTNode>(identifier, type);
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

    std::unique_ptr<ExpressionASTNode> makeASTNode(const SyntaxAnalysis::BinaryExpressionNode* node)
    {
        const auto& children = node->getChildren();
        const SyntaxAnalysis::SyntaxNode* lhs = children[0];
        const SyntaxAnalysis::SyntaxNode* rhs = children[1];

        std::unique_ptr<ExpressionASTNode> lhsASTNode;
        switch (lhs->getNodeType())
        {
            case SyntaxAnalysis::SyntaxNodeType::Literal:
                lhsASTNode = makeASTNode(static_cast<const SyntaxAnalysis::LiteralNode*>(lhs));
                break;
            default:
                return nullptr;
        }

        std::unique_ptr<ExpressionASTNode> rhsASTNode;
        switch (rhs->getNodeType())
        {
            case SyntaxAnalysis::SyntaxNodeType::Literal:
                lhsASTNode = makeASTNode(static_cast<const SyntaxAnalysis::LiteralNode*>(lhs));
                break;
            default:
                return nullptr; 
        }

        Type commonType = getCommonType(lhsASTNode->getOutputEntityType(), rhsASTNode->getOutputEntityType());

        switch (node->getOperator())
        {
        case SyntaxAnalysis::BinaryExpressionTypes::Addition:
            {
                auto leftChild = std::move(lhsASTNode);
                auto rightChild = std::move(rhsASTNode);
                if (lhsASTNode->getOutputEntityType() != commonType)
                {
                    leftChild = std::make_unique<ExpressionASTNode>(std::move(leftChild), commonType);
                }

                if (rhsASTNode->getOutputEntityType() != commonType)
                {
                    rightChild = std::make_unique<ExpressionASTNode>(std::move(rightChild), commonType);
                }

                return std::make_unique<BinaryExpressionASTNode>(std::move(leftChild), BinaryExpressionOperator::Addition, std::move(rightChild));
            }
        case SyntaxAnalysis::BinaryExpressionTypes::Subtraction:
            {
                auto leftChild = std::move(lhsASTNode);
                auto rightChild = std::move(rhsASTNode);
                if (lhsASTNode->getOutputEntityType() != commonType)
                {
                    leftChild = std::make_unique<ExpressionASTNode>(std::move(leftChild), commonType);
                }

                if (rhsASTNode->getOutputEntityType() != commonType)
                {
                    rightChild = std::make_unique<ExpressionASTNode>(std::move(rightChild), commonType);
                }

                return std::make_unique<BinaryExpressionASTNode>(std::move(leftChild), BinaryExpressionOperator::Subtraction, std::move(rightChild));
            }
        case SyntaxAnalysis::BinaryExpressionTypes::Multiplication:
            {
                auto leftChild = std::move(lhsASTNode);
                auto rightChild = std::move(rhsASTNode);
                if (lhsASTNode->getOutputEntityType() != commonType)
                {
                    leftChild = std::make_unique<ExpressionASTNode>(std::move(leftChild), commonType);
                }

                if (rhsASTNode->getOutputEntityType() != commonType)
                {
                    rightChild = std::make_unique<ExpressionASTNode>(std::move(rightChild), commonType);
                }

                return std::make_unique<BinaryExpressionASTNode>(std::move(leftChild), BinaryExpressionOperator::Addition, std::move(rightChild));
            }
        case SyntaxAnalysis::BinaryExpressionTypes::Division:
            {
                auto leftChild = std::move(lhsASTNode);
                auto rightChild = std::move(rhsASTNode);

                if (isFloatingPointType(leftChild->getOutputEntityType()) && 
                    isFloatingPointType(rightChild->getOutputEntityType()))
                {
                    
                }
            }
        }
    }

    std::unique_ptr<ASTNode> makeAST(std::shared_ptr<SyntaxAnalysis::FermiNode> syntaxTree)
    {
        auto root = std::make_unique<FermiASTNode>();

        for(const auto* child : syntaxTree->getChildren())
        {
            
        }   
    }
}

#endif