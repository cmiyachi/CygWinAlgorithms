///https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <bits/stdc++.h>
using namespace std;


class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int idx1 = lower_bound(nums, target);
    int idx2 = lower_bound(nums, target+1)-1;
    if (idx1 < nums.size() && nums[idx1] == target)
        return {idx1, idx2};
    else
        return {-1, -1};
}

int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}
};
class Solution {
public:
    
    /* int getFirst(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;  /// (s+e)/2
            
            if(nums[mid]==target){
                ans = mid;
                e = mid -1 ; /// LHS for first pos
                ///return mid;
            } else if(nums[mid] < target){
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
    
    int getLast(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;  /// (s+e)/2
            
            if(nums[mid]==target){
                ans = mid;
                s = mid + 1 ; /// RHS for last pos
                ///return mid;
            } else if(nums[mid] < target){
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
    */
    int getIndex(vector<int>& nums, int target, bool getFirst){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;  /// (s+e)/2
            
            if(nums[mid]==target){
                ans = mid;
                if(getFirst) {
                    e = mid -1 ;    /// LHS for first
                } else  {
                    s = mid +1 ;     /// RHS for last
                }
                ///return mid;
            } else if(nums[mid] < target){
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
          vector<int> v(2,-1);  
          int first = getIndex(nums,target,true);
          if(first == -1){
              return v;
          }
          int last = getIndex(nums,target,false);
        
          v[0] = first;
          v[1] = last;
        return v;
        
    }
};

int main(void)
{
	vector<int> nums{5,7,7,8,8,10};
	Solution sol;
	
	vector<int> result = sol.searchRange(nums,10);
	for ( int x : result)
		cout << x << " ";
		
	return 0;
}