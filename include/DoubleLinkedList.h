#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H


#include <unordered_map>
#include "Node.h"

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> nodeMap; // Stores node addresses by their positions
    int size;

public:
    DoubleLinkedList();

    // Adding an item to the top of the list
    void push_front(unsigned int const &value);

    // Removing an element from an arbitrary position
    void remove(unsigned int const &value);

    // Return list sizt
    int get_size() const;

    // return umap size (need for tests)
    int get_map_size() const;

    // return last item
    unsigned int get_last() const;

    ~DoubleLinkedList();
};
#endif