#include <iostream>
#include <string>

using namespace std;

//From pg. 74:
// "Assume you have a method isSubstring which checks if 
//  one word is a substring of another. Given two strings, s1 and s2, 
//  write code to check if s2 is a rotation of s1 using only one call 
//  to isSubstring (e.g.,"waterbottle" is a rotation of "erbottlewat") "

bool isRotation(const string& s1, const string& s2) {
	
	if(s1.size() != s2.size())
		return false;
	
	string s2ext = s2 + s2;
	if(s2ext.find(s1))
		return true;

	return false;
}



int main(){

	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	

	cout << s2 << " is ";
	if(! isRotation(s1, s2))
		cout << "not ";
	cout << "rotation of " << s1 << endl;


	return 0;


}