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


bool isUnique(std::string input_string){

	// check if string is empty
	if(input_string.size()==0){

		return true;
	}

	else{

		set<char> char_set(input_string.begin(), input_string.end());

		if(char_set.size()==input_string.size()){
			return true;
		}

		else{
			return false;
		}

	}
}

int main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	std::string input_string;
	bool result;

	cin>>input_string;
	result=isUnique(input_string);


	// Sets the boolalpha format flag for the str stream 
	// to print "true" and "false" instead of 1 and 0

	cout<<std::boolalpha<<result<<"\n";

	return 0;
}
