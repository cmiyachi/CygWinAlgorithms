#include <bits/stdc++.h>
using namespace std;

class AutocompleteSystem {
    unordered_map<string, int> dict;
    string data;

public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < times.size(); i++)
            dict[sentences[i]] += times[i];
        data.clear();
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            dict[data]++;
            data.clear();
            return {};
        }

        data.push_back(c);
        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second || a.second == b.second && a.first < b.first;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);

        for (auto &p : dict) {
            bool match = true;
            for (int i = 0; i < data.size(); i++) {
                if (data[i] != p.first[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                pq.push(p);
                if (pq.size() > 3)
                    pq.pop();
            }
        }

        vector<string> res(pq.size());
        for (int i = pq.size() - 1; i >= 0; i--) {
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};


/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */