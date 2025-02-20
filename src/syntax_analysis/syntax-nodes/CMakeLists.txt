add_library(syntax_nodes
    ${CMAKE_CURRENT_SOURCE_DIR}/syntax_node_printer.cpp
)
target_include_directories(syntax_nodes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})