#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		 int N = points.size();
        vector<int> dists(N);
        for (int i = 0; i < N; ++i)
            dists[i] = dist(points[i]);

        sort(dists.begin(), dists.end());
        int distK = dists[K-1];

        vector<vector<int>> ans; // = new int[K][2];
        int t = 0;
        for (int i = 0; i < N; ++i)
            if (dist(points[i]) <= distK)
                ans.push_back(points[i]);
        return ans;
        
    }
	int dist(vector<int> point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};

int main(void)
{
	int K = 1; 
	vector<vector<int>> points{{1,3},{-2,2}};
	
	Solution sol;
	vector<vector<int>> result = sol.kClosest(points, K); 
	
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << ", "; 
		cout << endl;
	}
	
	return 0;
}