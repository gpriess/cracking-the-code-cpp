#pragma once
#include "my_node.h"
#include <iostream>

class LinkedList {

	Node* _head;

public:
	// constructors
	LinkedList(void) : _head(nullptr) { }
	LinkedList(int val);
	LinkedList(Node* head);
	
	// destructor
	~LinkedList(void);
	
	// methods
	Node* getHead() const {return _head;};
	LinkedList& append(int val);
	void print() const;
	void removeDuplicates();
	Node* findKthToLast(int k);
	void deleteNode(Node* node);
	void partitionAroundValue(int value);

};

LinkedList::LinkedList(int val) {
	_head = new Node(val);
}

//manually set a head
LinkedList::LinkedList(Node* head) {
	_head = head;
}

LinkedList::~LinkedList(void) {
	
	while(_head != nullptr) {
		Node* temp = _head;
		_head = _head->_next;
		delete temp;
	}
}


LinkedList& LinkedList::append(int val) {
	Node* end = new Node(val);
	Node* n = _head;
	//Linked list is empty
	if(n == nullptr) {
		_head = end;
		return *this;
	}
	//Linked list is non-empty
	while(n->_next) {
		n = n->_next;
	}
	n->_next = end;

	return *this;

}

void LinkedList::print() const {
	
	Node* n = _head;
	while(n) {
		std::cout <<  n->_val;
		if(n->_next) std::cout << " -> ";
		n = n->_next;

	}
	std::cout << std::endl;

}

