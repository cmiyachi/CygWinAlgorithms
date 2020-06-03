#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    string minWindow(string s, string t) {
        int start = 0; // record the beginning of the minium substring
        int minLen = INT_MAX;
        int left = 0, right = 0;
        int match = 0; // record the match number between window and needs
        
        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        for (char c : t) {
            needs[c]++;
        }
        
        // first, move right to very right
        // if match == needs.size(), move left to right until match < needs.size()
        while (right < s.size()) {
            char c1 = s[right];
            if (needs.count(c1)) {
                window[c1]++;
                if (window[c1] == needs[c1]) {
                    match++;
                }
            }
            right++;
            
            while (match == needs.size()) {
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if (needs.count(c2)) {
                    window[c2]--;
                    if (window[c2] < needs[c2])
                        match--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

class Solution {
public:
string minWindow(string s, string t) {
        vector<int> hist(128, 0);
        for (char c : t) hist[c]++;
        
        int remaining = t.length();
        int left = 0, right = 0, minStart = 0, minLen = numeric_limits<int>::max();
        while (right < s.length()){
            if (--hist[s[right++]] >= 0) remaining--;
            while (remaining == 0){
                if (right - left < minLen){
                    minLen = right - left;
                    minStart = left;
                }
                if (++hist[s[left++]] > 0) remaining++;
            }
        }
            
        return minLen < numeric_limits<int>::max() ? s.substr(minStart, minLen) : "";
    }
    string minWindow2(string s, string t) {

      if (s.length() == 0 || t.length() == 0) {
          return "";
      }

      // Dictionary which keeps a count of all the unique characters in t.
      map<char, int> dictT;
      for (int i = 0; i < t.length(); i++) {
          dictT[t[i]]++; 
      }

      // Number of unique characters in t, which need to be present in the desired window.
      int required = dictT.size();

      // Left and Right pointer
      int l = 0, r = 0;

      // formed is used to keep track of how many unique characters in t
      // are present in the current window in its desired frequency.
      // e.g. if t is "AABC" then the window must have two A's, one B and one C.
      // Thus formed would be = 3 when all these conditions are met.
      int formed = 0;

      // Dictionary which keeps a count of all the unique characters in the current window.
      map<char, int> windowCounts;

      // ans list of the form (window length, left, right)
      int ans[3] = {-1, 0, 0};

      while (r < s.length()) {
          // Add one character from the right to the window
          char c = s[r];
          windowCounts[c]++; 

          // If the frequency of the current character added equals to the
          // desired count in t then increment the formed count by 1.
          if ((dictT.find(c)!= dictT.end()) && (windowCounts[c] == dictT[c])) {
              formed++;
          }

          // Try and contract the window till the point where it ceases to be 'desirable'.
          while (l <= r && formed == required) {
              c = s[l];
              // Save the smallest window until now.
              if (ans[0] == -1 || r - l + 1 < ans[0]) {
                  ans[0] = r - l + 1;
                  ans[1] = l;
                  ans[2] = r;
              }

              // The character at the position pointed by the
              // `Left` pointer is no longer a part of the window.
              windowCounts[c]--;
              if (dictT.find(c)!=dictT.end() && windowCounts[c] < dictT[c]) {
                  formed--;
              }

              // Move the left pointer ahead, this would help to look for a new window.
              l++;
          }

          // Keep expanding the window once we are done contracting.
          r++;   
      }

      return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] + 1);
  }
};

int main(void)
{
	string S = "ADOBECODEBANC", T = "ABC";
	
	Solution2 sol;
	cout << sol.minWindow(S,T);
	
	return 0;
}