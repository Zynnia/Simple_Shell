#include <iostream>
#include <istream>
#include "ram.h"



//Each file pointer will count as a program
//The array can only hold 10 programs at a time
void addToRam(std::shared_ptr<std::ifstream> &p) {
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
