/**
 * Template Doubly Linked List - Main
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include "Tml_Dbl_LinkedList.h"
#include <iostream>

int main() {
	// Declare a linked list
	DlinkedList<int> list;

	// Insert to the linked list
	for (int i = 0; i < 10; ++i) {
		list.insertAtEnd(i);
	}

	// Declare a Node_Iterator
	DlinkedList<int>::iterator iter1 = list.begin();
	while (iter1 != list.end()) {
		std::cout << *iter1 << " ";
		++iter1;
	}

	// Declare a Node_Iterator
	DlinkedList<int>::iterator iter2 = list.getTail();
	while (iter2 != list.begin()) {
		std::cout << *iter2 << " ";
		--iter2;
	} 

	return 0;
}