#include <bits/stdc++.h>

using namespace std;


// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
int bfs(unordered_map<int, vector<int>> &graph, vector<long> &ids, int src, int val) {
    unordered_map<int, int> dist; // id -> dist from src
    queue<int> q;
    
    dist[src] = 0;
    q.push(src);
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();

        for (int next : graph[curr]) {
            if (dist.find(next) != dist.end()) continue;            
            dist[next] = dist[curr] + 1;
            q.push(next);

            if (ids[next - 1] == val) {
                return dist[next];
            }
        }
    }
    return INT_MAX;
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    unordered_map<int,vector<int>> graph;        

    for (int i = 1; i <= graph_nodes; ++i) {
        graph[i] = {};
    }
    for (int i = 0; i < graph_from.size(); ++i) {
        int from = graph_from[i];
        int to = graph_to[i];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    int min_dist = INT_MAX;
    for (auto it = graph.begin(); it != graph.end(); ++it) {
        int src = it->first;
        if (ids[src - 1] != val) continue;

        int dist = bfs(graph, ids, src, val);
        min_dist = min(dist, min_dist);
    }
    return (min_dist == INT_MAX) ? -1 : min_dist;    
}

void test_case_1() {
    vector<int> graph_from = {4,1,1,4};
    vector<int> graph_to = {3,2,3,2};
    vector<long> ids= {1, 2, 1, 1};
    int val = 1;
    int graph_nodes = 4;
    int result = findShortest( graph_nodes, graph_from,  graph_to,  ids,  val);
    
    cout << "TEST 1: " << result << endl;
    
    
    
}


void test_case_2() {
    vector<int> graph_from = {5,1,1,2,3};
    vector<int> graph_to =   {4,2,3,4,5};
    vector<long> ids= {1, 2, 3, 3, 2};
    int val = 2;
    int graph_nodes = 5;
    int result = findShortest( graph_nodes, graph_from,  graph_to,  ids,  val);
    
    cout << "TEST 2: " << result << endl;
    
    
    
}


int main(void) {
    // insert code here...
   // std::cout << "Hello, World!\n";
    test_case_1();
    test_case_2();
    
    return 0;
}
