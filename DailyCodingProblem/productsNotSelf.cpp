#include <bits/stdc++.h>
	
using namespace std;

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

int main(void)
{
	vector<int> num1{1,2,3,4,5};
	Solution sol;
	vector<int> result = sol.productExceptSelf(num1);
	for (auto& it :result)
		cout << it << " ";
	cout << endl; 
	
	return 0;
}