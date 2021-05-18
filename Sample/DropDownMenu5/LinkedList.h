
#ifndef PROJECT1_CS008_LINKEDLIST_H
#define PROJECT1_CS008_LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include <iterator>
#include "Node_iterator.h"

using namespace std;


template <class T>
class LinkedList {
private:
    Node<T>* head=nullptr;
    Node<T>* tail=nullptr;
    Node<T>* current;

    void insertFirst(T item);
    Node<T>* createNode(T item);
    Node<T>* find(T item); // Find the node with the specific data
    void remove(Node<T>* node); // for remove the node
    Node<T>* previousNode(Node<T>* node);
    Node<T>* nextNode(Node<T>* node);
    Node<T>* previousNode(T item);


public:
    typedef Node_iterator<T> iterator;
    ~LinkedList();
    LinkedList();
    LinkedList(const LinkedList& list);
    LinkedList& operator=(const LinkedList& list);
    LinkedList& operator += (const int item);
    void insertHead(T item);
    void insertTail(T item);
    void insertBefore(T item, T beforeItem);
    void insertAfter(T item, T afterItem);

    void remove(T item);  // find then node and remove the node
    void removeHead();
    void removeTail();
    bool isEmpty()const;
    int Size(const LinkedList& list);
    T getHead();
    T getTail();
    T seek(int n);
    template<class S>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list);

    void clear();
    iterator begin()const ;
    iterator end()const ;
    iterator Rbegin();
    iterator Rend();

};


#include "LinkedList.cpp"
#endif //PROJECT1_CS008_LINKEDLIST_H
