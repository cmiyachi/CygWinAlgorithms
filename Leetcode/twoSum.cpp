#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result; 
		map<int,int>  num_map; 
		
		for (int i = 0; i < nums.size(); i++)
		{
			int complement = target - nums[i]; 
			if (num_map.find(complement) != num_map.end())
			{
				result.push_back(num_map[complement]);
				result.push_back(i);
				return result; 
			}
			num_map[nums[i]] = i; 
		} // for
        
    }
};

int main(void)
{
	Solution sol; 
	
	vector<int> nums{2, 7, 11, 15};
	
	vector<int>  result = sol.twoSum(nums, 9);
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl; 
	return 0;
}
/*
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement)) {
            return new int[] { map.get(complement), i };
        }
        map.put(nums[i], i);
    }
    throw new IllegalArgumentException("No two sum solution"); 
} */