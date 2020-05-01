#ifndef queue_self_h
#define queue_self_h

class queue_self{

private:
	stack_self S1; // Queue implemented using two stacks from our stack_self class
	stack_self S2;

public:
	queue_self();
	queue_self(const queue_self& S);
	queue_self& operator=(const queue_self& S);
	~queue_self();
	
	void enqueue(int n);
	void dequeue();
	int peek() const;
	int size() const;
	void display();
};

#endif
