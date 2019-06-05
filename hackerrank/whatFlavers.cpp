#include <bits/stdc++.h>

  
using namespace std; 

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
  unordered_map<int, int> dict;
  for (int i = 0; i < cost.size(); i++) {
    if (dict.find(money - cost[i]) == dict.end()) {
      dict[cost[i]] = i + 1;
      continue;
    }
    cout << dict[money - cost[i]] << " " << i + 1 << endl;
    return;
  }
}

int main(void)
{

	vector<int> cost{1 ,4, 5, 3 ,2};

	whatFlavors(cost, 4);
	return 0;
}