#include <bits/stdc++.h>

using namespace std;

 class Solution {
	 public: 
		 int lengthOfLongestSubstring(string s) {
			int n = s.length(), ans = 0;
			vector<int> index(128);  // ASCII CHars
			// try to extend the range [i, j]
			for (int j = 0, i = 0; j < n; j++) {
				i = max(index[s[j]], i);
				ans = max(ans, j - i + 1);
				index[s[j]] = j + 1;
			}
			return ans;
		}
};
int main(void)
{
	Solution sol;
	string s = "abcabcbb";
	cout << sol.lengthOfLongestSubstring(s) << endl;
	
	s = "bbbbb"; 
		cout << sol.lengthOfLongestSubstring(s) << endl;

	s = "pwwkew";
		cout << sol.lengthOfLongestSubstring(s) << endl;

	return 0;
}