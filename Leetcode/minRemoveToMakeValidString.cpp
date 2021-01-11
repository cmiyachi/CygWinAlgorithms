#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            if (s[i] == ')') {
                if (!st.empty()) st.pop();
                else s[i] = '*';
            }
        }
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        set<int> indicesToRemove;
        stack<int> st; 
         for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } if (s[i] == ')') {
                if (st.empty()) {
                    indicesToRemove.insert(i);
                } else {
                    st.pop();
                }
            }
        }
        // Put any indexes remaining on stack into the set.
        while (!st.empty())
        {
            indicesToRemove.insert(st.top());
            st.pop();
        }
        
        stringstream ss; 
        for (int i = 0; i < s.length(); i++) {
            if (indicesToRemove.find(i) == indicesToRemove.end()) {
               ss << s[i];  
            }
        }
        
        return ss.str(); 
    }
};


int main(void)
{
	string s = "))((";
	
	Solution sol;
	
	cout << sol.minRemoveToMakeValid(s); 
	
	return 0;
}
	