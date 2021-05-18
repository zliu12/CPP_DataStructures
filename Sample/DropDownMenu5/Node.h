#ifndef PROJECT1_NODE_H
#define PROJECT1_NODE_H
template <class T>
struct Node{
    T data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

#endif //PROJECT1_NODE_H
