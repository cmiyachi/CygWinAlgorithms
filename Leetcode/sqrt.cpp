#include <bits/stdc++.h>
using namespace std;
/**
Let's use recursion. Bases cases are \sqrt{x} = x 
x
​	
 =x for x < 2x<2. Now the idea is to decrease xx recursively at each step to go down to the base cases.

How to go down?

For example, let's notice that \sqrt{x} = 2 \times \sqrt{\frac{x}{4}} 
x
​	
 =2× 
4
x
​	
 
​	
 , and hence square root could be computed recursively as

\textrm{mySqrt}(x) = 2 \times \textrm{mySqrt}\left(\frac{x}{4}\right)mySqrt(x)=2×mySqrt( 
4
x
​	
 )

One could already stop here, but let's use left and right shifts, which are quite fast manipulations with bits

x << y \qquad \textrm{that means} \qquad x \times 2^yx<<ythat meansx×2 
y
 

x >> y \qquad \textrm{that means} \qquad \frac{x}{2^y}x>>ythat means 
2 
y
 
x
​	
 

That means one could rewrite the recursion above as

\textrm{mySqrt}(x) = \textrm{mySqrt}(x >> 2) << 1mySqrt(x)=mySqrt(x>>2)<<1

in order to fasten up the computations.
**/

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; 
		
		int left = mySqrt(x >> 2) << 1; 
		int right = left + 1; 
		return (long )right * right > x ? left : right; 
    }
};


int main(void)
{
	Solution sol;
	
	cout << sol.mySqrt(4) << endl;
	
	cout << sol.mySqrt(8) << endl; 
	
	return 0;
}