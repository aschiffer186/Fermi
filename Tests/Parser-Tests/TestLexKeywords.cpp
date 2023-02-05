#include <gtest/gtest.h>

#include "LexerTestUtils.hpp"

using SymbolKindType = FermiParser::symbol_kind::symbol_kind_type;

TEST(TestLexer, TestLexKeywords)
{
    runLexerTestValueless("let", SymbolKindType::S_LET);
    runLexerTestValueless("print", SymbolKindType::S_PRINT);
}