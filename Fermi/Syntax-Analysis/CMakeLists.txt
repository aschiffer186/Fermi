find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

set(PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PARSER_INCLUDE_DIR ${PARSER_DIR}/include)
set(PARSER_SOURCE_DIR ${PARSER_DIR}/src)

FLEX_TARGET(
    FermiLexer
    ${PARSER_INCLUDE_DIR}/FermiLexer.ll
    ${PARSER_SOURCE_DIR}/FermiLexer.cpp
)

BISON_TARGET(
    FermiParser
    ${PARSER_INCLUDE_DIR}/FermiParser.yy 
    ${PARSER_SOURCE_DIR}/FermiParser.cpp 
    DEFINES_FILE ${PARSER_INCLUDE_DIR}/FermiParser.hpp
    VERBOSE ${PARSER_INCLUDE_DIR}/FermiParserReport.txt
)
ADD_FLEX_BISON_DEPENDENCY(FermiLexer FermiParser)

set(SYNTAX_TREE_DIR ${PARSER_SOURCE_DIR}/Syntax-Tree)
set(SYNTAX_TREE_SOURCES 
    ${SYNTAX_TREE_DIR}/ExpressionNode.cpp
    ${SYNTAX_TREE_DIR}/StatementNode.cpp
    )

add_library(FermiParser STATIC ${BISON_FermiParser_OUTPUTS} ${FLEX_FermiLexer_OUTPUTS} ${SYNTAX_TREE_SOURCES})
target_compile_features(FermiParser PRIVATE cxx_std_20)
target_include_directories(FermiParser PUBLIC ${PARSER_INCLUDE_DIR} ${PARSER_INCLUDE_DIR}/Syntax-Tree)