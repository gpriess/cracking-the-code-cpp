#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

//compresses strings with repeated characters
//for example: "aabcccccaaa" -> "a2b1c5a3"
// ab a1b1 aab a2b1
void strCompression(string& orig){

	if(orig.size() == 0 || orig.size() == 1)
		return;
	//first calculate size of compressed string
	auto prev = orig.begin();
	auto curr = prev + 1;
	int comp_size = 0;
	for(; curr <= orig.end(); curr++)
	{
		if(curr == orig.end() || *curr != *prev){	
			comp_size += 2;
			prev = curr;
		}
	}
	cout << comp_size << endl;
	//If the comp string is not smaller than original
	if(comp_size >= orig.size())
		return;
	//construct compressed string
	string compressed;
	prev = orig.begin();
	curr = prev + 1;
	int run_size = 1;
	for( ; curr <= orig.end(); curr++){
		if(curr == orig.end() || *curr != *prev){	
			compressed.append(prev, prev + 1);
			string run_size_str = static_cast<ostringstream>( (ostringstream() << run_size) ).str();
			compressed.append(run_size_str);
			prev = curr;
			run_size = 1;
		}
		else ++run_size;
	}
	orig = compressed;
	return;

}

int main(){

	while(1)
	{
	string test;
	cin >> test;
	strCompression(test);
	cout << test << endl;
	}



	return 0;
}