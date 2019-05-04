#include <bits/stdc++.h>
#include <unordered_map>
#include <algorithm> // sort

using namespace std;



int sherlockAndAnagrams(string s)
{
    unordered_map<string, int> stringsMap;
    int anagrams = 0;

    for (int i = 0; i < s.length(); ++i) {
        for (int j = 1; j <= s.length() - i; ++j) {
            string word = s.substr(i, j);
            sort(word.begin(), word.end());

            if (stringsMap.count(word) != 0) {
                stringsMap[word] += 1;
                anagrams += stringsMap[word];
            }
            else
                stringsMap.insert(pair<string, int>(word, 0));
        }
    }

    return anagrams;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = sherlockAndAnagrams(s);
        cout << result << endl;
    }
    return 0;
}