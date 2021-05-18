#ifndef PROJECT1_STACK_CPP
#define PROJECT1_STACK_CPP
#include "Stack.h"
template<class T>
void Stack<T>::pop(){
    Node<T>* n = this->getTail();
    this->remove(n);
}
template<class T>
void Stack<T>::push(T item){
    this->insertTail(item);
}

template<class T>
T Stack<T>::top(){
    return this->getTail()->data;
}
template<class T>
T Stack<T>::seek(int n){
    Node<T>* walker = this->getTail();
    if (n<this->size()){
        for(int i=1;i<=n; i++) {
            walker = walker->prev;
        }
        return walker->data;
    }

}

#endif // PROJECT1_STACK_CPP