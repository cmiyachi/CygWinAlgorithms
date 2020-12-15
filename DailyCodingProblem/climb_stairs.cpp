
#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    int climbStairs(int n) {
        return climb_Stairs(0, n);
    }
    int climb_Stairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
    }
};
class Solution {
public:
    int climbStairs(int n) {
    int f[n + 1];  
    int i; 
    if(n==1){
        return 1;
    }
    // 0th and 1st number of the  
    // series are 0 and 1 
    f[0] = 0; 
    f[1] = 1; 
    f[2] = 2;
    for(i = 3; i <= n; i++) 
    { 
          
       //Add the previous 2 numbers  
       // in the series and store it 
       f[i] = f[i - 1] + f[i - 2]; 
    } 
    return f[n]; 
        
    }
};
// C++ program to count number of ways 
// to reach nth stair when a person 
// can climb either 1 or 2 stairs at a time 
#include <bits/stdc++.h> 
using namespace std; 

// A recursive function used by countWays 
int countWaysUtil(int n, int m) 
{ 
	if (n <= 1) 
	{ 
		return n; 
	} 
	
	int res = 0; 
	for(int i = 1; i <= m && i <= n; i++) 
	{ 
	res += countWaysUtil(n - i, m); 
	} 
	return res; 
} 

// Returns number of ways to reach s'th stair 
int countWays(int s, int m) 
{ 
	return countWaysUtil(s + 1, m); 
} 

// Driver code 
int main() 
{ 
	int s = 4, m = 2; 
	cout << "Nuber of ways = " << countWays(s, m); 

	return 0; 
} 
