/*

This is a crude implementation of linkedlist class for the problems in Pages 94 and 95
from the book "Cracking the Coding Interview" by Gayle Laakmann. Refer to linked_list.cpp 
for details.

Output:

1->2->3->2->5->6->null
1->2->3->5->6->null
5
3
1->2->3->5->6->8->4->null

Known Issues:

- No new issues

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

#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#include<forward_list>

#include "linked_list_h.h" 

using namespace std;


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

	return 0; 
}
