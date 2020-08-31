#include <bits/stdc++.h>
using namespace std;

/**This question belong to the same category as those such as "longest substring without repeating characters", "minimum window substring", and "substring with concatenation of all words". To solve this kind of question we can use two pointers and a hash table. When the key of the hash table is char, we can simply use an array as the hash table. The most important idea in solving this kind of questions is "how to update the "start" pointer" and the solution to these questions seem usually differ only in this respect.**/



class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
		if(s.empty()) return 0;
		
		int dict[256]; 
		fill_n(dict,256,0);
		int start = 0, len = 1, count = 0;
		for(int i=0; i<s.length(); i++) {
			dict[s[i]]++;
			if(dict[s[i]] == 1) { // new char
				count++;
				while(count > 2) {
					dict[s[start]]--;
					if(dict[s[start]] == 0) count--; 
					start++;
				}
			}
			if(i-start+1 > len) len = i-start+1;
		}
		return len;
	}
};

int main(void)
{
	Solution sol;
	string s1 = "eceba", s2 =  "ccaabbb"; 
	
	cout << sol.lengthOfLongestSubstringTwoDistinct(s1) << endl;
	cout << sol.lengthOfLongestSubstringTwoDistinct(s2) << endl;
	return 0;
}