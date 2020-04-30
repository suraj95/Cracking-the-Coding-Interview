#ifndef stack_self_h
#define stack_self_h

class stack_self{

private:
	linked_list L; // stack implemented using our linked_list class

public:
	stack_self();
	stack_self(const stack_self& S);
	stack_self& operator=(const stack_self& S);
	~stack_self();
	
	void push(int n);
	void pop();
	int peek() const;
	int size() const;
	void display();
};

#endif
