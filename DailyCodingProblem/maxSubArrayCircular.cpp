
#include <bits/stdc++.h>
using namespace std; 

class Solution {
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
	int minSubArray(vector<int>& nums) {
		int n = nums.size();
		int currSum = nums[0], minSum = nums[0];

		for(int i = 1; i < n; ++i) {
		  currSum = min(nums[i], currSum + nums[i]);
		  minSum = min(minSum, currSum);
		}
		return minSum;
        
    }
	int maxSubarraySumCircular(vector<int>& A) {
		
		int arrSum = 0;
		for (int i = 0; i < A.size(); i++)
			arrSum += A[i];
		
		int maxSumCircular = arrSum - minSubArray(A);
		if (maxSumCircular == 0)
			return maxSubArray(A);
		else 
			return max(maxSubArray(A), maxSumCircular); 
    }
};

int main(void)
{
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	
	Solution sol;
	
	/* cout << sol.maxSubArray(nums) << endl;
	
	vector<int> nums2{34,-50,42,14,-5,86};
	cout << sol.maxSubArray(nums2) << endl;
	
	vector<int> nums3{-5,-1,-8,-9};
	cout << sol.maxSubArray(nums3) << endl;
	
	vector<int> nums4{8,-1,3,4};
	cout << sol.maxSubArray(nums4) << endl; */
	
	vector<int> nums5{-3, -2, -1};
	cout << sol.maxSubarraySumCircular(nums5) << endl;
	
	return 0;
}