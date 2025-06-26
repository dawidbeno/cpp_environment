# CMakeLists.txt
cmake_minimum_required(VERSION 3.12) # to support c++20

# Define our project - this sets up basic variables and checks
project(CppStandardTest 
    VERSION 1.0
    DESCRIPTION "Testing C++ standard support"
    LANGUAGES CXX)  # We're only using C++

# Let's be explicit about what we want
# This tells CMake to fail if the compiler doesn't support our chosen standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Disable compiler-specific extensions to ensure portability
# This means we'll use pure C++ without compiler-specific additions
set(CMAKE_CXX_EXTENSIONS OFF)

# Function to create a test executable for a specific standard
function(create_standard_test std_version)
    # Create a unique name for this executable
    set(target_name "test_cpp${std_version}")

    # Tell CMake to create an executable from our source file
    add_executable(${target_name} test_standards.cpp)

    # Set the C++ standard for this specific executable
    # This is where CMake translates our request into compiler flags
    set_target_properties(${target_name} PROPERTIES
        CXX_STANDARD ${std_version}
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )

    # Add some compile-time information
    # This helps us see exactly what flags CMake is using
    target_compile_definitions(${target_name} PRIVATE 
        STANDARD_VERSION=${std_version}
    )

    # Print information about what we're building
    message(STATUS "Created target: ${target_name} with C++${std_version}")
endfunction()

# Now let's create executables for different standards
# Each one will be compiled with its specific standard
create_standard_test(11)
create_standard_test(14)
create_standard_test(17)
create_standard_test(20)

# Add a custom target to run all tests
# This creates a convenient way to run all our tests at once
add_custom_target(run_all_tests
    COMMAND echo "Running C++11 test:"
    COMMAND $<TARGET_FILE:test_cpp11>
    COMMAND echo "Running C++14 test:"
    COMMAND $<TARGET_FILE:test_cpp14>
    COMMAND echo "Running C++17 test:"
    COMMAND $<TARGET_FILE:test_cpp17>
    COMMAND echo "Running C++20 test:"
    COMMAND $<TARGET_FILE:test_cpp20>
    DEPENDS test_cpp11 test_cpp14 test_cpp17 test_cpp20
    COMMENT "Running all C++ standard tests"
)
