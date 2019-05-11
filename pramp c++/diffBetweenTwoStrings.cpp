// A Dynamic Programming based C++ program to find minimum 
// number operations to convert str1 to str2 
#include<bits/stdc++.h> 
using namespace std; 

vector<string> final_result; 

// Utility function to find the minimum of three numbers 
int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 

int editDistDP(string str1, string str2, int m, int n) 
{ 
	// Create a table to store results of subproblems 
	int dp[m+1][n+1]; 

	// Fill d[][] in bottom up manner 
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			// If first string is empty, only option is to 
			// insert all characters of second string 
			if (i==0) 
				dp[i][j] = j; // Min. operations = j 

			// If second string is empty, only option is to 
			// remove all characters of second string 
			else if (j==0) 
				dp[i][j] = i; // Min. operations = i 

			// If last characters are same, ignore last char 
			// and recur for remaining string 
			else if (str1[i-1] == str2[j-1]) 
			{
				dp[i][j] = dp[i-1][j-1]; 
				//final_result.push_back(&str1[i-1]); 
			}

			// If the last character is different, consider all 
			// possibilities and find the minimum 
			else
			{
				string stringplus = "+"; 
				string stringrem = "-"; 
				dp[i][j] = 1 + min(dp[i][j-1], // Insert 
								dp[i-1][j], // Remove 
								dp[i-1][j-1]); // Replace 
				int min_value = dp[i][j] - 1;
				if (min_value == dp[i-1][j-1])
				{
					string add = stringplus.append(1, str2[j-1]); 
					//final_result.push_back(add);
				}
				else if (min_value == dp[i-1][j])
				{
					string rem = stringrem.append(1, str1[i-1]);
					final_result.push_back(rem);
				}
				else if (min_value == dp[i][j-1])
				{
					string add = stringplus.append(1, str2[j-1]); 
					final_result.push_back(add);
				}
			}
		} 
	} 

	return dp[m][n]; 
} 


vector<string> diffBetweenTwoStrings(const string& source, const string& target)
{
	int m = source.length();
	int n = target.length();
	
	int edit_dist = 0;
	
	edit_dist = editDistDP(source, target, m,n);
	
	cout << "edit dist " << edit_dist << endl;
	
	return final_result; 
}

// Driver program 
int main() 
{ 
	// your code goes here 
	string str1 = "sunday"; 
	string str2 = "saturday"; 

	vector<string> result = diffBetweenTwoStrings(str1, str2); 
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i];
	cout << endl;

	return 0; 
} 




