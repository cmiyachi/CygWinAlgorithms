//https://leetcode.com/problems/guess-number-higher-or-lower-ii/
#include <bits/stdc++.h>

// The wording of the question is confusing. In general, we want to use binary search to narrow
// the range of guesses. However, the binary search path does not yield the minimum cost.
// For example: with {1,2,3,4}, the worst case for binary search costs 2 + 3 = 5. 
// However, choosing 3 then 1 (cost=$4) is a tighter upper bound (3 is a better first guess than 2).
// Brute Force: Try all initial guesses then recurse on left and right sub-ranges. 
// Better: Improve the above, by memo-izing based on [start,end] of the range.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> table(n+1, vector<int>(n+1,0)); 
        return dp(1,n, table);    
    }
    int dp(int left, int right, vector<vector<int>>& table) {
        if (left >= right) return 0;
        if (table[left][right] != 0) return table[left][right];
        int min_choice = INT_MAX;
        for (int i = left; i <= right; ++i) {
            int tmp = max(i + dp(i+1, right, table), i + dp(left, i-1, table));
            min_choice = min(min_choice, tmp);
        }
        table[left][right] = min_choice;
        return min_choice;
    }
};
int main() {
    Solution s;
    for (int i = 0; i < 21; ++i) {
        cout << i << " : " << s.getMoneyAmount(i) << endl;
    }
}