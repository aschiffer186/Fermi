/**
 * @file TestLexLiterals.cpp
 * @author Alex Schiffer (aschiffer186@gmail.com)
 * @brief Test lexing literals
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <sstream>

#include <gtest/gtest.h>

#include "FermiLexer.hpp"

using namespace Fermi::SyntaxAnalysis;

TEST(TestLexer, TestLexIntegerLiterals)
{
    std::string testString1 = "123456789";
    std::stringstream ss1(testString1);

    FermiLexer lexer1(ss1);
    FermiToken token = lexer1.nextToken();

    EXPECT_EQ(token.location.line, 1);
    EXPECT_EQ(token.location.startCol, 1);
    EXPECT_EQ(token.location.endCol, 9);
    EXPECT_EQ(token.type, FermiTokenType::IntegerLiteral);
    EXPECT_STREQ(token.value.c_str(), testString1.c_str());
}

TEST(TestLexer, TestLexFloatLiterals)
{
    std::string testString1 = "123456789.987654321";
    std::stringstream ss1(testString1);

    FermiLexer lexer1(ss1);
    FermiToken token1 = lexer1.nextToken();

    EXPECT_EQ(token1.location.line, 1);
    EXPECT_EQ(token1.location.startCol, 1);
    EXPECT_EQ(token1.location.endCol, 19);
    EXPECT_EQ(token1.type, FermiTokenType::FloatLiteral);
    EXPECT_STREQ(token1.value.c_str(), testString1.c_str());

    std::string testString2 = ".123456789";
    std::stringstream ss2(testString2);

    FermiLexer lexer2(ss2);
    FermiToken token2 = lexer2.nextToken();
    EXPECT_EQ(token2.location.line, 1);
    EXPECT_EQ(token2.location.startCol, 1);
    EXPECT_EQ(token2.location.endCol, 10);
    EXPECT_EQ(token2.type, FermiTokenType::FloatLiteral);
    EXPECT_STREQ(token2.value.c_str(), testString2.c_str());

    std::string testString3 = ".0e123456789";
    std::stringstream ss3(testString3);

    FermiLexer lexer3(ss3);
    FermiToken token3 = lexer3.nextToken();
    EXPECT_EQ(token3.location.line, 1);
    EXPECT_EQ(token3.location.startCol, 1);
    EXPECT_EQ(token3.location.endCol, 12);
    EXPECT_EQ(token3.type, FermiTokenType::FloatLiteral);
    EXPECT_STREQ(token3.value.c_str(), testString3.c_str());

    std::string testString4 = ".0E123456789";
    std::stringstream ss4(testString4);

    FermiLexer lexer4(ss4);
    FermiToken token4 = lexer4.nextToken();
    EXPECT_EQ(token4.location.line, 1);
    EXPECT_EQ(token4.location.startCol, 1);
    EXPECT_EQ(token4.location.endCol, 12);
    EXPECT_EQ(token4.type, FermiTokenType::FloatLiteral);
    EXPECT_STREQ(token4.value.c_str(), testString4.c_str());
}