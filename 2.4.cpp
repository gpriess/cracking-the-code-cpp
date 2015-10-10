#include "my_linked_list.h"
#include <iostream>

// From pg. 77:
// "Write code to partition a linked list around a value x, 
//such that all nodes less than x come before all nodes greater than 
// or equal to x."
// Solution is declared in my_linked_list.h, and
// defined below in LinkedList::partitionAroundValue()



void LinkedList::partitionAroundValue(int value) {
	
	Node* ptr = _head;
	//less is a pointer to stay on rightmost node that contains value
	//strictly less than 'value'
	//moreOrEqual is a pointer to stay on leftmost node that contains value
	//greater than or equal to 'value'
	Node* less = nullptr;
	Node* moreOrEqual = nullptr;
	_head = nullptr;
	while(ptr != nullptr) {
		//preserve next element to iterate to
		Node* temp = ptr->_next;
		if(ptr->_val < value) {
			if(less == nullptr) {
				_head = ptr;
				less = ptr;
			}
			else {
				less->_next = ptr;
				less = less->_next;
			}
		}
		else { // ptr->_val >= value

			Node* temp = moreOrEqual;
			moreOrEqual = ptr;
			moreOrEqual->_next = temp;
		}
		ptr = temp;
	}
	if(_head == nullptr)	_head = moreOrEqual;
	else 	less->_next = moreOrEqual;

	return;

}


int main(){

	
	LinkedList l = LinkedList(0);
	l.append(2).append(1).append(2).append(1).append(3).append(4);
	std::cout << "before: "; l.print();
	int value = 2;
	l.partitionAroundValue(value);
	std::cout << "after:  "; l.print();

	return 0;


}