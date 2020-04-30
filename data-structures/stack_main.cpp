/*

This is a crude implementation of Stack data structure class for the problems in Pages 98 and 99
from the book "Cracking the Coding Interview" by Gayle Laakmann. It is done using my self-implemented 
Linked List data structure in linked_list.cpp

Refer to stack_self.cpp for details.

Issues

1. lldb/gdb debugger reveals that after initializing a stack_self object, my linked_list classes copy 
constructor gets called with the linked_list argument defaulting to null, which on iterating gives
segmentation fault (at linked_list.cpp:40:20).


*/


#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include "linked_list_h.h" 
#include "stack_self_h.h"

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	stack_self a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(2);
	a.push(5);
	a.push(6);
	a.display();
	// a.pop();
	// a.pop();
	cout<<a.peek()<<"\n";
	// a.display();

	return 0;
}


