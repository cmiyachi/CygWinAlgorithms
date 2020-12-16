#include <bits/stdc++.h> 
using namespace std; 

/*
This problem is a classical one and it's important to know the solution to feel classy.

The first idea is to use brute-force that means to generate all possible ways to put N queens on the board, and then check them to keep only the combinations with no queen under attack. That means \mathcal{O}(N^N)O(N 
N
 ) time complexity and hence we're forced to think further how to optimize.

There are two programming conceptions here which could help.

The first one is called constrained programming.

That basically means to put restrictions after each queen placement. One puts a queen on the board and that immediately excludes one column, one row and two diagonals for the further queens placement. That propagates constraints and helps to reduce the number of combinations to consider.

The second one called backtracking.

Let's imagine that one puts several queens on the board so that they don't attack each other. But the combination chosen is not the optimal one and there is no place for the next queen. What to do? To backtrack. That means to come back, to change the position of the previously placed queen and try to proceed again. If that would not work either, backtrack again.
*/

class Solution {
public:
    int count = 0;
    int totalNQueens(int n) {
        if(n == 1){
            return n;
        }
        if(n > 1 && n < 4)
            return 0;
        
        int board[9][9]= {0};
        //memset(board,0,n);
        solveNQueensUtil(board,0,n);
        return count;
    }
    
    bool solveNQueensUtil(int board[][9],int col,int n){
        if(col == n){
            count++;
            return true;
        }
        int col_true= false;
        
        for(int i =0;i<n;i++){
            if(isSafe(i,col,board,n)){
                board[i][col] = 1;
                col_true = solveNQueensUtil(board,col+1,n) || col_true;
                //backtrack
                board[i][col] = 0;
            }
        }
        return col_true;
    }
	bool isSafe(int row, int col, int board[][9],int n){
	//check rows on left side
        for(int i = 0;i<col;i++){
            if(board[row][i])
                return false;
        }
        // upper diagonal on left
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j])
                return false;
        }
        //lower diagonal on left because on need to check on right because we haven't seen it yet
        for(int i = row, j = col; i < n && j >= 0; i++, j--){
            if(board[i][j])
                return false;
        }
        return true;
    }    
};

int main(void)
{
	Solution sol;
	
	cout << sol.totalNQueens(4);
	
	
	return 0;
}
