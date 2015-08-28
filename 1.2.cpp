#include <iostream>
#include <string>
#include <string.h>

using namespace std;


string reverse(string s){
	string::iterator p1 = s.begin();
	string::iterator p2 = s.end() - 1;
	while(p1 < p2)
	{
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++; p2--;
	}
	return s;
}

void cReverse(char* str)
{
	char* p1 = &str[0];
	char* p2 = p1;
	//have p2 point to the last element
	while(*p2 != '\0') p2++;
	p2--;
	
	//reverse the string in-place
	while(p1 < p2)
	{
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++; p2--;
	}
	return;
}

int main()
{
	string s1 = "greg";
	string s2 = "gregory";

	cout << s1 << " rev: " << reverse(s1) << endl;
	cout << s2 << " rev: " << reverse(s2) << endl;
	char c1[20] = "greg";
	char c2[20] = "gregory";
	cout << c1 << " rev: ";
	cReverse(c1);
	cout << c1 << endl;
	cout << c2 << " rev: ";
	cReverse(c2);
	cout << c2 << endl;






}