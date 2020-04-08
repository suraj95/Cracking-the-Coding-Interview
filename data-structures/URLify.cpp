/*
URLify: Write a method to replace all spaces in a string with '%20: You may assume that the string has 
sufficient space at the end to hold the additional characters, and that you are given the "true" length
of the string.

EXAMPLE

Input: "Mr John Smith",

Output: "Mr%20John%20Smith"
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

std::string URLify(std::string input_string){

	// if input string is empty, then simply return it
	if(input_string.size()==0){
		return input_string;
	}

	else{
		std::string output_string;
		std::string url_code="%20";

		int idx=0;
		char space=' ';

		for(int i=0; i<input_string.size(); i++){

			char temp=input_string[i];

			// check for space
			if(temp==space){
				output_string.insert(idx,url_code);
				idx+=3; // %20 is 3 characters
			}

			else{
				// There are a number of overloads of std::string::insert
				// 1 is the number of times to insert char temp into the string at position idx
				output_string.insert(idx,1,temp);
				idx++;
			}

		}

		return output_string;
	}
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	std::string input_string, output_string;
	getline(cin, input_string);

	output_string= URLify(input_string);

	cout<<output_string<<"\n";

	return 0;
}
