#include<iostream>

#include "BST_self_h.h"

using namespace std;

/*

The class is declared and defined in header files. We don't have to redefine here. 
We simply use the :: scope operator to write the function definition.

Reference template- https://www.codesdope.com/blog/article/binary-search-tree-in-c/

*/



// default constructor
BST_self::BST_self(){

    this->root = NULL;
    this->sz=0;
}


// copy constructor
BST_self::BST_self(const BST_self& B){

    this->root = NULL;
    this->sz=0;
    node* tmp=B.root;

    if(tmp!=NULL){
    	// add code to copy BST here
    }
}

// assignment operator
BST_self& BST_self::operator=(const BST_self& B){

    // check for self assignment 
    if(this != &B){

        BST_self temp(B);

        // Move Semantics (turn expensive copies to cheap moves)
        std::swap(root, temp.root);
        std::swap(sz, temp.sz);
    }

   return *this;    
}

BST_self::~BST_self(){

    this->remove_all();
}

int BST_self::find_minimum(){

	// add code

	return 0;
}

int BST_self::size() const{

	return this->sz;
}


// helper function that recursively calls itself to add nodes

node* insert(node* ptr, int n){
	if(ptr==NULL){
		ptr = new node;
    	ptr->data = n;

    	ptr->left_child = NULL;
    	ptr->right_child = NULL;
	}
	
	return ptr;
}

void BST_self::add_node(int n){
    if(this->root==NULL){
    	this->root=insert(this->root, n);
    }
    // n is greater. Should be inserted to right
    else if(n>this->root->data){
    	root->right_child = insert(root->right_child, n);
    } 

    // n is smaller should be inserted to left
    else{
    	root->left_child = insert(root->left_child, n);
    } 

    this->sz++;
}


void BST_self::remove_node(int n){
	// add code
}


void BST_self::remove_all(){
	// add code
}

void BST_self::display(){
	// add code

	cout<<this->sz<<"\n";
}

node* BST_self::search(int n) const{
	// add code

	return this->root;
}

node* BST_self::show_root() const{

	return this->root;
}

