class Solution {
public:
    void dfs(int cur, int m, int n, int step, vector<vector<int>>& skips, int& res, vector<bool> visited){
        if(step > n){
            return ;
        }
        if(step >= m){
            res++;
        }
        step++;
        visited[cur] = true;
        for(int x = 1; x <= 9; x++){
            if(!visited[x] && (skips[cur][x]==0 || visited[skips[cur][x]])){
                dfs(x, m, n, step, skips, res, visited);
            }
        }
    }
    
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skips(10, vector<int>(10, 0));
        skips[1][3] = 2;
        skips[1][7] = 4;
        skips[1][9] = 5;
        
        skips[3][1] = 2;
        skips[3][7] = 5;
        skips[3][9] = 6;
        
        skips[7][1] = 4;
        skips[7][3] = 5;
        skips[7][9] = 8;
        
        skips[9][3] = 6;
        skips[9][1] = 5;
        skips[9][7] = 8;
        
        skips[2][8] = 5;
        skips[8][2] = 5;
        skips[4][6] = 5;
        skips[6][4] = 5;
        
        int res = 0;
        vector<bool> visited(10, false);
        int res1 = 0;
        dfs(1, m, n, 1, skips, res1, visited);
        res1 *= 4;
        int res2 = 0;
        dfs(2, m, n, 1, skips, res2, visited);
        res2 *= 4;
        int res3 = 0;
        dfs(5, m, n, 1, skips, res3, visited);
        return res1 + res2 + res3;
    }
};
/*
The optimization idea is that 1,3,7,9 are symmetric, 2,4,6,8 are also symmetric. Hence we only calculate one among each group and multiply by 4.

public class Solution {
    // cur: the current position
    // remain: the steps remaining
    int DFS(boolean vis[], int[][] skip, int cur, int remain) {
        if(remain < 0) return 0;
        if(remain == 0) return 1;
        vis[cur] = true;
        int rst = 0;
        for(int i = 1; i <= 9; ++i) {
            // If vis[i] is not visited and (two numbers are adjacent or skip number is already visited)
            if(!vis[i] && (skip[cur][i] == 0 || (vis[skip[cur][i]]))) {
                rst += DFS(vis, skip, i, remain - 1);
            }
        }
        vis[cur] = false;
        return rst;
    }
    
    public int numberOfPatterns(int m, int n) {
        // Skip array represents number to skip between two pairs
        int skip[][] = new int[10][10];
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        boolean vis[] = new boolean[10];
        int rst = 0;
        // DFS search each length from m to n
        for(int i = m; i <= n; ++i) {
            rst += DFS(vis, skip, 1, i - 1) * 4;    // 1, 3, 7, 9 are symmetric
            rst += DFS(vis, skip, 2, i - 1) * 4;    // 2, 4, 6, 8 are symmetric
            rst += DFS(vis, skip, 5, i - 1);        // 5
        }
        return rst;
    }
}*/