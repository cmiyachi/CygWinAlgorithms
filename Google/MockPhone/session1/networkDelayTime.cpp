/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:



Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

*/ 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};

typedef pair<int, int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> g[n + 1];
        for (const auto& t : times) {
            g[t[0]].push_back(make_pair(t[1], t[2]));
        }
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push(make_pair(0, k));
        int u, v, w;
        while (!pq.empty()) {
            pii p = pq.top(); pq.pop();
            u = p.second;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace_back(dist[v], v);
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
    }
};

public int networkDelayTime(int[][] times, int N, int K) {
    if (times == null || times.length == 0) {
        return -1;
    }

    /* Subproblem: dp(i) represents minimum distance from K to i (iteratively update dp(i) when we find another shorter distance from K to i)*/
    int[] dp = new int[N + 1];

    /* Base case 1: initialize MAX value as initial minimum distance from K to every point*/
    /* Base case 2: initialize 0 as min distance to K itself*/
    for (int i = 0; i < N + 1; i++) {
        dp[i] = Integer.MAX_VALUE;
    }
    dp[K] = 0;

    /* traverse all destinations*/
    for (int i = 0; i < N; i++) {
        for (int[] edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];

            /* if dp[u] (starting point of current edge) has already been visited, and new distance from u to v is smaller than previous saved distance
            we should update minimum distance from u to v*/
            if (dp[u] != Integer.MAX_VALUE && dp[v] > dp[u] + w) {
                dp[v] = dp[u] + w;
            }
        }
    }

    /* after getting minimum distance (travel time) to all points, we should retrieve the max distance from these minimum distance, 
     * to ensure that we can travel all points in a specific travel time
    */
    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = Math.max(result, dp[i]);
    }
    /* if we do not visit all points, we should return -1*/
    return result == Integer.MAX_VALUE ? -1 : result;
}            



/* C++ program to solve Network Delay time problem
Problem Statement - https://leetcode.com/problems/network-delay-time/
*/

#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<pair<int, int>> adj_list[N+1];
    for(int i = 0; i<times.size(); i++){
        adj_list[times[i][0]].push_back({times[i][1], times[i][2]});
    }
    set<pair<int, int>> s;
    s.insert({0, K});
    vector<int> dist(N+1, INT_MAX);
    dist[K] = 0;
    while(!s.empty()){
        pair<int, int> temp = *(s.begin());
        int wt = temp.first;
        int u = temp.second;
        s.erase(s.begin());
        for(int i = 0; i<adj_list[u].size(); i++){
            int v = adj_list[u][i].first;
            int weight = adj_list[u][i].second;
            if(dist[v]>dist[u]+weight){
                if(dist[v]!= INT_MAX)
                    s.erase(s.find({dist[v], v}));
                dist[v] = dist[u] + weight;
                s.insert({dist[v], v});
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 1; i<=N; i++){
        ans = max(ans, dist[i]);
    }
    return (ans == INT_MAX) ? -1 : ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
	int N = 4, K = 2;
	cout<<networkDelayTime(times, N, K)<<endl;
	return 0;
}




int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<int> dist(N+1, INT_MAX);
    
    dist[K] =0;
    
    for(int i =1; i<N+1; i++){
        for(auto edge : times){
            int u=edge[0], v=edge[1], w=edge[2];
            
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
            }
        }
    }
    
    sort(dist.begin(), dist.end());
    if(dist[N-1]!= INT_MAX)
        return dist[N-1];
    else
        return -1;
    
    
    
}
