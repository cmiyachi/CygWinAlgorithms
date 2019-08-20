#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
                return {low + 1, high + 1};
            else if (sum < target)
                ++low;
            else
                --high;
        }
        return {-1, -1};
    }
};

int main(void)
{
	
	vector<int> numbers{2,7,11,15};
	int target = 9;
	
	Solution sol;
	vector<int>  result = sol.twoSum(numbers, target);
	
	for (int i = 0;i < result.size(); i++)
		cout << result[i] <<","; 
	

return 0;
}