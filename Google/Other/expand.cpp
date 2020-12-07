/*
A string S represents a list of words.

Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  If there is more than one option, then curly braces delimit the options.  For example, "{a,b,c}" represents options ["a", "b", "c"].

For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].

Return all words that can be formed in this manner, in lexicographical order.

 

Example 1:

Input: "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]
Example 2:

Input: "abcd"
Output: ["abcd"]
 

Note:

1 <= S.length <= 50
There are no nested curly brackets.
All characters inside a pair of consecutive opening and ending curly brackets are different.*/

class Solution {
public:
    vector<string> expand(string S) {
        
    }
};

vector<string> expand(string S) {
        vector<string> list(100);
        int n = 0;
        bool option = false;
        for(auto&c : S) {
            if(c == ',')
                continue;
            else if(c == '{'){
                option = true;
            }
            else if(c == '}') {
                option = false;
                ++n;
            }
            else {
                list[n] += c;
                if(!option)
                    ++n;
            }
        }
        
        for(int i = 0; i < n; ++i)
            sort(list[i].begin(), list[i].end());
        vector<string> res;
        
        dfs(list, 0, n, "", res);
        return res;
    }
    
    void dfs(vector<string>& list, int i , int n, string cur, vector<string>& res) {
        if(i == n) {
            res.push_back(cur);
            return;
        }
        
        for(auto& c : list[i])
            dfs(list, i+1, n, cur+c, res);
    } 