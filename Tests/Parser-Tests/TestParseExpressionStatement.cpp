#include <iostream>

#include <gtest/gtest.h>

#include "FermiSourceFile.hpp"
#include "FermiParser.hpp"

using namespace Fermi::SyntaxAnalysis;

TEST(TestParser, TestExpressionStatementLiterals)
{
    std::string integerLiteral = "123456789;";
    std::istringstream ss1{integerLiteral};

    FermiSourceFile srcFile1{"Test 1", ss1};
    FermiParser parser1{srcFile1};

    ASSERT_EQ(parser1.parse(), 0);

    std::shared_ptr<ExpressionNode> exp = std::make_shared<LiteralNode>("123456789", LiteralType::Integer);
    std::shared_ptr<StatementNode> stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode root{{stmt}};

    EXPECT_EQ(root, *srcFile1.syntaxTree);

    std::string floatLiteral = "1234567890.9876543210e-1234567890;";
    std::istringstream ss2{floatLiteral};

    FermiSourceFile srcFile2{"Test 2", ss2};
    FermiParser parser2{srcFile2};

    ASSERT_EQ(parser2.parse(), 0);

    exp = std::make_shared<LiteralNode>("1234567890.9876543210e-1234567890", LiteralType::Float);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode root2{{stmt}};

    EXPECT_EQ(root2, *srcFile2.syntaxTree);

    std::string identifier = "abcdefg;";
    std::istringstream ss3{identifier};

    FermiSourceFile srcFile3{"Test 3", ss3};
    FermiParser parse3{srcFile3};

    exp = std::make_shared<LiteralNode>("abcdefg", LiteralType::Identifier);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode root3{{stmt}};
}

TEST(TestParser, TestParseBinaryExpressions)
{
    std::string binaryAddition = "x + y;";
    std::istringstream ss1{binaryAddition};
    FermiSourceFile srcFile1{"Binary Addition Test", ss1};
    FermiParser parser1{srcFile1};

    ASSERT_EQ(parser1.parse(), 0);

    std::shared_ptr<ExpressionNode> lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    std::shared_ptr<ExpressionNode> rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    std::shared_ptr<ExpressionNode> exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Addition, rhs);
    std::shared_ptr<StatementNode> stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node1{{stmt}};

    EXPECT_EQ(*srcFile1.syntaxTree, node1);
}