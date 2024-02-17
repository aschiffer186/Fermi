#include <gtest/gtest.h>

#include "Scanner.hh" 

TEST(TestLexer, TestLexSpaces)
{
    using enum Fermi::TokenType;

    const std::string test1 = "let a +b    = 32;  ";
    Fermi::Lexer scanner{test1};
    std::vector<Fermi::Token> tokens = scanner.scanTokens();
    std::vector<Fermi::Token> expectedTokens
    {
        Fermi::Token{.type=Let,        .line=1, .lexeme="let", .literal=""},
        Fermi::Token{.type=Identifier, .line=1, .lexeme="a",   .literal=""},
        Fermi::Token{.type=Plus,       .line=1, .lexeme="+",   .literal=""},
        Fermi::Token{.type=Identifier, .line=1, .lexeme="b",   .literal=""},
        Fermi::Token{.type=Assign,     .line=1, .lexeme="=",   .literal=""},
        Fermi::Token{.type=Integer,    .line=1, .lexeme="32",  .literal="32"},
        Fermi::Token{.type=Semicolon,  .line=1, .lexeme=";",   .literal=""},
        Fermi::Token{.type=FermiEOF,   .line=1, .lexeme="$",   .literal=""}
    };
    EXPECT_EQ(expectedTokens, tokens);

    const std::string test2 = "   let a +b    = 32;";
    Fermi::Lexer scanner2{test2};
    tokens = scanner2.scanTokens();
    EXPECT_EQ(expectedTokens, tokens);
}

TEST(TestLexer, TestLexNewlines)
{
    using enum Fermi::TokenType;

    const std::string test1 = "let a+ b\n"
                              "  = 32;\n";
    Fermi::Lexer scanner{test1};
    std::vector<Fermi::Token> tokens = scanner.scanTokens();
    std::vector<Fermi::Token> expectedTokens
    {
        Fermi::Token{.type=Let,        .line=1, .lexeme="let", .literal=""},
        Fermi::Token{.type=Identifier, .line=1, .lexeme="a",   .literal=""},
        Fermi::Token{.type=Plus,       .line=1, .lexeme="+",   .literal=""},
        Fermi::Token{.type=Identifier, .line=1, .lexeme="b",   .literal=""},
        Fermi::Token{.type=Assign,     .line=2, .lexeme="=",   .literal=""},
        Fermi::Token{.type=Integer,    .line=2, .lexeme="32",  .literal="32"},
        Fermi::Token{.type=Semicolon,  .line=2, .lexeme=";",   .literal=""},
        Fermi::Token{.type=FermiEOF,   .line=3, .lexeme="$",   .literal=""}
    };
    EXPECT_EQ(expectedTokens, tokens);    
}

TEST(TestLexer, TestLexComment)
{
    using enum Fermi::TokenType; 
    const std::string test1 = "#This is a comment and\n"
                              "#it is continuing onto another line\n"
                              "let a+ b\n"
                              "  = 32;\n";
    Fermi::Lexer scanner{test1};
    std::vector<Fermi::Token> tokens = scanner.scanTokens();
    std::vector<Fermi::Token> expectedTokens
    {
        Fermi::Token{.type=Let,        .line=3, .lexeme="let", .literal=""},
        Fermi::Token{.type=Identifier, .line=3, .lexeme="a",   .literal=""},
        Fermi::Token{.type=Plus,       .line=3, .lexeme="+",   .literal=""},
        Fermi::Token{.type=Identifier, .line=3, .lexeme="b",   .literal=""},
        Fermi::Token{.type=Assign,     .line=4, .lexeme="=",   .literal=""},
        Fermi::Token{.type=Integer,    .line=4, .lexeme="32",  .literal="32"},
        Fermi::Token{.type=Semicolon,  .line=4, .lexeme=";",   .literal=""},
        Fermi::Token{.type=FermiEOF,   .line=5, .lexeme="$",   .literal=""}
    };
    EXPECT_EQ(expectedTokens, tokens); 
}

TEST(TestLexer, TestLexEmpty)
{
    const std::string test1 = "";

    Fermi::Lexer scanner{test1};
    std::vector<Fermi::Token> tokens = scanner.scanTokens();
    std::vector<Fermi::Token> expectedTokens
    {
        Fermi::Token{.type=Fermi::TokenType::FermiEOF, .line=1, .lexeme="$", .literal=""}
    };

    const std::string test2 = "       \n\n\n   \n";
    Fermi::Lexer scanner2{test2};
    tokens = scanner.scanTokens();
    expectedTokens  =
    {
        Fermi::Token{.type=Fermi::TokenType::FermiEOF, .line=5, .lexeme="$", .literal=""}
    };

}