/// https://leetcode.com/problems/jump-game/
#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goodPos = n-1;
        
        for(int i=n-2;i>=0;i--){
            if(i + nums[i]  >= goodPos){
                goodPos = i;
            }
        }
        
        if(goodPos==0) return true;
        else return false;
    }
};

class Solution2 {
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
	vector<int> nums{2,3,1,1,4};
	Solution sol;
	
	cout << sol.canJump(nums) << endl;
	
	return 0;
}