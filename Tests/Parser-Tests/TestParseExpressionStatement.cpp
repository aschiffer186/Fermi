#include <iostream>

#include <gtest/gtest.h>

#include "FermiSourceFile.hpp"
#include "FermiParser.hpp"

using namespace Fermi::SyntaxAnalysis;

TEST(TestParser, TestExpressionStatementLiterals)
{
    std::string integerLiteral = "123456789;";
    std::istringstream ss1{integerLiteral};

    FermiSourceFile srcFile1{"Test 1"};
    FermiLexer lexer1{ss1};
    FermiParser parser1{srcFile1, lexer1};

    ASSERT_EQ(parser1.parse(), 0);

    std::shared_ptr<ExpressionNode> exp = std::make_shared<LiteralNode>("123456789", LiteralType::Integer);
    std::shared_ptr<StatementNode> stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode root{{stmt}};

    EXPECT_EQ(root, srcFile1.getTree());

    std::string floatLiteral = "1234567890.9876543210e-1234567890;";
    std::istringstream ss2{floatLiteral};

    FermiSourceFile srcFile2{"Test 2"};
    FermiLexer lexer2{ss2};
    FermiParser parser2{srcFile2, lexer2};

    ASSERT_EQ(parser2.parse(), 0);

    exp = std::make_shared<LiteralNode>("1234567890.9876543210e-1234567890", LiteralType::Float);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode root2{{stmt}};

    EXPECT_EQ(root2, srcFile2.getTree());

    std::string identifier = "abcdefg;";
    std::istringstream ss3{identifier};

    FermiSourceFile srcFile3{"Test 3"};
    FermiLexer lexer3{ss3};
    FermiParser parse3{srcFile3, lexer3};

    exp = std::make_shared<LiteralNode>("abcdefg", LiteralType::Identifier);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode root3{{stmt}};
}

TEST(TestParser, TestParseBinaryExpressions)
{
    std::string binaryAddition = "x + y;";
    std::istringstream ss1{binaryAddition};
    FermiSourceFile srcFile1{"Binary Addition Test"};
    FermiLexer lexer1{ss1};
    FermiParser parser1{srcFile1, lexer1};

    ASSERT_EQ(parser1.parse(), 0);

    std::shared_ptr<ExpressionNode> lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    std::shared_ptr<ExpressionNode> rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    std::shared_ptr<ExpressionNode> exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Addition, rhs);
    std::shared_ptr<StatementNode> stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node1{{stmt}};

    EXPECT_EQ(srcFile1.getTree(), node1);

    std::string binarySubtraction = "x - y;";
    std::istringstream ss2{binarySubtraction};
    FermiSourceFile srcFile2{"Binary Subtraction Test"};
    FermiLexer lexer2{ss2};
    FermiParser parser2{srcFile2, lexer2};

    ASSERT_EQ(parser2.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Subtraction, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node2{{stmt}};

    EXPECT_EQ(srcFile2.getTree(), node2);

    std::string binaryMultiplication = "x * y;";
    std::istringstream ss3{binaryMultiplication};
    FermiSourceFile srcFile3{"Binary Multiplication Test"};
    FermiLexer lexer3{ss3};
    FermiParser parser3{srcFile3, lexer3};

    ASSERT_EQ(parser3.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Multiplication, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node3{{stmt}};

    EXPECT_EQ(srcFile3.getTree(), node3);

    std::string binaryDivision = "x / y;";
    std::istringstream ss4{binaryDivision};
    FermiSourceFile srcFile4{"Binary Division Test"};
    FermiLexer lexer4{ss4};
    FermiParser parser4{srcFile4, lexer4};

    ASSERT_EQ(parser4.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Division, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node4{{stmt}};

    EXPECT_EQ(srcFile4.getTree(), node4);

    std::string binaryIntegerDivision = "x // y;";
    std::istringstream ss5{binaryIntegerDivision};
    FermiSourceFile srcFile5{"Binary Integer Division Test"};
    FermiLexer lexer5{ss5};
    FermiParser parser5{srcFile5, lexer5};

    ASSERT_EQ(parser5.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::IntegerDivision, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node5{{stmt}};

    EXPECT_EQ(srcFile5.getTree(), node5);

    std::string binaryExponentiation = "x ^ y;";
    std::istringstream ss6{binaryExponentiation};
    FermiSourceFile srcFile6{"Binary Exponentiation Test"};
    FermiLexer lexer6{ss6};
    FermiParser parser6{srcFile6, lexer6};

    ASSERT_EQ(parser6.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Exponentiation, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node6{{stmt}};

    EXPECT_EQ(srcFile6.getTree(), node6);

    std::string binaryModulo = "x % y;";
    std::istringstream ss7{binaryModulo};
    FermiSourceFile srcFile7{"Binary Modulo Test"};
    FermiLexer lexer7{ss7};
    FermiParser parser7{srcFile7, lexer7};

    ASSERT_EQ(parser7.parse(), 0);

    lhs = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    exp = std::make_shared<BinaryExpressionNode>(lhs, BinaryExpressionTypes::Modulo, rhs);
    stmt = std::make_shared<ExpressionStatementNode>(exp);
    FermiNode node7{{stmt}};

    EXPECT_EQ(srcFile7.getTree(), node7);
}

TEST(TestParser, TestBinaryExpressionPrecedenceHandling)
{
    std::string test = "x + z*y*z - x/y/z + 3*2^4^x - 3 + 2 % z;";
    std::istringstream ss{test};
    FermiSourceFile srcFile{"Precedence Test"};
    FermiLexer lexer{ss};
    FermiParser parser{srcFile, lexer};

    ASSERT_TRUE(srcFile.parsedSuccessfully());

    //x
    auto term1 = std::make_shared<LiteralNode>("x", LiteralType::Identifier);
    
    //z*y 
    auto fac1 = std::make_shared<BinaryExpressionNode>(std::make_shared<LiteralNode>("z", LiteralType::Identifier),
        BinaryExpressionTypes::Multiplication,
        std::make_shared<LiteralNode>("y", LiteralType::Identifier));
    auto term2 = std::make_shared<BinaryExpressionNode>(fac1, 
        BinaryExpressionTypes::Multiplication, 
        std::make_shared<LiteralNode>("z", LiteralType::Identifier));
   
}