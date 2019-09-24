#include <bits/stdc++.h>
using namespace std; 

// solution : use hash map
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> M    ;
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i ++) {
            M[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i ++) {
            reverse(words[i].begin(), words[i].end());
            int len = words[i].size();
            for (int j = 0; j <= len; j ++) {
                string left = words[i].substr(0, j), right = words[i].substr(j);
                if (M.count(left) && isPalindrom(right) && M[left] != i) {
                    res.push_back({M[left], i});
                }
                if (M.count(right) && isPalindrom(left) && M[right] != i && j > 0) {  // j > 0 avoid duplicates
                    res.push_back({i, M[right]});
                }
            }
        }
        return res;
    }
    
    bool isPalindrom(string & str) {
        for (int i = 0, j = str.length() - 1; i < j; i ++, j --) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
};


class Solution2 {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
		map<string, int> word_map; 
		vector<vector<int>> results; 
		
		
		for (int i = 0; i < words.size(); i++)
			for (int j = 0; j < words.size(); j++)
			{
				if (i == j) continue;
				string new_word = words[i] + words[j];
				if (isPalidrome(new_word))
				{
					vector<int> indices{i,j};
					results.push_back(indices); 
				}
			}
		return results; 
    }
	
	bool isPalidrome(string word)
	{
		int i = 0;
         int j = word.size() - 1; 

         while(i < j) {
             if(word[i++] != word[j--]) return false;
         }

         return true;
		 /*
		string rev_word = word;
		reverse(rev_word.begin(), rev_word.end());
		if (rev_word == word)
			return true; 
		else
			return false; */
	}
	
};

int main(void)
{
	vector<string> words{"abcd","dcba","lls","s","sssll"};
	Solution sol;
	
	vector<vector<int>> results = sol.palindromePairs(words); 
	
	for (int i = 0; i < results.size(); i++)
	{
		cout <<  "[";
		for (int j = 0; j < results[i].size(); j++)
			cout << results[i][j] << ","; 
		cout << "]" << endl;
	}
	return 0; 
}