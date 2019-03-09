// C++ program to convert binary to decimal 
#include<iostream> 
#include <vector> 
using namespace std; 

// Function to convert binary to decimal 
long binaryToDecimal(long n) 
{ 
	long num = n; 
	long dec_value = 0; 
	
	// Initializing base value to 1, i.e 2^0 
	long base = 1; 
	
	long temp = num; 
	while (temp) 
	{ 
		long last_digit = temp % 10; 
		// cout << "ld " << last_digit << endl; 
		temp = temp/10; 
		// cout << "temp " << temp << endl; 
		
		dec_value += last_digit*base; 
		
		base = base*2; 
	} 
	
	return dec_value; 
} 

// Driver program to test above function 
int main() 
{ 
	// long num = 10101001; 
	
	long  testcases;
	cin >> testcases;
	vector<long> results; 
	
	for (long i = 0; i < testcases; i++)
	{
		long num = 0; 
		cin >> num; 
		// cout <<binaryToDecimal(num)<<endl; 
		results.push_back(binaryToDecimal(num)); 
	} // for
	
	for (long j = 0; j < results.size(); j++)
		cout << results[j] <<endl; 
	
} 
