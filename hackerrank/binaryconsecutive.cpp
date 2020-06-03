
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int remainder = 0;
	stack<int> binaryNumber; 
	int max_cons = 1;
	
	while (n > 0)
	{
		remainder = n%2;
		n = n/2; 
		binaryNumber.push(remainder);
		
	}

	while (!binaryNumber.empty()) 
    { 
       if (binaryNumber.top() == 1)
		   max_cons++;
	   else
		   max_cons = 1; 
        binaryNumber.pop(); 
    } 
    cout <<  max_cons << '\n'; 
	
    return 0;
}


/*
while(n > 0):
    remainder = n%2;
    n = n/2;
    Insert remainder to front of a list or push onto a stack

Print list or stack
*/