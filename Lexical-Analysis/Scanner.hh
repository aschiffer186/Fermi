#ifndef SCANNER_HH
#define SCANNER_HH

#include <iosfwd> 
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace Fermi 
{
    enum class TokenType
    {
        // Punctuators 
        Comma, // ,
        LeftParen, // (
        RightParen, // )
        LeftBrace, // {
        RightBrace, // }

        // Operators 
        Assign, // =
        Bang, // !
        Caret, // ^
        Equal,
        Greater,
        LeftArrow, // <-
        Less,
        Minus, // -
        Percent, // %
        Plus, // +
        PlusMinus, // +-
        Slash, // /
        SlashSlash, // // 
        Star, // *

        // Keywords 
        // Fundmanetal types 
        Float32, 
        Float64,
        Int8, 
        Int16, 
        Int32, 
        Int64, 
        Nat8, 
        Nat16, 
        Nat32, 
        Nat64,

        // Declaration related
        As,
        Define,
        Let, 
        Private,
        Public,

        // Type modifiers
        Compeval,
        Mutable,
        Pure,
        Static,

        // Language values
        False, 
        This,
        True, 

        Identifier,

        // Literals 
        Complex,
        Character, 
        FloatingPoint, 
        Integer, 
        String,

        FermiEOF,
        Error
    };

    struct Token 
    {
        TokenType type; 
        std::uint32_t line; 
        std::string lexeme; 
        std::string literal;

        friend auto operator==(const Token&, const Token&) -> bool = default;
    };

    auto operator<<(std::ostream&, const Token&) -> std::ostream&;

    struct StringHash 
    {
        using is_transparent = void; 

        auto operator()(const char*)        const noexcept -> std::size_t;
        auto operator()(std::string_view)   const noexcept -> std::size_t;
        auto operator()(const std::string&) const noexcept -> std::size_t;
    };

    class Scanner 
    {
    public:
        explicit Scanner(std::string);

        auto scanTokens() -> const std::vector<Token>&;
    private:
        auto scanToken() -> Token;

        auto character()                                  -> Token; 
        auto makeToken(TokenType, std::string = "") const -> Token;
        auto digit()                                      -> Token;
        auto identifierKeyword()                          -> Token;
        auto string()                                     -> Token;

        auto advance()         -> char;
        auto peek()      const -> char;
        auto peekNext()  const -> char;
        auto match(char)       -> bool;

        auto isAtEnd() const -> bool;
    private:
        private:
        std::uint32_t start_{0};
        std::uint32_t current_{0};
        std::uint32_t line_{1};
        std::string source_;
        std::vector<Token> tokens_;
        static const std::unordered_map<std::string, TokenType, StringHash, std::equal_to<>> keywords_;
    };
}

#endif