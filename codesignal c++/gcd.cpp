// C++ program to find GCD of two numbers 
#include <iostream> 
#include <vector>
using namespace std; 
// Recursive function to return gcd of a and b 
int gcd(int a, int b) 
{ 
	// Everything divides 0 
	if (a == 0) 
	return b; 
	if (b == 0) 
	return a; 

	// base case 
	if (a == b) 
		return a; 

	// a is greater 
	if (a > b) 
		return gcd(a-b, b); 
	return gcd(a, b-a); 
} 

// Driver program to test above function  GCD of two numbers doesn’t change if smaller number is subtracted from a bigger number.
int main() 
{ 
	int  testcases;
	cin >> testcases;
	vector<int> results; 
	int a,b; 
	
	for (int i = 0; i < testcases; i++)
	{
		cin >> a; 
		cin >>  b; 
		
		results.push_back(gcd(a,b));
		 
		 
	} // for
	
	for (int j = 0; j < results.size(); j++)
		cout << results[j] <<endl; 
	
	// int a = 98, b = 56; 
	// cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b); 
	return 0; 
} 


// Recursive function to return gcd of a and b  A more efficient solution is to use modulo operator in Euclidean algorithm .
// int gcd(int a, int b) 
// { 
    // if (b == 0) 
        // return a; 
    // return gcd(b, a % b);  
      
// } 