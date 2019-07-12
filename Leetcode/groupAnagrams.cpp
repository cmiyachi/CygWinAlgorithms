

#include <bits/stdc++.h> 
using namespace std;

// O(NKlogK), group by sorted string
// N: # of strings, K: max length of string
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> anagrams;

		for (string str : strs) {
			string temp(str);
			sort(temp.begin(), temp.end());
			if (anagrams.find(temp) == anagrams.end())
				anagrams[temp] = vector<string>(1, str);
			else
				anagrams[temp].emplace_back(str);
		}

		vector<vector<string>> result;
		for (auto it = anagrams.begin(); it != anagrams.end(); it ++) {
			result.emplace_back(it -> second);
		}
		return result;
	}
};

// O(NK), group by alphabet count
class Solution2 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> anagrams;

		for (string str : strs) {
			vector<int> alphabetCount(26, 0);
			for (char c : str)
				alphabetCount[c - 'a'] ++;
			string key = "";
			for (int i = 0; i < 26; i++)
				key += ("#" + to_string(alphabetCount[i]));

			if (anagrams.find(key) == anagrams.end())
				anagrams[key] = vector<string>(1, str);
			else
				anagrams[key].emplace_back(str);
		}

		vector<vector<string>> result;
		for (auto it = anagrams.begin(); it != anagrams.end(); it ++) {
			result.emplace_back(it -> second);
		}
		return result;
	}
};
/*
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0) return new ArrayList();
        Map<String, List> ans = new HashMap<String, List>();
        int[] count = new int[26];
        for (String s : strs) {
            Arrays.fill(count, 0);
            for (char c : s.toCharArray()) count[c - 'a']++;

            StringBuilder sb = new StringBuilder("");
            for (int i = 0; i < 26; i++) {
                sb.append('#');
                sb.append(count[i]);
            }
            String key = sb.toString();
            if (!ans.containsKey(key)) ans.put(key, new ArrayList());
            ans.get(key).add(s);
        }
        return new ArrayList(ans.values());
    }
}
*/

int main(void)
{
	vector<string> input{"eat", "tea", "tan", "ate", "nat", "bat"}; 
	Solution sol;
	vector<vector<string>> result = sol.groupAnagrams(input); 
	
	for (int i = 0; i < result.size(); i++)
	{
		vector<string> currset = result[i]; 
		cout << "******" << endl; 
		for (int k = 0; k < currset.size(); k++)
			cout << currset[k] << ","; 
	}
	return 0;
}