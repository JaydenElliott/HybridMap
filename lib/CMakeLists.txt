# SOURCES
set (SOURCES 
    HybridMap.cpp
    Hash.cpp 
    )

# SETUP LIBRARY
add_library(${LIB_NAME} SHARED ${SOURCES})