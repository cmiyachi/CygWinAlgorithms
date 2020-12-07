#include <bits/stdc++.h>
using namespace std;
 bool isPalindrom(string & str);
 
   vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> M    ;
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i ++) {
            M[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i ++) {
            reverse(words[i].begin(), words[i].end());
            int len = words[i].size();
            for (int j = 0; j <= len; j ++) {
                string left = words[i].substr(0, j), right = words[i].substr(j);
                if (M.count(left) && isPalindrom(right) && M[left] != i) {
                    res.push_back({M[left], i});
                }
                if (M.count(right) && isPalindrom(left) && M[right] != i && j > 0) {  // j > 0 avoid duplicates
                    res.push_back({i, M[right]});
                }
            }
        }
        return res;
    }
    
    bool isPalindrom(string & str) {
        for (int i = 0, j = str.length() - 1; i < j; i ++, j --) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
	

vector<vector<string>> groupAnagrams(vector<string> words) {
  // Write your code here.
	unordered_map<string, vector<string>> sort_to_string;
	vector<vector<string>> result; 
	
	for (string s: words)
	{
		string sorted_letters = s;
		sort(sorted_letters.begin(), sorted_letters.end());
		sort_to_string[sorted_letters].push_back(s); 
	}
	
	for (auto i : sort_to_string)
		result.push_back(i.second); 
  
	return result; 
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>res;
        buildTrie(words);
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            for(auto x: Trie[s]) if(isPalindrome(x.first) && i != x.second) res.push_back({i, x.second});
            for(int j = 0; j <= s.size(); j++)
                if(m.count(s.substr(0, j)) && isPalindrome(s.substr(j)) && i != m[s.substr(0, j)]) 
                    res.push_back({i, m[s.substr(0, j)]});
        }    
        return res;
    }
    
private:
    unordered_map<string, vector<pair<string, int> > >Trie;
    unordered_map<string, int>m;
    void buildTrie(vector<string>& words){
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            reverse(s.begin(), s.end());
            m[s] = i;
            for(int j = 0; j < s.size(); j++) Trie[s.substr(0, j)].push_back({s.substr(j), i});
        }
    }
    
    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
};

int main(void)
{
	vector<string> words ={"abcd","dcba","lls","s","sssll"};
	vector<vector<int>> result = palindromePairs(words);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i][0] << "," << result[i][1] << endl;
	}
	
	return 0;
}
/**
class Solution {
    public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        for (int i = 0; i < words.size() - 1; ++i)
            for (int j = i+1; j < words.size(); ++j)
            {
                if (isPalindrome(words[i], words[j])) 
                    result.push_back({i, j});

                if (isPalindrome(words[j], words[i])) 
                    result.push_back({j, i});
            }

        return result;
    }

    bool isPalindrome(const string& s1, const string& s2) const
    {
        int left = 0;
        int right = s2.size() - 1;

        while (left < s1.size() && right >= 0)
        {
            if (s1[left] != s2[right])
                return false;

            ++left;
            --right;
        }

        if (left == s1.size() && right >= 0)
        {
            left = 0;
            while (left < right)
            {
                if (s2[left] != s2[right])
                    return false;

                ++left;
                --right;
            }
        }

        if (left < s1.size() && right < 0)
        {
            right = s1.size() - 1;
            while (left < right)
            {
                if (s1[left] != s1[right])
                    return false;

                ++left;
                --right;
            }
        }

        return true;
    }
}; **/