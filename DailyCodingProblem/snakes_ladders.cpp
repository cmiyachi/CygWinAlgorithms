#include <bits/stdc++.h> 
using namespace std; 
class Solution2 {
    
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q; //BFS
        unordered_map<int, int> moves;
        moves[1]=0; //no moves when we are in square 1
        q.push(1);
        while (!q.empty())
        {
            int curr_sq=q.front(); // current square (val from 1..n*n)
            q.pop();
            
            // try all the next 6 pos but not over n*n
            for(int i=1; i <= 6;++i)
            {
                int next_sq=curr_sq+i; // next pos when we move from sq
                
                 if (next_sq > n*n)
                    break;
                
                // Determine the next sq val, on snake or ladder
                // Compute row and col in the board
                int row = (next_sq-1)/n; 
                // the colum depends on if row is even or odd
                int col = (row % 2 ==0) ? (next_sq-1) % n : n-1 - (next_sq-1) % n;
                
                // the next sq can be on the snake (-1) or ladder
                if(board[n-1-row][col] != -1)
                    next_sq= board[n-1-row][col];
                    
                // update the moves for that square               
                if (moves.count(next_sq)==0)
                {
                    moves[next_sq]=moves[curr_sq] + 1; // moves to sq plus 1
                    if(next_sq==n*n) return moves[next_sq]; // early exit
                    q.push(next_sq);
                }
            }
             
        }
        
        return -1;
    }
};
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q;
        map<int,int> freq;
        
        q.push(1);
        int n = board.size();
        int level = 0;
        int square = 1;
        int j;
        bool flag = false; // flatten the board into array
        for(int i=n-1;i>=0;i--) {
            if(!flag) {
                // left to right
                for(j=0;j<n;j++) {
                    freq[square] = board[i][j];
                    square++;
                }
            } else {
                // right to left
                for(j=n-1;j>=0;j--) {
                    freq[square] = board[i][j];
                    square++;
                }
            }
            flag = !flag;
        }
		
        vector<bool> visited(n*n+1, false);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int a = q.front();
                if(a == n*n) return level;
                q.pop();
                bool found = false;
                for(int i=1;i<=6;i++) {
                    int newSquare = a+i;
                    if(newSquare <= n*n) {
                        int val = newSquare;
                        if(freq[newSquare] != -1) {
                            val = freq[newSquare];
                        } else {
                            val = newSquare;
                        }
                        if(!visited[val]) {
                             visited[val] = true;
                             q.push(val);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

class Solution3 {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
          int N = board.size();
        map<int, int> dist;
        dist[1] = 0; 
        
        queue<int> q;
        q.push(1);
        
        while(!q.empty())
        {
            int s = q.front();  q.pop();
            if (s == N*N) return dist[s];

            for (int s2 = s+1; s2 <= min(s+6, N*N); ++s2) {
                int rc = get(s2, N);
                int r = rc / N, c = rc % N;
                int s2Final = board[r][c] == -1 ? s2 : board[r][c];
                if (dist.find(s2Final) == dist.end())
                 {
                    dist[s2Final] =  dist[s]+1;
                    q.push(s2Final);
                }
            }
        }
        return -1;
    }

     int get(int s, int N) {
        // Given a square num s, return board coordinates (r, c) as r*N + c
        int quot = (s-1) / N;
        int rem = (s-1) % N;
        int row = N - 1 - quot;
        int col = row % 2 != N % 2 ? rem : N - 1 - rem;
        return row * N + col;
    }
};

int main(void)
{
	vector<vector<int>> board = {
{-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1},
{-1,35,-1,-1,13,-1},
{-1,-1,-1,-1,-1,-1},
{-1,15,-1,-1,-1,-1}};

vector<vector<int>> board2 = {
{-1,-1,-1,79,-1,51,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,18,-1,91},
{100,-1,-1,-1,-1,86,-1,-1,-1,-1},
{-1,22,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,77,40,-1,-1,-1,-1,29,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,84,-1,-1},
{-1,-1,-1,13,-1,-1,-1,-1,-1,-1},
{-1,-1,21,-1,-1,-1,-1,30,-1,-1}}; 
	Solution sol;
	
	cout << sol.snakesAndLadders(board2);
	
	return 0;
}
 