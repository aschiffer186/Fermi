macro(create_setup_test TARGET_NAME SOURCE_FILE)
    add_executable(${TARGET_NAME} EXCLUDE_FROM_ALL ${SOURCE_FILE})
    add_dependencies(build_tests ${TARGET_NAME})
    target_link_libraries(${TARGET_NAME} PRIVATE FermiSetup GTest::gtest_main)
    target_compile_features(${TARGET_NAME} PRIVATE cxx_std_20)
    gtest_discover_tests(${TARGET_NAME})
endmacro()

create_setup_test(TestCommandLineArgs TestCommandLineArgs.cpp)