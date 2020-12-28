/// https://leetcode.com/problems/valid-palindrome-ii/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    bool check(string A,int s,int e){
        while(s<=e){
            if(A[s] != A[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    
    bool validPalindrome(string A) {
        int s=0;
        int e = A.size()-1;
        
        while(s<=e){
            if(A[s] != A[e]){
                /// 2 cases
                /// delete s  check for A[s+1...e]
                /// delete e check for A[s...e-1]
                if(check(A,s+1,e) || check(A,s,e-1)){
                    return true;
                } else {
                    /// after deleting 1 char we are unable to obtain a palin
                    return false;
                }
                
            }
            s++;
            e--;
        }
        
        /// string is already palin
        return true;
    }
};

class Solution2 {
public:
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j]) return isp(s, i + 1, j) || isp(s, i, j - 1);
        return true;
    }

private:
    bool isp(string s, int l, int r) {
        for (int i = l, j = r; i < j; i++, j--)
            if (s[i] != s[j]) return false;
        return true;
    }
};

int main(void)
{
	Solution sol;
	
	cout << sol.validPalindrome("aba") << endl;
	cout << sol.validPalindrome("abca") << endl;
	cout << sol.validPalindrome("abcd") << endl;
	
	return 0;
}
	
	