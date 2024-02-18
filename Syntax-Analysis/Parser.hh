#ifndef PARSER_HH
#define PARSER_HH

#include <concepts>

#include "Scanner.hh"
#include "SyntaxTree/SyntaxNodes.hh"

namespace Fermi 
{
    class Parser 
    {
    public:
        explicit Parser(std::vector<Token> tokens);

        auto parse() -> std::vector<Token>&;
    private:
        auto parseStatment()            -> void;
        auto parseExpressionStatement() -> void;

        auto parseExpression() -> std::size_t;
        auto parseOr()         -> std::size_t;
        auto parseAnd()        -> std::size_t;
        auto parseEquality()   -> std::size_t; 
        auto parseComparison() -> std::size_t; 
        auto parseTerm()       -> std::size_t;
        auto parseFactor()     -> std::size_t; 
        auto parseExponent()   -> std::size_t; 
        auto parseUnaryFact()  -> std::size_t; 
        auto parseUnary()      -> std::size_t; 
        auto parsePrimary()    -> std::size_t;
    private:
        template<typename... Args>
        auto match(Args... args) -> bool
        {
            static_assert(std::same_as<TokenType, std::common_type_t<Args...>>);
            bool match = (... || check(args));
            if (match) { 
                advance(); 
                return true; 
            }
            return false;
        }
        auto expect(TokenType type)      -> const Token&;
        auto check(TokenType type) const -> bool;
        auto isAtEnd()             const -> bool;

        auto advance()                   -> const Token&;
        auto peek()                const -> const Token&;
        auto previous()            const -> const Token&;
        template<typename Type, typename... Args> 
        auto addNode(Args&&... args) -> std::size_t
        {
            tree_.emplace_back(std::in_place_type<Type>, std::forward<Args>(args)...);
            return tree_.size() - 1;
        }
    private: 
        std::size_t current_;
        std::vector<Token> tokens_;
        std::vector<SyntaxNode> tree_;
    };
}

#endif 