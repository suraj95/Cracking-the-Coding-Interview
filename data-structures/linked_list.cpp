#include<iostream>
#include "linked_list_h.h"

using namespace std;


// class is already defined in header

linked_list::linked_list(){
    head = NULL;
    tail = NULL;

    sz=0;
}

void linked_list::add_node(int n){
        
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if(head == NULL){

        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tail->next;
    }
    sz++;
}

// cannot be first or last, so head and tail wont change
void linked_list::remove_node(int n){
        
    node *tmp;
    node *prev;
    tmp=head;

    while(tmp->next!=NULL){
        if(tmp->data==n){
            prev->next=tmp->next;
            sz--;
            break;
        }

        prev=tmp;
        tmp=tmp->next;
    }
}


void linked_list::display(){

    if(head==NULL){
        return;
    }

    else{
        node *tmp;
        tmp=head;

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
    return sz;
}

node* linked_list::show_head(){
    return head;
}


