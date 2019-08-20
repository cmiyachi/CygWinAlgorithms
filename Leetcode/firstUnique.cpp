#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
		
		map<char,int> charmap; 
		int min_index = -1; 
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			charmap[c]++; 
		}
		
		for (int i = 0; i < s.size(); i++)
			if (charmap[s[i]] == 1)
				return i; 

		return -1; 
    }
};

int main(void)
{
	string s = "leetcode";
	Solution sol;
	cout << sol.firstUniqChar(s) << endl; 
	s = "loveleetcode";
	cout << sol.firstUniqChar(s) << endl; 
	return 0;
}