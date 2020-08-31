#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getRange(int start, int end){
        return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        long int pre = (long) lower - 1;
        
        for(int i = 0; i <= nums.size(); i++){
            long int cur = i == nums.size() ? (long) upper+1 : (long) nums[i];
            if(cur - pre >= 2)
                result.push_back(getRange(pre+1, cur-1));
            pre = cur;
            
        }
        
        return result;
    }
};

int main(void)
{
	Solution sol;
	vector<int> nums{0, 1, 3, 50, 75};
	int	lower = 0, upper = 99;
	
	vector<string> result = sol.findMissingRanges(nums, lower, upper);
	
	for (auto s: result)
		cout << s << " , ";
	
	return 0;
}