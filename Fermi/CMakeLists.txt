find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

add_subdirectory(Lexical-Analysis)

add_executable(Fermi Fermi.cpp)
target_link_libraries(Fermi PRIVATE Syntax-Analysis)