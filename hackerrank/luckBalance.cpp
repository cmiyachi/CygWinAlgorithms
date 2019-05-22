#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    vector<int> lucks_in_contests;
    int luck = 0;
    for (int i = 0; i < contests.size(); i++) {
        if (contests[i][1] == 1) {
            lucks_in_contests.push_back(contests[i][0]);
            continue;
        }

        luck += contests[i][0];
    }

    sort(lucks_in_contests.begin(), lucks_in_contests.end(), greater<int>());

    for (int i = 0; i < lucks_in_contests.size(); i++) {
        if (i < k) {
            luck += lucks_in_contests[i];
        } else {
            luck -= lucks_in_contests[i];
        }
    }

    return luck;
}

int main()
{
	int k,n;
	// vector<vector<int>> c; 
	vector<vector<int>> c(10, vector<int> (2, 0));
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>c[i][j];
		}
	}
	cout<<luckBalance(k,c);
	
}