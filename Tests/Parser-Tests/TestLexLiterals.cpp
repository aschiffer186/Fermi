#include <sstream>

#include <gtest/gtest.h>

#include "FermiLexer.hpp"

using namespace Fermi::SyntaxAnalysis;
using SymbolKindType = FermiParser::symbol_kind::symbol_kind_type;


TEST(TestLexer, TestLexIntegers)
{
    std::string testString1 = "1";
    std::stringstream testStream1{testString1};
    
    FermiLexer lexer1{testStream1};
    auto token1 = lexer1.nextToken();

    EXPECT_EQ(token1.kind(), SymbolKindType::S_INTEGER_LITERAL);
    EXPECT_STREQ(token1.value.as<std::string>().c_str(), testString1.c_str());
    EXPECT_EQ(token1.location.begin.column, 1);
    EXPECT_EQ(token1.location.begin.line, 1);
    EXPECT_EQ(token1.location.end.column, testString1.length() + 1);
    EXPECT_EQ(token1.location.end.line, 1);

    std::string testString2 = "1234567890";
    std::stringstream testStream2{testString2};
    
    FermiLexer lexer2{testStream2};
    auto token2 = lexer2.nextToken();

    EXPECT_EQ(token2.kind(), SymbolKindType::S_INTEGER_LITERAL);
    EXPECT_STREQ(token2.value.as<std::string>().c_str(), testString2.c_str());
    EXPECT_EQ(token2.location.begin.column, 1);
    EXPECT_EQ(token2.location.begin.line, 1);
    EXPECT_EQ(token2.location.end.column, testString2.length() + 1);
    EXPECT_EQ(token2.location.end.line, 1);
}

TEST(TestLexer, TestLexFloatingPoint)
{
    std::string testString1 = ".1234567890";
    std::stringstream testStream1{testString1};

    FermiLexer lexer1{testStream1};
    auto token1 = lexer1.nextToken();

    EXPECT_EQ(token1.kind(), SymbolKindType::S_FLOAT_LITERAL);
    EXPECT_STREQ(token1.value.as<std::string>().c_str(), testString1.c_str());
    EXPECT_EQ(token1.location.begin.column, 1);
    EXPECT_EQ(token1.location.begin.line, 1);
    EXPECT_EQ(token1.location.end.column, testString1.length() + 1);
    EXPECT_EQ(token1.location.end.line, 1);

    std::string testString2 = "1234567890.9876543210";
    std::stringstream testStream2{testString2};

    FermiLexer lexer2{testStream2};
    auto token2 = lexer2.nextToken();

    EXPECT_EQ(token2.kind(), SymbolKindType::S_FLOAT_LITERAL);
    EXPECT_STREQ(token2.value.as<std::string>().c_str(), testString2.c_str());
    EXPECT_EQ(token2.location.begin.column, 1);
    EXPECT_EQ(token2.location.begin.line, 1);
    EXPECT_EQ(token2.location.end.column, testString2.length() + 1);
    EXPECT_EQ(token2.location.end.line, 1);

    std::string testString3 = "1234567890.9876543210e1234567890";
    std::stringstream testStream3{testString3};

    FermiLexer lexer3{testStream3};
    auto token3 = lexer3.nextToken();

    EXPECT_EQ(token3.kind(), SymbolKindType::S_FLOAT_LITERAL);
    EXPECT_STREQ(token3.value.as<std::string>().c_str(), testString3.c_str());
    EXPECT_EQ(token3.location.begin.column, 1);
    EXPECT_EQ(token3.location.begin.line, 1);
    EXPECT_EQ(token3.location.end.column, testString3.length() + 1);
    EXPECT_EQ(token3.location.end.line, 1);

    std::string testString4 = "1234567890.9876543210E1234567890";
    std::stringstream testStream4{testString4};

    FermiLexer lexer4{testStream4};
    auto token4 = lexer4.nextToken();

    EXPECT_EQ(token4.kind(), SymbolKindType::S_FLOAT_LITERAL);
    EXPECT_STREQ(token4.value.as<std::string>().c_str(), testString4.c_str());
    EXPECT_EQ(token4.location.begin.column, 1);
    EXPECT_EQ(token4.location.begin.line, 1);
    EXPECT_EQ(token4.location.end.column, testString4.length() + 1);
    EXPECT_EQ(token4.location.end.line, 1);

    std::string testString5 = "1234567890.9876543210e+1234567890";
    std::stringstream testStream5{testString5};

    FermiLexer lexer5{testStream5};
    auto token5 = lexer5.nextToken();

    EXPECT_EQ(token5.kind(), SymbolKindType::S_FLOAT_LITERAL);
    EXPECT_STREQ(token5.value.as<std::string>().c_str(), testString5.c_str());
    EXPECT_EQ(token5.location.begin.column, 1);
    EXPECT_EQ(token5.location.begin.line, 1);
    EXPECT_EQ(token5.location.end.column, testString5.length() + 1);
    EXPECT_EQ(token5.location.end.line, 1);

    std::string testString6 = "1234567890.9876543210e-1234567890";
    std::stringstream testStream6{testString6};

    FermiLexer lexer6{testStream6};
    auto token6 = lexer6.nextToken();

    EXPECT_EQ(token6.kind(), SymbolKindType::S_FLOAT_LITERAL);
    EXPECT_STREQ(token6.value.as<std::string>().c_str(), testString6.c_str());
    EXPECT_EQ(token6.location.begin.column, 1);
    EXPECT_EQ(token6.location.begin.line, 1);
    EXPECT_EQ(token6.location.end.column, testString6.length() + 1);
    EXPECT_EQ(token6.location.end.line, 1);

}