#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <vector>

void help();
void setValue(std::string &varName, std::string &value);
void printVariable(const std::string &varName);
void run(std::string &fileLocation, bool &signal);
void exec(const std::vector<std::string> &argu, bool &signal);
void interpreter(const std::string &command, bool &signal);

#endif