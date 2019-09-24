#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
        if (matrix.size() == 0) return ans;
        int R = matrix.size(), C = matrix[0].size();
		
        vector<vector<bool>> seen(R,vector<bool>(C));
		
        vector<int> dr{0, 1, 0, -1};
        vector<int> dc{1, 0, -1, 0};
        int r = 0, c = 0, di = 0;
        for (int i = 0; i < R * C; i++) {
            ans.push_back(matrix[r][c]);
            seen[r][c] = true;
            int cr = r + dr[di];
            int cc = c + dc[di];
            if (0 <= cr && cr < R && 0 <= cc && cc < C && !seen[cr][cc]){
                r = cr;
                c = cc;
            } else {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        return ans;
        
    }
};

int main(void)
{
	Solution sol; 
	vector<vector<int>>  matrix{{ 1, 2, 3 },
								{ 4, 5, 6 },
								{ 7, 8, 9 }};
	vector<int> ans = sol.spiralOrder(matrix);  
	
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ","; 
	return 0;
}
