#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        while (arr[i] < arr[i+1]) i++;
        return i;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
		int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (arr[mi] < arr[mi + 1])
                lo = mi + 1;
            else
                hi = mi;
        }
        return lo;
	}
};

int main(void)
{
	Solution sol;
	vector<int> arr{0,10,5,2};
	
	cout << sol.peakIndexInMountainArray(arr) << endl;
	return 0;
}