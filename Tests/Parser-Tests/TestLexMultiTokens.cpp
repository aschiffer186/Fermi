#include <gtest/gtest.h>

#include "LexerTestUtils.hpp"

using TokenType = FermiParser::symbol_type;

TEST(TestLexer, TestLexMultipleTokensNoWhitespace)
{
    std::string testStr = "1+2.3456-x23";
    auto expectedTokens = std::vector<TokenType>{
        FermiParser::make_INTEGER_LITERAL("1", makeLocation(1, 1, 1, 2)),
        FermiParser::make_PLUS(makeLocation(1, 2, 1, 3)),
        FermiParser::make_FLOAT_LITERAL("2.3456", makeLocation(1, 3, 1, 9)),
        FermiParser::make_MINUS(makeLocation(1,9,1,10)),
        FermiParser::make_IDENTIFIER("x23", makeLocation(1,10,1,13)),
        FermiParser::make_YYEOF(makeLocation(1, 13, 1, 13))
    };

    runLexerTest(testStr, expectedTokens);
}