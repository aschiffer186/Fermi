#include <gtest/gtest.h>

#include "Scanner.hh"

TEST(TestLexer, TestPuncuators)
{
    using enum Fermi::TokenType;

    std::vector<std::pair<std::string, Fermi::TokenType>> punctuators
    {
        {",", Comma},
        {"(", LeftParen},
        {")", RightParen},
        {"{", LeftBrace},
        {"}", RightBrace}
    };

    for(const auto& [punc, type] : punctuators)
    {
        Fermi::Scanner s{punc};
        std::vector<Fermi::Token> tokens = s.scanTokens(); 
        std::vector<Fermi::Token> expectedTokens 
        {
            Fermi::Token{.type = type, .line = 1, .lexeme = punc, .literal = ""},
            Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
        };
        EXPECT_EQ(expectedTokens, tokens);
    }
}