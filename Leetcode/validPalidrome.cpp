/// https://leetcode.com/problems/valid-palindrome/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string A) {
        int s=0;
        int n = A.size();
        int e = n-1;
        
        while(s<=e){
            
            while(s<e && !isalnum(A[s])) s++;
            while(s<e && !isalnum(A[e])) e--;
            
            if(toupper(A[s]) != toupper(A[e])) return false;
            
            s++;
            e--;
        }
        return true;
    }
};

class Solution2 {
public:
    bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
			while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
			while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
			if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
		}
		
		return true;
	}
};

int main(void)
{
	Solution sol;
	
	cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << sol.isPalindrome("race a car") << endl;
	
	return 0;
}
