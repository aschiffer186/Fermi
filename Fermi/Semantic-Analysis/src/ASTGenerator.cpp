/** @file ASTGenerator.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <cstdint>
#include <limits>
#include <stdexcept>

#include "Syntax-Tree/ExpressionNode.hpp"
#include "Syntax-Tree/StatementNode.hpp"

#include "ASTNodes/ExpressionASTNode.hpp"
#include "ASTGenerator.hpp"
#include "Type.hpp"

namespace Fermi::SemanticAnalysis
{
    std::unique_ptr<ExpressionASTNode> transform(const SyntaxAnalysis::LiteralNode& node)
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
                }
            }
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
                }
            }
        case SyntaxAnalysis::LiteralType::Identifier:
            return nullptr;
        }
    }
}