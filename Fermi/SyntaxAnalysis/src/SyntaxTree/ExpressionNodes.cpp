/**
 * @file ExpressionNodes.cpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief Implementation of expression nodes
 * @version 0.1
 * @date 2023-04-14
 * 
* @copyright Copyright (c) 2023
 * 
 */

#include "SyntaxTree/ExpressionNodes.hpp"
#include "SyntaxTree/SyntaxNode.hpp"

namespace Fermi::SyntaxAnalysis
{
    // Literal Expression Node
    BinaryExpressionNode::BinaryExpressionNode(std::unique_ptr<ExpressionNode> lhs, 
                                               BinaryOperatorType op,
                                               std::unique_ptr<ExpressionNode> rhs,
                                               const FermiSourceLocation& location)
    : _lhs{std::move(lhs)}, _op{std::move(op)}, _rhs{std::move(rhs)}, _location{location}
    {

    }

    SyntaxNodeType BinaryExpressionNode::getSyntaxNodeType() const
    {
        return SyntaxNodeType::BinaryExpressionNode;
    }

    std::vector<const SyntaxNode*> BinaryExpressionNode::getChildren() const 
    {
        return {_lhs.get(), _rhs.get()};
    }

    const FermiSourceLocation& BinaryExpressionNode::getSourceLocation() const 
    {
        return _location;
    }

    BinaryOperatorType BinaryExpressionNode::getOperator() const 
    {
        return _op;
    }

    bool BinaryExpressionNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = static_cast<const BinaryExpressionNode&>(other);
        return *(node._lhs) == *_lhs && node._op == _op && node._rhs == _rhs && node._location == _location;
    }

    void BinaryExpressionNode::print(std::ostream& os, std::string indent, bool isLast) const 
    {

    }

    // Identifier Expression Node
    IdentifierExpressionNode::IdentifierExpressionNode(std::string_view identifier, const FermiSourceLocation& location)
    : _identifier{identifier}, _location{location}
    {

    }

    SyntaxNodeType IdentifierExpressionNode::getSyntaxNodeType() const 
    {
        return SyntaxNodeType::IdentifierExpressionNode;
    }

    std::vector<const SyntaxNode*> IdentifierExpressionNode::getChildren() const 
    {
        return {};
    }

    const FermiSourceLocation& IdentifierExpressionNode::getSourceLocation() const 
    {
        return _location;
    }

    const std::string& IdentifierExpressionNode::getIdentifier() const 
    {
        return _identifier;
    }
    
    bool IdentifierExpressionNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = static_cast<const IdentifierExpressionNode&>(other);
        return _identifier == node._identifier && _location == node._location;
    }

    // Literal Expression Node
    LiteralExpressionNode::LiteralExpressionNode(LiteralExpressionType type, std::string_view value, const FermiSourceLocation& location)
    : _type{type}, _value{value}, _location{location}
    {

    }

    SyntaxNodeType LiteralExpressionNode::getSyntaxNodeType() const 
    {
        return SyntaxNodeType::LiteralExpressionNode;
    }

    std::vector<const SyntaxNode*> LiteralExpressionNode::getChildren() const 
    {
        return {};
    }

    const FermiSourceLocation& LiteralExpressionNode::getSourceLocation() const
    {
        return _location;
    }

    LiteralExpressionType LiteralExpressionNode::getLiteralExpressionType() const 
    {
        return _type;
    }

    const std::string& LiteralExpressionNode::getValue() const 
    {
        return _value;
    }

    bool LiteralExpressionNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = static_cast<const LiteralExpressionNode&>(other);
        return node._type == _type && node._value == _value && node._location == _location;
    }
}