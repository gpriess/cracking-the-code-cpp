#include <iostream>
#include <vector>

// From pg. 80:
// "Describe how you could use a single array to implement three stacks."
//

// Solution is defined below in function isPalindrome()
// relies on reverseLinkedList(), which returns a reversed copy of
// a linked list.
const int NUM_OF_STACKS = 3;
const int SIZE_OF_EACH_STACK = 30;

class Stack {

	//each _top[x] corresponds to an index of a stack in _stacks
	//if a _top is set to -1, that stack is empty

	int _top[NUM_OF_STACKS];
	std::vector<int> _stacks; 


public:
	// constructors
	Stack(void);
	
	
	// methods require stack argument specifying 
	// index of which stack you want to use
	bool isEmpty(int stack) const {return (_top[stack] == -1); };
	int peek(int stack) const {return _stacks[_top[stack]]; };
	int pop(int stack);
	void push(int stack, int val);


};

Stack::Stack(void) {

	_stacks.resize(NUM_OF_STACKS * SIZE_OF_EACH_STACK);
	for(int i = 0; i < NUM_OF_STACKS; i++) {
		_top[i] = -1;
	}
}

int Stack::pop(int stack) {
	int indexOfTop = (stack)*((_stacks.size())/(NUM_OF_STACKS));
	int temp = _stacks[_top[stack]];
	if(_top[stack] != indexOfTop)	_top[stack]--;
	else	_top[stack] = -1;
	
	return temp;
}

void Stack::push(int stack, int val) {
	int indexOfTop = (stack)*((_stacks.size())/(NUM_OF_STACKS));
	
	//stack is empty
	if(_top[stack] == -1) {
		_top[stack] = indexOfTop;
		_stacks[_top[stack]] = val;
		return;
	}
	//val can be inserted into stack
	if(_top[stack] < (stack + 1)*((_stacks.size())/(NUM_OF_STACKS))) {
		_top[stack]++;
		_stacks[_top[stack]] = val;
		return;
	}
	
	// stack is full (val cannot be pushed)
	return;
}


int main() {

	Stack stack;
	std::cout << "stack 0:" << std::endl;
	stack.push(0, 1);
	stack.push(0, 2);
	std::cout << stack.peek(0) << std::endl;
	std::cout << stack.pop(0) << std::endl;
	if(stack.isEmpty(0)) std::cout << "stack is empty" << std::endl;
	else std::cout << "stack is not empty" << std::endl;
	std::cout << stack.pop(0) << std::endl;
	if(stack.isEmpty(0)) std::cout << "stack is empty" << std::endl;
	else std::cout << "stack is not empty" << std::endl;
	std::cout << "stack 1:" << std::endl;
	stack.push(1, 4);
	stack.push(1, 6);
	std::cout << stack.pop(1) << std::endl;
	std::cout << stack.pop(1) << std::endl;


}