// Task: Given the (undirected) edge list of a tree and the number of vertices n, find the length of longest path in the tree
//
// Solution: Starting at any vertex v_1 find the vertex v_2 furthest away from it. Then find
// the vertex v_3 that is furthest away from v_2. The length of the path from v_2 to v_3 is the
// diameter of the tree
//
// We do this recursively with a depth first search
//
// Example: Given n = 10, and tree = [[2, 5], [5, 7], [5, 1], [1, 9], [1, 0], [7, 6], [6, 3], [3, 8], [8, 4]]
//			the function should return 7

#include <iostream>
#include <vector>
#include <set>

// Depth first search
void findFurthestVertex(std::vector<std::vector<int> >& graph,int curr_node, std::set<int>& visited, int dist, int& max_dist,int& targ);

// Finds diameter of tree on n vertices
int treeDiameter(int n, std::vector<std::vector<int> > tree);



void findFurthestVertex(std::vector<std::vector<int> >& graph,int curr_node, std::set<int>& visited, int dist, int& max_dist,int& targ)
{
    if(visited.insert(curr_node).second) // if it's the first time the node has been visited
	/*The single element versions (1) return a pair, with its member pair::first set to an iterator pointing to either the 
	newly inserted element or to the equivalent element already in the set. The pair::second element in the pair is set to 
	true if a new element was inserted or false if an equivalent element already existed.
	*/
    {
        ++dist;
        if(dist > max_dist)
        {
            targ = curr_node; 
            max_dist = dist;
        }
        for(int v : graph[curr_node]){findFurthestVertex(graph,v,visited,dist,max_dist,targ);}
    }
}

int treeDiameter(int n, std::vector<std::vector<int> > tree) {
    
    if(n == 1){return 0;}

    //Convert edge list into a list of vertices with their own list of edges
    std::vector<std::vector<int> > graph(n);
    for(std::vector<int> e : tree)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    int max_dist = 0;
    int targ; // keeps track of the node furthest from the start node
    std::set<int> visited;

    // Start at vertex 0, but the start vertex is arbitrary
    findFurthestVertex(graph,0,visited,-1,max_dist,targ);
    visited.clear();
    max_dist=0;

    // Use targ from above as the new start
    findFurthestVertex(graph,targ,visited,-1,max_dist,targ);
    
    return max_dist;
}

// One test case
int main(){

	int n = 10;
	std::vector<std::vector<int> > tree = { {2, 5}, {5, 7}, {5, 1}, {1, 9}, {1, 0}, {7, 6}, {6, 3}, {3, 8}, {8, 4} };

	std::cout << treeDiameter(n,tree) << std::endl;

	return 0;
}