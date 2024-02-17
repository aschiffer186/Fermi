#include "Scanner.hh"

#include <algorithm>
#include <functional>
#include <ostream>
#include <ranges>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>

namespace Fermi 
{

    auto StringHash::operator()(const char* txt) const noexcept -> std::size_t 
    {
        return std::hash<std::string_view>{}(txt);
    }

    auto StringHash::operator()(std::string_view txt) const noexcept -> std::size_t 
    {
        return std::hash<std::string_view>{}(txt);
    }

    auto StringHash::operator()(const std::string& txt) const noexcept -> std::size_t 
    {
        return std::hash<std::string>{}(txt);
    }

    auto operator<<(std::ostream& os, const Token& tok) -> std::ostream&
    {
        os << "{Type: "     << static_cast<std::underlying_type_t<TokenType>>(tok.type); 
        os << ", Line: "    << tok.line; 
        os << ", Lexeme: "  << tok.lexeme; 
        os << ", Literal: " << tok.literal << "}";
        return os;
    }

    const std::unordered_map<std::string, TokenType, StringHash, std::equal_to<>> Scanner::keywords_
    {
        {"float32_t", TokenType::Float32},
        {"float64_t", TokenType::Float64},
        {"int8_t", TokenType::Int8},
        {"int16_t", TokenType::Int16},
        {"int32_t", TokenType::Int32},
        {"int64_t", TokenType::Int64},
        {"nat8_t", TokenType::Nat8},
        {"nat16_t", TokenType::Nat16},
        {"nat32_t", TokenType::Nat32},
        {"nat64_t", TokenType::Nat64},
        {"as", TokenType::As},
        {"define", TokenType::Define},
        {"let", TokenType::Let},
        {"private", TokenType::Private},
        {"public", TokenType::Public},
        {"compeval", TokenType::Compeval},
        {"mutable", TokenType::Mutable},
        {"pure", TokenType::Pure},
        {"static", TokenType::Static},
        {"false", TokenType::False},
        {"this", TokenType::This},
        {"true", TokenType::True}
    };

    Scanner::Scanner(std::string source)
    : source_(std::move(source))
    {

    }

    auto Scanner::scanTokens() -> const std::vector<Token>& 
    {
        while (!isAtEnd())
        {
            start_ = current_;
            tokens_.push_back(scanToken());
        }

        tokens_.emplace_back(TokenType::FermiEOF, line_, "$", "");
        if (std::ranges::any_of(tokens_, [](const auto& tok) { return tok.type == TokenType::Error; }))
        {
            tokens_.clear();
            return tokens_;
        }
        return tokens_;
    }

    auto Scanner::scanToken() -> Token 
    {
        const char c = advance();
        switch (c)
        {
            using enum TokenType;
            case '(':
                return makeToken(LeftParen);
            case ')': 
                return makeToken(RightParen);
            case ',':
                return makeToken(Comma);
            case '{':
                return makeToken(LeftBrace);
            case '}':
                return makeToken(RightBrace);
            case '=':
            {
                const TokenType type = match('=') ? Assign : Equal; 
                return makeToken(type);
            }
            case '<':
                return makeToken(Less);
            case '>':
                return makeToken(Greater);
            case '+':
            {
                const TokenType type = match('-') ? PlusMinus : Plus;
                return makeToken(Plus);
            }
            case '-':
            {
                const TokenType type = match('>') ? LeftArrow : Minus;
                return makeToken(type);
            }
            case '*':
                return makeToken(Star);
            case '%':
                return makeToken(Percent);
            case '/':
            {
                const TokenType type = match('/') ? SlashSlash : Slash; 
                return makeToken(type);
            }
            case '^':
                return makeToken(Caret);
            case '!':
            {
                const TokenType type = match('=') ? Bang : Bang; 
                return makeToken(type);
            }
            case '.':
            {
                if (std::isdigit(peekNext())) { advance(); return digit(); }
            }
            case '"':
                return string();
            case '\'':
                return character();
            // Comments and whitespace 
            case '#':
                while (peek() != '\n' && !isAtEnd()) { advance(); }
                break;
            case ' ':
            case '\t':
            case '\r':
                break; 
            case '\n':
                ++line_; 
                break;
            default: 
                if (std::isdigit(c))             { return digit();      }
                if (std::isalpha(c) || c == '_') { return identifierKeyword(); }
                return makeToken(Error);
        }
        __builtin_unreachable();
    }

    auto Scanner::makeToken(TokenType type, std::string literal) const -> Token 
    {
        const std::string text{source_.cbegin() + start_, source_.cbegin() + current_};
        return {.type = type, .line = line_, .lexeme = text, .literal = std::move(literal)};
    }

    auto Scanner::character() -> Token 
    {
        using enum TokenType;

        while (peek() != '\'' && !isAtEnd())
        {
            if (peek() == '\n') { ++line_; }
            advance();
        }

        advance();
        std::string literal{source_.cbegin() + start_ + 1, source_.cbegin() + current_ - 1};
        if (literal.length() > 1) { return makeToken(Error); }
        return makeToken(Character, std::move(literal));
    }

    auto Scanner::string() -> Token 
    {
        using enum TokenType;
        while (peek() != '"' && !isAtEnd())
        {
            if (peek() == '\n') { ++line_; }
            advance(); 
        }

        advance();
        std::string literal{source_.cbegin() + start_ + 1, source_.cbegin() + current_ - 1};
        return makeToken(String, std::move(literal));
    }

    auto Scanner::identifierKeyword() -> Token 
    {
        using enum TokenType; 

        while (std::isalpha(peek()) || std::isdigit(peek()) || peek() == '_') { advance(); }

        const std::string_view text{source_.cbegin() + start_, source_.cbegin() + current_};
        if (auto it = keywords_.find(text); it != keywords_.end())
        {
            return makeToken(it->second);
        }
        return makeToken(Identifier);
    }

    auto Scanner::digit() -> Token 
    {
        using enum TokenType;

        while(std::isdigit(peek())) { advance(); }

        if (peek() == '.' && std::isdigit(peekNext())) { 
            advance(); 

            while (std::isdigit(peek())) { advance(); }
        }
        else if (peek() == '.')
        {
            advance();
        }

        const std::string text{source_.cbegin() + start_, source_.cbegin() + current_};
        if (text.find(".") != std::string::npos) 
        { 
            return makeToken(FloatingPoint, text); 
        }
        return makeToken(Integer, text);
    }

    auto Scanner::advance() -> char 
    {
        if(isAtEnd()) { return 0; }
        return source_[current_++];
    }

    auto Scanner::peek() const -> char 
    {
        if(isAtEnd()) { return '\0'; }
        return source_[current_];
    }

    auto Scanner::peekNext() const -> char 
    {
        if(current_ + 1 >= source_.length()) { return '\0'; }
        return source_[current_ + 1];
    }

    auto Scanner::match(char expected) -> bool 
    {
        if(isAtEnd())           { return false; }
        if (peek() != expected) { return false; }

        ++current_;
        return true;
    }   

    auto Scanner::isAtEnd() const -> bool 
    {
        return current_ >= source_.length();
    }
} 