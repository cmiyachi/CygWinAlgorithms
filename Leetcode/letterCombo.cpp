#include <bits/stdc++.h> 
using namespace std;

class Solution2 {
public:
	vector<string> char_map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	void letterCombinations(string digits, string::size_type n, string &s, vector<string> &v)
	{
		if (n == digits.size()) {
			v.push_back(s);
			return;
		}

		string chars = char_map[digits[n] - '0'];
		for (string::size_type i = 0; i < chars.size(); i++) {
			s += chars[i];
			letterCombinations(digits, n + 1, s, v);
			s.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> v;
        if (digits == "") return v; 
		string s;
		letterCombinations(digits, 0, s, v);
		return v;
	}
};

class Solution3 {
public:
vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.empty()) return vector<string>();
    static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");   // add a seed for the initial case
    for(int i = 0 ; i < digits.size(); ++i) {
        int num = digits[i]-'0';
        if(num < 0 || num > 9) break;
        const string& candidate = v[num];
        if(candidate.empty()) continue;
        vector<string> tmp;
        for(int j = 0 ; j < candidate.size() ; ++j) {
            for(int k = 0 ; k < result.size() ; ++k) {
                tmp.push_back(result[k] + candidate[j]);
            }
        }
        result.swap(tmp);
    }
    return result;
}
};   
class Solution {
public:
	vector<string> char_map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	void letterCombinations(string digits, string::size_type n, string &s, vector<string> &v)
	{
		if (n == digits.size()) {
			v.push_back(s);
			return;
		}

		string chars = char_map[digits[n] - '0'];
		for (string::size_type i = 0; i < chars.size(); i++) {
			s += chars[i];
			letterCombinations(digits, n + 1, s, v);
			s.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> v;
		if (digits == "") return v; 
		string s;
		letterCombinations(digits, 0, s, v);
		return v;
	}
};

int main(void)
{
	Solution sol; 
	vector<string> result = sol.letterCombinations("23");
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " , "; 
	
	return 0;
}