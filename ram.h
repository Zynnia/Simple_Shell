#ifndef RAM_H
#define RAM_H
#include <vector>
#include <memory>

//initialize an array of file pointers
extern std::vector<std::shared_ptr<std::ifstream>> ram;

void addToRam(std::shared_ptr<std::ifstream> &p);

#endif