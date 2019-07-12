#include <bits/stdc++.h>

using namespace std;

class Solution2 {
public:
    bool isValid(string s) {
		
		const char *arr = s.c_str(); 
		map<char,int> hash_map;
		for (int i = 0; i < s.length(); i++)
		{
			char c = arr[i];
			
			switch(c)
			{
				case '{':
					hash_map[c]++;
					break;
				case '}':
					hash_map['{']--; 
					break;
				case '[':
					hash_map[c]++;
					break;
				case ']':
					hash_map['[']--;
					break;
				case '(':
					hash_map[c]++;
					break;
				case ')':
					hash_map['(']--; 
					break;
				default:
					break;
			} // switch
		}
		
		if ((hash_map['{']!= 0) || (hash_map['[']!= 0) || (hash_map['(']!= 0))
			return false;
		else
			return true; 
        
    }
};

/* class Solution {

  // Hash table that takes care of the mappings.
  private HashMap<Character, Character> mappings;

  // Initialize hash map with mappings. This simply makes the code easier to read.
  public Solution() {
    this.mappings = new HashMap<Character, Character>();
    this.mappings.put(')', '(');
    this.mappings.put('}', '{');
    this.mappings.put(']', '[');
  }

  public boolean isValid(String s) {

    // Initialize a stack to be used in the algorithm.
    Stack<Character> stack = new Stack<Character>();

    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);

      // If the current character is a closing bracket.
      if (this.mappings.containsKey(c)) {

        // Get the top element of the stack. If the stack is empty, set a dummy value of '#'
        char topElement = stack.empty() ? '#' : stack.pop();

        // If the mapping for this bracket doesn't match the stack's top element, return false.
        if (topElement != this.mappings.get(c)) {
          return false;
        }
      } else {
        // If it was an opening bracket, push to the stack.
        stack.push(c);
      }
    }

    // If the stack still contains elements, then it is an invalid expression.
    return stack.isEmpty();
  }
} */

class Solution {
public:
	map<char,char>  mappings; 
	Solution() {
		mappings[')'] = '(';
		mappings['}'] = '{';
		mappings[']'] = '[';
	}
	
    bool isValid(string s) {
		stack<char> pStack; 
		
		for (int i = 0; i < s.length(); i++)
		{
			char c = s[i]; 
			// if closing bracket
			auto itr = mappings.find(c); 
			if (itr != mappings.end())
			{
				// get top element of stack
				char topElement = pStack.empty() ? '#': pStack.top(); 
				pStack.pop(); 
				//the top of stack has to match this closing element
				if (topElement  != mappings[c])
					return false; 
			}
			else // it's an opening bracket
				pStack.push(c);
		} // for
        
		return pStack.empty(); 
    }
};

int main(void)
{
	string s = "(((((())))))";
	Solution sol;
	cout << s << " "<< sol.isValid(s) << endl; 
	
	s = "()()()()";
	cout << s << " "<< sol.isValid(s) << endl;
	
	s = "(((((((()"; 
	cout << s << " "<< sol.isValid(s) << endl;
	
	s = "([)]"; 
	cout << s << " "<< sol.isValid(s) << endl;
	return 0;
}