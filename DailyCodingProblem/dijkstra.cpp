#include <bits/stdc++.h>
using namespace std;


tuple <int, int> getVertexWithMinDist(vector<int> distances,
																		 set<int> visited);

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
  // Write your code here;
	int num_vert = edges.size(); 
	vector<int>  minDist(edges.size(),INT_MAX);
	minDist[start] = 0; 
	
	set<int> visited;
	
	while (visited.size() != num_vert)
	{
		auto [vertex, curr_min] = getVertexWithMinDist(minDist, visited);
		if (curr_min == INT_MAX)
			break;
		
		visited.insert(vertex); 
		
		for (auto edge :edges[vertex])
		{
			auto dest = edge[0];
			auto dist_to_dest = edge[1]; 
			
			if (visited.find(dest) != visited.end())
				continue; 
			
			auto newPathDist = curr_min + dist_to_dest; 
			auto curr_dest_dist = minDist[dest]; 
			if (newPathDist < curr_dest_dist)
				minDist[dest] = newPathDist; 
		}
	}
	
	vector<int> finalDist; 
	for (auto distance : minDist)
	{
		if (distance == INT_MAX)
			finalDist.push_back(-1);
		else
			finalDist.push_back(distance);
		
	}
  return finalDist; 
}

tuple <int, int> getVertexWithMinDist(vector<int> distances,
																		 set<int> visited)
{
	int curr_min = INT_MAX;
	int vertex = -1;
	for (int i = 0; i < distances.size(); i++)
	{
		int distance = distances[i]; 
		if (visited.find(i) != visited.end())
			continue;
		
		if (distance <= curr_min)
		{
			vertex = i;
			curr_min = distance; 
		}
	}
	
	return {vertex, curr_min}; 
}

int main(void)
{
	vector<vector<vector<int>>> data{{{1,5},{2,3},{5,4}},{{3,8}},{{3,1}},{{5,10},{4,5}},{},{}};
	
	vector<int> result = dijkstrasAlgorithm(0,data);
	
	for (int r : result)
		cout << r << "->";
		
		
	
	return 0;
}