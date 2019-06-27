// C++ program for count in C++ STL for 
// array 
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	int size;
	cin >> size;
	vector<int>  arr; 
	vector<int> seen; 
	int x; 
	for (int i = 0; i < size; i++)
	{
		cin >> x; 
		arr.push_back(x);
	}

	int firsttime = 0; 
	sort(arr.begin(), arr.end()); 
	
	for (int i = 0 ; i < size; i++)
	{
		if (find(seen.begin(), seen.end(), arr[i]) != seen.end()) continue; 
		int num = count(arr.begin(), arr.end(), arr[i]); 
		if (num > 1)
		{
			if (firsttime == 0) 	firsttime = 1;
			else cout << ","; 
			cout << "(" << arr[i] << "," << num << ")";
			seen.push_back(arr[i]); 
		}
	}

	return 0; 
} 
