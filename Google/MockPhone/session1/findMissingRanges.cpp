class Solution {
public:
    string getRange(int start, int end){
        return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        long int pre = (long) lower - 1;
        
        for(int i = 0; i <= nums.size(); i++){
            long int cur = i == nums.size() ? (long) upper+1 : (long) nums[i];
            if(cur - pre >= 2)
                result.push_back(getRange(pre+1, cur-1));
            pre = cur;
            
        }
        
        return result;
    }
};