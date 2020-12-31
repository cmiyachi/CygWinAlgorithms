// https://www.interviewbit.com/problems/find-permutation/
// https://leetcode.com/articles/find-permutation/#

#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<int> findPermutation(string s) {
		int n = s.size() +1;
      vector<int> ans(n);
      int start = 1, e = n;
      
      for(int i=0;i<s.size();i++){
          if(s[i]=='D'){
              ans[i] = e;
              e--;
          }else{
              ans[i] = start;
              start++;
          }
      }
      ans[n-1] = start; /// e
      return ans;
}
};

class Solution {
public:
    vector<int> findPermutation(string s) {
         vector<int> res(s.length() + 1);
        res[0]=1;
        int i = 1;
        while (i <= s.length()) {
            res[i]=i+1;
            int j = i;
            if(s[i-1]=='D')
            {
                while (i <= s.length() && s[i - 1] == 'D')
                    i++;
                for (int k = j - 1, c = i; k <= i - 1; k++, c--) {
                    res[k] = c;
                }
            }
            else
                i++;
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> findPermutation(string s) {
        vector<int> res(s.size()+1); 
        
        stack<int> stck;
        
        int j = 0;
      for (int i = 1; i <= s.length(); i++) {
        if (s[i-1] == 'I') {
            stck.push(i);
            while (!stck.empty())
            {
                res[j++] = stck.top();
                stck.pop();
            }
        } else
            stck.push(i);
    }
        stck.push(s.length() + 1);
        while (!stck.empty())
        {
            res[j++] = stck.top();
            stck.pop();
        }
        return res;
        
        
    }
};