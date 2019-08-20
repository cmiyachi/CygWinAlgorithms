// A C program to count number of ways to reach n't stair when 
// a person can climb either 1 or 2 stairs at a time 
#include<stdio.h> 

// A recursive function used by countWays 
int countWaysUtil(int n, int m) 
{ 
	if (n <= 1) 
		return n; 
	int res = 0; 
	for (int i = 1; i<=m && i<=n; i++) 
		res += countWaysUtil(n-i, m); 
	return res; 
} 

// Returns number of ways to reach s'th stair 
int countWays(int s, int m) 
{ 
	return countWaysUtil(s+1, m); 
} 

// Driver program to test above functions- 
int main () 
{ 
	int s = 4, m = 2; 
	printf("Nuber of ways = %d", countWays(s, m)); 
	return 0; 
} 
