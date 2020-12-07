/*
We can represent a sentence as an array of words, for example, the sentence "I am happy with leetcode" can be represented as arr = ["I","am",happy","with","leetcode"].

Given two sentences sentence1 and sentence2 each represented as a string array and given an array of string pairs similarPairs where similarPairs[i] = [xi, yi] indicates that the two words xi and yi are similar.

Return true if sentence1 and sentence2 are similar, or false if they are not similar.

Two sentences are similar if:

They have the same length (i.e. the same number of words)
sentence1[i] and sentence2[i] are similar.
Notice that a word is always similar to itself, also notice that the similarity relation is not transitive. For example, if the words a and b are similar and the words b and c are similar, a and c are not necessarily similar.

 

Example 1:

Input: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","fine"],["drama","acting"],["skills","talent"]]
Output: true
Explanation: The two sentences have the same length and each word i of sentence1 is also similar to the corresponding word in sentence2.
Example 2:

Input: sentence1 = ["great"], sentence2 = ["great"], similarPairs = []
Output: true
Explanation: A word is similar to itself.
Example 3:

Input: sentence1 = ["great"], sentence2 = ["doubleplus","good"], similarPairs = [["great","doubleplus"]]
Output: false
Explanation: As they don't have the same length, we return false.

*/

/*
Intuition and Algorithm

To check whether words1[i] and words2[i] are similar, either they are the same word, or (words1[i], words2[i]) or (words2[i], words1[i]) appear in pairs.

To check whether (words1[i], words2[i]) appears in pairs quickly, we could put all such pairs into a Set structure.

*/

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
    }
};
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        map<string, set<string>> map;
        for (vector<string> p : pairs)
            map[p[0]].insert(p[1]);

        for (int i = 0; i < words1.size(); i++)
            if (words1[i] != words2[i] && !map[words1[i]].count(words2[i]) && !map[words2[i]].count(words1[i]))
                return false;
        return true;
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        
    }
};

bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
    if(words1.size() != words2.size()) return false;
    unordered_map<string, unordered_set<string>> h;
    for(auto p: pairs){
        h[p[0]].insert(p[1]);
        h[p.[1]].insert(p[0]);
    }
    for(int i = 0; i < words1.size(); i++){
        if(words1[i] != words2[i] && h[words1[i]].count(words2[i]) == 0)
            return false;
    }
    return true;
}

/*
737. Sentence Similarity II
Medium

513

34

Add to List

Share
Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.

Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].*/


/*
This is a good use case for Union-Find, compare to Sentence Similarity I, here the similarity between words are transitive, so all the connected(similar) words should be group into an union represented by their ultimate parent(or family holder, you name it).
The connections can be represented by an parent map Map<String, String> m, which record the direct parent-ship we learned in each pair, but not the ultimate-parent. To build it, go through the input pairs, for each pair<w1, w2>, use the recursive find() method to find the ultimate-parent for both word - parent1, parent2, if they are different, assign parent1 as parent of parent2(or the other way around), so that the to families are merged.
The classic find(x) method will find the ultimate-parent of x. I modified it a little bit, make it do a little of extra initialization work - assign x itself as its parent when it is not initialize - so that we don't have to explicitly initialize the map at the beginning.
Java*/

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& a, vector<string>& b, vector<vector<string>>& pairs) { //vector<pair<string, string>> pairs) {
        if (a.size() != b.size()) return false;
        map<string, string> m;
        for (vector<string> p : pairs) {
            string parent1 = find(m, p[0]), parent2 = find(m, p[2]);
            if (parent1 != parent2) m[parent1] = parent2;
        }

        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i] && find(m, a[i]) != find(m, b[i])) return false;

        return true;
    }

private:
    string find(map<string, string>& m, string s) {
        return !m.count(s) ? m[s] = s : (m[s] == s ? s : find(m, m[s]));
    }
};



class Solution {
public:
    string find(map<string, string> &m, string s) {
        if (m.find(s)==m.end()) {
            m[s] = s;
        }
        while(m[s]!=s) {
            s=m[s];
        }
        return m[s];
    }
    void uni(map<string, string> &m, string s1, string s2) {
        if (find(m,s1) != find(m,s2)) {
            m[find(m, s1)] = find(m,s2);            
        }
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        
        if (words1.size()!= words2.size()) {
            return false;
        }
        map<string, string> m;
        for (int i = 0; i < pairs.size(); i++) {
            uni(m, pairs[i][0], pairs[i][1]);
        }
        for(int i = 0; i < words1.size(); i++) {
            
            if (find(m, words1[i]) != find(m, words2[i]))
                return false;
        }
        return true;
    }
};