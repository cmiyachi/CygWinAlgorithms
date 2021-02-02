#include <bits/std++.h>
using namespace std;

class Solution {
public:
   int longestPalindrome(string s) {
    int l = s.length();
    map<char, int> m;

    for(int i=0; i<l; i++) {
        m[s[i]]++;
    }
    int ans = 0;
    bool flag = false;
    for(auto it: m) {
        if(it.second % 2 == 0) {
            ans += it.second;
        }
        else {
            ans += it.second-1;
            flag = true;
        }
    }
    if(flag) ans++;
    return ans;
}
};