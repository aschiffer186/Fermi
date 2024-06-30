#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "FermiLexer.hpp"
#include "FermiParser.hpp"
#include "location.hh"

using namespace Fermi::SyntaxAnalysis;

auto setupTest(const std::string& literal, std::uint64_t value) -> void
{
    std::stringstream ss{literal};

    FermiLexer lexer{ss};

    const FermiParser::symbol_type token = lexer.nextToken();
    const auto& [begin, end]             = token.location;

    EXPECT_EQ(token.kind(), FermiParser::symbol_kind::S_INTEGER_LITERAL);
    EXPECT_EQ(token.value.as<std::uint64_t>(), value);
    EXPECT_EQ(begin.line, 1);
    EXPECT_EQ(begin.column, 1);
    EXPECT_EQ(end.line, 1);
    EXPECT_EQ(end.column, literal.length() + 1);
}

TEST(TestLexIntegerLiterals, TestLexSimpleLiteral)
{
    SCOPED_TRACE("TestLexSimpleLiteral");

    setupTest("0123456789", 123'456'789);
}

TEST(TestLexIntegerLiterals, TestLexDecimalExponent)
{
    SCOPED_TRACE("TestLexDecimalExponent");

    setupTest("10e9", 10'000'000'000);
    setupTest("10E9", 10'000'000'000);
    setupTest("3E+11", 300'000'000'000);
}

TEST(TestLexIntegerLiterals, TestLexBasedLiteral)
{
    SCOPED_TRACE("TestLexBasedLiteral");

    setupTest("36#ZYO12#", 60'404'006);
    setupTest("2#101#", 5);
}

TEST(TestLexIntegerLiterals, TestLexBasedExponent)
{
    SCOPED_TRACE("TestLexBasedExponent");
    setupTest("36#ZA#A", 12'700'000'000'000);
    setupTest("2#101#1000", 500'000'000);
}