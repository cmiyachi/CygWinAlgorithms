/// https://leetcode.com/problems/zigzag-conversion/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<=1) return s;
        
        int n = s.size();
        //string *A = new string[nRows];
		vector<string> A(nRows);
        
        int row = 0;
        int step = 1;
        for(int i=0;i<n;i++){
            A[row].push_back(s[i]);
            
            /// row++ row--
            if(row==0) step = 1;  /// row++
            else if(row==nRows-1) step = -1;   ///row--;
            
            row = row + step;
        }
        
         s = "";
        for(int i=0;i<nRows;i++){
            s = s + A[i];
        }
        return s;
    }
};
// O(n) + O (nRows) ~~ O(n) Space is O(nRows) ~~ O(1)
int main(void)
{
	Solution sol;
	string s="PAYPALISHIRING";
	
	cout << sol.convert(s,3); 
	
	return 0;
}