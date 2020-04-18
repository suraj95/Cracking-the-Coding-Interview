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
	item_set.insert(temp_node->data); //last item

	for (int item: item_set){
		result.add_node(item);
	}

	return result;
}

int kth_to_last(linked_list L, int k){

	int size=L.size();
	int position=size-k;  // 1st from behind is last

	node* temp_node; // pointer to a node
	temp_node=L.show_head(); // point to first node

	int count=0;

	while(temp_node->next!=NULL){

		int item=temp_node->data;
		if(count==position){
			break;
		}
		
		temp_node=temp_node->next;
		count++;
	}

	return count;
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

	b=remove_duplicates(a);

	b.display();

	
	int from_last_a=kth_to_last(a,1);
	int from_last_b=kth_to_last(b,2);

	cout<<from_last_a<<"\n";
	cout<<from_last_b<<"\n";

	b.remove_node(3); // cannot be first or last
	b.display();

	return 0;
}
