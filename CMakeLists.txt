cmake_minimum_required(VERSION 3.12)
project(Fermi CXX)

set(FERMI_MAJOR_VERSION 0)
set(FERMI_MINOR_VERSION 1)
set(FERMI_PATCH_VERSION 1)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(FERMI_MAJOR_VERSION=${FERMI_MAJOR_VERSION})
add_compile_definitions(FERMI_MINOR_VERSION=${FERMI_MINOR_VERSION})
add_compile_definitions(FERMI_PATCH_VERSION=${FERMI_PATCH_VERSION})

add_subdirectory(Fermi)

add_subdirectory(Tests)