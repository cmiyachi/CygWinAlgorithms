#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
	public:
	vector<string> results;
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }
	
	vector<string> autocomplete(string prefix)
	{
		vector<string> result; 
		
		results.clear();
		TrieNode *subtrie = find(prefix);
		string word; word.resize(100);
		int pos = 0;
		getWords(subtrie, word, pos, prefix);
		
		return results; 
	}
	// Function to count number of words 
	void getWords(struct TrieNode *node, string &word, int pos = 0, string prefix="") 
	{ 
		if (node == NULL) return;  
	  
		// Leaf denotes end of a word 
		if (node->is_word) 
		{
			string str = word.substr(0,pos);
			if (prefix != "") str = prefix + str; 
			results.push_back(str);
		}
		  
		for (int i = 0; i < 26; i++)     
		  if (node->next[i] != NULL) 
		  {
			word[pos] = (i+'a');
			getWords(node->next[i], word, pos+1, prefix); 
		  }

		return; 
	} 
private:
    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};

int main(void)
{
	
	Trie* trie = new Trie();
   trie->insert("bad");
   trie->insert("bed");
   trie->insert( "beard");
   trie->insert( "beautiful");
   trie->insert( "beauty");
   trie->insert( "bread");
   string word;
   word.resize(100);
   trie->getWords(trie->root, word, 0);
   
   for (string s : trie->results)
	cout << s << endl;
	
	cout<< "******************" << endl;
	
	trie->autocomplete("beau");
	
	 for (string s : trie->results)
	cout << s << endl;
	
	
	return 0;
}