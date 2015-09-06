#include "my_linked_list.h"


// From pg. 77:
// "Implement an algorithm to delete a node in the middle of a singly linked
// list, given only access to that node. "
// Solution is declared in my_linked_list.h, and
// defined below in LinkedList::deleteNode()



void LinkedList::deleteNode(Node* node) {
	
	Node* ptr = _head;

	while(ptr != nullptr && ptr->_next != node)
		ptr = ptr->_next;
	if(ptr == nullptr)
		return;
	Node* temp = ptr->_next->_next;
	delete ptr->_next;
	ptr->_next = temp;

}

//-----------------------------------------------------------
//COPIED FROM 2.2.cpp FOR TESTING CONVENIENCE
Node* LinkedList::findKthToLast(int k) {
	
	Node* n = _head;
	int totalElements = 0;
	while(n != nullptr) {
		totalElements++;
		n = n->_next;
	}
	if(k >= totalElements) {
		//return nullptr if there is not a kth to
		//last element
		return nullptr;
	}
	int i = 0;
	n = _head;
	while(n != nullptr && ((totalElements - 1 - i) > k)) {
		n = n->_next;
		i++;
	}

	return n;
}
//COPIED FROM 2.2.cpp FOR TESTING CONVENIENCE
//-----------------------------------------------------------

int main(){

	
	LinkedList l = LinkedList(0);
	l.append(1).append(2).append(2).append(1).append(3).append(4);
	l.print();
	int k = 0;
	Node* n = l.findKthToLast(k);
	if(n != nullptr)
		l.deleteNode(n);

	l.print();

	return 0;


}