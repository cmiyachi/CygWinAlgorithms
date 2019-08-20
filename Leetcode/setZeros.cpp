#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		int MODIFIED = -1000000;
		int R = matrix.size();
		int C = matrix[0].size();
		
		for (int r = 0; r < R; r++) {
		  for (int c = 0; c < C; c++) {
			if (matrix[r][c] == 0) {
			  // We modify the corresponding rows and column elements in place.
			  // Note, we only change the non zeroes to MODIFIED
			  for (int k = 0; k < C; k++) {
				if (matrix[r][k] != 0) {
				  matrix[r][k] = MODIFIED;
				}
			  }
			  for (int k = 0; k < R; k++) {
				if (matrix[k][c] != 0) {
					matrix[k][c] = MODIFIED;
				}
			  }
			}
		  }
		} //for
		
		 for (int r = 0; r < R; r++) {
		  for (int c = 0; c < C; c++) {
			// Make a second pass and change all MODIFIED elements to 0 """
			if (matrix[r][c] == MODIFIED) {
			  matrix[r][c] = 0;
			}
		  }
		} 
    }
};

int main(void)
{
	vector<vector<int>> matrix{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
	Solution sol;
	sol.setZeroes(matrix);
	
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " "; 
		cout << endl;
	}
	
	return 0;
}