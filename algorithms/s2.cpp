#include <iostream>
#include <vector>
#include <cmath>
#include <stddef.h>

using namespace std;

vector<char>  getCandidates( vector<vector<char>>& board, int row, int col);
bool sudokuSolveWork(  vector<vector<char>>& board ) ;

bool sudokuSolve(  const vector<vector<char>>& board ) 
{
	// copy vector into a non-const vector
	vector<vector<char>> working_board = board;
	
	return sudokuSolveWork(working_board);
}

bool sudokuSolveWork(  vector<vector<char>>& board ) 
{
	// # For each empty cell, consider 'newCandidates', the
    // # set of possible candidate values that can
    // # be placed into that cell.
   
    int row = -1 ;
    int col = -1;
    vector<char> candidates; 
    
   for (int r = 0; r < 9; r++)
   {
        for (int c = 0; c < 9; c++)
		{
            if (board[r][c] == '.'){
                vector<char> newCandidates = getCandidates(board, r, c);
                // # Then, we want to keep the smallest
                // # sized 'newCandidates', plus remember the
                // # position where it was found
                if (candidates.empty() || (newCandidates.size() < candidates.size()))
				{
                    candidates = newCandidates;
                    row = r ;
                    col = c;
				} // if cand..
			} // if board
		} // for c
   } // for r
 
    // # If we have not found any empty cell, then
    // # the whole board is filled already
    if (candidates.size() == 0)
        return true;
 
    // # For each possible value that can be placed
    // # in position (row, col), let's
    // # place that value and then recursively query
    // # whether the board can be solved.  If it can,
    // # we are done. 
    // for val in candidates:
	for (int i = 0; i < candidates.size(); i++)
	{
        board[row][col] = candidates[i];
        if (sudokuSolveWork(board)) return true;
          
        // # The tried value val didn't work so restore  
        // # the (row, col) cell back to '.'
        board[row][col] = '.';
	}
 
    // # Otherwise, there is no value that can be placed
    // # into position (row, col) to make the
    // # board solved
    return false;
	
}

vector<char>  getCandidates( vector<vector<char>>& board, int row, int col)
{
	// # A helper function that returns a set of all valid
// # candidates for a given cell in the board

	vector<char> candidates;

// function getCandidates(board, row, col):
    // # For some empty cell board[row][col], what possible
    // # characters can be placed into this cell
    // # that aren't already placed in the same row,
    // # column, and sub-board?
 
    // # At the beginning, we don't have any candidates
    // candidates = []
    
    // # For each character add it to the candidate list
    // # only if there's no collision, i.e. that character 
    // # doesn't already exist in the same row, column 
    // # and sub-board. Notice the top-left corner of (row, col)'s 
    // # sub-board is (row - row%3, col - col%3).
	char Num[] = { '0','1', '2', '3', '4', '5', '6', '7','8', '9' } ;
	 for (int int_chr = 1; int_chr <=9; int_chr++)
	 {		 
		char chr_cand = Num[int_chr];
		bool collision = false; 
		for (int i = 0; i < 9; i++)
		{
			if (board[row][i] == chr_cand ||
				board[i][col] == chr_cand ||
				board[(row-row%3) + floor(i/3)][(col - col%3)+ i %3] == chr_cand) 
				{
					collision = true;
					break;
				}
		}
		
		if (!collision) 
			candidates.push_back(chr_cand);
			
	 }
         
    return candidates;
}

int main() {
 vector<vector<char>> board =
	{{'.','.','.','7','.','.','3','.','1'},
	{'3','.','.','9','.','.','.','.','.'},
	{'.','4','.','3','1','.','2','.','.'},
	{'.','6','.','4','.','.','5','.','.'},
	{'.','.','.','.','.','.','.','.','.'},
	{'.','.','1','.','.','8','.','4','.'},
	{'.','.','6','.','2','1','.','5','.'},
	{'.','.','.','.','.','9','.','.','8'},
	{'8','.','5','.','.','4','.','.','.'}};

   /*  vector<vector<char>> board2 = 
  {{'.', '8', '7', '6', '5', '4', '3', '2', '1'}, 
   {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'3', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'5', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'6', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'7', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'8', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'9', '.', '.', '.', '.', '.', '.', '.', '.'}}; */
  bool result = sudokuSolve(board);
  cout << "FINAL " << result; 
  
  
vector<vector<char>> board_false = 
{{'.','8','9','.','4','.','6','.','5'},
{'.','7','.','.','.','8','.','4','1'},
{'5','6','.','9','.','.','.','.','8'},
{'.','.','.','7','.','5','.','9','.'},
{'.','9','.','4','.','1','.','5','.'},
{'.','3','.','9','.','6','.','1','.'},
{'8','.','.','.','.','.','.','.','7'},
{'.','2','.','8','.','.','.','6','.'},
{'.','.','6','.','7','.','.','8','.'}};

   result = sudokuSolve(board_false);
  cout << "FINAL " << result; 
    
  return 0;
}


// function sudokuSolve(board):
    