/*

This is a crude implementation of Que data structure class for the problems in Pages 98 and 99
from the book "Cracking the Coding Interview" by Gayle Laakmann. It is done using two stacks from 
my self-implemented Stack data structure which was in turn implemented using my self implemented
Linked List data structure in linked_list.cpp.

Refer to queue_self.cpp for details.

Fixed Issues

1. dequeue() method for our queue data structure gives segmentation fault.

*/


#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include "linked_list_h.h"
#include "stack_self_h.h"
#include "queue_self_h.h"

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	queue_self a;
	a.enqueue(1);
	a.enqueue(2);
	a.enqueue(3);
	a.enqueue(2);
	a.enqueue(5);
	a.enqueue(6);
	a.display();
	cout<<a.peek()<<"\n";

	a.dequeue();
	//a.dequeue();
	a.display();
	cout<<a.peek()<<"\n";

	return 0;
}


