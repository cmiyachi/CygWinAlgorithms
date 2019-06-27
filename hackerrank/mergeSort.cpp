#include<bits/stdc++.h>
using namespace std; 

vector<int> mergeArrays(vector<int> arr1, vector<int> arr2) 
{ 
	int i = 0, j = 0, k = 0; 
	int n1 = arr1.size();
	int n2 = arr2.size();
	vector<int> result(n1+n2); 

	
	while (i<n1 && j <n2) 
	{ 
		if (arr1[i] < arr2[j]) 
			result[k++] = arr1[i++]; 
		else
			result[k++] = arr2[j++]; 
	} 

	while (i < n1) 
		result[k++] = arr1[i++]; 
	
	while (j < n2) 
		result[k++] = arr2[j++]; 
} 

int main() 
{ 
	int no_lists; 
	cin >> no_lists; 
	int no_elements; 
	vector<int> a, b; 
	int x; 
	
	vector<int>  mergeList; 
	 
	
	cin >> no_elements; 
	
	for (int i = 0; i < no_elements; i++)
	{
		cin >> x; 
		a.push_back(x); 
	}
		
	for (int i = 1; i < no_lists; i++)
	{
		cin >> no_elements;
		
		for (int j = 0; j< no_elements; j++)
		{
			cin >> x; 
			b.push_back(x);
		}
		
		a = mergeArrays(a,b); 
		
	}
	
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << ","; 
	}
		/* cin >> 
	
	int arr1[] = {1, 3, 5, 7}; 
	int n1 = sizeof(arr1) / sizeof(arr1[0]); 

	int arr2[] = {2, 4, 6, 8}; 
	int n2 = sizeof(arr2) / sizeof(arr2[0]); 

	int arr3[n1+n2]; 
	mergeArrays(arr1, arr2, n1, n2, arr3); 

	cout << "Array after merging" <<endl; 
	for (int i=0; i < n1+n2; i++) 
		cout << arr3[i] << " ";  */

	return 0; 
} 
