#include <bits/stdc++.h> 
using namespace std; 

class Solution {
    vector<int> prefixSums;
public:
    Solution(vector<int> &w) {
        for (auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }

    int pickIndex() {
        // generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums.back();
        // run a linear search to find the target zone
        for (int i = 0; i < prefixSums.size(); ++i)
            if (target < prefixSums[i])
                return i;
        return prefixSums.size() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
 
 int main(void)
 {
	 vector<int> w1{1};
	 
	Solution* solution1 = new Solution(w1);
	cout << solution1->pickIndex() << endl; 
	
	vector<int> w2{1,3};
	Solution* solution = new Solution(w2);
	cout << solution->pickIndex() << endl; // return 1. It's returning the second element (index = 1) that has probability of 3/4.
	cout << solution->pickIndex() << endl; // return 1
	cout << solution->pickIndex() << endl; // return 1
	cout << solution->pickIndex() << endl; // return 1
	cout << solution->pickIndex() << endl; // return 0. It's returning the first element (index = 0) that has probability of 1/4.
	 
	 return 0;
 }