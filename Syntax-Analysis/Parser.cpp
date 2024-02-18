#include "Parser.hh"

#include <algorithm>
#include <utility>

#include "Scanner.hh"
#include "SyntaxTree/ExpressionNodes.hh"
#include "SyntaxTree/StatementNodes.hh"
#include "SyntaxTree/SyntaxNodes.hh"

namespace Fermi 
{
    Parser::Parser(std::vector<Token> tokens)
    : tokens_(std::move(tokens))
    {

    }

    auto Parser::parse() -> std::vector<Token>& 
    {
        while(!isAtEnd())
        {
            parseStatment();
        }
        return tokens_;
    }

    auto Parser::parseStatment() -> void 
    {
        parseExpressionStatement();
    }

    auto Parser::parseExpressionStatement() -> void 
    {
        std::size_t child = parseExpression(); 
        if (match(";")) {
            tree_.emplace_back(std::in_place_type<ExpressionStatementNode>, child);
        }
    }

    auto Parser::parseExpression() -> std::size_t 
    {
        return parseOr();
    }


    auto Parser::parseOr() -> std::size_t 
    {
        std::size_t leftChild = parseAnd();
        while (match(TokenType::Or))
        {
            TokenType op = previous().type;
            std::size_t rightChild = parseAnd();
            tree_.emplace_back(std::in_place_type<BinaryExpressionNode>, leftChild, op, rightChild);
            leftChild = tree_.size() - 1;
        }
        return leftChild;
    }

    auto Parser::parseAnd() -> std::size_t 
    {
        std::size_t leftChild = parseEquality(); 
        while(match(TokenType::And))
        {
            TokenType op = previous().type; 
            std::size_t rightChild = parseEquality();
            tree_.emplace_back(std::in_place_type<BinaryExpressionNode>, leftChild, op, rightChild);
            leftChild = tree_.size() - 1;
        }
        return leftChild;
    }

    auto Parser::parseEquality() -> std::size_t 
    {
        std::size_t leftChild = parseComparison(); 
        while(match(TokenType::Equal, TokenType::NotEqual))
        {
            TokenType op = previous().type; 
            std::size_t rightChild = parseComparison(); 
            tree_.emplace_back(std::in_place_type<BinaryExpressionNode>, leftChild, op, rightChild);
            leftChild = tree_.size() - 1;
        }
        return leftChild;
    }

    auto Parser::parseComparison() -> std::size_t 
    {
        std::size_t leftChild = parseTerm(); 
        while(match(TokenType::Less, TokenType::LessEqual, TokenType::Greater, TokenType::GreaterEqual))
        {
            TokenType op = previous().type; 
            std::size_t rightChild = parseTerm(); 
            tree_.emplace_back(std::in_place_type<BinaryExpressionNode>, leftChild, op, rightChild);
            leftChild = tree_.size() - 1;
        }
        return leftChild;
    }

    auto Parser::parseTerm() -> std::size_t 
    {
        std::size_t leftChild = parseFactor(); 
        while(match(TokenType::Plus, TokenType::PlusMinus, TokenType::Minus))
        {
            TokenType op = previous().type; 
            std::size_t rightChild = parseFactor(); 
            tree_.emplace_back(std::in_place_type<BinaryExpressionNode>, leftChild, op, rightChild); 
            leftChild = tree_.size() - 1; 
        }
        return leftChild;
    }

    auto Parser::parseFactor() -> std::size_t 
    {
        std::size_t leftChild = parseExponent();
        while(match(TokenType::Star, TokenType::Slash, TokenType::SlashSlash, TokenType::Percent))
        {
            TokenType op = previous().type; 
            std::size_t rightChild = parseExponent(); 
            leftChild = addNode<BinaryExpressionNode>(leftChild, op, rightChild); 
        }
        return leftChild;
    }

    auto Parser::parseExponent() -> std::size_t 
    {
        std::size_t leftChild = parseUnaryFact(); 
        while(match(TokenType::Caret))
        {
            TokenType op = previous().type; 
            std::size_t rightChild = parseExponent(); 
            leftChild = addNode<BinaryExpressionNode>(leftChild, op, rightChild);
        }
        return leftChild;
    }

    auto Parser::parseUnary() -> std::size_t 
    {
        if (match("!"))
        {
            TokenType op = previous().type;
            std::size_t child = parsePrimary();
            return addNode<UnaryExpressionNode>(op, child);
        }
        return parsePrimary();
    }

    auto Parser::parsePrimary() -> std::size_t 
    {
        if (match(TokenType::Integer, TokenType::FloatingPoint, TokenType::Character, TokenType::String))
        {
            TokenType op        = previous().type; 
            std::string literal = previous().literal;
            return addNode<LiteralExpressionNode>(op, std::move(literal));
        }

        if (match(TokenType::Identifier))
        {
            std::string identifier = previous().lexeme; 
            return addNode<IdentifierNode>(std::move(identifier));
        }

        if (match(TokenType::LeftParen))
        {
            std::size_t expr = parseExpression();
            expect(TokenType::RightParen);
        }
        return -1;
    }

    auto Parser::check(TokenType type) const -> bool 
    {
        if (isAtEnd()) { return false; }
        return peek().type == type;
    }

    auto Parser::peek() const -> const Token& 
    {
        return tokens_[current_];
    }

    auto Parser::advance() -> const Token& 
    {
        const Token& tok = peek();
        if(!isAtEnd()) { current_++; }
        return tok;
    }

    auto Parser::previous() const -> const Token& 
    {
        return tokens_[current_ - 1];
    }
}