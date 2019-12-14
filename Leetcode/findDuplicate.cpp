#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
		unordered_map<string, vector<string>> files;
		vector<vector<string>> result;

		for (auto path : paths) {
			stringstream ss(path);
			string root;
			string s;
			getline(ss, root, ' ');
			while (getline(ss, s, ' ')) {
				string fileName = root + '/' + s.substr(0, s.find('('));
				string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
				files[fileContent].push_back(fileName);
			}
		}

		for (auto file : files) {
			if (file.second.size() > 1)
				result.push_back(file.second);
		}

		return result;
	}

};


int main(void)
{
Solution sol;
	
	vector<string> paths{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
	
	vector<vector<string>> result = sol.findDuplicate(paths);
	
	for (int i = 0; i < result.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << ","; 
		cout << "]";
		cout << endl; 
	}
	
	return 0;
}