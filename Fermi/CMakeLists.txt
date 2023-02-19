set(FERMI_CXX_WARNINGS "-Wall -Wextra -Wshadow -Wno-unused-but-set-variable -Werror -pedantic")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${FERMI_CXX_WARNINGS})

add_subdirectory(Setup)
add_subdirectory(Syntax-Analysis)

add_executable(Fermi Fermi.cpp)
target_link_libraries(Fermi PRIVATE FermiParser FermiSetup)