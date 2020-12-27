/// https://leetcode.com/problems/longest-common-prefix/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
       /* string ans = "";
        if(strs.size()==0) return "";
        
        string s = *min_element(strs.begin(),strs.end());  /// return min string
        
        for(int i=0;i<s.size();i++){
            for(int j=0;j<strs.size();j++){
                if(s[i] != strs[j][i]){
                    return ans;
                }
            }
            ans.push_back(s[i]);
        }
        return ans;*/
        
         string ans = "";
        if(strs.size()==0) return "";
        
        string s = strs[0]; 
        
        for(int i=0;i<s.size();i++){
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].size() || s[i] != strs[j][i]){
                    return ans;
                }
            }
            ans.push_back(s[i]);
        }
        return ans;
        
    }
};

int main(void)
{
	vector<string> strs{"flower","flow","flight"};
	vector<string> strs2{"dog","racecar","car"};
	Solution sol;
	
	cout << sol.longestCommonPrefix(strs) << endl; 
	cout << sol.longestCommonPrefix(strs2) << endl; 

	return 0;
}