// A Dynamic Programming based C++ program to find minimum of coins 
// to make a given change V 
#include<bits/stdc++.h> 
using namespace std; 

class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
		 int max = amount + 1;
		  // table[i] will be storing the minimum number of coins 
		// required for i value. So table[amount] will have result
		vector<int> dp(amount + 1, max);
		// Base case (If given value amount is 0) 
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
		  for (int j = 0; j < coins.size(); j++) {
			if (coins[j] <= i) {
			  dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		  }
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// Driver program to test above function 
int main() 
{ 
	Solution sol;
	vector<int> coins{9, 6, 5, 1};  
	int V = 11; 
	cout << "Minimum coins required is "
		<< sol.coinChange(coins, V); 
	return 0; 
} 
