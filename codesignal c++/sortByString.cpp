#include <bits/stdc++.h>

using namespace std;

std::string sortByString(std::string s, std::string t) {
	// loop through string t 
	// for each char c
	// is that char in s? if so add to result and remove that char from s
	// keep searching until there are no more char c's in s
	// end when either string t is done or s is empty
	
	int i = 0; 
	string result; 
	while ((i < t.length()) || (s.length() != 0))
	{
		int pos = s.find(t[i]); 
		while ( pos != string::npos)
		{
			result.append(1,t[i]);
			s.erase(pos,1); 
			pos = s.find(t[i]);
		}
		i++; 
	} // while
	
	return result;
}

int main(void)
{
	string s = "weather",  t = "therapyw";

	cout << sortByString(s, t) << endl;
	
	s = "good"; t = "odg";
	
	cout << sortByString(s, t) << endl;
	
	return 0; 
}