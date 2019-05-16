#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    void combinationSumUtil(vector<int>& candidates, int target, 
                          vector<vector<int>>& result,
                          vector<int> &combination,
                          int start){
      if(target<0){
        return;
      }else if(target == 0){
        result.push_back(combination);
        return;
      }

      for(int i=start;i<candidates.size();i++){
        combination.push_back(candidates[i]);
        combinationSumUtil(candidates, target-candidates[i], result, combination, i);
        combination.pop_back();
      }
        
    }
    string combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> result;
      vector<int> combination;
      sort(candidates.begin(), candidates.end());
      combinationSumUtil(candidates, target, result, combination, 0);
      
	  cout << "Got here" << result.size() << endl;
	  string final = ""; 
	  for (int i = 0; i < result.size(); i++)
	  {
		  final = final + "("; 
		  for (int j = 0; j < result[i].size(); i++)
		  {
			  cout << i << " " << j << result[i][j] <<"..." ;
			final = final+to_string(result[i][j])+" ";
		  }
		  final = final + ")"; 
	  }
	  
	  return final; 
    }

};

int main(){
  Solution so;
  vector<int> nums={2, 3, 6, 7};
  string result = so.combinationSum(nums, 7);
  cout << result << endl; 
  

  vector<int> nums2={1,2};
  string result2 = so.combinationSum(nums2, 4);
  cout << result2 << endl; 
  

  vector<int> nums3={4, 2, 8};
  string result3 = so.combinationSum(nums3, 8);
  cout << result3 <<endl; 
  
}