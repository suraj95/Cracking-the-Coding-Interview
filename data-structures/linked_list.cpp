#include<iostream>
#include "linked_list_h.h"

using namespace std;

/*

Class is declared and defined in header files. We don't have to redefine here. 
We simply use the :: scope operator to write the function definition.

Copy constructor is called when a new object is created from an existing object, 
as a copy of the existing object. And assignment operator is called when an already 
initialized object is assigned a new value from another existing object.

*/


// default constructor
linked_list::linked_list(){

    this->head = NULL;
    this->tail = NULL;

    sz=0;
}

// copy constructor
linked_list::linked_list(const linked_list& L){

    //cout<<"copy constructor called"<<"\n";

    node* tmp=L.head;
    this->sz=0;

    this->head=NULL;
    this->tail=NULL;

// final head and tail are taken care of in add_node()

    while(tmp->next!=NULL){
        this->add_node(tmp->data); 

        tmp=tmp->next;
    }
    this->add_node(tmp->data);
    
}


/* 

deallocating is giving error because I haven't implemented copy and parameterized constructor. So 
variables like head and tail are uninitialized which on deallocating give segmentation fault.


delete does not set pointer to null. It simply deallocates the memory the pointer points to. 
We cannot straightaway delete from the front because the moment we delete a node, we lose the 
pointers to the next nodes.

*/


linked_list::~linked_list(){

    node* temp=this->head; // temp is pointing to head;
    node* store;

    if(temp==NULL){
        return;
    }
    else if(temp->next==this->tail){
        delete this->tail;
        delete this->head;

        return;

    }

    //this code deletes all nodes except the first one. And it is also modifying other references

    // temp=this->head->next;
    // while(temp!=NULL){
    //     this->head->next = temp->next;
    //     temp->next = NULL;
    //     delete temp;
    //     temp = this->head->next;
    // }

    // this->head=NULL;
    // this->tail=NULL;
    // this->sz=0;

}

void linked_list::add_node(int n){
        
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if(this->head == NULL){

        this->head = tmp;
        this->tail = tmp;
    }
    else{
        this->tail->next = tmp;
        this->tail = tail->next;
    }
    this->sz++;
}

// cannot be first or last, so head and tail won't change
void linked_list::remove_node(int n){
        
    node *tmp;
    node *prev;
    tmp=this->head;

    while(tmp->next!=NULL){
        if(tmp->data==n){
            prev->next=tmp->next;
            sz--;
            break;
        }

        prev=tmp;
        tmp=tmp->next;
    }

    delete tmp; // tmp points to the node we removed
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

node* linked_list::show_head() const{
    return this->head;
}


