
#include <bits/stdc++.h>
using namespace std; 

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int currSum = nums[0], maxSum = nums[0];

		for(int i = 1; i < n; ++i) {
		  currSum = max(nums[i], currSum + nums[i]);
		  maxSum = max(maxSum, currSum);
		}
		return maxSum;
        
    }
};

class Solution3 {
public:
	 int crossSum(vector<int> nums, int left, int right, int p) {
		if (left == right) return nums[left];

		int leftSubsum = INT_MIN;
		int currSum = 0;
		for(int i = p; i > left - 1; --i) {
		  currSum += nums[i];
		  leftSubsum = max(leftSubsum, currSum);
		}

		int rightSubsum = INT_MIN;
		currSum = 0;
		for(int i = p + 1; i < right + 1; ++i) {
		  currSum += nums[i];
		  rightSubsum = max(rightSubsum, currSum);
		}

		return leftSubsum + rightSubsum;
	  }

	int helper(vector<int> nums, int left, int right) {
		if (left == right) return nums[left];

		int p = (left + right) / 2;

		int leftSum = helper(nums, left, p);
		int rightSum = helper(nums, p + 1, right);
		int cross_sum = crossSum(nums, left, right, p);

		return max(max(leftSum, rightSum), cross_sum);
	  }

	int maxSubArray(vector<int>& nums) {
		return helper(nums, 0, nums.size());
	  }
};

class Solution {
  public:
	int maxSubArray(vector<int>& nums) {
    int n = nums.size(), maxSum = nums[0];
    for(int i = 1; i < n; ++i) {
      if (nums[i - 1] > 0) nums[i] += nums[i - 1];
      maxSum = max(nums[i], maxSum);
    }
    return maxSum;
  }
};


int main(void)
{
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	
	Solution sol;
	
	cout << sol.maxSubArray(nums);
	return 0;
}