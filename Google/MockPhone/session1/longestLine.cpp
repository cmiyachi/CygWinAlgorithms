#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Approach: DP
     *
     * Time complexity:  O(R * C)
     * Space complexity: O(C)
     *
     * dp1[j] = M[i][j] * (1 + (j > 0 ? dp1[j - 1] : 0));
     * dp2[j] = M[i][j] * (1 + dp2[j]);
     * dp3[j] = M[i][j] * (1 + (j > 0 ? dp3[j - 1] : 0));
     * dp4[j] = M[i][j] * (1 + (j < col - 1 ? dp4[j + 1] : 0));
     *
     */
    int longestLine(vector<vector<int>> &M) {
        if (M.empty() || M[0].empty()) return 0;
        int row = M.size(), col = M[0].size();
        int result = 0;
        vector<int> dp1(col, 0), dp2(col, 0), dp3(col, 0), dp4(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                // 1. horizontal
                dp1[j] = M[i][j] * (1 + (j > 0 ? dp1[j - 1] : 0));
                result = max(result, dp1[j]);

                // 2. vertical
                dp2[j] = M[i][j] * (1 + dp2[j]);
                result = max(result, dp2[j]);

                // 4. anti-diagonal
                dp4[j] = M[i][j] * (1 + (j < col - 1 ? dp4[j + 1] : 0));
                result = max(result, dp4[j]);

            }
            // 3. diagonal
            for (int j = col - 1; j >= 0; --j) {
                dp3[j] = M[i][j] * (1 + (j > 0 ? dp3[j - 1] : 0));
                result = max(result, dp3[j]);
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> M = {{0, 1, 1, 0},
                             {0, 1, 1, 0},
                             {0, 0, 0, 1},
                             {0, 0, 1, 1},
                             {0, 1, 0, 0},
                             {1, 0, 0, 1}};
    //display_2d_vector(M);

    Solution s;
    cout << s.longestLine(M) << endl;
    return 0;
}