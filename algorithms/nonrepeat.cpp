#include <iostream>
#include <algorithm>
#include <string> 
#include <map>



using namespace std;

char firstNotRepeatingCharacter(std::string s) {

	char cand = '_';
	map<char, int> strMap; 
	
	for (char c : s)
	{
		strMap[c]++;
	}		
	
	for (char c : s )
	{
		if (strMap[c] == 1)
		{
			cand = c;
			break;
		}
	}
		

	
	return cand; 
	

}

int main()
{

	string s = "abacabad"; 
	
	cout << firstNotRepeatingCharacter(s); 
	
	return 0;
	
}
	
	
