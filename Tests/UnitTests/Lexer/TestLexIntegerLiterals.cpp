#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "FermiLexer.hpp"
#include "FermiParser.hpp"
#include "location.hh"

using namespace Fermi::SyntaxAnalysis;

auto setupTest(const std::string& literal) -> void
{
    std::stringstream ss{literal};

    // const FermiParser::symbol_type token;
    // const auto& [begin, end] = token.location;

    // EXPECT_EQ(token.kind(), FermiParser::symbol_kind::S_INTEGER_LITERAL);
    // EXPECT_EQ(begin.line, 1);
    // EXPECT_EQ(begin.column, 1);
    // EXPECT_EQ(end.line, 1);
    // EXPECT_EQ(end.column, literal.length());
}

TEST(TestLexIntegerLiterals, TestLexSimpleLiteral)
{
    SCOPED_TRACE("TestLexSimpleLiteral");

    setupTest("0123456789");
}

TEST(TestLexIntegerLiterals, TestLexDecimalExponent)
{
    SCOPED_TRACE("TestLexDecimalExponent");

    setupTest("9876543210e0123456789");
    setupTest("0123456789E987654321");
    setupTest("0123456789e+09876543210");
}

TEST(TestLexIntegerLiterals, TestLexBasedLiteral)
{
    SCOPED_TRACE("TestLexBasedLiteral");

    setupTest(
        "36#ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789#");
}

TEST(TestLexIntegerLiterals, TestLexBasedExponent)
{
    SCOPED_TRACE("TestLexBasedExponent");
    setupTest(
        "36#Z#9876543210ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
}