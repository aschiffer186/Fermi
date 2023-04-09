find_package(FLEX REQUIRED)

set(PARSER_INCLUDE_DIR ${PARSER_DIR}/include)
set(PARSER_SOURCE_DIR ${PARSER_DIR}/src)

FLEX_TARGET(
    FermiLexer
    ${PARSER_INCLUDE_DIR}/FermiLexer.ll
    ${PARSER_SOURCE_DIR}/FermiLexer.cpp
)