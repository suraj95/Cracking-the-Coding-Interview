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
	int sz; 

public:
	linked_list();
	linked_list(const linked_list& L);
	~linked_list();
	
	void add_node(int n);
	void display() const;
	void remove_node(int n);

	int size() const;

	node* show_head() const;

};

#endif
