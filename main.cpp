#include <iostream>

struct Car {
    std::string number;
};

struct LinkedListNode {
    LinkedListNode* next;
    LinkedListNode* prev;
    Car value;
};

struct LinkedList {
    LinkedList() : root(nullptr) {}
    
    void push(Car v) {
        if(root == nullptr) {
            LinkedListNode* node = new LinkedListNode();
            node->value = v;
            node->prev = nullptr;
            node->next = nullptr;
            root = node;
            return;
        }
        
        LinkedListNode* tmp = root; 
        while(tmp->next != nullptr) {
            tmp = tmp->next;
        }
        
        LinkedListNode* node = new LinkedListNode();
        node->value = v;
        tmp->next = node;
        node->prev = tmp;
        node->next = nullptr;
    }
    
    void printAll() {
        if(root == nullptr) {
            return;
        }
        LinkedListNode* currentNode = root;
        while(true) {
            std::cout<< currentNode->value.number << std::endl;
            if(currentNode->next == nullptr) {
                break;
            }
            currentNode = currentNode->next;
        }
    }
    private:
    LinkedListNode* root;
};

int main() {
    LinkedList list;
    
    Car car1;
    car1.number = "A571HH_26";

    Car car2;
    car2.number = "B132OP_26";
        
    list.push(car1);
    list.push(car2);
    
    list.printAll();
    
    return 0;
}
