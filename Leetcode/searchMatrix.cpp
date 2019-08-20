#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size() -1;
		int col = 0; 
		
		 while (row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] > target) {
                row--;
            } else if (matrix[row][col] < target) {
                col++;
            } else { // found it
                return true;
            }
        }
        return false;
    }
};

int main(void)
{
	Solution sol;
	
	vector<vector<int>> matrix{
			  {1,   4,  7, 11, 15},
			  {2,   5,  8, 12, 19},
			  {3,   6,  9, 16, 22},
			  {10, 13, 14, 17, 24},
			  {18, 21, 23, 26, 30}
			};
			
	cout << sol.searchMatrix(matrix, 5) << endl;; 
	cout << sol.searchMatrix(matrix, 20); 
	return 0;
}