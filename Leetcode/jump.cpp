/// https://leetcode.com/problems/jump-game-ii/

#include <bits/stdc++.h> 
using namespace std; 
// Greedy, \mathcal{O}(N)O(N) time and \mathcal{O}(1)O(1) space.
class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size();
        if(n==1) return 0;
        if(A[0]==0) return -1;
        
        int ladder = A[0];    /// biggest ladder/ max reachable Index
        int stair = A[0];     /// current ladder
        int jump = 1;
        
        for(int i=1;i<n;i++){
            if(i==n-1) return jump;
            
            if(i+A[i] > ladder){
                ladder = i + A[i];
            }
            
            stair--; /// traversing current ladder
            
            if(stair==0){    // current ladder finished
                jump++;
                if(i>=ladder) return -1;
                stair = ladder - i;
               // if(stair<=0) return -1;
            }
        }
        
        return -1;
    }
};

int main(void)
{
	vector<int> nums{2,3,1,1,4};
	Solution sol;
	
	cout << sol.jump(nums) << endl;
	
	return 0;
}