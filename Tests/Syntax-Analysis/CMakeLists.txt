add_executable(TestExpressionStatement TestExpressionStatement.cpp)
add_test(NAME ExpressionStatementTest COMMAND TestExpressionStatement)
target_link_libraries(TestExpressionStatement PRIVATE Scanner Parser GTest::gtest_main)
target_include_directories(TestExpressionStatement PRIVATE ${CMAKE_SOURCE_DIR}/Lexical-Analysis
                                                           ${CMAKE_SOURCE_DIR}/Syntax-Analysis)