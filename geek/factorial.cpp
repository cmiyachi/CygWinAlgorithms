#include <iostream>
using namespace std;
#include <vector> 

/* int factorial(int n)
{
	if (n ==1)
		return 1;
	
	return n*factorial(n-1);
} */

long factorial(long n)
{
	long result=1;
	
	for (int i = 2; i <= n; i++)
	{
		result *= i;
	}
	
	return result; 
}
int main() {
	//code
	int  testcases;
	cin >> testcases;
	vector<long> results;
	int n; 
	
	for (int i = 0; i < testcases; i++)
	{
		cin >> n;
		results.push_back(factorial(n)); 
	}
	
	
	for (int j = 0; j < results.size(); j++)
		cout << results[j] <<endl; 
	return 0;
}