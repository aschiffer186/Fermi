set(FERMI_CXX_WARNINGS "-Wall" "-Wextra" "-Wshadow" "-Werror" "-pedantic")
set(CMAKE_CXX_OPTIONS ${CMAKE_CXX_OPTIONS} ${FERMI_CXX_WARNINGS})

add_subdirectory(Syntax-Analysis)