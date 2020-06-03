#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
		// Start from last and find the index where value start decreasing
        int i = nums.size()-1;
        while(i>0) {
            if (nums[i]>nums[i-1]){ // This is the decreasing point.
				// Find next larger value and replace the smaller value i.e. nums[i-1] with it.
				int j=i;
                while(j+1<nums.size() && nums[j+1]>nums[i-1])
                    j++;
                swap(nums[i-1], nums[j]);
                break;
            }
            i--;
        }
		// As the right side of the list is in decending order, reverse it in ascending in order to get next greater permutation number.
        reverse(nums.begin()+i, nums.end());
    }