#include<iostream>
#include<set>

#include "linked_list_h.h"
#include "stack_self_h.h"

using namespace std;

// default constructor
stack_self::stack_self(){

    this->L=linked_list(); // unfortunately, this is still calling copy constructor
}

// copy constructor
stack_self::stack_self(const stack_self& S){

    linked_list temp(S.L); // call the linked_list classes copy constructor
    this->L=temp;
}

// assignment operator
stack_self& stack_self::operator=(const stack_self& S){

    // check for self assignment 
    if(this != &S){

        stack_self temp(S);

        // Move Semantics (turn expensive copies to cheap moves)
        std::swap(L, temp.L);
    }

   return *this;  
}

// destructor
stack_self::~stack_self(){

    this->L.~linked_list();
}


// Class methods

void stack_self::push(int n){

    this->L.add_node(n);
}


/*
    head for linked_list is the starting node, while peek() and pop() are supposed to act on the 
    tail node. I can either iterate it all the way, but that would make the operation O(n) instead of 
    O(1) which pretty much defeats the point of using a stack. I should implement a tail pointer in 
    my base linked_list class.
*/

void stack_self::pop(){

    this->L.remove_node(this->peek());
}


int stack_self::peek() const{

    return this->L.show_head()->data;
}



int stack_self::size() const{

    return this->L.size();
}

void stack_self::display(){
    this->L.display();
}


