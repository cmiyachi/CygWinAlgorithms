#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
int climbingStairs(int n) {
// 1: [1]
// 2: [11, 2]       => f(1) + f(0)
// 3: [111, 12, 21] => f(2) + f(1)
// 4: [1111, 121, 112, 211, 22] => f(3) + f(2)
    if(m[n]) return m[n];
    if(n<3) return n;
    m[n] = climbingStairs(n-1) + climbingStairs(n-2);
    return m[n];
}

int main(void)
{
	
	cout << climbingStairs(4);
	
	return 0;
}