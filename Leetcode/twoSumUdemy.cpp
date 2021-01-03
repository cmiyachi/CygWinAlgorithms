/// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        vector<int> ans;
        unordered_map<int,int> mymap;
        
        for(int i=0;i<A.size();i++){
            int search = target - A[i];
            
            if(mymap.find(search) == mymap.end()){
                mymap[A[i]] = i;
            }else{
                /// search value is present 
                ans.push_back(mymap[search]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};

// O(n) for space and time

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result; 
		map<int,int>  num_map; 
		
		for (int i = 0; i < nums.size(); i++)
		{
			int complement = target - nums[i]; 
			if (num_map.find(complement) != num_map.end())
			{
				result.push_back(num_map[complement]);
				result.push_back(i);
				return result; 
			}
			num_map[nums[i]] = i; 
		} // for
        
        return result; 
        
    }
};