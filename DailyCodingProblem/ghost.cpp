#include <bits/stdc++.h>
using namespace std;
bool solve(vector<string> &words) {
   map<char, set<string>> mp;
   for (auto &it : words) {
      char ch = it[0];
      mp[ch].insert(it);
   }
   int mn = INT_MAX;
   for (auto &it : mp) {
      string str = *(it.second.begin());
      int size = str.size();
      if (size % 2 == 0)
         return 1;
   }
   return 0;
}
int main(){
   vector<string> v = {"manage", "manager", "min"};
   cout << solve(v);
}