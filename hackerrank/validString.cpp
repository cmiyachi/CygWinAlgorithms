#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
	map<char,int> strmap;
	
	for(char& c : s)
	{
		strmap[c]++;
	}
	
	int diffcount = 0;
	int value = strmap[s[0]]; 
// 	cout << "va " << value << endl; 
	
	for ( const auto &myPair : strmap )
	{
		//cout << "strmap " << myPair.first << " " << myPair.second << endl; 
		if (strmap[myPair.first] != value)
		{
			diffcount++;
		//	cout << "diff " << diffcount << endl; 
			if (diffcount >= 2) return "NO";	
		}
	}
	
	return "YES"; 
}

int main(void)
{
	string str;
	cin >> str;
	
	cout << isValid(str); 
	return 0;
}