#include <iostream>
#include <string>
#include "shell.h"
#include "interpreter.h"

void parse() {
    std::string input;
    bool signal = true;
    while (signal) {
        std::cout << "$";
        getline(std::cin, input);
        if (!input.empty()) {
            interpreter(input, signal);
        }
    }
}
