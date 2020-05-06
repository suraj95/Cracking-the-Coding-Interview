/*

This is a crude implementation of Binary Search Tree data structure class for the problems in Pages 109, 110,
111 from the book "Cracking the Coding Interview" by Gayle Laakmann. 

Refer to BST_self.cpp for details.

This is our Binary Search Tree

                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42


Output:
 1 
 5 
 7 
 9 
 12 
 15 
 20 
 25 
 30 
 40 
 42 
 45

Issues:


*/


#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include "BST_self_h.h"

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	BST_self a;
	a.add_node(20);
   	a.add_node(5);
    a.add_node(1);
    a.add_node(15);
    a.add_node(9);
    a.add_node(7);
    a.add_node(12);
   	a.add_node(30);
    a.add_node(25);
    a.add_node(40);
    a.add_node(45);
    a.add_node(42);
    a.display();

}
