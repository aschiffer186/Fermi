find_package(FLEX REQUIRED)

set(SYNTAX_ANALYSIS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SYNTAX_ANALYSIS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)


FLEX_TARGET(
    FermiLexer
    ${SYNTAX_ANALYSIS_INCLUDE_DIR}/FermiLexer.ll
    ${SYNTAX_ANALYSIS_SRC_DIR}/FermiLexer.cpp
)

add_library(FermiSyntaxAnalysis STATIC ${FLEX_FermiLexer_OUTPUTS})
target_include_directories(FermiSyntaxAnalysis PUBLIC ${SYNTAX_ANALYSIS_INCLUDE_DIR})