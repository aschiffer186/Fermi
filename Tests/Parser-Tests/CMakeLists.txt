macro(create_parser_test TARGET_NAME SOURCE_FILE)
    add_executable(${TARGET_NAME} EXCLUDE_FROM_ALL ${SOURCE_FILE})
    add_dependencies(build_tests ${TARGET_NAME})
    target_link_libraries(${TARGET_NAME} PRIVATE FermiParser GTest::gtest_main)
    target_compile_features(${TARGET_NAME} PRIVATE cxx_std_20)
    gtest_discover_tests(${TARGET_NAME})
endmacro()

create_parser_test(TestLexKeywords TestLexKeywords.cpp)
create_parser_test(TestLexLiterals TestLexLiterals.cpp)
create_parser_test(TestLexOperators TestLexOperators.cpp)
create_parser_test(TestLexMultiTokens TestLexMultiTokens.cpp)

create_parser_test(TestParseAssignmentStatement TestParseAssignmentStatement.cpp)
create_parser_test(TestParsePrintStatement TestParsePrintStatement.cpp)
create_parser_test(TestParseExpressionStatement TestParseExpressionStatement.cpp)
create_parser_test(TestParseVariableDeclarationStatement TestParseVariableDeclarationStatement.cpp)