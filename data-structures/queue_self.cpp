#include<iostream>
#include<set>

#include "linked_list_h.h"
#include "stack_self_h.h"
#include "queue_self_h.h"

using namespace std;

/*
    We could have implemented this easily by using our linked_list class, but question 3.4 specifically 
    asks us to implement this using 2 Stacks. The idea of two stacks is that enqueue() operation will 
    take O(1) by simply pushing our item to Stack 1, but dequeue() will take O(n) as we will have to
    internally reverse the order of items by popping them from Stack 1 and pushing them to Stack 2.

    *Even the vice versa is possible in which dequeue takes O(1) and enqueue takes O(n). But for now, I 
    am implementing the former.
*/


// default constructor
queue_self::queue_self(){

    this->S1=stack_self(); // unfortunately, this is still calling copy constructor
    this->S2=stack_self();
}

// copy constructor
queue_self::queue_self(const queue_self& Q){

    queue_self temp(Q); // call the self_stack copy constructor
    this->S1=temp.S1;
    this->S2=temp.S2;
}

// assignment operator
queue_self& queue_self::operator=(const queue_self& Q){

    // check for self assignment 
    if(this != &Q){

        queue_self temp(Q);

        // Move Semantics (turn expensive copies to cheap moves)
        std::swap(S1, temp.S1);
        std::swap(S2, temp.S2);
    }

   return *this;  
}

// destructor
queue_self::~queue_self(){

    this->S1.~stack_self();
    this->S2.~stack_self();
}


// Class methods

void queue_self::enqueue(int n){ // enqueue is of O(1)

    this->S1.push(n); // simply push to Stack 1
}

void queue_self::dequeue(){ // dequeue is of O(n)

    // keep popping from Stack 1 and push to Stack 2 till the first item is left

    while(S1.size()!=1){
        int item=this->S1.peek();
        this->S1.pop();
        this->S2.push(item);
    }

    // swap our variables now
    std::swap(S1,S2);

}

int queue_self::peek() const{

    return this->S1.peek();
}

int queue_self::size() const{

    return this->S1.size();
}

void queue_self::display(){
    this->S1.display();
}


