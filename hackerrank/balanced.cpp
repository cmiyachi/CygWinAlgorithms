#include<bits/stdc++.h> 
using namespace std; 

int areParanthesisBalanced(string expr) 
{ 
	stack<char> s; 
	char x; 

	for (int i=0; i<expr.length(); i++) 
	{ 
		if (expr[i]=='(') 
		{ 
			// Push the element in the stack 
			s.push(expr[i]); 
			continue; 
		} 

		if (s.empty()) 
		return -1; 

		switch (expr[i]) 
		case ')': 
		{
			// Store the top element in a 
			x = s.top(); 
			s.pop(); 
			break; 

		} 
	} 

	// Check Empty Stack 
	return (s.empty()); 
} 

// Driver program to test above function 
int main() 
{ 
	string expr = "((()((()())))()(())))"; 

	if (areParanthesisBalanced(expr)) 
		cout << "Balanced"; 
	else
		cout << "Not Balanced"; 
	return 0; 
} 
