#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::ios_base::sync_with_stdio(false);

        // 1. single word always true
        if (words.size() == 1) return true;

        // 2. build an alien dictionary with letter order
        unordered_map<char, int> hash;
        int i = 0;
        for (auto ch : order) 
            hash.insert({ch, i++});

        // 3. walk through the vector
        for (int i = 1; i < words.size(); ++i) {
            if (compareString(words[i - 1], words[i], hash) == false)
                return false;
        }
        return true;
    }

    bool compareString(const string& first, 
                       const string& second, 
                       const unordered_map<char, int>& hash) {
        int i = 0;
        int equal = 0;
        while (i < first.length() && i < second.length()) {
            // get the <letter, order> pair
            auto p1 = hash.find(first[i]); 
            auto p2 = hash.find(second[i]);
            // "second" is the order of letter in alien directory
            if (p1->second < p2->second)    
                return true;
            if (p1->second > p2->second)
                return false;
            if (p1->second == p2->second)
                equal++;
            i++;
        }
        
        // "Apple" > "App"
        if (i == equal && first.length() > second.length()) {
            return false; 
        }
        return true;
    }
};

int main(void)
{
	vector<string> words{"hello","leetcode"};
	string order = "hlabcdefgijkmnopqrstuvwxyz";
	
	Solution sol;
	
	cout << sol.isAlienSorted(words, order) << endl; 
	
	vector<string> words2{"word","world","row"};
	string order2 = "worldabcefghijkmnpqstuvxyz";
	cout << sol.isAlienSorted(words2, order2) << endl; 
	
	return 0;
}