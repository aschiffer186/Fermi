#include <gtest/gtest.h>

#include "FermiLexer.hpp"

using namespace Fermi::SyntaxAnalysis;

auto setupTest(const std::string& literal, const std::string& value) -> void
{
    std::stringstream ss{literal};

    FermiLexer lexer{ss};

    const FermiParser::symbol_type token = lexer.nextToken();
    const auto& [begin, end]             = token.location;

    EXPECT_EQ(token.kind(), FermiParser::symbol_kind::S_IDENTIFIER);
    EXPECT_STREQ(token.value.as<std::string>().c_str(), value.c_str());
    EXPECT_EQ(begin.line, 1);
    EXPECT_EQ(begin.column, 1);
    EXPECT_EQ(end.line, 1);
    EXPECT_EQ(end.column, literal.length() + 1);
}

TEST(TestLexIdentifiers, TestLexIdentifiers)
{
    SCOPED_TRACE("TestLexIdentifiers");

    setupTest("_", "_");
    setupTest("_a0", "_a0");
}