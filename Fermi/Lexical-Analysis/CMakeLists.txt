FLEX_TARGET(FermiLexer ${CMAKE_CURRENT_SOURCE_DIR}/include/FermiLexer.ll ${CMAKE_CURRENT_SOURCE_DIR}/src/FermiLexer.cpp)
BISON_TARGET(FermiParser ${CMAKE_CURRENT_SOURCE_DIR}/include/FermiParser.yy ${CMAKE_CURRENT_SOURCE_DIR}/src/FermiParser.cpp
    DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/export/FermiParser.hpp
    VERBOSE REPORT_FILE ${CMAKE_BINARY_DIR}/Bison-Report)

ADD_FLEX_BISON_DEPENDENCY(FermiLexer FermiParser)

add_library(Syntax-Analysis STATIC ${FLEX_FermiLexer_OUTPUTS})
target_include_directories(Syntax-Analysis PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/export)
target_link_libraries(Syntax-Analysis PUBLIC ${FLEX_LIBRARIES} ${BISON_LIBRARIES})

add_custom_command(TARGET Syntax-Analysis POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/src/location.hh ${CMAKE_CURRENT_SOURCE_DIR}/export)

add_custom_command(TARGET Syntax-Analysis POST_BUILD COMMAND ${CMAKE_COMMAND} -E rm -f
    ${CMAKE_CURRENT_SOURCE_DIR}/src/location.hh 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FermiParser.hpp)