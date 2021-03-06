#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        unordered_map<char, int> m;
        vector<bool> digit(10, false);

        vector<string> newwords;        
        int maxlen = 0;
        for (auto w: words)
        {
            maxlen = max(maxlen, (int)w.size());
            reverse(w.begin(), w.end());
            newwords.push_back(w);
        }
        
        reverse(result.begin(), result.end());
        newwords.push_back(result);  // reverser all the input strings, to make it convenient to iterate from the least important digits
        maxlen = max(maxlen, (int)result.size());
        
        return dfs(newwords, result, m, digit, 0, 0, maxlen, 0);
    }
    
    bool dfs(vector<string> & words, const string & result, unordered_map<char, int> & m, vector<bool> & digit, int which_word, int which_char, int maxlen, int carry)
    {
        if (which_word == words.size())  // we have iterated all the words, so let's check if it is valid.
        {
            int sum = carry;
            for (int p=0; p<words.size() - 1; ++p)
                if (which_char<words[p].size())
                    sum += m[words[p][which_char]];
            
            if (sum % 10 != m[result[which_char]])
                return false;
            
            carry = sum / 10;
            ++which_char;
            which_word = 0;  // move forward the character pointer while restarting from the first word
            
            if (which_char==maxlen && carry == 0)
                return true;
        }
        
        if (which_char==maxlen) return false;
        int i = which_char;
        bool success = false;
            
        auto w = words[which_word];
        if (i >= w.size() || m.count(w[i]))
        {
            success = dfs(words, result, m, digit, which_word + 1, i, maxlen, carry);
            return success;
        }
        else
        {
            int j = (i==w.size() - 1)? 1: 0;
            for (; j<=9; ++j)
            {
                if (digit[j] == true) continue;
                m[w[i]] = j;
                digit[j] = true;

                success = dfs(words, result, m, digit, which_word + 1, i, maxlen, carry);
                if (success) return true;

                digit[j] = false;
                m.erase(w[i]);
            }
        }
        
        return false;
    }
};