#include <bits/stdc++.h>
using namespace std;

 class Solution2 {
    public:
    	 bool exist(vector<vector<char> > &board, string word) {
    		 m=board.size();
    		 n=board[0].size();
            for(int x=0;x<m;x++)
                for(int y=0;y<n;y++)
                {
    				if(isFound(board,word.c_str(),x,y))
    					return true;
                }
            return false;
        }
    private:
    	int m;
    	int n;
        bool isFound(vector<vector<char> > &board, const char* w, int x, int y)
        {
    		if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||*w!=board[x][y])
    			return false;
            if(*(w+1)=='\0')
                return true;
    		char t=board[x][y];
    		board[x][y]='\0';
    		if(isFound(board,w+1,x-1,y)||isFound(board,w+1,x+1,y)||isFound(board,w+1,x,y-1)||isFound(board,w+1,x,y+1))
    			return true; 
    		board[x][y]=t;
            return false;
        }
    };
	
	class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                // traverse the board to find the first char
                if (dfsSearch(board, word, 0, i, j)) return true;
        return false;
    }
private:
    int m;
    int n;
    bool dfsSearch(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || word[k] != board[i][j]) return false;
        if (k == word.length() - 1) return true;  // found the last char

        char cur = board[i][j];
        board[i][j] = '*';  // used
        bool search_next = dfsSearch(board, word, k+1, i-1 ,j) 
                        || dfsSearch(board, word, k+1, i+1, j) 
                        || dfsSearch(board, word, k+1, i, j-1)
                        || dfsSearch(board, word, k+1, i, j+1);
        board[i][j] = cur;  // reset
        return search_next;
    }
};

int main(void)
{
	Solution sol;

	
	vector<vector<char>> board{
  {'A','B','C','E'},
  {'S','F','C','S'},
  {'A','D','E','E'}
	};
	
	string word1 = "ABCCED", word2 = "SEE", word3 = "ABCB"; 
	
	cout << sol.exist(board, word1) << endl;
	cout << sol.exist(board, word2) << endl;
	cout << sol.exist(board, word3) << endl;
	
	return 0;
}