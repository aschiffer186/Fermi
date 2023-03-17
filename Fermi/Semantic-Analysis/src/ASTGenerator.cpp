#include <limits>

#include "Syntax-Tree/ExpressionNode.hpp"
#include "Syntax-Tree/StatementNode.hpp"

#include "ASTGenerator.hpp"
#include "ASTNodes/StatementNodes.hpp"

namespace Fermi::SemanticAnalysis
{
    ASTGenerator::ASTGenerator(const SyntaxAnalysis::FermiNode& node, std::unordered_map<std::string, Type>& symbolTable)
    : tree_{std::make_unique<FermiASTNode>(symbolTable)}, symbolTable_{symbolTable}
    {
        node.accept(this);
    }

    std::unique_ptr<ASTNode> makeAST(const SyntaxAnalysis::FermiNode& node)
    {
        
    }

    void ASTGenerator::visit(const SyntaxAnalysis::FermiNode* node)
    {
        for(const auto* child : node->getChildren())
            child->accept(this);
    }

    void ASTGenerator::visit(const SyntaxAnalysis::LiteralNode* node)
    {
        SyntaxAnalysis::LiteralType literalType = node->getType();
        const std::string& valueStr = node->getValue();
        switch (literalType)
        {
        case SyntaxAnalysis::LiteralType::Integer:
            {
                int64_t valueInt = std::stoll(valueStr);

                if (valueInt >= std::numeric_limits<int8_t>::min() && valueInt <= std::numeric_limits<int8_t>::max())
                    tree_->addChild(std::make_unique<LiteralASTNode>(Fermi_int8_t, valueStr));
                else if(valueInt >= std::numeric_limits<int16_t>::min() && valueInt <= std::numeric_limits<int16_t>::max())
                    tree_->addChild(std::make_unique<LiteralASTNode>(Fermi_int16_t, valueStr));
                else if(valueInt >= std::numeric_limits<int32_t>::min() && valueInt <= std::numeric_limits<int32_t>::max())
                    tree_->addChild(std::make_unique<LiteralASTNode>(Fermi_int32_t, valueStr));
                else if(valueInt >= std::numeric_limits<int64_t>::min() && valueInt <= std::numeric_limits<int64_t>::max())
                    tree_->addChild(std::make_unique<LiteralASTNode>(Fermi_int64_t, valueStr));
            }
            break;
        case SyntaxAnalysis::LiteralType::Float:
            {
                long double valueFloat = std::stold(valueStr);

                if (std::abs(valueFloat) <= std::numeric_limits<float>::max())
                    tree_->addChild(std::make_unique<LiteralASTNode>(Fermi_float32_t, valueStr));
                else if (std::abs(valueFloat) <= std::numeric_limits<double>::max())
                    tree_->addChild(std::make_unique<LiteralASTNode>(Fermi_float64_t, valueStr));
            }
            break;
        case SyntaxAnalysis::LiteralType::Identifier:
            {
                if(auto it = symbolTable_.find(valueStr); it != symbolTable_.end())
                    tree_->addChild(std::make_unique<IdentifierASTNode>(valueStr, it->second));
            }
        }
    }

    void ASTGenerator::visit(const SyntaxAnalysis::BinaryExpressionNode* node)
    {
        std::vector children{node->getChildren()};
        std::unique_ptr<ExpressionASTNode> lhs;
        std::unique_ptr<ExpressionASTNode> rhs;

        const auto* lhsChild = children[0];
        const auto& rhsChild = children[0];

        

    }

    std::unique_ptr<FermiASTNode> ASTGenerator::getTree()
    {
        return std::move(tree_);
    }
}