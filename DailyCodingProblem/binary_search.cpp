#include <bits/stdc++.h> 
using namespace std; 
int helper(vector<int> array, int target, int left, int right);

int binarySearch(vector<int> array, int target) {
  return helper(array, target, 0, array.size()-1);
}

int helper(vector<int> array, int target, int left, int right)
{
	if (left > right) return -1; 
	
	int middle = (right + left)/2; 
	int match = array[middle]; 
	if (target == match) return middle; 
	else if (target < array[middle])
		return helper(array, target, left, middle -1);
	else 
		return helper(array, target, middle+1, right); 
}

int main(void)
{
	vector<int> array1{4,5,6,15,29,65,88,99,190,250,300};
	
	int target = 15; 
	
	cout << binarySearch(array1, target);  
	
	return 0;
}