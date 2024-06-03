#ifndef CPU_H
#define CPU_H
#include <istream>
#include <memory>
#include <string>

class Cpu {
private:
    std::ifstream ip; //instruction pointer
    std::string ir; //instruction register
    const int quanta{2}; //quanta field
public:
    void run(std::ifstream& _ip);
};

void Cpu::run(std::ifstream& _ip) {
    std::string line;
    while (getline(_ip, line)) {

    }
}

#endif