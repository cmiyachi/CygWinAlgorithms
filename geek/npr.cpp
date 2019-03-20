#include <iostream>
#include <vector> 
using namespace std;

long fact(long n) 
{ 
	if (n <= 1) 
		return 1; 
	return n*fact(n-1); 
} 

long nPr(long n, long r) 
{ 
	return fact(n)/fact(n-r); 
} 

int main() 
{ 

	//code
	int  testcases;
	cin >> testcases;
	vector<long> results;
	long n,r; 
	
	for (int i = 0; i < testcases; i++)
	{
		cin >> n;
		cin >> r; 
		results.push_back(nPr(n,r)); 
	}
	
	
	for (int j = 0; j < results.size(); j++)
		cout << (results[j]) <<endl; 
	
	return 0;
}
