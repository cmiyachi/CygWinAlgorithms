#include <bits/stdc++.h> 
using namespace std; 

// brute force
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int result = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int accu = 1;
            for (int j = i; j < nums.size(); j++) {
                accu *= nums[j];
                result = max(result, accu);
            }
        }

        return result;
    }
};


class Solution {
    public:
	int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

            max_so_far = temp_max;

            result = max(max_so_far, result);
        }

        return result;
    }
};

int main(void)
{
	vector<int> nums{2,3,-2,4}; 
	Solution sol;
	cout << sol.maxProduct(nums) << endl;
	return 0;
}
	