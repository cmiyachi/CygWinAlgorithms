#include <bits/stdc++.h>

using namespace std;

int tilings(n)
{
	vector<int> f(n+1,0);
	vector<int> g(n+1,0);
	
	f[1] = 1; f[2] = 2;
	g[1] = 1; g[2] = 2;
	
	for (int i = 3; i < n+1; i++)
	{
		f[i] = f[i-1] + f[i-2] + 2*g[i-2];
		g[i] = g[i-1] + f[i-1];
		
	}
	
	return f[n];
	
}
class Solution2 {
public:
    int mod=1e9+7;
    vector<int> t;
    int solve(int i){
        if(i<=1)
            return 1;
        
        if(i==2)
            return 2;
        
        if(t[i]!=-1)
            return t[i];
        
        int ans=0;
        ans=((2*solve(i-1))%mod+(solve(i-3))%mod)%mod;
        
        return t[i]=ans;
    }
    
    int numTilings(int N) {
        t.resize(N+1,-1);
        return solve(N);
    }
};

class Solution {
public:
    int numTilings(int N) {
        int MOD = 1e9 + 7;
        int dp[2][3];
        dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 0;
        dp[0][2] = dp[1][2] = 1;
        for (int i = 2; i <= N; i++) {
            int a = (dp[1][1] + dp[0][2]) % MOD;
            int b = (dp[1][0] + dp[0][2]) % MOD;
            int c = ((dp[1][0] + dp[1][1]) % MOD + 
                        (dp[1][2] + dp[0][2]) % MOD) % MOD;
            dp[0][0] = dp[1][0], dp[0][1] = dp[1][1], dp[0][2] = dp[1][2];
            dp[1][0] = a, dp[1][1] = b, dp[1][2] = c;
        }
        return dp[1][2];
    }
};
