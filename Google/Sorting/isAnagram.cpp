#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		if (s.length() != t.length()) {
			return false;
		}
		vector<int> counter(26,0); 
		
		for (int i = 0; i < s.length(); i++) {
			counter[s[i] - 'a']++;
			counter[t[i] - 'a']--;
		}
		for (int count : counter) {
			if (count != 0) {
				return false;
			}
		}
		return true;
	}
};

int main(void)
{
	
	string s = "anagram";
	string t = "nagaram"; 
	
	Solution sol;
	cout << sol.isAnagram(s,t) << endl; 
	
	s = "rat"; t = "car";
	cout << sol.isAnagram(s,t); 
	return 0;
}