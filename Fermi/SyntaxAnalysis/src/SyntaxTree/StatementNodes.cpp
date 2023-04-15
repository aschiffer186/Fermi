/**
 * @file StatementNodes.cpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief Definition of statement syntax nodes
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "SyntaxTree/StatementNodes.hpp"

#include "SyntaxTree/ExpressionNodes.hpp"
#include "SyntaxTree/SyntaxNode.hpp"

#include <algorithm>

 namespace Fermi::SyntaxAnalysis
 {
    // Assignment Statement Node
    AssignmentStatementNode::AssignmentStatementNode(std::unique_ptr<IdentifierExpressionNode> lhs, 
                                                     std::unique_ptr<ExpressionNode> rhs,
                                                     const FermiSourceLocation& location)
    : _lhs{std::move(lhs)}, _rhs{std::move(rhs)}, _location{location}
    {

    }

    SyntaxNodeType AssignmentStatementNode::getSyntaxNodeType() const 
    {
        return SyntaxNodeType::AssignmentStatementNode;
    }

    std::vector<const SyntaxNode*> AssignmentStatementNode::getChildren() const 
    {
        return {_lhs.get(), _rhs.get()};
    }

    const FermiSourceLocation& AssignmentStatementNode::getSourceLocation() const 
    {
        return _location;
    }

    bool AssignmentStatementNode::equals(const SyntaxNode& other) const noexcept
    {
        const auto& node = static_cast<const AssignmentStatementNode&>(other);
        return *(node._lhs) == *_lhs && *(node._rhs) == *_rhs && node._location == _location;
    }

    // Fermi Node
    SyntaxNodeType FermiStatementNode::getSyntaxNodeType() const 
    {
        return SyntaxNodeType::FermiStatementNode;
    }

    std::vector<const SyntaxNode*> FermiStatementNode::getChildren() const 
    {
        std::vector<const SyntaxNode*> children;
        std::ranges::transform(_children, std::back_inserter(children), [](const auto& node){
            return node.get();
        });
        return children;
    }

    const FermiSourceLocation& FermiStatementNode::getSourceLocation() const 
    {
        return _location;
    }

    void FermiStatementNode::addChild(std::unique_ptr<StatementNode> child)
    {
        _children.push_back(std::move(child));
    }

    bool FermiStatementNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = static_cast<const FermiStatementNode&>(other);
        return std::equal(_children.begin(), _children.end(), node._children.begin(), [](const auto& lhs, const auto& rhs){
            return *lhs == *rhs;
        }) && _location == node._location;
    }

    // Print Statement Node
    PrintStatementNode::PrintStatementNode(std::vector<std::unique_ptr<ExpressionNode>> vec, const FermiSourceLocation& location)
    : _children{std::move(vec)}, _location{location}
    {

    }

    SyntaxNodeType PrintStatementNode::getSyntaxNodeType() const 
    {
        return SyntaxNodeType::PrintStatementNode;
    }

    std::vector<const SyntaxNode*> PrintStatementNode::getChildren() const 
    {
        std::vector<const SyntaxNode*> children;
        std::ranges::transform(_children, std::back_inserter(children), [](const auto& node){
            return node.get();
        });
        return children;
    }

    const FermiSourceLocation& PrintStatementNode::getSourceLocation() const 
    {
        return _location;
    }

    bool PrintStatementNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = static_cast<const PrintStatementNode&>(other);
        return std::equal(_children.begin(), _children.end(), node._children.begin(), [](const auto& lhs, const auto& rhs){
            return *lhs == *rhs;
        }) && _location == node._location;
    }

    VariableDeclarationStatementNode::VariableDeclarationStatementNode(std::string_view identifier,
                                                                       std::optional<TypeNode> type, 
                                                                       std::unique_ptr<ExpressionNode> initializer, 
                                                                       const FermiSourceLocation& location)
    : _identifier{identifier}, _type{type}, _initializer{std::move(initializer)}, _location{location}
    {
        
    }

    SyntaxNodeType VariableDeclarationStatementNode::getSyntaxNodeType() const 
    {
        return SyntaxNodeType::VariableDeclarationStatementNode;
    }

    std::vector<const SyntaxNode*> VariableDeclarationStatementNode::getChildren() const 
    {
        return {_initializer.get()};
    }

    const FermiSourceLocation& VariableDeclarationStatementNode::getSourceLocation() const 
    {
        return _location;
    }

    const std::string& VariableDeclarationStatementNode::getIdentifier() const 
    {
        return _identifier;
    }

    std::optional<TypeNode> VariableDeclarationStatementNode::getType() const 
    {
        return _type;
    }

    bool VariableDeclarationStatementNode::equals(const SyntaxNode& other) const noexcept 
    {
        const auto& node = static_cast<const VariableDeclarationStatementNode&>(other);
        return _identifier == node._identifier &&
            _type == node._type &&
            *_initializer == *(node._initializer) &&
            _location == node._location;
    }

    void VariableDeclarationStatementNode::print(std::ostream& os, std::string indent, bool isLast) const
    {
        std::string tokenMarker = (isLast) ? CORNER : TEE;

        os << indent;
        os << tokenMarker;
        os << "Variable Declaration";
        indent += (isLast) ? SPACE : PIPE + SPACE; 
        os << "\n" << indent << TEE; 
        os << "Type: " << ((_type) ? _type->name : "Deduced");
        os << "\n";
        if (!_initializer)
            os << indent << CORNER << "Identifier: " << _identifier; 
        else 
        {
            os << indent << TEE << "Identifier: " << _identifier; 
            os << "\n";
            _initializer->print(os, indent, true);
        }

    }
 }