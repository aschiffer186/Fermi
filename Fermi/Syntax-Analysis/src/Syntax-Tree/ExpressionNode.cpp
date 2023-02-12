#include <typeinfo>

#include "ExpressionNode.hpp"

using namespace std::literals;

namespace Fermi::SyntaxAnalysis
{
    BinaryExpressionNode::BinaryExpressionNode(std::shared_ptr<ExpressionNode> lhs, 
                                               BinaryExpressionTypes operatorIn, 
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

    BinaryExpressionTypes BinaryExpressionNode::getOperator() const 
    {
        return operator_;
    }

    bool BinaryExpressionNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = dynamic_cast<const BinaryExpressionNode&>(other);
        return *lhs_ == *node.lhs_ && operator_ == node.operator_ && *lhs_ == *node.rhs_;
    }

    namespace 
    {
        std::unordered_map<BinaryExpressionTypes, std::string> BinaryNodeToString = {
            {BinaryExpressionTypes::Addition, "+"},
            {BinaryExpressionTypes::Division, "/"},
            {BinaryExpressionTypes::Exponentiation, "^"},
            {BinaryExpressionTypes::IntegerDivision, "//"},
            {BinaryExpressionTypes::Modulo, "%"},
            {BinaryExpressionTypes::Multiplication, "*"},
            {BinaryExpressionTypes::Subtraction, "-"}
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
        os << indent << TEE << BinaryNodeToString[operator_];
        os << "\n";
        rhs_->print(os, indent, true);
        return os;
    }

    LiteralNode::LiteralNode(std::string_view value, LiteralType type)
    : type_{type}, value_{value}
    {

    }

    SyntaxNodeType LiteralNode::getNodeType() const 
    {
        return SyntaxNodeType::Literal;
    }

    std::vector<const SyntaxNode*> LiteralNode::getChildren() const 
    {
        return {};
    }

    const std::string& LiteralNode::getValue() const 
    {
        return value_;
    }

    LiteralType LiteralNode::getType() const 
    {
        return type_;
    }

    bool LiteralNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = dynamic_cast<const LiteralNode&>(other);
        return type_ == node.type_ && value_ == node.value_;
    }

    std::ostream& LiteralNode::print(std::ostream& os, std::string indent, bool isLast) const
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