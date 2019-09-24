#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int count = 0;
        for (int start = 0; start < nums.size(); start++) {
            int sum=0;
            for (int end = start; end < nums.size(); end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
};

int main(void)
{
	Solution sol;
	vector<int> nums{1,1,1};
	int k = 2;
	
	cout << sol.subarraySum(nums, k);
	
	return 0;
}