// An efficient C++ program to randomly select 
// a number from stream of numbers. 
#include <bits/stdc++.h> 
#include <time.h> 
using namespace std; 

// A function to randomly select a item 
// from stream[0], stream[1], .. stream[i-1] 
int selectRandom(int x) 
{ 
	static int res; // The resultant random number 
	static int count = 0; // Count of numbers visited 
						// so far in stream 

	count++; // increment count of numbers seen so far 

	// If this is the first element from stream, 
	// return it 
	if (count == 1) 
		res = x; 
	else
	{ 
		// Generate a random number from 0 to count - 1 
		int i = rand() % count; 

		// Replace the prev random number with 
		// new number with 1/count probability 
		if (i == count - 1) 
			res = x; 
	} 
	return res; 
} 

// Driver Code 
int main() 
{ 
	int stream[] = {1, 2, 3, 4}; 
	int n = sizeof(stream) / sizeof(stream[0]); 

	// Use a different seed value for every run. 
	srand(time(NULL)); 
	for (int i = 0; i < n; ++i) 
		cout << "Random number from first " << i + 1 
			<< " numbers is " << selectRandom(stream[i]) << endl; 
	return 0; 
} 

/*
How does this work
We need to prove that every element is picked with 1/n probability where n is the number of items seen so far. For every new stream item x, we pick a random number from 0 to ‘count -1’, if the picked number is ‘count-1’, we replace the previous result with x.

To simplify proof, let us first consider the last element, the last element replaces the previously-stored result with 1/n probability. So the probability of getting the last element as the result is 1/n.

Let us now talk about the second last element. When the second last element processed the first time, the probability that it replaced the previous result is 1/(n-1). The probability that the previous result stays when the nth item is considered is (n-1)/n. So the probability that the second last element is picked in the last iteration is [1/(n-1)] * [(n-1)/n] which is 1/n.

Similarly, we can prove for third last element and others.*/
