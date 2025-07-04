cmake_minimum_required(VERSION 3.15)
project(Greeter CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(fmt REQUIRED)

option(BUILD_USA_GREETING "Build with a special greeting for the USA" OFF)

# We define the executable with its standard logical name
add_executable(GreeterApp main.cpp)

if(BUILD_USA_GREETING)
    message(STATUS "Building with the special USA greeting!")

    # Add the compile definition for the C++ code, as before
    target_compile_definitions(GreeterApp PRIVATE GREETING_USA)

    # --- NEW LINE ---
    # Set a property on our target to change its output filename
    set_target_properties(GreeterApp PROPERTIES OUTPUT_NAME "GreeterAppUS")

endif()

# This line doesn't need to change, because the logical target
# name is still "GreeterApp"
target_link_libraries(GreeterApp PRIVATE fmt::fmt)