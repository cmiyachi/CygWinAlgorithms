#include <vector>
using namespace std;

void helper(vector<int> &array, int start, int end); 

vector<int> quickSort(vector<int> array) {
  // Write your code here.
	helper(array, 0, array.size()-1);
	return array;
}

void helper(vector<int> &array, int start, int end)
{
	if (start >= end) return; 
	
	int pivot = start; 
	int left = start+1; 
	int right = end; 
	while (right >= left)
	{
		if (array[left] > array[pivot] &&
			array[right] < array[pivot])
			swap(array[left], array[right]); 
		if (array[left] <= array[pivot])
			left++; 
		if (array[right] >= array[pivot])
			right--; 
	}
	swap(array[pivot], array[right]); 
}
