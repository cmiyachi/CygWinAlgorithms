// problem link : https://codefights.com/interview-practice/task/cAXEnPyzknC5zgd7x
// solution by : youssef_ali
// codefights profile : https://codefights.com/profile/youssef_ali
#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, int curr); 

vector<vector<int>> sols;
int sol[11];


vector<vector<int>> climbingStaircase(int n, int k) {
    solve(n,k,0);
    return sols;
}

void solve(int n, int k, int curr){
    if(n < 0) return;
    if(n == 0){
        vector<int> tmp;
		/* for (int j =0; j < 11; j++)
			cout << "sol " << sol[j]; 
		cout << endl; */
        for(int i = 0; i < 11; i++) if(sol[i] != 0)
            tmp.push_back(sol[i]);
        sols.push_back(tmp);
        return;
    }
    for(int i = 1; i <= k; i++){
        sol[curr] = i;
        solve(n - i, k, curr+1);
		//cout << "curr " << curr << " i " << i << endl;
        sol[curr] = 0;
    }
}

int main(void)
{
	vector<vector<int>> results = climbingStaircase(4,2);
	
	for (int i = 0; i < results.size(); i++)
	{
		int sollength = results[i].size(); 
		for (int j = 0; j < sollength; j++)
			cout << results[i][j] << " ";
		cout << endl;
	}
	return 0;
}