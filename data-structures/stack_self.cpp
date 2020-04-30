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

void stack_self::pop(){

    this->L.remove_last_node();
}

int stack_self::peek() const{

    return this->L.show_tail()->data;
}

int stack_self::size() const{

    return this->L.size();
}

void stack_self::display(){
    this->L.display();
}


