#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "shellmemory.h"
#include "kernel.h"

ListNode shellMemory;

void interpreter (const std::string &command, bool &signal);

void help() {
    /*
     * Even entries contains commands. Odd entries contains Descriptions.
     */
    const std::vector<std::string> commands = {
            "COMMAND", "DESCRIPTION",
            "help", "Displays all the commands",
            "quit", "Exits the shell",
            "set VAR STRING", "Assigns a value to shell memory",
            "print Var", "Prints the String assigned to VAR",
            "run SCRIPT.txt", "Executes the file SCRIPT.txt",
            "exec p1 p2 p3", "Executes concurrent programs. Example exec p1.txt p2.txt"
    };
    const char separator = ' ';
    const int padding = 30;

    for (int i = 0; i < commands.size(); ++i) {
        if (i % 2 == 0) {
            std::cout << std::left << std::setw(padding) << std::setfill(separator) << commands[i];
        } else {
            std::cout << commands[i] << std::endl;
        }
    }
}

void setValue(std::string &varName, std::string &value) {
    shellMemory.add(varName, value);
}

void printVariable(const std::string &varName) {
    shellMemory.printVariable(varName);
}

void run(std::string &fileLocation, bool &signal) {
    std::ifstream testScript;
    testScript.open(fileLocation);
    if (!testScript.is_open()) {
        std::cout << "Script not found" << std::endl;
        return;
    }
    std::string line;
    while (getline(testScript, line)) {
        interpreter(line, signal);
        if (line == "quit") { break; }
    }
    testScript.close();
}

void exec(const std::vector<std::string>& argu, bool &signal) {
    //Here exec will call the run function
    //probably best to pass in the array then have it call
    //run in a loop

    //need to check for valid file extension and if the program has already ran
    //check if the last 4 characters are a .txt
    const size_t len = argu.size();
    for (int i = 1; i < len; ++i) {
        //std::cout << x << std::endl;
        std::string ext;
        size_t lenWord = argu[i].size();
        for (int j = 0; j < 4; ++j) {
            ext += argu[i][lenWord - j - 1];
        }
        if (ext != "txt.") {
            std::cout << "Invalid file extension" << std::endl;
            signal = false;
        }
        std::cout << ext << std::endl;
    }
    std::vector<std::string> p;
    myInit(p);
}

void interpreter(const std::string &command, bool &signal) {

    //Split the arguments by spaces
    std::vector<std::string> instructions;
    std::string token;
    std::stringstream ss(command);

    while (getline(ss, token, ' ')) {
        instructions.push_back(token);
    }
    const size_t argument = instructions.size();

    if (instructions[0] == "help" && argument == 1) {
        help();
    }
    else if (instructions[0] == "set" && argument == 3) {
        setValue(instructions[1], instructions[2]);
    }
    else if (instructions[0] == "print" && argument == 2) {
        printVariable(instructions[1]);
    }
    else if (instructions[0] == "run" && argument == 2) {
        run(instructions[1], signal);
    }
    else if (instructions[0] == "exec" && argument >=2 && argument <= 4) {
        exec(instructions, signal);
    }
    else if (instructions[0] == "quit" && argument == 1) {
        signal = false;
        std::cout << "Bye!\n";
    }
    else {
        std::cout << "Unknown Command\n";
    }
}
#endif