#include<iostream>
#include<cstdlib>
#include<queue>

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


// helper function that clones nodes
node* clone_node(node* orgNode){

	if(orgNode!=NULL){
		node* ptr = new node;
		ptr->data = orgNode->data;

    	ptr->left_child=NULL;
    	ptr->right_child=NULL;

    	return ptr;
	}

	else{
		return NULL;
	}
}

// helper function that copies trees
void copy_inorder(node* copyTree, node* orgTree){

    if(orgTree !=NULL){

        //left side
        node* newLeftNode = clone_node(orgTree->left_child);
        copyTree->left_child = newLeftNode;
        copy_inorder(copyTree->left_child, orgTree->left_child);

        //right side
        node* newRightNode = clone_node(orgTree->right_child);
        copyTree->right_child = newRightNode;
        copy_inorder(copyTree->right_child, orgTree->right_child);
    }
}


/*

The structure of the BST is based on the order in which the elements are added. So, even if you use 
the same elements, but populate in a different order, you will get a different tree. That is why it is
important to "clone" the tree properly. 

*/

// copy constructor
BST_self::BST_self(const BST_self& B){

    this->root = NULL;  // just to make sure pointer is initialized
    this->sz=0;

    node* tmp=B.show_root();
    this->root=clone_node(tmp);
    copy_inorder(this->root, tmp); // node will trickle down
    this->sz=B.size();
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
	
	iterate_delete(*this,this->root); // node will trickle down
}


// helper function that recursively calls itself and prints nodes
void print_inorder(node* ptr){
/* 
	inorder representation means the parent node is printed in between the
	two children.
*/

	if(ptr!=NULL) // checking if the ptr is not null
    {
        print_inorder(ptr->left_child); // visiting left child
        cout<<ptr->data<<" \n";// printing data at node
        print_inorder(ptr->right_child);// visiting right child
    }
}


void BST_self::display(){
    
	print_inorder(this->root); // our node will trickle down 
}


// helper function that recursively calls itself and searches the node
node* iterate_search(node* ptr, int n){

	//if root->data is n then the element is found
	if(ptr==NULL || ptr->data==n){
		return ptr;
	} 

	// n is greater, so we will search the right subtree
    else if(n>ptr->data){
    	return iterate_search(ptr->right_child, n);
    } 
      
    // n is smaller than the data, so we will search the left subtree
    else{
    	return iterate_search(ptr->left_child, n);
    }
}

node* BST_self::search(int n) const{

	node* result=iterate_search(this->root,n);

/*
	NULL is a “manifest constant” (a #define of C) that’s actually an integer that can be assigned to
	a pointer because of an implicit conversion. nullptr is a keyword representing a value of 
	self-defined type, that can convert into a pointer, but not into integers.
*/

	// if NULL is returned, that means a hit has not been found
	if(result!=NULL){
		cout<<"Node found !\n";
		return result;
	}
	else{
		cout<<"Node not found\n";
		return nullptr;
	}
}


node* BST_self::show_root() const{

	return this->root;
}

/*
    We cannot use a recursive function like we used before for add, remove and search because
    we will have to keep track of how many times it was called using a global variable, or
    through arguments in the function. So the iterative solution is a lot cleaner and concise.
*/
node* BST_self::random_node() const{

    if(this->root==NULL){
        return nullptr;
    }

    // not using self-implemented queue because it is hardcoded to integer data type
    queue <node*> q;
    q.push(this->root);

/*
    Using rand function and the modulus operator is usually discouraged because it may not generate 
    numbers uniformly (it depends on the range and the value of RAND_MAX). I'll stick to this for now.
*/

    int idx=rand()%this->size();

    std::vector <node*> result;

    while(!q.empty()){

        node *temp = q.front();
        q.pop(); 

        if(temp->left_child != NULL){
            q.push(temp->left_child); 
        }
        if(temp->right_child != NULL){
            q.push(temp->right_child); 
        }

        result.push_back(temp);
    }

    return result[idx];
}


// helper function that calculates the max depth of a node
int maxDepth(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left_child);  
        int rDepth = maxDepth(node->right_child);  
      
        /* use the larger one */
        if (lDepth > rDepth) {
            return(lDepth + 1);  
        }
        else{
            return(rDepth + 1);  
        }
    }  
}  

/*
    A balanced tree is defined to be a tree such that the heights of the two subtrees of any node 
    never differ by more than one.

    For now, I am just checking the depth of the root nodes children for simplicity.
*/

bool BST_self::check_balanced() const{

    return maxDepth(this->root->left_child)==maxDepth(this->root->right_child);
}

bool iterate_check(node* ptr){
    if(ptr==NULL){
        return true;
    }

    // left_child is NULL
    else if(ptr->left_child==NULL && ptr->right_child!=NULL){
        return ptr->data < ptr->right_child->data && iterate_check(ptr->right_child);
    }

    // right_child is NULL
    else if(ptr->left_child!=NULL && ptr->right_child==NULL){
        return iterate_check(ptr->left_child) && ptr->left_child->data < ptr->data;
    }

    // both children are NULL
    else if(ptr->left_child==NULL && ptr->right_child==NULL){
        return true;
    }

    // no children are NULL
    else if(ptr->left_child!=NULL && ptr->right_child!=NULL){
        return iterate_check(ptr->left_child) && 
        ptr->left_child->data < ptr->data < ptr->right_child->data &&
        iterate_check(ptr->right_child);
    }

    // Program won't reach here. Adding this just to remove Compiler warning. 
    else{
        return false;
    }

}

bool BST_self::validate_BST() const{

    return iterate_check(this->root); // node will trickle down
}

