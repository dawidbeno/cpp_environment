// In file: main.cpp
#include <iostream>
#include "math_lib.h" // <-- Including our new library header

int main() {
    int result = add(5, 3);
    std::cout << "The result is: " << result << std::endl;
    return 0;
}