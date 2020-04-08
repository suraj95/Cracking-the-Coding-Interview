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


/* 

Three types of edits that can be performed on strings: insert a character, remove a character, 
or replace a character.

*/

bool oneAway(std::string str1,std::string str2){

	set<char> set1(str1.begin(), str1.end());
	set<char> set2(str2.begin(), str2.end());

	set<char>::iterator itr;
	int match_count=0;

	for (itr = set1.begin(); itr != set1.end(); ++itr){

		//  check if element exists in set2
		const bool is_in = set2.find(*itr) != set2.end();

		if(is_in){
			match_count++;
		}
   	}

	// character is replaced
	if(set1.size()==set2.size()){
   		return match_count==set1.size()-1; // all will match other than replaced characters

	}

	// character is added
	else if(set1.size()==set2.size()+1){
		return match_count==set2.size(); // all elements of set2 should be in set1
	}

	// character is removed
	else if(set1.size()+1==set2.size()){
		return match_count==set2.size(); // all elements of set1 should be in set2
	}

	else{
		return false;
	}

}

int main(){

	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::string string1, string2;
	cin>>string1>>string2;

	bool result=oneAway(string1,string2);
	cout<<std::boolalpha<<result<<"\n";

	return 0;
}
