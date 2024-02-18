#include <gtest/gtest.h> 

#include "Scanner.hh"
#include "Parser.hh"

using namespace Fermi;
using enum TokenType;


#define ADD_SYNTAX_NODE(val, type, ...)\
    val.emplace_back(std::in_place_type<type>, __VA_ARGS__)

TEST(TestParser, TestIdentifierExpressionStatement)
{
    std::string test = "identifier;";
    Lexer lexer{std::move(test)};
    auto toks = lexer.scanTokens();
    Fermi::Parser parser{std::move(toks)};
    auto syntaxTree = std::move(parser.parse());
    std::vector<Fermi::SyntaxNode> expectedTree;
    ADD_SYNTAX_NODE(expectedTree, IdentifierNode, "identifier");
}

TEST(TestParser, TestLiteralExressionStatement)
{
    std::string test = "123456;";
    Lexer lexer1{std::move(test)};
    auto toks = lexer1.scanTokens();
    Parser parser{std::move(toks)};
    auto syntaxTree = std::move(parser.parse()); 
    std::vector<Fermi::SyntaxNode> expectedTree; 
    ADD_SYNTAX_NODE(expectedTree, LiteralExpressionNode, Integer, "123456");

    test = "0.1234567;";
    Lexer lexer2{std::move(test)};
    toks = lexer2.scanTokens(); 
    Parser parser2{std::move(toks)};
    syntaxTree = std::move(parser.parse());
    expectedTree.clear();
    ADD_SYNTAX_NODE(expectedTree, LiteralExpressionNode, FloatingPoint, "0.1234567");
}

TEST(TestParser, TestOrExpressionStatement)
{
    std::string test = "a or b;";
    Lexer lexer{std::move(test)};
    auto toks = lexer.scanTokens();
    Parser parser{std::move(toks)};
    auto syntaxTree = std::move(parser.parse());
    std::vector<Fermi::SyntaxNode> expectedSyntaxTree;
    ADD_SYNTAX_NODE(expectedSyntaxTree, IdentifierNode, "a");
    ADD_SYNTAX_NODE(expectedSyntaxTree, IdentifierNode, "b");
    ADD_SYNTAX_NODE(expectedSyntaxTree, BinaryExpressionNode, 0, Or, 1);
}

TEST(TestParser, TestAndExpressionStatement)
{
    std::string test = "a and b;";
    Lexer lexer{std::move(test)};
    auto toks = lexer.scanTokens();
    Parser parser{std::move(toks)};
    auto syntaxTree = std::move(parser.parse());
    std::vector<Fermi::SyntaxNode> expectedSyntaxTree;
    ADD_SYNTAX_NODE(expectedSyntaxTree, IdentifierNode, "a");
    ADD_SYNTAX_NODE(expectedSyntaxTree, IdentifierNode, "b");
    ADD_SYNTAX_NODE(expectedSyntaxTree, BinaryExpressionNode, 0, And, 1);
}