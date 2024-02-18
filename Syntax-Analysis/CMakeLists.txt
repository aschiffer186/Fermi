add_subdirectory(SyntaxTree)

add_library(Parser Parser.cpp)
target_link_libraries(Parser PRIVATE Syntax-Tree Scanner)