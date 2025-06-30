cmake_minimum_required(VERSION 3.15)
project(DadJokeCLI CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Find our two dependencies
# CMake will find the libraries we installed with Homebrew.
find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

# 3. Define our executable
add_executable(dad_joke_cli main.cpp)

# 4. Link ALL dependencies to our executable
# We just list the imported targets one after another.
# By convention, the targets are `cpr::cpr` and `nlohmann_json::nlohmann_json`.
target_link_libraries(dad_joke_cli 
    PRIVATE 
        cpr::cpr
        nlohmann_json::nlohmann_json
)