/*
https://www.geeksforgeeks.org/finding-the-probability-of-a-state-at-a-given-time-in-a-markov-chain-set-2/
*/
// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Macro to define a vector of float 
#define vf vector<float> 

// Function to multiply two matrices A and B 
vector<vf > multiply(vector<vf > A, vector<vf > B, int N) 
{ 
	vector<vf > C(N, vf(N, 0)); 
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) 
			for (int k = 0; k < N; ++k) 
				C[i][j] += A[i][k] * B[k][j]; 
	return C; 
} 

// Function to calculate the power of a matrix 
vector<vf > matrix_power(vector<vf > M, int p, int n) 
{ 
	vector<vf > A(n, vf(n, 0)); 
	for (int i = 0; i < n; ++i) 
		A[i][i] = 1; 

	while (p) { 
		if (p % 2) 
			A = multiply(A, M, n); 
		M = multiply(M, M, n); 
		p /= 2; 
	} 

	return A; 
} 

// Function to calculate the probability of 
// reaching F at time T after starting from S 
float findProbability(vector<vf > M, int N, int F, 
										int S, int T) 
{ 
	// Storing M^T in MT 
	vector<vf > MT = matrix_power(M, T, N); 

	// Returning the answer 
	return MT[F - 1][S - 1]; 
} 

// Driver code 
int main() 
{ 
	// Adjacency matrix 
	// The edges have been stored in the row 
	// corresponding to their end-point 
	vector<vf > G{ { 0, 0.09, 0, 0, 0, 0 }, 
				{ 0.23, 0, 0, 0, 0, 0.62 }, 
				{ 0, 0.06, 0, 0, 0, 0 }, 
				{ 0.77, 0, 0.63, 0, 0, 0 }, 
				{ 0, 0, 0, 0.65, 0, 0.38 }, 
				{ 0, 0.85, 0.37, 0.35, 1.0, 0 }}; 

	// N is the number of states 
	int N = 6; 
	
	int S = 4, F = 2, T = 100; 

	cout << "The probability of reaching " << F << " at time "
				<< T << "\nafter starting from " << S << " is "
				<< findProbability(G, N, F, S, T); 

	return 0; 
} 
