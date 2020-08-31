#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    // Time O(N), Space O(N)
	/**
	Problem
"Start from any index, we can collect at most two types of fruits. What is the maximum amount"


Translation
Find out the longest length of subarrays with at most 2 different numbers?
**/

    int totalFruit(vector<int> &tree) {
        unordered_map<int, int> count;
        int i, j;
        for (i = 0, j = 0; j < tree.size(); ++j) {
            count[tree[j]]++;
            if (count.size() > 2) {
                if (--count[tree[i]] == 0)count.erase(tree[i]);
                i++;
            }
        }
        return j - i;
    }
};

int main(void)
{
	Solution sol;
	vector<int> tree{1,2,3,2,2};
	
	cout << sol.totalFruit(tree) << endl;
	
	return 0;
}