
#include <bits/stdc++.h>
using namespace std;

/// https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& A) {
        int ans = 0;
        for(int i=0;i<A.size();i++){
            ans = ans ^ A[i];
        }
        return ans;
    }
};

int main(void)
{
	vector<int> nums{4,1,2,1,2};
	
	Solution sol;
	
	cout << sol.singleNumber(nums);
	
	return 0;
}