#include <bits/stdc++.h>
	
using namespace std;

class Solution {
    vector<vector<int>> g, ret;
    vector<int> dfn, low;
    int timestamp = 0;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn = vector<int>(n);
        low = vector<int>(n);
        g.resize(n);
        for(auto& c: connections) {
            int u = c[0], v = c[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        return ret;
    }
    
    void dfs(int cur, int pre) {
        if(dfn[cur] > 0) 
            return;
        dfn[cur] = low[cur] = ++timestamp;
        for(int next: g[cur]) {
            if(next == pre) {
                continue;
            }
            dfs(next, cur);
            low[cur] = min(low[cur], low[next]);
            if(low[next] > dfn[cur]) {
                ret.push_back({cur, next});
            }
        }
    }
};

int main(void)
{
	int n = 4;
	vector<vector<int>> connections{{0,1},{1,2},{2,0},{1,3}};
	
	Solution sol;
	
	vector<vector<int>> result = sol.criticalConnections(n, connections);
	
	vector< vector<int> >::iterator row;
	vector<int>::iterator col;
	
	for (row = result.begin(); row != result.end(); row++) {
		for (col = row->begin(); col != row->end(); col++) {
			cout << *col << endl;
		}
	}
	
	/* for (int i = 0; i < result.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < result[i].size(); i++)
			cout << result[i][j] << ",";
		cout << "] " << endl;
	} */

	return 0;
}