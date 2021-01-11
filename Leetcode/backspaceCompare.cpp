#include <bits/stdc++.h>

using namespace std;

class Solution2 {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> ss, ts;
		for (const auto &c: S) {
			if (c != '#') {
				ss.push(c);
			}else{
				if(ss.empty()){
					continue;
				}
				ss.pop();
			}
		}
		
		for (const auto &c: T) {
			if (c != '#') {
				ts.push(c);
			}else{
				if(ts.empty()){
					continue;
				}
				ts.pop();
			}
		}
		
		if(ss.size()!=ts.size()){
			return false;
		}
		
		while(!ss.empty()){
			if(ss.top()!=ts.top()){
				return false;
			}
			ss.pop();
			ts.pop();
		}
		return true;
	}
};

class SolutionOverflow {
public:
    bool backspaceCompare(string S, string T) {
        int p1 = S.length()-1;
        int p2 = T.length()-1; 
        
        
        while (p1 >= 0 || p2>= 0)
        {
            if (S[p1] == '#' || T[p2] == '#')
            {
                
                if(S[p1] == '#') {
                    int backCount = 2;
                
                    while(backCount > 0) {
                        p1--;
                        backCount--;
                    
                        if(S[p1] == '#') {
                            backCount += 2;
                        }
                    }
                }
            
                if(T[p2] == '#') {
                    int backCount = 2;

                    while(backCount > 0) {
                        p2--;
                        backCount--;

                        if(T[p2] == '#') {
                            backCount += 2;
                        }
                    }
                }
             }
            else
            {
                 if(S[p1] != T[p2]) {
                        return false;
                } else {
                    p1--;
                    p2--;
                }
            }
        } // while
       
        return true; 
    }
};


class Solution {
public:
	bool backspaceCompare(string S, string T) {
	string s1="",s2="";
		for(int i=0;i<S.length();i++){
			if(S[i]=='#'){
				if(s1.length())
					s1.erase(s1.length()-1);
				}else
					s1=s1+S[i];
		}
		for(int i=0;i<T.length();i++){
			if(T[i]=='#'){
				if(s2.length())
					s2.erase(s2.length()-1);
			}else
				s2=s2+T[i];
		}
		if(s1==s2)
			return true;

		return false;
	}
};
int main(void)
{
	
	Solution sol;
	
	string s = "xywrrmp";
	string t = "xywrrmu#p";
	
	// cout << sol.backspaceCompare(s,t);
	
	string s1 = "e##e#o##oyof##q";
	string t2 = "e##e#fq##o##oyof##q";
	
		cout << sol.backspaceCompare(s1,t2);
	
	return 0;
}