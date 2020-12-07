#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
   vector<char> names;
   for (auto c : s)
       names.push_back(c); 
        
   names.erase(unique(names.begin(), names.end()));
                
   string result;
   for (auto c : names)
                result.push_back(c);

    return result; 

 }
};

int main(void)
{
	string s = "abbaca"; 
	
	Solution sol;
	
	cout << sol.removeDuplicates(s) << endl;
	return 0;
}