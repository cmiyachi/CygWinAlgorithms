#include <bits/stdc++.h>
	
using namespace std;

class Solution {
    int max_lefts;
public:
    Solution() : max_lefts(0) {}
    typedef vector<int>::size_type sz_t;
    vector<string> removeInvalidParentheses(string s) {
        set<string> res;
        max_lefts = 0;
        removeInvalidParentheses(s, "", 0, 0, res);
        vector<string> ret(res.begin(), res.end());
        if (ret.empty())
            ret.push_back("");
        return ret;
    }
    void removeInvalidParentheses(string s, string part, int lcount, int mlcount, set<string> &res) {
        if (s.empty()) {
            if (lcount == 0) {
                max_lefts = max(max_lefts, mlcount);
                if (mlcount == max_lefts) {
                    res.insert(part);
                }
            }
            return;
        } 
        string next = s.substr(1);
        if (s.front() == '(') {
            removeInvalidParentheses(next, part+s.front(), lcount+1, mlcount+1, res);
            removeInvalidParentheses(next, part, lcount, mlcount, res);
        } else if (s.front() == ')') {
            if (lcount > 0)
                removeInvalidParentheses(next, part+s.front(), lcount-1, mlcount, res);
            removeInvalidParentheses(next, part, lcount, mlcount, res);
        } else {
            removeInvalidParentheses(next, part+s.front(), lcount, mlcount, res);
        }
    }
};

class Solution2 {
private:

vector<string> validExpressions;

 void recurse(
      string s,
      int index,
      int leftCount,
      int rightCount,
      int leftRem,
      int rightRem,
      string expression) {

    // If we reached the end of the string, just check if the resulting expression is
    // valid or not and also if we have removed the total number of left and right
    // parentheses that we should have removed.
    if (index == s.length()) {
      if (leftRem == 0 && rightRem == 0) {
        validExpressions.push_back( expression);
      }

    } else {
      char character = s[index];
      int length = expression.length();

      // The discard case. Note that here we have our pruning condition.
      // We don't recurse if the remaining count for that parenthesis is == 0.
      if ((character == '(' && leftRem > 0) || (character == ')' && rightRem > 0)) {
        recurse(
            s,
            index + 1,
            leftCount,
            rightCount,
            leftRem - (character == '(' ? 1 : 0),
            rightRem - (character == ')' ? 1 : 0),
            expression);
      }

      expression += character;

      // Simply recurse one step further if the current character is not a parenthesis.
      if (character != '(' && character != ')') {

        recurse(s, index + 1, leftCount, rightCount, leftRem, rightRem, expression);

      } else if (character == '(') {

        // Consider an opening bracket.
        recurse(s, index + 1, leftCount + 1, rightCount, leftRem, rightRem, expression);

      } else if (rightCount < leftCount) {

        // Consider a closing bracket.
        recurse(s, index + 1, leftCount, rightCount + 1, leftRem, rightRem, expression);
      }

      // Delete for backtracking.
      expression.erase(expression.begin()+length);
    }
  }

public:
    vector<string> removeInvalidParentheses(string s) {
		 int left = 0, right = 0;

		// First, we find out the number of misplaced left and right parentheses.
		for (int i = 0; i < s.length(); i++) {

		  // Simply record the left one.
		  if (s[i] == '(') {
			left++;
		  } else if (s[i] == ')') {
			// If we don't have a matching left, then this is a misplaced right, record it.
			right = left == 0 ? right + 1 : right;

			// Decrement count of left parentheses because we have found a right
			// which CAN be a matching one for a left.
			left = left > 0 ? left - 1 : left;
		  }
		}

		string expression;
		recurse(s, 0, 0, 0, left, right, expression);
		
		vector<string>::iterator ip; 
  
		// Using std::unique 
		ip = std::unique(validExpressions.begin(), validExpressions.begin() + validExpressions.size()); 
		
  
		// Resizing the vector so as to remove the undefined terms 
		validExpressions.resize(std::distance(validExpressions.begin(), ip)); 
		return validExpressions; 
			
    }
};

class Solution3 {
    void remove(int open, int left, int right, int iStart, string s, vector<string> &out) {
        // Iterate through all the remaining characters and see if we can remove them
        // In the meantime we can also keep track of how many open parantheses we have 
        // so far to avoid calculating it separately.
        for (int i = iStart; i < s.size() && open >= 0; ++i) {
            if (s[i] == '(') {
                // If we should remove this open parantheses, make sure last element wasn't an
                // open parantheses since removing this would result in the same output
                // as removing the previous one so it's redundant.
                if (left > 0 && (i == 0 || s[i - 1] != '('))
                    remove(open, left - 1, right, i, s.substr(0, i) + s.substr(i + 1), out);

                ++open;
            } else if (s[i] == ')') {
                // Same as open parantheses, don't remove if same as previous character
                if (right > 0 && (i == 0 || s[i - 1] != ')'))
                    remove(open, left, right - 1, i, s.substr(0, i) + s.substr(i + 1), out);

                --open;
            }
        }
        
        if (left == 0 && right == 0 && open == 0)
            out.emplace_back(move(s));
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> out;
        
        // How many left and right parantheses should we remove?
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++left;
            } else if (s[i] == ')') {
                if (left > 0)
                    --left;
                else
                    ++right;
            }                
        }
        
        remove(0, left, right, 0, s, out);
        return out;
    }
};

int main(void)
{
	string s = "()())()"; 
	Solution sol;
	Solution3 sol2;
	
	vector<string> result = sol.removeInvalidParentheses(s);
	
	cout << "[";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ","; 
	cout << "]";
	
	s = "(a)())()"; 
	result = sol.removeInvalidParentheses(s);
	cout << "[";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ","; 
	cout << "]";
	
	
	s = "()())()"; 
	vector<string> result2 = sol2.removeInvalidParentheses(s);
	
	cout << "[";
	for (int i = 0; i < result2.size(); i++)
		cout << result2[i] << ","; 
	cout << "]";
	
	result2.clear();
	
	s = "(a)())()"; 
	result2 = sol2.removeInvalidParentheses(s);
	cout << "[";
	for (int i = 0; i < result2.size(); i++)
		cout << result2[i] << ","; 
	cout << "]";
	return 0;
}
