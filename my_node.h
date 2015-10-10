
class Node {

private:	
	int _val;
	Node* _next;
	Node* _prev;

	//friend class forward declaration
	friend class LinkedList;
	friend class Stack;

public:
	// constructors
	Node(void) : _next(nullptr) { }
	Node(int val) : _val(val), _next(nullptr), _prev(nullptr) { }
	Node(int val, Node* next) : _val(val), _next(next), _prev(nullptr) { }

	// methods
	int getValue(void) { return _val; }
	Node* getNext(void) { return _next; }
	void setNext(Node* next) { _next = next;}

};