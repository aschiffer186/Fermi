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
        {"}", RightBrace},
        {";", Semicolon}
    };

    for(const auto& [punc, type] : punctuators)
    {
        Fermi::Lexer s{punc};
        std::vector<Fermi::Token> tokens = s.scanTokens(); 
        std::vector<Fermi::Token> expectedTokens 
        {
            Fermi::Token{.type = type, .line = 1, .lexeme = punc, .literal = ""},
            Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
        };
        EXPECT_EQ(expectedTokens, tokens);
    }
}

TEST(TestLexer, TestOperators)
{
    using enum Fermi::TokenType;

    std::vector<std::pair<std::string, Fermi::TokenType>> operators
    {
        {"=", Assign},
        {"!", Bang}, 
        {"^", Caret},
        {"==", Equal},
        {">", Greater},
        {">=", GreaterEqual},
        {"<-", LeftArrow},
        {"<", Less},
        {"<=", LessEqual}, 
        {"-", Minus},
        {"!=", NotEqual},
        {"%", Percent},
        {"+", Plus},
        {"+-", PlusMinus},
        {"/", Slash},
        {"//", SlashSlash},
        {"*", Star}
    };

    constexpr auto diff =  static_cast<int>(Float32) - static_cast<int>(Assign);
    ASSERT_EQ(operators.size(), diff);

    for(const auto& [op, type] : operators)
    {
        Fermi::Lexer s{op};
        std::vector<Fermi::Token> tokens = s.scanTokens(); 
        std::vector<Fermi::Token> expectedTokens 
        {
            Fermi::Token{.type = type, .line = 1, .lexeme = op, .literal = ""},
            Fermi::Token{.type = Fermi::TokenType::FermiEOF, .line = 1, .lexeme = "$", .literal = ""}
        };
        EXPECT_EQ(expectedTokens, tokens);
    }
}