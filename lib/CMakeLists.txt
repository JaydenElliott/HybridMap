# SETUP LIBRARY
add_library(HybridMap src/HybridMap.hpp)
target_include_directories(HybridMap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
set_target_properties(HybridMap PROPERTIES LINKER_LANGUAGE CXX)