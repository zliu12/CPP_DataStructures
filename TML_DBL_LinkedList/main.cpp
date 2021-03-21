/**
 * Template Doubly Linked List - Main
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <iostream>
#include "Tml_Dbl_LinkedList.h"
using std::cout;
using std::endl;

int main() {
	DlinkedList<int> list;
	DlinkedList<int> list2;
	int num;

	// check if the list is empty
	if (list.listEmpty()) {
		cout << "list is empty" << endl;
	} else {
		cout << "list is not empty" << endl;
	}

	// Insert 7 to the list
	list.insertAtBegin(7);
	// list = 7
	cout << "Insert 7 to the empty list: " << list << endl;

	// check if the list is empty
	if (list.listEmpty()) {
		cout << "list is empty" << endl;
	} else {
		cout << "list is not empty" << endl;
	}

	// Insert 2 at the end of the list
	list.insertAtEnd(2);
	// list = 7 2
	cout << "Insert 2 at the end of the list: " << list << endl;

	// Overload the += operator to insert 3 at the end of the list
	list += 3;
	// list = 7 2 3
	cout << "Using += to insert 3 at the end of the list: " << list << endl;

	// Insert 4 at the beginning of the list
	list.insertAtBegin(4);
	// list = 4 7 2 3
	cout << "Insert 4 at the beginning of the list:" << list << endl;

	// Insert 1 before 2
	list.insertBeforeNode(1, 2);
	// list = 4 7 1 2 3
	cout << "Insert 1 before 2 to the list: " << list << endl;

	// Insert 0 after 1
	list.insertAfterNode(0, 1);
	// list = 4 7 1 0 2 3
	cout << "Insert 0 after 1 to the list: " << list << endl;

	// Remove 1 from the list
	list.remove(1);
	// list = 4 7 0 2 3
	cout << "Remove 1 out of the list: " << list << endl;

	// Check size of the list
	// list size = 5
	cout << "list size: " << list.getSize() << endl;

	// Find 7
	num = 7;
	if (list.findValue(num)) {
		cout << num << " found" << endl;
	} else {
		cout << num << " not found" << endl;
	}

	// Fine 77
	num = 77;
	if (list.findValue(num)) {
		cout << num << " found" << endl;
	} else {
		cout << num << " not found" << endl;
	}

	// Copy the list
	list2 = list;
	cout << "list2 copied from the list: " << list2 << std::endl;

	// Clear the list2
	list2.removeALL();
	if (list2.listEmpty()) {
		cout << "list2 cleared" << endl;
	} else {
		cout << "list2 not cleared: " << list2 << endl;
	}

	// Clear the list
	list.removeALL();
	if (list2.listEmpty()) {
		cout << "list cleared" << endl;
	} else {
		cout << "list not cleared: " << list << endl;
	}

	return 0;
}