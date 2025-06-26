# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(StandardTest)

# Let CMake tell us what it thinks is available
message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

# Check CMake's built-in standard support detection
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Try different standards and see what CMake accepts
foreach(std IN ITEMS 11 14 17 20 23)
    set(CMAKE_CXX_STANDARD ${std})
    message(STATUS "Testing C++${std} support...")
    
    # CMake will warn or error if the standard isn't supported
    try_compile(CXX${std}_SUPPORTED 
                ${CMAKE_BINARY_DIR}
                ${CMAKE_SOURCE_DIR}/test_standards.cpp
                CXX_STANDARD ${std}
                CXX_STANDARD_REQUIRED ON)
    
    if(CXX${std}_SUPPORTED)
        message(STATUS "C++${std}: SUPPORTED")
    else()
        message(STATUS "C++${std}: NOT SUPPORTED")
    endif()
endforeach()