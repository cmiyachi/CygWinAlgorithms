#include <bits/stdc++.h>
using namespace std;

// n2 so too slow
class Solution2 {
public:
    vector<int> countSmaller(vector<int>& nums) {

	int n = nums.size();
	vector<int> countSmaller(n,0);

	  for (int i = 0; i < n; i++) 
	  { 
		for (int j = i+1; j < n; j++) 
		{ 
		   if (nums[j] < nums[i]) 
			 countSmaller[i]++; 
		} 
	  } 
	  return countSmaller; 
	} 
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> db;
        vector<int> result(nums.size());
        for(int i = nums.size()-1; i >= 0; i--)
        {
            auto it = lower_bound(db.begin(), db.end(), nums[i]);
			
			cout << "n " << nums[i] << " i " << i <<  endl;
            result[i] = it - db.begin();
			cout << "re " << result[i] << endl;
            db.insert(it, nums[i]);
			for (auto d:db)
				cout << "db " << d << endl;
        }
        return result;
    }
};

int main(void)
{
	Solution sol;
	
	vector<int> nums{5,2,6,1};
	
	vector<int> result = sol.countSmaller(nums);
	
	for (auto r :result)
		cout << r << ",";
	return 0;
}