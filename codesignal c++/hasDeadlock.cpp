#include<iostream> 
#include <vector> 

using namespace std;
//basically the problem statement requires us to find if a graph contains cycles. below algorithm does it in O(V+E)

bool dfscycles(int i, int *visited, int *stack ,vector<vector<int>> &adj)
{
    if(!visited[i])
    {
        visited[i]=1;
        stack[i]=1;
        //if graph node is not visited, mark it as visited, visit its immediate adjacent node.
        //since it has other nodes (its a fucking adjacency list) we store the immediate node in a recursion stack.
        //could use a Red black tree to store visited with compromise in time complexity for lesser space.
        
        //use of visited array is for dfs keeping a list of what to traverse next, in O(1) time
        //use of stack is actual cycle detection, as for every node it checks if the immediate child is in stack, and therefore is a cycle
        
        vector<int>::iterator it;
        
        for(it=adj[i].begin();it!=adj[i].end();++it)
        {
            if(!visited[*it]&&dfscycles(*it,visited,stack,adj))
                return true;
            else if (stack[*it])
                return true;
        }
    }
    stack[i]=0;
    return false;
}
bool hasDeadlock(std::vector<std::vector<int>> connections) {
    int V=connections.size();
    int visited[V]={0};
    int stack[V]={0};
    for(int i=0;i<V;i++)
    {
        if(dfscycles(i,visited,stack,connections))
            return true;
    }
    return false;
}

int main()
{
	vector<vector<int>> connections = {{1}, {2}, {3, 4}, {4}, {0}}; 
	cout << hasDeadlock(connections); 
	return 0;
}