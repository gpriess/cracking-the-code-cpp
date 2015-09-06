#include <iostream>
#include <string.h>

using namespace std;


void encodeSpaces(char* str, const char* replace, const int offset){
	char * p = str;
	int spaces = 0;
	while(*p){
		if(*p == ' ') spaces++;
		p++;
	}
	while(p >= str)
	{
		if(*p == ' '){
			spaces--;
			memcpy((p + offset * spaces), replace, offset + 1);
		}
		else *(p + offset * spaces) = *p;
		p--;
	}
}


int main(){

	int offset = 2;
	char replace[100] = "%20";
	char str[100] = " Mr John Smith ";
	cout << str << endl;
	encodeSpaces(str, replace, offset);
	cout << str << endl;

}