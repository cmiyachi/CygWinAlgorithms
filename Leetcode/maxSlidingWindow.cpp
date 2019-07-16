#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size(); 
		vector<int> result; 
		
		if (n*k == 0) {
			result.push_back(0); 
			return result; 
		}
		for (int i=0; i < n-k+1; i++)
		{
			int thismax = INT_MIN; 
			for (int j = 0; j < i+k;j++)
				thismax = max(thismax, nums[j]);
			result.push_back(thismax); 
		}
		return result; 
    }
};

class Solution2 { 
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        vector<int> result;
        deque<int> d;

        for (auto i=0; i<nums.size(); i++) {
            if (!d.empty() && d.front() <= i-k)
                d.pop_front();

            while (!d.empty() && nums[i] > nums[d.back()])
                d.pop_back();

            d.push_back(i);

            if (i >= k-1)
                result.push_back(nums[d.front()]);
        }

        return result;
    }
};


int main(void)
{
	vector<int> nums{1,3,-1,-3,5,3,6,7};
	int k = 3;
	vector<int> result;
	Solution sol;
	
	result = sol.maxSlidingWindow(nums, k); 
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ", "; 
	return 0;
}

/*

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if (n * k == 0) return new int[0];
        
        int [] output = new int[n - k + 1];
        for (int i = 0; i < n - k + 1; i++) {
            int max = Integer.MIN_VALUE;
            for(int j = i; j < i + k; j++) 
                max = Math.max(max, nums[j]);
            output[i] = max;
        }
        return output;
    }
}*/