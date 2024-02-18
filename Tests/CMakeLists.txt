enable_testing()

include(CTest)
find_package(GTest REQUIRED)

add_subdirectory(Lexical-Analysis)
add_subdirectory(Syntax-Analysis)