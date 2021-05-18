
#ifndef PROJECT1_NODE_ITERATOR_H
#define PROJECT1_NODE_ITERATOR_H

//#include "LinkedList.h"
#include "Node.h"
#include <iterator>
#include <vector>

template<class T>
class Node_iterator :public std::iterator<std::forward_iterator_tag,T> {
private:
    Node<T>* current;

public:
    Node_iterator& operator++();
    Node_iterator operator++(int);
    Node_iterator& operator--();
    Node_iterator operator--(int);
    T& operator*();
    T& operator*() const;

    template<class S>
    friend Node_iterator<S> operator+(const Node_iterator<S>&left, int steps);


    template<class S>
    friend bool operator==(const Node_iterator<S>&left, const Node_iterator<S>& right);
    template<class S>
    friend bool operator!=(const Node_iterator<S>&left, const Node_iterator<S>& right);
    Node_iterator();
    Node_iterator(Node<T>* node);


    template<class S>
    friend bool operator==(const Node_iterator<S>& left, const Node_iterator<S>& right);

    template<class S>
    friend bool operator!=(const Node_iterator<S>& left, const Node_iterator<S>& right);


};

#include "Node_iterator.cpp"
#endif //PROJECT1_CS008_NODE_ITERATOR_H
