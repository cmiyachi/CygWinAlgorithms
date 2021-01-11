class Solution {
public:
    typedef pair<int, int> PII;
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<PII> q;
        int sum = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                if (!v) continue;
                if (v == 2) {
                    q.push({i, j}); 
                    visited[i][j] = true;
                }
                sum++;
            }
        
		// judge corner cases
        if (sum == 0) return 0;
        if (q.size() == 0) return -1;
        if (sum == q.size()) return 0;
        
        int step = 0, cnt = 0;
        while (q.size()) {
            int sz = q.size();
            cnt += sz;
            for (int i = 0; i < sz; i++) {
                PII a = q.front(); q.pop();
                for (int j = 0; j < 4; j++) {
                    int x = dx[j] + a.first, y = dy[j] + a.second;
                    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || grid[x][y] == 0) continue;
                    visited[x][y] = true;
                    
                    q.push({x, y});
                }
            }
            step++;
        }
        if (cnt == sum) return step - 1;
        else return -1;
    }
};

class Solution {
public:
  
    int orangesRotting(vector<vector<int>>& matrix) {
    vector<vector<int>> directions{
          {-1, 0}, //up
           {0, 1}, //right
            {1, 0}, //down
             {0, -1} //left
            };
      if(matrix.size() == 0) return 0;

      queue<vector<int>> q;
      int freshOranges = 0;

      for(int row = 0; row < matrix.size(); row++) {
        for(int col = 0; col < matrix[0].size(); col++) {
          if(matrix[row][col] == 2) {
            q.push({row, col});
          }

          if(matrix[row][col] == 1) {
            freshOranges++;
          }
        }
      }

      int minutes = 0;
      int currentQueueSize = q.size();

      while(q.size() > 0) {
        if(currentQueueSize == 0) {
          currentQueueSize = q.size();
          minutes++;
        }

        vector<int> currentOrange = q.front(); q.pop();
        currentQueueSize--;
        int row = currentOrange[0];
        int col = currentOrange[1];

        for(int i = 0; i < directions.size(); i++) {
          auto currentDir = directions[i];
          auto nextRow = row + currentDir[0];
          auto nextCol = col + currentDir[1];

          if(nextRow < 0 || nextRow >= matrix.size() || nextCol < 0 || nextCol >= matrix[0].size()) {
            continue;
          }

          if (matrix[nextRow][nextCol] == 1) {
            matrix[nextRow][nextCol] = 2;
            freshOranges--;
            q.push({nextRow, nextCol});
          }
        }
      }

      if(freshOranges != 0) {
        return -1;
      }

      return minutes;

        }
    };
