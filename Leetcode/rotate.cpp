
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> a(nums.size()); 
        for (int i = 0; i < nums.size(); i++) {
            a[(i + k) % nums.size()] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = a[i];
        } // for
    }// rotate
};

int main(void)
{	
	vector<int> nums{-1,-100,3,99};
	int k = 2;
	
	Solution sol;
	
	sol.rotate(nums, k);
	
	for (auto x : nums)
		cout << x << ", ";
	
	return 0;
}