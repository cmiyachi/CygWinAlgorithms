class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0 || rooms[0].size() == 0) return; 
        int m = rooms.size(), n = rooms[0].size();
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0)
                    q.push(make_pair(i, j));
            }
        }
        
        int row, col;
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                row = x + directions[k][0];
                col = y + directions[k][1];
                if(row >= 0 && row < m && col >= 0 && col < n && rooms[row][col] == INT_MAX){
                rooms[row][col] = rooms[x][y] + 1;
                q.push(make_pair(row, col));
                }
            }
        }
    }
};