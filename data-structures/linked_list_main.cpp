/*

This is a crude implementation of a Linked List data structure for the problems in Pages 94 and 95
from the book "Cracking the Coding Interview" by Gayle Laakmann. Refer to linked_list.cpp 
for details.

Output:

1->2->3->2->5->6->null
1->2->3->5->6->null
5
3
1->2->3->5->6->8->4->null

Fixed Issues:

1. Destructor giving segmentation fault because "shallow copies" reference same object which 
when deallocated twice gives "Abort trap: 6" error.
2. add_node() method giving segmentation fault (usually when adding nodes 3 and 5) sometimes in copy 
constructor while other times in the first linked_list itself. Was happening because of uninitialized 
pointer.
3. Modification after using assignment operator giving segmentation fault due to going out of bounds.
4. Destructor giving segmentation fault due to going out of bounds.

*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include "linked_list_h.h" 

using namespace std;

int sum_lists(linked_list& L1, linked_list& L2){

	int number1=L1.represent_number();
	int number2=L2.represent_number();

	int result=number1+number2;

	return result;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	linked_list a;
	a.add_node(1);
	a.add_node(2);
	a.add_node(3);
	a.add_node(2);
	a.add_node(5);
	a.add_node(6);
	a.display();

	linked_list b;
	a.remove_duplicates();
	b=a;
	b.add_node(7);
	b.add_node(9);
	b.display();
	a.display();
	int from_last_a=a.kth_to_last(1); 
	int from_last_b=b.kth_to_last(2);
	cout<<from_last_a<<"\n";
	cout<<from_last_b<<"\n";


	linked_list c(a);
	c.add_node(8);
	c.add_node(4);
	c.display();
	cout<<std::boolalpha<<c.check_palindrome()<<"\n";

	linked_list d;
	d.add_node(1);
	d.add_node(2);
	d.add_node(2);
	d.add_node(1);
	d.display();
	cout<<std::boolalpha<<d.check_palindrome()<<"\n";

	linked_list e;
	e.add_node(7);
	e.add_node(1);
	e.add_node(6);
	linked_list f;
	f.add_node(5);
	f.add_node(9);
	f.add_node(2);
	e.display();
	f.display();
	cout<<sum_lists(e,f)<<"\n";

	return 0; 
}
