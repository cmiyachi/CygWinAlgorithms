#include <bits/stdc++.h>
using namespace std;
class Solution3 {
public:
  bool backspaceCompare(string S, string T) { return brute_force(S, T); }

private:
  bool brute_force(const string &S, const string &T) {
    return to_normal_string(S) == to_normal_string(T);
  }

  string to_normal_string(const string &str) {
    string normal;
    for (const auto c : str) {
      if (c == '#') {
        if (!normal.empty()) {
          normal.pop_back();
        }
      } else {
        normal.push_back(c);
      }
    }

    return normal;
  }
};
class Solution2 {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> ss, ts;
		for (const auto &c: S) {
			if (c != '#') {
				ss.push(c);
			}else{
				if(ss.empty()){
					continue;
				}
				ss.pop();
			}
		}
		
		for (const auto &c: T) {
			if (c != '#') {
				ts.push(c);
			}else{
				if(ts.empty()){
					continue;
				}
				ts.pop();
			}
		}
		
		if(ss.size()!=ts.size()){
			return false;
		}
		
		while(!ss.empty()){
			if(ss.top()!=ts.top()){
				return false;
			}
			ss.pop();
			ts.pop();
		}
		return true;
	}
};
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> s1;
        vector<char> s2;
        backspaceString(S, s1);
        backspaceString(T, s2);
        if (s1.size() != s2.size()) {
            return false;
        }
        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }

    void backspaceString(string &s, vector<char> &ret) {
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (!ret.empty()) {
                    ret.pop_back();
                }
            } else {
                ret.push_back(s[i]);
            }
        }
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    cout << s.backspaceCompare("ab#c", "ad#c") << endl;
    cout << (s.backspaceCompare("ab##", "c#d#")) << endl;
    cout << (s.backspaceCompare("a##c", "#a#c")) << endl;
    cout << (s.backspaceCompare("a#c", "b")) << endl;
    cout << (s.backspaceCompare("y#fo##f", "y#f#o##f")) << endl;
    return 0;
}
