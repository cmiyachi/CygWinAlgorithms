#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	 bool magic(vector<int> vals) {
        vector<int> count(16); 
        for (int v: vals) count[v]++;
        for (int v = 1; v <= 9; ++v)
            if (count[v] != 1)
                return false;

        return (vals[0] + vals[1] + vals[2] == 15 &&
                vals[3] + vals[4] + vals[5] == 15 &&
                vals[6] + vals[7] + vals[8] == 15 &&
                vals[0] + vals[3] + vals[6] == 15 &&
                vals[1] + vals[4] + vals[7] == 15 &&
                vals[2] + vals[5] + vals[8] == 15 &&
                vals[0] + vals[4] + vals[8] == 15 &&
                vals[2] + vals[4] + vals[6] == 15);
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
		int R = grid.size(), C = grid[0].size();
        int ans = 0;
        for (int r = 0; r < R-2; ++r)
            for (int c = 0; c < C-2; ++c) {
                if (grid[r+1][c+1] != 5) continue;  // optional skip
				vector<int> vals{grid[r][c], grid[r][c+1], grid[r][c+2],
                          grid[r+1][c], grid[r+1][c+1], grid[r+1][c+2],
				grid[r+2][c], grid[r+2][c+1], grid[r+2][c+2]};
                if (magic(vals))
                    ans++;
            }

        return ans;
        
    }
};

int main(void)
{
	vector<vector<int>> grid{{4,3,8,4},
        {9,5,1,9},
			{2,7,6,2}}; 
			
	Solution sol;
	
	cout << sol.numMagicSquaresInside(grid); 
	
	return 0;
}

/*
Let's check every 3x3 grid individually. For each grid, all numbers must be unique and between 1 and 9; plus every row, column, and diagonal must have the same sum.

Extra Credit

We could also include an if grid[r+1][c+1] != 5: continue check into our code, helping us skip over our for r... for c... for loops faster. This is based on the following observations:

The sum of the grid must be 45, as it is the sum of the distinct values from 1 to 9.
Each horizontal and vertical line must add up to 15, as the sum of 3 of these lines equals the sum of the whole grid.
The diagonal lines must also sum to 15, by definition of the problem statement.
Adding the 12 values from the four lines that cross the center, these 4 lines add up to 60; but they also add up to the entire grid (45), plus 3 times the middle value. This implies the middle value is 5.
*/