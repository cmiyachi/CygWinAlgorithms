#include <bits/stdc++.h> 
using namespace std; 

class Crossword
{
	public:
	bool hasValidWordLen(vector<vector<int>> grid)
	{
		for (int i = 0; i < grid.size(); i++)
		{
			int word_len = 0;
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == 0)
					word_len++;
				else	
				{
					if ((0 < word_len) && (word_len < 3))
						return false;
					word_len = 0; 
				}
			}
			if ((0 < word_len) && (word_len < 3))
				cout << "i " << i << endl;
			//	return false;
		}
		
		return true;
	} // this will work for both across and down words as we will transpose the grid
	// O(n)
	bool isRotationallySymmetric(vector<vector<int>> grid)
	{
		vector<vector<int>> final;
		final = transpose(grid);
		final = reverseRows(final);
		final = transpose(final);
		final = reverseRows(final);
		final = transpose(final);
		
		if (final == grid) return true;
		else return false; 
		
	}
	
	void printGrid(vector<vector<int>> matrix)
	{
		int n = matrix.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << matrix[i][j] << ", ";
			
			cout << endl;
		}
		cout << "****************" << endl;
		return;
	}
			
	
	vector<vector<int>> transpose(vector<vector<int>> A) 
	{ 
		int i, j; 
		int N = A.size();
		vector<vector<int>> B(N,vector<int>(N,0)); 
		for (i = 0; i < N; i++) 
			for (j = 0; j < N; j++) 
				B[i][j] = A[j][i]; 
				
		printGrid(B);
		return B; 
	} 
	vector<vector<int>> reverseRows(vector<vector<int>> arr) 
	{ 	
		int N = arr.size();
		// Traverse each row of arr[][] 
		for (int i = 0; i < N; i++) { 
	  
			// Initialise start and end index 
			int start = 0; 
			int end = N - 1; 
	  
			// Till start < end, swap the element 
			// at start and end index 
			while (start < end) { 
	  
				// Swap the element 
				swap(arr[i][start], 
					 arr[i][end]); 
	  
				// Increment start and decrement 
				// end for next pair of swapping 
				start++; 
				end--; 
			} 
		}
		
		printGrid(arr);
		return arr; 
	}	
	
	bool isValid(vector<vector<int>> grid)
	{
		return hasValidWordLen(grid) && isRotationallySymmetric(grid); 
	}
};

int main(void)
{
	Crossword cw; 
	vector<vector<int>> grid{{0,0,0},
							 {1,1,0},
							 {1,1,0}};
	
	cout << cw.isValid(grid);
}
	

	
			