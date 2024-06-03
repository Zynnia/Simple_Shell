#ifndef PCB_H
#define PCB_H
#include <istream>
#include <sstream>

class PCB {
public:
    std::shared_ptr<std::ifstream> pc; //our file pointer - program counter
    explicit PCB(std::shared_ptr<std::ifstream> p) : pc(std::move(p)) {};
};

class ReadyQueue : public List {
private:
    std::shared_ptr<PCB> head; //points to the beginning of the queue
    std::shared_ptr<PCB> tail; //points to the tail of the queue
public:
    ReadyQueue(): head(nullptr), tail(nullptr) {}
    void add(std::string &name, std::string &val) override;
    void printVariable(const std::string &var) override;
    void printList() override;
};

void ReadyQueue::add(std::string &name, std::string &val) {

}

void ReadyQueue::printVariable(const std::string &var) {

}

void ReadyQueue::printList() {

}

PCB makePCB(std::shared_ptr<std::ifstream> &p) {
    PCB pp(p);
    return pp;
}


#endif