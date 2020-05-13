/*

This is a crude implementation of Binary Search Tree data structure class for the problems in Pages 109, 
110 and 111 from the book "Cracking the Coding Interview" by Gayle Laakmann. 

Refer to BST_self.cpp for details.

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
============
true
Node found !
Node found !
Node not found
9
5
25
true
20
false
============
true
1
5 
15 
20 
25 
30 
42 
false
============
true
1
1 
5 
15 
20 
25 
30 
40 
42 
45 
false
============


Issues:

1. In the random_node() method, the random nodes returned are not uniformly distributed because I am 
using rand function which is discouraged.

2. In the check_balanced() method, I am only checking children of root node.

3. For copy constructor and assignment operator, I am getting a different tree because the order 
in which nodes get added is different. [Fixed]

4. copy_inorder() function is giving Segmentation Fault. [Fixed]

*/


#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include "BST_self_h.h"

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*


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

*/

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
  cout<<"============\n";


/*
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
                           /
                          /
                         42
*/
  cout<<boolalpha<<a.validate_BST()<<"\n";
  a.search(12);
  a.search(20);
  a.search(11);
  cout<<a.random_node()->data<<"\n";
  cout<<a.random_node()->data<<"\n";
  cout<<a.random_node()->data<<"\n";
  cout<<boolalpha<<a.check_balanced()<<"\n";
  a.remove_node(7);
  a.remove_node(12);
  a.remove_node(9);
  cout<<a.show_root()->data<<"\n";
  cout<<boolalpha<<a.check_balanced()<<"\n";
  cout<<"============\n";

/*

                   20
                 /    \
                /      \
               5       30
                \      /\
                 \    /  \
                 15  25  42
                 /          
                /           
               9             

*/

  BST_self b(a);
  cout<<boolalpha<<b.validate_BST()<<"\n";
  cout<<b.show_root()->data<<"\n";
  b.remove_node(1);
  b.remove_node(45);
  b.remove_node(40);
  b.display();
  cout<<boolalpha<<b.check_balanced()<<"\n";
  cout<<"============\n";


/*
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
                           /
                          /
                         42
*/

  BST_self c=a;
  cout<<boolalpha<<c.validate_BST()<<"\n";
  cout<<c.show_root()->data<<"\n";
  c.display();
  cout<<boolalpha<<c.check_balanced()<<"\n";
  cout<<"============\n";

}
