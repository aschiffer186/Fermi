add_library(environment 
    ${CMAKE_CURRENT_SOURCE_DIR}/environment.cpp
)
target_include_directories(environment PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})