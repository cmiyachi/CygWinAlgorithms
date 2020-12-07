/*
mplement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist */

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        
    }
    
    bool query(char letter) {
        
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
 
 /*
 Prerequisites
This design article uses data structure Trie. If you never worked with trie before, you might want to check this introduction article first to simplify the further reading.

Approach 1: Trie
Trie

Trie is widely used in real life: autocomplete search, spell checker, T9 predictive text, IP routing (longest prefix matching), some GCC containers.

Trie is something to think about if you're asked to design a structure to dynamically add and search strings.

Intuition

The first idea is to add all input words in the trie and then implement a standard search.

fig

Figure 1. Naive implementation.

The problem is we don't know how many characters to match. On the example above, should we try to match the last three stream characters "jkl", the last two "kl", or the last one "l"?

The way to solve the problem is to notice that we always know the last character to match. That gives us an idea to build a trie of reversed words, and try to match the reversed stream of characters.

fig

Figure 2. Trie of the reversed words and the reversed stream of characters.

This way, instead of multiple choices to match, we always have one path: to match character by character starting from the end of the stream. We could stop once we meet the "end of word" label, which means success. If we couldn't match a character before we meet that label, that means fail.

Constructor StreamChecker

Trie is usually implemented as nested hashmaps. At each step, one has to verify if the child node to add is already present. If yes, we go one level down. If not, we add the node into a trie and then go one step down. The particularity of the current problem is that we add in the trie the reversed words.

The last thing to discuss is how to store the reversed stream of characters. For that, we need a structure for which appendleft / addFirst operation takes a constant time. The good choice here is double ended queue, it's implemented as deque in Python, and as ArrayDeque in Java.

Complexity Analysis

Time complexity: \mathcal{O}(N \cdot M)O(N⋅M), where NN is a number of input words, and MM is the word length. We have NN words to process. At each step, we either examine or create a node in the trie. That takes only MM operations.

Space complexity: \mathcal{O}(N \cdot M)O(N⋅M). In the worst-case newly inserted key doesn't share a prefix with the keys already added in the trie. We have to add N \cdot MN⋅M new nodes, which takes \mathcal{O}(N \cdot M)O(N⋅M) space.

Query Implementation

The search is very straightforward: we start from the end of the stream and check character by character, going down in trie.

fig

Figure 3. Search in trie. */

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        // insert reversed word into trie and keep track of the length of longest word
        for (auto& word: words) 
        {
            trie.insert_reversed(word);
            if (word.length() > longest_word)
                longest_word = word.length();
        }
    }
    
    bool query(char letter) {
        queries.insert(queries.begin(), letter);
        // keep in queries only the "longest word" last queries, because we don't need the other ones anymore
        if (queries.size() > longest_word)
            queries.pop_back();
        Trie* cur = &trie;
        for (auto it = queries.begin(); it!=queries.end();++it)
        {
            if (cur->is_leaf) return true;
            if (cur->children[*it -'a'] == NULL) return false;
            cur = cur->children[*it-'a'];
        }
        return cur->is_leaf;
    }
private:
    
    class Trie {
    public:
        Trie() {
            this->is_leaf = false;
            for(int i=0;i<26;i++)
                this->children[i] = NULL;
        }
        
        void insert_reversed(string word) {
            reverse(word.begin(), word.end());
            Trie* root = this;
            for(int i=0;i<word.length();i++)
            {
                int index = word[i] - 'a';
                if (root->children[index] == NULL)
                    root->children[index] = new Trie();
                root = root->children[index];
            }
            root->is_leaf = true;
        }
        
    bool is_leaf;
    Trie* children[26];
    };
    
    Trie trie;
    vector<char> queries;
    int longest_word=0;
};