#include<iostream>

#include "BST_self_h.h"

using namespace std;

/*

The class is declared and defined in header files. We don't have to redefine here. 
We simply use the :: scope operator to write the function definition.

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

int BST_self::size(){

	return this->sz;
}

void BST_self::add_node(int x){

	// add code
}


void BST_self::remove_node(int x){
	// add code
}


void BST_self::remove_all(){
	// add code
}

void BST_self::display(){
	// add code
}

node* search(int x) const{
	// add code

	return this->root;
}

node* show_root() const{

	return this->root;
}

