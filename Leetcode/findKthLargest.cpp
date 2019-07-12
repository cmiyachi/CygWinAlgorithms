#include <bits/stdc++.h> 
using namespace std;

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Sort the given array 
    sort(nums.begin(), nums.end()); 
  
    // Return k'th element in the sorted array 
    return nums[nums.size() - k];
        
    }
};

/*
class Solution {
    public int findKthLargest(int[] nums, int k) {
        // init heap 'the smallest element first'
        PriorityQueue<Integer> heap =
            new PriorityQueue<Integer>((n1, n2) -> n1 - n2);

        // keep k largest elements in the heap
        for (int n: nums) {
          heap.add(n);
          if (heap.size() > k)
            heap.poll();
        }

        // output
        return heap.poll();        
  }
}*/ 

class Solution {
public:
 int findKthLargest(vector<int>& nums, int k) 
	{
		priority_queue<int, vector<int>, greater<int> > min_heap;
		
		// keep k largest elements in the heap
		for (auto n: nums)
		{
			min_heap.push(n); 
			if (min_heap.size() > k)
				min_heap.pop(); 
			
		}// for
		
		return min_heap.top(); 
	}
};

int main(void)
{
	Solution sol; 
	vector<int> arr{12, 3, 5, 7, 19}; 
	int n = arr.size(); 
	int k = 2; 
	cout << "K'th largest element is " <<  sol.findKthLargest(arr, k) << endl; 
	
	vector<int> arr2{7, 6, 5, 4, 3, 2, 1};
	int k2 =2; 
	 cout << "K'th largest element is " <<  sol. findKthLargest(arr2, k2) << endl; 
	return 0; 
}