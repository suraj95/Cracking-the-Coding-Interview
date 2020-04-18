#ifndef linked_list_h
#define linked_list_h

// declare struct only once, ideally in the header
struct node{
	int data;
	node* next;	
};

class linked_list{

private:
	node *head, *tail;

public:
	linked_list();
	
	void add_node(int n);
	void display();

	node* show_head();
		
};

#endif
