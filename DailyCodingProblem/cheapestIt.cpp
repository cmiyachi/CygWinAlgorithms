#include <bits/stdc++.h> 
using namespace std; 


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> graph(n); //pair<weight,node>
        
        for(auto node : flights){
           graph[node[0]].push_back(make_pair(node[2],node[1])); 
        }
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minH;
        
        minH.push({0,src,K});
        
        while(!minH.empty()){
            vector<int> currNodeData=minH.top();
            minH.pop();
            
            int currNWeight=currNodeData[0];
            int currNode=currNodeData[1];
            int hopsYet=currNodeData[2];
            
            if(currNode==dst){
                return currNWeight;
            }
            if(hopsYet>=0){
                for(auto nbr : graph[currNode]){
                    int node=nbr.second;
                    int weight=nbr.first;
                    
                    minH.push({currNWeight+weight,node,hopsYet-1});
                      
                }
            }
                
        }
        
        return -1;
    }
};

int main(void)
{
	int n = 7;
	vector<vector<int>> edges = {{0,1,150},{1,2,400},{3,4,200},{4,5,80},{0,6,800},{1,3,90},{0,4,500}};
	int start = 0, end = 4; 
	
	Solution sol;
	
	cout << sol.findCheapestPrice(n,edges, start, end, 3);
	
	return 0;
}