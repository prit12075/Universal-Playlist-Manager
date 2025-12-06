#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    // Constructor
    Node(T val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

#endif