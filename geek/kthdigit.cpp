// CPP program for finding k-th digit in a^b 
#include <bits/stdc++.h> 
using namespace std; 

// To compute k-th digit in a^b 
long kthdigit(int a, int b, int k) 
{ 
	// computing a^b 
	long p = pow(a, b); 

	int count = 0; 
	while (p > 0 && count < k) { 

		// getting last digit 
		long rem = p % 10; 

		// increasing count by 1 
		count++; 

		// if current number is required digit 
		if (count == k) 
			return rem; 

		// remove last digit 
		p = p / 10; 
	} 

	return 0; 
} 

// Driver code 
int main() 
{ 
//	int a = 5, b = 2; 
//	int k = 1; 
// 	cout << kthdigit(a, b, k); 
	
	int t; cin>>t;
	vector<long> results;
    while(t--)
    {
        int a,b,k; cin>>a>>b>>k;
        results.push_back(kthdigit(a,b,k));
    }
	
	
	for (int j = 0; j < results.size(); j++)
		cout << results[j] <<endl; 
   
	return 0; 
} 
