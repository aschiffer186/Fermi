#include <gtest/gtest.h> 

#include "Scanner.hh" 

TEST(TestLexer, TestIdentifiers)
{
    const std::string test1 = "abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_";
    Fermi::Scanner s{test1};
    std::vector<Fermi::Token> tokens = s.scanTokens();
    std::vector<Fermi::Token> expectedTokens
    {
        Fermi::Token{.type = Fermi::TokenType::Identifier, .line = 1, .lexeme = test1, .literal = ""},
        Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
    };
    EXPECT_EQ(expectedTokens, tokens);

    const std::string test2 = "_";
    Fermi::Scanner s2{test2};
    tokens = s2.scanTokens();
    expectedTokens =
    {
        Fermi::Token{.type = Fermi::TokenType::Identifier, .line = 1, .lexeme = test2, .literal = ""},
        Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
    };
    EXPECT_EQ(expectedTokens, tokens);
}

TEST(TestLexer, TestKeywords)
{
    using enum Fermi::TokenType; 
    const std::vector<std::pair<std::string, Fermi::TokenType>> keywords 
    {
        {"float32_t", Float32},
        {"float64_t", Float64}, 
        {"int8_t",    Int8},
        {"int16_t",   Int16},
        {"int32_t",   Int32},
        {"int64_t",   Int64},
        {"nat8_t",    Nat8},
        {"nat16_t",   Nat16},
        {"nat32_t",   Nat32},
        {"nat64_t",   Nat64},
        {"as",        As},
        {"define",    Define},
        {"let",       Let},
        {"private",   Private},
        {"public",    Public},
        {"compeval",  Compeval},
        {"mutable",   Mutable},
        {"pure",      Pure},
        {"static",    Static},
        {"false",     False},
        {"this",      This},
        {"true",      True}
    };

    for(const auto& [keyword, type] : keywords)
    {
        Fermi::Scanner s{keyword};
        std::vector<Fermi::Token> tokens = s.scanTokens(); 
        std::vector<Fermi::Token> expectedTokens 
        {
            Fermi::Token{.type = type, .line = 1, .lexeme = keyword, .literal = ""},
            Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
        };
        EXPECT_EQ(expectedTokens, tokens);
    }
}