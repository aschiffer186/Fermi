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

    FermiSourceFile srcFile1("Test Var Decl1", ss1);
    FermiParser parser1{srcFile1};

    ASSERT_EQ(parser1.parse(), 0);

    auto variableDeclarationNode = std::make_shared<VariableDeclarationNode>(Type::int8_t, "xyz123");
    FermiNode node1{{variableDeclarationNode}};

    EXPECT_EQ(*srcFile1.syntaxTree, node1);
}