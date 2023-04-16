#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include "FermiLexer.hpp"
#include "FermiSourceFile.hpp"

#include "ExpressionNodes.hpp"
#include "StatementNodes.hpp"

using namespace Fermi::SyntaxAnalysis;

TEST(TestParser, TestPrintIntegerLiterals)
{
    std::string statement = "print(1, 2, 3);";

    std::stringstream ss{statement};
    FermiSourceFile srcFile{"Test1"};
    FermiLexer lexer1{ss};
    FermiParser parser{srcFile, lexer1};
    
    EXPECT_EQ(parser.parse(), 0);

    // Build expected syntax tree
    std::vector<std::shared_ptr<ExpressionNode>> expressions;
    expressions.push_back(std::make_shared<LiteralExpressionNode>("1", LiteralType::Integer));
    expressions.push_back(std::make_shared<LiteralExpressionNode>("2", LiteralType::Integer));
    expressions.push_back(std::make_shared<LiteralExpressionNode>("3", LiteralType::Integer));
    
    std::vector<std::shared_ptr<StatementNode>> statements;
    statements.push_back(std::make_shared<PrintStatementNode>(expressions));

    FermiStatementNode node{statements};

    EXPECT_EQ(srcFile.getTree(), node);
}

TEST(TestParser, TestPrintFloatLiterals)
{
    std::string statement = "print(1.1, 2, 0.6672);";

    std::stringstream ss{statement};
    FermiSourceFile srcFile{"Test1"};
    FermiLexer lexer1{ss};
    FermiParser parser{srcFile, lexer1};

    EXPECT_EQ(parser.parse(), 0);

    //Build expected syntax tree 
     std::vector<std::shared_ptr<ExpressionNode>> expressions;
    expressions.push_back(std::make_shared<LiteralExpressionNode>("1.1", LiteralType::Float));
    expressions.push_back(std::make_shared<LiteralExpressionNode>("2", LiteralType::Integer));
    expressions.push_back(std::make_shared<LiteralExpressionNode>("0.6672", LiteralType::Float));
    
    std::vector<std::shared_ptr<StatementNode>> statements;
    statements.push_back(std::make_shared<PrintStatementNode>(expressions));

    FermiStatementNode node{statements};

    EXPECT_EQ(srcFile.getTree(), node);
}

TEST(TestParser, TestPrintMixedLiterals)
{
    std::string statement = "print(1.1, 2, 0.6672, var1);";

    std::stringstream ss{statement};
    FermiSourceFile srcFile{"Test1"};
    FermiLexer lexer{ss};
    FermiParser parser{srcFile, lexer};

    EXPECT_EQ(parser.parse(), 0);

    //Build expected syntax tree 
     std::vector<std::shared_ptr<ExpressionNode>> expressions;
    expressions.push_back(std::make_shared<LiteralExpressionNode>("1.1", LiteralType::Float));
    expressions.push_back(std::make_shared<LiteralExpressionNode>("2", LiteralType::Integer));
    expressions.push_back(std::make_shared<LiteralExpressionNode>("0.6672", LiteralType::Float));
    expressions.push_back(std::make_shared<LiteralExpressionNode>("var1", LiteralType::Identifier));
    
    std::vector<std::shared_ptr<StatementNode>> statements;
    statements.push_back(std::make_shared<PrintStatementNode>(expressions));

    FermiStatementNode node{statements};

    EXPECT_EQ(srcFile.getTree(), node);
}