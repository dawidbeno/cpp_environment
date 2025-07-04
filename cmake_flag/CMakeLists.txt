# CMakeLists.txt

cmake_minimum_required(VERSION 3.15)
project(Greeter CXX)
set(CMAKE_CXX_STANDARD 17)

# Find the {fmt} library for our cool printing functions
find_package(fmt REQUIRED)

# ---- THE IMPORTANT PART STARTS HERE ----

# 1. Create a user-configurable option.
#    This creates a variable 'BUILD_USA_GREETING', gives it a description,
#    and sets its default value to OFF.
option(BUILD_USA_GREETING "Build with a special greeting for the USA" OFF)

# Add our executable target
add_executable(GreeterApp main.cpp)

# 2. Check the value of our option.
if(BUILD_USA_GREETING)
    # 3. If the option is ON, add a compile definition to our target.
    #    This is like passing "-DGREETING_USA" to the compiler on the
    #    command line. It makes the #ifdef in C++ work!
    target_compile_definitions(GreeterApp PRIVATE GREETING_USA)
    message(STATUS "Building with the special USA greeting!")
endif()

# ---- THE IMPORTANT PART ENDS HERE ----

# Link the {fmt} library so we can use its functions
target_link_libraries(GreeterApp PRIVATE fmt::fmt)