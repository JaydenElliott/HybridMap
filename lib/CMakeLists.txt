# SOURCES
set (SOURCES 
    src/HybridMap.cpp
    src/Hash.cpp 
    )

# SETUP LIBRARY
add_library(HybridMap SHARED ${SOURCES})
target_include_directories(HybridMap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")