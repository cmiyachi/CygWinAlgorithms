#include <bits/stdc++.h>
using namespace std;
 

bool balancedBrackets(string str) {
  // Write your code here.
	vector<char> opening{'(', '[', '{'};
	vector<char> close{')', ']', '}'};
	stack<char> bracket_stack;
	unordered_map<char, char> bracket_map{{')','('}, {']','['},{'}','{'}};
	
	for (char c : str)
	{
		if (find(opening.begin(), opening.end(),c) != opening.end())
			bracket_stack.push(c);
		else if (find(close.begin(), close.end(), c) != close.end())
		{
			if (bracket_stack.size() == 0) return false; 
			char matching_bracket = bracket_map[c]; 
			char open_bracket = bracket_stack.top();
			// bracket_stack.pop();
			if (open_bracket != matching_bracket)
				return false; 
			else
				bracket_stack.pop();
		}
	}
  return bracket_stack.empty(); 
}

int main(void)
{
	string s1 = "([a]b)[c]({d})";
	string s2 = "((()";
	string s3 = "([)]";
	
	cout << balancedBrackets(s1) << endl; 
	cout << balancedBrackets(s2) << endl; 
	cout << balancedBrackets(s3) << endl; 
	return 0;
}
