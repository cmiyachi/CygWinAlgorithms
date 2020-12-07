#include <bits/stdc++.h>
using namespace std;

int leastBricksBrute(vector<vector<int>> wall) {
	vector<int> pos(wall.size());
	int c = 0, sum = 0, res = INT_MAX;
	for (int el: wall[0])
		sum += el;
	while (sum != 0) {
		int count = 0;
		for (int i = 0; i < wall.size(); i++) {
			vector<int> row = wall[i];
			if (row[pos[i]] != 0)
				count++;
			else
				pos[i]++;
			row[pos[i]] =  row[pos[i]] - 1;
		}
		sum--;
		res = min(res, count);
	}
	return res;

}


 int leastBricks(vector<vector<int>> wall) {
	unordered_map<int, int> mp;
	for (vector<int> row: wall) {
		int sum = 0;
		for (int i = 0; i < row.size() - 1; i++) {
			sum += row[i];
			if (mp.find(sum) != mp.end())
				mp[sum]++;
			else
				mp[sum] = 1; 
		}
	}
	int res = wall.size();
	for (auto i: mp)
	{
		int diff = wall.size() - i.second;
		if (res > diff) res = diff; 
	}
	return res;
}

int main(void)
{
	vector<vector<int>> wall{{1,2,2,1},
        {3,1,2},
        {1,3,2},
        {2,4},
        {3,1,2},
		{1,3,1,1}};
		
		cout << leastBricks(wall); 
		return 0;
}