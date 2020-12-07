/*
Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 */
 class Solution {
public:
    string removeDuplicates(string S) {
        
    }
};


string removeDuplicateLetters(string s) {
    vector<int> cand(256, 0);
    vector<bool> visited(256, false);
    for (char c : s)
        cand[c]++;
    string result = "0";
    for (char c : s) {
        cand[c]--;
        if (visited[c]) continue;
        while (c < result.back() && cand[result.back()]) {
            visited[result.back()] = false;
            result.pop_back();
        }
        result += c;
        visited[c] = true;
    }
    return result.substr(1);
}



string removeDuplicateLetters(string s) {
    vector<unsigned int> cnt(26,0); //only consider lowercase letters
    vector<bool> inRes(26, false); //true if the letter has been added to res 
    for(char ch:s) cnt[ ch-'a' ]++;
    string res = ""; //use res as a stack
    for(char ch:s){
       cnt[ ch-'a' ]--;
       if(res.empty()){ 
           res.push_back(ch);
           inRes[ ch-'a' ] = true;
           continue;
       }
       if(inRes[ch-'a']) continue;
       while(ch<res.back() && !res.empty() && cnt[ res.back()-'a' ]>0){
           inRes[ res.back()-'a' ] = false;
           res.pop_back();
           
       }
       res.push_back(ch);
       inRes[ ch-'a' ] = true;
    }
    return res;
}


class Solution {
public:
    string removeDuplicates(string S) {
        int i = 0, j = 0;
        while (j < S.size()) {
            if (i == 0) {
                S[i++] = S[j];
            } else if (S[i - 1] == S[j]) {
                i--;
            } else {
                S[i++] = S[j];
            }
            j++;
        }
        S.resize(i);
        return S;
    }
};