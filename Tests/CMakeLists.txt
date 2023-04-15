enable_testing()

find_package(GTest REQUIRED)
include(CTest)

add_subdirectory(SyntaxAnalysisTests)