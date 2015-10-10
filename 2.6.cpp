#include "my_linked_list.h"
#include <iostream>
#include <unordered_set>

// From pg. 78:
// "Given a circular linked list, implement an 
// algorithm which returns the node at the beginning of the loop. "
//
// Using custom Node defined in my_linked_list.h.
// Solution is defined below in function findCircularBeginning()
// Also defined is detectCircularList(), which efficiently determines
// whether a given linked list is circular.

bool detectCircularList(Node* head) {

	Node* fastPtr = head;
	Node* slowPtr = head;
	
	while(fastPtr != nullptr && slowPtr	!= nullptr) {
		fastPtr = fastPtr->getNext();
		if(fastPtr == nullptr)	break;
		if(fastPtr == slowPtr)	return true;
		fastPtr = fastPtr->getNext();
		if(fastPtr == nullptr)	break;
		if(fastPtr == slowPtr)	return true;
		slowPtr = slowPtr->getNext();
	}

	return false;
}


Node* findCircularBeginning(Node* head) {

	Node* n = head;
	std::unordered_set<Node *> nextPointers;
	std::unordered_set<Node *>::iterator res;
	
	while(n) {
		if(n->getNext() == nullptr)
			return nullptr;
		res = nextPointers.find(n->getNext());
		if(res == nextPointers.end())
			nextPointers.insert(n->getNext());
		else
			return n->getNext();

		n = n->getNext();
	}

	return nullptr;
}

int main(int argc, char const *argv[])
{
	//Circular construction:
	// 1 -> 2 -> 3 -> 4 -> 5 -> 3 (where last 5 -> 3 -> 4 -> 5 loop)
	
	Node* five = new Node(5);
	Node* four = new Node(4, five);
	Node* three = new Node(3, four);
	Node* two = new Node(2, three);
	Node* one = new Node(1, two);
	five->setNext(three);

	std::cout << "list is ";
	if(!detectCircularList(one)) std::cout << "not ";
	std::cout << "circular." << std::endl;

	if(detectCircularList(one))
		std::cout << "circular beginning val: " << 
			findCircularBeginning(one)->getValue() << std::endl;






	return 0;
}

