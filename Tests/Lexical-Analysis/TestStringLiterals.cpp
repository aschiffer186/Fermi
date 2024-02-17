#include <gtest/gtest.h> 

#include "Scanner.hh"

TEST(TestLexer, TestStringLiterals)
{
    const std::string test1 = 
        "\"abcddefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
        "!@#$%^&*()-_=+{}[];:,.<>/?'\"";
    Fermi::Scanner s{test1};
    std::vector<Fermi::Token> tokens = s.scanTokens();
    std::vector<Fermi::Token> expectedTokens
    {
        Fermi::Token{.type = Fermi::TokenType::String, .line = 1, .lexeme = test1, .literal = test1.substr(1, test1.length() - 2)}, 
        Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
    };
    EXPECT_EQ(expectedTokens, tokens);

    const std::string test2 = "\"\"";
    Fermi::Scanner s2{test2};
    tokens = s2.scanTokens(); 
    expectedTokens = 
    {
        Fermi::Token{.type = Fermi::TokenType::String, .line = 1, .lexeme = test2, .literal = ""}, 
        Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
    };
    EXPECT_EQ(expectedTokens, tokens);

    const std::string test3= "\"\\\"\\\\n";
    Fermi::Scanner s3{test3};
    //tokens = s.scanTokens(); 
    expectedTokens = 
    {
        Fermi::Token{.type = Fermi::TokenType::String, .line = 1, .lexeme = test3, .literal = test3.substr(1, test3.length() - 2)}, 
        Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
    };
}

TEST(TestLexer, TestCharacterLiters)
{
    const std::string allChars = 
        "abcddefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
        "!@#$%^&*()-_=+{}[];:,.<>/?\"";
    for(char c : allChars)
    {
        std::string test1 = "'";
        test1.append(std::string{c});
        test1.append("'");

        Fermi::Scanner s{test1};
        std::vector<Fermi::Token> tokens = s.scanTokens();
        std::vector<Fermi::Token> expectedTokens
        {
            Fermi::Token{.type = Fermi::TokenType::Character, .line = 1, .lexeme = test1, .literal = test1.substr(1, test1.length() - 2)}, 
            Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
        };
        EXPECT_EQ(expectedTokens, tokens);
    }
}
