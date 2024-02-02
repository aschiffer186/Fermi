#ifndef EXPRESSION_SYNTAX_NODES
#define EXPRESSION_SYNTAX_NODES

#include <variant>
#include <vector>

#include "FermiLexerTypes.hpp"

namespace Fermi::SyntaxAnalysis
{
    struct BinaryExpressionNode
    {
        LexicalAnalysis::FermiTokenKind op;
        LexicalAnalysis::Location start; 
        LexicalAnalysis::Location end;
        std::size_t leftChildIndex;
        std::size_t rightChildIndex;

        friend bool operator==(const BinaryExpressionNode&, const BinaryExpressionNode&) = default;
    };

    struct UnaryExpressionNode
    {
        LexicalAnalysis::FermiTokenKind op;
        LexicalAnalysis::Location start; 
        LexicalAnalysis::Location end;
        std::size_t operandIndex;

        friend bool operator==(const UnaryExpressionNode&, const UnaryExpressionNode&) = default;
    };

    enum class LiteralType 
    {
        CharacterLiteral,
        ComplexLiteral,
        FloatLiteral,
        IntegerLiteral,
        StringLiteral
    };

    struct LiteralExpressionNode 
    {
        LiteralType type;
        LexicalAnalysis::Location start;
        LexicalAnalysis::Location end; 
        std::string value;

        friend bool operator==(const LiteralExpressionNode&, const LiteralExpressionNode&) = default;
    };

    struct FunctionCallExpressionNode 
    {
        std::string functionName;
        LexicalAnalysis::Location start;
        LexicalAnalysis::Location end;
        std::vector<std::size_t> parameters;

        friend bool operator==(const FunctionCallExpressionNode&, const FunctionCallExpressionNode&) = default;
    };
}

#endif