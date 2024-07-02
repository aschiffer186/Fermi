#ifndef EXPRESSION_NODES
#define EXPRESSION_NODES

#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>
#include <variant>
namespace Fermi::SyntaxAnalysis
{
    enum class BinaryOperation
    {
        Addition,
        Subtraction,
        Multiplication,
        Division,
        Modulo,
        Exponentiation
    };

    struct BinaryExpressionNode
    {
        std::size_t     lhsChild;
        BinaryOperation op;
        std::size_t     rhsChild;

        BinaryExpressionNode(
            std::size_t lhsChildIn, BinaryOperation opIn,
            std::size_t rhsChildIn)
            : lhsChild(lhsChildIn),
              op(opIn),
              rhsChild(rhsChildIn)
        {
        }

        friend bool operator==(
            const BinaryExpressionNode&, const BinaryExpressionNode&) = default;
    };

    enum class LiteralExpressionType
    {
        Integer,
        Float,
        Complex
    };

    struct LiteralExpressionNode
    {
        std::variant<std::uint64_t, double> value;
        LiteralExpressionType               type;

        LiteralExpressionNode(double valueIn, LiteralExpressionType type)
            : value(std::in_place_type<double>, valueIn),
              type(type)
        {
        }

        LiteralExpressionNode(std::uint64_t valueIn, LiteralExpressionType type)
            : value(std::in_place_type<std::uint64_t>, valueIn),
              type(type)
        {
        }

        friend bool operator==(
            const LiteralExpressionNode&,
            const LiteralExpressionNode&) = default;
    };

    struct IdentifierExpressionNode
    {
        std::string identifier;

        explicit IdentifierExpressionNode(std::string identifierIn)
            : identifier(std::move(identifierIn))
        {
        }

        friend bool operator==(
            const IdentifierExpressionNode&,
            const IdentifierExpressionNode&) = default;
    };

    struct ParenthesizedExpressionNode
    {
        std::size_t child;

        explicit ParenthesizedExpressionNode(std::size_t childIn)
            : child(childIn)
        {
        }
    };
} // namespace Fermi::SyntaxAnalysis

#endif