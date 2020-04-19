/*

Write code to remove duplicates from an unsorted linked list.

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

	b=a; // assignment operator, don't modify b after this
	b.display();
	
	int from_last_a=a.kth_to_last(1); 
	int from_last_b=b.kth_to_last(2);

	cout<<from_last_a<<"\n";
	cout<<from_last_b<<"\n";

	//a.add_node(4);
	//a.display();

	return 0; 
}
