#ifndef LEXER_TEST_UTILS_HPP
#define LEXER_TEST_UTILS_HPP

#include <fstream>
#include <sstream>
#include <string_view>

#include <gtest/gtest.h>

#include "FermiLexer.hpp"
#include "FermiParser.hpp"

using namespace Fermi::SyntaxAnalysis;

inline location makeLocation(int startLine, int startCol, int endLine, int endCol)
{
    position start;
    start.column = startCol;
    start.line = startLine;
    
    position end;
    end.column = endCol;
    end.line = endLine;

    return location{start, end};
}

inline void runLexerTest(const std::string& testStr, FermiParser::symbol_kind_type expectedSymbolKind)
{
    std::stringstream testStream{testStr};
    FermiLexer lexer{testStream};

    FermiParser::symbol_type token = lexer.nextToken();

    EXPECT_EQ(token.kind(), expectedSymbolKind);
    EXPECT_STREQ(token.value.as<std::string>().c_str(), testStr.c_str());
    EXPECT_EQ(token.location.begin.column, 1);
    EXPECT_EQ(token.location.begin.line, 1);
    EXPECT_EQ(token.location.end.column, testStr.length() + 1);
    EXPECT_EQ(token.location.end.line, 1);
}

void compareTokens(const FermiParser::symbol_type&, const FermiParser::symbol_type&);

inline void runLexerTest(const std::string& testStr, 
    const std::vector<FermiParser::symbol_type>& expectedTokens)
{
    std::stringstream testStream{testStr};
    FermiLexer lexer{testStream};

    auto tokenVec = std::vector<FermiParser::symbol_type>{};
    while (true)
    {
        auto token = lexer.nextToken();
        tokenVec.push_back(token);
        if (token.kind() == FermiParser::symbol_kind_type::S_YYEOF)
            break;
    }

    ASSERT_EQ(tokenVec.size(), expectedTokens.size());
    for(auto it1 = tokenVec.cbegin(), it2 = expectedTokens.cbegin(); it1 != tokenVec.end(); ++it1, ++it2)
    {
        compareTokens(*it1, *it2);
    }
}

inline void runLexerTest(std::fstream& testStream, 
    const std::vector<FermiParser::symbol_type>& expectedTokens)
{
    FermiLexer lexer{testStream};

    auto tokenVec = std::vector<FermiParser::symbol_type>{};
    while (true)
    {
        auto token = lexer.nextToken();
        tokenVec.push_back(token);
        if (token.kind() == FermiParser::symbol_kind_type::S_YYEOF)
            break;
    }

    ASSERT_EQ(tokenVec.size(), expectedTokens.size());
    for(auto it1 = tokenVec.cbegin(), it2 = expectedTokens.cbegin(); it1 != tokenVec.end(); ++it1, ++it2)
    {
        compareTokens(*it1, *it2);
    }
}

inline void compareTokens(const FermiParser::symbol_type& actual, const FermiParser::symbol_type& expected)
{
    EXPECT_EQ(actual.kind(), expected.kind());
    EXPECT_EQ(actual.location.begin.column, expected.location.begin.column);
    EXPECT_EQ(actual.location.end.column, expected.location.end.column);
    EXPECT_EQ(actual.location.begin.line, expected.location.begin.line);
    EXPECT_EQ(actual.location.end.line, expected.location.end.line);
    if (actual.kind() == FermiParser::symbol_kind::S_INTEGER_LITERAL
        || actual.kind() == FermiParser::symbol_kind::S_FLOAT_LITERAL
        || actual.kind() == FermiParser::symbol_kind::S_IDENTIFIER)
    {
        EXPECT_STREQ(actual.value.as<std::string>().c_str(), expected.value.as<std::string>().c_str());
    }
}

inline void runLexerTestValueless(const std::string& testStr, FermiParser::symbol_kind_type expectedSymbolKind)
{
    std::stringstream testStream{testStr};
    FermiLexer lexer{testStream};

    FermiParser::symbol_type token = lexer.nextToken();

    EXPECT_EQ(token.kind(), expectedSymbolKind);
    EXPECT_EQ(token.location.begin.column, 1);
    EXPECT_EQ(token.location.begin.line, 1);
    EXPECT_EQ(token.location.end.column, testStr.length() + 1);
    EXPECT_EQ(token.location.end.line, 1);
}


#endif