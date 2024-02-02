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
    /**
     * @brief Enum representing the category of a Fermi Token
     * 
     */
    enum class FermiTokenKind : unsigned char
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
        Amp, // "&"
        Colon, // :
        Comma, // ","
        LeftBrace, // "{"
        LeftBracket, // "["
        LeftParenthesis, // "("
        RightBrace, // "}"
        RightBracket, // "]"
        RightParenthesis, // ")"
        SemiColon, // ;
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
        PipePipe, // "||"
        Bang, // "!"
        Equal, // "=="
        NotEqual, // "!="
        Greater, // ">"
        Less, // "<"
        GreaterEqual, // ">="
        LessEqual, // <=
        Spaceship, // "<=>"
        Dot, // "."
        //Other
        Assign,
        //Keywords
        As, // "as"
        Define, // "define"
        Export, // "export"
        Let, // "let"
        Module, // "module"
        Nothrow, // "nothrow"
        Operator, // "operator"
        Public, // "public"
        Pure, // "pure"
        Struct, // "struct"
        Template, // "template"
        Typeset, // "typeset"
        FermiError, 
        FermiEOF,
        END
    };

    std::ostream& operator<<(std::ostream&, FermiTokenKind);

    /**
     * @brief The Location struct represents a location in a source file
     * 
     */
    struct Location 
    {
        /// The line in the source file.
        /// Starts at 1.
        std::size_t line;
        /// The column in the source file. Starts at 1.
        std::size_t column;

        friend constexpr auto operator<=>(const Location&, const Location&) noexcept = default;
    };

    /**
     * @brief Represents a single token.
     * 
     * A token is the smallest unit of syntatic significance in a valid Fermi program. 
     * Each token has a category repersenting its syntactic meaning as well as a value 
     * corresponding to the text it represents. The FermiToken struct also carries information 
     * about its location in a source file.
     */
    struct FermiToken 
    {
        /// The location of the first character of the token.
        Location start; 
        /// The location of the last character of the token.
        Location end;
        /// The syntactic category of the token.
        FermiTokenKind kind; 
        /// The value of the token i.e. the corresponding text in the source file.
        std::string value;

        friend bool operator==(const FermiToken&, const FermiToken&) noexcept = default;
    };

    std::ostream& operator<<(std::ostream&, const FermiToken&);
}

#endif