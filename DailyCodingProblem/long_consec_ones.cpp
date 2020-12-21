// C++ program to find length of the longest 
// consecutive 1s in binary reprsentation of 
// a number. 
#include<bits/stdc++.h> 
using namespace std; 

int maxConsecutiveOnes(int x) 
{ 
	// Initialize result 
	int count = 0; 

	// Count the number of iterations to 
	// reach x = 0. 
	while (x!=0) 
	{ 
		// This operation reduces length 
		// of every sequence of 1s by one. 
		x = (x & (x << 1)); 

		count++; 
	} 

	return count; 
} 
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}
 
// Driver code 
int main() 
{ 
	cout << maxConsecutiveOnes(14) << endl; 
	bin(14);
	cout << maxConsecutiveOnes(222) << endl; 
	bin(222);
	return 0; 
} 
