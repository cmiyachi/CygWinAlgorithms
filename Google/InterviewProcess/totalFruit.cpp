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
	vector<int> tree{0,1,2,2};
	
	cout << sol.totalFruit(tree) << endl;
	
	return 0;
}

/*
Keep count of each same type of continuos fruit in a vector.
For this: [3,3,3,1,2,1,1,2,3,3,4]
maxCons will be: {3,3}, {1,1}, {2,1}, {1,2}, {2,1}, {3,2}, {4,1}

Now, iterate over this and keep increasing count till current fruit is equal to the any of the last fruit.
Otherwise, update max count and keep the last fruit as the first fruit and current as the second fruit(we have two baskets, so first fruit and second fruit) and keep their sum as the current count.*/

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        vector<pair<int, int>> maxCons;
        int count = 1, prev = -1;
        for(int i = 0; i < tree.size(); i++){
            if(tree[i] == prev){
                count++;
            } else {
                if(prev != -1)
                    maxCons.push_back({prev, count});
                count = 1;
                prev = tree[i];
            }
        }
        maxCons.push_back({prev, count});
        count = 0;
        int first = -1, second = -1, ans = INT_MIN;
        for(int i = 0; i < maxCons.size(); i++){
            if(first == -1){
                first = maxCons[i].first;
                count += maxCons[i].second;
            } else if(second == -1){
                second = maxCons[i].first;
                count += maxCons[i].second;
            } else if(maxCons[i].first == first || maxCons[i].first == second){
                count += maxCons[i].second;
            } else {
                ans = max(ans, count);
                first = maxCons[i-1].first;
                second = maxCons[i].first;
                count = maxCons[i-1].second + maxCons[i].second;
            }
        }
        return max(ans, count);;
    }
};