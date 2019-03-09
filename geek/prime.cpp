#include <iostream>
using namespace std;
#include <vector> 

bool prime(int n)
{
	if (n <=1) return false;
	if (n <=3) return true; 
	
	if (n%2 ==0 || n%3 == 0) return false; 
	
	for (int i = 5; i*i <=n; i = i + 6)
		if (n%i == 0 || n%(i+2) == 0)
			return false; 
	
	return true;
}

int main() {
	//code
	int  testcases;
	cin >> testcases;
	vector<bool> results;
	int n; 
	
	for (int i = 0; i < testcases; i++)
	{
		cin >> n;
		results.push_back(prime(n)); 
	}
	
	
	for (int j = 0; j < results.size(); j++)
		cout << (results[j] ? "Yes": "No") <<endl; 
	
	return 0;
}