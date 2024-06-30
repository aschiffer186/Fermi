#include <gtest/gtest.h>

#include "FermiLexer.hpp"

using namespace Fermi::SyntaxAnalysis;

auto setupTest(const std::string& literal, double value) -> void
{
    std::stringstream ss{literal};

    FermiLexer lexer{ss};

    const FermiParser::symbol_type token = lexer.nextToken();
    const auto& [begin, end]             = token.location;

    EXPECT_EQ(token.kind(), FermiParser::symbol_kind::S_FLOAT_LITERAL);
    EXPECT_FLOAT_EQ(token.value.as<double>(), value);
    EXPECT_EQ(begin.line, 1);
    EXPECT_EQ(begin.column, 1);
    EXPECT_EQ(end.line, 1);
    EXPECT_EQ(end.column, literal.length() + 1);
}

TEST(TestLexFloatLiterals, TestLexSimpleLiterals)
{
    SCOPED_TRACE("TestLexFloatLiterals");

    setupTest(".1234567890", 0.1234567890);
    setupTest("9876543210.1234567890", 9876543210.1234567890);
}

TEST(TestLexFloatLiterals, TestLexDecimalExponent)
{
    SCOPED_TRACE("TestLexFloatLiterals");

    setupTest("12.7e10", 12.7e10);
    setupTest("12.7E10", 12.7E10);
    setupTest("12.7e-10", 12.7e-10);
    setupTest("12.7E+10", 12.7E+10);
}