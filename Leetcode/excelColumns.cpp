#include <bits/stdc++.h>
using namespace std;

/// https://leetcode.com/problems/excel-sheet-column-number/
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        long long pow = 1;
        int n = s.size();
        
        for(int i=n-1;i>=0;i--){
            ans = ans + (s[i]-64)*pow;
            pow = pow*26;
        }
        return ans;
    }
};

int main(void)
{
	string s = "A";
	Solution sol;
	
	cout << sol.titleToNumber(s) << endl;
	cout << sol.titleToNumber("AB") << endl;	
	cout << sol.titleToNumber("ZY") << endl;	
	return 0;
}