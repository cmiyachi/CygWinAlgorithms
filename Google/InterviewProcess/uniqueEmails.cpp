#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> st;
		for(string &email : emails) {
			string cleanEmail;
			for(char c : email) {
				if(c == '+' || c == '@') break;
				if(c == '.') continue;
				cleanEmail += c;
			}
			cleanEmail += email.substr(email.find('@'));
			st.insert(cleanEmail);
		}
		return st.size();
	}
};

int main(void)
{
	vector<string> emails{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"}; 
	Solution sol;
	
	cout << sol.numUniqueEmails(emails) << endl;
	
	return 0;
}