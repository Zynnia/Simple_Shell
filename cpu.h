#ifndef CPU_H
#define CPU_H
#include <istream>
#include <memory>
#include <string>
#include "interpreter.h"
#include "pcb.h"



class CPU {
private:
    std::ifstream ip; //instruction pointer
    std::string ir; //instruction register
    const int quanta{2}; //quanta field
public:
    void run(std::shared_ptr<std::ifstream> &_ip);
};

void CPU::run(std::shared_ptr<std::ifstream> &_ip) {
    std::string line;
    bool signal = true;
    int num = 0;
    while (getline(*_ip, line)) {
        ir = line;
        interpreter(ir, signal);
        num++;
        if (num > quanta) break;
    }
    //If eof then close the file otherwise update the ready queue
    if (_ip->eof()) {
        _ip->close();
        //For testing purposes
        std::cout << "We reach the end of the file" << std::endl;

    } else {
        //Here we need to get the information to return it back to the ready queue.
        queue.updatePCB(_ip);
    }
}

#endif