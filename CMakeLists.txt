enable_testing()

# GENERAL CONFIG
set (PROJECT_NAME HybridMap)
cmake_minimum_required(VERSION 3.0)
project (${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 20)

# SOURCES
set (SOURCES 
    src/hybrid_map.cpp
    src/hash.cpp 
    )

# SETUP LIBRARY
add_library(${PROJECT_NAME} ${SOURCES})

# SETUP TESTING EXECUTABLE
add_executable(TESTING_EXE tests/test.cpp)
target_link_libraries(TESTING_EXE ${PROJECT_NAME})

# LINK GOOGLETEST
add_subdirectory(include/googletest)
target_link_libraries(TESTING_EXE
    gtest
    gtest_main
)