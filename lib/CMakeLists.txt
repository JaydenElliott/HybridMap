# SETUP LIBRARY
add_library(HybridMap STATIC src/HybridMap.hpp src/Hash.cpp)
target_include_directories(HybridMap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
set_target_properties(HybridMap PROPERTIES LINKER_LANGUAGE CXX)