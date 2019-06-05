#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */
void InOrder(vector<vector<int>> &tree, vector<vector<int>> &ans, int index, int step);

void Swap(vector<vector<int>> &tree, int index, int k, int level) 
{
  //   cout << 'a';
    if(level % k == 0)
    {
        int temp = tree[index][0];
        tree[index][0] = tree[index][1];
        tree[index][1] = temp;
    }

    if(tree[index][0] != -1) Swap(tree, tree[index][0]-1, k, level + 1);
    if(tree[index][1] != -1) Swap(tree, tree[index][1]-1, k, level + 1);
}

void InOrder(vector<vector<int>> &tree, vector<int> &ans, int index) 
{
    if(tree[index][0] != -1)
        InOrder(tree, ans, tree[index][0] - 1);
    ans.push_back(index + 1);
    if(tree[index][1] != -1)
        InOrder(tree, ans, tree[index][1] - 1);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> ans(queries.size());

    for(int i = 0; i < queries.size(); ++i)
    {
        int k = queries[i];

        Swap(indexes, 0,  k, 1);
        InOrder(indexes, ans[i], 0);
    }

    for(int i = 0; i < ans.size(); ++i)
    {
        for(int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return ans;
}

int main(){

	int n, q;
	cin >> n;
	vector< vector<int> > indexes(n);
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		indexes[i].push_back(a);
		indexes[i].push_back(b);
	}

	cin >> q;
	vector<int> queries(q);
	for(int i = 0; i < q; i++){
		cin >> queries[i];
	}

	vector< vector<int> > res;
	res = swapNodes(indexes, queries);
	for(auto t : res){
		for(auto el : t){
			cout << el << " ";
		}
		cout << endl;
	}

	return 0;
}