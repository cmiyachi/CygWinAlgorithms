#include <bits/stdc++.h>
using namespace std;
 
 
int strstr(std::string s, std::string x) {
	
	int s_index = 0;
	
	while (s_index < s.length())
	{
		int try_index = s_index; 
		int x_index = 0; 
		// if first char of sub string match - check for full pattern
		while((s_index < s.length()) && (x_index < x.length()) && (s[s_index] == x[x_index]))
		{
			s_index++; x_index++; 
		}
		// if pattern completed we have a match)
		if (x_index >= x.length())
			return try_index;
		
		s_index = try_index + 1; 
	}
	
	return -1; 
		
		
		
}
/* Driver Function */ 
// char* StrStr(char *str, char *substr)
// {
	  // while (*str) 
	  // {
		    // char *Begin = str;
		    // char *pattern = substr;
		    
		    // // If first character of sub string match, check for whole string
		    // while (*str && *pattern && *str == *pattern) 
			// {
			      // str++;
			      // pattern++;
		    // }
		    // // If complete sub string match, return starting address 
		    // if (!*pattern)
		    	  // return Begin;
		    	  
		    // str = Begin + 1;	// Increament main string 
	  // }
	  // return NULL;
// }
 
/* Main Method */
int main()
{
	string s1  = "This is www.firmcodes.com";
   
   cout <<  strstr(s1, "firmcodes"); 
 
	return 0;
}