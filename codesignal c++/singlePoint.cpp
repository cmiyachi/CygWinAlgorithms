#include <iostream>
#include <vector> 
#include <map>
#include <set>

using namespace std; 

class Graph{
public:
  std::map<int, int> disc;
  std::map<int, int> low;
  std::set<int> visited;
  std::map<int, int> parent;
  
  std::vector<std::vector<int>> conn;
  int ts;
  int ret;

  Graph(std::vector<std::vector<int>>& a_conn){
    conn = a_conn;
    ts = 0;
    ret = 0;
  }
  
  void dfs(int st){
    disc[st] = ts;
    low[st] = ts;
    ts++;
    visited.insert(st);
    for(int c = 0; c < conn.size(); ++c){
      if(conn[st][c] == 0) continue; 
      if(visited.count(c) == 0){
        parent[c] = st;
        dfs(c);
        if(low[c] > disc[st]){
          ret++;
        }
      }
      if(parent.count(st) == 0 || c != parent[st]){
        low[st] = std::min(low[st], low[c]);
      }
    }
    
  }
};


int singlePointOfFailure(std::vector<std::vector<int>> connections) {
  Graph g(connections);
  g.dfs(0);
  return g.ret;
}

int main(void)
{
    std::vector<std::vector<int>> v =
        {{0, 1, 1, 1, 1}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}};
    //print (v);

    std::vector<std::vector<int>> v1 ={{0,1},{1,0}};

     std::vector<std::vector<int>> v2 = {{0,1,1},
                                         {1,0,1},
                                         {1,1,0}};

     std::vector<std::vector<int>> v3 =
         {{0,1,1,0,0,0,0},
          {1,0,1,0,0,0,0},
          {1,1,0,0,0,0,1},
          {0,0,0,0,1,1,1},
          {0,0,0,1,0,1,0},
          {0,0,0,1,1,0,0},
          {0,0,1,1,0,0,0}};

    int f = singlePointOfFailure(v3);
    cout << f << endl;
	f = singlePointOfFailure(v2);
	cout << f << endl;
	f = singlePointOfFailure(v1);
	cout << f << endl; 
}