/*The logic behind this problem is that we can finish all the courses if the topological order exists and topological order exist only if the graph is acyclic(i.e, it doesn't contain any cycles). So, if the graph is acyclic we can say topological cycle exists and we can finish all the courses otherwise not.
*/
class Solution {
    int cycle_start,cycle_end;
     vector<int> color;
public:
    bool dfs(int v, vector<vector<int>>&adj, vector<int>&color){
        color[v]=1;
        for(auto u:adj[v]){
            if(color[u]==0){
               if(dfs(u,adj,color))
                   return true;
            }
            else if(color[u]==1){
                cycle_start=u;
                cycle_end=v;
                return true;
            }
        }
        color[v]=2;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }
       
     color.assign(n,0);
        cycle_start=-1;
        for(int i=0;i<n;i++){
            if(color[i]==0 && dfs(i,adj,color))
                break;
        }
        if(cycle_start==-1)return true;
        return false;
    }
};

class Solution {
public:
    
    // Function to check for cycles (dfs approach)
    bool dfs(int u, vector<int> adj[], vector<bool> &visited, vector<bool> &ancestor){
        visited[u] = true;
        ancestor[u] = true;
        
        for(auto i: adj[u]){
            if(visited[i] && ancestor[i])
                return true;
            if(visited[i])
                continue;
            if(dfs(i, adj, visited, ancestor))
                return true;
        }
        ancestor[u] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj [numCourses];
        
        // Creating adjacency list according to dependencies
        for(auto vec: prerequisites){
            adj[vec[1]].push_back(vec[0]);
        }
        
        // visited is to check if the node is visited or not 
        // ancestor checks if the node we are currently visiting is an ancestor 
        // to that node
        vector<bool> visited (numCourses, false);
        vector<bool> ancestor (numCourses, false);
        
        // running loop and doing dfs to visit even non connected graphs
        for(int i=0; i<numCourses; i++){
            if(!visited[i])
                if(dfs(i, adj, visited, ancestor))
                    return false;
        }
        return true;
    }
};



class SolutionTimeLimit {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> courseDict; 
        
        for (auto relation:prerequisites) {
          // relation[0] depends on relation[1]
            courseDict[relation[1]].push_back(relation[0]);
        }

        vector<bool> path(numCourses);

        for (int currCourse = 0; currCourse < numCourses; ++currCourse) {
          if (isCyclic(currCourse, courseDict, path)) {
            return false;
          }
        }

        return true;
        
    }
    
    bool isCyclic(
      int  currCourse,
      unordered_map<int, vector<int>> courseDict,
      vector<bool>& path) {

            if (path[currCourse]) {
              // come across a previously visited node, i.e. detect the cycle
              return true;
            }

            // no following courses, no loop.
            if (courseDict[currCourse].size() == 0)
              return false;

            // before backtracking, mark the node in the path
            path[currCourse] = true;

            // backtracking
            bool ret = false;
            for (int nextCourse : courseDict[currCourse]) {
              ret = isCyclic(nextCourse, courseDict, path);
              if (ret)
                break;
            }
            // after backtracking, remove the node from the path
            path[currCourse] = false;
            return ret;
      }
};
