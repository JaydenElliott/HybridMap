
set (LIB_NAME HybridMap)
cmake_minimum_required(VERSION 3.0)
project (${LIB_NAME})
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)
add_subdirectory(tests)