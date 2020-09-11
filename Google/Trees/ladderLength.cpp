#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		map<string,vector<string>> allComboDict; 
        int L = beginWord.length();
		for (string word : wordList)
		{
			for (int i = 0; i < L; i++)
			{
				// Key is the generic word
				// Value is a list of words which have the same intermediate generic word.
				string newWord = word.substr(0, i) + '*' + word.substr(i + 1, L);
				vector<string> transformations;
				if (allComboDict.find(newWord) == allComboDict.end())
				{
					allComboDict[newWord] = transformations; 
				}
				transformations.push_back(word);
				allComboDict[newWord] = transformations;
			} // for i
		}// for word
		
		// Queue for BFS
		queue<pair<string,int>> Q; 
		Q.push(make_pair(beginWord,1)); 
		
		// Visited to make sure we don't repeat processing same word.
		map<string, bool> visited; 
		visited[beginWord] = true;

		while (!Q.empty()) {
		  pair<string, int> node = Q.front();Q.pop(); 
		  string word = node.first;
		  int level = node.second;
		  for (int i = 0; i < L; i++) {

			// Intermediate words for current word
			string newWord = word.substr(0, i) + '*' + word.substr(i + 1, L);

			// Next states are all the words which share the same intermediate state.
			for (string adjacentWord : allComboDict[newWord]) {
			  // If at any point if we find what we are looking for
			  // i.e. the end word - we can return with the answer.
			  if (adjacentWord == endWord) {
				return level + 1;
			  }
			  // Otherwise, add it to the BFS Queue. Also mark it visited
			  if ((visited.find(adjacentWord)) == visited.end()) {
				visited[adjacentWord] = true;
				Q.push(make_pair(adjacentWord, level + 1));
			  } // if
			} // for adj
		  } // for int i
		} // while
	}
};

class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if( find( wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        unordered_set<string> dict( wordList.begin(), wordList.end());
        queue< pair< string, int> > q;
        q.push(make_pair(beginWord, 1));
        dict.erase(beginWord);

        while( !q.empty() && !dict.empty()) {

            string str = q.front().first;
            int ladder = q.front().second;
            q.pop();

            for( int i=0; i<str.size(); ++i) {
                string tmpstr = str;
                for(int j=0; j<26; ++j) {
                    tmpstr[i] = 'a'+j;
                    if( dict.find(tmpstr) != dict.end()) {
                        if( tmpstr == endWord) return ladder+1;
                        q.push( make_pair(tmpstr, ladder+1));
                        dict.erase( tmpstr);
                    }
                }
            }
        }
        return 0;
    }
};

int main(void)
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList{"hot","dot","dog","lot","log","cog"};
	
	Solution2 sol;
	
	cout << sol.ladderLength(beginWord, endWord, wordList); 

	return 0;
}
/*
import javafx.util.Pair;

class Solution {
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {

    // Since all words are of same length.
    int L = beginWord.length();

    // Dictionary to hold combination of words that can be formed,
    // from any given word. By changing one letter at a time.
    HashMap<String, ArrayList<String>> allComboDict = new HashMap<String, ArrayList<String>>();

    wordList.forEach(
        word -> {
          for (int i = 0; i < L; i++) {
            // Key is the generic word
            // Value is a list of words which have the same intermediate generic word.
            String newWord = word.substr(0, i) + '*' + word.substr(i + 1, L);
            ArrayList<String> transformations =
                allComboDict.getOrDefault(newWord, new ArrayList<String>());
            transformations.add(word);
            allComboDict.put(newWord, transformations);
          }
        });

    // Queue for BFS
    Queue<Pair<String, Integer>> Q = new LinkedList<Pair<String, Integer>>();
    Q.add(new Pair(beginWord, 1));

    // Visited to make sure we don't repeat processing same word.
    HashMap<String, Boolean> visited = new HashMap<String, Boolean>();
    visited.put(beginWord, true);

    while (!Q.isEmpty()) {
      Pair<String, Integer> node = Q.remove();
      String word = node.getKey();
      int level = node.getValue();
      for (int i = 0; i < L; i++) {

        // Intermediate words for current word
        String newWord = word.substr(0, i) + '*' + word.substr(i + 1, L);

        // Next states are all the words which share the same intermediate state.
        for (String adjacentWord : allComboDict.getOrDefault(newWord, new ArrayList<String>())) {
          // If at any point if we find what we are looking for
          // i.e. the end word - we can return with the answer.
          if (adjacentWord.equals(endWord)) {
            return level + 1;
          }
          // Otherwise, add it to the BFS Queue. Also mark it visited
          if (!visited.containsKey(adjacentWord)) {
            visited.put(adjacentWord, true);
            Q.add(new Pair(adjacentWord, level + 1));
          }
        }
      }
    }

    return 0;
  }
}

*/