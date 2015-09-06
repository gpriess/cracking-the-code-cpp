#include "my_linked_list.h"


// From pg. 77:
// "Implement an algorithm to find the kth to 
//last element of a singly linked list."
// Solution is declared in my_linked_list.h, and
// defined below in LinkedList::findKthToLast()



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



int main(){

	
	LinkedList l = LinkedList(0);
	l.append(1).append(2).append(2).append(1).append(3).append(4);
	l.print();
	for(int k = 0; k <= 7; k++) {
		Node* n = l.findKthToLast(k);
		if(n != nullptr)
			std::cout << k << " to last has val: " << n->getValue() << std::endl;
		else std::cout << k << " to last element doesn't exist" << std::endl;
	}

	return 0;


}