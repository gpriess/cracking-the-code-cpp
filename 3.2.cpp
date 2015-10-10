#include "my_stack.h"

// From pg. 80:
// "How would you design a stack which, in addition to push and pop, 
// also has a function min which returns the minimum element? Push, 
// pop and min should all operate in O(1) time."
//

// Solution is implemented in my_stack.h
// main() below tests the functionality with a simple example.



int main() {
	Stack s;

	s.push(3);
	s.push(2);
	s.push(5);
	s.push(1);

	while(!s.isEmpty()) {
		std::cout << "min: " << s.min() << std::endl;
		std::cout << "pop: " << s.pop() << std::endl;
	}	


}