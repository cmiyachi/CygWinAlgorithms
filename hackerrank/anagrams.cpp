#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b)
{
    unordered_map<char, int> dels;
    for (int i = 0; i < a.size(); i++)
    {
        dels[a[i]]++;
    }
    for (int i = 0; i < b.size(); i++)
    {
        dels[b[i]]--;
    }

    int totalDel = 0;
    auto it = dels.begin();
    while (it != dels.end())
    {
        totalDel += abs(it->second);
        it++;
    }
    return totalDel;
}

int main()
{
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    cout << res << "\n";

    return 0;
}