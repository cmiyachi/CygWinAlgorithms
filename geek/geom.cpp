// CPP Program to find nth term of 
// geometric progression 
#include <bits/stdc++.h> 

using namespace std; 

int Nth_of_GP(int a, int r, int N) 
{ 
	// using formula to find 
	// the Nth term 
	// TN = a1 * r(N-1) 
	return( a * (int)(pow(r, N - 1)) ); 
	
} 


int main()
{
    int t; cin>>t;
	vector<long> results;
    while(t--)
    {
        float a,b,n; cin>>a>>b>>n;
        float r=b/a;
        float res=(a*(pow(r,n-1)));
		results.push_back(floor(res));
    }
	
	
	for (int j = 0; j < results.size(); j++)
		cout << results[j] <<endl; 
    return 0;
}