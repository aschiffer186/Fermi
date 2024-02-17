cmake_minimum_required(VERSION 3.12)
project(Fermi CXX C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(FERMI_MAJOR_VERSION 0)
set(FERMI_MINOR_VERSION 3)
set(FERMI_PATCH_VERSION 0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(FERMI_MAJOR_VERSION=${FERMI_MAJOR_VERSION})
add_compile_definitions(FERMI_MINOR_VERSION=${FERMI_MINOR_VERSION})
add_compile_definitions(FERMI_PATCH_VERSION=${FERMI_PATCH_VERSION})

add_subdirectory(Lexical-Analysis)

add_executable(Fermi Fermi.cpp)
target_link_libraries(Fermi PRIVATE Scanner)
target_include_directories(Fermi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Lexical-Analysis)

add_subdirectory(Tests)
