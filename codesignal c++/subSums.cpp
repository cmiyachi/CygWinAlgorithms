//to print sums of all subsets
#include<bits/stdc++.h>
using namespace std;

/* std::vector<std::vector<int>> sumSubsets(std::vector<int> arr, int num)
{
	int n = arr.size();
    long long total = 1<<n;
	vector<int> candidate;
	vector<vector<int>> result; 
    for (long long i=0; i<total; i++) {
        long long sum = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
			{
                sum += arr[j];
				candidate.push_back(arr[j]); 
			}
		if (sum == num)
		{
			// for (int k = 0; k < candidate.size(); k++)
			// 	cout <<  candidate[k] << " "; 
		     int k = 0;
			for ( k =0; k < result.size(); k++)
				if (result[k] == candidate) break; 
			
			if (k == (result.size()))
				result.push_back(candidate); 
        }
		candidate.clear(); 
		// cout<<endl;
    }
	
	sort(result.begin(), result.end()); 
	return result; 
    
} */
void findSubsets(vector<vector<int>> &results, vector<int> &temp, const vector<int> &arr,
                 const int order,const int target);
				 
std::vector<std::vector<int>> sumSubsets(std::vector<int> arr, int num) {
    vector<vector<int>> results;
    sort(arr.begin(),arr.end());
    vector<int> temp;        
    for(auto it:arr){cout<<it<<" ";}
    findSubsets(results,temp,arr,0,num);
    return results;
}

void findSubsets(vector<vector<int>> &results, vector<int> &temp, const vector<int> &arr,
                 const int order,const int target){    
    if(target==0){//<-------------------------------------------------------------------------------------------------------------->
        results.push_back(temp);
        return;
    }else{
        for(int j=order;j<arr.size();j++){
            if(arr[j]>target) return;
            if( j && arr[j-1]==arr[j] && j>order) continue;
            temp.push_back(arr[j]);
            findSubsets(results,temp,arr,j+1,target-arr[j]);
            temp.pop_back();
        }
    }
}                

int main() {
    vector<int> arr{1,2,2,3,4,5};
    vector<vector<int>> result = sumSubsets(arr, 5);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << ","; 
		cout << endl;
	}
			
    return 0;
}