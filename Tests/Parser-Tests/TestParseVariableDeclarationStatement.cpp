#include <sstream>

#include <gtest/gtest.h>

#include "FermiSourceFile.hpp"
#include "FermiLexer.hpp"
#include "FermiParser.hpp"

using namespace Fermi::SyntaxAnalysis;

TEST(TestParser, TestParseVariableDeclarationNoInitializer)
{
    std::string varDecl1 = "let xyz123 : int8_t;";
    std::istringstream ss1{varDecl1};

    FermiSourceFile srcFile1("Test Var Decl1");
    FermiLexer lexer1{ss1};
    FermiParser parser1{srcFile1, lexer1};

    ASSERT_EQ(parser1.parse(), 0);

    auto variableDeclarationNode = std::make_shared<VariableDeclarationStatementNode>(Type::int8_t, "xyz123");
    FermiStatementNode node1{{variableDeclarationNode}};

    EXPECT_EQ(srcFile1.getTree(), node1);

    std::string varDecl2 = "let xyz123 : int16_t = 10;";
    std::istringstream ss2{varDecl2};

    FermiSourceFile srcFile2{"Test Var Decl2"};
    FermiLexer lexer2{ss2};
    FermiParser parser2{srcFile2, lexer2};
    
    ASSERT_EQ(parser2.parse(), 0);

    auto initializerNode = std::make_shared<LiteralExpressionNode>("10", LiteralType::Integer);
    variableDeclarationNode = std::make_shared<VariableDeclarationStatementNode>(Type::int16_t, "xyz123", initializerNode);
    FermiStatementNode node2{{variableDeclarationNode}};

    EXPECT_EQ(srcFile2.getTree(), node2);

    std::string varDecl3 = "let xyz123 = 11.2345;";
    std::istringstream ss3{varDecl3};

    FermiSourceFile srcFile3{"Test Var Decl3"};
    FermiLexer lexer3{ss3};
    FermiParser parser3{srcFile3, lexer3};

    ASSERT_EQ(parser3.parse(), 0);

    initializerNode = std::make_shared<LiteralExpressionNode>("11.2345", LiteralType::Float);
    variableDeclarationNode = std::make_shared<VariableDeclarationStatementNode>(Type::deduced, "xyz123", initializerNode);

    FermiStatementNode node3{{variableDeclarationNode}};
    EXPECT_EQ(srcFile3.getTree(), node3);
}