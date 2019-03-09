#include <iostream>
#include <vector>

using namespace std;

bool solveSudoku(int puzzle[][9], int row, int col);

int N = 9; 

bool sudokuSolve( const vector<vector<char>>& board ) 
{
	int puzzle[9][9];
	
	// cout << board[0][0] << "\n";
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == '.') 
			{
				
				puzzle[i][j] = 0;
			}
			else {
				puzzle[i][j] = board[i][j] - '0'; 
				
				
			}
			// cout << puzzle[i][j];
		}
		//cout << "\n";
	}
	return solveSudoku(puzzle, 0, 0); 
}

bool isAvailable(int puzzle[][9], int row, int col, int num)
{
    int sqCol = col % 3 * 3;
    int sqRow = row % 3 * 3;
    for (int i = 0; i<9; ++i)
    {
        if (puzzle[row][i] == num) return false;
        if (puzzle[i][col] == num) return false;

        // You need to add this test.
        if (puzzle[sqRow + (i % 3)][sqCol + (i / 3)] == num) return false;
    }
    return true;
}
bool solveSudoku(int puzzle[][9], int row, int col)
{
    if (col == 9) {
        col = 0;
        row++;
    }
    if (row == 9) {
        return true;
    }

    if (puzzle[row][col] != 0) {
        return solveSudoku(puzzle, row, col + 1);
    }

    for (int i = 1; i <= 9; ++i)
    {
        if (isAvailable(puzzle, row, col, i))
        {
            puzzle[row][col] = i;
            if (solveSudoku(puzzle, row, col + 1))
                return true;
        }
    }
    puzzle[row][col] = 0;
    return false;
}

int main() {
 /* vector<vector<char>> board =
	{{'.','.','.','7','.','.','3','.','1'},
	{'3','.','.','9','.','.','.','.','.'},
	{'.','4','.','3','1','.','2','.','.'},
	{'.','6','.','4','.','.','5','.','.'},
	{'.','.','.','.','.','.','.','.','.'},
	{'.','.','1','.','.','8','.','4','.'},
	{'.','.','6','.','2','1','.','5','.'},
	{'.','.','.','.','.','9','.','.','8'},
	{'8','.','5','.','.','4','.','.','.'}};

    vector<vector<char>> board2 = 
  {{'.', '8', '7', '6', '5', '4', '3', '2', '1'}, 
   {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'3', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'5', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'6', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'7', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'8', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'9', '.', '.', '.', '.', '.', '.', '.', '.'}}; */
 //   bool result = sudokuSolve(board);
  //  cout << "FINAL " << result; 
    
  return 0;
}