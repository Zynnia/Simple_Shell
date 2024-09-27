#ifndef PCB_H
#define PCB_H
#include <memory>
#include <vector>

//TODO: RAM will always point to the front of the file where as the pcb will keep track.
//      Then on initialization the pcb will copy the file pointer from the ram
//      CPU and the PCB will share the same file pointer
class PCB {
public:
    std::shared_ptr<std::ifstream> pc; // our file pointer
    std::shared_ptr<PCB> next;
    std::vector<int> pageTable;
    int pcPage;
    int pcOffset;
    int pagesMax; //this is the total Number of Pages we have
    PCB(std::shared_ptr<std::ifstream> p, int _pagesMax) : pc(p), pagesMax(_pagesMax), next(nullptr), pageTable(10, -1) {};

    //PCB(std::shared_ptr<std::ifstream> p) : pc(p), next(nullptr) {};
};

class ReadyQueue {
private:
    std::shared_ptr<PCB> head; //points to the beginning of the queue
public:
    ReadyQueue(): head(nullptr) {}
    void addToReady(PCB pcb);
    std::shared_ptr<std::ifstream> instruction() {
        auto dummy = std::move(head->pc);
        head = head->next;
        return dummy;
    }
    void updatePCB(std::shared_ptr<std::ifstream> ip, int _pageMax);
    bool isEmpty() const;
    void test();
};

//Add the pcb to our ready queue
void ReadyQueue::addToReady(PCB pcb) {
    if (head == nullptr) {
        head = std::make_shared<PCB>(pcb);
    } else {
        auto dummy = head;
        while (dummy->next != nullptr) {
            dummy = dummy->next;
        }
        dummy->next = std::make_shared<PCB>(pcb);
    }
}

inline void ReadyQueue::updatePCB(std::shared_ptr<std::ifstream> ip, int _pageMax) {
    //Make a new pcb
    PCB pcb(std::move(ip), _pageMax);
    //Add it to the end of the queue
    addToReady(pcb);
}

//check to see if the Ready Queue is empty
inline bool ReadyQueue::isEmpty() const {
    return (head == nullptr);
}

//Tester to see if things are added correctly
inline void ReadyQueue::test() {
    auto dummy = head;
    size_t i = 0;
    while (dummy != nullptr) {
        i++;
        dummy = dummy->next;
    }
    std::cout << "The number of entry is " << i << std::endl;
}

extern ReadyQueue queue;


#endif