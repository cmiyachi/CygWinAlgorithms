#include <bits/stdc++.h>
using namespace std;
/**
First, check the sequence of L and R in start and end is the same;
Second, index of L in start should be >= index of corresponding L in end, while index of R <= corresponding index.
**/ 
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        string s1, s2;
        for (int i = 0; i < n; ++i) 
            if (start[i] != 'X') s1 += start[i];
        for (int i = 0; i < n; ++i) 
            if (end[i] != 'X') s2 += end[i];
        if (s1 != s2) return false;
        for (int i = 0, j = 0; i < n && j < n;) {
            if (start[i] == 'X') 
               i++;
            else if (end[j] == 'X') 
               j++;
            else {
                if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;
                i++;
                j++;
            }
        }
        return true;
    }
};

int main(void)
{
	Solution sol;
	string start = "LLR", end = "RRL"; 
	cout << sol.canTransform(start, end) << endl;
	
	return 0;
}