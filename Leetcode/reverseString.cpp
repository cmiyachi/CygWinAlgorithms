#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0 ,  j = s.size()-1 ;
        while(i < j)
        { int temp = s[i];
             s[i] = s [j] ;
             s[j] = temp ; 
            j--;
            i++;
		}
    }
};

class Solution2 {
public:
    void reverseString(vector<char>& s) {
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			st.push(s[i]);
		}
		
		for (int i = 0; i < s.size(); i++)
		{
			s[i] = st.top(); st.pop();
		}
		
	}
};

int main(void)
{
	vector<char> s{'a','b','c','d'};
	Solution sol;
	sol.reverseString(s);
	for ( char c:s)
		cout << c;
	return 0;
}