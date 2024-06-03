#ifndef SHELL_H
#include "interpreter.h"

void parse() {
    std::string input;
    bool signal = true;
    while (signal) {
        getline(std::cin, input);
        if (!input.empty()) {
            interpreter(input, signal);
        }
    }
}

#endif