class Solution {
public:
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

};

class Solution {
public:
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
};