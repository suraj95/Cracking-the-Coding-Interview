#ifndef linked_list_h
#define linked_list_h

// declare struct only once, ideally in the header
struct node{
	int data;
	node* next;	
};

class linked_list{

private:
	node *head;
	int sz; 

public:
	linked_list();
	linked_list(const linked_list& L);
	linked_list& operator=(const linked_list& L);
	~linked_list();
	
	void add_node(int n);
	void remove_node(int n);
	void remove_all();
	void remove_duplicates();
	
	bool check_palindrome();

	int size() const;
	int kth_to_last(int k) const;
	void display();
	int represent_number();

	node* show_head() const;

};

#endif
