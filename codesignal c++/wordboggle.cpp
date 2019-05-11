// C++ program for Boggle game 
#include <bits/stdc++.h>
#include<iostream> 
#include<cstring> 
using namespace std; 



// Let the given dictionary be following 

int n = 0; 
int M, N = 0;
vector<string> results;
vector<string> dictionary;

// A given function to check if a given string is present in 
// dictionary. The implementation is naive for simplicity. As 
// per the question dictionary is given to us. 
bool isWord(string &str) 
{ 
	// Linearly search all words 
	for (int i=0; i<n; i++) 
		if (str.compare(dictionary[i]) == 0) 
		return true; 
	return false; 
} 

// A recursive function to print all words present on boggle 
void findWordsUtil(vector<vector<char>> boggle, vector<vector<bool>> visited, int i, 
				int j, string &str) 
{ 
	// Mark current cell as visited and append current character 
	// to str 
	visited[i][j] = true; 
	str = str + boggle[i][j]; 

	// If str is present in dictionary, then print it 
	if (isWord(str)) 
	{	
		/* int k = 0; 
		for ( k = 0; k < results.size(); k++)
		{
			if (results[k] == str) break; // duplicate string don't address
		}
		if (k == results.size()) */
			results.push_back(str); 
		// cout << str << endl; 

	}
	// Traverse 8 adjacent cells of boggle[i][j] 
	for (int row=i-1; row<=i+1 && row<M; row++) 
	for (int col=j-1; col<=j+1 && col<N; col++) 
		if (row>=0 && col>=0 && !visited[row][col]) 
		findWordsUtil(boggle,visited, row, col, str); 

	// Erase current character from string and mark visited 
	// of current cell as false 
	str.erase(str.length()-1); 
	visited[i][j] = false; 
} 

// Prints all words present in dictionary. 
void findWords(vector<vector<char>> boggle) 
{ 

	// Mark all characters as not visited 
	// bool visited[M][N] = {{false}}; 
	vector<vector<bool>> visited;
			visited.resize(M, vector<bool>(N,false));  

	// Initialize current string 
	string str = ""; 

	// Consider every character and look for all words 
	// starting with this character 
	for (int i=0; i<M; i++) 
	for (int j=0; j<N; j++) 
			findWordsUtil(boggle, visited, i, j, str); 
} 
std::vector<std::string> wordBoggle(std::vector<std::vector<char>> board, std::vector<std::string> words) {
	
	dictionary = words;
	n = dictionary.size();
	
	M = board.size();
	N = board[0].size();
	
	
	findWords(board);
	
	sort(results.begin(), results.end());
	results.erase(std::unique(results.begin(), results.end()), results.end());
	
	return results; 

}


// Driver program to test above function 
int main() 
{ 
	vector<vector<char>> boggle{{'G','I','Z'}, 
						{'U','E','K'}, 
						{'Q','S','E'}}; 

	vector<string> dict{"GEEKS", "FOR", "QUIZ", "GO"}; 
	
	// n = dictionary.size(); 
	cout << "Following words of dictionary are present\n"; 
	results  = wordBoggle(boggle, dict); 
	
	for (int i = 0; i < results.size(); i++)
		cout << results[i] << endl; 
	
	return 0; 
}
