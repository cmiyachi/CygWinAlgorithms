#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
		
		// transpose
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int tmp = matrix[j][i];
				matrix[j][i] = matrix[i][j];
				matrix[i][j] = tmp;
			}
		}
		 // reverse each row
		for (int i = 0; i < n; i++) {
		  for (int j = 0; j < n / 2; j++) {
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[i][n - j - 1];
			matrix[i][n - j - 1] = tmp;
		  }
		}
    }
};
int main(void)
{
	vector<int> a{1,2,3};
	vector<int> b{4,5,6};
	vector<int> c{7,8,9}; 
	
	vector<vector<int>> matrix; 
	matrix.push_back(a);
	matrix.push_back(b);
	matrix.push_back(c); 
	
	Solution sol;
	sol.rotate(matrix);
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << matrix[i][j] << " , ";
		cout << endl;
	}
		
  
  return 0;
}