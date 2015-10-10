#include "my_linked_list.h"
#include <iostream>

// From pg. 77:
// "You have two numbers represented by a linked list, where each 
// node contains a single digit. The digits are stored in reverse 
// order, such that the 1's digit is at the head of the list. Write 
// a function that adds the two numbers and returns the sum as a linked list.
//
// Using custom LinkedList defined in my_linked_list.h.
// Solution is defined below in function addReversedLists()


unsigned sumReversedList(const LinkedList& list) {
	unsigned sum = 0;
	unsigned tensMultiplier = 1;
	Node* node = list.getHead();
	while(node) {
		sum += node->getValue()*tensMultiplier;
		tensMultiplier *= 10;
		node = node->getNext();
	}

	return sum;
}

unsigned sumForwardList(const LinkedList& list) {
	unsigned sum = 0;
	unsigned tensMultiplier = 1;
	Node* node = list.getHead();
	//calculate tens position
	while(node) { 
		tensMultiplier *= 10;
		node = node->getNext();
	}

	node = list.getHead();	
	while(node) {
		tensMultiplier /= 10;
		sum += node->getValue()*tensMultiplier;
		node = node->getNext();
	}

	return sum;
}

unsigned addForwardLists(const LinkedList& list1, const LinkedList& list2) {

	return sumForwardList(list1) + sumForwardList(list2);
}

unsigned addReversedLists(const LinkedList& list1, const LinkedList& list2) {

	return sumReversedList(list1) + sumReversedList(list2);
}

int main() {

	LinkedList list1 = LinkedList(7);
	list1.append(1).append(6);
	LinkedList list2 = LinkedList(5);
	list2.append(9).append(2);
	std::cout << "expected: 912 ";
	std::cout << "result: " << addReversedLists(list1, list2) << std::endl;
	std::cout << "expected: 1308 ";
	std::cout << "result: " << addForwardLists(list1, list2) << std::endl;

	return 0;
}