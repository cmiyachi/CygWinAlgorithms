#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
		vector<int> partitionLabels(string S) {
			vector<int> last(26);
			for (int i = 0; i < S.length(); ++i)
				last[S[i] - 'a'] = i;
			
			int j = 0, anchor = 0;
			vector<int> ans;
			for (int i = 0; i < S.length(); ++i) {
				j = max(j, last[S[i] - 'a']);
				if (i == j) {
					ans.push_back(i - anchor + 1);
					anchor = i + 1;
				}
			}
			return ans;
		}
};

int main(void)
{
	
	string S = "ababcbacadefegdehijhklij"; 
	
	Solution sol;
	
	vector<int> result = sol.partitionLabels(S);
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ", ";
	
	return 0;
}