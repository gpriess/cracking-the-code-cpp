#include "my_linked_list.h"
#include <iostream>
#include <unordered_set>

// From pg. 78:
// "Implement a function to check if a linked list is a palindrome. "
//
// Using custom Node defined in my_linked_list.h.
// Solution is defined below in function isPalindrome()
// relies on reverseLinkedList(), which returns a reversed copy of
// a linked list.

LinkedList reverseLinkedList(const LinkedList& list) {
	

	Node* orig = list.getHead();
	Node* reversedNode = nullptr;
	Node* reversedNextNode = nullptr;
	while(orig) {
		reversedNode = new Node(orig->getValue(), reversedNextNode);
		reversedNextNode = reversedNode;
		orig = orig->getNext();

	}
	LinkedList rev = LinkedList(reversedNode);
	return rev;
}


bool isPalindrome(const LinkedList& list) {

	LinkedList reversed = reverseLinkedList(list);
	Node* reversedNode = reversed.getHead();
	Node* node = list.getHead();
	while(node != nullptr && reversedNode != nullptr)
	{
		if(node->getValue() != reversedNode->getValue())
			return false;
		node = node->getNext();
		reversedNode = reversedNode->getNext();
	}

	return true;
}


int main(int argc, char const *argv[])
{
	LinkedList l = LinkedList(0);
	l.append(2).append(1).append(2).append(1).append(2).append(0);
	l.print();
	LinkedList rev = reverseLinkedList(l);
	rev.print();

	std::cout << "list is ";
	if(!isPalindrome(l)) std::cout << "not ";
	std::cout << "palindrome." << std::endl;






	return 0;
}

