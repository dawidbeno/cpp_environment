# 1. Set the minimum required version of CMake and define the project
cmake_minimum_required(VERSION 3.10)
project(MathProject CXX)

# 2. Add the library target
# This command creates a static library target named "math_lib" from its source file.
# A static library's code is copied directly into the final executable at compile time.
add_library(math_lib STATIC math/src/math_lib.cpp)

# 3. Specify the library's include directories
# This is a crucial step. It tells CMake that the "math_lib" target needs
# its own "math/include" directory to find its headers.
# More importantly, by using PUBLIC, we are saying: "Any target that links to
# math_lib should ALSO get this include path automatically."
target_include_directories(math_lib PUBLIC math/include)

# 4. Add the executable target
# This is the same command you know from your Hello World project.
add_executable(my_app main.cpp)

# 5. Link the library to the executable
# This command tells CMake that the "my_app" target depends on the "math_lib" target.
# CMake will handle everything:
#   - Ensure math_lib is built before my_app.
#   - Pass the location of the compiled library file to the linker.
#   - Propagate the public include directories from math_lib to my_app.
target_link_libraries(my_app PRIVATE math_lib)