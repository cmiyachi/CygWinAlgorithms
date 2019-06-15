#include <bits/stdc++.h>

using namespace std;

int minimumMoves(vector <string> grid, int startX, int startY, int goalX, int goalY) {
	
	int n = grid.size(); 
    // Complete this function
    vector<vector<int>> v(n,vector<int>(n)); // visited
    vector<vector<int>> t(n,vector<int>(n)); // cost
    queue< pair<int,int> > q;
	
	// push the start location on the queue
    q.push(make_pair(startX,startY));
	// set this location to visited
    v[startX][startY] = 1;
	
	// until we reach the goal...
    while(v[goalX][goalY] == 0){
        pair<int,int> p = q.front();  // create a pair from the first item on the queue. 
        q.pop(); // remove that location
        int i=p.first;
        int j=p.second;  // this is x,y
        int cost = t[i][j]; // starts out at 0
        for(int k=i+1,l=j;k<n;k++) { // try to move in the x direction - break if obstacle is reached
            if(grid[k][l] == 'X'){
                break;
            }
            if(v[k][l] == 0){ // where did we break?
                q.push(make_pair(k,l)); // push on our queue
                v[k][l] = 1;
                t[k][l] = cost + 1; // add up the cost
            }
        }
        for(int k=i-1,l=j;k>=0;k--) { // go in the opposite direction
            if(grid[k][l] == 'X'){
                break;
            }
            if(v[k][l] == 0){
                q.push(make_pair(k,l));
                v[k][l] = 1;
                t[k][l] = cost + 1;
            }
        }
        for(int k=i,l=j+1;l<n;l++){  // go on the y axis
            if(grid[k][l] == 'X'){
                break;
            }
            if(v[k][l] == 0){
                q.push(make_pair(k,l));
                v[k][l] = 1;
                t[k][l] = cost + 1;
            }
        }
        for(int k=i,l=j-1;l>=0;l--){
            if(grid[k][l] == 'X'){
                break;
            }
            if(v[k][l] == 0){
                q.push(make_pair(k,l));
                v[k][l] = 1;
                t[k][l] = cost + 1;
            }
        }
    }
    return t[goalX][goalY];
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    int startX;
    int startY;
    int goalX;
    int goalY;
    cin >> startX >> startY >> goalX >> goalY;
    int result = minimumMoves(grid, startX, startY, goalX, goalY,n);
    cout<<result;
    return 0;
}
