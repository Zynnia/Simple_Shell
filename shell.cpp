#include <iostream>
#include <string>
#include "interpreter.h"

void parse() {
    std::string input;
    bool signal = true;
    while (signal) {
        getline(std::cin, input);
        interpreter(input, signal);
    }
}

int main() {
    std::cout << "Welcome to the C++ Shell\n";
    std::cout << "Version 1.0 Created March 2024\n";
    parse();

    return 0;
}