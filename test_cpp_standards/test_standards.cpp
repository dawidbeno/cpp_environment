// test_standards.cpp
#include <iostream>

// Test different C++ standard features
#if __cplusplus >= 201103L
#include <vector>
#include <memory>
void test_cpp11() {
    auto x = std::make_shared<int>(42);  // C++11 features
    std::vector<int> v{1, 2, 3};        // Brace initialization
    std::cout << "C++11 features work\n";
}
#endif

#if __cplusplus >= 201402L
void test_cpp14() {
    auto lambda = [](auto x) { return x * 2; };  // Generic lambdas
    std::cout << "C++14 features work: " << lambda(21) << "\n";
}
#endif

#if __cplusplus >= 201703L
#include <optional>
void test_cpp17() {
    std::optional<int> opt = 42;  // std::optional
    if (auto val = opt; val.has_value()) {  // if with initializer
        std::cout << "C++17 features work: " << *val << "\n";
    }
}
#endif

#if __cplusplus >= 202002L
#include <concepts>
template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

void test_cpp20() {
    std::cout << "C++20 concepts work\n";
}
#endif

int main() {
    std::cout << "C++ Standard level: " << __cplusplus << "\n";
    
#if __cplusplus >= 201103L
    test_cpp11();
#endif
#if __cplusplus >= 201402L
    test_cpp14();
#endif
#if __cplusplus >= 201703L
    test_cpp17();
#endif
#if __cplusplus >= 202002L
    test_cpp20();
#endif
    
    return 0;
}