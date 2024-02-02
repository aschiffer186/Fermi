add_library(Parser ${CMAKE_CURRENT_SOURCE_DIR}/src/FermiParser.cpp)
target_compile_features(Parser PRIVATE cxx_std_20)
target_include_directories(Parser PRIVATE ${LEXICAL_ANALYSIS_INCLUDE_DIR}
                                          ${CMAKE_CURRENT_SOURCE_DIR}/include)