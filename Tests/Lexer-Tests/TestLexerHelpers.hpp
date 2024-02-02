#ifndef TEST_LEXER_HELPERS_HPP
#define TEST_LEXER_HELPERS_HPP

#include <sstream>
#include <string_view>

#include <gtest/gtest.h>

#include "FermiLexer.hpp"

inline void testSingleString(const std::string& text, Fermi::LexicalAnalysis::FermiTokenKind kind)
{
    std::istringstream ss{text};
    Fermi::LexicalAnalysis::FermiLexer lexer{ss};

    std::vector<Fermi::LexicalAnalysis::FermiToken> vec = lexer.lex();
    ASSERT_FALSE(vec.empty());

    const auto& tok = vec.front();

    Fermi::LexicalAnalysis::Location start{.line = 1, .column = 1};
    Fermi::LexicalAnalysis::Location end{.line = 1, .column = text.length()};

    EXPECT_EQ(tok.kind, kind);
    EXPECT_EQ(tok.start, start);
    EXPECT_EQ(tok.start, end);
    EXPECT_STREQ(tok.value.c_str(), text.c_str());
}

#endif 