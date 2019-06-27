#include<bits/stdc++.h> 
using namespace std; 

int findDepth(string expr) 
{ 
	stack<char> s; 
	char c; 
	int maxdepth = 0; 
	int themax = 0; 

	// Traversing the Expression 
	for (int i=0; i<expr.length(); i++) 
	{ 
		if (expr[i]=='(') 
		{ 
			// Push the element in the stack 
			s.push(expr[i]); 
			maxdepth++; 
			if (maxdepth > themax) 
				themax = maxdepth; 
			
			continue; 
		} 

	
		if (s.empty()) 
		return -1; 

		//switch (expr[i]) 
		//{ 
		//case ')': 
		if (expr[i] == ')')
		{
			c = s.top(); 
			s.pop(); 
			maxdepth--; 
			//break; 
		} 
	} 

	// Check Empty Stack 
	if (!(s.empty()))
		return -1;
	else	
		return themax; 
} 

// Driver program to test above function 
int main() 
{ 
	string expr = "((()((()())))()(())))"; 

	cout << (findDepth(expr)) ;

	return 0; 
} 
