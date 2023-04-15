/**
 * @file FermiParser.cpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief Definition of Fermi Parser
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "FermiParser.hpp"
#include "FermiLexer.hpp"
#include "SyntaxTree/ExpressionNodes.hpp"
#include "SyntaxTree/SyntaxNodes.hpp"
#include "SyntaxTree/SyntaxNodesFwd.hpp"

namespace Fermi::SyntaxAnalysis
{
    FermiParser::FermiParser(std::istream& in)
    : _lexer{in}
    {

    }

    std::unique_ptr<FermiStatementNode> FermiParser::parse()
    {
        auto statement = std::make_unique<FermiStatementNode>();
        do 
        {
            statement->addChild(parseStatement());
        } while (_nextToken.type != FermiTokenType::FermiEOF);
        return statement;
    }

    std::unique_ptr<StatementNode> FermiParser::parseStatement()
    {
        if (accept(FermiTokenType::Print))
        {
            return parsePrintStatement();
        }
        else if (accept(FermiTokenType::Let))
        {
            return parseVariableDeclarationStatement();
        }
        else if(auto tok = accept(FermiTokenType::Identifier); tok)
        {
            if (accept(FermiTokenType::Equal))
                return parseAssignmentStatement(tok->value);
            return parseExpressionStatement();
        }
        else 
        {
            return parseExpressionStatement();
        }
    }

    std::unique_ptr<StatementNode> FermiParser::parseExpressionStatement()
    {
        auto child = parseExpression();
        auto loc = child->getSourceLocation();
        return std::make_unique<ExpressionStatementNode>(std::move(child), loc);
    }

    std::unique_ptr<StatementNode> FermiParser::parseAssignmentStatement(std::string_view identifier)
    {
        std::unique_ptr<IdentifierExpressionNode> lhs = std::make_unique<IdentifierExpressionNode>(identifier, FermiSourceLocation{});
        std::unique_ptr<ExpressionNode> rhs = parseExpression();
        return std::make_unique<AssignmentStatementNode>(std::move(lhs), std::move(rhs), FermiSourceLocation{});
    }

    std::unique_ptr<StatementNode> FermiParser::parsePrintStatement() 
    {
        std::vector<std::unique_ptr<ExpressionNode>> expressions;
        expect(FermiTokenType::LeftParenthesis);
        expect(FermiTokenType::RightParenthesis);
        while(_lexer.lookaheadToken().type != FermiTokenType::RightParenthesis && 
              _lexer.lookaheadToken().type != FermiTokenType::SemiColon &&
              _lexer.lookaheadToken().type != FermiTokenType::Error &&
              _lexer.lookaheadToken().type != FermiTokenType::FermiEOF)
        {
            expressions.push_back(parseExpression());
        }
        if(expressions.empty())
            return nullptr;
        expect(FermiTokenType::RightParenthesis);
        expect(FermiTokenType::SemiColon);
        FermiSourceLocation loc{.line = expressions.front()->getSourceLocation().line,
                                .startCol = expressions.back()->getSourceLocation().startCol,
                                .endCol = expressions.back()->getSourceLocation().endCol};
        return std::make_unique<PrintStatementNode>(std::move(expressions), loc);
    }

    std::unique_ptr<StatementNode> FermiParser::parseVariableDeclarationStatement()
    {
        std::unique_ptr<ExpressionNode> initializer = nullptr;
        FermiSourceLocation loc;
        std::string identifier = _nextToken.value;
        loc.line = _nextToken.location.line;
        loc.startCol = _nextToken.location.startCol;
        loc.endCol = _nextToken.location.endCol;
        expect(FermiTokenType::Identifier);
        auto t = parseType();

        if (accept(FermiTokenType::Equal))
        {
            initializer = parseExpression();
            loc.endCol = initializer->getSourceLocation().endCol;
        }
        else if (!t.has_value())
        {
            throw 1;
        }
        return std::make_unique<VariableDeclarationStatementNode>(identifier, t, std::move(initializer), loc);
    }

    std::optional<FermiToken> FermiParser::accept(FermiTokenType type)
    {
        if(_nextToken.type == type)
        {
            auto currToken = _nextToken;
            _nextToken = _lexer.nextToken();
            return currToken;
        }
        return std::nullopt;
    }

    std::optional<FermiToken> FermiParser::expect(FermiTokenType type)
    {
        if(_nextToken.type == type)
        {
            auto currToken = _nextToken;
            _nextToken = _lexer.nextToken();
            return currToken;
        }
        throw 1;
    }
}