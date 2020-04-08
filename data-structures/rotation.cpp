/*

Given two strings, s1 and s2, write code to check if s2 is a rotation of s1.

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

bool rotation_check(std::string str1, std::string str2){

	set<char> set1(str1.begin(), str1.end());
	set<char> set2(str2.begin(), str2.end());

	// operator== is correctly defined for all standard containers (except unordered containers)
	if(set1==set2){

		std::string result;

		for(int k=1; k<str1.size()-1; k++){

			result=""; //reinitialize for each k
			int idx=0;

			for(int i=0; i<str1.size(); i++){

				if(i+k<str1.size()){
					result+=str1[i+k];
					idx++;
				}

				else{
					result+=str1[i+k-str1.size()];
					idx++;
				}
			}

			//If str2 matches a rotation
			if(result==str2){
				return true;
			}
		}

		return false;
	}

	else{
		return false;
	}

}

int main(){

	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	std::string input_string1, input_string2;


	cin>>input_string1>>input_string2;
	bool result=rotation_check(input_string1,input_string2);
	cout<<std::boolalpha<<result<<"\n";

	return 0;
}