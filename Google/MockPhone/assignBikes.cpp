/*On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.

Our goal is to assign a bike to each worker. Among the available bikes and workers, we choose the (worker, bike) pair with the shortest Manhattan distance between each other, and assign the bike to that worker. (If there are multiple (worker, bike) pairs with the same shortest Manhattan distance, we choose the pair with the smallest worker index; if there are multiple ways to do that, we choose the pair with the smallest bike index). We repeat this process until there are no available workers.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that the i-th worker is assigned to.

 */
 class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        
    }
};

/*
Since the range of distance is [0, 2000] which is much lower than the # of pairs, which is 1e6. It's a good time to use bucket sort. Basically, it's to put each pair into the bucket representing its distance. Eventually, we can loop thru each bucket from lower distance.
Therefore, it's O(M * N) time and O(M * N) space. Only takes 60 ms in C++ beat most submissions.
See the code:**/

class Solution {
public:
    // bucket sort
    // O(N*M) time, O(N*M) space
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // bucket sort since range of distance is [0, 2000]
        vector<vector<pair<int, int>>> buckets(2001); // buckets[i] is the vector<worker id, bike id> with distance i
        int n = workers.size(), m = bikes.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                buckets[dis].push_back({i, j});
            }
        }
        vector<int> res(n, -1);
        vector<bool> bikeUsed(m, false);
        for (int d = 0; d <= 2000; d++) {
            for (int k = 0; k < buckets[d].size(); k++) {
                if (res[buckets[d][k].first] == -1 && !bikeUsed[buckets[d][k].second]) {
                    bikeUsed[buckets[d][k].second] = true;
                    res[buckets[d][k].first] = buckets[d][k].second;
                }
            }
        }
		//int sum  = accumulate(res.begin(), res.end(), 0);
        return res;
    }
};



We precompute a 2D matrix, where the (i, j)-th element represents the distance between worker i and bike j, and then we sort each row and maintain the original bike indices information in the post-sorted row, that is

int m = workers.size(), n = bikes.size();
vector<vector<pair<int, int>>> distToBikes(m, vector<pair<int, int>>(n));
for (int i = 0; i < m; ++i) {
	for (int j = 0; j < n; ++j) {
		int xw = workers[i][0], yw = workers[i][1], xb = bikes[j][0], yb = bikes[j][1];
		int dist = abs(xw - xb) + abs(yw - yb);
		distToBikes[i][j] = {dist, j};
	}
	sort(distToBikes[i].begin(), distToBikes[i].end());
}
Once we get the m*n matrix distToBikes, we do a dfs that sequentially matches each worker to an avaiable bike --- we do the match in a greedy way by starting from the cloest bike that is available, and then proceed to find a match for the next worker, if at some point, we know that all the rest workers can be matched to their closest bike with no tie, then there is no point to proceed since we know that we cannot get better results any more. In order to get the no-tie information, the dfs routine needs to return a boolean value, which is true if all the workers starting from the current index to the last one can be matched to their closest bike with no tie, and false otherwise.

class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int res = INT_MAX;
        int m = workers.size(), n = bikes.size();
        vector<vector<pair<int, int>>> distToBikes(m, vector<pair<int, int>>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int xw = workers[i][0], yw = workers[i][1], xb = bikes[j][0], yb = bikes[j][1];
                int dist = abs(xw - xb) + abs(yw - yb);
                distToBikes[i][j] = {dist, j};
            }
            sort(distToBikes[i].begin(), distToBikes[i].end());
        }
        
        vector<bool> matched(n, false);
        dfs(distToBikes, 0, m, n, matched, 0, res);
        return res;
    }
    
    bool dfs(vector<vector<pair<int, int>>>& distToBikes, int workerIdx, int m, int n, vector<bool>& matched, int curSum, int& res) {
        if (workerIdx == m) {
            res = min(res, curSum);
            return true;
        }
        
        bool noTie = false;
        for (int j = 0; j < n && distToBikes[workerIdx][j].first == distToBikes[workerIdx][0].first; ++j) {
            if (!matched[distToBikes[workerIdx][j].second]) {
                noTie = true;
                break;
            }
        }
        
        for (int j = 0; j < n; ++j) {
            if (matched[distToBikes[workerIdx][j].second])
                continue;
            
            matched[distToBikes[workerIdx][j].second] = true;
            bool restNoTie = dfs(distToBikes, workerIdx + 1, m, n, matched, curSum + distToBikes[workerIdx][j].first, res);
            matched[distToBikes[workerIdx][j].second] = false;
            if (restNoTie)
                break;
            else
                noTie = false;
        }
        return noTie;
    }
};
Although the time complexity in worst case is still O(m! * n), the above approach does terminate early in a lot of cases we can imagine.

This solution is inspired by @lee215

The code is commented in very details. Hope it helps.
But I discovered a big pitfall when rewritting the code. It will be wrong to check whether state is visited inside for-loop of traversing all available bikes. I haven't figured the reason yet.

Could anyone please help to clarify?

In standard BFS, we usually check whether state is visited before pushing to the queue, AND mark state as visited immediately after being pushed to queue. But this stardard way won't work here! Why????

class Solution {
public:
    /*or we can define struct Node        
        int worker_id;
        int mask;
        int cost;
    */

    //bitmask state encode <current worker_id, bikes> into 32-bit int
    //NOTE: current worker_id is NOT assigned bike yet!
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        if (workers.empty() || bikes.empty()) return 0;
        
        int n = workers.size(), m = bikes.size();
        
        //minheap for total distance sum
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; //<total distance sum, bitmask state> 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minheap(cmp);        
        minheap.push({0, 0}); //total distance = 0, state bitmask = 0 means starting from worker_id = 0, but we do NOT assign bike to worker_id = 0 yet!
        unordered_set<int> visited;
        // visited.insert(0); //state 0 is visited, i.e., pushed to queue already
        
        while (!minheap.empty()) {
            int distance = minheap.top().first;
            int state = minheap.top().second;
            minheap.pop();
            
            int i = state >> 16; //how to find the bit with 1 (current worker_id)? say, 0b1000 denotes current worker_id = 3? NO! we encode single worker_id into the full bitmask 0b1000 = 8 which means worker_id = 8
            int mask = state & 0xFFFF; //bikes bitmask
            
            if (i == n) return distance; //NOTE: when all workers are assigned
            
            if (visited.count(state)) continue;
            visited.insert(state);
            
            //1) traverse all available bikes b/c available bikes are dynamically changing, thus we need to scan all of them each time; 2)do we only need to find the closest bike? No! b/c we need to minimize total distance for ALL workers. choose closest bike for each worker won't necessarily achieve the minimum total distance, b/c each step of bike assignment affects sequential choices.
            for (int j = 0; j < m; j++) {
                if ((mask & (1 << j)) == 0) {//bike still available
                    int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]); //NOTE: assign bike j to current worker_id i
                    
                    int next = mask | (1 << j); 
                    next |= (i + 1) << 16; //encode next worker_id to high 16-bit
                    
                    //NOTE: skip visited state! otherwise, TLE. but for current worker_id = i, next step we have worker_id = i + 1, then loop through all available bikes j, how can this generate duplicated visited state? b/c minheap does NOT take out worker_id according to its total distance so far! thus, worker_id is NOT sequentially from 0 to n - 1
					
                    // if (visited.count(next) > 0) { **//Question: Put here is wrong! but why?**
                    //     continue;
                    // }
                    
                    minheap.push({distance + d, next});
                    // visited.insert(next); //NOTE: mark state as visited!!
                }
            }
            
        }
        
        return 0;
    }
};