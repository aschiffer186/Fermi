/** @file ASTGenerator.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ASTGenerator.hpp"

#include <cstdint>
#include <cassert>
#include <limits>
#include <stdexcept>

#include "Syntax-Tree/ExpressionNodes.hpp"
#include "Syntax-Tree/StatementNodes.hpp"

#include "ASTNodes/ExpressionASTNode.hpp"
#include "ASTNodes/StatementASTNode.hpp"
#include "Syntax-Tree/SyntaxNode.hpp"
#include "Type.hpp"

#if defined(__cpp_lib_unreachable) && __cpp_lib_unreachable >= 202202L
#define FERMI_UNREACHABLE std::unreachable()
#else 
#define FERMI_UNREACHABLE std::terminate()
#endif

namespace Fermi::SemanticAnalysis
{
    struct string_hash
    {
        using hash_type = std::hash<std::string_view>;
        using is_transparent = void;
    
        std::size_t operator()(const char* str) const        { return hash_type{}(str); }
        std::size_t operator()(std::string_view str) const   { return hash_type{}(str); }
        std::size_t operator()(std::string const& str) const { return hash_type{}(str); }
    };
    
    std::unordered_map<std::string, FermiType, string_hash, std::equal_to<>> symbolTable;

    std::unique_ptr<ExpressionASTNode> transform(const SyntaxAnalysis::LiteralExpressionNode& node)
    {
        SyntaxAnalysis::LiteralType type = node.getType();
        const std::string& valueStr = node.getValue();

        switch(type)
        {
        case SyntaxAnalysis::LiteralType::Float: 
            {
                try 
                {
                    double value = std::stod(valueStr);
                    if (std::abs(value) < std::numeric_limits<float>::max())
                        return std::make_unique<LiteralExpressionASTNode>(valueStr, Fermi_float32_t);
                    else 
                        return std::make_unique<LiteralExpressionASTNode>(valueStr, Fermi_float64_t);
                } 
                catch (const std::out_of_range& ex) 
                {
                    //Useful error message
                    throw 1;
                }
            }
            break;
        case SyntaxAnalysis::LiteralType::Integer: 
            {
                try 
                {
                    std::int64_t value = std::stoll(valueStr);
                    if (std::abs(value) < std::numeric_limits<std::int8_t>::max())
                        return std::make_unique<LiteralExpressionASTNode>(valueStr, Fermi_int8_t);
                    if (std::abs(value) < std::numeric_limits<std::int16_t>::max())
                        return std::make_unique<LiteralExpressionASTNode>(valueStr, Fermi_int16_t); 
                    if (std::abs(value) < std::numeric_limits<int32_t>::max())
                        return std::make_unique<LiteralExpressionASTNode>(valueStr, Fermi_int32_t);
                    return std::make_unique<LiteralExpressionASTNode>(valueStr, Fermi_int64_t); 
                } 
                catch (const std::out_of_range& ex)
                {
                    //Useful error message
                    throw 1;
                }
            }
            break;
        case SyntaxAnalysis::LiteralType::Identifier:
            if (auto it = symbolTable.find(valueStr); it != symbolTable.end())
            {
                return std::make_unique<IdentifierExpressionASTNode>(valueStr, it->second);
            }
            else 
            {
                throw 1;
            }
        }
    }

    std::unique_ptr<ExpressionASTNode> transform(const SyntaxAnalysis::BinaryExpressionNode& node)
    {
        const auto* lhsExpr = node.getChildren()[0];
        const auto* rhsExpr = node.getChildren()[0];

        std::unique_ptr<ExpressionASTNode> lhsChild;
        std::unique_ptr<ExpressionASTNode> rhsChild;

        if (lhsExpr->getNodeType() == SyntaxAnalysis::SyntaxNodeType::Literal)
        {
            lhsChild = transform(static_cast<const SyntaxAnalysis::LiteralExpressionNode&>(*lhsExpr));
        }
        else if (lhsExpr->getNodeType() == SyntaxAnalysis::SyntaxNodeType::BinaryExpression)
        {
            lhsChild = transform(static_cast<const SyntaxAnalysis::BinaryExpressionNode&>(*lhsExpr));
        }

        if (rhsExpr->getNodeType() == SyntaxAnalysis::SyntaxNodeType::Literal)
        {
            rhsChild = transform(static_cast<const SyntaxAnalysis::LiteralExpressionNode&>(*rhsExpr));
        }
        else if (rhsExpr->getNodeType() == SyntaxAnalysis::SyntaxNodeType::BinaryExpression)
        {
            rhsChild = transform(static_cast<const SyntaxAnalysis::BinaryExpressionNode&>(*rhsExpr));
        }

        FermiType childCommonType = commonType(lhsChild->getType(), rhsChild->getType());

        if (lhsChild->getType() != childCommonType)
        {
            lhsChild = std::make_unique<TypeConversionASTNode>(std::move(lhsChild), childCommonType);
        }

        if (rhsChild->getType() != childCommonType)
        {
            rhsChild = std::make_unique<TypeConversionASTNode>(std::move(rhsChild), childCommonType);
        }

        BinaryOperatorType op;
        switch(node.getOperator())
        {
        case SyntaxAnalysis::BinaryExpressionOperators::Addition:
            op = BinaryOperatorType::Addition;
            break;
        case SyntaxAnalysis::BinaryExpressionOperators::Subtraction:
            op = BinaryOperatorType::Subtraction;
            break;
        case SyntaxAnalysis::BinaryExpressionOperators::Multiplication:
            op = BinaryOperatorType::Multiplication;
            break;
        case SyntaxAnalysis::BinaryExpressionOperators::Division:
            op = BinaryOperatorType::Division;
            break;
        case SyntaxAnalysis::BinaryExpressionOperators::IntegerDivision:
            op = BinaryOperatorType::IntegerDivision;
            break;
        case SyntaxAnalysis::BinaryExpressionOperators::Exponentiation:
            op = BinaryOperatorType::Exponentiation;
            break;
        case SyntaxAnalysis::BinaryExpressionOperators::Modulo:
            op = BinaryOperatorType::Modulo;
            break;
        }

        return std::make_unique<BinaryExpressionASTNode>(std::move(lhsChild), op, std::move(rhsChild));
    }

    std::unique_ptr<ExpressionASTNode> transform(const SyntaxAnalysis::ExpressionNode& node)
    { 
        switch(node.getNodeType())
        {
        case SyntaxAnalysis::SyntaxNodeType::BinaryExpression:
            return transform(static_cast<const SyntaxAnalysis::BinaryExpressionNode&>(node));
        case SyntaxAnalysis::SyntaxNodeType::Literal:
            return transform(static_cast<const SyntaxAnalysis::LiteralExpressionNode&>(node));
        default:
            FERMI_UNREACHABLE;
        }
    }

    std::unique_ptr<StatementASTNode> transform(const SyntaxAnalysis::AssignmentStatementNode& node)
    {
        std::string_view assignee = node.getAssignee();
        auto it = symbolTable.find(assignee);
        if (it == symbolTable.end())
            throw 1;
        const FermiType& type = it->second;

        const SyntaxAnalysis::SyntaxNode* child = node.getChildren()[0];
        std::unique_ptr<ExpressionASTNode> initializer = transform(static_cast<const SyntaxAnalysis::ExpressionNode&>(*child));

        if (initializer->getType() != type)
        {
            if (isConvertibleTo(initializer->getType(), type))
            {
                initializer = std::make_unique<TypeConversionASTNode>(std::move(initializer), type);
            }
            else 
            {
                throw 1;
            }
        }

        return std::make_unique<AssignmentStatementASTNode>(assignee, std::move(initializer));
    }

    std::unique_ptr<StatementASTNode> transform(const SyntaxAnalysis::VariableDeclarationStatementNode& node)
    {
        std::string_view identifier = node.getIdentifier();
        SyntaxAnalysis::Type type = node.getType();
        const SyntaxAnalysis::SyntaxNode* child = node.getChildren()[0];

        std::unique_ptr<ExpressionASTNode> initializer;
        FermiType nodeType;
        if (child)
            initializer = transform(static_cast<const SyntaxAnalysis::ExpressionNode&>(*child));
        
        if (type == SyntaxAnalysis::Type::deduced)
        {
            if (!child)
                throw 1;
            nodeType = initializer->getType();
        }
        else 
        {
            nodeType = toASTType(type);
            if (initializer && initializer->getType() != nodeType)
            {
                if(!isConvertibleTo(initializer->getType(), nodeType))
                    throw 1;
                initializer = std::make_unique<TypeConversionASTNode>(std::move(initializer), nodeType);
            }
        }

        symbolTable.emplace(identifier, type);
        return std::make_unique<VariableDeclarationASTNode>(identifier, nodeType, std::move(initializer));
    }

    std::unique_ptr<StatementASTNode> transform(const SyntaxAnalysis::ExpressionStatementNode& node)
    {
        const auto* child = node.getChildren()[0];
        return std::make_unique<ExpressionStatementASTNode>(transform(static_cast<const SyntaxAnalysis::ExpressionNode&>(*child)));
    }

    std::unique_ptr<FermiASTNode> transform(const SyntaxAnalysis::FermiStatementNode& node)
    {
        std::unique_ptr<FermiASTNode> output = std::make_unique<FermiASTNode>();
        for(const auto* child : node.getChildren())
        {
            SyntaxAnalysis::SyntaxNodeType type = child->getNodeType();
            switch(type)
            {
            case SyntaxAnalysis::SyntaxNodeType::AssignmentStatementNode:
                output->addChild(transform(static_cast<const SyntaxAnalysis::AssignmentStatementNode&>(*child)));
                break;
            case SyntaxAnalysis::SyntaxNodeType::ExpressionStatementNode:
                output->addChild(transform(static_cast<const SyntaxAnalysis::ExpressionStatementNode&>(*child)));
                break;
            default:
                FERMI_UNREACHABLE;
            }
        }
        return output;
    }
}