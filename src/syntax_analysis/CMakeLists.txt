find_package(BISON REQUIRED)

add_custom_target(make_lexer)

set(CMAKE_CXX_FLAGS_OLD ${CMAKE_CXX_FLAGS})
FetchContent_Declare (
    RE2C
    GIT_REPOSITORY "https://github.com/skvadrik/re2c.git"
)
FetchContent_MakeAvailable(
    RE2C
)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS_OLD})

set(RE2C_COMMAND "${CMAKE_BINARY_DIR}/_deps/re2c-build/re2c")
add_custom_command(
    TARGET make_lexer
    COMMAND ${RE2C_COMMAND}
    ARGS "${CMAKE_CURRENT_SOURCE_DIR}/lexer-in.cpp" -o "${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp")

BISON_TARGET(
    Parser 
    ${CMAKE_CURRENT_SOURCE_DIR}/parser.yy 
    ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp 
    DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/parser.hpp 
    # COMPILE_FLAGS "-Wcounterexamples"
    VERBOSE ${CMAKE_CURRENT_SOURCE_DIR}/FermiParserReport.txt
)

add_subdirectory(syntax-nodes)

add_library(syntax_analysis
    ${BISON_Parser_OUTPUTS}
    ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp
)
target_include_directories(syntax_analysis PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(syntax_analysis PUBLIC syntax_nodes)
add_dependencies(syntax_analysis make_lexer)