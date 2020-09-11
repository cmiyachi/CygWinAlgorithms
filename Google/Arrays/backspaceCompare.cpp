#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:    
    string getString(string &str) {
        int n=str.length(), count=0;
        string result="";
        for(int i=n-1; i>=0; i--) {
            char ch=str[i];
            if(ch=='#') 
                count++;
            else {
                if(count>0)
                    count--;
                else {
                    result+=ch;
                }                     
            }
        }
        return result;        
    }
    
    bool backspaceCompare(string S, string T) {
        return getString(S)==getString(T);
    }
};

/**Follow up: O(1) Space
Can you do it in O(N) time and O(1) space?
I believe you have one difficulty here:
When we meet a char, we are not sure if it will be still there or be deleted.

However, we can do a back string compare (just like the title of problem).
If we do it backward, we meet a char and we can be sure this char won't be deleted.
If we meet a '#', it tell us we need to skip next lowercase char.

The idea is that, read next letter from end to start.
If we meet #, we increase the number we need to step back, until back = 0


C++: **/

    bool backspaceCompare2(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1, back;
        while (true) {
            back = 0;
            while (i >= 0 && (back > 0 || S[i] == '#')) {
                back += S[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || T[j] == '#')) {
                back += T[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;
    }
/** Original version
C++:
**/
    bool backspaceCompareOG(string S, string T) {
        for (int i = S.length() - 1, j = T.length() - 1;; i--, j--) {
            for (int back = 0; i >= 0 && (back || S[i] == '#'); --i)
                back += S[i] == '#' ? 1 : -1;
            for (int back = 0; j >= 0 && (back || T[j] == '#'); --j)
                back += T[j] == '#' ? 1 : -1;
            if (i < 0 || j < 0 || S[i] != T[j]) return i == -1 && j == -1;
        }
    }
class Solution {
public:
    bool backspaceCompare(string S, string T) {
		return (convertString(S) == convertString(T));
        
    }
	string convertString(string s)
	{
		stack<char> ans;
		for (auto c : s)
		{
			if (c != '#')
				ans.push(c); 
			else if (!ans.empty())
				ans.pop();
		}
		
		int n = ans.size();
		string result(n,' ');

		for (int i = n-1; i>=0; i--){
			result[i] = ans.top(); ans.pop(); 
		}
		return result; 
	}
};

int main(void)
{
	Solution sol;
	string S ="ab#c", T = "ad#c";
	
	cout << sol.backspaceCompare(S,T) << endl;
	
	string S2 = "ab##", T2 = "c#d#";
	
	cout << sol.backspaceCompare(S2,T2) << endl;
	
	string S3 = "a#c", T3 = "b";
	cout << sol.backspaceCompare(S3,T3) << endl;
	
	return 0;
}