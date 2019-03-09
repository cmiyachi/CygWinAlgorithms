#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool findUnassignedLocation(const vector<vector<char>>& board, int &row, int &col) ;
bool isSafe(const vector<vector<char>>& board, int row, int col, char num) ; 
bool sudokuSolve2( vector<vector<char>>& board );

// size of board
int N = 9;
char Num[] = { '0','1', '2', '3', '4', '5', '6', '7','8', '9' } ;

bool sudokuSolve( const vector<vector<char>>& board ) 
{
	vector<vector<char>> board2 = board;
	
	return sudokuSolve2(board2);
}
	
bool sudokuSolve2( vector<vector<char>>& board ) 
{
    
    
    int row = 0;
    int col = 0; 
  // If there is no unassigned location, we are done 
    if (!findUnassignedLocation(board, row, col)) 
       return true; // success! 
   
   cout << "New call row, col " << row << " " << col << "\n"; 
   
   // consider digits 1 to 9 
    for (int num = 1; num <= 9; num++) 
    { 
        char char_num = Num[num];
      // cout << char_num;
       
        if (isSafe(board, row, col, char_num)) 
        { 
           cout << "trying " << char_num << "\n"; 
            // make tentative assignment 
            board[row][col] = char_num; 
  
            // return, if success, yay! 
            if (sudokuSolve2(board)) 
                return true; 
  
            // failure, unmake & try again 
            board[row][col] = '.'; 
        }  
    } 
    return false;
}

/* Searches the grid to find an entry that is still unassigned. If 
   found, the reference parameters row, col will be set the location 
   that is unassigned, and true is returned. If no unassigned entries 
   remain, false is returned. */
bool findUnassignedLocation(const vector<vector<char>>& board, int &row, int &col) 
{ 
   
    for (int row = 0; row < N; row++) 
        for (int col = 0; col < N; col++) 
            if (board[row][col] == '.') 
            { 
                cout << row << " find  " << col << "\n"; 
                return true; 
            }
                
    return false; 
} 

bool usedInRow(const vector<vector<char>>& board, int row, char num) 
{ 
    for (int col = 0; col < N; col++) 
        if (board[row][col] == num) 
        {
            cout << "used in row " << num << "\n"; 
            return true; 
        }
    return false; 
} 

bool usedInCol(const vector<vector<char>>& board, int col, char num) 
{ 
    for (int row = 0; row < N; row++) 
        if (board[row][col] == num) {
           cout << "used in col " << num << "\n";; 
             return true; 
        }
           
    return false; 
} 
  

bool usedInBox(const vector<vector<char>>& board, int boxStartRow, int boxStartCol, char num) 
{ 
    for (int row = 0; row < 3; row++) 
        for (int col = 0; col < 3; col++) 
            if (board[row+boxStartRow][col+boxStartCol] == num) 
                return true; 
    return false; 
} 
  

bool isSafe(const vector<vector<char>>& board, int row, int col, char num) 
{ 

   cout << "safe " << row << " " << col << " " << num << "\n";; 
    return !usedInRow(board, row, num) && 
           !usedInCol(board, col, num) && 
           !usedInBox(board, row - row%3 , col - col%3, num)&& 
            board[row][col]=='.'; 
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

    vector<vector<char>> board2 = 
  {{'.', '8', '7', '6', '5', '4', '3', '2', '1'}, 
   {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'3', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'5', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'6', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'7', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'8', '.', '.', '.', '.', '.', '.', '.', '.'}, 
   {'9', '.', '.', '.', '.', '.', '.', '.', '.'}};
    bool result = sudokuSolve(board);
    cout << "FINAL " << result; 
    
  return 0;
}