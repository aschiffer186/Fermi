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
    FermiSourceFile srcFile{"Test1", ss};

    FermiParser parser{srcFile};

    EXPECT_EQ(parser.parse(), 0);

    auto rhs = std::make_shared<LiteralNode>("y", LiteralType::Identifier);
    auto assignmentNode = std::make_shared<AssignmentStatementNode>("x", rhs);
    FermiNode node{{assignmentNode}};

    EXPECT_EQ(*srcFile.syntaxTree, node);

    std::string statement2 = "x = 1;";
    std::stringstream ss2{statement2};

    FermiSourceFile srcFile2{"Test2", ss};

    FermiParser parser2{srcFile2};

    EXPECT_EQ(parser2.parse(), 0);

    rhs = std::make_shared<LiteralNode>("1", LiteralType::Identifier);
    assignmentNode = std::make_shared<AssignmentStatementNode>("x", rhs);
    FermiNode node2{{assignmentNode}};

    EXPECT_EQ(*srcFile2.syntaxTree, node2);
}