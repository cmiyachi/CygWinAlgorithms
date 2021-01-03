#include <bits/stdc++.h>

using namespace std;


int  linearSearch(vector<int>& a, int key)
{
	int n = a.size();
	int pos = -1; 
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
			return i;
	}
	
	
	return -1; 
}
int main(void)
{
	
	int n; 
	
	cin >> n;
	
	vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	int key; 
	cout << "key" << endl; 
	cin >> key; 
	 int pos = linearSearch(a, key);
	
	cout << pos << endl; 
	
	return 0;
}