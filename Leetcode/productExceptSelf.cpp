#include <bits/stdc++.h> 
using namespace std; 

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
		vector<int> result(n); 
		for (int i = 0; i < n; i++)
		{
			int product = 1; 
			for (int j = 0; j < n; j++)
				if (i != j) product *= nums[j]; 
			result[i] = product; 
		}
		return result; 
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int length = nums.size(); 
		vector<int> answer(length); 
		
		answer[0] = 1; 
		
		 for (int i = 1; i < length; i++) {

            // answer[i - 1] already contains the product of elements to the left of 'i - 1'
            // Simply multiplying it with nums[i - 1] would give the product of all 
            // elements to the left of index 'i'
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to the right,
        // so the R would be 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {

            // For the index 'i', R would contain the 
            // product of all elements to the right. We update R accordingly
            answer[i] = answer[i] * R;
            R *= nums[i];
        }

        return answer;
        
    }
};

class SolutionNSpace {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		
		int length = nums.size();
		
		vector<int> L(length); 
		vector<int> R(length); 
		vector<int> answer(length); 
		L[0] = 1; R[length-1] = 1; 
		for (int i = 1; i < length; i++) {

            // L[i - 1] already contains the product of elements to the left of 'i - 1'
            // Simply multiplying it with nums[i - 1] would give the product of all
            // elements to the left of index 'i'
            L[i] = nums[i - 1] * L[i - 1];
        }
        for (int i = length - 2; i >= 0; i--) {

            // R[i + 1] already contains the product of elements to the right of 'i + 1'
            // Simply multiplying it with nums[i + 1] would give the product of all
            // elements to the right of index 'i'
            R[i] = nums[i + 1] * R[i + 1];
        }
		
		for (int i = 0; i < length; i++) {
            // For the first element, R[i] would be product except self
            // For the last element of the array, product except self would be L[i]
            // Else, multiple product of all elements to the left and to the right
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};


int main(void)
{
	vector<int> nums{1,2,3,4}; 
	Solution sol;
	
	vector<int> result = sol.productExceptSelf(nums); 
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ", ";
	
	return 0; 
}