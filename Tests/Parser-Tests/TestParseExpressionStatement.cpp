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

    std::string binarySubtraction = "x - y;";
    std::istringstream ss2{binarySubtraction};
    FermiSourceFile srcFile2{"Binary Subtraction Test", ss2};
    FermiParser parser2{srcFile2};

    ASSERT_EQ(parser2.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Subtraction, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node2{{stmt}};

    EXPECT_EQ(*srcFile2.syntaxTree, node2);

    std::string binaryMultiplication = "x * y;";
    std::istringstream ss3{binaryMultiplication};
    FermiSourceFile srcFile3{"Binary Multiplication Test", ss3};
    FermiParser parser3{srcFile3};

    ASSERT_EQ(parser3.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Multiplication, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node3{{stmt}};

    EXPECT_EQ(*srcFile3.syntaxTree, node3);

    std::string binaryDivision = "x / y;";
    std::istringstream ss4{binaryDivision};
    FermiSourceFile srcFile4{"Binary Division Test", ss4};
    FermiParser parser4{srcFile4};

    ASSERT_EQ(parser4.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Division, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node4{{stmt}};

    EXPECT_EQ(*srcFile4.syntaxTree, node4);

    std::string binaryIntegerDivision = "x // y;";
    std::istringstream ss5{binaryIntegerDivision};
    FermiSourceFile srcFile5{"Binary Integer Division Test", ss5};
    FermiParser parser5{srcFile5};

    ASSERT_EQ(parser5.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::IntegerDivision, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node5{{stmt}};

    EXPECT_EQ(*srcFile5.syntaxTree, node5);

    std::string binaryExponentiation = "x ^ y;";
    std::istringstream ss6{binaryExponentiation};
    FermiSourceFile srcFile6{"Binary Exponentiation Test", ss6};
    FermiParser parser6{srcFile6};

    ASSERT_EQ(parser6.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Exponentiation, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node6{{stmt}};

    EXPECT_EQ(*srcFile6.syntaxTree, node6);

    std::string binaryModulo = "x % y;";
    std::istringstream ss7{binaryModulo};
    FermiSourceFile srcFile7{"Binary Modulo Test", ss7};
    FermiParser parser7{srcFile7};

    ASSERT_EQ(parser7.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Modulo, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node7{{stmt}};

    EXPECT_EQ(*srcFile7.syntaxTree, node7);
}

TEST(TestParser, TestBinaryExpressionPrecedenceHandling)
{
    std::string test = "x + z*y*z - x/y/z + 3*2^4^x - 3 + 2 % z;";
    std::istringstream ss{test};
    FermiSourceFile srcFile{"Precedence Test", ss};
    FermiParser parser{srcFile};

    ASSERT_EQ(parser.parse(), 0);

    auto term1 = std::make_shared<LiteralNode>("x", LiteralType::Identifier);

   
}