//Given an array of integers arr where each element is at most k places
//away from its sorted position, code an efficient function sortKMessedArray
//that sorts arr. For instance, for an input array of size 10 and k = 2
//an element belonging to index 6 in the sorted array will be located at
//either index 4, 5, 6, 7 or 8 in the input array.

//Time: O(n), Space: O(k) "Not considering the ans vector"

/* A simple solution would be to use an efficient sorting algorithm to sort the whole array again. The worst case time complexity of this
approach will be O(N⋅log(N)) where N is the size of the input array. This method also do not use the fact that array is k-sorted.
We can also use insertion sort that will correct the order in just O(N∙K) time. Insertion Sort performs really well for small values of k
but it is not recommended for large value of k (use it for k < 12).
However, we can do better than that. If we use min heap, we can get an asymptotically better time complexity. We can solve this problem in
O(N⋅log(K)). The idea is to construct a min-heap of size k+1 and insert first k+1 elements into the heap. Then we remove min from the heap
and insert next element from the array into the heap and continue the process until both array and heap are exhausted. Each pop operation
from the heap should insert the corresponding top element in its correct position in the array. */


#include <iostream>
#include <vector>
 #include <bits/stdc++.h>
 #include <queue>

using namespace std;

vector<int> sortKMessedArray( const vector<int>& arr, int k ){
    vector<int> results = arr; 
	for(int i = 1; i < arr.size(); i++) {
		int key = results[i];
		int j = i - 1;

		// Move elements of A[0...i - 1], that are greater than key, to one position ahead of their current position
		// This loop will run at most k times
		while(j >= 0 && results[j] > key) {
		  results[j + 1] = results[j];
		  j = j - 1;
		}
		results[j + 1] = key;
  }
  
  return results; 
}

int main() {
	// vector<int> arr = { 1, 4, 5, 2, 3, 7, 8, 6, 10, 9 };
	// int k = 2;
	vector<int> arr = { 6,1,4,11,2,0,3,7,10,5,8,9 };
  
  int k = 6;
	vector<int> results = sortKMessedArray(arr, k);
	
	for (int i = 0; i < results.size(); i++)
		cout << results[i] << " "; 
	return 0;
}