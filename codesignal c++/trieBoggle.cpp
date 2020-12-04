// C++ program for Boggle game 
#include<bits/stdc++.h> 
using namespace std; 

// Converts key current character into index 
// use only 'A' through 'Z' 
#define char_int(c) ((int)c - (int)'A') 

// Alphabet size 
#define SIZE (26) 


vector<string> results; 
int n, M, N; 

// trie Node 
struct TrieNode 
{ 
	TrieNode *Child[SIZE]; 

	// isLeaf is true if the node represents 
	// end of a word 
	bool leaf; 
}; 

// Returns new trie node (initialized to NULLs) 
TrieNode *getNode() 
{ 
	TrieNode * newNode = new TrieNode; 
	newNode->leaf = false; 
	for (int i =0 ; i< SIZE ; i++) 
		newNode->Child[i] = NULL; 
	return newNode; 
} 

// If not present, inserts a key into the trie 
// If the key is a prefix of trie node, just 
// marks leaf node 
void insert(TrieNode *root, string Key) 
{ 
	int n = Key.length(); 
	TrieNode * pChild = root; 

	for (int i=0; i<n; i++) 
	{ 
		int index = char_int(Key[i]); 

		if (pChild->Child[index] == NULL) 
			pChild->Child[index] = getNode(); 

		pChild = pChild->Child[index]; 
	} 

	// make last node as leaf node 
	pChild->leaf = true; 
} 

// function to check that current location 
// (i and j) is in matrix range 
bool isSafe(int i, int j, vector<vector<bool>> visited) 
{ 
	return (i >=0 && i < M && j >=0 && 
			j < N && !visited[i][j]); 
} 

// A recursive function to print all words present on boggle 
void searchWord(TrieNode *root, vector<vector<char>> boggle, int i, 
				int j, vector<vector<bool>> visited, string str) 
{ 
	// if we found word in trie / dictionary 
	if (root->leaf == true) 
	{
		cout << str << endl ; 
		results.push_back(str);
	}

	// If both I and j in range and we visited 
	// that element of matrix first time 
	if (isSafe(i, j, visited)) 
	{ 
		// make it visited 
		visited[i][j] = true; 

		// traverse all childs of current root 
		for (int K =0; K < SIZE; K++) 
		{ 
			if (root->Child[K] != NULL) 
			{ 
				// current character 
				char ch = (char)K + (char)'A' ; 

				// Recursively search reaming character of word 
				// in trie for all 8 adjacent cells of boggle[i][j] 
				if (isSafe(i+1,j+1,visited) && boggle[i+1][j+1] == ch) 
					searchWord(root->Child[K],boggle,i+1,j+1,visited,str+ch); 
				if (isSafe(i, j+1,visited) && boggle[i][j+1] == ch) 
					searchWord(root->Child[K],boggle,i, j+1,visited,str+ch); 
				if (isSafe(i-1,j+1,visited) && boggle[i-1][j+1] == ch) 
					searchWord(root->Child[K],boggle,i-1, j+1,visited,str+ch); 
				if (isSafe(i+1,j, visited) && boggle[i+1][j] == ch) 
					searchWord(root->Child[K],boggle,i+1, j,visited,str+ch); 
				if (isSafe(i+1,j-1,visited) && boggle[i+1][j-1] == ch) 
					searchWord(root->Child[K],boggle,i+1, j-1,visited,str+ch); 
				if (isSafe(i, j-1,visited)&& boggle[i][j-1] == ch) 
					searchWord(root->Child[K],boggle,i,j-1,visited,str+ch); 
				if (isSafe(i-1,j-1,visited) && boggle[i-1][j-1] == ch) 
					searchWord(root->Child[K],boggle,i-1, j-1,visited,str+ch); 
				if (isSafe(i-1, j,visited) && boggle[i-1][j] == ch) 
					searchWord(root->Child[K],boggle,i-1, j, visited,str+ch); 
			} 
		} 

		// make current element unvisited 
		visited[i][j] = false; 
	} 
} 

// Prints all words present in dictionary. 
void findWords(vector<vector<char>> boggle, TrieNode *root) 
{ 
	// Mark all characters as not visited 
	vector<vector<bool>> visited;
			visited.resize(M, vector<bool>(N,false));
	// bool visited[M][N]; 
	// memset(visited,false,sizeof(visited)); 

	TrieNode *pChild = root ; 

	string str = ""; 

	// traverse all matrix elements 
	for (int i = 0 ; i < M; i++) 
	{ 
		for (int j = 0 ; j < N ; j++) 
		{ 
			// we start searching for word in dictionary 
			// if we found a character which is child 
			// of Trie root 
			if (pChild->Child[char_int(boggle[i][j])] ) 
			{ 
				str = str+boggle[i][j]; 
				searchWord(pChild->Child[char_int(boggle[i][j])], 
						boggle, i, j, visited, str); 
				str = ""; 
			} 
		} 
	} 
} 

std::vector<std::string> wordBoggle(std::vector<std::vector<char>> board, std::vector<std::string> words) {
	
	
	n = words.size();
	
	M = board.size();
	N = board[0].size();
	// root Node of trie 
	TrieNode *root = getNode(); 

	// insert all words of dictionary into trie  
	for (int i=0; i<n; i++) 
		insert(root, words[i]); 
	
	findWords(board, root);
	
	// sort(results.begin(), results.end());
	// results.erase(std::unique(results.begin(), results.end()), results.end());
	results.erase(std::unique(results.begin(), results.end()), results.end());
	sort(results.begin(), results.end());
	return results; 

}

//Driver program to test above function 
int main() 
{ 
	// Let the given dictionary be following 
	vector<string> dict{"GEEKS", "FOR", "QUIZ", "GEE"}; 

	

	vector<vector<char>> boggle{{'G','I','Z'}, 
		{'U','E','K'}, 
		{'Q','S','E'} 
	}; 

	//findWords(boggle, root); 
	
	vector<string> final = wordBoggle(boggle, dict); 
	
	vector<string> dict2{"this",
				  "is",
				  "not",
				  "a",
				  "simple",
				  "boggle",
				  "board",
				  "test",
				  "REPEATED",
				  "NOTRE-PEATED"}; 

	

	vector<vector<char>> boggle2{{'t', 'h', 'i', 's', 'i', 's', 'a'},
				  {'s', 'i', 'm', 'p', 'l', 'e', 'x'},
				  {'b', 'x', 'x', 'x', 'x', 'e', 'b'},
				  {'x', 'o', 'g', 'g', 'l', 'x', 'o'},
				  {'x', 'x', 'x', 'D', 'T', 'r', 'a'},
				  {'R', 'E', 'P', 'E', 'A', 'd', 'x'},
				  {'x', 'x', 'x', 'x', 'x', 'x', 'x'},
				  {'N', 'O', 'T', 'R', 'E', '-', 'P'},
				  {'x', 'x', 'D', 'E', 'T', 'A', 'E'}
				}; 

	vector<string> final2 = wordBoggle(boggle2, dict2); 
	return 0; 
} 
