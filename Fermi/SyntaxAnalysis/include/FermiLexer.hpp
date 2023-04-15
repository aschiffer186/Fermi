/**
 * @file FermiLexer.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief Declaration of FermiLexer
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <array>
#include <iosfwd>

#ifndef yyFlexLexer
#include <FlexLexer.h>
#endif

namespace Fermi::SyntaxAnalysis
{
    struct FermiSourceLocation 
    {
        std::size_t line = 1;
        std::size_t startCol = 1;
        std::size_t endCol = 1;

        friend bool operator==(const FermiSourceLocation& lhs, const FermiSourceLocation& rhs) noexcept = default;
    };

    enum class FermiTokenType : short 
    {
        //Literals
        IntegerLiteral,
        FloatLiteral,
        //Identifiers
        Identifier,
        //Operators
        Plus,
        Minus,
        Star,
        Slash,
        DoubleSlash,
        Caret,
        Percent,
        Equal,
        //Punctuators
        SemiColon,
        Colon,
        LeftParenthesis,
        RightParenthesis,
        Comma,
        //Keywords
        Let,
        Print,
        //Misc,
        Error,
        FermiEOF
    };

    inline constexpr std::array typeNames{"Integer Literal",
                                          "Float Literal",
                                          "Identifier",
                                          "Plus",
                                          "Minus",
                                          "Star",
                                          "Slash",
                                          "Double Slash",
                                          "Caret",
                                          "Percent",
                                          "Equal",
                                          "Semi Colon",
                                          "Colon",
                                          "Left Parenthesis",
                                          "Right Parenthesis",
                                          "Comma",
                                          "Let",
                                          "Print",
                                          "Error",
                                          "Fermi EOF"};
    std::ostream& operator<<(std::ostream& os, FermiTokenType type);

    struct FermiToken 
    {
        FermiSourceLocation location;
        FermiTokenType type;
        std::string value;

        friend bool operator==(const FermiToken& lhs, const FermiToken& rhs) noexcept = default;
    };

    std::ostream& operator<<(std::ostream& os, const FermiToken& token);

    class FermiLexer : public yyFlexLexer 
    {
    public:
        FermiLexer(std::istream& in);

        using FlexLexer::yylex;

        FermiToken nextToken();

        FermiToken lookaheadToken();
    private:
        FermiToken makeToken(FermiTokenType type);
        FermiToken makeEOF();
    private:
        std::size_t _line;
        std::size_t _col;
    };
}