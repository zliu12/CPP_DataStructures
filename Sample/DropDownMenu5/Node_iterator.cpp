#ifndef PROJECT1_NODE_ITERATOR_CPP
#define PROJECT1_NODE_ITERATOR_CPP

#include "Node_iterator.h"
#include <iterator>
template<class T>
Node_iterator<T>&Node_iterator<T>::operator++(){//PREFIX
    current = current->next;
    return *this;
}

template<class T>
Node_iterator<T> Node_iterator<T> ::operator++(int){
    Node_iterator<T> temp =*this;
    current = current->next;
    return temp;
}
template<class T>
Node_iterator<T>&Node_iterator<T>:: operator--(){//PREFIX
    current = current->prev;
    return *this;
}

template<class T>
Node_iterator<T> Node_iterator<T> ::operator--(int){
    Node_iterator<T> temp =*this;
    current = current->prev;
    return temp;
}

template<class T>
T& Node_iterator<T>::operator*(){
    return current->data;
}
// dereference operator
template<class T>
T&Node_iterator<T>:: operator*() const{
    return current->data;
}

template<class T>
bool operator==(const Node_iterator<T>& left, const Node_iterator<T>& right){
    return left.current == right.current;
}

template<class T>
bool operator!=(const Node_iterator<T>& left, const Node_iterator<T>& right)
{
    return left.current != right.current;

}

template<class T>
Node_iterator<T>::Node_iterator():current(nullptr){

}

template<class T>
Node_iterator<T>::Node_iterator(Node<T>* node):current(node){

}
template<class T>
Node_iterator<T> operator+(const Node_iterator<T>& left, int steps)
{
    Node_iterator<T>temp(left);
    for(int i=0;i<steps; i++)
    {
        if((temp.current != nullptr)&& (temp.current->next !=nullptr))
        {
            temp.current = temp.current->next;
        }
    }
    return temp;
}

#endif
