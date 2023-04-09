set(FERMI_CXX_WARNINGS "-Wall -Wextra -Wshadow -Wno-unused-but-set-variable -Werror -pedantic")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${FERMI_CXX_WARNINGS})

set(PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Syntax-Analysis)
set(SEMANTIC_ANALYSIS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Semantic-Analysis)

add_subdirectory(Setup)
# add_subdirectory(Syntax-Analysis)
add_subdirectory(Syntax-Analysis-New)
add_subdirectory(Semantic-Analysis)

add_executable(Fermi Fermi.cpp)
# target_link_libraries(Fermi PRIVATE FermiParser FermiSetup FermiSemanticAnalysis)