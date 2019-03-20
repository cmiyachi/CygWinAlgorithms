// C++ implementation to find the number closest to n 
// and divisible by m 
#include <bits/stdc++.h> 
#include <vector> 
#include <iostream> 

using namespace std; 

// function to find the number closest to n 
// and divisible by m 
int closestNumber(int n, int m) 
{ 
	// find the quotient 
	int q = n / m; 
	
	// 1st possible closest number 
	int n1 = m * q; 
	
	// 2nd possible closest number 
	int n2 = (n * m) > 0 ? (m * (q + 1)) : (m * (q - 1)); 
	
	// if true, then n1 is the required closest number 
	if (abs(n - n1) < abs(n - n2)) 
		return n1; 
	
	// else n2 is the required closest number	 
	return n2;	 
} 

// Driver program to test above 
int main() 
{ 
	/* int n = 13, m = 4; 
	cout << closestNumber(n, m) << endl; 
	
	n = -15; m = 6; 
	cout << closestNumber(n, m) << endl; 
	
	n = 0; m = 8; 
	cout << closestNumber(n, m) << endl; 
	
	n = 18; m = -7; 
	cout << closestNumber(n, m) << endl;  */
	//code
	int  testcases;
	cin >> testcases;
	vector<int> results;
	int n,m; 
	
	for (int i = 0; i < testcases; i++)
	{
		cin >> n;
		cin >> m; 
		results.push_back(closestNumber(n,m));
	}
	
	
	for (int j = 0; j < results.size(); j++)
		cout << results[j] <<endl; 
	return 0; 
} 
