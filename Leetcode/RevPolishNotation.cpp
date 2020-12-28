#include <bits/stdc++.h>
using namespace std;

/// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(int i=0;i<tokens.size();i++){
            
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
              /// 2 elements
             int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            
            if(tokens[i]=="+"){
                st.push(v2+v1);  /// push result inside stack
            } 
            else if(tokens[i]=="-"){
                st.push(v2-v1);  /// push result inside stack
            }
             else if(tokens[i]=="*"){
                st.push(v2*v1);  /// push result inside stack
            }
             else if(tokens[i]=="/"){
                st.push(v2/v1);  /// push result inside stack
            }
        }
        
        else {
            /// operands
            st.push(atoi(tokens[i].c_str()));
        }
    }
        
    /// one element inside the stack
        
        return st.top();
    }       
            
};

int main(void)
{
	vector<string> tokens1{"2", "1", "+", "3", "*"};
	vector<string> tokens2{"4", "13", "5", "/", "+"};
	vector<string> tokens3{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	
	Solution sol;
	
	cout << sol.evalRPN(tokens1) << endl;
	cout << sol.evalRPN(tokens2) << endl;
	cout << sol.evalRPN(tokens3) << endl;	
	return 0;
}