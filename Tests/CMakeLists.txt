enable_testing()

find_package(GTest REQUIRED)
include(CTest)

add_custom_target(build_tests)

add_custom_target(run_tests DEPENDS build_tests)
add_custom_command(TARGET run_tests 
    COMMENT "Run unit-tests"
    POST_BUILD
    COMMAND ctest 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Tests)

add_subdirectory(Parser-Tests)
add_subdirectory(Setup-Tests)