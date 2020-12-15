#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();
        
        vector<int> dp(n+1 , 0);
        
        dp[0] = 1;
    
        if( s[0] == 0)
            return 0;
        
        for(int i= 1; i<= n ;i++)
        {
            if( s[i-1] > '0')
            {
                dp[i] = dp[i-1];
            }
            if( i >= 2 and (s[i-2] == '1' or (s[i-2] == '2' and s[i-1] < '7')))
                dp[i]+= dp[i-2];
        }
        return dp[n];
    }
};


class Solution2 {
public:
    int numDecodings(string s) {
         return s.empty() ? 0: numDecodings(0,s);
    }
	int numDecodings(int p, string& s) {
        int n = s.size();
        if(p == n) return 1;
        if(s[p] == '0') return 0;
        int res = numDecodings(p+1,s);
        if( p < n-1 && (s[p]=='1'|| (s[p]=='2'&& s[p+1]<'7'))) res += numDecodings(p+2,s);
        return res;
    }
};

int main(void)
{
	
	Solution sol;
	cout << sol.numDecodings("111");
	
	return 0;
}