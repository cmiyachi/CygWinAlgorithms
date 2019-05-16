#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;


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
    vector<vector<int>> combinationSumTop(vector<int>& candidates, int target) {
      vector<vector<int>> result;
      vector<int> combination;
      sort(candidates.begin(), candidates.end());
      combinationSumUtil(candidates, target, result, combination, 0);
      
      return result;
    }

std::string combinationSum(std::vector<int> a, int sum) {
	vector<vector<int>> result = combinationSumTop(a, sum);
	result.erase(std::unique(result.begin(), result.end()), result.end());
	string final = ""; 
	ostringstream str1; 
	if (result.size() == 0) return "Empty"; 
	
	for(int i=0;i<result.size();i++){
		str1 << "("; 
		for(int j=0;j<result[i].size();j++){
			//cout << result[i][j] << " ";
			str1 << result[i][j]; 
			if (j != (result[i].size()-1)) str1 << " ";
		}
		str1 << ")"; 
	//	cout << endl;
	}
	return str1.str(); 
}


int main(){
  vector<int> nums={2, 3, 6, 7};
  string result = combinationSum(nums, 7);
  cout << result << endl; ; 

  vector<int> nums2={1,2};
  result = combinationSum(nums2, 4);
  cout << result << endl;

  vector<int> nums3={4, 2, 8};
  result = combinationSum(nums3, 8);
  cout << result << endl; 
  
   vector<int> nums4={8, 1, 8, 6, 8};
  result = combinationSum(nums4, 12);
  cout << result << endl; 
}
