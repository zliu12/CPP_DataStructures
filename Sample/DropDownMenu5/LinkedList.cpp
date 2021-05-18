
#ifndef PROJECT1_CS008_LINKEDLIST_CPP
#define PROJECT1_CS008_LINKEDLIST_CPP

#include "LinkedList.h"
template<class T>
void LinkedList<T>::insertFirst(T item)
{ // creat a new node as first node
    //Node* n = new Node;
    //n->data = itembox;
    Node<T>* n = createNode(item);

    tail = n;
    head =n;

}

template<class T>
void LinkedList<T>::insertHead(T item){

    if(head == nullptr)    //if list is empty then create the node as first node
        insertFirst(item);
    else{
        // creat a new node  n
        Node<T>* n = new Node<T>;
        n->data = item;
        // n points to the next  is the head
        n->next = head;
        n->prev= nullptr;
        // and now the head is the new node n
        head = n;

    }
}
template<class T>
void LinkedList<T>::insertTail(T item)
{
    if(head == nullptr)    //if list is empty then create the node as first node
        insertFirst(item);
    else{
        // creat a new node  n
        Node<T>* n= createNode(item);
        // let current tail point to the new node that just create

        tail->next =n;
        n->next = nullptr;
        n->prev = tail;

        // now the tail  becomes to the new node that just create
        tail = n;

    }

}
template<class T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list){
    Node<T>* walker = list.head; //creat a walker at head

    while(walker != nullptr){
        // walker will go through the list from head to tail since the end is nullptr
        out<<walker -> data;
        walker= walker->next;
    }
    return out;
}
template<class T>
Node<T>* LinkedList<T>::createNode(T item)
{
    Node<T>* n = new Node<T>;
    n->data = item;
    n->next = nullptr;
    n->prev= nullptr;

    return n;
}
template<class T>
Node<T>* LinkedList<T>::find(T item)
{
    Node<T>* walker =head;
    // when walker is not empty and walker is not the itembox we are looking
    while(walker != nullptr && walker -> data != item)
    {
        // the walker is the one we are looking for
        // and walker point to next
        walker= walker->next;
    }
    return walker;
}
// 1) walk to the previous node *2) point previous next to the remove's next *3)delete remove
// case when list is empty
// case when only 1 itembox
// if remove ==tail
template<class T>
void LinkedList<T>::remove(Node<T>* node)
{
    if (node == nullptr)
        return;
    // if the list is empty
    if(head == nullptr)
        return;

    Node<T>* previous = previousNode(node);
    Node<T>* next = nextNode(node);
    // check is there is only one itembox
    if(head == tail)
    {
        head = nullptr;
        tail = nullptr;
        delete node;
    }
    else if (node == tail)
    { // if you want to remove tail
        tail = previous;
        tail->next = nullptr;
        delete node;
    }
    else if(node == head)
    { // if you want to remove head
        head = head->next;
        head->prev= nullptr;
        delete node;
    }
    else{
        // if you want to remove node in the middle of the list
        previous->next =node->next;
        next->prev = node->prev;

        delete node;
    }
}
template<class T>
void LinkedList<T>::remove(T item)
{   // call remove(Node* node) function and remove the pointer from find function
    remove(find(item));

}

template<class T>
Node<T>* LinkedList<T>::previousNode(Node<T>* node)
{   // find the previous node of the target node
    Node<T>* walker = head;
    while(walker != nullptr && walker->next != node )
    {
        walker= walker->next;
    }
    return walker;
}
template<class T>
Node<T>* LinkedList<T>::nextNode(Node<T>* node)
{   // find the previous node of the target node
    Node<T>* walker = head;
    while(walker != nullptr && walker->prev != node )
    {
        walker= walker->prev;
    }
    return walker;
}

template<class T>
Node<T>* LinkedList<T>::previousNode(T item)
{
    return previousNode(find(item));
}
//destructor
// destroyed the linked list and clear the memory

template<class T>
LinkedList<T>::~LinkedList(){
    while(head !=nullptr)
    {
        remove(head);
        //std::cout<<*this<<std::endl;
    }

}
template<class T>
int LinkedList<T>::Size(const LinkedList<T>& list)
{
    int n=0;
    current = list.head;
    while(current != nullptr)
    {
        n++;
        current = current->next;
    }
    return n;
}

template<class T>
LinkedList<T>::LinkedList()
{ // constructor
    head = nullptr;
    tail = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& list) : LinkedList()
{
    // it is going to call assignment operator
    //' *this ' is going to be the left side
    // 'list' is going to be the right side
    //(*this).operator=(list);  // same as the line below
    *this = list;

}
template<class T>
LinkedList<T>& LinkedList<T>::operator += (const int item){
    if(head == nullptr)    //if list is empty then create the node as first node
        insertFirst(item);
    else{
        // creat a new node  n
        Node<T>* n= createNode(item);
        // let current tail point to the new node that just create

        tail->next =n;
        n->next = nullptr;
        n->prev = tail;

        // now the tail  becomes to the new node that just create
        tail = n;
    }
    return *this;

}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list){
    // "this" and &list are an address
    if(this == &list)
        return *this;

    // call destructor to delete left side of the assignment operator ,
    // before we assign the right side.
    this->~LinkedList();
    // copy every from the list
    Node<T>* walker = list.head;
    //walker through all the nodes of the linked list
    // then add its data to the linked list
    while(walker !=nullptr)
    {
        insertTail(walker->data);
        walker += walker->next;
    }
    return *this;

}


template<class T>
void LinkedList<T>::removeHead() {
    remove(head);
}

template<class T>
void LinkedList<T>::removeTail() {
    remove(tail);
}
template<class T>
bool LinkedList<T>::isEmpty()const
{
    if(head == nullptr) {
        //std::cout << " List is empty" << std::endl;
        return true;
    }else{
        //std::cout << " List is not empty" << std::endl;
        return false;

    }

}

//int LinkedList::getHead()
template<class T>
T LinkedList<T>::getHead()
{
    if(head != nullptr)
        return head->data;
}
template<class T>
T LinkedList<T>::getTail()
{
    if(head != nullptr)
        return tail->data;
}
template<class T>
T LinkedList<T>::seek(int n){
    Node<T>* walker = head;
    int i=0;
    while(walker != nullptr && i<n)
    {
        walker = walker->next;
        i++;
    }
    if(walker != nullptr)
    {
        walker->data;
    }
    else if(tail != nullptr)
    {
        return tail->data;
    }
    return T();

}
template<class T>

void LinkedList<T>::clear()
{
    Node<T>* walker = head;
    //Node<T>* prev;
    while(walker != nullptr)
    {
       // prev = walker;
        walker = walker->next;
        delete walker;
    }
    head=nullptr;
    tail=nullptr;
}
template<class T>
typename LinkedList<T>::iterator LinkedList<T>::begin()const
{
    return Node_iterator<T>(head);

}
template<class T>
typename LinkedList<T>::iterator LinkedList<T>::end()const
{
    return Node_iterator<T>(nullptr);

}
template<class T>
typename LinkedList<T>::iterator LinkedList<T>::Rbegin(){
    return Node_iterator<T>(tail);

}
template<class T>
typename LinkedList<T>::iterator LinkedList<T>::Rend(){

    return Node_iterator<T>(nullptr);
}


#endif
