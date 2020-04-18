#include<iostream>
#include "linked_list_h.h"

using namespace std;

/*

Class is defined in header files. We don't have to redefine here. 

Copy constructor is called when a new object is created from an existing object, as a copy of the 
existing object. And assignment operator is called when an already initialized 
object is assigned a new value from another existing object.

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

*/


linked_list::~linked_list(){

    node* tmp=head;

    while(tmp!=tail)
    {
        node* old = tmp;
        tmp = tmp->next;

        if(old!=NULL){
            //delete old;
        }
    }

    //delete tail;
}

void linked_list::add_node(int n){
        
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if(this->head == NULL){

        head = tmp;
        tail = tmp;
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


void linked_list::display(){

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

int linked_list::size(){
    return this->sz;
}

node* linked_list::show_head(){
    return this->head;
}


