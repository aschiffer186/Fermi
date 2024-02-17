add_executable(TestNumberLiterals TestNumberLiterals.cpp)
add_test(NAME NumberLiteralsTest COMMAND TestNumberLiterals)
target_link_libraries(TestNumberLiterals PRIVATE Scanner GTest::gtest_main)
target_include_directories(TestNumberLiterals PRIVATE ${CMAKE_SOURCE_DIR}/Lexical-Analysis)

add_executable(TestStringLiterals TestStringLiterals.cpp)
add_test(NAME StringLiteralsTest COMMAND TestStringLiterals)
target_link_libraries(TestStringLiterals PRIVATE Scanner GTest::gtest_main)
target_include_directories(TestStringLiterals PRIVATE ${CMAKE_SOURCE_DIR}/Lexical-Analysis)

add_executable(TestIdentifierKeywords TestIdentifierKeywords.cpp)
add_test(NAME IdentifierKeywordsTest COMMAND TestIdentifierKeywords)
target_link_libraries(TestIdentifierKeywords PRIVATE Scanner GTest::gtest_main)
target_include_directories(TestIdentifierKeywords PRIVATE ${CMAKE_SOURCE_DIR}/Lexical-Analysis)

add_executable(TestOperators TestOperators.cpp)
add_test(NAME OperatorsTest COMMAND TestOperators)
target_link_libraries(TestOperators PRIVATE Scanner GTest::gtest_main)
target_include_directories(TestOperators PRIVATE ${CMAKE_SOURCE_DIR}/Lexical-Analysis)