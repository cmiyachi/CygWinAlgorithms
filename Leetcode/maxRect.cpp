#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) return 0;
        int maxarea = 0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == '1'){

                    // compute the maximum width and update dp with it
                    dp[i][j] = j == 0? 1 : dp[i][j-1] + 1;

                    int width = dp[i][j];

                    // compute the maximum area rectangle with a lower right corner at [i, j]
                    for(int k = i; k >= 0; k--){
                        width = min(width, dp[k][j]);
                        maxarea = max(maxarea, width * (i - k + 1));
                    }
                }
            }
        } return maxarea;
        
    }
};

int main(void)
{
	Solution sol; 
	vector<vector<char>> input;
	vector<char> row1{'1','0','1','0','0'};
	vector<char> row2{'1','0','1','1','1'};
	vector<char> row3{'1','1','1','1','1'};
	vector<char> row4{'1','0','0','1','0'};
	input.push_back(row1);
	input.push_back(row2);
	input.push_back(row3);
	input.push_back(row4);
	
	cout << sol.maximalRectangle(input); 
	
	return 0;
}