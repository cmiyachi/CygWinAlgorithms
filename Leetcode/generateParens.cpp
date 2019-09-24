#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> ans;
        if (n == 0) {
            ans.push_back("");
        } else {
            for (int c = 0; c < n; ++c)
                for (auto&& left: generateParenthesis(c))
                    for (auto&& right: generateParenthesis(n-1-c))
                        ans.push_back("(" + left + ")" + right);
        }
        return ans;
    }
};

int main(void)
{
	Solution sol;
	
	vector<string> result = sol.generateParenthesis(3);
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	
	return 0; 
}