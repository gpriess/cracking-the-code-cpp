#include <iostream>

using namespace std;

bool uniqueChars(string s)
{
	bool a[256];
	memset(a, 0, sizeof(a));
	for(auto it = s.begin(); it < s.end(); it++)
	{
		if(a[(int)*it] == true)
			return false;
		else
			a[(int)*it] = true;
	}
	return true;
}

bool isUnique3(string s)
{
    long long check = 0;
    int len = s.length();
    for(int i=0; i<len; ++i)
    {
        int v = (int)(s[i]-'a');
        cout << "char: " << s[i] << " num: " << v << endl;
        if(check & (1<<v)) return false;
        check |= (1<<v);
    }
    return true;
}

int main()
{
	string a = "abcdefghijklmnopqrstuvwxyz0123456789";
	string b = "greg";
	cout << a << " " << isUnique3(a) << endl;
	cout << b << " " << isUnique3(b) << endl;

	return 0;
}