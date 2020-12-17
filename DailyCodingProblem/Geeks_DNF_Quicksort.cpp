// C++ program for 3-way quick sort
#include <bits/stdc++.h>
using namespace std;

/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */
void partition(int a[], int l, int r, int& i, int& j)
{
	i = l - 1, j = r;
	int p = l - 1, q = r;
	int v = a[r];

	while (true) {
		// From left, find the first element greater than
		// or equal to v. This loop will definitely
		// terminate as v is last element
		while (a[++i] < v)
			;

		// From right, find the first element smaller than
		// or equal to v
		while (v < a[--j])
			if (j == l)
				break;

		// If i and j cross, then we are done
		if (i >= j)
			break;

		// Swap, so that smaller goes on left greater goes
		// on right
		swap(a[i], a[j]);

		// Move all same left occurrence of pivot to
		// beginning of array and keep count using p
		if (a[i] == v) {
			p++;
			swap(a[p], a[i]);
		}

		// Move all same right occurrence of pivot to end of
		// array and keep count using q
		if (a[j] == v) {
			q--;
			swap(a[j], a[q]);
		}
	}

	// Move pivot element to its correct index
	swap(a[i], a[r]);

	// Move all left same occurrences from beginning
	// to adjacent to arr[i]
	j = i - 1;
	for (int k = l; k < p; k++, j--)
		swap(a[k], a[j]);

	// Move all right same occurrences from end
	// to adjacent to arr[i]
	i = i + 1;
	for (int k = r - 1; k > q; k--, i++)
		swap(a[i], a[k]);
}

// 3-way partition based quick sort
void quicksort(int a[], int l, int r)
{
	if (r <= l)
		return;

	int i, j;

	// Note that i and j are passed as reference
	partition(a, l, r, i, j);

	// Recur
	quicksort(a, l, j);
	quicksort(a, i, r);
}

// A utility function to print an array
void printarr(int a[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

// Driver code
int main()
{
	int a[] = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4 };
	int size = sizeof(a) / sizeof(int);

	// Function Call
	printarr(a, size);
	quicksort(a, 0, size - 1);
	printarr(a, size);
	return 0;
}
// C++ program to sort an array 
// with 0, 1 and 2 in a single pass 
#include <bits/stdc++.h> 
using namespace std; 

// Function to sort the input array, 
// the array is assumed 
// to have values in {0, 1, 2} 
void sort012(int a[], int arr_size) 
{ 
	int lo = 0; 
	int hi = arr_size - 1; 
	int mid = 0; 

	// Iterate till all the elements 
	// are sorted 
	while (mid <= hi) { 
		switch (a[mid]) { 

		// If the element is 0 
		case 0: 
			swap(a[lo++], a[mid++]); 
			break; 

		// If the element is 1 . 
		case 1: 
			mid++; 
			break; 

		// If the element is 2 
		case 2: 
			swap(a[mid], a[hi--]); 
			break; 
		} 
	} 
} 

// Function to print array arr[] 
void printArray(int arr[], int arr_size) 
{ 
	// Iterate and print every element 
	for (int i = 0; i < arr_size; i++) 
		cout << arr[i] << " "; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	sort012(arr, n); 

	cout << "array after segregation "; 

	printArray(arr, n); 

	return 0; 
} 

// This code is contributed by Shivi_Aggarwal 
// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Utility function to print the contents of an array 
void printArr(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

// Function to sort the array of 0s, 1s and 2s 
void sortArr(int arr[], int n) 
{ 
	int i, cnt0 = 0, cnt1 = 0, cnt2 = 0; 

	// Count the number of 0s, 1s and 2s in the array 
	for (i = 0; i < n; i++) { 
		switch (arr[i]) { 
		case 0: 
			cnt0++; 
			break; 
		case 1: 
			cnt1++; 
			break; 
		case 2: 
			cnt2++; 
			break; 
		} 
	} 

	// Update the array 
	i = 0; 

	// Store all the 0s in the beginning 
	while (cnt0 > 0) { 
		arr[i++] = 0; 
		cnt0--; 
	} 

	// Then all the 1s 
	while (cnt1 > 0) { 
		arr[i++] = 1; 
		cnt1--; 
	} 

	// Finally all the 2s 
	while (cnt2 > 0) { 
		arr[i++] = 2; 
		cnt2--; 
	} 

	// Print the sorted array 
	printArr(arr, n); 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
	int n = sizeof(arr) / sizeof(int); 

	sortArr(arr, n); 

	return 0; 
} 
