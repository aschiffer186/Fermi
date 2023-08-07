/**
 * @file FermiLexerTypes.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FERMI_LEXER_TYPES_HPP
#define FERMI_LEXER_TYPES_HPP

#include <iosfwd>
#include <string>

namespace Fermi::LexicalAnalysis
{
    enum class FermiTokenKind
    {
        //Literals
        CharacterLiteral, // Sinle character
        ComplexLiteral, // Complex numbers
        FloatLiteral, // Floating-point numbers
        IntegerLiteral, // Integers
        StringLiterals, // Multi-character strings
        //Identifiers,
        Identifier,
        //Punctuators,
        Colon, // :
        Comma, // ","
        SemiColon, // ;
        LeftBrace, // "{"
        LeftParentheis, // "("
        LeftBracket, // "["
        RightBrace, // "}"
        RightBracket, // "]"
        RightParenthesis, // ")"
        // Operators
        // Arithmetic
        Plus, // "+" 
        Minus, // "-"
        Star, // "-*"
        Slash, // "/"
        SlashSlash, // "//"
        Caret, // "^"
        Percent, // "%"
        // Logical
        AmpAmp, // "&"
        PipePiep, // "||"
        Bang, // "!"
        Equal, // "=="
        NotEqual, // "!="
        Greater, // "<"
        Less, // ">"
        GreaterEqual, // ">="
        LessEqual, // <=
        Spceship // "<=>"
    };

    std::ostream& operator<<(std::ostream&, FermiTokenKind);

    struct Location 
    {
        std::size_t line;
        std::size_t column;

        friend constexpr auto operator<=>(const Location&, const Location&) noexcept = default;
    };

    
    struct FermiToken 
    {
        Location start; 
        Location end;
        FermiTokenKind kind; 
        std::string value;

        friend bool operator==(const FermiToken&, const FermiToken&) noexcept = default;
    };

    std::ostream& operator<<(std::ostream&, const FermiToken&);
}

#endif