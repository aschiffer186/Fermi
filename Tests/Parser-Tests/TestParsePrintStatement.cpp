#include <sstream>

#include <gtest/gtest.h>

#include "FermiLexer.hpp"
#include "FermiParser.hpp"

using namespace Fermi::SyntaxAnalysis;

TEST(TestParser, TestPrintIntegerLiterals)
{
    std::string statement = "print(1, 2, 3);";

    std::stringstream ss{statement};
    FermiLexer lexer{ss};
    FermiParser parser{lexer};
    
    EXPECT_EQ(parser.parse(), 0);
}