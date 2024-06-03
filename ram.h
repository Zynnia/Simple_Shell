#ifndef RAM_H
#define RAM_H
#include <vector>
#include <istream>
#include <memory>

//initialize an array of file pointers
std::vector<std::shared_ptr<std::ifstream>> ram(10, nullptr);

void addToRam(std::shared_ptr<std::ifstream>& p) {
    for (size_t i = 0; i < 10; ++i) {
        if (ram[i] == nullptr) {
            ram[i] = std::move(p);
            return;
        }
    }
}

void printfile(){
    std::string line;
    for (auto x: ram) {
        if (x != nullptr) {
            while (getline(*x, line)) {
                std::cout << line << std::endl;
            }
        }
    }
}


#endif