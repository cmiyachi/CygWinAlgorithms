#include <iostream>
#include <vector> 
using namespace std;
// Recursive function to return gcd of a and b 
long gcd(long a, long b) 
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
// Function to return LCM of two numbers  
 long lcm(long a, long b)  
 {  
    return (a*b)/gcd(a, b);  
 }  
int main() {
	//code
	long  testcases;
	cin >> testcases;
	vector<long> results;
	vector<long> results2;
	long n,m; 
	
	for (long i = 0; i < testcases; i++)
	{
		cin >> n;
		cin >> m; 
		results.push_back(gcd(n,m));
		results2.push_back(lcm(n,m));
	}
	
	
	for (long j = 0; j < results.size(); j++)
		cout << (results2[j]) << " " << results[j] <<endl; 
	
	return 0;
}