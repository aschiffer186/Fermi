#include <algorithm>

#include "ExpressionNode.hpp"
#include "StatementNode.hpp"

using namespace std::literals;

namespace Fermi::SyntaxAnalysis
{
    VariableDeclarationNode::VariableDeclarationNode(Type type, std::string_view identifier, std::shared_ptr<ExpressionNode> initializer)
    : type_{type}, identifier_{identifier}, initializer_{std::move(initializer)}
    {

    }

    SyntaxNodeType VariableDeclarationNode::getNodeType() const 
    {
        return SyntaxNodeType::VariableDeclarationNode;
    }

    std::vector<const SyntaxNode*> VariableDeclarationNode::getChildren() const 
    {
        return {initializer_.get()};
    }

    Type VariableDeclarationNode::getType() const 
    {
        return type_;
    }

    const std::string& VariableDeclarationNode::getIdentifier() const 
    {
        return identifier_;
    }

    bool VariableDeclarationNode::equals(const SyntaxNode& other) const noexcept
    {
        const auto& node = dynamic_cast<const VariableDeclarationNode&>(other);
        if(type_ != node.type_)
            return false;
        if (identifier_ != node.identifier_)
            return false;
        if (!initializer_)
            return !node.initializer_;
        return *initializer_ == *node.initializer_;
    }

    std::ostream& VariableDeclarationNode::print(std::ostream& os, std::string indent, bool isLast) const
    {
        std::string tokenMarker = (isLast) ? CORNER : TEE;

        os << indent; 
        os << tokenMarker;

        os << "Variable Declaration";
        indent += (isLast) ? " " : PIPE + " "s;

        os << "\n" << indent << TEE;
        os << "Type: ";
        switch(type_)
        {
        case Type::deduced:
            os << "Deduced";
            break;
        case Type::float32_t:
            os << "float32_t";
            break;
        case Type::float64_t:
            os << "float64_t";
            break;
        case Type::int8_t:
            os << "int8_t";
            break;
        case Type::int16_t:
            os << "int16_t";
            break;
        case Type::int32_t:
            os << "int32_t";
            break;
        case Type::int64_t:
            os << "int64_t";
            break;
        }
        os << "\n";
        if (!initializer_)
            os << indent << CORNER << "Identifier: " << identifier_;
        else 
        {
            os << indent << PIPE << "Identifier: " << identifier_;
            os << "\n";
            initializer_->print(os, indent, true);
        }
        return os;
    }

    PrintNode::PrintNode(std::vector<std::shared_ptr<ExpressionNode>>&& vec)
    : expressions_{std::move(vec)}
    {

    }
    
    SyntaxNodeType PrintNode::getNodeType() const 
    {
        return SyntaxNodeType::PrintNode;
    }

    std::vector<const SyntaxNode*> PrintNode::getChildren() const 
    {
        std::vector<const SyntaxNode*> children;
        std::transform(expressions_.begin(), expressions_.end(), std::back_inserter(children), [](const auto& exp) {return exp.get();});
        return children;
    }

    void PrintNode::addPrintingExpression(std::shared_ptr<ExpressionNode> expression)
    {
        expressions_.push_back(expression);
    }

    bool PrintNode::equals(const SyntaxNode& other) const noexcept
    {
        const auto& node = dynamic_cast<const PrintNode&>(other);
        return std::equal(expressions_.begin(), expressions_.end(), node.expressions_.begin(), [](const auto& lhs, const auto& rhs){
            return *lhs == *rhs;
        });
    }

    std::ostream& PrintNode::print(std::ostream& os, std::string indent, bool isLast) const 
    {
        
        std::string tokenMarker = (isLast) ? CORNER : TEE;

        os << indent; 
        os << tokenMarker;

        os << "Print Node";
        indent += (isLast) ? " " : PIPE + " "s;
        for(size_t i = 0; i < expressions_.size(); ++i)
        {
            if (i == expressions_.size() - 1)
                expressions_[i]->print(os, indent, true);
            else
                expressions_[i]->print(os, indent, false);
        }
        return os;
    }

    AssignmentStatementNode::AssignmentStatementNode(std::string_view lhs, std::shared_ptr<ExpressionNode> rhs)
    : lhs_{lhs}, rhs_{rhs}
    {

    }


    SyntaxNodeType AssignmentStatementNode::getNodeType() const 
    {
        return SyntaxNodeType::AssignmentStatementNode;
    }

    std::vector<const SyntaxNode*> AssignmentStatementNode::getChildren() const 
    {
        return {rhs_.get()};
    }

    const std::string& AssignmentStatementNode::getAssignee() const 
    {
        return lhs_;
    }

    bool AssignmentStatementNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = dynamic_cast<const AssignmentStatementNode&>(other);
        return lhs_ == node.lhs_ && *rhs_ == *node.rhs_;
    }

    std::ostream& AssignmentStatementNode::print(std::ostream& os, std::string indent, bool isLast) const 
    {
        
        std::string tokenMarker = (isLast) ? CORNER : TEE;

        os << indent; 
        os << tokenMarker;

        os << "PAssignmentStatement Node";
        indent += (isLast) ? " " : PIPE + " "s;
        os << indent << TEE << lhs_;
        os << "\n";
        os << indent <<  CORNER;
        rhs_->print(os, indent, true);
        return os;
    }
}