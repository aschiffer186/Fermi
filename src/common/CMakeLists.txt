add_library(common
    ${CMAKE_CURRENT_SOURCE_DIR}/source_file.cpp
)
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(common PUBLIC syntax_nodes environment)