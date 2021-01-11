#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          dfs(grid, r, c);
        }
      }
    }

    return num_islands;
  }
};

class Solution2 {
public:
    
     void solve(vector<vector<char>>& grid ,int start , int end){
            if(start>=grid.size() || end>=grid[start].size() ||start<0 )
                return ;
            
            if(grid[start][end]=='1'){
                grid[start][end]='2';  //marking as visited grid 
                solve(grid , start , end+1); //recursive call 
                solve(grid  , start ,end-1);
                solve(grid  ,start-1 , end);
                solve(grid  , start+1 , end);
            }
            
        }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int ans =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){ // only call the solve function when the grid[i][j] is not visited
                    solve(grid  , i ,j);
                    ans++;  // counting the number of island
                }
            }
        }
        return ans;
    }
};

int main(void)
{
	vector<char> row1{'1','1','1','1','0'};
	vector<char> row2{'1','1','0','1','0'};
	vector<char> row3{'1','1','0','0','0'};
	vector<char> row4{'0','0','0','0','0'};

	vector<vector<char>> grid{row1,row2,row3,row4};
	
	Solution sol;
	cout << sol.numIslands(grid); 
	
	return 0;
}