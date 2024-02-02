#include <sstream>

#include <gtest/gtest.h>

#include "FermiLexer.hpp"
#include "TestLexerHelpers.hpp"

using namespace Fermi::LexicalAnalysis;

TEST(TestFermiLexer, TestLexIntegerLiterals)
{
    {
        SCOPED_TRACE("TestLexIntegerLiterals");
        testSingleString("1234567890987654321", FermiTokenKind::IntegerLiteral);
    }
}

TEST(TestFermiLexer, TestLexFloatLiterals)
{
    {
        SCOPED_TRACE("TestLexFloatLiterals");
        testSingleString(".0123456789", FermiTokenKind::FloatLiteral);
    }

    {
        SCOPED_TRACE("TestLexFloatLiterals");
        testSingleString("123456789.0123456789", FermiTokenKind::FloatLiteral);
    }
}