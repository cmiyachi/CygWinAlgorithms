#include <bits/stdc++.h>
	
using namespace std;

// General idea:
// - first split your cpdomain into int n and string s
// - then parse s backwards looking for '.' and do a += n to a hashmap with the substring for domain
// - make sure to add the whole domain to hasmap when you hit beginning of line
// - create vector of strings at the end from hashmap and return
class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) 
	{    
		unordered_map<string, int> m; 

		for (const auto& word : cpdomains) 
		{
			int i    = word.find (" "); 
			int n    = stoi (word.substr (0, i)); 
			string s = word.substr (i+1, word.size ()-i-1);

			for (int i = s.size ()-1; i > 0; i--) {
				if (s[i] == '.') m[s.substr (i+1, s.size ()-i-1)] += n;
			}
			
			m[s] += n;
		}

		vector<string> v;
		for (const auto& e : m) v.push_back (to_string (e.second) + " " + e.first);
		return v;
	}
};

int main(void)
{	
	vector<string> input{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
	
	Solution sol;
	
	vector<string> result = sol.subdomainVisits(input); 
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	
	return 0;
}