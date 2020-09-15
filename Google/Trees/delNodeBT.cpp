
/*
A tree rooted at node 0 is given as follows:

The number of nodes is nodes;
The value of the i-th node is value[i];
The parent of the i-th node is parent[i].
Remove every subtree whose sum of values of nodes is zero.

After doing so, return the number of nodes remaining in the tree.
*/
class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        
    }
};

/**
Solution 1: DFS
Build up the mapping of parent and its children.
Recursively find the sum and the count of subtree.
Time O(N), Space O(N)


Python:

    def deleteTreeNodes(self, n, parent, value):
        sons = {i: set() for i in xrange(n)}
        for i, p in enumerate(parent):
            if i: sons[p].add(i)

        def dfs(x):
            total, count = value[x], 1
            for y in sons[x]:
                t, c = dfs(y)
                total += t
                count += c
            return total, count if total else 0
        return dfs(0)[1]

Solution 2: One Pass
Wrote this solution in 2019-11-30,
don't have the premium so I'll lose the access to my this post.

Hidden condition:
parernt[i] < i for all i > 0
a parent always has have smaller index of its children.


Intuition
Don't ask me why, my friend told me.
He said it was an intuition.
We hardly see a tree problem represented by array.
Another observation is tha, no test case contains a tree with sum = 0.

The problem writer was lasy and made some random cases.
I personally think taht he didn't actually do the work.


Complexity
Time O(N)
Space O(N)


C++ **/

    int deleteTreeNodes(int n, vector<int>& parent, vector<int>& value) {
        vector<int> res(n);
        for (int i = n - 1; i > 0; --i) {
            value[parent[i]] += value[i];
            res[parent[i]] += value[i] ? res[i] + 1 : 0;
        }
        return value[0] ? res[0] + 1 : 0;
    }
/*
Find those vertices which would have sum = 0, by doing dfs and getting the value bottom up.
These vertices should be marked as this subtree would not be included while finding total count.
Do another dfs to count vertices but if sum of that subtree is 0(which was earlier marked), then 0 should be returned. */
class Solution {
public:
    int dfs(int u, vector<unordered_set<int>>& adj, vector<int>& v, vector<bool>& f) {
        int sum = v[u];
        for(auto i : adj[u]) {
            sum += dfs(i, adj, v, f);
        }
        if(sum == 0) {
            f[u] = true;
        }
        return sum;
    }
    
    int dfs(int u, vector<unordered_set<int>>& adj, vector<bool>& f) {
        if(f[u])
            return 0;
        int ans = 1;
        for(int i : adj[u]) {
            ans += dfs(i, adj, f);
        }
        return ans;
    }
    
    int deleteTreeNodes(int n, vector<int>& p, vector<int>& v) {
        vector<unordered_set<int>> adj(n);
        vector<bool> f(n, false);
        for(int i = 0; i < p.size(); i++) {
            int val = p[i];
            if(p[i] != -1) {
                adj[p[i]].insert(i);
            }
        }
        dfs(0, adj, v, f);
        return dfs(0, adj, f);
    }
};


class Solution {
public:
    int dfs(int u, vector<unordered_set<int>>& adj, vector<int>& v, vector<bool>& f) {
        int sum = v[u];
        for(auto i : adj[u]) {
            sum += dfs(i, adj, v, f);
        }
        if(sum == 0) {
            f[u] = true;
        }
        return sum;
    }
    
    int dfs(int u, vector<unordered_set<int>>& adj, vector<bool>& f) {
        if(f[u])
            return 0;
        int ans = 1;
        for(int i : adj[u]) {
            ans += dfs(i, adj, f);
        }
        return ans;
    }
    
    int deleteTreeNodes(int n, vector<int>& p, vector<int>& v) {
        vector<unordered_set<int>> adj(n);
        vector<bool> f(n, false);
        for(int i = 0; i < p.size(); i++) {
            int val = p[i];
            if(p[i] != -1) {
                adj[p[i]].insert(i);
            }
        }
        dfs(0, adj, v, f);
        return dfs(0, adj, f);
    }
};