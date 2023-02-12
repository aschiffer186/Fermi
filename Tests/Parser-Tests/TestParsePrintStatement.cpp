#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include "FermiLexer.hpp"
#include "FermiSourceFile.hpp"

#include "ExpressionNode.hpp"
#include "StatementNode.hpp"

using namespace Fermi::SyntaxAnalysis;

TEST(TestParser, TestPrintIntegerLiterals)
{
    std::string statement = "print(1, 2, 3);";

    std::stringstream ss{statement};
    FermiSourceFile srcFile{"Test1", ss};

    FermiParser parser{srcFile};
    
    EXPECT_EQ(parser.parse(), 0);

    // Build expected syntax tree
    std::vector<std::shared_ptr<ExpressionNode>> expressions;
    expressions.push_back(std::make_shared<LiteralNode>("1", LiteralType::Integer));
    expressions.push_back(std::make_shared<LiteralNode>("2", LiteralType::Integer));
    expressions.push_back(std::make_shared<LiteralNode>("3", LiteralType::Integer));
    
    std::vector<std::shared_ptr<StatementNode>> statements;
    statements.push_back(std::make_shared<PrintNode>(expressions));

    FermiNode node{statements};

    EXPECT_EQ(*srcFile.syntaxTree, node);
}

TEST(TestParser, TestPrintFloatLiterals)
{
    std::string statement = "print(1.1, 2, 0.6672);";

    std::stringstream ss{statement};
    FermiSourceFile srcFile{"Test1", ss};

    FermiParser parser{srcFile};

    EXPECT_EQ(parser.parse(), 0);

    //Build expected syntax tree 
     std::vector<std::shared_ptr<ExpressionNode>> expressions;
    expressions.push_back(std::make_shared<LiteralNode>("1.1", LiteralType::Float));
    expressions.push_back(std::make_shared<LiteralNode>("2", LiteralType::Integer));
    expressions.push_back(std::make_shared<LiteralNode>("0.6672", LiteralType::Float));
    
    std::vector<std::shared_ptr<StatementNode>> statements;
    statements.push_back(std::make_shared<PrintNode>(expressions));

    FermiNode node{statements};

    EXPECT_EQ(*srcFile.syntaxTree, node);
}

TEST(TestParser, TestPrintMixedLiterals)
{
    std::string statement = "print(1.1, 2, 0.6672, var1);";

    std::stringstream ss{statement};
    FermiSourceFile srcFile{"Test1", ss};

    FermiParser parser{srcFile};

    EXPECT_EQ(parser.parse(), 0);

    //Build expected syntax tree 
     std::vector<std::shared_ptr<ExpressionNode>> expressions;
    expressions.push_back(std::make_shared<LiteralNode>("1.1", LiteralType::Float));
    expressions.push_back(std::make_shared<LiteralNode>("2", LiteralType::Integer));
    expressions.push_back(std::make_shared<LiteralNode>("0.6672", LiteralType::Float));
    expressions.push_back(std::make_shared<LiteralNode>("var1", LiteralType::Identifier));
    
    std::vector<std::shared_ptr<StatementNode>> statements;
    statements.push_back(std::make_shared<PrintNode>(expressions));

    FermiNode node{statements};

    EXPECT_EQ(*srcFile.syntaxTree, node);
}