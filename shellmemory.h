#ifndef SHELLMEMORY_H

class Node {
public:
    std::string name;
    std::string value;
    Node *next;

    Node(std::string &_name, std::string &_value) : name(_name), value(_value), next(nullptr) {}
};

class ListNode {
private:
    Node *head;
public:

    ListNode(): head(nullptr) {}

    void add(std::string &name, std::string &val) {
        if (head == nullptr) {
            head = new Node(name, val);
            return;
        } else {
            Node *temp = head;
            while (temp != nullptr) {
                if (temp->name == name) {
                    temp->value = val;
                    break;
                } else if (temp->next == nullptr) {
                    Node *newNode = new Node(name, val);
                    temp->next = newNode;
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void printVariable(const std::string &var) {
        Node *temp = head;
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
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->name << " " << temp->value << std::endl;
            temp = temp->next;
        }
    }
};

#endif