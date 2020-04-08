/*
String Compression: Implement a method to perform basic string compression using the counts of repeated 
characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would
not become smaller than the original string, your method should return the original string. 

You can assume the string has only uppercase and lowercase letters (a - z).
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

std::string compression(std::string input_string){

	std::string output_string;
	int idx=0;

	char prev=' ';
	int ctr=0;

	for(int i=0;i<input_string.size(); i++){
		char temp=input_string[i];

		// if char is a digit, then input string is already compresssed
		if(isdigit(temp)){

			// could copy string, but that would be slow
			return input_string;
		}
		else{
			// initialize loop
			if(prev==' '){
				prev=temp;
				ctr=1;
			}

			// increment counter
			else if(prev==temp){
				ctr++;

			}

			// continuity broken, so insert to output_string
			else{
				std::string  str(1, prev); 
				str+=to_string(ctr);
				output_string.insert(idx,str);

				// reset indices
				ctr=1;
				idx+=2;
				prev=temp;
			}
		}
	}

	// last item of list
	std::string  str(1, prev); 
	str+=to_string(ctr);
	output_string.insert(idx,str);

	return output_string;
}


int main(){

	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::string input_string, output_string;

	cin>>input_string;
	output_string=compression(input_string);

	cout<<output_string<<"\n";

	return 0;
}
