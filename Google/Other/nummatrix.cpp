#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int N = matrix.size();
        if(!N) return;
        int M = matrix[0].size();
        if(!M) return;
        vector<vector<int>> temp (N, vector<int>(M + 1));
        rec = temp;

        for(int i = 0; i < N; i++){
            for(int j = M - 1; j >= 0;  j--){
                if(j == M-1) rec[i][j] = matrix[i][j];
                else rec[i][j] = rec[i][j+1] + matrix[i][j];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int pre = rec[row][col] - rec[row][col+1];
        for(int i = col; i >= 0; i--){
            rec[row][i] += (val - pre);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++){
            sum += (rec[i][col1] - rec[i][col2 + 1]);
        }
        return sum;
    }
private:
    vector<vector<int>> rec;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
/*
What I've done is just keep a record of accumulative sum of each row.
eg.

       [1,2,3]                                                   [ 6,5,3]
Given  [2,3,4] ,we simply record accumulative sum of each row -> [ 9,7,4]
       [3,4,5]                                                   [12,9,5]
When calculate sum within certain range, just use

Σ record[row_i][col1] - record[row_i][col2 + 1]
Time Complexity:
update -> O(N)
sum->O(N)

Space Complexity:
O(N^2)

N is the length or width of matrix. */

int main(void)
{
	vector<vector<int>> matrix = {
	  {3, 0, 1, 4, 2},
	  {5, 6, 3, 2, 1},
	  {1, 2, 0, 1, 5},
	  {4, 1, 0, 1, 7},
	  {1, 0, 3, 0, 5}
	};

	NumMatrix nm(matrix);
	cout << nm.sumRegion(2, 1, 4, 3) << endl; // -> 8
	nm.update(3, 2, 2);
	cout << nm.sumRegion(2, 1, 4, 3) << endl; // -> 10
	
	return 0;
}