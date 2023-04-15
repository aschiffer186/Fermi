/**
 * @file SyntaxNode.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ExpressionNodes.hpp"

#include <typeinfo>

#include "Visitor.hpp"

using namespace std::literals;

namespace Fermi::SyntaxAnalysis
{
    BinaryExpressionNode::BinaryExpressionNode(std::shared_ptr<ExpressionNode> lhs, 
                                               BinaryExpressionOperators operatorIn, 
                                               std::shared_ptr<ExpressionNode> rhs)
        : lhs_{lhs}, operator_{operatorIn}, rhs_{rhs}
        {

        }

    SyntaxNodeType BinaryExpressionNode::getNodeType() const 
    {
        return SyntaxNodeType::BinaryExpression;
    }

    std::vector<const SyntaxNode*> BinaryExpressionNode::getChildren() const 
    {
        return {lhs_.get(), rhs_.get()};
    }

    BinaryExpressionOperators BinaryExpressionNode::getOperator() const 
    {
        return operator_;
    }

    bool BinaryExpressionNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = dynamic_cast<const BinaryExpressionNode&>(other);
        return *lhs_ == *node.lhs_ && operator_ == node.operator_ && *rhs_ == *node.rhs_;
    }

    namespace 
    {
        std::unordered_map<BinaryExpressionOperators, std::string> BinaryNodeToString = {
            {BinaryExpressionOperators::Addition, "+"},
            {BinaryExpressionOperators::Division, "/"},
            {BinaryExpressionOperators::Exponentiation, "^"},
            {BinaryExpressionOperators::IntegerDivision, "//"},
            {BinaryExpressionOperators::Modulo, "%"},
            {BinaryExpressionOperators::Multiplication, "*"},
            {BinaryExpressionOperators::Subtraction, "-"}
        };
    }

    std::ostream& BinaryExpressionNode::print(std::ostream& os, std::string indent, bool isLast) const
    {
        std::string tokenMarker = (isLast) ? CORNER : TEE;

        os << indent; 
        os << tokenMarker;

        os << "Binary Expression";
        indent += (isLast) ? SPACE : PIPE + SPACE;
        os << "\n";
        lhs_->print(os, indent, false);
        os << "\n";
        os << indent << TEE << "Operator: " << BinaryNodeToString[operator_];
        os << "\n";
        rhs_->print(os, indent, true);
        return os;
    }

    LiteralExpressionNode::LiteralExpressionNode(std::string_view value, LiteralType type)
    : type_{type}, value_{value}
    {

    }

    SyntaxNodeType LiteralExpressionNode::getNodeType() const 
    {
        return SyntaxNodeType::Literal;
    }

    std::vector<const SyntaxNode*> LiteralExpressionNode::getChildren() const 
    {
        return {};
    }

    const std::string& LiteralExpressionNode::getValue() const 
    {
        return value_;
    }

    LiteralType LiteralExpressionNode::getType() const 
    {
        return type_;
    }

    bool LiteralExpressionNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = dynamic_cast<const LiteralExpressionNode&>(other);
        return type_ == node.type_ && value_ == node.value_;
    }

    std::ostream& LiteralExpressionNode::print(std::ostream& os, std::string indent, bool isLast) const
    {
        std::string tokenMarker = (isLast) ? CORNER : TEE;

        os << indent; 
        os << tokenMarker;

        os << "Literal Node";
        indent += (isLast) ? SPACE : PIPE + SPACE;

        os << "\n"; 
        os << indent << TEE << "Value: " << value_;
        os << "\n";
        os << indent << CORNER;
        switch(type_)
        {
            case LiteralType::Identifier:
                os << "Identifier";
                break;
            case LiteralType::Integer:
                os << "Integer";
                break; 
            case LiteralType::Float:
                os << "Float";
                break;
        }
        return os;
    }

}