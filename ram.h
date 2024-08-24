#ifndef RAM_H
#define RAM_H
#include <vector>
#include <istream>
#include <memory>

//initialize an array of file pointers
std::vector<std::shared_ptr<std::ifstream>> ram(10, nullptr);

//Each file pointer will count as a program
//The array can only hold 10 programs at a time
void addToRam(std::shared_ptr<std::ifstream>& p) {
    for (size_t i = 0; i < 10; ++i) {
        //find the first instance of empty ram space
        if (ram[i] == nullptr) {
            //Note now p is consider empty. after the move semantics
            //ram[i] = std::move(p);
            ram[i] = p;
            return;
        }
    }
}

//Testing purposes
void printfile(){
    std::string line;
    for (const auto &x: ram) {
        int i = 0;
        if (x != nullptr) {
            while (getline(*x, line)) {
                std::cout << line << " " << i << std::endl;
                i++;
                if (i == 2) break;
            }
        }
    }
}

void printNumberOfProgs() {
    uint32_t num = 0;
    for (auto x: ram) {
        if (x != nullptr) {
            num++;
        }
    }
    std::cout << "Total number of program in ram " << num << std::endl;
}


#endif