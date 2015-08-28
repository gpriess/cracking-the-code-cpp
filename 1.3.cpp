#include <iostream>
#include <unordered_map>

using namespace std;

//creates a map of { characters -> frequency } of string s
//reads from string s, and constructs map
void hashString(const string& s, unordered_map<char, int>& map){

	for(string::const_iterator it = s.begin(); it < s.end(); it++)
	{
		unordered_map<char, int>::iterator search = map.find(*it);
		if(search == map.end())
			map.insert({*it, 1});
		else
			search->second++;
	}
	return;
}

bool isPermutation(const string& s1, const string& s2){
	if(s1.length() != s2.length())
		return false;
	//construct hash maps for s1, s2
	unordered_map<char, int> map_s1, map_s2;
	hashString(s1, map_s1);
	hashString(s2, map_s2);
	//iterate through map_s1 comparing it to map_s2
	unordered_map<char, int>::iterator it_1;
	unordered_map<char, int>::iterator it_2;
	for(it_1 = map_s1.begin(); it_1 != map_s1.end(); it_1++){
		it_2 = map_s2.find(it_1->first);
		if(it_2 == map_s1.end())
			return false;
		if(it_2->second != it_1->second)
			return false;
	}
	return true;
	
}

int main(){

	string s1 = "cdfggregoryaba";
	string s2 = "gabagrcdfgeory";
	string s3 = "cabagrcdfgeory";

	//STL implementation
	cout << is_permutation(s1.begin(), s1.end(), s2.begin()) << endl;
	//my implementation
	cout << isPermutation(s1, s2) << endl;
	cout << isPermutation(s2, s3) << endl;

}