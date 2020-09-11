#include <bits/stdc++.h>

using namespace std;
string longestPalSubstr(char *str) ; 

class Solutions {
public:
    string longestPalindrome(string s) {
		
		char s_array[s.length()+1]; 
		strcpy(s_array, s.c_str()); 
		
		string result = longestPalSubstr(s_array); 
		
		return result; 
    }
};

// A O(n^2) time and O(1) space program to 
// find the longest palindromic substring 
#include <bits/stdc++.h> 
using namespace std; 

// A utility function to print a substring str[low..high] 
string makeSubStr(char* str, int low, int high) 
{ 
	string result; 
	for( int i = low; i <= high; ++i ) 
		result = result + str[i]; 
	
	return result; 
} 

// This function prints the longest palindrome substring (LPS) 
// of str[]. It also returns the length of the longest palindrome 
string longestPalSubstr(char *str) 
{ 
	int maxLength = 1; // The result (length of LPS) 

	int start = 0; 
	int len = strlen(str); 

	int low, high; 

	// One by one consider every character as center point of 
	// even and length palindromes 
	for (int i = 1; i < len; ++i) 
	{ 
		// Find the longest even length palindrome 
		// with center points as i-1 and i. 
		low = i - 1; 
		high = i; 
		while (low >= 0 && high < len && str[low] == str[high]) 
		{ 
			if (high - low + 1 > maxLength) 
			{ 
				start = low; 
				maxLength = high - low + 1; 
			} 
			--low; 
			++high; 
		} 

		// Find the longest odd length palindrome with center 
		// point as i 
		low = i - 1; 
		high = i + 1; 
		while (low >= 0 && high < len && str[low] == str[high]) 
		{ 
			if (high - low + 1 > maxLength) 
			{ 
				start = low; 
				maxLength = high - low + 1; 
			} 
			--low; 
			++high; 
		} 
	} 

	string result = makeSubStr(str, start, start + maxLength - 1); 

	return result; 
} 
class Solution {
public:
    string longestPalindrome(string s) {
		if (s.length() < 1) return "";
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++) {
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = max(len1, len2);
			if (len > end - start) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end + 1-start);
			
    }
private:
	int expandAroundCenter(string s, int left, int right) {
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R]) {
			L--;
			R++;
		}
		return R - L - 1;
	}
};

// Driver program to test above functions 
int main() 
{ 
	string s = "forgeeksskeegfor"; 
	Solution sol;
	
	cout << sol.longestPalindrome(s); 
	return 0; 
} 

