#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
// Complete the pairs function below.
int pairs(int k, vector<int> arr) {
	
	if (arr.size() < 2)
		return 0; 
	
	int count = 0;
	sort(arr.begin(), arr.end());
	
	int i = 0;
	int j = 1; // arr.size() -1; 
	while (j < arr.size())
	{
		
		int diff = (arr[j] - arr[i]); 
		if (diff == k) {count++; j++;}
		else if (diff < k)
			j++;
		else
			i++;
	}
			
	return count;  
}

int main(void)
{
	vector<int>  arr{1, 5, 3, 4, 2};
	int k = 2; 
	
	cout << pairs(k, arr) << endl;
	
	vector<int> arr2{1, 3, 5, 8, 6, 4, 2};
	k = 2;
	
	cout << pairs(k, arr2) << endl;
	
	return 0;
}