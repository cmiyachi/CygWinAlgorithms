#include <bits/stdc++.h>
using namespace std;

vector<int>  reconstruct(vector<char> arr)
{
	int n = arr.size();
	vector<int> result;
	//result.push_back(0);
	stack<int> st;
	
	for (int i = 0; i < n-1; i++)
	{
		if (arr[i+1] == '-')
			st.push(i);
		else
		{
				result.push_back(i);
				while (!st.empty())
				{
					int val = st.top(); 
					st.pop();
					result.push_back(val);
				}
		}
	}
	st.push(n-1);
	while (!st.empty())
	{
		int val = st.top(); 
		st.pop();
		result.push_back(val);
	}
	return result;
}

int main(void)
{
	vector<char> arr{'n','+','+','-','+'};
	
	vector<int> result = reconstruct(arr);
	
	for (int r : result)
		cout << r << " "; 
	return 0;
}


