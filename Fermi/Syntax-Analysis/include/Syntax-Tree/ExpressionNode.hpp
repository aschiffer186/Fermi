#ifndef EXPRESSION_NODE_HPP
#define EXPRESSION_NODE_HPP

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>

#include "SyntaxNode.hpp"

namespace Fermi::SyntaxAnalysis
{
    /**
     * @brief Base class for all expression nodes
     * 
     */
    class ExpressionNode : public SyntaxNode 
    {
    public:
        virtual ~ExpressionNode() = default;
    };

    /**
     * @brief Enum representing types of binary expressions
     * 
     * This enum contains values representing all possible operators
     * in a binary expression.
     */
    enum class BinaryExpressionTypes
    {
        /// @brief Binary addition operator
        Addition,
        /// @brief Binary subtraction operator
        Subtraction,
        /// @brief Binary multiplication operator
        Multiplication,
        /// @brief Binary division operator
        Division,
        /// @brief Binary integer division operator
        IntegerDivision,
        /// @brief Binary exponentiation operator
        Exponentiation,
        /// @brief Binary modulo operator
        Modulo
    };

    /**
     * @brief Binary expression node.
     * 
     * This class represents a binary expression in Fermi source code. 
     * Each binary expression has an expression child node that is the left hand side operand, 
     * an expression node child node that is the right hand side operand and an operator. 
     */
    class BinaryExpressionNode : public ExpressionNode
    {
    public:
        /**
         * @brief Constructor
         * 
         * Creates a new binary expression node with the specified operator and operands.
         * 
         * @param lhs the left hand side operand
         * @param operatorIn the binary operator
         * @param rhs the right hand side operand
         */
        BinaryExpressionNode(std::shared_ptr<ExpressionNode> lhs, BinaryExpressionTypes operatorIn, std::shared_ptr<ExpressionNode> rhs);

        SyntaxNodeType getNodeType() const override; 

        std::vector<const SyntaxNode*> getChildren() const override; 

        /**
         * @brief Returns the binary operator
         * 
         * Return's the binary expression node's binary operator
         * 
         * @return the binary expression node's binary operator
         */
        BinaryExpressionTypes getOperator() const;

        std::ostream& print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    private:
        std::shared_ptr<ExpressionNode> lhs_;
        BinaryExpressionTypes operator_;
        std::shared_ptr<ExpressionNode> rhs_;
    };

    /**
     * @brief 
     * 
     */
    enum class LiteralType 
    {
        Integer, 
        Float, 
        Identifier
    };

    class LiteralNode : public ExpressionNode
    {
    public:
        explicit LiteralNode(std::string_view value, LiteralType type);

        SyntaxNodeType getNodeType() const override;

        std::vector<const SyntaxNode*> getChildren() const override;

        const std::string& getValue() const;

        LiteralType getType() const;
        
        std::ostream& print(std::ostream& os, std::string indent, bool isLast) const override;
    private:
        bool equals(const SyntaxNode& other) const noexcept override;
    private:
        LiteralType type_;
        std::string value_;
    };

    
}

#endif