#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include "FermiParser.hpp"
#include "FermiSourceFile.hpp"

#include "ExpressionNode.hpp"
#include "StatementNode.hpp"

using namespace Fermi::SyntaxAnalysis;

TEST(TestParser, TestAssignLiterals)
{
    std::string statement = "x = y;";

    std::stringstream ss{statement};
    FermiSourceFile srcFile{"Test1"};
    FermiLexer lexer{ss};

    FermiParser parser{srcFile, lexer};

    EXPECT_EQ(parser.parse(), 0);

    auto rhs = std::make_shared<LiteralExpressionNode>("y", LiteralType::Identifier);
    auto assignmentNode = std::make_shared<AssignmentStatementNode>("x", rhs);
    FermiStatementNode node{{assignmentNode}};

    EXPECT_EQ(srcFile.getTree(), node);

    std::string statement2 = "x = 1;";
    std::stringstream ss2{statement2};
    FermiLexer lexer2{ss2};
    FermiSourceFile srcFile2{"Test2"};

    FermiParser parser2{srcFile2, lexer2};

    EXPECT_EQ(parser2.parse(), 0);

    rhs = std::make_shared<LiteralExpressionNode>("1", LiteralType::Integer);
    assignmentNode = std::make_shared<AssignmentStatementNode>("x", rhs);
    FermiStatementNode node2{{assignmentNode}};

    EXPECT_EQ(srcFile2.getTree(), node2);
}