enable_testing()

# SETUP TESTING EXECUTABLE
add_executable(TESTING_EXE test.cpp)
target_link_libraries(TESTING_EXE ${LIB_NAME})

# LINK GOOGLETEST
add_subdirectory(include/googletest)
target_link_libraries(TESTING_EXE
    gtest
    gtest_main
    ${LIB_NAME}
)