#include <iostream>
#include <vector>



using namespace std;

class SSolution
{
public:
    bool solveSudoku(vector<vector<char>>& board)
    {
        //Looping through thre rows and the columns
        vector<pair<int,int>> dotpos;
        for (size_t r = 0; r < 9; ++r)
        {
            for (size_t c = 0; c < 9; ++c)
            {
                //Pushing the position where there is an empty sudoku slot
                if (board[r][c] == '.')
                {
                    dotpos.push_back(make_pair(r, c));
                }
            }
        }
        //Call Depth First Search after all positions are collected
        return dfs(board, dotpos, 0);
    }
    


    bool dfs(vector<vector<char>>& board, vector<pair<int,int>>& dotpos, size_t index)
    {
        // Base Case -- breaks when there are no more empty positions
        if (index == dotpos.size())
        {
            return true;
        }
        
        //gets the row and the column 
        size_t r = dotpos[index].first;
        size_t c = dotpos[index].second;
        
        
        for (board[r][c] = '1'; board[r][c] <= '9'; board[r][c] += 1)
        {
            bool valid = true;
            for (size_t i = 0; valid && i < 9; ++i)
            {
                if (i != r && board[i][c] == board[r][c]
                    || i != c && board[r][i] == board[r][c]
                    || i != r % 3 * 3 + c % 3 && board[r / 3 * 3 + i / 3][c / 3 * 3 + i % 3] == board[r][c])
                {
                    valid = false;
                    break;
                }
            }
            if (valid && dfs(board, dotpos, index + 1))
            {
                return true;
            }
        }
        
        return false;
    }
};

bool sudokuSolve( const vector<vector<char>>& board ) 
{
	vector<vector<char>> board2 = board;
	
	SSolution solution;
	
	return solution.solveSudoku(board2);
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
  cout << "FINAL " << result << "\n"; 
  
  
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

