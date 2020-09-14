#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    int minAreaRect(vector<vector<int>>& points) {
        /**
        * Base case: we need at least 4 points to form a rectangle
        */ 
        if (points.size() < 4)
            return 0;
        
        /**
        * minArea: result 
        * pointSet: stores all the points
        *   (we can use unordered_set here to reduce the time complexity, 
        *    but be aware that in C++ unordered_set doesn't not take type of vector or pair
        *    unless you create a hasher)
        *   referenes:
        *       unordered_set<vector<int>>: https://stackoverflow.com/questions/29855908/c-unordered-set-of-vectors
        *       unordered_set<pair<int, int>>: https://stackoverflow.com/questions/15160889/how-to-make-unordered-set-of-pairs-of-integers-in-c
        */ 
        int minArea = INT_MAX;
        set<vector<int>> pointSet;
        
        for (auto point : points) 
            pointSet.insert(point);
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                /**
                * Check if current points pair (<x1, y1> & <x2, y2>) can form a diagonal 
                *   If (true): 
                *       check if point <x1, y2> && point <x2, y1> exists
                *           If yes:
                *               1. calculate the curArea
                *               2. update the minArea if curArea > minArea
                *           Else:
                *               continue checking next possible pair;
                *   Else: 
                *       continue checking next possible pair;
                */
                int xOne = points[i][0], yOne = points[i][1];
                int xTwo = points[j][0], yTwo = points[j][1];

                if (xOne != xTwo && yOne != yTwo && xOne != yTwo && yOne != xTwo) {
                    if (pointSet.count({ xOne, yTwo }) && pointSet.count({ xTwo, yOne })) {
                        int curArea = (abs(xTwo-xOne) * abs(yTwo-yOne));
                        minArea = min(minArea, curArea);
                    }
                }
            }
        }
        
        return minArea == INT_MAX ? 0 : minArea;
    }
};
int minAreaRect2(vector<vector<int>>& points) {
    unordered_set<int> pointSet;

    // Assume that x and y coordinates are in range of (0,40000)
    // Also x and y coordinates are integers. 
    // This means that distance between every x coordinate is atleast 1 (same stands true for y coordinate)
    // So we can map all y coordinates for given x in space of 40000 uniquely
    // Hence our hash function can be : h(x,y) = 40001*x + y 
    
    int HASH_CONSTANT = 40001;
    for(vector<int> point : points){
        pointSet.insert(HASH_CONSTANT*point[0]+point[1]);
    }
    
    int minarea = INT_MAX;

    // Iterate over all pair of points
    for(int i=0; i<points.size(); i++){
        for(int j=i+1; j<points.size(); j++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];
            
            // Check if given pair can form diagonal of rectangle ?
            if(x1!=x2 && y1!=y2){

                // If yes, do we have another two missing points in our point set ?
                // Not that this method is only possible when we have rectangles parallel to x&y axes
                if(pointSet.find(HASH_CONSTANT*x1+y2) != pointSet.end() &&
                    pointSet.find(HASH_CONSTANT*x2+y1) != pointSet.end()){
                    minarea = min(minarea, abs(x2-x1)*abs(y2-y1));
                }
            }
        }
    }
    
    return (minarea == INT_MAX ? 0 : minarea);
}
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        int res = INT_MAX;
        
        for(const auto& point : points)
            mp[point[0]].insert(point[1]);
        
        for(int i=0; i<points.size()-1; i++)
        {
            for(int j=i+1; j<points.size(); j++)
            {
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                if(mp[points[i][0]].count(points[j][1]) && mp[points[j][0]].count(points[i][1]))
                    res = min(res, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
            }
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }
};

int main(void)
{
	Solution sol;
	vector<vector<int>> points{{1,1},{1,3},{3,1},{3,3},{2,2}};
	
	cout << sol.minAreaRect(points); 
	return 0;
}