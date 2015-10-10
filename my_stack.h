#pragma once
#include "my_node.h"
#include <iostream>


class Stack {

	Node* _top;
	Node* _min;

public:
	// constructors
	Stack(void) : _top(nullptr), _min(nullptr) { }
	Stack(int val);
	
	// destructor
	~Stack(void);
	
	// methods
	bool isEmpty() const {return (_top == nullptr); };
	int peek() const {return _top->getValue();};
	int min() const {return _min->getValue();};
	int pop();
	void push(int val);

};

Stack::Stack(int val) {
	_top = new Node(val);
}

Stack::~Stack(void) {
	
	while(_top != nullptr) {
		Node* item = _top;
		_top = _top->_next;
		delete item;
	}
}
int Stack::pop() {

	if(_top != nullptr) {
		//maintain _min
		if(_top->_val == _min->_val) {
			Node * temp = _min;
			_min = _min->_next;
			delete temp;
		}
		
		int val = _top->_val;
		Node * temp = _top;
		_top = _top->_next;
		delete temp;
		return val;
	}

	else return 0;
}
void Stack::push(int val) {
	Node* new_top = new Node(val, _top);
	new_top->_next = _top;
	_top = new_top;

	//maintain _min
	if(_min == nullptr || _top->_val < _min->_val) {
		Node* new_min = new Node(val, _top);
		new_min->_next = _min;
		_min = new_min;
	}
}

