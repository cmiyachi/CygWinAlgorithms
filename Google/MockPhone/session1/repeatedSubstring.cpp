/*
Overview
The problem could be solved in many ways. Easy approaches have \mathcal{O}(N^2)O(N 
2
 ) time complexity, though one could improve it by using one of string searching algorithms.

overview



Approach 1: Regex
To use regex during the interviews is like to use built-in functions, the community has no single opinion about it yet, and it's a sort of risk.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        regex pat("^(.+)\\1+$");
        return regex_match(s, pat);
    }
};