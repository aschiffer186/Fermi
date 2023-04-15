/**
 * @file FermiParser.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief Declaration of parser for Fermi source files
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once 

#include <memory>
#include <optional>

#include "FermiLexer.hpp"
#include "SyntaxTree/SyntaxNodesFwd.hpp"

namespace Fermi::SyntaxAnalysis
{
    class FermiParser 
    {
    public: 
        explicit FermiParser(std::istream& in);

        std::unique_ptr<FermiStatementNode> parse();
    private:
        std::unique_ptr<StatementNode> parseStatement();
        std::unique_ptr<StatementNode> parseAssignmentStatement(std::string_view identifer);
        std::unique_ptr<StatementNode> parseExpressionStatement();
        std::unique_ptr<StatementNode> parsePrintStatement();
        std::unique_ptr<StatementNode> parseVariableDeclarationStatement();

        std::unique_ptr<ExpressionNode> parseExpression();

        std::optional<TypeNode> parseType();

        std::optional<FermiToken> accept(FermiTokenType token);

        std::optional<FermiToken> expect(FermiTokenType token);
    private:
        FermiLexer _lexer;
        FermiToken _nextToken;
    };
}