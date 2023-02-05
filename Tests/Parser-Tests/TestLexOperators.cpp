#include <gtest/gtest.h>

#include "LexerTestUtils.hpp"

using SymbolKindType = FermiParser::symbol_kind::symbol_kind_type;

TEST(TestLexer, TestLexArithmeticOperators)
{
    runLexerTestValueless("+", SymbolKindType::S_PLUS);
    runLexerTestValueless("-", SymbolKindType::S_MINUS);
    runLexerTestValueless("*", SymbolKindType::S_STAR);
    runLexerTestValueless("/", SymbolKindType::S_SLASH);
    runLexerTestValueless("//", SymbolKindType::S_SLASH_SLASH);
    runLexerTestValueless("^", SymbolKindType::S_CARET);
    runLexerTestValueless("%", SymbolKindType::S_PERCENT);
}

TEST(TestLexer, TestLexPunctuators)
{
    runLexerTestValueless("(", SymbolKindType::S_LEFT_PARENTHESIS);
    runLexerTestValueless(")", SymbolKindType::S_RIGHT_PARENTHESIS);
    runLexerTestValueless(";", SymbolKindType::S_SEMI_COLON);
    runLexerTestValueless(":", SymbolKindType::S_COLON);
    runLexerTestValueless(",", SymbolKindType::S_COMMA);
}