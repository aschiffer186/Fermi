/**
 * @file Parser.hpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <unordered_map>
#include <vector>

#include "FermiLexerTypes.hpp"

#include "Syntax-Tree/SyntaxNodes.hpp"

namespace Fermi::SyntaxAnalysis
{
    class FermiParser 
    {
    public:
        explicit FermiParser(std::vector<LexicalAnalysis::FermiToken> tokens);

        void parse();

        const std::vector<SyntaxNode>& getSyntaxTree() const;
    private:
        static auto getPrecedence(LexicalAnalysis::FermiTokenKind);

        std::size_t parseExpression();
        std::size_t parseStatement();
        std::size_t parseFunctionDeclaration();

        bool accept(LexicalAnalysis::FermiTokenKind);
        bool expect(LexicalAnalysis::FermiTokenKind);
    private:
        std::size_t currTokenIdex_{0};

        static const std::unordered_map<LexicalAnalysis::FermiTokenKind, int> tokPrec_;

        std::vector<LexicalAnalysis::FermiToken> tokens_;
        std::vector<SyntaxNode> syntaxTree_;
    };
}

#endif