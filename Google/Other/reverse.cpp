#include <bits/stdc++.h>
using namespace std;
/*
ntuition

We can build up the reverse integer one digit at a time. While doing so, we can check beforehand whether or not appending another digit would cause overflow.

Algorithm

Reversing an integer can be done similarly to reversing a string.

We want to repeatedly "pop" the last digit off of xx and "push" it to the back of the \text{rev}rev. In the end, \text{rev}rev will be the reverse of the xx.

To "pop" and "push" digits without the help of some auxiliary stack/array, we can use math.

//pop operation:
pop = x % 10;
x /= 10;

//push operation:
temp = rev * 10 + pop;
rev = temp;
However, this approach is dangerous, because the statement \text{temp} = \text{rev} \cdot 10 + \text{pop}temp=rev⋅10+pop can cause overflow.

Luckily, it is easy to check beforehand whether or this statement would cause an overflow.

To explain, lets assume that \text{rev}rev is positive.

If temp = \text{rev} \cdot 10 + \text{pop}temp=rev⋅10+pop causes overflow, then it must be that \text{rev} \geq \frac{INTMAX}{10}rev≥ 
10
INTMAX
​	
 
If \text{rev} > \frac{INTMAX}{10}rev> 
10
INTMAX
​	
 , then temp = \text{rev} \cdot 10 + \text{pop}temp=rev⋅10+pop is guaranteed to overflow.
If \text{rev} == \frac{INTMAX}{10}rev== 
10
INTMAX
​	
 , then temp = \text{rev} \cdot 10 + \text{pop}temp=rev⋅10+pop will overflow if and only if \text{pop} > 7pop>7
Similar logic can be applied when \text{rev}rev is negative.*/
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

class Solution2 {
public:
    int reverse(long long x) {
        long long rev = 0;
		bool negative = false;
		string x_string = to_string(x);
		if (x_string[0] == '-')
		{
			x_string = x_string.substr(1, x_string.size()-1);
			negative = true;
		}
		std::reverse(x_string.begin(), x_string.end());
		stringstream s_rev(x_string);
		s_rev >> rev; 
		if (negative == true)
			rev = -rev;
        return rev;
    }
};

int main(void)
{
	Solution sol;
	
	cout << sol.reverse(-123) << endl;
	cout << sol.reverse(123) << endl;
	
	Solution2 sol2;
	cout << sol2.reverse(-123) << endl;
	cout << sol2.reverse(123) << endl;
	cout << sol2.reverse(1230) << endl;
	cout << sol2.reverse(1534236469) << endl;
	
	 
	 return 0;
}