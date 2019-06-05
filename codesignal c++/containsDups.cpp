#include <bits/stdc++.h>

using namespace std;

bool containsDuplicates(std::vector<int> a) {
	map<int,int> dups; 
	
	for (int i = 0; i < a.size(); i++)
	{
		dups[a[i]]++;
		if (dups[a[i]] > 1) return true; 
		
	}
	return false; 
}

int main(void)
{
	vector<int> a{1, 2, 3, 1};
	
	cout << containsDuplicates(a); 
	
	vector<int> b{1,3};
	
	cout << endl << containsDuplicates(b);
	
	return 0;
}