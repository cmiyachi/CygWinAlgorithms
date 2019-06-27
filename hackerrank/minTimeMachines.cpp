/* Enter your code here. Read input from STDIN. Print output to STDOUT *//* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;

struct edge{
    int from;
    int to;
    int w;
};

bool comp(edge e1, edge e2){
   return e1.w > e2.w;
}

int find(vector<int> &parent, int x){
    while (x != parent[x]){
        parent[x]= find(parent, parent[x]);
        x = parent[x];
    }
    return parent[x];
}

bool check(vector<int> &parent, int u, int v){
    return (find(parent, u) == find(parent, v));
}    

void join(vector<int> &parent, int u, int v) {
    u = find(parent, u);
    v = find(parent, v);
    parent[v] = u;
}

int defend_cost(int n, int k, vector<edge> E, vector<bool> M){
    vector<int> parent(n);
    FOR(i, n) parent[i] = i;
    
    sort(E.begin(), E.end(),comp);
    
    int cost = 0;
    FOR(i, n-1){
        edge e = E[i];
        //cout << e.from << " - " << e.to << endl;
        int u = find(parent, e.from);
        int v = find(parent, e.to);
        if (M[u] && M[v]){
            cost += e.w;
        } else if (M[u] && !M[v]) {
            join(parent, e.from, e.to);
        } else {
            join(parent, e.to, e.from);
        } 
    }
    return cost;   
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<edge> E(n-1);
    vector<bool> M(n);   
    
    FOR(i, n-1){
        edge e;
        cin >> e.from >> e.to >> e.w;
        E[i] = e;
    }
    FOR(i, n) M[i] = false;
    FOR(i, k){
        int l;
        cin >> l;
        M[l] = true;            
    }
    cout << defend_cost(n, k, E, M);
}