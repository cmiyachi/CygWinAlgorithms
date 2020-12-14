#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string A , string P ) {
        
        int M = A.size() ;
        int N = P.size() ;
        
        vector<vector<bool>> t(M+1, vector<bool>(N+1,0));
        t[0][0] = 1 ;
        
        for( int j = 2 ; j <= N ; j++ )if(P[j-1]=='*')t[0][j] = t[0][j-2]; 
        
        for( int i = 1 ; i <= M ; i++ )
        for( int j = 1 ; j <= N ; j++ )
        {
            if( P[j-1] == '*' )
            {
                 t[i][j] = t[i][j-2] ; 
                
                if( P[j-2] == '.' || P[j-2] == A[i-1] )
                    t[i][j] = t[i][j] || t[i-1][j] ; 
            }
            
            else if(  P[j-1] == A[i-1] || P[j-1] == '.' )
                t[i][j] = t[i-1][j-1] ; 
        }
        
        
        return t[M][N] ; 
        
    }
};

bool matches_first_Char(string s, string r)
{
	return s[0] == r[0] || (r[0] = '.' && s.length() >0); 
}

bool matches(string s, string r)
{
	if (r == "") return s == "";
	
	if (r.length() == 1 || r[1] != '*')
	{
		// the first char in the regex is not succeeded by a *
		if (matches_first_Char(s,r))
		{
			return(matches(s.substr(1), r.substr(1)));
		}
		else
			return false;
	}
	else
	{
		// the first char is succeeded by a *
		if (matches(s,r.substr(2)))
			return true;
			
		// keep globbing more prefixes
		int i = 0;
		while(matches_first_Char(s.substr(i), r))
		{
			if (matches(s.substr(i+1), r.substr(2)))
				return true;
			i++;
		}

	}
	return false; 
}

int main(void)
{
	
	string r = ".*at";
	string s = "chat"; 
	
	cout << matches(s,r) << endl;
	
	string r2 = "ra.";
	string s1 = "ray", s2 = "raymond";
	
	cout << matches(s1,r2) << endl;
	cout << matches(s2,r2) << endl;
	
	return 0;
}
