class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        
        int count = 0;
        vector<vector<pair<int,bool>>> path(n);// false means path directed away from a to b
        for(int i=0;i<connections.size();i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            path[a].push_back({b,true});
            path[b].push_back({a,false});
        }
        
        int start = 0;
        
        queue<int> q;
        //bool visited[n] = {false};
        vector<bool> visited(n,false);
        q.push(start);
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            if(!visited[top]) visited[top] = true;
            for(auto ele : path[top])
            {
                int node = ele.first;
                if(!visited[node] && ele.second) count++;
                if(!visited[node]) q.push(node);
                
            }
            
        }
        
        return count;
    }
};