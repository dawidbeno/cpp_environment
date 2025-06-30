# C++ Environment

This repository demonstrates modern C++ development, project organization, and build management using CMake. It contains several example projects and libraries, each showcasing different aspects of C++ programming, dependency management, and build configuration.

## Project Structure

- `dad_joke/` — Command-line app fetching random dad jokes from an API
- `hello_library/` — Example of a C++ static library and an app using it
- `test_cpp_standards/` — Demonstrates building with multiple C++ standards

### dad_joke
A simple command-line tool that fetches and displays random dad jokes from an online API.
- Uses [cpr](https://github.com/libcpr/cpr) for HTTP requests
- Uses [nlohmann/json](https://github.com/nlohmann/json) for JSON parsing
- Demonstrates linking external dependencies with CMake

### hello_library
An example of organizing code into a reusable static library (`math_lib`) and an application that links against it.
- Shows best practices for separating headers and sources
- Demonstrates CMake targets and linking libraries

### test_cpp_standards
A small project that builds the same code with different C++ standards (C++11, C++14, C++17, C++20) to demonstrate compatibility and feature differences.

## Building the Projects

This workspace uses CMake for cross-platform builds. To build any project:

```sh
cd <project_folder>
mkdir -p build
cd build
cmake ..
make
```

For example, to build the dad_joke CLI:

```sh
cd dad_joke
mkdir -p build
cd build
cmake ..
make
./dad_joke_cli
```

## Requirements

- CMake >= 3.15
- A C++17-compatible compiler (e.g., GCC, Clang, MSVC)
- [cpr](https://github.com/libcpr/cpr) and [nlohmann/json](https://github.com/nlohmann/json) libraries (install via package manager or from source)

## License

This project is for educational purposes.
