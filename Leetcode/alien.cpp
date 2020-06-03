#include<bits/stdc++.h> 
using namespace std;
/**
BFS + Topological Sort, time complexity O(n), space complexity O(n)

STEP 1: Initialize
for each letter in each word indegree[letter] = 0;

STEP 2: Build Graph and Record the edge
for each edge (cur node, nex node) graph.insert(cur, nex)
for each nex node indegree[nex]++;

STEP 3: Topological Sort
use queue, push all nodes which indegree is 0;
use BFS start to iterate the whole graph.

STEP 4: Tell if cyclic
compare the result with indegree if (res.size() == indegree.size())
	**/

struct Node {
    int previous_chars = 0;  // number of characters that comes before
    vector<char> next_chars {};  // list of characters that come after
};

class Solution2 {
public:
    string alienOrder(const vector<string>& words) {
        if (std::empty(words)) return "";

        // initialize graph with empty nodes
        // for each character in the dictionary
        unordered_map<char, Node*> graph;
        for (const auto& word : words) {
            for (auto c : word) {
                if (!graph.count(c)) {
                    graph[c] = new Node();
                }
            }
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            const auto& word_0 = words[i];
            const auto& word_1 = words[i + 1];
            
            int idx = 0;
            // loop keeps going until a character mismatch
            // is found or if the index is out of bounds
            while (idx < word_0.size()
                    && idx < word_1.size()
                    && word_0[idx] == word_1[idx]) {
                ++idx;
            }
            
            if (idx >= word_0.size() || idx >= word_1.size()) {
                // if the index is out of bounds, make sure
                // word_1 isn't a prefix of word_0
                if (word_1.size() < word_0.size()) return "";
            } else {
                // if the index isn't out of bounds, we have a mismatch
                
                // the character in the first word should add the character
                // in the second word to its next characters list
                graph[word_0[idx]]->next_chars.emplace_back(word_1[idx]); 
                
                // the character in the second word should increment
                // its its previous characters count
                graph[word_1[idx]]->previous_chars++;
                
            }

        }

        // add all characters without predecessors
        // to the processing stack
        stack<char> processing {};
        for (auto [c, node] : graph) {
            if (node->previous_chars == 0) {
                processing.emplace(c);
            }
        }

        string alien_order = "";
        while (!std::empty(processing)) {
            // if the character doesn't have predecessors
            // we can add it to the order string
            alien_order += processing.top();
            processing.pop();

            // loop through all the characters that come after it
            // and decrement the previous chars count
            for (auto c : graph[alien_order.back()]->next_chars) {
                graph[c]->previous_chars--;
                if (graph[c]->previous_chars == 0) {
                    // if we processed all the characters that come before
                    // we should process this character next
                    processing.emplace(c);
                }
            }
        }
    
        // if string size doesn't match total characters in words dictionary
        // the graph was cyclical, the dictionary is out of order
        if (alien_order.size() < graph.size()) {
            return "";
        }

        return alien_order;
    }
};


class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 0) return "";
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;
        
        // initialize
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                indegree[c] = 0; 
            }
        }
        
        // build graph and record indegree
        for (int i = 0; i < words.size() - 1; i++) {
            string cur = words[i];
            string nex = words[i + 1];
            int len = min(cur.size(), nex.size());
            for (int j = 0; j < len; j++) {
                if (cur[j] != nex[j]) {
                    unordered_set<char> set = graph[cur[j]];
                    if (set.find(nex[j]) == set.end()) {
                        graph[cur[j]].insert(nex[j]); // build graph
                        indegree[nex[j]]++; // add indegree
                    }
                    break;                        
                }
				if (j == len - 1 and cur.size() > nex.size()) return "";
            }
        }
        
        // topoligical sort
        string ans;
        queue<char> q;
        for (auto& e : indegree) {
            if (e.second == 0) {
                q.push(e.first);
            }
        }
        while(!q.empty()) {
            char cur = q.front();
            q.pop();
            ans += cur;
            
            if (graph[cur].size() != 0) {
                for (auto& e : graph[cur]) {
                    indegree[e]--;
                    if (indegree[e] == 0) {
                        q.push(e);
                    }
                }
            }            
        }
        
        // tell if it is cyclic
        return ans.length() == indegree.size() ? ans : "";
    }
};

int main(void)
{
	vector<string> words{"wrt","wrf","er","ett","rftt"}; 
  
	Solution2 sol;
  
	string alphabet  = sol.alienOrder(words);
  
	cout << alphabet << endl; 
	
	vector<string> words2{"abc" "ab"};
	alphabet = sol.alienOrder(words2);
	cout << alphabet << endl; 
	
  
	return 0;
}