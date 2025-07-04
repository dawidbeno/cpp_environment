// main.cpp
#include <fmt/core.h> // Using the modern {fmt} library for nice output!

int main() {
#ifdef GREETING_USA
    // This code will only be included in the binary if the GREETING_USA flag is set!
    fmt::print("Happy Fourth of July! 🎆\n");
#else
    // This is the default code.
    fmt::print("Dobrý deň from Slovakia! 👋\n");
#endif
    return 0;
}