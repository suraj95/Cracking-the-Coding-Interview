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

// helper function that calls itself recursively and adds the nodes
void iterate_add(BST_self& B, node* ptr){

	if(ptr!=NULL) // checking if the ptr is not null
    {
    	int data=ptr->data;

        iterate_add(B,ptr->left_child); // visiting left child
        B.add_node(data);
        iterate_add(B,ptr->right_child);// visiting right child
    }
}

// copy constructor
BST_self::BST_self(const BST_self& B){

    this->root = NULL;
    this->sz=0;

    node* tmp=B.root;
    iterate_add(*this,tmp); // node will trickle down
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

// helper function that recursively calls itself and finds the minimum node
node* find_minimum(node* ptr){

	if(ptr == NULL){
        return NULL;
	}

	// node with minimum value will have no left child
    else if(ptr->left_child != NULL){
    	return find_minimum(ptr->left_child); // left most element will be minimum
    }
        
    return ptr;
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

    // n is greater. Should be inserted to right
    else if(n>ptr->data){
    	ptr->right_child = insert(ptr->right_child, n);
    } 

    // n is smaller should be inserted to left
    else{
    	ptr->left_child = insert(ptr->left_child, n);
    } 

	return ptr;
}

void BST_self::add_node(int n){
    this->root=insert(this->root, n); // our node will trickle down  
    this->sz++;
}


// helper function that recursively calls itself to remove nodes
node* remove(node* ptr, int n){

	//searching for the item to be deleted
    if(ptr==NULL){
        return NULL;
    }

    if (n>ptr->data){
        ptr->right_child = remove(ptr->right_child, n);
    }
    else if(n<ptr->data){
        ptr->left_child = remove(ptr->left_child, n);
    }
    else
    {
        //No Children
        if(ptr->left_child==NULL && ptr->right_child==NULL)
        {
            delete ptr;
            return NULL;
        }

        //One Child
        else if(ptr->left_child==NULL || ptr->right_child==NULL)
        {
            node *temp;
            if(ptr->left_child==NULL)
                temp = ptr->right_child;
            else
                temp = ptr->left_child;
            delete ptr;
            return temp;
        }

        //Two Children
        else
        {
        	/*
				when node has two children, we simply replace node with the node containing
				the smallest item. Then that node will trickle down.
        	*/
            node *temp = find_minimum(ptr->right_child);
            ptr->data = temp->data;
            ptr->right_child = remove(ptr->right_child, temp->data);
        }
    }
    return ptr;
}

void BST_self::remove_node(int n){
	this->root=remove(this->root,n); // node will trickle down
	this->sz--;
}


// helper function that calls itself recursively and deletes the nodes
void iterate_delete(BST_self& B, node* ptr){

	if(ptr!=NULL) // checking if the ptr is not null
    {
    	int data=ptr->data;

        iterate_add(B,ptr->left_child); // visiting left child
        B.remove_node(data);
        iterate_add(B,ptr->right_child);// visiting right child
    }
}

void BST_self::remove_all(){
	node * tmp=this->root;
	iterate_delete(*this,tmp);
}


// helper function that recursively calls itself and prints nodes
void inorder(node* ptr){
/* 
	inorder representation means the parent node is printed in between the
	two children.
*/

	if(ptr!=NULL) // checking if the ptr is not null
    {
        inorder(ptr->left_child); // visiting left child
        cout<<ptr->data<<" \n";// printing data at node
        inorder(ptr->right_child);// visiting right child
    }
}


void BST_self::display(){
	inorder(this->root); // our node will trickle down 
}


node* BST_self::search(int n) const{
	// add code

	return this->root;
}

node* BST_self::show_root() const{

	return this->root;
}

