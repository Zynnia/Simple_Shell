#ifndef SHELLMEMORY_H
#include<memory>

class Node {
public:
    std::string name;
    std::string value;
    std::shared_ptr<Node> next;

    Node(std::string &_name, std::string &_value) : name(_name), value(_value), next(nullptr) {}
};

class ListNode {
private:
    std::shared_ptr<Node> head;
public:

    ListNode(): head(nullptr) {}

    void add(std::string &name, std::string &val) {
        if (head == nullptr) {
            head = std::make_shared<Node>(Node(name, val));
            return;
        } else {
            std::shared_ptr<Node> temp = head;
            while (temp != nullptr) {
                if (temp->name == name) {
                    temp->value = val;
                    break;
                } else if (temp->next == nullptr) {
                    temp->next = std::make_shared<Node>(Node(name, val));
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void printVariable(const std::string &var) {
        std::shared_ptr<Node> temp = head;
        while (temp != nullptr) {
            if (temp->name == var) {
                std::cout << temp->value << std::endl;
                return;
            }
            temp = temp->next;
        }
        std::cout << "Variable does not exist" << std::endl;
    }

    void printList() {
        std::shared_ptr<Node> temp = head;
        while (temp != nullptr) {
            std::cout << temp->name << " " << temp->value << std::endl;
            temp = temp->next;
        }
    }
};

#endif