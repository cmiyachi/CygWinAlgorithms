#include <bits/stdc++.h> 
using namespace std;
int isSafe(vector<vector<int>> M, int row, 
           int col, 
           vector<vector<bool>> visitied);
void dfs(vector<vector<int>> M, int row, int col, 
         vector<vector<bool>> &visited, int& count); 

int isSafe(vector<vector<int>> M, int row, 
           int col, 
           vector<vector<bool>> visited)
{
	int ROW = M.size();
	int COL = M[0].size();
	cout << "R C " << ROW << " " << COL << "r c " << row << " " << col << endl;
    // row number is in range, 
    // column number is in 
    // range and value is 1 
    // and not yet visited 
    return (row >= 0) 
           && (row < ROW) 
           && (col >= 0) 
           && (col < COL) 
           && (M[row][col] 
               && !visited[row][col]); 
} 
void dfs(vector<vector<int>> M, int row, int col, 
         vector<vector<bool>> &visited, int& count) 
{ 
    // These arrays are used 
    // to get row and column 
    // numbers of 8 neighbours 
    // of a given cell 
    static int rowNbr[] = {-1, 0, 0, 1}; 
    static int colNbr[] = { 0,-1, 1, 0}; 
  
    // Mark this cell as visited 
    visited[row][col] = true; 
  
    // Recur for all connected neighbours 
    for (int k = 0; k < 4; ++k) { 
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], 
                   visited)) { 
            // Increment region length by one 
            count++; 
			cout << "row " << row << " col " <<col << " count " << count << " k " << k << endl;
            dfs(M, row + rowNbr[k], col + colNbr[k], 
                visited, count); 
        } 
    } 
} 
vector<int> riverSizes(vector<vector<int>> matrix) {
  // Write your code here.
	int n = matrix.size();
	int m = matrix[0].size();
	vector<int> results; 
	vector<vector<bool>> visited(n,vector<bool>(m, false)); 
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j]  && !visited[i][j])
			{
				int count = 1; 
				dfs(matrix, i, j, visited, count);
				results.push_back(count);
			}

		}
  return results;
}

int main(void)
{
	vector<vector<int>> testInput{
          {1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 1},
          {1, 0, 1, 0, 1}, {1, 0, 1, 1, 0},
      };
      vector<int> expected{1, 2, 2, 2, 5};
      vector<int> output = riverSizes(testInput);
      sort(output.begin(), output.end());
	  
	  for (auto num : output)
		  cout << num << " ";
	return 0;
}
