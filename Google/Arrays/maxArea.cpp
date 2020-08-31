#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int maxarea = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};

int main(void)
{
	vector<int> h{1,8,6,2,5,4,8,3,7};
	
	Solution sol;
	
	cout << sol.maxArea(h); 
	return 0;
}