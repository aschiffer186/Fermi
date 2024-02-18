add_library(Syntax-Tree INTERFACE ExpressionNodes.hh)
target_include_directories(Syntax-Tree INTERFACE ${CMAKE_SOURCE_DIR}/Lexical-Analysis)
