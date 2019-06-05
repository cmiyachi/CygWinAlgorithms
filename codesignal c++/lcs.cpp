/* Dynamic Programming solution to find length of the 
longest common substring */
#include <bits/stdc++.h>
using namespace std; 


int longestCommonSubstring(std::string s, std::string t) {
	
	int m = s.length();
	int n = t.length(); 
	
	// Create a table to store lengths of longest 
	// common suffixes of substrings. Note that 
	// LCSuff[i][j] contains length of longest 
	// common suffix of X[0..i-1] and Y[0..j-1]. 

	// vector<vector<int>> LCSuff[m+1][n+1];
	vector<vector<int>> LCSuff(m+1, vector<int> (n+1, 0));
	int result = 0; // To store length of the 
					// longest common substring 
					
	/* Following steps build LCSuff[m+1][n+1] in 
		bottom up fashion. */
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 

			// The first row and first column 
			// entries have no logical meaning, 
			// they are used only for simplicity 
			// of program 
			if (i == 0 || j == 0) 
				LCSuff[i][j] = 0; 

			else if (s[i-1] == t[j-1]) 
			{ 
				LCSuff[i][j] = LCSuff[i-1][j-1] + 1; 
				result = max(result, LCSuff[i][j]); 
			} 
			else LCSuff[i][j] = 0; 
		} 
	} 
	return result; 

}
/* Returns length of longest common substring of X[0..m-1] 
and Y[0..n-1] */
int LCSubStr(char *X, char *Y, int m, int n) 
{ 
	// Create a table to store lengths of longest 
	// common suffixes of substrings. Note that 
	// LCSuff[i][j] contains length of longest 
	// common suffix of X[0..i-1] and Y[0..j-1]. 

	int LCSuff[m+1][n+1]; 
	int result = 0; // To store length of the 
					// longest common substring 

	/* Following steps build LCSuff[m+1][n+1] in 
		bottom up fashion. */
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 

			// The first row and first column 
			// entries have no logical meaning, 
			// they are used only for simplicity 
			// of program 
			if (i == 0 || j == 0) 
				LCSuff[i][j] = 0; 

			else if (X[i-1] == Y[j-1]) 
			{ 
				LCSuff[i][j] = LCSuff[i-1][j-1] + 1; 
				result = max(result, LCSuff[i][j]); 
			} 
			else LCSuff[i][j] = 0; 
		} 
	} 
	return result; 
} 

/* Driver program to test above function */
int main() 
{ 
	char X[] = "OldSite:GeeksforGeeks.org"; 
	char Y[] = "NewSite:GeeksQuiz.com"; 
	
	string s = "OldSite:GeeksforGeeks.org";
	string t = "NewSite:GeeksQuiz.com"; 

	int m = strlen(X); 
	int n = strlen(Y); 

	cout << "Length of Longest Common Substring is "
		<< LCSubStr(X, Y, m, n); 
		
		
	cout << longestCommonSubstring(s,t); 
	
	return 0; 
} 
