#include <bits/stdc++.h>

using namespace std;

std::string amendTheSentence(std::string s) {
	
	string result=""; 
	
	// look at first character
	if (isupper(s[0]))
	{
		result.append(1, tolower(s[0]));
	}
	else
		result.append(1, s[0]); 
	
	for(int i = 1; i < s.length(); i++)
	{
		char c = s[i];
		if (isupper(c))
		{
			result.append(1, ' '); 
			result.append(1,tolower(c));
		}
		else
			result.append(1,c);	
	}

	return result; 
}

int main(void)
{
	string s = "CodesignalIsAwesome";
	
	cout << amendTheSentence(s); 
	
	s = "Hello";
	
	cout << amendTheSentence(s); 

	return 0;
}