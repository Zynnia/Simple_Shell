#include <iostream>
#include <string>
#include "interpreter.h"
#include "shell.h"
#include "pcb.h"
#include "ram.h"
#include "cpu.h"

void addToReady(PCB p);

void myInit(std::vector<std::string> &instructions) {
    for (int i = 0; i < instructions.size(); ++i) {
        //We want to pass the argument was a FILE* pointer to the ram
        std::shared_ptr<std::ifstream> program = std::make_shared<std::ifstream>(std::ifstream (instructions[i]));

        addToRam(program);
        //auto gg = makePCB(instructions[i]);
    }
    std::cout << "Hello the exec calls is here" << std::endl;
    printfile();
}

void addToReady(PCB p) {

}


int main() {
    std::cout << "Welcome to the C++ Shell\n";
    std::cout << "Version 1.0 Created March 2024\n";
    parse();

    return 0;

}

