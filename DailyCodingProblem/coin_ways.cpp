#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;

        for (int coin : coins) {
          for (int x = coin; x < amount + 1; ++x) {
            dp[x] += dp[x - coin];
          }
        }
        return dp[amount];

}
    };
	
int main(void)
{
	vector<int> coins{1,5};
	
	int n = 100;
	
	Solution sol;
	cout << sol.change(n, coins);
	
	return 0;
}
