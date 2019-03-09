// C++ program to find length of the shortest chain 
// transformation from source to target 
#include<bits/stdc++.h> 
using namespace std; 

// To check if strings differ by exactly one character 
bool isadjacent(string& a, string& b) 
{ 
	int count = 0; // to store count of differences 
	int n = a.length(); 
	
	// if (a == b) return false; 
	if (n != b.length()) return false;

	// Iterate through all characters and return false 
	// if there are more than one mismatching characters 
	for (int i = 0; i < n; i++) 
	{ 
		if (a[i] != b[i]) count++; 
		if (count > 1) return false; 
	} 
	return count == 1 ? true : false; 
} 

// A queue item to store word and minimum chain length 
// to reach the word. 
struct QItem 
{ 
	string word; 
	int len; 
}; 

// Returns length of shortest chain to reach 'target' from 'start' 
// using minimum number of adjacent moves. D is dictionary 
int shortestChainLen(string& start, string& target, vector<string> &D ) //set<string> &D) 
{ 
	// Create a queue for BFS and insert 'start' as source vertex 
	queue<QItem> Q; 
	QItem item = {start, 0}; // Chain length for start word is 1 
	Q.push(item); 

	// While queue is not empty 
	while (!Q.empty()) 
	{ 
		// Take the front word 
		QItem curr = Q.front(); 
		Q.pop(); 

		// Go through all words of dictionary 
		// for (vector<string>::iterator it = D.begin(); it != D.end(); it++) 
		for (int i = 0; i < D.size(); i++)
		{ 
			// Process a dictionary word if it is adjacent to current 
			// word (or vertex) of BFS 
			string temp = D[i]; //*it; 
			if (isadjacent(curr.word, temp)) 
			{ 
				// Add the dictionary word to Q 
				item.word = temp; 
				item.len = curr.len + 1; 
				Q.push(item); 

				// Remove from dictionary so that this word is not 
				// processed again. This is like marking visited 
				D.erase(D.begin() + i); 

				// If we reached target 
				if (temp == target) 
				return item.len; 
			} 
		} 
	} 
	return -1; 
} 

int shortestWordEditPath(const string& source, const string& target, const vector<string>& words)
{

	string src = source; 
	string tgt = target; 
	vector<string> wds(words.begin(), words.end()); 
	// set<string> s(words.begin(), words.end());
	
	return shortestChainLen(src, tgt, wds);
}
// Driver program 
int main() 
{ 
	// make dictionary 
	set<string> D; 
	D.insert("poon"); 
	D.insert("plee"); 
	D.insert("same"); 
	D.insert("poie"); 
	D.insert("plie"); 
	D.insert("poin"); 
	D.insert("plea"); 
	string start = "toon"; 
	string target = "plea"; 
	
	std::vector <string> words;
	words.push_back("poon"); 
	words.push_back("plee"); 
	words.push_back("same"); 
	words.push_back("poie"); 
	words.push_back("plie"); 
	words.push_back("poin"); 
	words.push_back("plea");
	/* cout << "Length of shortest chain is: "
		<< shortestChainLen(start, target, D); */ 
	cout << "Length of shortest path  is: "
		<< shortestWordEditPath(start, target, words); 
	
	string source = "abc", target2 = "ab";
	vector<string> words2 = {"abc", "ab"};
	
	cout << "Length of shortest path  is: "
		<< shortestWordEditPath(source, target2, words2); 
		
	return 0; 
}
