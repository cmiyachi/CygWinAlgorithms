#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int n = nums.size(); 
        for (int reach = 0; i < n && i <= reach; ++i)
            reach = max(i + nums[i], reach);
        return i == n;
        
    }
};

int main(void)
{
	Solution sol;
	
	vector<int> nums{3,2,1,0,4};
	vector<int> nums2{2,3,1,1,4};
	
	cout << sol.canJump(nums) << endl;
	cout << sol.canJump(nums2) << endl;
	return 0;
}
