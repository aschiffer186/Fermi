set(FERMI_CXX_WARNING_FLAGS "-Wall" "-Werror" "-Wextra" "-pedantic")

set(LEXICAL_ANALYSIS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Lexical-Analysis)
set(LEXICAL_ANALYSIS_INCLUDE_DIR ${LEXICAL_ANALYSIS_DIR}/include)
set(SYNTAX_ANALYSIS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Syntax-Analysis)

add_subdirectory(Lexical-Analysis)
add_subdirectory(Syntax-Analysis)