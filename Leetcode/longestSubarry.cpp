#include <bits/stdc++.h> 
using namespace std; 
class Solution2 {
public:
    // time: O(n), space: O(n)
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxdq, mindq;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!maxdq.empty() && nums[i] > maxdq.back()) maxdq.pop_back();
            while (!mindq.empty() && nums[i] < mindq.back()) mindq.pop_back();
            maxdq.push_back(nums[i]);
            mindq.push_back(nums[i]);
            while (maxdq.front() - mindq.front() > limit) {
                if (maxdq.front() == nums[j]) maxdq.pop_front();
                if (mindq.front() == nums[j]) mindq.pop_front();
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};

class Solution {
public:
    // binary search tree
    // Time: O(nlogn), Space: O(n)
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ms.insert(nums[i]);
            while (*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[j]));
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};

int main(void)
{
	vector<int> nums{8,2,4,7};
	int limit = 4;
	
	Solution sol;
	
	cout << sol.longestSubarray(nums, limit) << endl;
	return 0;
}