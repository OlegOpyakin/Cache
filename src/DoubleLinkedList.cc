#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Adding an item to the top of the list
void DoubleLinkedList::push_front(unsigned int const &value) {
    Node* newNode = new Node(value);
    if (head) {
        newNode->next = head;
        head->prev = newNode;
    }
    else{
        tail = newNode;
    }
    head = newNode;
    nodeMap[value] = newNode; 
    size++;
}

// Removing an element from an arbitrary position
void DoubleLinkedList::remove(unsigned int const &value) {
    Node* nodeToRemove = nodeMap[value];

    if (nodeToRemove->prev) {
        nodeToRemove->prev->next = nodeToRemove->next;
    }
    else {
        head = nodeToRemove->next; // if delete first element
    }

    if (nodeToRemove->next) {
        nodeToRemove->next->prev = nodeToRemove->prev;
    }
    else{
        tail = nodeToRemove->prev;  // if delete last element
    }

    nodeMap.erase(value);

    delete nodeToRemove; // Free memory

    size--;
}

// Return list size
int DoubleLinkedList::get_size() const {
    return size;
}

// Return umap size
int DoubleLinkedList::get_map_size() const {
    return nodeMap.size();
}

// return last item
unsigned int DoubleLinkedList::get_last() const{
    return tail->data;
}

// Destroyer
DoubleLinkedList::~DoubleLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}