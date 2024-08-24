#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "shell.h"
#include "ram.h"
#include "cpu.h"
#include "pcb.h"

ReadyQueue queue;
CPU cpu;

void scheduler();

void myInit(std::vector<std::string> &instructions) {

    for (size_t i = 0; i < instructions.size(); ++i) {
        //We want to pass the argument was a FILE* pointer to the ram
        std::shared_ptr<std::ifstream> program = std::make_shared<std::ifstream>(std::ifstream (instructions[i]));

        //add to ram
        addToRam(program);

        //create a pcb with the file pointer
        PCB pcb(program);

        //add to the ready queue
        queue.addToReady(pcb);
    }
    scheduler();
}
//The ready queue works more like a queue rather than a linked list
//once the turn is up we pop it and move it to the back.
//So to do this we pop the head then pass it to the cpu
// then once the two quantas is up we pass it to the ready queue.
void scheduler() {
    while (!queue.isEmpty()) {
        auto ins = queue.instruction();
        cpu.run(ins);
    }
}

int main() {

    std::cout << "Welcome to the C++ Shell\n";
    std::cout << "Version 1.1 Updated August 2024\n";
    std::cout << "Type 'help' to see an overview of available commands\n";
    parse();

    return 0;
}

