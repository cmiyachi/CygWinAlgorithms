struct Node {
   bool isEnd;
   unordered_map<char, Node*> children;   
   Node() : isEnd() {}
};

class Trie {
   Node* root;
public:
   Trie() {
       root = new Node();
   }
   
   void add(string& s) {
       Node* node = root;
       int idx = 0;
       while (idx < s.size()) {
           if (node->children.find(s[idx]) == node->children.end()) {
               Node* newNode = new Node();
               node->children[s[idx]] = newNode;
           }
           node = node->children[s[idx]];
           idx++;
       }
       node->isEnd = true;
   }
   
   int search(int idx, string& s) {
       Node* node = root;
       int ret = -1;
       while (idx < s.size()) {
           if (node->children.find(s[idx]) == node->children.end()) {
               return ret;
           }
           node = node->children[s[idx]];
           if (node->isEnd) {
               ret = idx;
           }            
           idx++;
       }
       return ret;
   }
};

class Solution {
public:
   string addBoldTag(string s, vector<string>& dict) {
       if (s.size() == 0) {
           return s;
       }
       vector<bool> bold(s.size());
       //Build a trie
       Trie trie;
       for (auto word : dict) {
           trie.add(word);
       }
       //Search in s, mark bold array
       for (int i=0; i<s.size(); i++) {
           int idx = trie.search(i, s);
           for (int j=i; j<=idx; j++) {
               bold[j] = true;
           }
       }
       //Tag using boolean array
       bool state = true;
       string ret;
       for (int i=0; i<s.size(); i++) {
           if (state && bold[i]) {
               ret += "<b>";
               state = false;
           } else if (!state && !bold[i]) {
               ret += "</b>";
               state = true;
           }
           ret.push_back(s[i]);
       }
       if (!state) {
           ret += "</b>";
       }
       return ret;
   }
};