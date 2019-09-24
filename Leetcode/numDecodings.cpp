#include <bits/stdc++.h>
using namespace std;

/* Recursion O(2^n)*/ 
class Solution {
public:
    int numDecodings(string s) {
         return s.empty() ? 0: numDecodings(0,s);
    }
	int numDecodings(int p, string& s) {
        int n = s.size();
        if(p == n) return 1;
        if(s[p] == '0') return 0;
        int res = numDecodings(p+1,s);
        if( p < n-1 && (s[p]=='1'|| (s[p]=='2'&& s[p+1]<'7'))) res += numDecodings(p+2,s);
        return res;
    }
};

class Solution2 {
public:
    int numDecodings(string s) {
		int n = s.size();
		if(n == 0 || s[0] == '0') return 0;
		if(n == 1) return 1;
		int res = 0,fn_1 = 1,fn_2 = 1;
		for(int i = 1;i < n;i++){
			int temp = fn_1;
			if(isValid(s[i])&&isValid(s[i-1],s[i]))  res+=fn_1+fn_2;
			if(!isValid(s[i])&&isValid(s[i-1],s[i])) res+=fn_2;
			if(isValid(s[i])&&!isValid(s[i-1],s[i])) res+=fn_1;
			if(!isValid(s[i])&&!isValid(s[i-1],s[i]))  return 0;
			fn_1 = res;
			fn_2 = temp;
			res = 0;
		}
		return fn_1;
        
    }
	bool isValid(char a,char b){
    return a == '1'||(a == '2' && b <='6');
	}
	bool isValid(char a){
		return a != '0';
	}
};


int main(void)
{
	Solution sol;
	string s = "12";
	cout << sol.numDecodings(s) << endl;
	
	s = "226";
	cout << sol.numDecodings(s) << endl;
}
	

/*
    
Memoization O(n)
    int numDecodings(string s) {
        int n = s.size();
        vector<int> mem(n+1,-1);
        mem[n]=1;
        return s.empty()? 0 : num(0,s,mem);   
    }
    int num(int i, string &s, vector<int> &mem) {
        if(mem[i]>-1) return mem[i];
        if(s[i]=='0') return mem[i] = 0;
        int res = num(i+1,s,mem);
        if(i<s.size()-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) res+=num(i+2,s,mem);
        return mem[i] = res;
    }
dp O(n) time and space, this can be converted from #2 with copy and paste.
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='0') dp[i]=0;
            else {
                dp[i] = dp[i+1];
                if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) dp[i]+=dp[i+2];
            }
        }
        return s.empty()? 0 : dp[0];   
    }
dp constant space
    int numDecodings(string s) {
        int p = 1, pp, n = s.size();
        for(int i=n-1;i>=0;i--) {
            int cur = s[i]=='0' ? 0 : p;
            if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) cur+=pp;
            pp = p;
            p = cur;
        }
        return s.empty()? 0 : p;   
    }
	
	*/