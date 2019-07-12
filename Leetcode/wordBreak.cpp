#include <bits/stdc++.h> 
using namespace std;

class Solution2 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int len = s.length();
		bool *res = new bool[len+1];
		vector<string>::const_iterator it;

		if (s.length() == 0 || wordDict.size() == 0)
			return false;
		res[0] = true; 
		for (int i = 1; i < len+1; i++) 
			res[i] = false;
		for (int i = 0; i < s.length(); i++){ 
			for (int j = 0; j <= i; ++j) { //j-i
				string sub = s.substr(j, i+1-j); 
				it = find(wordDict.begin(), wordDict.end(), sub); 
				if (it != wordDict.end()) { 
					res[i+1] = res[j] && true; 
					if (res[i+1])
						break;
				}
			}
		}
		return res[len];
	}
};

class Solution {
public:
    bool hasWord(const string& s, vector<string>& wordDict, map<string, bool>& m) {
        for (auto w : wordDict) {
            if (s == w) {
                m[s] = true;
                return true;
            }
        }
        m[s] = false;
        return false;
    }

    bool wordBreak2(string s, vector<string>& wordDict, map<string, bool>& m) {
        if (m.find(s) != end(m))
            return m[s];
        else if (hasWord(s, wordDict, m))
            return true;

        for (auto i=1; i<s.length(); i++) {
            auto first = string(begin(s), begin(s)+i);
            auto second = string(begin(s)+i, end(s));
            if (hasWord(second, wordDict, m) && wordBreak2(first, wordDict, m))
                return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> m;
        return wordBreak2(s, wordDict, m);
    }

};

int main()
{
	string s1 = "leetbcode";
	vector<string> wordDict1 = { "leet", "code", "b"};
	string s2 = "abcd";
	vector<string> wordDict2 = { "a", "abc", "b", "cd" };
	string s3 = "aaaaaaa";
	vector<string> wordDict3 = { "aaaa", "aaa" };
	string s4 = "a";
	vector<string> wordDict4 = { "b" };
	string s5 = "dogs";
	vector<string> wordDict5 = { "dog", "s", "gs"};
	Solution sl;
	cout << sl.wordBreak(s1, wordDict1) << endl;
	cout << sl.wordBreak(s2, wordDict2) << endl;
	cout << sl.wordBreak(s3, wordDict3) << endl;
	cout << sl.wordBreak(s4, wordDict4) << endl;
	cout << sl.wordBreak(s5, wordDict5) << endl;
	
}