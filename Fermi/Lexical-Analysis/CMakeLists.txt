find_package(FLEX REQUIRED)

add_library(FermiLexer ${CMAKE_CURRENT_SOURCE_DIR}/src/FermiLexerTypes.cpp)
target_compile_features(FermiLexer PRIVATE cxx_std_20)
target_include_directories(FermiLexer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)