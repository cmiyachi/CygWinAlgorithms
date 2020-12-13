#include <bits/stdc++.h> 
using namespace std;

class Solution{
	public: 
		int n;
    vector<int> circles;
    
    void join(int x1, int x2) {
        x1 = find(x1);
        x2 = find(x2);
        if (x1 != x2) {
            circles[x1] = x2;
        }
        return;
    }
    
    int find(int x) {
        if (x != circles[x]) {
            circles[x] = find(circles[x]);
        }
        return circles[x];
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        n = M.size();
        for (int i = 0; i < n; i++) 
            circles.push_back(i);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && M[i][j] == 1) {
                    join(i, j);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++)
		{
			cout << "i " << i << " circle " << circles[i] << endl;
            if (i == circles[i])
			{
                result++;
				
			}
		}
			
        return result;
    }
};

int main(void)
{
	vector<vector<int>> M{	{0,1,1,0,0,0,0},
							{1,0,0,0,0,1,0},
							{1,0,0,0,0,0,0},
							{0,0,0,0,0,0,1},
							{0,0,0,0,0,0,0},
							{0,1,0,0,0,0,0},
							{0,0,0,1,0,0,0}};
	Solution sol;
	
	cout << "Count: "; 
	cout << sol.findCircleNum(M) << endl; 
	
	return 0;
}
						