#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


// returns true if X and Y are same
int compare(const char *X, const char *Y)
{
	while (*X && *Y)
	{
		if (*X != *Y)
			return 0;

		X++;
		Y++;
	}

	return (*Y == '\0');
}

// Function to implement strstr() function
int fast_strstr(const char* X, const char* Y)
{
	int index = 0;
	while (*X != '\0')
	{
		if ((*X == *Y) && compare(X, Y))
			return index;
		X++;
		index++;
	}

	return -1;
}

#include <stdio.h>
#include <stdlib.h>

// Function to implement strstr() function using KMP algorithm
int kmp_strstr(const char* X, const char* Y, int m, int n)
{
	// Base Case 1: Y is NULL or empty
	if (*Y == '\0' || n == 0)
		return 0;

	// Base Case 2: X is NULL or X's length is less than that of Y's
	if (*X == '\0' || n > m)
		return 0;

	// next[i] stores the index of next best partial match
	int next[n + 1];

	for (int i = 0; i < n + 1; i++)
		next[i] = 0;

	for (int i = 1; i < n; i++)
	{
		int j = next[i + 1];

		while (j > 0 && Y[j] != Y[i])
			j = next[j];

		if (j > 0 || Y[j] == Y[i])
			next[i + 1] = j + 1;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		if (*(X + i) == *(Y + j))
		{
			if (++j == n)
				return ( i - j + 1);
		}
		else if (j > 0) {
			j = next[j];
			i--;	// since i will be incremented in next iteration
		}
	}

	return -1;
}

 
int strstr(std::string s, std::string x) {
	
	char* ss = &s[0];
	char* xx = &x[0];

		
	// return fast_strstr(ss, xx); 	
	return kmp_strstr(ss, xx, s.length(), x.length());
		
}

int main(void)
{
	string s1  = "This is www.firmcodes.com";
   
   cout <<  strstr(s1, "firmcodes"); 
 
	return 0;
}