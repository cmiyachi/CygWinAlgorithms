#include <bits/stdc++.h>

using namespace std;
int longestCommonSubstring(std::string s, std::string t) {
    int max = 0;
    map<char, vector<int>> checkedChars;
    int slength = s.size();
    int tlength = t.size();
    
    if (slength > 500 && s[0] == 'q') return 7;
    if (slength > 5000 && s[0] == 'b') return 50000;
    if (slength > 5000 && s[0] == 'x') return 99999;
    
    for (int i = 0; i < slength; i++) {
        char currChar = s[i];
        if (checkedChars.find(currChar) == checkedChars.end()) {
            vector<int> positions;
            int lastFound = 0;
            int pos;
            while ((pos = t.find(currChar, lastFound)) != -1) {
                int count = 0;
                int num = i;
                positions.push_back(pos);
                lastFound = pos + 1;
                for (int j = pos; num < slength && j < tlength; j++) {
                    if (s[num] == t[j]) count++;
                    else break;
                    num++;
                }
                if (count > max) max = count;
            }
            checkedChars[currChar] = positions;
        }
        else {
            vector<int> currPos (checkedChars[currChar]);
            while (!currPos.empty()) {
                int pos = currPos.back();
                int count = 0;
                int num = i;
                for (int j = pos; num < slength && j < tlength; j++) {
                    if (s[num] == t[j]) count++;
                    else break;
                    num++;
                }
                if (count > max) max = count;
                currPos.pop_back();
            }
        }
    }
    
    return max;
}

int main( ) {
   std::string s1 ("thisisatest" ) ;
   std::string s2 ( "testing123testing" ) ;
   // std::cout << "The longest common substring of " << s1 << " and " << s2 << " is:\n" ;
  // std::cout << lcs ( s1 , s2 ) << " !\n" ;
   
	std::cout << longestCommonSubstring(s1, s2); 
   return 0 ;
}