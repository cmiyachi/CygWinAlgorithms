#include <unordered_map>
using namespace std;

// Do not edit the class below except for the
// populateSuffixTrieFrom and contains methods.
// Feel free to add new properties and methods
// to the class.
class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
  TrieNode *root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieFrom(string str) {
    // Write your code here.
		for (int i = 0; i < str.length(); i++)
			this->insertSubStringStartingAt(i, str);
  }

	void insertSubStringStartingAt(int i, string str)
	{
		TrieNode *node = this->root; 
		for (int j = i; j < str.length(); j++)
		{
			char letter = str[j];
			if (node->children.find(letter) == node->children.end())
			{
				TrieNode *newNode = new TrieNode();
				node->children.insert({letter, newNode});
			}
			node = node->children[letter]; 
		}
		node->children.insert({this->endSymbol, NULL}); 
	}
	
  bool contains(string str) {
    TrieNode *node = this->root; 
		for (char letter : str)
		{
			if (node->children.find(letter) == node->children.end())
				return false; 
			node = node->children[letter]; 
		}
		return node->children.find(this->endSymbol) != node->children.end(); 
  }
  bool containsPrefix(string str) {
    TrieNode *node = this->root; 
		for (char letter : str)
		{
			if (node->children.find(letter) == node->children.end())
				return false; 
			node = node->children[letter]; 
		}
		return true; 
  }
  
  vector<string> autopopulate(string prefix)
  {
	  int prefix_len = prefix.length();
	  
  }
};
