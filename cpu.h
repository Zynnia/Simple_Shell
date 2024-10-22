#ifndef CPU_H
#define CPU_H
#include <istream>
#include <memory>
#include <string>
#include "interpreter.h"
#include "pcb.h"

class CPU {
private:
    std::shared_ptr<std::ifstream> ip; //instruction pointer
    std::string ir; //instruction register
    const int quanta{2}; //quanta field
public:
    void run(const PCB& p);//std::shared_ptr<std::ifstream> &_ip);
};

void CPU::run(const PCB& p){//std::shared_ptr<std::ifstream> &_ip) {
    std::string line;
    bool signal = true;
    int num = 1;
    ip = p.pc;

    //Grab the instruction line and execute it

    while (getline(*ip, line)) {
        ir = line;
        interpreter(ir, signal);
        num++;
        if (num > quanta) break;
    }
    //If eof then close the file otherwise update the ready queue
    if (ip->eof()) {
        ip->close();
    } else {
        //Return the current instruction back to the ready queue
        queue.updatePCB(ip, p.pagesMax);
    }
}

#endif