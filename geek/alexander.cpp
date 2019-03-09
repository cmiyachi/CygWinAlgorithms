#include <iostream>
using namespace std;

int cube(int n)
{
	return n*n*n;
}
int main() {
	
	int testcases; 
	int num;
	
	cin >> testcases;
	
	 

	for (int i = 0; i < testcases; i++)
	{
		cin >> num;
		int digit1,digit2,digit3;
		digit3 = num % 10;
		digit2 = num / 10 % 10;
		digit1 = num / 100 % 10; 
		
		// cout << digit1 << " " << digit2 << " " << digit3 << endl; 
		// cout <<  << " " << (digit2^3) << " " << (digit3^3) << " " << num << endl; 
		
		if (cube(digit1)+cube(digit2)+cube(digit3) == num) 
			cout << "Yes" << endl;  
		else
			cout << "No" << endl;
	}
        
	return 0;
}