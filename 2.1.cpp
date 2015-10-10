#include "my_linked_list.h"
#include <iostream>

// From pg. 77:
// "Write code to remove duplicates from an unsorted linked list
// Follow up: how would you solve this problem if a temp buffer is
// not allowed?"
// Solution is declared in my_linked_list.h, and
// defined in LinkedList::removeDuplicates()




void LinkedList::removeDuplicates() {
	
	Node* unique = _head;
	Node* n = _head;
	while(unique != nullptr) {
		while(n->_next != nullptr) {
			if(unique->_val == n->_next->_val) {
				//remove duplicate
				Node* temp = n->_next->_next;
				delete n->_next;
				n->_next = temp;
			}
			else n = n->_next;
		}
		//finished searching for duplicates for 'unique'
		unique = unique->_next;
		n = unique;

	}

}



int main(){

	
	LinkedList l = LinkedList(0);
	l.append(1).append(2).append(2).append(1).append(3).append(4);
	l.print();
	l.removeDuplicates();
	l.print();


	return 0;


}