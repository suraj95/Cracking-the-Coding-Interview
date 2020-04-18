#include<iostream>
#include "linked_list_h.h"

using namespace std;


// class is already defined in header

linked_list::linked_list(){
    head = NULL;
    tail = NULL;
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
        int last=tmp->data;

        cout<<last<<"->null"<<"\n";
    }

}

node* linked_list::show_head(){
    return head;
}


