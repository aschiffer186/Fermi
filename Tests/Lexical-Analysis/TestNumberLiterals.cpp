#include <gtest/gtest.h> 

#include "Scanner.hh"

TEST(TestLexer, TestIntegerLiterals)
{
    const std::string test1 = "123456789";
    Fermi::Scanner s{test1};
    std::vector<Fermi::Token> tokens = s.scanTokens();
    std::vector<Fermi::Token> expectedTokens
    {
        Fermi::Token{.type = Fermi::TokenType::Integer, .line = 1, .lexeme = test1, .literal = test1},
        Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
    };
    EXPECT_EQ(tokens, expectedTokens);
}

TEST(TestLexer, TestFloatLiterals)
{
    const std::string test1 = "123456789.987654321";
    Fermi::Scanner s{test1};
    std::vector<Fermi::Token> tokens = s.scanTokens();
    std::vector<Fermi::Token> expectedTokens
    {
        Fermi::Token{.type = Fermi::TokenType::FloatingPoint, .line = 1, .lexeme = test1, .literal = test1},
        Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
    };
    EXPECT_EQ(tokens, expectedTokens);

    const std::string test2 = ".987654321";
    Fermi::Scanner s2{test2};
    tokens = s2.scanTokens(); 
    expectedTokens = 
    {
        Fermi::Token{.type = Fermi::TokenType::FloatingPoint, .line = 1, .lexeme = test2, .literal = test2},
        Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
    };
    EXPECT_EQ(tokens, expectedTokens);

    const std::string test3 = "123456789.";
    Fermi::Scanner s3{test3};
    tokens = s3.scanTokens();
    expectedTokens = 
    {
        Fermi::Token{.type = Fermi::TokenType::FloatingPoint, .line = 1, .lexeme = test3, .literal = test3},
        Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
    };
}