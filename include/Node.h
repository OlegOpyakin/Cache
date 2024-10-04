#ifndef NODE_H 
#define NODE_H
class Node {
public:
    unsigned int data;
    Node* prev;
    Node* next;

    Node(unsigned int value);
};
#endif 