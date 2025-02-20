add_subdirectory(environment)
add_subdirectory(syntax_analysis)
add_subdirectory(common)

add_executable(fermi 
    ${CMAKE_CURRENT_SOURCE_DIR}/fermi.cpp
)
target_link_libraries(fermi PRIVATE common environment syntax_analysis)