#include <bits/stdc++.h> 
using namespace std; 

//Using an unordered_map to save all the destinations (using multiset to keep them in order) // for each //starting city. Then do dfs search from "JFK", if failed, backtracking

class Solution {
private: 
    bool dfs(vector<string> &res, unordered_map<string, multiset<string>> &map, int len)
    {
        if(res.size()==len) return true; // if we successfully find a path, then return true;
        if(map.count(res.back())==0 || map[res.back()].empty()) return false; // if the current path reaches end but still have some flights not included, return false
        
        string prev ="", start=res.back(); 
        for(auto it= map[start].begin(); it!=map[start].end();++it)
        {
            if(*it==prev) continue;//if it has been visited before
            prev = *it; 
            map[res.back()].erase(it); // find a new destination, extend the path
            res.push_back(prev); 
            if(dfs(res, map, len)) return true; // if it finds a valid path, return true
            res.pop_back(); // else traceback, and try the next one
            it = map[res.back()].insert(prev);
        }
        return false; // if it fails all the tries, return false
    }

public:
//    vector<string> findItinerary(vector<pair<string, string>> tickets) {
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int len = tickets.size(), i;
        vector<string> res(1,"YUL");
        unordered_map<string, multiset<string>> map;
        //build map
        for(i=0; i<len;++i) map[tickets[i][0]].insert(tickets[i][1]);
        
        dfs(res, map, len+1);
        return res;
    }
};

int main(void)
{
	Solution sol;
	
	vector<vector<string>> flights{{"SFO","HKO"},{"YYZ", "SFO"}, {"YUL", "YYZ"}, {"HKO","ORD"}};
	
	vector<string> result = sol.findItinerary(flights);
	
	for (string s: result)
		cout << s << " ";
		
	return 0;
}