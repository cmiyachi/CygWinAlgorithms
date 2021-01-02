/// https://leetcode.com/problems/valid-parentheses/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string A) {
        stack<char> s;
        
        for(int i=0;i<A.size();i++){
            
            if(A[i]=='(' || A[i]=='{' || A[i]=='['){
                s.push(A[i]);
            } else{
                
                if(s.empty()) return false; /// imp otherwise run time erro
                else if(A[i]==')'){
                    if(s.top() == '(') s.pop();
                    else return false;
                }else if(A[i]=='}'){
                    if(s.top() == '{') s.pop();
                    else return false;
                }else if(A[i]==']'){
                    if(!s.empty() && s.top() == '[') s.pop();
                    else return false;
                }
                
            }
            
        }
        
        if(s.empty()) return true;
        
        return false;
    }
};

class Solution2 {
public:
	map<char,char>  mappings; 
	Solution2() {
		mappings[')'] = '(';
		mappings['}'] = '{';
		mappings[']'] = '[';
	}
	
    bool isValid(string s) {
		stack<char> pStack; 
		
		for (int i = 0; i < s.length(); i++)
		{
			char c = s[i]; 
			// if closing bracket
			auto itr = mappings.find(c); 
			if (itr != mappings.end())
			{
				// get top element of stack
				char topElement = pStack.empty() ? '#': pStack.top(); 
				pStack.pop(); 
				//the top of stack has to match this closing element
				if (topElement  != mappings[c])
					return false; 
			}
			else // it's an opening bracket
				pStack.push(c);
		} // for
        
		return pStack.empty(); 
    }
};

int main(void)
{
	Solution sol;
	
	string s = "([]{}())"; 
	
	cout << sol.isValid(s);
	
	return 0;
}