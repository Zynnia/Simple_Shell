#ifndef PCB_H
#define PCB_H
#include <memory>
#include <queue>
#include <vector>

//TODO: RAM will always point to the front of the file where as the pcb will keep track.
//      Then on initialization the pcb will copy the file pointer from the ram
//      CPU and the PCB will share the same file pointer
class PCB {
public:
    std::shared_ptr<std::ifstream> pc; // our file pointer
    std::vector<int> pageTable;
    int pcPage;
    int pcOffset;
    int pagesMax; //this is the total Number of Pages we have
    PCB(std::shared_ptr<std::ifstream> p, int _pagesMax) : pc(p), pagesMax(_pagesMax), pageTable(10, -1) {};

    //PCB(std::shared_ptr<std::ifstream> p) : pc(p), next(nullptr) {};
};

class ReadyQueue {
private:
    std::queue<PCB> head; //points to the beginning of the queue
public:
    ReadyQueue()= default;
    void addToReady(PCB pcb);

    //Pop the first pcb in the instruction to process
    PCB instruction() {
        PCB currPCB = head.front();
        head.pop();
        return currPCB;
    }
    void updatePCB(std::shared_ptr<std::ifstream> ip, int _pageMax);
    bool isEmpty() const;
    void test();
};

//Add the pcb to our ready queue
inline void ReadyQueue::addToReady(PCB pcb) {
    head.push(pcb);
}

inline void ReadyQueue::updatePCB(std::shared_ptr<std::ifstream> ip, const int _pageMax) {
    //Make a new pcb
    PCB pcb(std::move(ip), _pageMax);
    //Add it to the end of the queue
    addToReady(pcb);
}

//check to see if the Ready Queue is empty
inline bool ReadyQueue::isEmpty() const {
    return (head.empty());
}

//Tester to see if things are added correctly
inline void ReadyQueue::test() {

    std::cout << "The number of entry is " << head.size() << std::endl;
}

extern ReadyQueue queue;


#endif