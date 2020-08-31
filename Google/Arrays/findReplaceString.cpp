#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector<pair<int, int>> vp;
       
        for(int i = 0; i < n; i++) {
            vp.push_back(make_pair(indexes[i], i));  
        }
        
        sort(vp.rbegin(), vp.rend()); // sort in descending order, then replace from right to left
        
        for(int i = 0; i < n; i++) { 
            int first = vp[i].first;
            int second = vp[i].second;
            if(S.find(sources[second], first) == first) {// check if sources[i] starts at specified position
                S.replace(first, sources[second].length(), targets[second]);
            }
        }
        
        return S;
    }
};

int main(void)
{
	Solution sol;
	
	string S = "abcd";
	vector<int> indexes{0,2};
	vector<string> sources{"a","cd"};
	vector<string> targets{"eee","ffff"};
	
	cout << sol.findReplaceString(S, indexes, sources, targets) << endl;
	
	string S2 = "abcd";
	vector<int> indexes2{0,2};
	vector<string> sources2{"ab","ec"};
	vector<string> targets2{"eee","ffff"};
	
	cout << sol.findReplaceString(S2, indexes2, sources2, targets2) << endl;
	return 0;
}


