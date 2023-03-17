#include <limits>

#include "Syntax-Tree/ExpressionNode.hpp"
#include "Syntax-Tree/StatementNode.hpp"
#include "Syntax-Tree/SyntaxNode.hpp"

#include "ASTGenerator.hpp"
#include "ASTNode.hpp"
#include "FermiModule.hpp"
#include "StatementNodes.hpp"

namespace Fermi::SemanticAnalysis
{
    using SyntaxNodeType = SyntaxAnalysis::SyntaxNodeType;

    std::unique_ptr<ExpressionASTNode> makeASTNode(const SyntaxAnalysis::LiteralNode* node)
    {
        SyntaxAnalysis::LiteralType type = node->getType();

        switch (type)
        {
        case SyntaxAnalysis::LiteralType::Float:
            {
                const std::string& valueStr = node->getValue();
                long double value = std::stold(valueStr);
                if (std::abs(value) <= std::numeric_limits<float>::max())
                    return std::make_unique<ExpressionASTNode>(Fermi_float32_t, valueStr);
                if (std::abs(value) <= std::numeric_limits<double>::max())
                    return std::make_unique<ExpressionASTNode>(Fermi_float64_t, valueStr);
                break;
            }
        case SyntaxAnalysis::LiteralType::Integer:
            {
                const std::string& valueStr = node->getValue();
                int64_t value = std::stoll(valueStr);
                if (std::abs(value) <= std::numeric_limits<int8_t>::max())
                    return std::make_unique<ExpressionASTNode>(Fermi_int8_t, valueStr);
                if (std::abs(value) <= std::numeric_limits<int16_t>::max())
                    return std::make_unique<ExpressionASTNode>(Fermi_int16_t, valueStr);
                if (std::abs(value) <= std::numeric_limits<int32_t>::max())
                    return std::make_unique<ExpressionASTNode>(Fermi_int32_t, valueStr);
                if (std::abs(value) <= std::numeric_limits<int64_t>::max())
                    return std::make_unique<ExpressionASTNode>(Fermi_int64_t, valueStr);
            }
        }
        
        return nullptr;
    }

    std::unique_ptr<ExpressionASTNode> makeASTNode(const SyntaxAnalysis::BinaryExpressionNode* node)
    {
        std::vector children{node->getChildren()};
    }

    std::unique_ptr<FermiASTNode> makeAST(const SyntaxAnalysis::FermiNode& node)
    {
        std::unique_ptr<FermiASTNode> tree = std::make_unique<FermiASTNode>();
        for(const auto* child : node.getChildren())
        {
            switch(child->getNodeType())
            {
            case SyntaxNodeType::Literal:
                tree->addChild()
            }
        }
    }

    FermiModule::FermiModule(std::string_view moduleName, const SyntaxAnalysis::FermiNode& syntaxTree)
    : ASTRoot_{std::make_unique<FermiASTNode>()}, moduleName_{moduleName}, symbolTable_{}
    {
       
    }
}