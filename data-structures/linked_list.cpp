#include<iostream>
#include<set>

#include "linked_list_h.h"

using namespace std;

/*

The class is declared and defined in header files. We don't have to redefine here. 
We simply use the :: scope operator to write the function definition.

*/


// default constructor
linked_list::linked_list(){

    this->head = NULL;
    this->sz=0;
}

/*

Copy constructor is called when a new object is created from an existing object, 
as a copy of the existing object. And assignment operator is called when an already 
initialized object is assigned a new value from another existing object.

*/

// copy constructor
linked_list::linked_list(const linked_list& L){

    this->head=NULL;
    this->sz=0;

    node* tmp=L.head;

    while(tmp->next!=NULL){
        int item=tmp->data;
        this->add_node(item); 

        tmp=tmp->next;
    }

    int last_item=tmp->data;
    this->add_node(last_item);
}

// assignment operator
linked_list& linked_list::operator=(const linked_list& L){

    // check for self assignment 
    if(this != &L){

        linked_list temp(L);

        // Move Semantics (turn expensive copies to cheap moves)
        std::swap(head, temp.head);
        std::swap(sz, temp.sz);
    }

   return *this;    
}

/* 

delete does not set pointer to null. It simply deallocates the memory the pointer points to. 
We cannot just straightaway delete from the front because the moment we delete a node, we lose the 
pointers to the next nodes.

Initally deallocating was giving me error because I had not implemented copy and parameterized 
constructor. So variables like head and tail are uninitialized which on deallocating give 
segmentation fault. 

Now I don't get segmentation fault, but I cannot modify linked_list after assignment operator because
it returns a reference to the argument that was passed. I remember facing this problem in my ICS45C
class by Thornton, and the fix was definitely not straightforward. I'll leave this for now.

*/

linked_list::~linked_list(){

    this->remove_all();
}

void linked_list::add_node(int n){
        
    node *tmp=this->head; //points to head

    if(tmp == NULL){

        this->head = new node;
        this->head->data = n;

        // Uninitialized pointer is NOT the same as nullptr !

        this->head->next=NULL;
    }
    else{

        /*
            According to gdb debugger, the null check condition statement in the while loop 
            below gives segmentation fault on random occasions (usually when adding nodes 5 or 3) 
            suggesting that there is an issue with adding a node at the end.

            Segmentation fault seems to be coming from tmp->next when tmp is NULL. I copy pasted 
            the class template from the link below and improved up it: 

            https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/

            The author had used a tail pointer to keep track of the tail of the linkled list 
            which I removed because it seemed unnecessary. But I can see how the tail pointer can 
            be useful for adding nodes at O(1).

        */

        // check if next is null
        while(tmp->next!=NULL){ 
            tmp=tmp->next;
        }

        tmp->next=new node;
        tmp->next->data=n;

        // Uninitialized pointer is NOT the same as nullptr !
        tmp->next->next=NULL;

    }
    this->sz++;
}

// cannot be first or last
void linked_list::remove_node(int n){
        
    node *tmp;
    node *prev;
    tmp=this->head;

    while(tmp->next!=NULL){
        if(tmp->data==n){
            prev->next=tmp->next;
            break;
        }

        prev=tmp;
        tmp=tmp->next;
    }

    this->sz--;
    delete tmp; // tmp points to the node we removed
}

void linked_list::remove_all(){	

    node* current=this->head;
    node* next=NULL;

    while(current!=NULL){

        if(current->next==NULL){
            break;
        }
        else{
            next=current->next; // store reference to next node
            delete current; // delete the current node
            current = next; //move pointer to next node
        }
    }

	this->sz=0;
	this->head=NULL;

}

void linked_list::remove_duplicates(){

	set<int> item_set;

	node* temp_node; // pointer to a node
	temp_node=this->head; // point to head

    this->sz=0;
    this->head=NULL; // reset head

	//this->remove_all(); //clears the whole linked list

	while(temp_node->next!=NULL){
		int item=temp_node->data;
		item_set.insert(item);

		temp_node=temp_node->next;
	}
	item_set.insert(temp_node->data); //last item

	for (int item: item_set){
		this->add_node(item);
	}

}

int linked_list::kth_to_last(int k) const {

	int position=this->sz-k-1;  // 1st from behind is last

	node* temp_node; // pointer to a node
	temp_node=this->head; // point to first node

	int idx=0;

	while(temp_node!=NULL){

		int item=temp_node->data;
		if(idx==position){
			return item;
		}
		
		temp_node=temp_node->next;
		idx++;
	}

	return -1; // to indicate a hit has not been found
}



void linked_list::display() const {

    if(this->head==NULL){
        return;
    }

    else{
        node *tmp;
        tmp=this->head;

        while(tmp->next!=NULL){

            int item=tmp->data;
            cout<<item<<"->";

            tmp=tmp->next;
        }
        int last=tmp->data; // last item

        cout<<last<<"->null"<<"\n";
    }

}

int linked_list::size() const {
    return this->sz;
}

node* linked_list::show_head() const {
    return this->head;
}


