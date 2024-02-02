find_package(FLEX REQUIRED)

FLEX_TARGET(FermiGeneratedLexer 
             ${CMAKE_CURRENT_SOURCE_DIR}/include/FermiLexer.ll 
             ${CMAKE_CURRENT_SOURCE_DIR}/src/FermiLexer.cpp)

add_library(FermiLexer 
            ${CMAKE_CURRENT_SOURCE_DIR}/src/FermiLexerTypes.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/FermiLexer.cpp
           )

target_compile_features(FermiLexer PRIVATE cxx_std_20)
target_compile_options(FermiLexer PRIVATE ${FERMI_CXX_WARNING_FLAGS})
target_include_directories(FermiLexer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)