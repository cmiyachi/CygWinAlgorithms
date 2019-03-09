// Simple C++ program to find k'th smallest element 
#include<iostream> 
#include<algorithm> 
#include <vector>
using namespace std; 
  
// Function to return k'th smallest element in a given array 
int kthSmallest(vector<int> arr, int n, int k) 
{ 
    // Sort the given array 
    sort(arr.begin(), arr.end()); 
  
    // Return k'th element in the sorted array 
    return arr[k-1]; 
} 
  
int kthLargestElement(std::vector<int> nums, int k) {
	// Sort the given array 
    sort(nums.begin(), nums.end()); 
  
    // Return k'th element in the sorted array 
    return nums[nums.size() - k];

}
// Driver program to test above methods 
int main() 
{ 
    vector<int> arr{12, 3, 5, 7, 19}; 
    int n = arr.size(); 
	int k = 2; 
    cout << "K'th smallest element is " <<  kthLargestElement(arr, k) << endl; 
	
	vector<int> arr2{7, 6, 5, 4, 3, 2, 1};
	int k2 =2; 
	 cout << "K'th smallest element is " <<  kthLargestElement(arr2, k2) << endl; 
    return 0; 
} 