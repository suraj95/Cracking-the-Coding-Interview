/*
Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
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

using namespace std;

bool check_permutation(std::string string1,std::string string2){

	// check if string sizes are equal
	if(string1.size()==string2.size()){

		int n=string1.size();

		// declaring character array 
    	char c1[n + 1]; 
    	char c2[n + 1]; 
  
    	// copying the contents of the 
    	// string to char array 
    	strcpy(c1, string1.c_str()); 
    	strcpy(c2, string2.c_str());
  
		while(std::next_permutation(c1,c1+n)){

			// reinitialize for each permutation
			int count=0;

			for (int i = 0; i < n; i++){

				// if character does not match, break the loop
				if(c1[i]!=c2[i]){
					break;
				}
				else{
					count++;
				}
			}
				// all the characters in the arrays match each other
			if(count==n){
				return true;
			}

		}

		// none of the permutations of string1 matched the string2 

		return false;
	}

	else{
		return false;
	}
}



int main(){
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::string input_string1;
	std::string input_string2;
	cin>>input_string1>>input_string2;

	bool result;
	result=check_permutation(input_string1,input_string2);

	cout<<std::boolalpha<<result<<"\n";

	return 0;
}
