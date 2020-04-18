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

linked_list remove_duplicates(linked_list L){

	set<int> item_set;

	node* temp_node; // pointer to a node
	temp_node=L.show_head(); // point to first node

	linked_list result;

	while(temp_node->next!=NULL){
		int item=temp_node->data;
		item_set.insert(item);

		temp_node=temp_node->next;
	}

	for (int item: item_set){
		result.add_node(item);
	}

	return result;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	linked_list a;
	a.add_node(1);
	a.add_node(2);
	a.add_node(3);
	a.add_node(2);

	a.display();

	linked_list b;

	b=remove_duplicates(a);

	b.display();

	return 0;
}
