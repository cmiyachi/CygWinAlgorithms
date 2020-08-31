#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
		int dist, zero, i;
		int seatsSize = seats.size();

		dist = 0;
		// if seats begin with 0 this is required.
		while (seats[dist] == 0)
			++dist;
		zero = 0;
		// general case
		for (i = dist + 1; i < seatsSize; ++i)
			if (seats[i] == 0) {
				++zero;
			} else {
				dist = max(dist, (zero + 1) / 2);
				zero = 0;
			}

		return max(dist, zero);
			
		}
};

int main(void)
{
	Solution sol;
	vector<int> seats{1,0,0,0,1,0,1};
	
	cout << sol.maxDistToClosest(seats) << endl;
	
	vector<int> seats2{1,0,0,0};
	cout << sol.maxDistToClosest(seats2) << endl;
	return 0;
}