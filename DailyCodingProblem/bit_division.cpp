// CPP program to divide a number by other 
// without using / operator 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find division without using 
// '/' operator 
int division(int num1, int num2) 
{ 
if (num1 == 0) 
	return 0; 
if (num2 == 0) 
	return INT_MAX; 

bool negResult = false; 

// Handling negative numbers 
if (num1 < 0) 
{ 
	num1 = -num1 ; 
	if (num2 < 0) 
		num2 = - num2 ; 
	else
		negResult = true; 
} 
else if (num2 < 0) 
{ 
	num2 = - num2 ; 
	negResult = true; 
} 

// if num1 is greater than equal to num2 
// subtract num2 from num1 and increase 
// quotient by one. 
int quotient = 0; 
while (num1 >= num2) 
{ 
	num1 = num1 - num2 ; 
	quotient++ ; 
} 

// checking if neg equals to 1 then making 
// quotient negative 
if (negResult) 
		quotient = - quotient ; 
return quotient ; 
} 

int divide(int x, int y)
{
	if (y==0) return INT_MAX;
	
	int quotient = 0;
	
	int power = 32; 
	
	int y_power = (y << power); // starty with y * 2^32
	int remainder = x;
	
	while (remainder >= y)
	{
		while (y_power  > remainder)
		{
			y_power = (y_power >> 1);
			power -= 1; 
		}
		(quotient += 1) << power;
		remainder -= y_power; 

	}
	
	return quotient;
	
}
// Driver program 
int main() 
{ 
	int num1 = 13, num2 = 2 ; 
	cout << division(num1, num2); ; 
	cout << endl;
	cout << divide(num1, num2); 
	return 0; 
} 
