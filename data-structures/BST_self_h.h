#ifndef BST_self_h
#define BST_self_h

// declare struct only once, ideally in the header
struct node{
	int data;
	node* left_child;
	node* right_child;
};

class BST_self{

private:
	node* root;
	int sz;

public:
	BST_self();
	BST_self(const BST_self& B);
	BST_self& operator=(const BST_self& B);
	~BST_self();

	int size() const;

	void add_node(int n);
	void remove_node(int n);
	void remove_all();
	void display();

	node* search(int n) const;
	node* show_root() const;
	node* random_node() const;
};




#endif
