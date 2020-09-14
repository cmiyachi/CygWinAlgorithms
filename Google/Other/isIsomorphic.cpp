#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map_s[128] = { 0 };
        char map_t[128] = { 0 };
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (map_s[s[i]]!=map_t[t[i]]) return false;
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
        }
        return true;    
    }
}; 

int main(void)
{
	string s = "paper", t = "title";
	Solution sol;
	
	cout << sol.isIsomorphic(s,t) << endl;
	
	s = "foo", t = "bar"; 
	cout << sol.isIsomorphic(s,t) << endl;
	return 0;
}