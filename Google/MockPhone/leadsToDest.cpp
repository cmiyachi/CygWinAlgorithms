/*For the visited array, -1 means never processed, false is being analyzed, and true is that all routes from that nodes lead to the destination. This is to avoid re-processing portions of the graph. */

bool dfs(vector<vector<int>> &al, vector<int> &visited, int i, int dest) {
  if (al[i].empty()) return i == dest;
  if (visited[i] != -1) return visited[i];
  visited[i] = 0;
  for (auto j : al[i])
    if (!dfs(al, visited, j, dest)) return false;
  return visited[i] = true;
}
bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
  vector<vector<int>> al(n);
  vector<int> visited(n, -1);
  for (auto e : edges) al[e[0]].push_back(e[1]);
  return dfs(al, visited, source, destination);
}

/*If we can reach a cycle from the source We get trapped in that cycle forever.
image
In this example is we go from 0 to 1 then 1 and 2 will keep alternating between itself and will never reach the destination.
Note: Though we can reach from 0 to 3 the question ask all paths should lead me to the destination.

I will be taking a BFS approach to solve this.
I will record the indegrees of each node after building the graph.
To build a graph i use adjacencey list:-

        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
		}
Indegrees are the number of incoming edges to the graph.
I store the indegrees of each edge in a vector indegree(n).
So my code builds up to this:-

        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
After recording all of this info my next task is to push the source into my queue to perform the bfs.
While i am traversing through the nodes if a node conatins no neighbors that mean it has to be the destination. If it is not then return false aswe have reached a leaf node and there is no way to come back.
image

Here 1 is such an example.
Now the other caviat that I have to tackle is that if I were to reach a cycle fromt my source I will get stuck in that indefinetly so how do I tackle that?
indegree role will come here
If I visit a node I decrement the indegree by 1.
The way to detect a cycle is that if I were to keep exploring neighbors and decrement the neighbors indegree if I encounter a node with negative indegree it means i have visited this node more than I need to so it is a cycle.
I would suggest u guys to use this principle on this graph:-

image

If I dont have all of this issues I can safely assume all paths lead to the destination from the source.
Time Complexity - O(V+E)
Space Complexity - O(V)
*/

    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            if(graph[t].empty() && t!=destination)return false;
            for(int x:graph[t])
            {
                if(indegree[x]<0)return false;
                indegree[x]--;
                q.push(x);
            }
        }
        return true;
    }