#include <bits/stdc++.h> 
using namespace std; 

void selectionSort(int a[], int n)
{
	 for (int i = 0; i < n-2; i++)
	 {
		 int small_index = i;  
		 for (int j = i+1; j <=n-1; j++)
		 {
			 if (a[j]< a[small_index])
			 {
				small_index = j; 
			 }
		 }
		 
		 if (a[i] > a[small_index])
			swap(a[i], a[small_index]);  
	 }
	
}

int main(void)
{
	int n; 
	cin >> n;
	
	int a[n];
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	selectionSort(a, n);
	
	for (int i = 0; i < n; i++)
		cout << a[i] << " "; 
	return 0;
}