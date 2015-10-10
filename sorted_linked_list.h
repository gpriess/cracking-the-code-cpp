#pragma once
#include <iostream>


class Node {

public:
	int val;
	Node* next;
	Node* prev;

	// constructors
	Node(int val_in) : val(val_in), next(nullptr), prev(nullptr) { }


};


class SortedLinkedList {

	Node* head;
	Node* tail;

public:
	// constructors
	SortedLinkedList(void) : head(nullptr) { }
	SortedLinkedList(int val);
	SortedLinkedList(Node* head);
	
	// destructor
	~SortedLinkedList(void);
	
	// methods
	Node* getHead() const {return head;};
	SortedLinkedList& insert(int val);
	void print() const;

};

SortedLinkedList::SortedLinkedList(int val) {
	head = new Node(val);
	tail = head;

}

//manually set a head
SortedLinkedList::SortedLinkedList(Node* head_in) {
	head = head_in;
}

SortedLinkedList::~SortedLinkedList(void) {
	
	while(head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}


SortedLinkedList& SortedLinkedList::insert(int val) {
	Node* element = new Node(val);
	if(head == nullptr)
	{
		head = element;
		tail = element;
		return *this;
	}	
	Node* p = head;
	//insert at beginning
	if(val < p->val)
	{
		head = element;
		head->next = p;
		p->prev = head;
		return *this;
	}
	while(p->next != nullptr && p->val < val) {
		p = p->next;
	}
	//p->next == nullptr or p->val >= val
	if(p->val >= val) {
		Node* prev = p->prev;
		p->prev = element;
		element->next = p;
		element->prev = prev;
		prev->next = element;
	}	
	else {
		p->next = element;
		tail = element;
	}
	return *this;

}

void SortedLinkedList::print() const {
	
	Node* n = head;
	while(n) {
		std::cout <<  n->val;
		if(n->next) std::cout << " -> ";
		n = n->next;

	}
	std::cout << std::endl;

}

