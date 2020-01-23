#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; 
		
		int left = mySqrt(x >> 2) << 1; 
		int right = left + 1; 
		return (long )right * right > x ? left : right; 
    }
};


int main(void)
{
	Solution sol;
	
	cout << sol.mySqrt(4) << endl;
	
	cout << sol.mySqrt(8) << endl; 
	
	return 0;
}