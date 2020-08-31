#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
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
};

int main(void)
{
	Solution sol;
	
	vector<int> first{1,2,3};
	vector<int> second{3,2,1};
	vector<int> third{1,1,5};
	
	sol.nextPermutation(first);
	for (auto num : first)
		cout << num << ",";
	cout << endl;
	
	sol.nextPermutation(second);
	for (auto num : second)
		cout << num << ",";
	cout << endl;
	
	sol.nextPermutation(third);
	for (auto num : third)
		cout << num << ",";
	cout << endl;
	
	return 0;
}

	