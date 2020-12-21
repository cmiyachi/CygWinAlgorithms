// C++ program to find nth magic numebr 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find nth magic numebr 
int nthMagicNo(int n) 
{ 
	int pow = 1, answer = 0; 

	// Go through every bit of n 
	while (n) 
	{ 
	pow = pow*7; 

	// If last bit of n is set 
	if (n & 1) 
		answer += pow; 

	// proceed to next bit 
	n >>= 1; // or n = n/2 
	} 
	return answer; 
} 

int nth_sevenish_number(int n)
{
	int answer = 0;
	int bit_place = 0;
	
	while (n)
	{
		if (n & 1)
			answer += pow(7, bit_place);
		
		n >>= 1; // n/2
		bit_place += 1; 
	}
	
	return answer; 
}

// Driver program to test above function 
int main() 
{ 
	int n = 5; 
	cout << "nth magic number is " << nthMagicNo(n) << endl; 
	
	cout << nth_sevenish_number(10); 
	
	return 0; 
} 
