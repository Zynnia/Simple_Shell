#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "shell.h"
#include "ram.h"
#include "cpu.h"
#include "pcb.h"
#include "memorymanager.h"

ReadyQueue queue;
CPU cpu;
std::vector<std::shared_ptr<std::ifstream>> ram(10, nullptr);

void scheduler();
void boot();

void myInit(std::vector<std::string> &instructions) {

    for (size_t i = 0; i < instructions.size(); ++i) {
        //We want to pass the argument was a FILE* pointer to the ram
        std::shared_ptr<std::ifstream> program = std::make_shared<std::ifstream>(std::ifstream (instructions[i]));

        //add to ram
        addToRam(program);

        //create a pcb with the file pointer
        //So we want to add in the the total number of page count
        const int pageMax = countTotalPages(program);
        PCB pcb(program, pageMax);

        //add to the ready queue
        queue.addToReady(pcb);

    }
    scheduler();
}
//The ready queue works more like a queue (hence the name) rather than a linked list
//once the turn is up we pop it and move it to the back.
//So to do this we pop the head then pass it to the cpu
//then once the two quantas is up we pass it to the ready queue.
//I think the pageOffset is not neccessar due too the fact the it is kept track by the ifstream
void scheduler() {
    while (!queue.isEmpty()) {
        auto ins = queue.instruction();
        cpu.run(ins);
    }
}

void boot() {

    //System command for Windows systems and Ubuntu Linux
    //To remove the BackingStore Directory if it exists
    //Both cases will silence the error output if folder does not exist
    #ifdef _WIN32
        std::system("if exist BackingStore rmdir /s /q Backingstore");
    #else
        std::system("rmdir BackingStore 2>/dev/null");
    #endif

    //Make the BackingStore
    std::system("mkdir BackingStore");

}

int main() {
    boot();
    std::cout << "Welcome to the C++ Shell\n";
    std::cout << "Version 1.2 Updated October 2024\n";
    std::cout << "Type 'help' to see an overview of available commands" << std::endl;
    parse();

    return 0;
}

