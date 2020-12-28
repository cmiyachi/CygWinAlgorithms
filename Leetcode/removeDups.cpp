/// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
/// https://www.hackerrank.com/challenges/reduced-string/problem

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string A) {
         /*stack<char> s;
         for(int i=0;i<A.size();i++){
             if(s.empty() || A[i] != s.top()){
                 s.push(A[i]);
             } else {
                 s.pop();
             }
         }
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        */
        
        /// simulate inplace stack
        int stptr = -1;
        for(int i=0;i<A.size();i++){
             if(stptr ==-1 || A[i] != A[stptr] ){
                 stptr++;
                 A[stptr] = A[i];
             } else {
                 stptr--;
             }
         }
         string ans="";
        for(int i=0;i<=stptr;i++){
            ans.push_back(A[i]);
        }
		
        return ans;
    }
};

class Solution2 {
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

int main(void)
{
	Solution sol;
	cout << sol.removeDuplicates("abbaca") << endl;
	
	
	return 0;
}